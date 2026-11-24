import { test, before, after } from 'node:test';
import assert from 'node:assert/strict';
import { createServer } from 'node:http';
import { readFileSync } from 'node:fs';
import { createPublicKey, createPrivateKey } from 'node:crypto';
import { abrirBanco } from '../src/banco.js';
import { criarApp } from '../src/app.js';
import { lerConfig } from '../src/config.js';
import { conferirLicenca } from '../src/licenca.js';
import { gerar, paraCsv } from '../src/relatorio.js';
import { diaDe, inicioDoDia } from '../src/tempo.js';
import { carregaNucleo, chaveDesenvolvimento } from '../../testes/licenca/gerador.mjs';

// As licenças são feitas pelo próprio gerador de licenças (núcleo do HTML) com a chave de desenvolvimento.
const Licencas = carregaNucleo();
const chave = await chaveDesenvolvimento(Licencas);
const publicaBytes = await Licencas.chavePublica(chave);
const PUBLICA_B64 = Licencas.paraBase64(publicaBytes);
const publica = createPublicKey(createPrivateKey(readFileSync(new URL('./chave-desenvolvimento.pem', import.meta.url))));

const SEGREDO = 'segredo-da-maquina-de-teste-com-mais-de-32-letras';
const CODIGO = '1020737342896379';
let emitida = Math.floor(Date.now() / 1000) - 100;
const licenca = (extra = {}) => Licencas.gerarLicenca(chave, { codigo: CODIGO, cliente: 'Bar do Teste', situacao: 'ativa',
  validade: 'permanente', emitida: ++emitida, ...extra });

let servidor;
let base;
let db;
let config;
let cookie = '';
let csrf = '';

before(async () => {
  config = lerConfig({ ADMIN_SENHA: 'senha-forte-de-teste', FUSO_HORARIO: '-03:00', VIRADA_DO_DIA: '6', LICENCA_CHAVE_PUBLICA: PUBLICA_B64 });
  db = abrirBanco(':memory:');
  servidor = createServer(criarApp(db, config));
  await new Promise((r) => servidor.listen(0, '127.0.0.1', r));
  base = `http://127.0.0.1:${servidor.address().port}`;
});

after(() => {
  servidor.close();
  db.close();
});

async function contato(corpo, segredo = SEGREDO, codigo = CODIGO) {
  const r = await fetch(`${base}/api/v1/contato`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json', Authorization: `Bearer ${segredo}` },
    body: JSON.stringify({ codigo, versao: 'teste', ...corpo }),
  });
  return { status: r.status, corpo: await r.json() };
}

async function entrar(senha = 'senha-forte-de-teste') {
  return fetch(`${base}/entrar`, {
    method: 'POST', redirect: 'manual',
    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
    body: new URLSearchParams({ usuario: 'admin', senha }),
  });
}

async function pagina(caminho) {
  const r = await fetch(`${base}${caminho}`, { headers: { Cookie: cookie }, redirect: 'manual' });
  return { status: r.status, texto: await r.text(), r };
}

async function postar(caminho, campos = {}) {
  return fetch(`${base}${caminho}`, {
    method: 'POST', redirect: 'manual',
    headers: { Cookie: cookie, 'Content-Type': 'application/x-www-form-urlencoded' },
    body: new URLSearchParams({ csrf, ...campos }),
  });
}

const enviar = async (texto) => postar('/licencas', { licenca: texto });

// 21/11/2026 23:30 em Brasília (02:30 UTC do dia 22): pela virada das 6h, é a noite do dia 21.
const NOITE = Date.UTC(2026, 10, 22, 2, 30) / 1000;

test('o gerador de licenças faz o licenca_publica.inc da chave de desenvolvimento do repositório', () => {
  const inc = Licencas.incDaChavePublica(publicaBytes);
  const repo = readFileSync(new URL('../../src/licenca_publica.desenvolvimento.inc', import.meta.url), 'utf8');
  const bytes = (t) => /array\[0\.\.31\] of Byte = \(([^)]*)\)/.exec(t)[1].replace(/\s/g, '');
  assert.equal(bytes(inc), bytes(repo));
  assert.match(inc, /NOVA_CHAVE_DESENVOLVIMENTO = False/);
});

