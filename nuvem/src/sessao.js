// Login do painel: um usuário (ADMIN_USUARIO / ADMIN_SENHA), sessão por cookie e token CSRF nos formulários.
import { createHash, randomBytes, timingSafeEqual } from 'node:crypto';

const DURACAO_MS = 30 * 86_400_000;
const COOKIE = 'nuvem_sessao';
const TENTATIVAS = 5;
const BLOQUEIO_MS = 5 * 60_000;

const sha = (t) => createHash('sha256').update(t).digest();
const hex = (t) => sha(t).toString('hex');

export function confereLogin(config, usuario, senha) {
  if (!config.adminSenha) return false;
  const u = timingSafeEqual(sha(String(usuario ?? '')), sha(config.adminUsuario));
  const s = timingSafeEqual(sha(String(senha ?? '')), sha(config.adminSenha));
  return u && s;
}

/** Freio para quem fica chutando a senha: 5 erros por IP e espera 5 minutos. */
export class Freio {
  constructor() {
    this.ips = new Map();
  }

  bloqueado(ip, agora = Date.now()) {
    const r = this.ips.get(ip);
    return Boolean(r && r.ate > agora);
  }

  erro(ip, agora = Date.now()) {
    const r = this.ips.get(ip) ?? { erros: 0, ate: 0 };
    r.erros += 1;
    if (r.erros >= TENTATIVAS) {
      r.erros = 0;
      r.ate = agora + BLOQUEIO_MS;
    }
    this.ips.set(ip, r);
  }

  acerto(ip) {
    this.ips.delete(ip);
  }
}

export function criaSessao(db, agora = Date.now()) {
  const token = randomBytes(32).toString('base64url');
  const csrf = randomBytes(24).toString('base64url');
  db.prepare('DELETE FROM sessoes WHERE expira_em < ?').run(agora);
  db.prepare('INSERT INTO sessoes (token_hash, csrf, expira_em) VALUES (?, ?, ?)').run(hex(token), csrf, agora + DURACAO_MS);
  return { token, csrf };
}

export function leCookies(req) {
  const saida = {};
  for (const parte of (req.headers.cookie || '').split(';')) {
    const i = parte.indexOf('=');
    if (i > 0) saida[parte.slice(0, i).trim()] = decodeURIComponent(parte.slice(i + 1).trim());
  }
  return saida;
}

/** Sessão do pedido, ou null. */
export function sessaoDe(db, req, agora = Date.now()) {
  const token = leCookies(req)[COOKIE];
  if (!token) return null;
  const s = db.prepare('SELECT token_hash, csrf, expira_em FROM sessoes WHERE token_hash = ?').get(hex(token));
  if (!s || s.expira_em < agora) return null;
  return s;
}

export function encerraSessao(db, req) {
  const token = leCookies(req)[COOKIE];
  if (token) db.prepare('DELETE FROM sessoes WHERE token_hash = ?').run(hex(token));
}

export function cookieSessao(config, token) {
  const seguro = config.cookieSeguro ? '; Secure' : '';
  if (!token) return `${COOKIE}=; Path=/; HttpOnly; SameSite=Strict; Max-Age=0${seguro}`;
  return `${COOKIE}=${encodeURIComponent(token)}; Path=/; HttpOnly; SameSite=Strict; Max-Age=${DURACAO_MS / 1000}${seguro}`;
}

export function csrfConfere(sessao, enviado) {
  if (!sessao || typeof enviado !== 'string') return false;
  const a = Buffer.from(sessao.csrf);
  const b = Buffer.from(enviado);
  return a.length === b.length && timingSafeEqual(a, b);
}
