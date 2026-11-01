#!/bin/sh
# Refaz a tradução completa: C legível -> globais.inc -> jukelinux1_rotinas.inc -> eventos.inc.
# Uso: sh regerar.sh <pasta da descompilação (com v2/funcoes, textos_ld.json, campos_form1.json, funcoes.txt)> <binário original>
set -e
D="$1"; BIN="$2"
E="$(cd "$(dirname "$0")" && pwd)"; S="$E/../../src"
python -I "$E/trocar_textos.py" "$D/textos_ld.json" "$D/campos_form1.json" "$D/v2/funcoes" "$D/v2/legivel"
python -I "$E/globais.py" "$BIN" "$D/v2/legivel" "$S/globais.inc"
python -I "$E/gerar_rotinas.py" "$D/v2/legivel" "$D/funcoes.txt" "$E/componentes.json" "$S/globais.inc" "$S"
python -I "$E/gerar_unit.py" "$E/componentes.json" "$S"