test('licença do gerador confere com a chave pública (e mexida não confere)', async () => {
  const texto = await licenca();
  const campos = conferirLicenca(texto, publica);
  assert.equal(campos.codigo, CODIGO);
  assert.equal(campos.situacao, 'ativa');
  assert.equal(campos.validade, 'permanente');
  assert.equal(campos.contato_ate, 'nunca');
  assert.equal(conferirLicenca(texto.replace('validade=permanente', 'validade=2099-12-31'), publica), null);
  await assert.rejects(() => licenca({ codigo: '123' }), /16 dígitos/);
  await assert.rejects(() => licenca({ validade: '2027-02-31' }), /inválida/);
});

test('máquina nova fica aguardando licença e já guarda os eventos', async () => {
  const r = await contato({
    nome: 'Bar do Teste',
    relogio: { total: 500, parcial: 120, pix_parcial: 20, ponto_pct: 30, creditos: 3 },
    eventos: [
      { id: '1', tipo: 'ligou', quando: NOITE, versao: '1.0' },
      { id: '2', tipo: 'credito', quando: NOITE, origem: 'noteiro', reais: 10, creditos: 10 },
      { id: '3', tipo: 'credito', quando: NOITE + 60, origem: 'pix', reais: 20, creditos: 20 },
      { id: '4', tipo: 'musica', quando: NOITE + 120, cd: 'ROBERTO CARLOS - EMOCOES', musica: '01 - EMOCOES' },
      { id: '5', tipo: 'musica', quando: NOITE + 300, cd: 'ROBERTO CARLOS - EMOCOES', musica: '01 - EMOCOES' },
      { id: '6', tipo: 'credito', quando: NOITE, origem: 'cartao-falso', reais: 5 },
    ],
  });
  assert.equal(r.status, 200);
  assert.equal(r.corpo.situacao, 'pendente');
  assert.equal(r.corpo.licenca, null);
  assert.deepEqual(r.corpo.recebidos, ['1', '2', '3', '4', '5', '6'], 'o inválido também sai da fila da máquina');
  assert.equal(r.corpo.rejeitados, 1);
  assert.equal(db.prepare('SELECT COUNT(*) AS n FROM eventos').get().n, 5);
});

test('reenviar os mesmos eventos não duplica (a máquina reenvia se a resposta se perder)', async () => {
  const r = await contato({ eventos: [{ id: '2', tipo: 'credito', quando: NOITE, origem: 'noteiro', reais: 10, creditos: 10 }] });
  assert.deepEqual(r.corpo.recebidos, ['2']);
  assert.equal(db.prepare(`SELECT COUNT(*) AS n FROM eventos WHERE tipo = 'credito'`).get().n, 2);
});

test('outro aparelho com o mesmo código é recusado', async () => {
  const r = await contato({ eventos: [] }, 'outro-segredo-qualquer-com-mais-de-32-letras!!');
  assert.equal(r.status, 403);
  assert.ok(db.prepare('SELECT intruso_em FROM maquinas').get().intruso_em);
});

test('sem segredo ou com código errado a API recusa', async () => {
  assert.equal((await contato({}, '')).status, 401);
  const r = await fetch(`${base}/api/v1/contato`, {
    method: 'POST', headers: { Authorization: `Bearer ${SEGREDO}` }, body: JSON.stringify({ codigo: '123' }),
  });
  assert.equal(r.status, 400);
  const lixo = await fetch(`${base}/api/v1/contato`, { method: 'POST', headers: { Authorization: `Bearer ${SEGREDO}` }, body: '{' });
  assert.equal(lixo.status, 400);
});

