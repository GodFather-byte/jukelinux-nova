// Banco da nuvem (SQLite embutido no Node, sem dependências nativas).
import { DatabaseSync } from 'node:sqlite';
import { mkdirSync } from 'node:fs';
import { dirname } from 'node:path';

const ESQUEMA = `
CREATE TABLE IF NOT EXISTS maquinas (
  id INTEGER PRIMARY KEY,
  codigo TEXT NOT NULL UNIQUE,          -- 16 dígitos, sem tracinhos (código da tela de ativação)
  segredo_hash TEXT,                    -- sha256 do segredo que a máquina gerou no 1º contato
  nome TEXT NOT NULL,
  local TEXT NOT NULL DEFAULT '',
  cliente TEXT NOT NULL DEFAULT '',
  observacao TEXT NOT NULL DEFAULT '',
  situacao TEXT NOT NULL DEFAULT 'pendente' CHECK (situacao IN ('pendente', 'ativa', 'bloqueada')),
  validade TEXT,                        -- AAAA-MM-DD; NULL = permanente
  contato_dias INTEGER NOT NULL DEFAULT 0, -- sem uso (versão antiga)
  criada_em INTEGER NOT NULL,
  liberada_em INTEGER,
  ultimo_contato INTEGER,
  versao TEXT NOT NULL DEFAULT '',
  ip TEXT NOT NULL DEFAULT '',
  relogio TEXT,                         -- JSON: o que a máquina mandou no último contato (relógios, créditos)
  licenca_emitida INTEGER,
  licenca_texto TEXT,                   -- a última licença enviada: reenviada igual enquanto nada mudar
  intruso_em INTEGER                    -- outro aparelho tentou falar com este código
);

CREATE TABLE IF NOT EXISTS eventos (
  id INTEGER PRIMARY KEY,
  maquina_id INTEGER NOT NULL REFERENCES maquinas(id) ON DELETE CASCADE,
  evento_id TEXT NOT NULL,              -- id dado pela máquina (não repete): o mesmo evento nunca entra 2 vezes
  tipo TEXT NOT NULL,                   -- credito, musica, fechamento, ligou
  quando INTEGER NOT NULL,              -- ms UTC, relógio da máquina
  recebido_em INTEGER NOT NULL,
  origem TEXT NOT NULL DEFAULT '',      -- credito: noteiro ou pix
  reais INTEGER NOT NULL DEFAULT 0,
  creditos INTEGER NOT NULL DEFAULT 0,
  cd TEXT NOT NULL DEFAULT '',
  musica TEXT NOT NULL DEFAULT '',
  dados TEXT,                           -- JSON com o resto
  UNIQUE (maquina_id, evento_id)
);
CREATE INDEX IF NOT EXISTS eventos_quando ON eventos (tipo, quando);
CREATE INDEX IF NOT EXISTS eventos_maquina ON eventos (maquina_id, quando);

CREATE TABLE IF NOT EXISTS sessoes (
  token_hash TEXT PRIMARY KEY,
  csrf TEXT NOT NULL,
  expira_em INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS historico (
  id INTEGER PRIMARY KEY,
  quando INTEGER NOT NULL,
  maquina_id INTEGER REFERENCES maquinas(id) ON DELETE CASCADE,
  acao TEXT NOT NULL,
  detalhe TEXT NOT NULL DEFAULT ''
);
`;

export function abrirBanco(caminho) {
  if (caminho !== ':memory:') mkdirSync(dirname(caminho), { recursive: true });
  const db = new DatabaseSync(caminho);
  db.exec('PRAGMA journal_mode = WAL; PRAGMA foreign_keys = ON; PRAGMA busy_timeout = 5000;');
  db.exec(ESQUEMA);
  // bancos criados antes desta coluna
  const colunas = db.prepare('PRAGMA table_info(maquinas)').all().map((c) => c.name);
  if (!colunas.includes('licenca_texto')) db.exec('ALTER TABLE maquinas ADD COLUMN licenca_texto TEXT');
  return db;
}

/** Roda `fn` numa transação (tudo ou nada). */
export function transacao(db, fn) {
  db.exec('BEGIN');
  try {
    const r = fn();
    db.exec('COMMIT');
    return r;
  } catch (e) {
    db.exec('ROLLBACK');
    throw e;
  }
}

export function registrar(db, maquinaId, acao, detalhe = '') {
  db.prepare('INSERT INTO historico (quando, maquina_id, acao, detalhe) VALUES (?, ?, ?, ?)')
    .run(Date.now(), maquinaId, acao, detalhe);
}
