#!/bin/sh
# Testa a conversa da jukebox com a nuvem (src/nuvem.pas + src/licenca.pas) contra a nuvem rodando de verdade
# (nuvem/servidor.js), com a chave de desenvolvimento. Precisa de fpc, node 22.13+ e curl.
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
RAIZ=$(cd "$AQUI/../.." && pwd)
T=$(mktemp -d)
NUVEM=""
limpa() {
  # espera a nuvem fechar o banco (ela apaga o -wal e o -shm ao sair) antes de apagar a pasta
  if [ -n "$NUVEM" ]; then kill "$NUVEM" 2>/dev/null || true; wait "$NUVEM" 2>/dev/null || true; fi
  if [ -n "$T" ] && [ -d "$T" ]; then rm -rf "$T"; fi
}
trap limpa EXIT

mkdir "$T/u" "$T/juke"
fpc -Mobjfpc -Sh -O2 -dLICENCA_DESENVOLVIMENTO -Fu"$RAIZ/src" -FU"$T/u" -FE"$T" "$AQUI/teste_nuvem.lpr" >"$T/fpc.log" || { grep -E "Error|Fatal" "$T/fpc.log"; exit 1; }

PORTA=$(node -e "const s=require('net').createServer().listen(0,()=>{console.log(s.address().port);s.close()})")
SENHA=senha-do-teste-da-nuvem
echo "url = http://127.0.0.1:$PORTA" > "$T/juke/nuvem.txt"

echo "--- sem a nuvem no ar"
"$T/teste_nuvem" offline "$T/juke"

echo "--- nuvem no ar"
PORTA=$PORTA BANCO="$T/nuvem.db" ADMIN_SENHA=$SENHA INTERVALO_CONTATO=10 \
  LICENCA_CHAVE_PRIVADA_ARQUIVO="$RAIZ/nuvem/testes/chave-desenvolvimento.pem" \
  node --disable-warning=ExperimentalWarning "$RAIZ/nuvem/servidor.js" >"$T/nuvem.log" 2>&1 &
NUVEM=$!
for i in $(seq 1 50); do curl -s "http://127.0.0.1:$PORTA/saude" >/dev/null 2>&1 && break; sleep 0.1; done

"$T/teste_nuvem" pendente "$T/juke"
node "$AQUI/painel.mjs" "http://127.0.0.1:$PORTA" "$SENHA" liberar
"$T/teste_nuvem" liberada "$T/juke"

CSV=$(node "$AQUI/painel.mjs" "http://127.0.0.1:$PORTA" "$SENHA" csv)
FALHAS=0
confere() { if eval "$2"; then echo "OK    $1"; else echo "FALHA $1"; FALHAS=$((FALHAS + 1)); fi; }
confere "relatório da nuvem: noteiro R\$ 10, Pix R\$ 20, total R\$ 30, 2 músicas" \
  'echo "$CSV" | grep -q "^TOTAL;10;20;1;30;2"'

MUSICAS=$(node --disable-warning=ExperimentalWarning -e "
  const db = new (require('node:sqlite').DatabaseSync)(process.argv[1]);
  console.log(db.prepare(\"SELECT cd || ' / ' || musica AS m FROM eventos WHERE tipo = 'musica' ORDER BY id\").all().map((l) => l.m).join('|'));
" "$T/nuvem.db")
confere "nomes com acento e aspas chegam certos na nuvem" \
  '[ "$MUSICAS" = "ROBERTO CARLOS - EMOCOES / 01 - EMOCOES|ALCEU VALENCA - \"AO VIVO\" / 01 - ANUNCIAÇÃO" ]'

node "$AQUI/painel.mjs" "http://127.0.0.1:$PORTA" "$SENHA" bloquear
"$T/teste_nuvem" bloqueada "$T/juke"

# outra jukebox (outro segredo) dizendo ser esta máquina
mkdir "$T/juke2"
cp "$T/juke/nuvem.txt" "$T/juke2/"
"$T/teste_nuvem" intruso "$T/juke2"

[ "$FALHAS" = 0 ] || { echo "--- nuvem.log"; cat "$T/nuvem.log"; exit 1; }
echo "Nuvem: tudo OK"
