#!/bin/sh
# Cria a chave secreta das licenças em src/licenca_chave.inc (fica fora do git). Faça UMA vez e guarde o arquivo:
# a jukebox e o gerador de contra-senhas precisam ser compilados com a mesma chave, e quem tiver o arquivo gera
# contra-senhas. Para o build do GitHub, copie o valor de NOVA_CHAVE_LICENCA para o segredo LICENCA_CHAVE do repositório.
set -e
DEST="$(cd "$(dirname "$0")" && pwd)/../../src/licenca_chave.inc"
if [ -f "$DEST" ] && ! grep -q "NOVA_CHAVE_DESENVOLVIMENTO = True" "$DEST"; then
  echo "Já existe uma chave real em $DEST; não sobrescrevo."
  exit 1
fi
CHAVE=$(head -c 32 /dev/urandom | od -An -tx1 | tr -d ' \n')
umask 077
cat > "$DEST" <<FIM
{ Chave secreta das licenças da JukeLinux Nova. NÃO vai para o git. Guarde uma cópia em lugar seguro. }
const
  NOVA_CHAVE_LICENCA = '$CHAVE';
  NOVA_CHAVE_DESENVOLVIMENTO = False;
FIM
echo "Chave criada em $DEST"
