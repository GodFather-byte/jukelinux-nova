#!/bin/sh
# Escreve na saída o licenca_publica.inc (chave pública Ed25519 em 32 bytes) de uma chave privada .pem.
#   sh chave_publica.sh chave.pem True|False      (True = chave de desenvolvimento)
set -e
PRIVADA=$1
DESENVOLVIMENTO=${2:-False}
BYTES=$(openssl pkey -in "$PRIVADA" -pubout -outform DER | tail -c 32 | od -An -tu1 | tr -s ' \n' ' ' | sed 's/^ //; s/ $//; s/ /, /g')
[ "$(echo "$BYTES" | tr ',' '\n' | wc -l)" = 32 ] || { echo "chave pública inesperada" >&2; exit 1; }
if [ "$DESENVOLVIMENTO" = True ]; then
  echo "{ Chave pública das licenças SÓ PARA DESENVOLVIMENTO E TESTES: a privada está no git"
  echo "  (nuvem/testes/chave-desenvolvimento.pem), então qualquer um emite licenças para ela."
  echo "  Para as máquinas, crie a chave de verdade com ferramentas/licenca/nova_chave.sh. }"
else
  echo "{ Chave pública das licenças da JukeLinux Nova (Ed25519). Pode ir para o git: só confere licenças."
  echo "  A privada fica com a empresa e na nuvem (LICENCA_CHAVE_PRIVADA). }"
fi
echo "const"
echo "  NOVA_CHAVE_PUBLICA: array[0..31] of Byte = ($BYTES);"
echo "  NOVA_CHAVE_DESENVOLVIMENTO = $DESENVOLVIMENTO;"
