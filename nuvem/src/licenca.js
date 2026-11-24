// Licença da jukebox. Quem assina é o gerador de licenças da empresa (ferramentas/licenca/gerador-de-licencas.html),
// que fica só no computador dela: a nuvem NÃO tem a chave privada. Ela recebe a licença pelo painel ("Enviar
// licença"), confere com a chave pública (LICENCA_CHAVE_PUBLICA) e repassa à máquina no próximo contato.
//
// Formato (texto, uma informação por linha; a assinatura Ed25519 cobre tudo antes da linha "assinatura=", com o \n):
//   JUKELINUX NOVA LICENCA 1
//   codigo=1020737342896379        16 dígitos da máquina
//   situacao=ativa                 ativa ou bloqueada
//   validade=permanente            ou AAAA-MM-DD (último dia que vale)
//   contato_ate=nunca
//   cliente=Bar do Zé              só para mostrar
//   emitida=1795500000             segundos desde 1970 (UTC); a jukebox nunca troca uma licença por outra mais antiga
//   assinatura=<base64>
import { verify } from 'node:crypto';

export const CABECALHO = 'JUKELINUX NOVA LICENCA 1';

/**
 * Lê e confere uma licença. Com `chavePublica`, a assinatura precisa conferir; sem ela, só o formato.
 * Devolve os campos ou null.
 */
export function conferirLicenca(texto, chavePublica) {
  const normal = String(texto ?? '').replace(/\r/g, '');
  const i = normal.lastIndexOf('\nassinatura=');
  if (i < 0) return null;
  const corpo = normal.slice(0, i + 1);
  const assinatura = Buffer.from(normal.slice(i + '\nassinatura='.length).trim(), 'base64');
  if (assinatura.length !== 64) return null;
  if (chavePublica && !verify(null, Buffer.from(corpo, 'utf8'), chavePublica, assinatura)) return null;
  const linhas = corpo.trimEnd().split('\n');
  if (linhas[0] !== CABECALHO) return null;
  const campos = Object.fromEntries(linhas.slice(1).map((l) => [l.slice(0, l.indexOf('=')), l.slice(l.indexOf('=') + 1)]));
  if (!/^\d{16}$/.test(campos.codigo ?? '') || !['ativa', 'bloqueada'].includes(campos.situacao)) return null;
  if (campos.validade !== 'permanente' && !/^\d{4}-\d{2}-\d{2}$/.test(campos.validade ?? '')) return null;
  if (!/^\d+$/.test(campos.emitida ?? '')) return null;
  return { ...campos, texto: `${corpo}assinatura=${assinatura.toString('base64')}\n` };
}
