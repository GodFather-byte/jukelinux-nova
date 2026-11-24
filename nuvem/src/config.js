// Configuração da nuvem, tirada das variáveis de ambiente (veja LEIA-ME.md).
import { readFileSync } from 'node:fs';
import { createPrivateKey } from 'node:crypto';

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

function chavePrivada(env) {
  let pem = env.LICENCA_CHAVE_PRIVADA;
  if (!pem && env.LICENCA_CHAVE_PRIVADA_ARQUIVO) pem = readFileSync(env.LICENCA_CHAVE_PRIVADA_ARQUIVO, 'utf8');
  if (!pem) return null;
  // Em painéis de hospedagem a quebra de linha às vezes vira "\n" literal.
  const chave = createPrivateKey(pem.replace(/\\n/g, '\n'));
  if (chave.asymmetricKeyType !== 'ed25519') throw new Error('A chave das licenças precisa ser Ed25519');
  return chave;
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
    chavePrivada: chavePrivada(env),
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
  if (!config.chavePrivada && producao) {
    throw new Error('Defina LICENCA_CHAVE_PRIVADA (ou LICENCA_CHAVE_PRIVADA_ARQUIVO): sem ela a nuvem não emite licenças');
  }
  return config;
}
