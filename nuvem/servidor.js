// Nuvem da JukeLinux Nova. Uso: npm start (variáveis de ambiente em LEIA-ME.md).
import { createServer } from 'node:http';
import { randomBytes } from 'node:crypto';
import { lerConfig } from './src/config.js';
import { abrirBanco } from './src/banco.js';
import { criarApp } from './src/app.js';

const config = lerConfig();
if (!config.adminSenha) {
  config.adminSenha = randomBytes(9).toString('base64url');
  console.warn(`ATENÇÃO: sem ADMIN_SENHA. Senha provisória desta execução: ${config.adminSenha} (usuário ${config.adminUsuario})`);
}
if (!config.chavePrivada) {
  console.warn('ATENÇÃO: sem LICENCA_CHAVE_PRIVADA: as máquinas conversam com a nuvem, mas não recebem licença.');
}

const db = abrirBanco(config.banco);
const servidor = createServer(criarApp(db, config));
servidor.listen(config.porta, config.host, () => {
  console.log(`Nuvem da JukeLinux no ar em http://${config.host}:${config.porta} (banco ${config.banco})`);
});

for (const sinal of ['SIGINT', 'SIGTERM']) {
  process.on(sinal, () => {
    servidor.close(() => {
      db.close();
      process.exit(0);
    });
  });
}
