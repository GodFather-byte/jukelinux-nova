// Carrega o núcleo do gerador de licenças (o <script id="nucleo"> de ferramentas/licenca/gerador-de-licencas.html)
// para os testes assinarem licenças com exatamente o mesmo código que a empresa usa.
import { readFileSync } from 'node:fs';
import { runInNewContext } from 'node:vm';

const HTML = new URL('../../ferramentas/licenca/gerador-de-licencas.html', import.meta.url);
const CHAVE_DESENVOLVIMENTO = new URL('../../nuvem/testes/chave-desenvolvimento.pem', import.meta.url);

export function carregaNucleo() {
  const html = readFileSync(HTML, 'utf8');
  const m = /<script id="nucleo">\n([\s\S]*?)<\/script>/.exec(html);  // o 1º <script id="nucleo"> do arquivo é o do comentário
  if (!m) throw new Error('não achei o <script id="nucleo"> no gerador');
  const contexto = { crypto: globalThis.crypto, TextEncoder, btoa, atob, Date, Math, Number, String, Array, Uint8Array, JSON, Error };
  contexto.globalThis = contexto;
  runInNewContext(m[1], contexto);
  return contexto.Licencas;
}

/** A chave de desenvolvimento (a privada está no git: só para testes). */
export async function chaveDesenvolvimento(Licencas = carregaNucleo()) {
  return Licencas.importaChave(readFileSync(CHAVE_DESENVOLVIMENTO, 'utf8'));
}
