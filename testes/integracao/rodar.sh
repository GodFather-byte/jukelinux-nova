#!/bin/sh
# Teste de integração: abre a jukebox numa tela virtual (Xvfb) com uma máquina de teste e a nuvem rodando aqui, e
# confere o que ela grava e o que chega à nuvem.
#   sudo sh testes/integracao/rodar.sh [executável]     (padrão: ./jukelinux-teste)
# O executável precisa ser o do modo "Teste" (lazbuild --build-mode=Teste jukelinux.lpi): ele confere as licenças
# com a chave de desenvolvimento, que a nuvem de teste usa para assinar.
# A jukebox só roda em /home/jkb/jukelinux: o que já estiver lá (e em /home/jkb/musicas) é guardado e volta no fim.
# MANTER=/pasta guarda lá uma cópia da máquina de teste no fim (para investigar uma falha).
# Precisa de python3, node 22.13+, curl, Xvfb e xdotool (sem ele, as teclas não são testadas).
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
RAIZ=$(cd "$AQUI/../.." && pwd)
EXE=$(cd "$(dirname "${1:-$RAIZ/jukelinux-teste}")" && pwd)/$(basename "${1:-$RAIZ/jukelinux-teste}")
JUKE=/home/jkb/jukelinux
MUS=/home/jkb/musicas
T=$(mktemp -d)
NUVEM=""
XVFB=""
[ -x "$EXE" ] || { echo "ERRO: não achei o executável $EXE (lazbuild --build-mode=Teste jukelinux.lpi)"; exit 1; }

guarda() { if [ -e "$1" ]; then mv "$1" "$T/guardado.$(basename "$1")"; fi; }
devolve() {
  pkill -f "^$EXE" 2>/dev/null || true
  if [ -n "$NUVEM" ]; then kill "$NUVEM" 2>/dev/null || true; wait "$NUVEM" 2>/dev/null || true; fi
  [ -n "$XVFB" ] && kill "$XVFB" 2>/dev/null || true
  if [ -n "$MANTER" ]; then rm -rf "$MANTER"; mkdir -p "$MANTER"; cp -a "$JUKE" "$MUS" "$T/nuvem.db" "$MANTER/" 2>/dev/null || true; fi
  rm -rf "$JUKE" "$MUS"
  [ -e "$T/guardado.jukelinux" ] && mv "$T/guardado.jukelinux" "$JUKE"
  [ -e "$T/guardado.musicas" ] && mv "$T/guardado.musicas" "$MUS"
  rm -rf "$T"
}
trap devolve EXIT
guarda "$JUKE"
guarda "$MUS"
mkdir -p "$JUKE" "$MUS"
python3 -I "$AQUI/dados.py" "$JUKE" "$MUS"
rm -f /tmp/jukelinux-nova-erros.log

# a nuvem, com a chave de desenvolvimento; a jukebox fala com ela a cada 10 s
PORTA=$(node -e "const s=require('net').createServer().listen(0,()=>{console.log(s.address().port);s.close()})")
SENHA=senha-do-teste-de-integracao
BASE="http://127.0.0.1:$PORTA"
PORTA=$PORTA BANCO="$T/nuvem.db" ADMIN_SENHA=$SENHA INTERVALO_CONTATO=10 \
  LICENCA_CHAVE_PRIVADA_ARQUIVO="$RAIZ/nuvem/testes/chave-desenvolvimento.pem" \
  node --disable-warning=ExperimentalWarning "$RAIZ/nuvem/servidor.js" >"$T/nuvem.log" 2>&1 &
NUVEM=$!
for i in $(seq 1 50); do curl -s "$BASE/saude" >/dev/null 2>&1 && break; sleep 0.1; done
echo "url = $BASE" > "$JUKE/nuvem.txt"

espera_log() {  # espera_log TEXTO SEGUNDOS
  for i in $(seq 1 $(($2 * 2))); do grep -q "$1" "$JUKE/log.txt" 2>/dev/null && return 0; sleep 0.5; done
  return 1
}

# abre a jukebox SEM licença: ela fica na tela de ativação e aparece no painel aguardando liberação
for N in 91 92 93 94 95; do [ -e "/tmp/.X$N-lock" ] || break; done
Xvfb ":$N" -screen 0 1024x768x24 >/dev/null 2>&1 &
XVFB=$!
export DISPLAY=":$N"
sleep 1
cd "$JUKE"
timeout 120 "$EXE" >"$T/saida.txt" 2>&1 &
espera_log "Inicio da Operacao" 20 || true
espera_log "Licenca: sem licença" 10 || true
LIBEROU=""
for i in $(seq 1 30); do
  if node "$RAIZ/testes/nuvem/painel.mjs" "$BASE" "$SENHA" liberar >/dev/null 2>&1; then LIBEROU=sim; break; fi
  sleep 0.5
done
espera_log "Licenca: liberada" 30 || true
sleep 5  # o aviso de "Ativação OK" sai

