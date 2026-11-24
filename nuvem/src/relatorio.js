// Relatório de um período, no modelo do relatório do Jukebox Pix: dinheiro (noteiro e Pix), músicas, dia a dia,
// horário de pico, mais tocadas e fechamentos, de todas as máquinas ou de uma.
//
// Dinheiro: cada pulso do noteiro é R$ 1 (como no relógio da jukebox) e cada Pix vale o que o cliente pagou.
// A parte da casa segue a regra da máquina: o "ponto" é a porcentagem do relógio que fica com o bar
// (PORCENTAGEMDOPONTO, mandada no último contato).
import { diaDe, inicioDoDia, somaDias, horaLocal, validaDia } from './tempo.js';

const MAX_DIAS = 366;

export class ErroRelatorio extends Error {}

export function periodo(de, ate) {
  if (!validaDia(de) || !validaDia(ate)) throw new ErroRelatorio('Informe as datas no formato AAAA-MM-DD.');
  if (ate < de) throw new ErroRelatorio('A data final não pode ser antes da inicial.');
  const dias = Math.round((Date.parse(ate) - Date.parse(de)) / 86_400_000) + 1;
  if (dias > MAX_DIAS) throw new ErroRelatorio(`Escolha um período de até ${MAX_DIAS} dias.`);
  return dias;
}

function pontoDe(maquina) {
  try {
    const r = JSON.parse(maquina.relogio || '{}');
    return Number.isInteger(r.ponto_pct) ? r.ponto_pct : null;
  } catch {
    return null;
  }
}

