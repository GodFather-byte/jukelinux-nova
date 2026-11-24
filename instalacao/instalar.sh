#!/bin/sh
# Instala a JukeLinux Nova numa máquina (troca direta da JukeLinux antiga ou máquina nova, ex. Linux Mint).
#
#   sudo sh instalar.sh                         instala o ./jukelinux que veio junto com este script
#   sudo sh instalar.sh --nuvem https://...     idem, e liga a jukebox à nuvem da empresa (grava nuvem.txt)
#   sudo sh instalar.sh --iniciar-sozinha       idem, e põe a jukebox para abrir sozinha ao entrar no Linux
#   sudo sh instalar.sh --desfazer              volta o executável anterior (a cópia guardada na última instalação)
# As opções podem ir juntas (ex.: --nuvem https://... --iniciar-sozinha). Um nuvem.txt junto deste script também
# vale (sem --nuvem); um nuvem.txt que já esteja na máquina só é trocado com --nuvem.
#
# O que faz:
#   1. instala o que a Nova usa: mplayer, curl, xrandr e as bibliotecas do GTK2 (nomes do Ubuntu/Mint antigo e novo);
#   2. guarda o executável atual em /home/jkb/jukelinux/jukelinux.antes-da-nova-AAAAMMDD-HHMMSS;
#   3. põe a Nova no mesmo lugar e com o mesmo nome (/home/jkb/jukelinux/jukelinux): o que já inicia a jukebox nessa
#      máquina continua iniciando a Nova;
#   4. numa máquina nova (sem a JukeLinux antiga): cria /home/jkb/musicas, ritmos/ e letras/, deixa tudo do usuário
#      que vai rodar a jukebox (jkb, ou quem rodou o sudo se não houver jkb) e põe a jukebox para abrir sozinha ao
#      entrar no Linux, com a tela sem apagar nem bloquear (iniciar-jukebox.sh). As configurações a Nova cria ao abrir;
#   5. instala o baixador de músicas do YouTube (baixar-youtube.sh, yt-dlp, ffmpeg) com um atalho no menu;
#   6. com --nuvem (ou nuvem.txt junto do script), grava /home/jkb/jukelinux/nuvem.txt: a jukebox fala com a nuvem
#      da empresa quando tiver internet (licença, dinheiro, relatórios); sem internet ela funciona do mesmo jeito;
#   7. não mexe em nada mais: músicas, configurações (.txt), relógios e créditos ficam como estão.
# Na primeira vez que abrir, a Nova mostra a tela de ativação com o código da máquina, até a empresa liberar a
# máquina no painel da nuvem (ou até colocar no pendrive o licenca.txt baixado no painel). Ver README, "Licença".
set -e

PASTA=/home/jkb/jukelinux
MUSICAS=/home/jkb/musicas
AQUI=$(cd "$(dirname "$0")" && pwd)
NOVO="$AQUI/jukelinux"

falha() { echo "ERRO: $*" >&2; exit 1; }

[ "$(id -u)" = "0" ] || falha "rode com sudo: sudo sh $0"

INICIAR_SOZINHA=""
DESFAZER=""
URL_NUVEM=""
while [ $# -gt 0 ]; do
  case "$1" in
    --desfazer) DESFAZER=sim ;;
    --iniciar-sozinha) INICIAR_SOZINHA=sim ;;
    --nuvem) shift; URL_NUVEM=$1 ;;
    --nuvem=*) URL_NUVEM=${1#--nuvem=} ;;
    *) falha "opção desconhecida: $1 (veja o começo do instalar.sh)" ;;
  esac
  shift
done
if [ -n "$URL_NUVEM" ]; then
  case "$URL_NUVEM" in
    https://*|http://*) ;;
    *) falha "o endereço da nuvem precisa começar com https:// (recebi: $URL_NUVEM)" ;;
  esac
fi

if [ -n "$DESFAZER" ]; then
  ANTERIOR=$(ls -1t "$PASTA"/jukelinux.antes-da-nova-* 2>/dev/null | head -1)
  [ -n "$ANTERIOR" ] || falha "não achei cópia do executável anterior em $PASTA"
  cp -p "$ANTERIOR" "$PASTA/jukelinux"
  echo "Voltou o executável anterior: $ANTERIOR"
  exit 0
