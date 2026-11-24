// Páginas do painel da empresa.
import { html, cru, reais, esc } from './html.js';
import { registrar } from './banco.js';
import { conferirLicenca } from './licenca.js';
import { gerar, ErroRelatorio } from './relatorio.js';
import { dataHora, dataBr, hoje, somaDias, inicioDoDia } from './tempo.js';

const SITUACAO = { pendente: 'aguardando licença', ativa: 'liberada', bloqueada: 'bloqueada' };

export function codigoBonito(c) {
  return String(c).replace(/(\d{4})(?=\d)/g, '$1-');
}

function online(m, config, agora) {
  return m.ultimo_contato && agora - m.ultimo_contato < config.intervaloContato * 3000;
}

function tempoAtras(ms, agora) {
  if (!ms) return 'nunca';
  const min = Math.round((agora - ms) / 60_000);
  if (min < 2) return 'agora';
  if (min < 60) return `há ${min} min`;
  const h = Math.round(min / 60);
  if (h < 48) return `há ${h} h`;
  return `há ${Math.round(h / 24)} dias`;
}

function relogioDe(m) {
  try {
    return JSON.parse(m.relogio || '{}');
  } catch {
    return {};
  }
}

const seloSituacao = (m) => html`<span class="selo ${m.situacao}">${SITUACAO[m.situacao]}</span>`;
const seloRede = (m, config, agora) => (online(m, config, agora)
  ? html`<span class="selo online">online</span>`
  : html`<span class="selo offline">sem contato</span>`);

function validadeTexto(m, config, agora) {
  if (m.situacao === 'pendente') return 'nenhuma ainda';
  const partes = [m.situacao === 'bloqueada' ? 'de bloqueio' : m.validade ? `até ${dataBr(m.validade)}` : 'permanente'];
  if (m.situacao === 'ativa' && m.validade && m.validade < hoje(config, agora)) partes.push('VENCIDA');
  return partes.join(' · ');
}

/** Lista de máquinas com o dinheiro de hoje. */
export function paginaMaquinas(db, config, agora = Date.now()) {
  const maquinas = db.prepare('SELECT * FROM maquinas ORDER BY situacao = \'pendente\' DESC, nome').all();
  const dia = hoje(config, agora);
  const inicio = inicioDoDia(dia, config);
  const hojePor = new Map(db.prepare(`
    SELECT maquina_id,
           SUM(CASE WHEN tipo = 'credito' AND origem = 'noteiro' THEN reais ELSE 0 END) AS noteiro,
           SUM(CASE WHEN tipo = 'credito' AND origem = 'pix' THEN reais ELSE 0 END) AS pix,
           SUM(CASE WHEN tipo = 'musica' THEN 1 ELSE 0 END) AS musicas
      FROM eventos WHERE quando >= ? AND quando < ? GROUP BY maquina_id`)
    .all(inicio, inicio + 86_400_000).map((l) => [l.maquina_id, l]));

  let tNoteiro = 0;
  let tPix = 0;
  let tMusicas = 0;
  let nOnline = 0;
  for (const m of maquinas) {
    const h = hojePor.get(m.id);
    tNoteiro += h?.noteiro ?? 0;
    tPix += h?.pix ?? 0;
    tMusicas += h?.musicas ?? 0;
    if (online(m, config, agora)) nOnline++;
  }
  const pendentes = maquinas.filter((m) => m.situacao === 'pendente').length;

  const linhas = maquinas.map((m) => {
    const h = hojePor.get(m.id) ?? {};
    const r = relogioDe(m);
    return html`<tr>
      <td><a href="/maquinas/${m.id}"><b>${m.nome}</b></a><br><span class="suave">${m.local || codigoBonito(m.codigo)}</span></td>
      <td>${seloSituacao(m)}${m.intruso_em ? html` <span class="selo bloqueada" title="Outro aparelho tentou usar este código">alerta</span>` : ''}</td>
      <td>${seloRede(m, config, agora)}<br><span class="suave">${tempoAtras(m.ultimo_contato, agora)}</span></td>
      <td class="n">${reais(h.noteiro ?? 0)}</td>
      <td class="n">${reais(h.pix ?? 0)}</td>
      <td class="n"><b>${reais((h.noteiro ?? 0) + (h.pix ?? 0))}</b></td>
      <td class="n">${h.musicas ?? 0}</td>
      <td class="n">${r.parcial ?? '—'}</td>
    </tr>`;
  });

  return html`
    <h1>Máquinas</h1>
    ${pendentes ? html`<p class="erro">${pendentes} máquina(s) aguardando licença: gere a licença no gerador com o código
      dela e envie em <a href="/licencas"><b>Enviar licença</b></a>.</p>` : ''}
    <div class="grade">
      <div class="numero"><span>Hoje (${dataBr(dia)}): total</span><b>${reais(tNoteiro + tPix)}</b></div>
      <div class="numero"><span>Noteiro</span><b>${reais(tNoteiro)}</b></div>
      <div class="numero"><span>Pix</span><b>${reais(tPix)}</b></div>
      <div class="numero"><span>Músicas</span><b>${tMusicas}</b></div>
      <div class="numero"><span>Online agora</span><b>${nOnline} de ${maquinas.length}</b></div>
    </div>
    <div class="tabela"><table>
      <thead><tr><th>Máquina</th><th>Licença</th><th>Internet</th><th class="n">Noteiro hoje</th><th class="n">Pix hoje</th>
        <th class="n">Total hoje</th><th class="n">Músicas hoje</th><th class="n">Relógio parcial</th></tr></thead>
      <tbody>${linhas.length ? linhas : html`<tr><td colspan="8" class="suave">Nenhuma máquina ainda. Quando uma jukebox com
        <code>nuvem.txt</code> ligar com internet, ela aparece aqui aguardando licença.</td></tr>`}</tbody>
    </table></div>
    <p class="suave">O dia vai das ${config.viradaDoDia}h às ${config.viradaDoDia}h. As máquinas mandam o que aconteceu a cada
      ${config.intervaloContato} s quando têm internet; sem internet elas funcionam normalmente e mandam tudo depois.</p>`;
}

