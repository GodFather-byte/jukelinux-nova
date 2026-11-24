// Contato das máquinas: POST /api/v1/contato.
//
// A jukebox chama a cada INTERVALO_CONTATO segundos (quando tem internet) e manda o que juntou na fila desde o
// último contato. A nuvem guarda os eventos (cada um só uma vez, pelo id), atualiza os relógios e devolve a licença
// da máquina assinada. Sem internet a jukebox continua funcionando: a fila espera e vai no próximo contato.
//
// Identificação: a máquina manda o código dela (16 dígitos) e um segredo que ela mesma sorteou na primeira vez
// (Authorization: Bearer). A nuvem guarda o hash do segredo no 1º contato; depois disso, outro aparelho com o
// mesmo código é recusado (e o painel avisa). "Esquecer o aparelho" no painel libera para uma máquina reinstalada.
import { createHash, timingSafeEqual } from 'node:crypto';
import { transacao, registrar } from './banco.js';
import { emitirLicenca } from './licenca.js';

export const MAX_EVENTOS = 500;
const TIPOS = new Set(['credito', 'musica', 'fechamento', 'ligou']);
const ORIGENS = new Set(['noteiro', 'pix']);
const ID_EVENTO = /^[A-Za-z0-9._-]{1,64}$/;
const SEGUNDOS_2020 = 1_577_836_800;

export class ErroContato extends Error {
  constructor(status, mensagem) {
    super(mensagem);
    this.status = status;
  }
}

const hashSegredo = (segredo) => createHash('sha256').update(segredo).digest('hex');

function mesmoHash(a, b) {
  const x = Buffer.from(a, 'hex');
  const y = Buffer.from(b, 'hex');
  return x.length === y.length && timingSafeEqual(x, y);
}

const texto = (v, max) => (typeof v === 'string' ? v.replace(/[\u0000-\u001f]/g, ' ').trim().slice(0, max) : '');

function inteiro(v, min, max) {
  const n = typeof v === 'string' && v.trim() !== '' ? Number(v) : v;
  return Number.isInteger(n) && n >= min && n <= max ? n : null;
}

/** Valida um evento vindo da máquina. Devolve a linha para o banco ou null (evento inválido, descartado). */
export function normalizarEvento(e, agoraMs) {
  if (!e || typeof e !== 'object' || !ID_EVENTO.test(e.id ?? '') || !TIPOS.has(e.tipo)) return null;
  let quando = inteiro(e.quando, SEGUNDOS_2020, 4_102_444_800);
  // relógio da máquina muito adiantado: vale a hora em que chegou
  quando = quando === null || quando * 1000 > agoraMs + 86_400_000 ? agoraMs : quando * 1000;
  const linha = { evento_id: e.id, tipo: e.tipo, quando, origem: '', reais: 0, creditos: 0, cd: '', musica: '', dados: null };

  if (e.tipo === 'credito') {
    if (!ORIGENS.has(e.origem)) return null;
    linha.origem = e.origem;
    linha.reais = inteiro(e.reais, 1, 100_000);
    linha.creditos = inteiro(e.creditos ?? 0, 0, 100_000);
    if (linha.reais === null || linha.creditos === null) return null;
  } else if (e.tipo === 'musica') {
    linha.cd = texto(e.cd, 200);
    linha.musica = texto(e.musica, 200);
    linha.creditos = inteiro(e.creditos ?? 1, 0, 100) ?? 1;
    if (!linha.musica) return null;
  } else if (e.tipo === 'fechamento') {
    linha.reais = inteiro(e.parcial, 0, 100_000_000);
    if (linha.reais === null) return null;
    linha.dados = JSON.stringify({
      pix: inteiro(e.pix ?? 0, 0, 100_000_000) ?? 0,
      ponto: inteiro(e.ponto ?? 0, 0, 100_000_000) ?? 0,
    });
  } else if (e.tipo === 'ligou') {
    linha.dados = JSON.stringify({ versao: texto(e.versao, 40) });
  }
  return linha;
}

function normalizarRelogio(r) {
  if (!r || typeof r !== 'object') return null;
  const campos = ['total', 'parcial', 'pix_parcial', 'pix_total', 'ponto_pct', 'creditos'];
  const saida = {};
  for (const c of campos) {
    const n = inteiro(r[c], 0, 1_000_000_000);
    if (n !== null) saida[c] = n;
  }
  return Object.keys(saida).length ? JSON.stringify(saida) : null;
}

