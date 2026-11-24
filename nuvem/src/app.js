// Roteador HTTP da nuvem: API das máquinas (/api/v1/contato) e painel da empresa.
import { tratarContato, ErroContato } from './contato.js';
import { pagina, html, ESTILO, SCRIPT } from './html.js';
import {
  confereLogin, Freio, criaSessao, sessaoDe, encerraSessao, cookieSessao, csrfConfere,
} from './sessao.js';
import {
  paginaMaquinas, paginaMaquina, acaoMaquina, licencaParaBaixar, paginaRelatorio, paginaHistorico,
  paginaEnviarLicenca, enviarLicenca,
} from './painel.js';
import { gerar, paraCsv, ErroRelatorio } from './relatorio.js';
import { hoje, somaDias } from './tempo.js';

const MAX_CORPO = 1024 * 1024;
const SEGURANCA = {
  'Content-Security-Policy': "default-src 'self'; style-src 'self' 'unsafe-inline'; script-src 'self'; img-src 'self' data:; form-action 'self'; frame-ancestors 'none'; base-uri 'none'",
  'X-Content-Type-Options': 'nosniff',
  'Referrer-Policy': 'same-origin',
  'X-Frame-Options': 'DENY',
};

function lerCorpo(req) {
  return new Promise((resolve, reject) => {
    const partes = [];
    let tamanho = 0;
    req.on('data', (p) => {
      tamanho += p.length;
      if (tamanho > MAX_CORPO) {
        reject(Object.assign(new Error('Corpo grande demais'), { status: 413 }));
        req.destroy();
        return;
      }
      partes.push(p);
    });
    req.on('end', () => resolve(Buffer.concat(partes).toString('utf8')));
    req.on('error', reject);
  });
}

function responder(res, status, corpo, tipo = 'text/html; charset=utf-8', extras = {}) {
  res.writeHead(status, { 'Content-Type': tipo, 'Cache-Control': 'no-store', ...SEGURANCA, ...extras });
  res.end(corpo);
}

const json = (res, status, obj) => responder(res, status, JSON.stringify(obj), 'application/json; charset=utf-8');
const redirecionar = (res, para, extras = {}) => {
  res.writeHead(303, { Location: para, 'Cache-Control': 'no-store', ...SEGURANCA, ...extras });
  res.end();
};

function ipDe(req, config) {
  if (config.confiarProxy && req.headers['x-forwarded-for']) return String(req.headers['x-forwarded-for']).split(',')[0].trim();
  return req.socket.remoteAddress || '';
}