fi

[ -f "$NOVO" ] || falha "não achei o executável da Nova em $NOVO"
head -c 4 "$NOVO" | grep -q "ELF" || falha "$NOVO não é um executável Linux"

# usuário que roda a jukebox: jkb (máquinas da JukeLinux) ou, numa máquina nova sem jkb, quem rodou o sudo
if id jkb >/dev/null 2>&1; then
  USUARIO=jkb
elif [ -n "$SUDO_USER" ] && [ "$SUDO_USER" != "root" ]; then
  USUARIO=$SUDO_USER
else
  USUARIO=""
fi

if [ -z "$INSTALAR_SEM_APT" ]; then
  echo "Instalando dependências..."
  apt-get update -qq
  # GTK2: no Ubuntu 24.04 / Mint 22 o pacote se chama libgtk2.0-0t64; antes, libgtk2.0-0
  GTK=libgtk2.0-0
  apt-cache show libgtk2.0-0t64 >/dev/null 2>&1 && GTK=libgtk2.0-0t64
  apt-get install -y -qq mplayer curl x11-xserver-utils "$GTK" >/dev/null
  # para baixar músicas do YouTube (baixar-youtube.sh): ffmpeg, zenity (janelas) e python3 (o yt-dlp)
  apt-get install -y -qq ffmpeg zenity python3 >/dev/null || echo "Aviso: não instalei ffmpeg/zenity (baixar do YouTube)"
fi
for programa in mplayer curl xrandr; do
  command -v "$programa" >/dev/null 2>&1 || falha "falta o programa $programa"
done
# a licença é conferida pela libcrypto do OpenSSL 3 (já vem no Mint 21/22 e no Ubuntu 22.04/24.04, junto do curl)
ldconfig -p 2>/dev/null | grep -q "libcrypto.so.3" || echo "Aviso: não achei a libcrypto.so.3 (OpenSSL 3): sem ela a licença não é conferida"

MAQUINA_NOVA=""
[ -f "$PASTA/jukelinux" ] || MAQUINA_NOVA=sim
mkdir -p "$PASTA" "$PASTA/ritmos" "$PASTA/letras" "$MUSICAS"
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

# nuvem da empresa: --nuvem troca; nuvem.txt junto do script só entra se a máquina ainda não tiver um
if [ -n "$URL_NUVEM" ]; then
  printf 'url = %s\n' "$URL_NUVEM" > "$PASTA/nuvem.txt"
  echo "Nuvem: $URL_NUVEM"
elif [ -f "$AQUI/nuvem.txt" ] && [ ! -f "$PASTA/nuvem.txt" ]; then
  cp "$AQUI/nuvem.txt" "$PASTA/nuvem.txt"
  echo "Nuvem: $(grep -v '^#' "$PASTA/nuvem.txt" | head -1)"
fi
[ -f "$PASTA/nuvem.txt" ] || echo "Aviso: sem nuvem.txt: a jukebox não fala com a nuvem (licença só por pendrive)"

# baixar músicas do YouTube: o script e o yt-dlp na pasta da jukebox (do usuário dela, para ele se atualizar sozinho)
if [ -f "$AQUI/baixar-youtube.sh" ]; then
  cp "$AQUI/baixar-youtube.sh" "$PASTA/baixar-youtube.sh"
  chmod 755 "$PASTA/baixar-youtube.sh"
  if [ ! -x "$PASTA/yt-dlp" ]; then
    if curl -fsSL -o "$PASTA/yt-dlp.novo" https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp; then
      chmod 755 "$PASTA/yt-dlp.novo" && mv -f "$PASTA/yt-dlp.novo" "$PASTA/yt-dlp"
    else
      rm -f "$PASTA/yt-dlp.novo"
      echo "Aviso: não baixei o yt-dlp (sem internet?); o baixador tenta o yt-dlp do sistema"
    fi
  fi
fi

# script que abre a jukebox: tela sempre ligada, sem bloqueio, uma jukebox só
cat > "$PASTA/iniciar-jukebox.sh" <<'FIM'
#!/bin/sh
# Abre a JukeLinux Nova (criado pelo instalar.sh). A tela não apaga nem bloqueia enquanto a jukebox está aberta.
xset s off -dpms s noblank 2>/dev/null || true
for esquema in org.cinnamon.desktop.screensaver org.gnome.desktop.screensaver org.mate.screensaver; do
  gsettings set "$esquema" lock-enabled false 2>/dev/null || true
