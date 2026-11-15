#!/bin/sh
# Testa a licença (src/licenca.pas). Precisa de fpc. Usa src/licenca_chave.inc (ou a de desenvolvimento).
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
SRC="$AQUI/../../src"
T=$(mktemp -d)
limpa() { [ -n "$T" ] && [ -d "$T" ] && rm -r "$T"; }
trap limpa EXIT
[ -f "$SRC/licenca_chave.inc" ] || cp "$SRC/licenca_chave.desenvolvimento.inc" "$T/licenca_chave.inc"
mkdir "$T/u"
fpc -Mobjfpc -Sh -O2 -Fu"$SRC" -Fi"$T" -Fi"$SRC" -FU"$T/u" -FE"$T" "$AQUI/teste_licenca.lpr" >/dev/null
"$T/teste_licenca" "$T"
