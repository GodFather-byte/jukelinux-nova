#!/bin/sh
# Instala a JukeLinux Nova numa máquina (troca direta da JukeLinux antiga ou máquina nova).
#
#   sudo sh instalar.sh            instala o ./jukelinux que veio junto com este script
#   sudo sh instalar.sh --desfazer volta o executável anterior (a cópia guardada na última instalação)
#
# O que faz:
#   1. instala o que a Nova usa: mplayer, curl, xrandr e as bibliotecas do GTK2;
#   2. guarda o executável atual em /home/jkb/jukelinux/jukelinux.antes-da-nova-AAAAMMDD-HHMMSS;
#   3. põe a Nova no mesmo lugar e com o mesmo nome (/home/jkb/jukelinux/jukelinux): o que já inicia a jukebox nessa
#      máquina continua iniciando a Nova;
#   4. numa máquina nova, cria as pastas /home/jkb/musicas, ritmos/ e letras/ (as configurações a Nova cria ao abrir);
#   5. não mexe em nada mais: músicas, configurações (.txt), relógios e créditos ficam como estão.
# Na primeira vez que abrir, a Nova mostra a tela de ativação com o código da máquina (ver README, "Licença").
set -e

PASTA=/home/jkb/jukelinux
USUARIO=jkb
AQUI=$(cd "$(dirname "$0")" && pwd)
NOVO="$AQUI/jukelinux"

falha() { echo "ERRO: $*" >&2; exit 1; }

[ "$(id -u)" = "0" ] || falha "rode com sudo: sudo sh $0"

if [ "$1" = "--desfazer" ]; then
  ANTERIOR=$(ls -1t "$PASTA"/jukelinux.antes-da-nova-* 2>/dev/null | head -1)
  [ -n "$ANTERIOR" ] || falha "não achei cópia do executável anterior em $PASTA"
  cp -p "$ANTERIOR" "$PASTA/jukelinux"
  echo "Voltou o executável anterior: $ANTERIOR"
  exit 0
fi

[ -f "$NOVO" ] || falha "não achei o executável da Nova em $NOVO"
file "$NOVO" 2>/dev/null | grep -q "ELF 64-bit" || falha "$NOVO não é um executável Linux de 64 bits"

if [ -z "$INSTALAR_SEM_APT" ]; then
  echo "Instalando dependências..."
  apt-get update -qq
  apt-get install -y -qq mplayer curl x11-xserver-utils libgtk2.0-0 >/dev/null
fi
for programa in mplayer curl xrandr; do
  command -v "$programa" >/dev/null 2>&1 || falha "falta o programa $programa"
done

mkdir -p "$PASTA" "$PASTA/ritmos" "$PASTA/letras" /home/jkb/musicas
if [ -f "$PASTA/jukelinux" ] && cmp -s "$PASTA/jukelinux" "$NOVO"; then
  echo "Esta versão já está instalada; nada a guardar."
elif [ -f "$PASTA/jukelinux" ]; then
  COPIA="$PASTA/jukelinux.antes-da-nova-$(date +%Y%m%d-%H%M%S)"
  cp -p "$PASTA/jukelinux" "$COPIA"
  echo "Executável anterior guardado em $COPIA"
fi
cp "$NOVO" "$PASTA/jukelinux.novo"
chmod 755 "$PASTA/jukelinux.novo"
mv -f "$PASTA/jukelinux.novo" "$PASTA/jukelinux"
if [ -f "$AQUI/pix.txt.exemplo" ] && [ ! -f "$PASTA/pix.txt.exemplo" ]; then
  cp "$AQUI/pix.txt.exemplo" "$PASTA/pix.txt.exemplo"
fi
if id "$USUARIO" >/dev/null 2>&1; then
  chown "$USUARIO": "$PASTA" "$PASTA/ritmos" "$PASTA/letras" /home/jkb/musicas "$PASTA/jukelinux"
  [ -f "$PASTA/pix.txt.exemplo" ] && chown "$USUARIO": "$PASTA/pix.txt.exemplo"
fi

echo "JukeLinux Nova instalada em $PASTA/jukelinux."
echo "Ao abrir, se a máquina ainda não tiver licença, aparece a tela de ativação com o código da máquina."
echo "Para voltar o executável anterior: sudo sh $0 --desfazer"
