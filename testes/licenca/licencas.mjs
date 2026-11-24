// Gera licenças de teste assinadas com a chave de DESENVOLVIMENTO (nuvem/testes/chave-desenvolvimento.pem),
// com o mesmo código da nuvem de verdade (nuvem/src/licenca.js).
//   node licencas.mjs PASTA CODIGO
import { readFileSync, writeFileSync } from 'node:fs';
import { createPrivateKey } from 'node:crypto';
import { join } from 'node:path';
import { emitirLicenca } from '../../nuvem/src/licenca.js';

const [pasta, codigoComTracos] = process.argv.slice(2);
const codigo = codigoComTracos.replace(/\D/g, '');
const chave = createPrivateKey(readFileSync(new URL('../../nuvem/testes/chave-desenvolvimento.pem', import.meta.url)));
const agora = Date.now();
const DIA = 86_400_000;
const FUSO = -180;
const data = (ms) => new Date(ms + FUSO * 60_000).toISOString().slice(0, 10);
const base = { codigo, nome: 'Bar de Teste', cliente: 'Bar de Teste', situacao: 'ativa', validade: null, contato_dias: 0 };

const licencas = {
  'permanente.txt': emitirLicenca(base, chave, agora, FUSO),
  'antiga.txt': emitirLicenca(base, chave, agora - 10 * DIA, FUSO),
  'trinta-dias.txt': emitirLicenca({ ...base, validade: data(agora + 30 * DIA) }, chave, agora, FUSO),
  'vencida.txt': emitirLicenca({ ...base, validade: data(agora - 2 * DIA) }, chave, agora - 40 * DIA, FUSO),
  'bloqueada.txt': emitirLicenca({ ...base, situacao: 'bloqueada' }, chave, agora + 1000, FUSO),
  'contato-7.txt': emitirLicenca({ ...base, contato_dias: 7 }, chave, agora, FUSO),
  'outra-maquina.txt': emitirLicenca({ ...base, codigo: '9999888877776666' }, chave, agora, FUSO),
};
licencas['adulterada.txt'] = licencas['trinta-dias.txt'].replace(/validade=[\d-]+/, 'validade=permanente');
for (const [nome, texto] of Object.entries(licencas)) writeFileSync(join(pasta, nome), texto);
