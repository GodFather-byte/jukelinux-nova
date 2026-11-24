// Gera licenças de teste com o próprio gerador de licenças (ferramentas/licenca/gerador-de-licencas.html), assinadas
// com a chave de DESENVOLVIMENTO.
//   node licencas.mjs PASTA CODIGO
import { writeFileSync } from 'node:fs';
import { join } from 'node:path';
import { carregaNucleo, chaveDesenvolvimento } from './gerador.mjs';

const [pasta, codigo] = process.argv.slice(2);
const Licencas = carregaNucleo();
const chave = await chaveDesenvolvimento(Licencas);
const agora = Math.floor(Date.now() / 1000);
const DIA = 86_400;
const data = (s) => new Date((s - 3 * 3600) * 1000).toISOString().slice(0, 10);
const base = { codigo, cliente: 'Bar de Teste', situacao: 'ativa', validade: 'permanente', emitida: agora };
const gera = (extra) => Licencas.gerarLicenca(chave, { ...base, ...extra });

const licencas = {
  'permanente.txt': await gera({}),
  'antiga.txt': await gera({ emitida: agora - 10 * DIA }),
  'trinta-dias.txt': await gera({ validade: data(agora + 30 * DIA) }),
  'vencida.txt': await gera({ validade: data(agora - 2 * DIA), emitida: agora - 40 * DIA }),
  'bloqueada.txt': await gera({ situacao: 'bloqueada', emitida: agora + 1 }),
  'outra-maquina.txt': await gera({ codigo: '9999888877776666' }),
};
licencas['adulterada.txt'] = licencas['trinta-dias.txt'].replace(/validade=[\d-]+/, 'validade=permanente');
for (const [nome, texto] of Object.entries(licencas)) writeFileSync(join(pasta, nome), texto);
