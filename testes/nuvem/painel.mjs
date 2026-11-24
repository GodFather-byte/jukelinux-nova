// Faz o que a empresa faria (para os testes): gera a licença no gerador de licenças e envia pelo painel da nuvem.
//   node painel.mjs BASE SENHA liberar|bloquear     (a primeira máquina da lista)
//   node painel.mjs BASE SENHA csv                  (relatório de ontem a amanhã, em CSV, na saída)
//   node painel.mjs - - publica                     (a chave pública de desenvolvimento, para LICENCA_CHAVE_PUBLICA)
import { carregaNucleo, chaveDesenvolvimento } from '../licenca/gerador.mjs';

const [base, senha, acao] = process.argv.slice(2);
const Licencas = carregaNucleo();
const chave = await chaveDesenvolvimento(Licencas);

if (acao === 'publica') {
  console.log(Licencas.paraBase64(await Licencas.chavePublica(chave)));
  process.exit(0);
}

const login = await fetch(`${base}/entrar`, {
  method: 'POST', redirect: 'manual',
  headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
  body: new URLSearchParams({ usuario: 'admin', senha }),
});
if (login.status !== 303) throw new Error(`login falhou: ${login.status}`);
const cookie = login.headers.get('set-cookie').split(';')[0];
const get = (c) => fetch(`${base}${c}`, { headers: { Cookie: cookie } }).then((r) => r.text());

if (acao === 'csv') {
  const dia = (d) => new Date(Date.now() - 3 * 3_600_000 - 6 * 3_600_000 + d * 86_400_000).toISOString().slice(0, 10);
  process.stdout.write(await get(`/relatorio.csv?de=${dia(-1)}&ate=${dia(1)}`));
} else {
  const lista = await get('/maquinas');
  const id = /href="\/maquinas\/(\d+)"/.exec(lista)?.[1];
  if (!id) throw new Error('nenhuma máquina no painel');
  const maquina = await get(`/maquinas/${id}`);
  const codigo = /Código: <code>([\d-]+)<\/code>/.exec(maquina)?.[1];
  const csrf = /name="csrf" value="([^"]+)"/.exec(maquina)?.[1];
  const texto = await Licencas.gerarLicenca(chave, {
    codigo, cliente: 'Bar de Teste', situacao: acao === 'bloquear' ? 'bloqueada' : 'ativa', validade: 'permanente',
  });
  const r = await fetch(`${base}/licencas`, {
    method: 'POST', redirect: 'manual',
    headers: { Cookie: cookie, 'Content-Type': 'application/x-www-form-urlencoded' },
    body: new URLSearchParams({ csrf, licenca: texto }),
  });
  if (r.status !== 303) throw new Error(`${acao} falhou: ${r.status} ${await r.text()}`);
  console.log(`${acao}: licença enviada para ${codigo}`);
}
