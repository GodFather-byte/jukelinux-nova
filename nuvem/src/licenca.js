// Licença assinada pela nuvem (Ed25519). A jukebox confere a assinatura com a chave pública embutida no
// executável (src/licenca_publica.inc), sem internet: só quem tem a chave privada (esta nuvem) emite licença.
//
// Formato (texto, uma informação por linha; a assinatura cobre tudo antes da linha "assinatura=", com o \n final):
//   JUKELINUX NOVA LICENCA 1
//   codigo=1020737342896379        16 dígitos da máquina
//   situacao=ativa                 ativa ou bloqueada
//   validade=permanente            ou AAAA-MM-DD (último dia que vale)
//   contato_ate=nunca              ou AAAA-MM-DD: sem falar com a nuvem até esse dia, a jukebox bloqueia
//   cliente=Bar do Zé              só para mostrar (sem quebra de linha)
//   emitida=1795500000             segundos desde 1970 (UTC); a jukebox nunca troca uma licença por outra mais antiga
//   assinatura=<base64>
import { sign, verify, createPublicKey } from 'node:crypto';

export const CABECALHO = 'JUKELINUX NOVA LICENCA 1';
const DIA_MS = 86_400_000;

const umaLinha = (texto) => String(texto ?? '').replace(/[\r\n]+/g, ' ').trim().slice(0, 80);

function dataMaisDias(agoraMs, dias, fusoMinutos) {
  return new Date(agoraMs + fusoMinutos * 60_000 + dias * DIA_MS).toISOString().slice(0, 10);
}

/** Corpo da licença (o que é assinado). */
export function corpoLicenca(maquina, agoraMs, fusoMinutos) {
  const contatoAte = maquina.contato_dias > 0 ? dataMaisDias(agoraMs, maquina.contato_dias, fusoMinutos) : 'nunca';
  return [
    CABECALHO,
    `codigo=${maquina.codigo}`,
    `situacao=${maquina.situacao === 'bloqueada' ? 'bloqueada' : 'ativa'}`,
    `validade=${maquina.validade || 'permanente'}`,
    `contato_ate=${contatoAte}`,
    `cliente=${umaLinha(maquina.cliente || maquina.nome)}`,
    `emitida=${Math.floor(agoraMs / 1000)}`,
  ].join('\n') + '\n';
}

/** Licença completa (corpo + assinatura). Só para máquinas liberadas ou bloqueadas (pendente não recebe). */
export function emitirLicenca(maquina, chavePrivada, agoraMs, fusoMinutos) {
  if (!chavePrivada) throw new Error('Sem LICENCA_CHAVE_PRIVADA a nuvem não emite licenças');
  const corpo = corpoLicenca(maquina, agoraMs, fusoMinutos);
  const assinatura = sign(null, Buffer.from(corpo, 'utf8'), chavePrivada).toString('base64');
  return `${corpo}assinatura=${assinatura}\n`;
}

/** Confere uma licença (usado nos testes e na tela da máquina). Devolve os campos ou null. */
export function conferirLicenca(texto, chavePublica) {
  const i = texto.lastIndexOf('assinatura=');
  if (i < 0) return null;
  const corpo = texto.slice(0, i);
  const assinatura = Buffer.from(texto.slice(i + 'assinatura='.length).trim(), 'base64');
  const publica = typeof chavePublica === 'string' ? createPublicKey(chavePublica) : chavePublica;
  if (!verify(null, Buffer.from(corpo, 'utf8'), publica, assinatura)) return null;
  const linhas = corpo.trimEnd().split('\n');
  if (linhas[0] !== CABECALHO) return null;
  return Object.fromEntries(linhas.slice(1).map((l) => [l.slice(0, l.indexOf('=')), l.slice(l.indexOf('=') + 1)]));
}

/** Chave pública em 32 bytes (o que vai para src/licenca_publica.inc). */
export function chavePublicaCrua(chavePrivada) {
  const der = createPublicKey(chavePrivada).export({ format: 'der', type: 'spki' });
  return der.subarray(der.length - 32);
}