export function paginaMaquina(db, config, id, csrf, agora = Date.now()) {
  const m = db.prepare('SELECT * FROM maquinas WHERE id = ?').get(id);
  if (!m) return null;
  const r = relogioDe(m);
  const eventos = db.prepare('SELECT * FROM eventos WHERE maquina_id = ? ORDER BY quando DESC, id DESC LIMIT 40').all(id);
  const historico = db.prepare('SELECT * FROM historico WHERE maquina_id = ? ORDER BY quando DESC LIMIT 15').all(id);
  const dia = hoje(config, agora);
  const de = somaDias(dia, -6);

  const descreve = (e) => {
    if (e.tipo === 'credito') return `${e.origem === 'pix' ? 'Pix' : 'Noteiro'}: ${reais(e.reais)} (${e.creditos} créditos)`;
    if (e.tipo === 'musica') return `Música: ${e.musica}${e.cd ? ` (${e.cd})` : ''}`;
    if (e.tipo === 'fechamento') {
      const d = JSON.parse(e.dados || '{}');
      return `Fechamento: relógio parcial ${e.reais}, Pix ${reais(d.pix ?? 0)}, ponto da casa ${d.ponto ?? 0}`;
    }
    if (e.tipo === 'ligou') return `Jukebox ligada (versão ${JSON.parse(e.dados || '{}').versao || '?'})`;
    return e.tipo;
  };

  const botao = (acao, texto, classe = '', confirmar = '') => html`
    <form method="post" action="/maquinas/${m.id}/${acao}" ${confirmar ? cru(`data-confirmar="${esc(confirmar)}"`) : ''}>
      <input type="hidden" name="csrf" value="${csrf}"><button class="${classe}">${texto}</button></form>`;

  const acoes = [];
  if (m.segredo_hash) {
    acoes.push(botao('esquecer-aparelho', 'Esquecer o aparelho', 'neutro',
      'Use quando a jukebox for reinstalada: o próximo aparelho com este código fica pareado. Continuar?'));
  }
  acoes.push(botao('excluir', 'Excluir', 'neutro', 'Excluir a máquina e todo o histórico dela? Não dá para desfazer.'));

  return html`
    <h1>${m.nome}</h1>
    <div class="grade">
      <div class="numero"><span>Licença</span><b>${seloSituacao(m)}</b></div>
      <div class="numero"><span>Internet</span><b>${seloRede(m, config, agora)}</b><span>${tempoAtras(m.ultimo_contato, agora)}</span></div>
      <div class="numero"><span>Relógio parcial</span><b>${r.parcial ?? '—'}</b></div>
      <div class="numero"><span>Relógio total</span><b>${r.total ?? '—'}</b></div>
      <div class="numero"><span>Pix no período (relógio)</span><b>${r.pix_parcial === undefined ? '—' : reais(r.pix_parcial)}</b></div>
      <div class="numero"><span>Ponto da casa</span><b>${r.ponto_pct === undefined ? '—' : `${r.ponto_pct}%`}</b></div>
      <div class="numero"><span>Créditos na tela</span><b>${r.creditos ?? '—'}</b></div>
    </div>
    ${m.intruso_em ? html`<p class="erro">Em ${dataHora(m.intruso_em, config)} outro aparelho tentou falar com a nuvem usando o código
      desta máquina e foi recusado. Se a jukebox foi reinstalada, use "Esquecer o aparelho".</p>` : ''}
    <div class="cartao">
      <p>Código: <code>${codigoBonito(m.codigo)}</code> · versão ${m.versao || '?'} · IP ${m.ip || '?'} ·
        cadastrada em ${dataHora(m.criada_em, config)}${m.liberada_em ? ` · liberada em ${dataHora(m.liberada_em, config)}` : ''}</p>
      <p>Licença: ${validadeTexto(m, config, agora)}${m.licenca_emitida ? ` · gerada em ${dataHora(m.licenca_emitida, config)}` : ''}</p>
      <div class="acoes">${acoes}
        <a href="/licencas">Enviar licença</a>
        ${m.licenca_texto ? html`<a href="/maquinas/${m.id}/licenca.txt">Baixar a licença enviada (licenca.txt)</a>` : ''}
        <a href="/relatorio?de=${de}&ate=${dia}&maquina=${m.id}">Relatório da máquina</a>
      </div>
    </div>

    <h2>Dados</h2>
    <form class="cartao linha" method="post" action="/maquinas/${m.id}/dados">
      <input type="hidden" name="csrf" value="${csrf}">
      <label>Nome<input name="nome" value="${m.nome}" maxlength="60" required></label>
      <label>Local (bar)<input name="local" value="${m.local}" maxlength="80"></label>
      <label>Cliente<input name="cliente" value="${m.cliente}" maxlength="80"></label>
      <label style="flex-basis:100%">Observação<textarea name="observacao" maxlength="500">${m.observacao}</textarea></label>
      <button>Salvar</button>
    </form>

    <h2>Últimos acontecimentos</h2>
    <div class="tabela"><table>
      <thead><tr><th>Quando</th><th>O quê</th></tr></thead>
      <tbody>${eventos.length ? eventos.map((e) => html`<tr><td>${dataHora(e.quando, config)}</td><td>${descreve(e)}</td></tr>`)
        : html`<tr><td colspan="2" class="suave">Nada ainda.</td></tr>`}</tbody>
    </table></div>

    <h2>Histórico da licença</h2>
    <div class="tabela"><table>
      <tbody>${historico.map((h) => html`<tr><td>${dataHora(h.quando, config)}</td><td>${h.acao}</td><td class="suave">${h.detalhe}</td></tr>`)}</tbody>
    </table></div>`;
}