test('painel pede login e recusa senha errada', async () => {
  assert.equal((await pagina('/maquinas')).status, 303);
  assert.equal((await entrar('errada')).status, 401);
  const r = await entrar();
  assert.equal(r.status, 303);
  cookie = r.headers.get('set-cookie').split(';')[0];
  const p = await pagina('/maquinas/1');
  assert.equal(p.status, 200);
  csrf = /name="csrf" value="([^"]+)"/.exec(p.texto)[1];
  assert.match(p.texto, /Bar do Teste/);
  assert.match(p.texto, /aguardando licença/);
  assert.match(p.texto, /1020-7373-4289-6379/);
  assert.match(p.texto, /outro aparelho tentou/);
});

test('formulário sem o token CSRF é recusado', async () => {
  const r = await fetch(`${base}/licencas`, {
    method: 'POST', redirect: 'manual',
    headers: { Cookie: cookie, 'Content-Type': 'application/x-www-form-urlencoded' },
    body: new URLSearchParams({ csrf: 'errado', licenca: await licenca() }),
  });
  assert.equal(r.status, 403);
  assert.equal(db.prepare('SELECT situacao FROM maquinas').get().situacao, 'pendente');
});

test('licença de outra chave ou mexida é recusada pelo painel', async () => {
  const outra = await Licencas.novaChave();
  const deOutraChave = await Licencas.gerarLicenca(outra, { codigo: CODIGO, situacao: 'ativa', validade: 'permanente' });
  const r = await enviar(deOutraChave);
  assert.equal(r.status, 400);
  assert.match(await r.text(), /assinatura não confere/);
  assert.equal((await enviar('qualquer coisa')).status, 400);
  assert.equal(db.prepare('SELECT situacao FROM maquinas').get().situacao, 'pendente');
});

test('enviar a licença: a máquina recebe no próximo contato, e a mesma até vir outra', async () => {
  const texto = await licenca();
  const r = await enviar(texto);
  assert.equal(r.status, 303);
  assert.equal(r.headers.get('location'), '/maquinas/1');
  assert.match((await pagina('/maquinas/1')).texto, /Licença guardada para 1020-7373-4289-6379/);
  assert.doesNotMatch((await pagina('/maquinas/1')).texto, /Licença guardada/, 'o aviso aparece uma vez só');

  const c = await contato({ eventos: [] });
  assert.equal(c.corpo.situacao, 'ativa');
  assert.equal(c.corpo.licenca, texto);
  assert.equal(Buffer.from(c.corpo.licenca_b64, 'base64').toString('utf8'), texto);
  assert.equal((await contato({ eventos: [] })).corpo.licenca, texto, 'a mesma licença enquanto não vier outra');
  assert.equal((await pagina('/maquinas/1/licenca.txt')).texto, texto);
});

test('licença mais velha que a atual é recusada', async () => {
  const velha = await Licencas.gerarLicenca(chave, { codigo: CODIGO, situacao: 'ativa', validade: 'permanente', emitida: 1_700_000_000 });
  await enviar(velha);
  assert.match((await pagina('/maquinas/1')).texto, /mais antiga/);
});

test('validade vai na licença e aparece no painel', async () => {
  await enviar(await licenca({ validade: '2027-12-31' }));
  const c = await contato({ eventos: [] });
  assert.equal(conferirLicenca(c.corpo.licenca, publica).validade, '2027-12-31');
  assert.match((await pagina('/maquinas/1')).texto, /até 31\/12\/2027/);
});

