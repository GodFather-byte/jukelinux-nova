#!/bin/sh
# Compila (se preciso) e roda o gerador de contra-senhas. Uso: ferramentas/licenca/gerar.sh CODIGO [prazo]
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
SRC="$AQUI/../../src"
[ -f "$SRC/licenca_chave.inc" ] || { echo "Falta $SRC/licenca_chave.inc: rode nova_chave.sh (ou copie o da empresa)."; exit 1; }
if [ ! -x "$AQUI/gerar_contrasenha" ] || [ "$SRC/licenca.pas" -nt "$AQUI/gerar_contrasenha" ] \
   || [ "$SRC/licenca_chave.inc" -nt "$AQUI/gerar_contrasenha" ]; then
  T=$(mktemp -d)
  fpc -Mobjfpc -Sh -O2 -Fu"$SRC" -Fi"$SRC" -FU"$T" -FE"$AQUI" "$AQUI/gerar_contrasenha.lpr" >/dev/null
  [ -n "$T" ] && rm -r "$T"
fi
"$AQUI/gerar_contrasenha" "$@"
