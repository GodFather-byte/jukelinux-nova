#!/bin/sh
# Testa a licença (src/licenca.pas) com licenças assinadas pela chave de DESENVOLVIMENTO. Precisa de fpc e node.
# Compila com -dLICENCA_DESENVOLVIMENTO: usa src/licenca_publica.desenvolvimento.inc (a privada de verdade não está aqui).
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
SRC="$AQUI/../../src"
T=$(mktemp -d)
limpa() { [ -n "$T" ] && [ -d "$T" ] && rm -r "$T"; }
trap limpa EXIT
mkdir "$T/u" "$T/licencas"
fpc -Mobjfpc -Sh -O2 -dLICENCA_DESENVOLVIMENTO -Fu"$SRC" -FU"$T/u" -FE"$T" "$AQUI/teste_licenca.lpr" >"$T/fpc.log" || { grep -E "Error|Fatal" "$T/fpc.log"; exit 1; }
node "$AQUI/licencas.mjs" "$T/licencas" "$("$T/teste_licenca")"
"$T/teste_licenca" "$T/licencas"