test('relatório soma noteiro e Pix na noite certa, com a parte da casa', async () => {
  const dia = diaDe(NOITE * 1000, config);
  assert.equal(dia, '2026-11-21');
  assert.equal(inicioDoDia('2026-11-21', config), Date.UTC(2026, 10, 21, 9, 0));
  const r = gerar(db, config, { de: '2026-11-21', ate: '2026-11-21' });
  assert.equal(r.totais.noteiro, 10);
  assert.equal(r.totais.pix, 20);
  assert.equal(r.totais.total, 30);
  assert.equal(r.totais.pix_qtd, 1);
  assert.equal(r.totais.musicas, 2);
  assert.equal(r.totais.casa, 9, '30% de R$ 30');
  assert.equal(r.totais.dono, 21);
  assert.equal(r.horario_de_pico, 23);
  assert.deepEqual({ ...r.top_musicas[0] }, { cd: 'ROBERTO CARLOS - EMOCOES', musica: '01 - EMOCOES', tocadas: 2 });
  assert.equal(gerar(db, config, { de: '2026-11-22', ate: '2026-11-22' }).totais.total, 0);

  const csv = paraCsv(r);
  assert.ok(csv.startsWith('﻿Dia;'));
  assert.match(csv, /21\/11\/2026;10;20;1;30;2/);

  const p = await pagina('/relatorio?de=2026-11-21&ate=2026-11-21');
  assert.equal(p.status, 200);
  assert.match(p.texto, /R\$ 30,00/);
  const c = await pagina('/relatorio.csv?de=2026-11-21&ate=2026-11-21');
  assert.match(c.r.headers.get('content-type'), /text\/csv/);
  assert.match((await pagina('/relatorio?de=2026-11-30&ate=2026-11-01')).texto, /não pode ser antes/);
});

test('fechamento aparece no relatório', async () => {
  await contato({ eventos: [{ id: '7', tipo: 'fechamento', quando: NOITE + 3600, parcial: 120, pix: 20, ponto: 36 }] });
  const r = gerar(db, config, { de: '2026-11-21', ate: '2026-11-21' });
  assert.equal(r.fechamentos.length, 1);
  assert.equal(r.fechamentos[0].parcial, 120);
  assert.equal(r.fechamentos[0].pix, 20);
});

test('licença de bloqueio: a máquina recebe e o painel mostra bloqueada', async () => {
  await enviar(await licenca({ situacao: 'bloqueada' }));
  const c = await contato({ eventos: [] });
  assert.equal(c.corpo.situacao, 'bloqueada');
  assert.equal(conferirLicenca(c.corpo.licenca, publica).situacao, 'bloqueada');
  await enviar(await licenca());
  assert.equal((await contato({ eventos: [] })).corpo.situacao, 'ativa');
});

test('licença de máquina que ainda não falou com a nuvem: fica guardada e o primeiro aparelho pareia', async () => {
  const outro = '5555444433332222';
  const texto = await Licencas.gerarLicenca(chave, { codigo: outro, cliente: 'Bar Novo', situacao: 'ativa', validade: 'permanente' });
  assert.equal((await enviar(texto)).status, 303);
  const r = await contato({ eventos: [] }, 'segredo-da-maquina-nova-com-mais-de-32-letras!!', outro);
  assert.equal(r.status, 200);
  assert.equal(r.corpo.licenca, texto);
  assert.match((await pagina('/maquinas')).texto, /Bar Novo/);
});

test('esquecer o aparelho deixa uma jukebox reinstalada parear de novo', async () => {
  const novo = 'segredo-da-jukebox-reinstalada-com-mais-de-32-letras';
  assert.equal((await contato({ eventos: [] }, novo)).status, 403);
  await postar('/maquinas/1/esquecer-aparelho');
  const r = await contato({ eventos: [] }, novo);
  assert.equal(r.status, 200);
  assert.equal(r.corpo.situacao, 'ativa');
  assert.equal((await contato({ eventos: [] })).status, 403, 'o aparelho antigo não fala mais');
});

test('em produção, sem senha a nuvem não sobe; chave pública errada também não', () => {
  assert.throws(() => lerConfig({ NODE_ENV: 'production', ADMIN_SENHA: 'curta' }), /ADMIN_SENHA/);
  assert.throws(() => lerConfig({ ADMIN_SENHA: 'uma-senha-bem-grande', LICENCA_CHAVE_PUBLICA: 'abc' }), /32 bytes/);
  assert.ok(lerConfig({ NODE_ENV: 'production', ADMIN_SENHA: 'uma-senha-bem-grande' }), 'a chave pública é opcional');
});