/** Ações dos botões da página da máquina. Devolve a mensagem para mostrar. */
export function acaoMaquina(db, config, id, acao, campos, agora = Date.now()) {
  const m = db.prepare('SELECT * FROM maquinas WHERE id = ?').get(id);
  if (!m) return { erro: 'Máquina não encontrada.' };
  switch (acao) {
    case 'esquecer-aparelho':
      db.prepare('UPDATE maquinas SET segredo_hash = NULL, intruso_em = NULL WHERE id = ?').run(id);
      registrar(db, id, 'aparelho esquecido', 'o próximo aparelho com este código fica pareado');
      return { aviso: 'Pronto: o próximo aparelho com este código fica pareado com a máquina.' };
    case 'excluir':
      db.prepare('DELETE FROM maquinas WHERE id = ?').run(id);
      return { aviso: `Máquina ${m.nome} excluída.`, excluida: true };
    case 'dados': {
      const nome = String(campos.nome ?? '').trim().slice(0, 60);
      if (!nome) return { erro: 'O nome não pode ficar vazio.' };
      db.prepare('UPDATE maquinas SET nome = ?, local = ?, cliente = ?, observacao = ? WHERE id = ?').run(
        nome, String(campos.local ?? '').trim().slice(0, 80), String(campos.cliente ?? '').trim().slice(0, 80),
        String(campos.observacao ?? '').trim().slice(0, 500), id);
      return { aviso: 'Dados salvos.' };
    }
    default:
      return { erro: 'Ação desconhecida.' };
  }
}

