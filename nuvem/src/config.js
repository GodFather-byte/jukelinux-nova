// Configuração da nuvem, tirada das variáveis de ambiente (veja LEIA-ME.md).
import { createPublicKey } from 'node:crypto';

const FUSO = /^([+-])(\d{2}):(\d{2})$/;

function minutosDoFuso(texto) {
  const m = FUSO.exec(texto);
  if (!m) throw new Error(`FUSO_HORARIO inválido: "${texto}" (use, por exemplo, -03:00)`);
  const minutos = Number(m[2]) * 60 + Number(m[3]);
  return m[1] === '-' ? -minutos : minutos;
}

function inteiro(nome, texto, padrao, min, max) {
  if (texto === undefined || texto === '') return padrao;
  const n = Number(texto);
  if (!Number.isInteger(n) || n < min || n > max) throw new Error(`${nome} deve ser um número inteiro de ${min} a ${max}`);
  return n;
}

/**
 * Chave PÚBLICA das licenças (a que o gerador de licenças mostra, em base64). A nuvem não tem a privada: só confere
 * se a licença enviada pelo painel foi mesmo assinada pela empresa antes de repassar à máquina.
 */
function chavePublica(env) {
  const texto = (env.LICENCA_CHAVE_PUBLICA || '').trim();
  if (!texto) return null;
  if (texto.includes('BEGIN PUBLIC KEY')) return createPublicKey(texto.replace(/\\n/g, '\n'));
  const bytes = Buffer.from(texto, 'base64');
  if (bytes.length !== 32) throw new Error('LICENCA_CHAVE_PUBLICA deve ter 32 bytes em base64 (como o gerador de licenças mostra)');
  return createPublicKey({ key: { kty: 'OKP', crv: 'Ed25519', x: bytes.toString('base64url') }, format: 'jwk' });
}

/** Monta a configuração. `env` é process.env (ou um objeto nos testes). */
export function lerConfig(env = process.env) {
  const producao = env.NODE_ENV === 'production';
  const config = {
    producao,
    porta: inteiro('PORTA', env.PORTA ?? env.PORT, 8080, 1, 65535),
    host: env.HOST || '0.0.0.0',
    banco: env.BANCO || 'dados/nuvem.db',
    adminUsuario: env.ADMIN_USUARIO || 'admin',
    adminSenha: env.ADMIN_SENHA || '',
    chavePublica: chavePublica(env),
    fusoMinutos: minutosDoFuso(env.FUSO_HORARIO || '-03:00'),
    viradaDoDia: inteiro('VIRADA_DO_DIA', env.VIRADA_DO_DIA, 6, 0, 12),
    intervaloContato: inteiro('INTERVALO_CONTATO', env.INTERVALO_CONTATO, 60, 10, 3600),
    // Atrás de um proxy HTTPS (Render, Cloudflare...), o cookie só vai por HTTPS.
    cookieSeguro: env.COOKIE_SEGURO ? env.COOKIE_SEGURO === '1' : producao,
    confiarProxy: env.CONFIAR_PROXY ? env.CONFIAR_PROXY === '1' : producao,
  };
  if (config.adminSenha.length < 10) {
    if (producao) throw new Error('Defina ADMIN_SENHA com pelo menos 10 caracteres');
  }
  return config;
}
