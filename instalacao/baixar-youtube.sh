#!/bin/bash
# Baixa músicas (ou clipes) do YouTube para um CD da jukebox, com o yt-dlp. Usa janelas (zenity) se rodar sem
# argumentos; pelo terminal:
#   baixar-youtube.sh LINK "ARTISTA - CD" "MP - MPB" [mp3|mp4]
# LINK pode ser um vídeo ou uma playlist (cada vídeo vira uma faixa). O CD fica em /home/jkb/musicas/ARTISTA - CD/
# no formato da jukebox: "01 - NOME.mp3" (ou .mp4 para DVD), genero.txt, capa.jpg e capapequena.jpg (da miniatura
# do vídeo). Se o CD já existir, as faixas novas entram depois das que já estão (até 40, o limite da jukebox).
# A jukebox lê os CDs ao abrir: feche e abra de novo para aparecerem.
# Atenção: baixe só o que você tem direito de tocar (direitos autorais / ECAD e termos de uso do YouTube).
set -u
MUSICAS=/home/jkb/musicas
JUKE=/home/jkb/jukelinux
YTDLP="$JUKE/yt-dlp"
[ -x "$YTDLP" ] || YTDLP=$(command -v yt-dlp || true)
LIMITE=40

janela() { [ -n "${DISPLAY:-}" ] && command -v zenity >/dev/null; }
erro() {
  if janela; then zenity --error --title="Baixar do YouTube" --text="$1" 2>/dev/null; else printf 'ERRO: %b\n' "$1" >&2; fi
  exit 1
}
aviso() {
  if janela; then zenity --info --title="Baixar do YouTube" --text="$1" 2>/dev/null; else printf '%b\n' "$1"; fi
}
# nome no padrão dos CDs da jukebox: maiúsculas, sem acento, sem caracteres que atrapalham em nome de arquivo
nome_jukebox() {
  python3 -c 'import sys, unicodedata, re
t = unicodedata.normalize("NFKD", sys.argv[1]).encode("ascii", "ignore").decode().upper()
print(re.sub(r"\s+", " ", re.sub(r"[/:*?\"<>|\\]", " ", t)).strip()[:80])' "$1"
}

[ -n "$YTDLP" ] || erro "Falta o yt-dlp. Rode de novo o instalador da jukebox (sudo sh instalar.sh)."
command -v ffmpeg >/dev/null || erro "Falta o ffmpeg. Rode de novo o instalador da jukebox (sudo sh instalar.sh)."