export function licencaParaBaixar(db, id) {
  return db.prepare('SELECT licenca_texto FROM maquinas WHERE id = ?').get(id)?.licenca_texto || null;
}

/** Página "Enviar licença": cola (ou abre) o licenca.txt feito no gerador de licenças. */
export function paginaEnviarLicenca(config, csrf) {
  return html`
    <h1>Enviar licença</h1>
    <form class="cartao" method="post" action="/licencas">
      <input type="hidden" name="csrf" value="${csrf}">
      <p>Gere a licença no <b>gerador de licenças</b> (no seu computador) com o código da máquina e cole aqui, ou abra o
        <code>licenca.txt</code>. A nuvem guarda e manda para a jukebox no próximo contato (em até um minuto, se ela estiver
        com internet). Para bloquear, gere uma licença de bloqueio e envie do mesmo jeito.</p>
      <label>Licença<textarea name="licenca" id="campo-licenca" rows="9" required
        placeholder="JUKELINUX NOVA LICENCA 1&#10;codigo=...&#10;assinatura=..."></textarea></label>
      <div class="acoes" style="margin-top:10px">
        <button>Enviar</button>
        <label class="suave" style="flex-direction:row;align-items:center;gap:6px">ou abrir o arquivo:
          <input type="file" accept=".txt" data-preenche="campo-licenca"></label>
      </div>
      ${config.chavePublica ? '' : html`<p class="erro">A nuvem está sem LICENCA_CHAVE_PUBLICA: ela não consegue conferir se a
        licença é mesmo sua antes de mandar (a jukebox confere de qualquer jeito). Ponha a chave pública que o gerador mostra.</p>`}
    </form>`;
}

/** Recebe uma licença do gerador: confere, acha (ou cria) a máquina pelo código e guarda para o próximo contato. */
export function enviarLicenca(db, config, texto, agora = Date.now()) {
  const campos = conferirLicenca(texto, config.chavePublica);
  if (!campos) {
    return { erro: config.chavePublica
      ? 'Licença recusada: não é do seu gerador de licenças (assinatura não confere) ou o texto está incompleto.'
      : 'Licença recusada: o texto não está no formato do gerador de licenças (copie tudo, até a linha "assinatura=").' };
  }
  const emitidaMs = Number(campos.emitida) * 1000;
  let m = db.prepare('SELECT * FROM maquinas WHERE codigo = ?').get(campos.codigo);
  if (!m) {
    // máquina que ainda não falou com a nuvem: fica cadastrada; o primeiro aparelho com este código pareia
    db.prepare('INSERT INTO maquinas (codigo, nome, cliente, criada_em) VALUES (?, ?, ?, ?)')
      .run(campos.codigo, campos.cliente || `Máquina ${campos.codigo.slice(-4)}`, campos.cliente || '', agora);
    m = db.prepare('SELECT * FROM maquinas WHERE codigo = ?').get(campos.codigo);
  } else if (m.licenca_emitida && emitidaMs < m.licenca_emitida) {
    return { erro: 'Esta licença é mais antiga que a que a máquina já tem: a jukebox não aceitaria. Gere outra.', id: m.id };
  }
  db.prepare(`UPDATE maquinas SET situacao = ?, validade = ?, licenca_texto = ?, licenca_emitida = ?,
                liberada_em = CASE WHEN ? = 'ativa' THEN COALESCE(liberada_em, ?) ELSE liberada_em END WHERE id = ?`)
    .run(campos.situacao, campos.validade === 'permanente' ? null : campos.validade, campos.texto, emitidaMs,
      campos.situacao, agora, m.id);
  const nova = db.prepare('SELECT * FROM maquinas WHERE id = ?').get(m.id);
  registrar(db, m.id, campos.situacao === 'bloqueada' ? 'licença de bloqueio enviada' : 'licença enviada',
    validadeTexto(nova, config, agora) + (campos.cliente ? ` · ${campos.cliente}` : ''));
  return {
    id: m.id,
    aviso: campos.situacao === 'bloqueada'
      ? `Bloqueio guardado para ${codigoBonito(m.codigo)}: a jukebox trava no próximo contato.`
      : `Licença guardada para ${codigoBonito(m.codigo)}: a jukebox recebe no próximo contato (em até um minuto, se estiver com internet).`,
  };
}