CARTAO_LIDO=""
if command -v xdotool >/dev/null; then
  # leitor de código de barras: 0 começa a leitura, depois os dígitos e Enter
  xdotool key z                       # sai da tela de abertura (tecla sem função; "a" é crédito)
  sleep 1
  xdotool type --delay 80 01234567
  xdotool key Return
  # o painel do cartão sobe, mostra os créditos e desce (uns 6 s), e só então o cartão é gravado
  for i in $(seq 1 30); do
    python3 -I "$AQUI/cartao.py" "$JUKE/cartoes.ccc" | grep -qx "01234567 - 4" && break
    sleep 0.5
  done
  CARTAO_LIDO=sim
  # pesquisa pelas teclas da jukebox: Cancelar 3x abre; CD+ escolhe a letra, Tocar põe; Música- desce na lista
  sleep 1
  xdotool key q; sleep 0.3; xdotool key q; sleep 0.3; xdotool key q; sleep 1
  for L in 4 8 2; do                       # E (A+4), M (E+8), O (M+2)
    for i in $(seq "$L"); do xdotool key h; sleep 0.1; done
    xdotool key k; sleep 0.3
  done
  xdotool key i; sleep 0.3; xdotool key i; sleep 0.3; xdotool key k; sleep 2
  # 3 pulsos de R$ 1 no noteiro (tecla de crédito) e Tocar: a música escolhida na pesquisa vai para a fila
  xdotool key a; sleep 0.3; xdotool key a; sleep 0.3; xdotool key a; sleep 1
  xdotool key k; sleep 1
  # a fila da nuvem vai no próximo contato (a cada 10 s)
  espera_log "Musica Selecionada" 5 || true
  sleep 12
else
  echo "(sem xdotool: as teclas não são testadas)"
fi
pkill -f "^$EXE" 2>/dev/null || true
sleep 1

CSV=$(node "$RAIZ/testes/nuvem/painel.mjs" "$BASE" "$SENHA" csv 2>/dev/null || true)
FALHAS=0
confere() { if eval "$2"; then echo "OK    $1"; else echo "FALHA $1"; FALHAS=$((FALHAS + 1)); fi; }
confere "a jukebox abriu (Inicio da Operacao no log)" 'grep -q "Inicio da Operacao" "$JUKE/log.txt"'
confere "sem exceção" '[ ! -s /tmp/jukelinux-nova-erros.log ]'
confere "sem licença: tela de ativação e máquina aguardando liberação na nuvem" \
  'grep -q "Licenca: sem licença" "$JUKE/log.txt" && [ -n "$LIBEROU" ]'
confere "liberada no painel: a licença chegou pela internet e a jukebox liberou sozinha" \
  'grep -q "Licenca: nova licenca da nuvem" "$JUKE/log.txt" && grep -q "Licenca: liberada" "$JUKE/log.txt"'
confere "licenca.txt gravado" 'grep -q "^JUKELINUX NOVA LICENCA 1" "$JUKE/licenca.txt"'
confere "configurações padrão criadas (pastas.txt, creditos.txt)" '[ -f "$JUKE/pastas.txt" ] && [ -f "$JUKE/creditos.txt" ]'
confere "50 mais tocadas: ANUNCIACAO primeiro, 3 vezes" \
  '[ "$(sed -n 1p "$JUKE/50musicasmaistocadas.txt")" = "/$MUS/ALCEU VALENCA - AO VIVO/01 - ANUNCIACAO.mp3" ] && [ "$(sed -n 2p "$JUKE/50musicasmaistocadas.txt")" = 3 ]'
confere "50 mais tocadas: EMOCOES em segundo, 2 vezes" \
  '[ "$(sed -n 3p "$JUKE/50musicasmaistocadas.txt")" = "/$MUS/ROBERTO CARLOS - EMOCOES/01 - EMOCOES.mp3" ] && [ "$(sed -n 4p "$JUKE/50musicasmaistocadas.txt")" = 2 ]'
confere "cartão 12345678 com 7 créditos (aacartoes.txt)" 'grep -qx "12345678 - 7 - N" "$JUKE/aacartoes.txt"'
confere "cartoes.ccc continua com 3 registros de 38 bytes" '[ "$(stat -c %s "$JUKE/cartoes.ccc")" = 114 ]'
confere "lançamento: ritmo LANCAMENTOS na lista de ritmos" 'grep -q "LANCAMENTOS" "$JUKE/ritmos.txt"'
confere "inicio.sh criado" '[ -x "$JUKE/inicio.sh" ]'
if [ -n "$CARTAO_LIDO" ]; then
  confere "pesquisa EMO pelas teclas leva à música 01 - EMOCOES" 'grep -q "Pesquisa: EMO -> 01 - EMOCOES" "$JUKE/log.txt"'
  confere "cartão 01234567 lido no modo Bar: usou 1 crédito (5 -> 4 no cartoes.ccc)" 'python3 -I "$AQUI/cartao.py" "$JUKE/cartoes.ccc" | grep -qx "01234567 - 4"'
  confere "nuvem: os 3 pulsos do noteiro (R\$ 3) e a música pedida chegaram ao relatório" \
    'echo "$CSV" | grep -q "^TOTAL;3;0;0;3;1"'
  confere "fila da nuvem vazia (tudo confirmado)" '[ ! -s "$JUKE/nuvem-fila.txt" ]'
fi
if [ "$FALHAS" -gt 0 ]; then
  echo "--- log.txt"; tail -30 "$JUKE/log.txt" 2>/dev/null || true
  echo "--- erros"; cat /tmp/jukelinux-nova-erros.log 2>/dev/null || true
  echo "--- saída"; tail -20 "$T/saida.txt" || true
  echo "--- nuvem"; tail -20 "$T/nuvem.log" || true
  echo "--- relatório"; echo "$CSV"
  exit 1
fi
echo "Integração: tudo OK"