done
gsettings set org.cinnamon.desktop.session idle-delay 0 2>/dev/null || true
gsettings set org.gnome.desktop.session idle-delay 0 2>/dev/null || true
gsettings set org.cinnamon.settings-daemon.plugins.power sleep-display-ac 0 2>/dev/null || true
pgrep -x jukelinux >/dev/null && exit 0
cd /home/jkb/jukelinux && exec ./jukelinux
FIM
chmod 755 "$PASTA/iniciar-jukebox.sh"

if [ -n "$USUARIO" ]; then
  # numa máquina nova tudo é do usuário da jukebox (ela grava as configurações na pasta)
  if [ -n "$MAQUINA_NOVA" ]; then
    chown -R "$USUARIO": /home/jkb
  else
    chown "$USUARIO": "$PASTA" "$PASTA/ritmos" "$PASTA/letras" "$MUSICAS" "$PASTA/jukelinux" "$PASTA/iniciar-jukebox.sh"
    for f in baixar-youtube.sh yt-dlp; do [ -f "$PASTA/$f" ] && chown "$USUARIO": "$PASTA/$f"; done
    [ -f "$PASTA/pix.txt.exemplo" ] && chown "$USUARIO": "$PASTA/pix.txt.exemplo"
    [ -f "$PASTA/nuvem.txt" ] && chown "$USUARIO": "$PASTA/nuvem.txt"
  fi
fi

# abrir sozinha ao entrar no Linux: máquina nova (a antiga já tem o jeito dela de abrir) ou --iniciar-sozinha
if [ -n "$USUARIO" ] && { [ -n "$MAQUINA_NOVA" ] || [ -n "$INICIAR_SOZINHA" ]; }; then
  CASA=$(getent passwd "$USUARIO" | cut -d: -f6)
  mkdir -p "$CASA/.config/autostart"
  cat > "$CASA/.config/autostart/jukelinux-nova.desktop" <<FIM
[Desktop Entry]
Type=Application
Name=JukeLinux Nova
Exec=$PASTA/iniciar-jukebox.sh
X-GNOME-Autostart-enabled=true
FIM
  chown -R "$USUARIO": "$CASA/.config/autostart"
  echo "A jukebox abre sozinha quando $USUARIO entrar no Linux (ligue o login automático desse usuário)."
fi

# atalho "Baixar músicas do YouTube" no menu de aplicativos (e na área de trabalho, se houver)
if [ -n "$USUARIO" ] && [ -f "$PASTA/baixar-youtube.sh" ]; then
  CASA=$(getent passwd "$USUARIO" | cut -d: -f6)
  ATALHO="[Desktop Entry]
Type=Application
Name=Baixar músicas do YouTube
Comment=Baixa um vídeo ou uma playlist do YouTube para um CD da jukebox
Exec=$PASTA/baixar-youtube.sh
Icon=folder-download
Terminal=false
Categories=AudioVideo;"
  mkdir -p "$CASA/.local/share/applications"
  printf '%s\n' "$ATALHO" > "$CASA/.local/share/applications/jukelinux-baixar-youtube.desktop"
  for MESA in "$CASA/Área de Trabalho" "$CASA/Desktop"; do
    if [ -d "$MESA" ]; then
      printf '%s\n' "$ATALHO" > "$MESA/jukelinux-baixar-youtube.desktop"
      chmod 755 "$MESA/jukelinux-baixar-youtube.desktop"
      chown "$USUARIO": "$MESA/jukelinux-baixar-youtube.desktop"
    fi
  done
  chown -R "$USUARIO": "$CASA/.local/share/applications"
fi

echo "JukeLinux Nova instalada em $PASTA/jukelinux (usuário: ${USUARIO:-root})."
echo "Para abrir agora: $PASTA/iniciar-jukebox.sh"
echo "Ao abrir, se a máquina ainda não tiver licença, aparece a tela de ativação com o código da máquina:"
echo "libere a máquina no painel da nuvem (ela chega pela internet) ou ponha no pendrive o licenca.txt do painel."
echo "Para voltar o executável anterior: sudo sh $0 --desfazer"
