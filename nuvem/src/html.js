// Pedaços de HTML do painel (renderizado no servidor, sem framework).

export function esc(v) {
  return String(v ?? '').replace(/[&<>"']/g, (c) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' })[c]);
}

/** Template com escape automático: html`<p>${texto}</p>`. Valores marcados com cru() entram sem escape. */
export function html(partes, ...valores) {
  let saida = partes[0];
  valores.forEach((v, i) => {
    saida += (Array.isArray(v) ? v.map(paraTexto).join('') : paraTexto(v)) + partes[i + 1];
  });
  return new Cru(saida);
}

class Cru {
  constructor(texto) {
    this.texto = texto;
  }

  toString() {
    return this.texto;
  }
}

export const cru = (t) => new Cru(t);
const paraTexto = (v) => (v instanceof Cru ? v.texto : v === null || v === undefined || v === false ? '' : esc(v));

export function reais(n) {
  if (n === null || n === undefined) return '—';
  const [inteiro, centavos] = Number(n).toFixed(2).split('.');
  return `R$ ${inteiro.replace(/\B(?=(\d{3})+(?!\d))/g, '.')},${centavos}`;
}

export function pagina({ titulo, csrf, ativo, conteudo, aviso, erro }) {
  const menu = csrf
    ? html`<nav>
        <a href="/maquinas" class="${ativo === 'maquinas' ? 'ativo' : ''}">Máquinas</a>
        <a href="/licencas" class="${ativo === 'licencas' ? 'ativo' : ''}">Enviar licença</a>
        <a href="/relatorio" class="${ativo === 'relatorio' ? 'ativo' : ''}">Relatório</a>
        <a href="/historico" class="${ativo === 'historico' ? 'ativo' : ''}">Histórico</a>
        <form method="post" action="/sair"><input type="hidden" name="csrf" value="${csrf}"><button class="link">Sair</button></form>
      </nav>`
    : '';
  return `<!doctype html>
<html lang="pt-BR">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>${esc(titulo)} · JukeLinux Nuvem</title>
<link rel="stylesheet" href="/estilo.css">
<script src="/painel.js" defer></script>
</head>
<body>
<header><a class="marca" href="/maquinas">JukeLinux <b>Nuvem</b></a>${menu}</header>
<main>
${aviso ? html`<p class="aviso">${aviso}</p>` : ''}
${erro ? html`<p class="erro">${erro}</p>` : ''}
${conteudo}
</main>
</body>
</html>`;
}

export const ESTILO = `
:root { --fundo: #f4f5f7; --cartao: #fff; --texto: #1d2230; --suave: #667085; --borda: #dfe3ea; --marca: #6d28d9;
  --verde: #0f7b3f; --verde-fundo: #e3f6ea; --vermelho: #b42318; --vermelho-fundo: #fde8e6; --amarelo: #8a5a00; --amarelo-fundo: #fff4d6; }
@media (prefers-color-scheme: dark) {
  :root { --fundo: #111318; --cartao: #1b1e26; --texto: #e7e9ee; --suave: #9aa3b2; --borda: #2c313c; --marca: #a78bfa;
    --verde: #5fd394; --verde-fundo: #13301f; --vermelho: #ff8a80; --vermelho-fundo: #3a1714; --amarelo: #f5c451; --amarelo-fundo: #33290f; }
}
* { box-sizing: border-box; }
body { margin: 0; font: 15px/1.45 system-ui, -apple-system, "Segoe UI", Roboto, sans-serif; background: var(--fundo); color: var(--texto); }
header { display: flex; flex-wrap: wrap; gap: 8px 20px; align-items: center; justify-content: space-between; padding: 12px 16px;
  background: var(--cartao); border-bottom: 1px solid var(--borda); }
.marca { color: var(--texto); text-decoration: none; font-size: 18px; }
.marca b { color: var(--marca); }
nav { display: flex; flex-wrap: wrap; gap: 4px 14px; align-items: center; }
nav a { color: var(--suave); text-decoration: none; padding: 4px 0; border-bottom: 2px solid transparent; }
nav a.ativo, nav a:hover { color: var(--texto); border-color: var(--marca); }
nav form { display: inline; }
main { max-width: 1100px; margin: 0 auto; padding: 16px; }
h1 { font-size: 22px; margin: 6px 0 14px; }
h2 { font-size: 17px; margin: 24px 0 10px; }
.cartao { background: var(--cartao); border: 1px solid var(--borda); border-radius: 10px; padding: 14px 16px; margin-bottom: 14px; }
.grade { display: grid; grid-template-columns: repeat(auto-fit, minmax(160px, 1fr)); gap: 10px; margin-bottom: 14px; }
.numero { background: var(--cartao); border: 1px solid var(--borda); border-radius: 10px; padding: 12px 14px; }
.numero span { display: block; color: var(--suave); font-size: 13px; }
.numero b { font-size: 22px; font-variant-numeric: tabular-nums; }
.tabela { overflow-x: auto; background: var(--cartao); border: 1px solid var(--borda); border-radius: 10px; margin-bottom: 14px; }
table { width: 100%; border-collapse: collapse; }
th, td { padding: 8px 10px; text-align: left; border-bottom: 1px solid var(--borda); white-space: nowrap; }
th { color: var(--suave); font-weight: 600; font-size: 13px; }
td.quebra { white-space: normal; }
td.n, th.n { text-align: right; font-variant-numeric: tabular-nums; }
tr:last-child td { border-bottom: 0; }
tfoot td { font-weight: 700; }
a { color: var(--marca); }
.selo { display: inline-block; padding: 1px 8px; border-radius: 999px; font-size: 12px; font-weight: 600; }
.selo.ativa, .selo.online { background: var(--verde-fundo); color: var(--verde); }
.selo.bloqueada, .selo.offline { background: var(--vermelho-fundo); color: var(--vermelho); }
.selo.pendente { background: var(--amarelo-fundo); color: var(--amarelo); }
.aviso { background: var(--verde-fundo); color: var(--verde); padding: 10px 14px; border-radius: 8px; }
.erro { background: var(--vermelho-fundo); color: var(--vermelho); padding: 10px 14px; border-radius: 8px; }
.suave { color: var(--suave); }
form.linha { display: flex; flex-wrap: wrap; gap: 10px; align-items: end; }
label { display: flex; flex-direction: column; gap: 4px; font-size: 13px; color: var(--suave); }
input, select, textarea { font: inherit; color: var(--texto); background: var(--fundo); border: 1px solid var(--borda); border-radius: 8px; padding: 7px 9px; min-width: 0; }
textarea { min-height: 60px; width: 100%; }
button { font: inherit; border: 0; border-radius: 8px; padding: 8px 14px; background: var(--marca); color: #fff; cursor: pointer; }
button.perigo { background: var(--vermelho); }
button.neutro { background: var(--borda); color: var(--texto); }
button.link { background: none; color: var(--suave); padding: 4px 0; }
.acoes { display: flex; flex-wrap: wrap; gap: 8px; }
.acoes form { display: inline; }
.barra { height: 8px; background: var(--marca); border-radius: 4px; min-width: 2px; }
.entrar { max-width: 360px; margin: 40px auto; }
.entrar form { display: flex; flex-direction: column; gap: 12px; }
code { font-size: 13px; }
@media print { header, form, .nao-imprimir { display: none !important; } body { background: #fff; color: #000; } .cartao, .tabela, .numero { border-color: #999; } }
`;

export const SCRIPT = `
document.addEventListener('submit', (e) => {
  const msg = e.target.getAttribute('data-confirmar');
  if (msg && !confirm(msg)) e.preventDefault();
});
document.addEventListener('click', (e) => {
  if (e.target.matches('[data-imprimir]')) window.print();
});
document.addEventListener('change', async (e) => {
  const alvo = e.target.getAttribute && e.target.getAttribute('data-preenche');
  if (alvo && e.target.files && e.target.files[0]) document.getElementById(alvo).value = await e.target.files[0].text();
});
`;