function barras(lista, campo, rotulo) {
  const max = Math.max(1, ...lista.map((l) => l[campo]));
  return lista.map((l) => html`<tr><td class="quebra">${rotulo(l)}</td><td class="n">${l[campo]}</td>
    <td style="width:45%"><div class="barra" style="width:${Math.round((l[campo] / max) * 100)}%"></div></td></tr>`);
}

export function paginaRelatorio(db, config, consulta, agora = Date.now()) {
  const dia = hoje(config, agora);
  const de = consulta.get('de') || somaDias(dia, -6);
  const ate = consulta.get('ate') || dia;
  const maquinaId = Number(consulta.get('maquina')) || null;
  const maquinas = db.prepare('SELECT id, nome FROM maquinas ORDER BY nome').all();

  let r;
  let erro = '';
  try {
    r = gerar(db, config, { de, ate, maquinaId });
  } catch (e) {
    if (!(e instanceof ErroRelatorio)) throw e;
    erro = e.message;
  }

  const filtros = html`
    <form class="cartao linha" method="get" action="/relatorio">
      <label>De<input type="date" name="de" value="${de}"></label>
      <label>Até<input type="date" name="ate" value="${ate}"></label>
      <label>Máquina<select name="maquina"><option value="">Todas</option>
        ${maquinas.map((m) => html`<option value="${m.id}" ${m.id === maquinaId ? cru('selected') : ''}>${m.nome}</option>`)}
      </select></label>
      <button>Ver</button>
      <a href="/relatorio?de=${dia}&ate=${dia}${maquinaId ? `&maquina=${maquinaId}` : ''}">Hoje</a>
      <a href="/relatorio?de=${somaDias(dia, -6)}&ate=${dia}${maquinaId ? `&maquina=${maquinaId}` : ''}">7 dias</a>
      <a href="/relatorio?de=${somaDias(dia, -29)}&ate=${dia}${maquinaId ? `&maquina=${maquinaId}` : ''}">30 dias</a>
    </form>`;
  if (!r) return { conteudo: html`<h1>Relatório</h1>${filtros}`, erro };

  const t = r.totais;
  const nomeMaquina = maquinaId ? maquinas.find((m) => m.id === maquinaId)?.nome : 'todas as máquinas';
  const csv = `/relatorio.csv?de=${de}&ate=${ate}${maquinaId ? `&maquina=${maquinaId}` : ''}`;

  return {
    conteudo: html`
    <h1>Relatório</h1>
    ${filtros}
    <p>${dataBr(de)} a ${dataBr(ate)} · ${nomeMaquina} · dia das ${config.viradaDoDia}h às ${config.viradaDoDia}h
      <span class="nao-imprimir"> · <a href="${csv}">Baixar CSV (Excel)</a> · <a href="#" data-imprimir>Imprimir</a></span></p>
    <div class="grade">
      <div class="numero"><span>Total</span><b>${reais(t.total)}</b></div>
      <div class="numero"><span>Noteiro</span><b>${reais(t.noteiro)}</b></div>
      <div class="numero"><span>Pix (${t.pix_qtd})</span><b>${reais(t.pix)}</b></div>
      <div class="numero"><span>Ticket médio do Pix</span><b>${reais(t.ticket_medio_pix)}</b></div>
      <div class="numero"><span>Parte das casas (ponto)</span><b>${reais(t.casa)}</b></div>
      <div class="numero"><span>Sua parte</span><b>${reais(t.dono)}</b></div>
      <div class="numero"><span>Músicas pedidas</span><b>${t.musicas}</b></div>
      <div class="numero"><span>Horário de pico</span><b>${r.horario_de_pico === null ? '—' : `${r.horario_de_pico}h`}</b></div>
    </div>
    ${t.casa === null ? html`<p class="suave">Alguma máquina ainda não mandou o ponto da casa: a divisão aparece depois do próximo contato dela.</p>` : ''}

    <h2>Por máquina</h2>
    <div class="tabela"><table>
      <thead><tr><th>Máquina</th><th class="n">Noteiro</th><th class="n">Pix</th><th class="n">Total</th><th class="n">Ponto</th>
        <th class="n">Casa</th><th class="n">Dono</th><th class="n">Músicas</th></tr></thead>
      <tbody>${r.por_maquina.length ? r.por_maquina.map((m) => html`<tr>
        <td><a href="/maquinas/${m.id}">${m.nome}</a> <span class="suave">${m.local}</span></td>
        <td class="n">${reais(m.noteiro)}</td><td class="n">${reais(m.pix)}</td><td class="n"><b>${reais(m.total)}</b></td>
        <td class="n">${m.ponto_pct === null ? '—' : `${m.ponto_pct}%`}</td><td class="n">${reais(m.casa)}</td>
        <td class="n">${reais(m.dono)}</td><td class="n">${m.musicas}</td></tr>`)
        : html`<tr><td colspan="8" class="suave">Nenhum movimento no período.</td></tr>`}</tbody>
    </table></div>

    <h2>Dia a dia</h2>
    <div class="tabela"><table>
      <thead><tr><th>Dia</th><th class="n">Noteiro</th><th class="n">Pix</th><th class="n">Total</th><th class="n">Músicas</th></tr></thead>
      <tbody>${r.por_dia.map((d) => html`<tr><td>${dataBr(d.dia)}</td><td class="n">${reais(d.noteiro)}</td>
        <td class="n">${reais(d.pix)}</td><td class="n"><b>${reais(d.total)}</b></td><td class="n">${d.musicas}</td></tr>`)}</tbody>
      <tfoot><tr><td>Total</td><td class="n">${reais(t.noteiro)}</td><td class="n">${reais(t.pix)}</td>
        <td class="n">${reais(t.total)}</td><td class="n">${t.musicas}</td></tr></tfoot>
    </table></div>

    <h2>Músicas por hora</h2>
    <div class="tabela"><table><tbody>${barras(r.por_hora.filter((h) => h.musicas > 0), 'musicas', (h) => `${h.hora}h`)}</tbody></table></div>

    <h2>Mais tocadas</h2>
    <div class="tabela"><table>
      <thead><tr><th>Música</th><th>CD</th><th class="n">Vezes</th></tr></thead>
      <tbody>${r.top_musicas.length ? r.top_musicas.map((m) => html`<tr><td>${m.musica}</td><td class="suave">${m.cd}</td><td class="n">${m.tocadas}</td></tr>`)
        : html`<tr><td colspan="3" class="suave">Nenhuma música no período.</td></tr>`}</tbody>
    </table></div>

    <h2>CDs mais pedidos</h2>
    <div class="tabela"><table><tbody>${barras(r.top_cds, 'tocadas', (c) => c.cd)}</tbody></table></div>

    <h2>Fechamentos (relógio parcial zerado)</h2>
    <div class="tabela"><table>
      <thead><tr><th>Quando</th><th>Máquina</th><th class="n">Relógio parcial</th><th class="n">Pix</th><th class="n">Ponto da casa</th></tr></thead>
      <tbody>${r.fechamentos.length ? r.fechamentos.map((f) => html`<tr><td>${dataHora(f.quando, config)}</td><td>${f.maquina}</td>
        <td class="n">${f.parcial}</td><td class="n">${reais(f.pix)}</td><td class="n">${f.ponto}</td></tr>`)
        : html`<tr><td colspan="5" class="suave">Nenhum fechamento no período.</td></tr>`}</tbody>
    </table></div>`,
    erro,
  };
}

export function paginaHistorico(db, config) {
  const linhas = db.prepare(`
    SELECT h.*, m.nome FROM historico h LEFT JOIN maquinas m ON m.id = h.maquina_id
     ORDER BY h.quando DESC LIMIT 200`).all();
  return html`
    <h1>Histórico das licenças</h1>
    <div class="tabela"><table>
      <thead><tr><th>Quando</th><th>Máquina</th><th>O quê</th><th></th></tr></thead>
      <tbody>${linhas.length ? linhas.map((h) => html`<tr><td>${dataHora(h.quando, config)}</td>
        <td>${h.maquina_id ? html`<a href="/maquinas/${h.maquina_id}">${h.nome}</a>` : ''}</td><td>${h.acao}</td><td class="suave">${h.detalhe}</td></tr>`)
        : html`<tr><td colspan="4" class="suave">Nada ainda.</td></tr>`}</tbody>
    </table></div>`;
}

