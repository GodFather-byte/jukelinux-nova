#!/bin/sh
# Teste de integração: abre a jukebox numa tela virtual (Xvfb) com uma máquina de teste e confere o que ela grava.
#   sudo sh testes/integracao/rodar.sh [executável]     (padrão: ./jukelinux)
# A jukebox só roda em /home/jkb/jukelinux: o que já estiver lá (e em /home/jkb/musicas) é guardado e volta no fim.
# MANTER=/pasta guarda lá uma cópia da máquina de teste no fim (para investigar uma falha).
# Precisa de fpc, python3, Xvfb (xvfb-run) e da licença compilada (src/licenca_chave.inc ou a de desenvolvimento).
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
RAIZ=$(cd "$AQUI/../.." && pwd)
EXE=$(cd "$(dirname "${1:-$RAIZ/jukelinux}")" && pwd)/$(basename "${1:-$RAIZ/jukelinux}")
JUKE=/home/jkb/jukelinux
MUS=/home/jkb/musicas
T=$(mktemp -d)
[ -x "$EXE" ] || { echo "ERRO: não achei o executável $EXE"; exit 1; }

guarda() { if [ -e "$1" ]; then mv "$1" "$T/guardado.$(basename "$1")"; fi; }
devolve() {
  pkill -f "^$EXE" 2>/dev/null || true
  if [ -n "$MANTER" ]; then rm -rf "$MANTER"; mkdir -p "$MANTER"; cp -a "$JUKE" "$MUS" "$MANTER/"; fi
  rm -rf "$JUKE" "$MUS"
  [ -e "$T/guardado.jukelinux" ] && mv "$T/guardado.jukelinux" "$JUKE"
  [ -e "$T/guardado.musicas" ] && mv "$T/guardado.musicas" "$MUS"
  rm -rf "$T"
}
trap devolve EXIT
guarda "$JUKE"
guarda "$MUS"
mkdir -p "$JUKE" "$MUS"

# licença desta máquina e dados de teste
SRC="$RAIZ/src"
[ -f "$SRC/licenca_chave.inc" ] || cp "$SRC/licenca_chave.desenvolvimento.inc" "$T/licenca_chave.inc"
mkdir "$T/u"
fpc -Mobjfpc -Sh -O2 -Fu"$SRC" -Fi"$T" -Fi"$SRC" -FU"$T/u" -FE"$T" "$AQUI/licenca_teste.lpr" >/dev/null
"$T/licenca_teste" "$JUKE"
python3 -I "$AQUI/dados.py" "$JUKE" "$MUS"
rm -f /tmp/jukelinux-nova-erros.log

# abre a jukebox por alguns segundos (carrega CDs, cartões e o ranking) e fecha
cd "$JUKE"
if [ -n "$DISPLAY" ] && command -v xdpyinfo >/dev/null && xdpyinfo >/dev/null 2>&1; then
  timeout 20 "$EXE" >"$T/saida.txt" 2>&1 &
else
  timeout 20 xvfb-run -a -s "-screen 0 1024x768x24" "$EXE" >"$T/saida.txt" 2>&1 &
fi
for i in $(seq 1 40); do
  grep -q "Inicio da Operacao" "$JUKE/log.txt" 2>/dev/null && break
  sleep 0.5
done
sleep 2
pkill -f "^$EXE" 2>/dev/null || true
sleep 1

FALHAS=0
confere() { if eval "$2"; then echo "OK    $1"; else echo "FALHA $1"; FALHAS=$((FALHAS + 1)); fi; }
confere "a jukebox abriu (Inicio da Operacao no log)" 'grep -q "Inicio da Operacao" "$JUKE/log.txt"'
confere "sem exceção" '[ ! -s /tmp/jukelinux-nova-erros.log ]'
confere "configurações padrão criadas (pastas.txt, creditos.txt)" '[ -f "$JUKE/pastas.txt" ] && [ -f "$JUKE/creditos.txt" ]'
confere "50 mais tocadas: ANUNCIACAO primeiro, 3 vezes" \
  '[ "$(sed -n 1p "$JUKE/50musicasmaistocadas.txt")" = "/$MUS/ALCEU VALENCA - AO VIVO/01 - ANUNCIACAO.mp3" ] && [ "$(sed -n 2p "$JUKE/50musicasmaistocadas.txt")" = 3 ]'
confere "50 mais tocadas: EMOCOES em segundo, 2 vezes" \
  '[ "$(sed -n 3p "$JUKE/50musicasmaistocadas.txt")" = "/$MUS/ROBERTO CARLOS - EMOCOES/01 - EMOCOES.mp3" ] && [ "$(sed -n 4p "$JUKE/50musicasmaistocadas.txt")" = 2 ]'
confere "cartão 12345678 com 7 créditos (aacartoes.txt)" 'grep -qx "12345678 - 7 - N" "$JUKE/aacartoes.txt"'
confere "cartoes.ccc continua com 2 registros de 38 bytes" '[ "$(stat -c %s "$JUKE/cartoes.ccc")" = 76 ]'
confere "lançamento: ritmo LANCAMENTOS na lista de ritmos" 'grep -q "LANCAMENTOS" "$JUKE/ritmos.txt"'
confere "inicio.sh criado" '[ -x "$JUKE/inicio.sh" ]'
if [ "$FALHAS" -gt 0 ]; then
  echo "--- log.txt"; tail -20 "$JUKE/log.txt" 2>/dev/null || true
  echo "--- erros"; cat /tmp/jukelinux-nova-erros.log 2>/dev/null || true
  echo "--- saída"; tail -20 "$T/saida.txt" || true
  exit 1
fi
echo "Integração: tudo OK"