export function gerar(db, config, { de, ate, maquinaId = null }) {
  const dias = periodo(de, ate);
  const inicio = inicioDoDia(de, config);
  const fim = inicioDoDia(somaDias(ate, 1), config);
  const filtro = maquinaId ? 'AND maquina_id = ?' : '';
  const args = maquinaId ? [inicio, fim, maquinaId] : [inicio, fim];

  const maquinas = new Map(db.prepare('SELECT id, nome, local, codigo, relogio FROM maquinas').all().map((m) => [m.id, m]));
  const vazio = () => ({ noteiro: 0, pix: 0, pix_qtd: 0, total: 0, musicas: 0 });

  const porDia = new Map();
  for (let i = 0; i < dias; i++) porDia.set(somaDias(de, i), { dia: somaDias(de, i), ...vazio() });
  const porMaquina = new Map();
  const porHora = Array.from({ length: 24 }, (_, hora) => ({ hora, reais: 0, musicas: 0 }));
  const totais = vazio();

  const linhaMaquina = (id) => {
    if (!porMaquina.has(id)) {
      const m = maquinas.get(id);
      porMaquina.set(id, { id, nome: m?.nome ?? `#${id}`, local: m?.local ?? '', ponto_pct: m ? pontoDe(m) : null, ...vazio() });
    }
    return porMaquina.get(id);
  };

  const creditos = db.prepare(`
    SELECT maquina_id, quando, origem, reais FROM eventos
     WHERE tipo = 'credito' AND quando >= ? AND quando < ? ${filtro}`).all(...args);
  for (const e of creditos) {
    const alvos = [totais, porDia.get(diaDe(e.quando, config)), linhaMaquina(e.maquina_id)];
    for (const a of alvos) {
      if (!a) continue;
      if (e.origem === 'pix') {
        a.pix += e.reais;
        a.pix_qtd += 1;
      } else {
        a.noteiro += e.reais;
      }
      a.total += e.reais;
    }
    porHora[horaLocal(e.quando, config)].reais += e.reais;
  }

  const musicas = db.prepare(`
    SELECT maquina_id, quando FROM eventos WHERE tipo = 'musica' AND quando >= ? AND quando < ? ${filtro}`).all(...args);
  for (const e of musicas) {
    totais.musicas += 1;
    const d = porDia.get(diaDe(e.quando, config));
    if (d) d.musicas += 1;
    linhaMaquina(e.maquina_id).musicas += 1;
    porHora[horaLocal(e.quando, config)].musicas += 1;
  }

  // parte da casa: cada máquina com o ponto dela
  let casa = 0;
  let casaConhecida = true;
  for (const m of porMaquina.values()) {
    if (m.ponto_pct === null) {
      m.casa = null;
      casaConhecida = false;
    } else {
      m.casa = Math.round((m.total * m.ponto_pct) / 100);
      casa += m.casa;
    }
    m.dono = m.casa === null ? null : m.total - m.casa;
  }
  totais.casa = casaConhecida ? casa : null;
  totais.dono = casaConhecida ? totais.total - casa : null;
  totais.ticket_medio_pix = totais.pix_qtd ? totais.pix / totais.pix_qtd : 0;

  const topMusicas = db.prepare(`
    SELECT cd, musica, COUNT(*) AS tocadas FROM eventos
     WHERE tipo = 'musica' AND quando >= ? AND quando < ? ${filtro}
     GROUP BY cd, musica ORDER BY tocadas DESC, musica LIMIT 15`).all(...args);
  const topCds = db.prepare(`
    SELECT cd, COUNT(*) AS tocadas FROM eventos
     WHERE tipo = 'musica' AND cd <> '' AND quando >= ? AND quando < ? ${filtro}
     GROUP BY cd ORDER BY tocadas DESC, cd LIMIT 10`).all(...args);
  const fechamentos = db.prepare(`
    SELECT maquina_id, quando, reais, dados FROM eventos
     WHERE tipo = 'fechamento' AND quando >= ? AND quando < ? ${filtro} ORDER BY quando`).all(...args)
    .map((f) => {
      const d = JSON.parse(f.dados || '{}');
      return { maquina: maquinas.get(f.maquina_id)?.nome ?? `#${f.maquina_id}`, quando: f.quando, parcial: f.reais, pix: d.pix ?? 0, ponto: d.ponto ?? 0 };
    });

  const pico = porHora.reduce((melhor, h) => (h.reais + h.musicas > melhor.reais + melhor.musicas ? h : melhor), porHora[0]);

  return {
    de, ate, dias, maquinaId,
    totais,
    por_dia: [...porDia.values()],
    por_maquina: [...porMaquina.values()].sort((a, b) => b.total - a.total || a.nome.localeCompare(b.nome)),
    por_hora: porHora,
    horario_de_pico: pico.reais + pico.musicas > 0 ? pico.hora : null,
    top_musicas: topMusicas,
    top_cds: topCds,
    fechamentos,
  };
}

// CSV para o Excel brasileiro: separador ";" e BOM para os acentos.
export function paraCsv(r) {
  const data = (t) => t.split('-').reverse().join('/');
  const linhas = [
    ['Dia', 'Noteiro (R$)', 'Pix (R$)', 'Pix (quantidade)', 'Total (R$)', 'Músicas'],
    ...r.por_dia.map((d) => [data(d.dia), d.noteiro, d.pix, d.pix_qtd, d.total, d.musicas]),
    ['TOTAL', r.totais.noteiro, r.totais.pix, r.totais.pix_qtd, r.totais.total, r.totais.musicas],
    [],
    ['Máquina', 'Local', 'Noteiro (R$)', 'Pix (R$)', 'Total (R$)', 'Ponto (%)', 'Casa (R$)', 'Dono (R$)', 'Músicas'],
    ...r.por_maquina.map((m) => [m.nome, m.local, m.noteiro, m.pix, m.total, m.ponto_pct ?? '', m.casa ?? '', m.dono ?? '', m.musicas]),
  ];
  const campo = (v) => {
    const s = String(v ?? '');
    return /[;"\r\n]/.test(s) ? `"${s.replace(/"/g, '""')}"` : s;
  };
  return `﻿${linhas.map((l) => l.map(campo).join(';')).join('\r\n')}\r\n`;
}