/**
 * Trata um contato. `corpo` é o JSON já lido; `segredo` vem do cabeçalho Authorization.
 * Devolve a resposta para a máquina.
 */
export function tratarContato(db, config, { corpo, segredo, ip }, agoraMs = Date.now()) {
  if (!corpo || typeof corpo !== 'object') throw new ErroContato(400, 'JSON inválido');
  const codigo = String(corpo.codigo ?? '').replace(/\D/g, '');
  if (codigo.length !== 16) throw new ErroContato(400, 'Código da máquina inválido');
  if (typeof segredo !== 'string' || segredo.length < 32 || segredo.length > 200) {
    throw new ErroContato(401, 'Sem o segredo da máquina');
  }
  const eventos = Array.isArray(corpo.eventos) ? corpo.eventos : [];
  if (eventos.length > MAX_EVENTOS) throw new ErroContato(413, `No máximo ${MAX_EVENTOS} eventos por contato`);

  const hash = hashSegredo(segredo);
  const versao = texto(corpo.versao, 40);
  const relogio = normalizarRelogio(corpo.relogio);

  const resposta = transacao(db, () => {
    let maquina = db.prepare('SELECT * FROM maquinas WHERE codigo = ?').get(codigo);
    if (!maquina) {
      const nome = texto(corpo.nome, 60) || `Máquina ${codigo.slice(-4)}`;
      db.prepare(`INSERT INTO maquinas (codigo, segredo_hash, nome, criada_em) VALUES (?, ?, ?, ?)`)
        .run(codigo, hash, nome, agoraMs);
      maquina = db.prepare('SELECT * FROM maquinas WHERE codigo = ?').get(codigo);
      registrar(db, maquina.id, 'primeiro contato', `aguardando liberação (IP ${ip || '?'})`);
    } else if (!maquina.segredo_hash) {
      db.prepare('UPDATE maquinas SET segredo_hash = ? WHERE id = ?').run(hash, maquina.id);
      registrar(db, maquina.id, 'aparelho novo', `pareado de novo (IP ${ip || '?'})`);
    } else if (!mesmoHash(maquina.segredo_hash, hash)) {
      return { intruso: maquina.id };
    }

    const recebidos = [];
    let rejeitados = 0;
    const inserir = db.prepare(`
      INSERT OR IGNORE INTO eventos (maquina_id, evento_id, tipo, quando, recebido_em, origem, reais, creditos, cd, musica, dados)
      VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)`);
    for (const e of eventos) {
      const linha = normalizarEvento(e, agoraMs);
      if (!linha) {
        rejeitados++;
        // descarta da fila da máquina também (um evento estragado não pode travar os outros)
        if (typeof e?.id === 'string' && ID_EVENTO.test(e.id)) recebidos.push(e.id);
        continue;
      }
      inserir.run(maquina.id, linha.evento_id, linha.tipo, linha.quando, agoraMs, linha.origem, linha.reais,
        linha.creditos, linha.cd, linha.musica, linha.dados);
      recebidos.push(linha.evento_id);
    }

    db.prepare(`UPDATE maquinas SET ultimo_contato = ?, versao = ?, ip = ?, relogio = COALESCE(?, relogio) WHERE id = ?`)
      .run(agoraMs, versao, ip || '', relogio, maquina.id);

    let licenca = null;
    if (maquina.situacao !== 'pendente' && config.chavePrivada) {
      licenca = emitirLicenca(maquina, config.chavePrivada, agoraMs, config.fusoMinutos);
      db.prepare('UPDATE maquinas SET licenca_emitida = ? WHERE id = ?').run(agoraMs, maquina.id);
    }

    return {
      situacao: maquina.situacao,
      licenca,
      // a mesma licença em base64 (só ASCII): a jukebox decodifica os bytes exatos, sem conversão de página de código
      licenca_b64: licenca ? Buffer.from(licenca, 'utf8').toString('base64') : null,
      recebidos,
      rejeitados,
      intervalo: config.intervaloContato,
      agora: Math.floor(agoraMs / 1000),
    };
  });
  if (resposta.intruso) {
    // fora da transação: o aviso fica gravado mesmo com a recusa
    db.prepare('UPDATE maquinas SET intruso_em = ? WHERE id = ?').run(agoraMs, resposta.intruso);
    throw new ErroContato(403, 'Outro aparelho já usa o código desta máquina. Fale com a empresa.');
  }
  return resposta;
}
