// Mexe no painel da nuvem como a empresa faria (para os testes).
//   node painel.mjs BASE SENHA liberar|bloquear     (a primeira máquina da lista)
//   node painel.mjs BASE SENHA csv                  (relatório de ontem a amanhã, em CSV, na saída)
const [base, senha, acao] = process.argv.slice(2);

const login = await fetch(`${base}/entrar`, {
  method: 'POST', redirect: 'manual',
  headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
  body: new URLSearchParams({ usuario: 'admin', senha }),
});
if (login.status !== 303) throw new Error(`login falhou: ${login.status}`);
const cookie = login.headers.get('set-cookie').split(';')[0];
const get = (c) => fetch(`${base}${c}`, { headers: { Cookie: cookie } }).then((r) => r.text());

const lista = await get('/maquinas');
const id = /href="\/maquinas\/(\d+)"/.exec(lista)?.[1];
const csrf = /name="csrf" value="([^"]+)"/.exec(lista)?.[1];

if (acao === 'csv') {
  const dia = (d) => new Date(Date.now() - 3 * 3_600_000 - 6 * 3_600_000 + d * 86_400_000).toISOString().slice(0, 10);
  process.stdout.write(await get(`/relatorio.csv?de=${dia(-1)}&ate=${dia(1)}`));
} else {
  if (!id) throw new Error('nenhuma máquina no painel');
  const r = await fetch(`${base}/maquinas/${id}/${acao}`, {
    method: 'POST', redirect: 'manual',
    headers: { Cookie: cookie, 'Content-Type': 'application/x-www-form-urlencoded' },
    body: new URLSearchParams({ csrf }),
  });
  if (r.status !== 303) throw new Error(`${acao} falhou: ${r.status}`);
  console.log(`${acao}: máquina ${id}`);
}