LINK=${1:-}
CD=${2:-}
GENERO=${3:-}
TIPO=${4:-}
if [ -z "$LINK" ]; then
  janela || erro "Uso: $0 LINK \"ARTISTA - CD\" \"RITMO\" [mp3|mp4]"
  LINK=$(zenity --entry --title="Baixar do YouTube" --width=600 \
    --text="Cole o link do vídeo ou da playlist do YouTube:" 2>/dev/null) || exit 0
  CD=$(zenity --entry --title="Baixar do YouTube" --width=600 \
    --text="Nome do CD (ARTISTA - NOME DO CD):" 2>/dev/null) || exit 0
  RITMOS=$(cat "$MUSICAS"/*/genero.txt 2>/dev/null | tr -d '\r' | sed '/^$/d' | sort -u)
  GENERO=$(printf '%s\n' "$RITMOS" | zenity --list --title="Baixar do YouTube" --width=400 --height=450 \
    --text="Ritmo do CD (ou escolha \"Outro\" para digitar):" --column="Ritmo" Outro 2>/dev/null) || exit 0
  if [ "$GENERO" = "Outro" ] || [ -z "$GENERO" ]; then
    GENERO=$(zenity --entry --title="Baixar do YouTube" --text="Ritmo (ex.: MP - MPB):" 2>/dev/null) || exit 0
  fi
  TIPO=$(zenity --list --radiolist --title="Baixar do YouTube" --width=400 --height=220 --text="Baixar como:" \
    --column="" --column="Tipo" --column="" TRUE mp3 "Música (só o áudio)" FALSE mp4 "Vídeo (DVD)" \
    --hide-column=2 --print-column=2 2>/dev/null) || exit 0
fi
TIPO=${TIPO:-mp3}
CD=$(nome_jukebox "$CD")
GENERO=$(nome_jukebox "$GENERO")
[ -n "$LINK" ] && [ -n "$CD" ] && [ -n "$GENERO" ] || erro "Faltou o link, o nome do CD ou o ritmo."
case "$TIPO" in mp3|mp4) ;; *) erro "Tipo deve ser mp3 ou mp4." ;; esac

PASTA_CD="$MUSICAS/$CD"
mkdir -p "$PASTA_CD" || erro "Não consegui criar $PASTA_CD"
JA=$(find "$PASTA_CD" -maxdepth 1 -type f \( -iname '*.mp3' -o -iname '*.mp4' -o -iname '*.wma' -o -iname '*.mkv' \) | wc -l)
[ "$JA" -lt "$LIMITE" ] || erro "O CD já tem $LIMITE faixas (o máximo da jukebox)."
SOBRA=$((LIMITE - JA))
[ -f "$PASTA_CD/genero.txt" ] || printf '%s\n' "$GENERO" > "$PASTA_CD/genero.txt"

# o YouTube muda sempre: atualiza o yt-dlp antes (se ele for da pasta da jukebox, o usuário pode atualizar)
"$YTDLP" -U >/dev/null 2>&1 || true

T=$(mktemp -d)
trap 'rm -rf "$T"' EXIT
if [ "$TIPO" = mp3 ]; then
  FORMATO=(-x --audio-format mp3 --audio-quality 0)
else
  FORMATO=(-f "bv*[height<=720][ext=mp4]+ba[ext=m4a]/b[ext=mp4]/bv*[height<=720]+ba/b" --merge-output-format mp4)
fi
baixa() {
  "$YTDLP" --yes-playlist --playlist-end "$SOBRA" --no-overwrites --restrict-filenames \
    --write-thumbnail --convert-thumbnails jpg \
    -o "$T/%(playlist_index|1)03d %(title)s.%(ext)s" -o "thumbnail:$T/capa-%(playlist_index|1)03d.%(ext)s" \
    "${FORMATO[@]}" "$LINK"
}
if janela; then
  baixa 2>&1 | tee "$T/saida.txt" | zenity --progress --pulsate --auto-close --no-cancel \
    --title="Baixar do YouTube" --text="Baixando para $CD..." 2>/dev/null
else
  baixa 2>&1 | tee "$T/saida.txt"
fi

# numera depois das faixas que o CD já tem: "NN - NOME.ext"
N=$JA
BAIXADAS=0
for ARQ in "$T"/*."$TIPO"; do
  [ -e "$ARQ" ] || continue
  N=$((N + 1))
  [ "$N" -le "$LIMITE" ] || break
  TITULO=$(basename "$ARQ" ".$TIPO" | sed 's/^[0-9]\{3\} //' | tr '_' ' ')
  TITULO=$(nome_jukebox "$TITULO")
  mv "$ARQ" "$PASTA_CD/$(printf '%02d' "$N") - ${TITULO:-FAIXA $N}.$TIPO"
  BAIXADAS=$((BAIXADAS + 1))
done
[ "$BAIXADAS" -gt 0 ] || erro "Nada foi baixado. Confira o link. Detalhes:\n$(tail -5 "$T/saida.txt")"

# capas da miniatura do primeiro vídeo (se o CD ainda não tiver)
MINI=$(ls "$T"/capa-*.jpg 2>/dev/null | head -1)
if [ -n "$MINI" ]; then
  [ -f "$PASTA_CD/capa.jpg" ] || ffmpeg -loglevel error -y -i "$MINI" \
    -vf "crop='min(iw,ih)':'min(iw,ih)',scale=400:400" "$PASTA_CD/capa.jpg"
  [ -f "$PASTA_CD/capapequena.jpg" ] || ffmpeg -loglevel error -y -i "$MINI" \
    -vf "crop='min(iw,ih)':'min(iw,ih)',scale=200:200" "$PASTA_CD/capapequena.jpg"
fi

echo "$(date '+%d/%m/%y %H:%M') - YouTube: $BAIXADAS faixa(s) em $CD ($LINK)" >> "$JUKE/log-youtube.txt" 2>/dev/null || true
aviso "Pronto: $BAIXADAS faixa(s) em \"$CD\" ($GENERO).\nFeche e abra a jukebox para o CD aparecer."
