#!/bin/sh
# Instala a JukeLinux Nova numa máquina (troca direta da JukeLinux antiga ou máquina nova, ex. Linux Mint).
#
#   sudo sh instalar.sh                    instala o ./jukelinux que veio junto com este script
#   sudo sh instalar.sh --iniciar-sozinha  idem, e põe a jukebox para abrir sozinha ao entrar no Linux
#   sudo sh instalar.sh --desfazer         volta o executável anterior (a cópia guardada na última instalação)
#
# O que faz:
#   1. instala o que a Nova usa: mplayer, curl, xrandr e as bibliotecas do GTK2 (nomes do Ubuntu/Mint antigo e novo);
#   2. guarda o executável atual em /home/jkb/jukelinux/jukelinux.antes-da-nova-AAAAMMDD-HHMMSS;
#   3. põe a Nova no mesmo lugar e com o mesmo nome (/home/jkb/jukelinux/jukelinux): o que já inicia a jukebox nessa
#      máquina continua iniciando a Nova;
#   4. numa máquina nova (sem a JukeLinux antiga): cria /home/jkb/musicas, ritmos/ e letras/, deixa tudo do usuário
#      que vai rodar a jukebox (jkb, ou quem rodou o sudo se não houver jkb) e põe a jukebox para abrir sozinha ao
#      entrar no Linux, com a tela sem apagar nem bloquear (iniciar-jukebox.sh). As configurações a Nova cria ao abrir;
#   5. não mexe em nada mais: músicas, configurações (.txt), relógios e créditos ficam como estão.
# Na primeira vez que abrir, a Nova mostra a tela de ativação com o código da máquina (ver README, "Licença").
set -e

PASTA=/home/jkb/jukelinux
MUSICAS=/home/jkb/musicas
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
INICIAR_SOZINHA=""
[ "$1" = "--iniciar-sozinha" ] && INICIAR_SOZINHA=sim

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
fi
for programa in mplayer curl xrandr; do
  command -v "$programa" >/dev/null 2>&1 || falha "falta o programa $programa"
done

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
    [ -f "$PASTA/pix.txt.exemplo" ] && chown "$USUARIO": "$PASTA/pix.txt.exemplo"
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

echo "JukeLinux Nova instalada em $PASTA/jukelinux (usuário: ${USUARIO:-root})."
echo "Para abrir agora: $PASTA/iniciar-jukebox.sh"
echo "Ao abrir, se a máquina ainda não tiver licença, aparece a tela de ativação com o código da máquina."
echo "Para voltar o executável anterior: sudo sh $0 --desfazer"
