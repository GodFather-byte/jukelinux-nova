#!/bin/sh
# Cria o par de chaves das licenças (Ed25519). Faça UMA vez, no computador da empresa:
#
#   sh ferramentas/licenca/nova_chave.sh [pasta da chave privada]     (padrão: ~/jukelinux-chave)
#
# - A chave PRIVADA fica na pasta indicada (chave-privada-licencas.pem), FORA do git. Ela vai para a nuvem
#   (variável LICENCA_CHAVE_PRIVADA) e é a única coisa que emite licenças. Guarde uma cópia em lugar seguro: sem ela
#   não dá para emitir licenças para as jukeboxes já instaladas, e quem a tiver emite licenças.
# - A chave PÚBLICA vai para src/licenca_publica.inc, que PODE ir para o git: com ela a jukebox só confere
#   licenças, não cria. Depois de rodar, faça commit de src/licenca_publica.inc e gere o executável de novo.
set -e
RAIZ=$(cd "$(dirname "$0")/../.." && pwd)
PASTA=${1:-$HOME/jukelinux-chave}
PRIVADA="$PASTA/chave-privada-licencas.pem"
PUBLICA="$RAIZ/src/licenca_publica.inc"

if [ -f "$PRIVADA" ]; then
  echo "Já existe $PRIVADA; não sobrescrevo (apague à mão se quiser mesmo trocar a chave:"
  echo "as jukeboxes com a chave antiga deixam de aceitar as licenças novas)."
  exit 1
fi
command -v openssl >/dev/null || { echo "Precisa do openssl"; exit 1; }
mkdir -p "$PASTA"
umask 077
openssl genpkey -algorithm ed25519 -out "$PRIVADA"
sh "$RAIZ/ferramentas/licenca/chave_publica.sh" "$PRIVADA" False > "$PUBLICA"

echo "Chave privada: $PRIVADA  (guarde; vai para a nuvem em LICENCA_CHAVE_PRIVADA)"
echo "Chave pública: $PUBLICA  (faça commit e gere o executável de novo)"