export function criarApp(db, config) {
  const freio = new Freio();
  // Mensagem de um POST para a página seguinte (POST → redirecionamento → GET), guardada na sessão.
  const recados = new Map();
  const comMensagem = (sessao, caminho, msg) => {
    recados.set(sessao.token_hash, msg);
    return caminho;
  };

  async function painel(req, res, url, sessao) {
    const msgs = req.method === 'GET' ? recados.get(sessao.token_hash) ?? {} : {};
    if (req.method === 'GET') recados.delete(sessao.token_hash);
    const p = url.pathname;
    const mostra = (titulo, ativo, conteudo, extras = {}) => responder(res, 200,
      pagina({ titulo, csrf: sessao.csrf, ativo, conteudo, ...msgs, ...extras }));

    if (req.method === 'GET' && (p === '/' || p === '/maquinas')) return mostra('Máquinas', 'maquinas', paginaMaquinas(db, config));
    if (req.method === 'GET' && p === '/historico') return mostra('Histórico', 'historico', paginaHistorico(db, config));
    if (req.method === 'GET' && p === '/licencas') return mostra('Enviar licença', 'licencas', paginaEnviarLicenca(config, sessao.csrf));
    if (req.method === 'POST' && p === '/licencas') {
      const campos = Object.fromEntries(new URLSearchParams(await lerCorpo(req)));
      if (!csrfConfere(sessao, campos.csrf)) return responder(res, 403, 'Formulário vencido: volte e tente de novo.', 'text/plain; charset=utf-8');
      const r = enviarLicenca(db, config, campos.licenca);
      if (r.erro && !r.id) {
        return responder(res, 400, pagina({ titulo: 'Enviar licença', csrf: sessao.csrf, ativo: 'licencas',
          conteudo: paginaEnviarLicenca(config, sessao.csrf), erro: r.erro }));
      }
      return redirecionar(res, comMensagem(sessao, `/maquinas/${r.id}`, { aviso: r.aviso, erro: r.erro }));
    }
    if (req.method === 'GET' && p === '/relatorio') {
      const r = paginaRelatorio(db, config, url.searchParams);
      return mostra('Relatório', 'relatorio', r.conteudo, r.erro ? { erro: r.erro } : {});
    }
    if (req.method === 'GET' && p === '/relatorio.csv') {
      const dia = hoje(config);
      try {
        const r = gerar(db, config, {
          de: url.searchParams.get('de') || somaDias(dia, -6),
          ate: url.searchParams.get('ate') || dia,
          maquinaId: Number(url.searchParams.get('maquina')) || null,
        });
        return responder(res, 200, paraCsv(r), 'text/csv; charset=utf-8',
          { 'Content-Disposition': `attachment; filename="relatorio-${r.de}-a-${r.ate}.csv"` });
      } catch (e) {
        if (e instanceof ErroRelatorio) return responder(res, 400, e.message, 'text/plain; charset=utf-8');
        throw e;
      }
    }

    const m = /^\/maquinas\/(\d+)(?:\/([a-z.-]+))?$/.exec(p);
    if (m) {
      const id = Number(m[1]);
      const acao = m[2];
      if (req.method === 'GET' && !acao) {
        const conteudo = paginaMaquina(db, config, id, sessao.csrf);
        if (!conteudo) return redirecionar(res, comMensagem(sessao, '/maquinas', { erro: 'Máquina não encontrada.' }));
        return mostra('Máquina', 'maquinas', conteudo);
      }
      if (req.method === 'GET' && acao === 'licenca.txt') {
        const texto = licencaParaBaixar(db, id);
        if (!texto) return redirecionar(res, comMensagem(sessao, `/maquinas/${id}`, { erro: 'Ainda não foi enviada licença para esta máquina.' }));
        return responder(res, 200, texto, 'text/plain; charset=utf-8', { 'Content-Disposition': 'attachment; filename="licenca.txt"' });
      }
      if (req.method === 'POST' && acao) {
        const campos = Object.fromEntries(new URLSearchParams(await lerCorpo(req)));
        if (!csrfConfere(sessao, campos.csrf)) return responder(res, 403, 'Formulário vencido: volte e tente de novo.', 'text/plain; charset=utf-8');
        const r = acaoMaquina(db, config, id, acao, campos);
        return redirecionar(res, comMensagem(sessao, r.excluida ? '/maquinas' : `/maquinas/${id}`, { aviso: r.aviso, erro: r.erro }));
      }
    }
    return responder(res, 404, pagina({ titulo: 'Não encontrado', csrf: sessao.csrf, conteudo: html`<h1>Página não encontrada</h1>` }));
  }

  async function tratar(req, res) {
    const url = new URL(req.url, 'http://nuvem');
    const p = url.pathname;

    if (p === '/saude') return json(res, 200, { ok: true });
    if (p === '/estilo.css') return responder(res, 200, ESTILO, 'text/css; charset=utf-8', { 'Cache-Control': 'max-age=3600' });
    if (p === '/painel.js') return responder(res, 200, SCRIPT, 'text/javascript; charset=utf-8', { 'Cache-Control': 'max-age=3600' });

    if (p === '/api/v1/contato') {
      if (req.method !== 'POST') return json(res, 405, { erro: 'Use POST' });
      try {
        let corpo;
        try {
          corpo = JSON.parse(await lerCorpo(req));
        } catch (e) {
          if (e.status) throw e;
          throw new ErroContato(400, 'JSON inválido');
        }
        const auth = String(req.headers.authorization || '');
        const segredo = auth.startsWith('Bearer ') ? auth.slice(7).trim() : '';
        return json(res, 200, tratarContato(db, config, { corpo, segredo, ip: ipDe(req, config) }));
      } catch (e) {
        if (e instanceof ErroContato || e.status) return json(res, e.status || 400, { erro: e.message });
        throw e;
      }
    }

    if (p === '/entrar') {
      const ip = ipDe(req, config);
      if (req.method === 'POST') {
        const campos = Object.fromEntries(new URLSearchParams(await lerCorpo(req)));
        if (freio.bloqueado(ip)) {
          return responder(res, 429, telaEntrar('Muitas tentativas erradas. Espere 5 minutos.'));
        }
        if (!confereLogin(config, campos.usuario, campos.senha)) {
          freio.erro(ip);
          return responder(res, 401, telaEntrar('Usuário ou senha errados.'));
        }
        freio.acerto(ip);
        const { token } = criaSessao(db);
        return redirecionar(res, '/maquinas', { 'Set-Cookie': cookieSessao(config, token) });
      }
      return responder(res, 200, telaEntrar(''));
    }

    const sessao = sessaoDe(db, req);
    if (p === '/sair' && req.method === 'POST') {
      encerraSessao(db, req);
      return redirecionar(res, '/entrar', { 'Set-Cookie': cookieSessao(config, null) });
    }
    if (!sessao) return redirecionar(res, '/entrar');
    return painel(req, res, url, sessao);
  }

  return async (req, res) => {
    try {
      await tratar(req, res);
    } catch (e) {
      if (e.status === 413) return json(res, 413, { erro: e.message });
      console.error('Erro:', e);
      if (!res.headersSent) responder(res, 500, 'Erro interno', 'text/plain; charset=utf-8');
    }
  };
}

function telaEntrar(erro) {
  return pagina({
    titulo: 'Entrar',
    erro,
    conteudo: html`<div class="entrar cartao"><h1>Entrar</h1>
      <form method="post" action="/entrar">
        <label>Usuário<input name="usuario" autocomplete="username" required></label>
        <label>Senha<input name="senha" type="password" autocomplete="current-password" required></label>
        <button>Entrar</button>
      </form></div>`,
  });
}
