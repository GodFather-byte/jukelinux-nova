#!/bin/sh
# Testa a decifração das músicas (src/musicacifra.pas) contra um codificador independente do formato da original.
# Precisa de: fpc e python3.
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
T=$(mktemp -d)
limpa() { [ -n "$T" ] && [ -d "$T" ] && rm -r "$T"; }
trap limpa EXIT
python3 -I -c "import os; open('$T/musica.bin','wb').write(b'ID3'+os.urandom(2048*7+330)); open('$T/exato.bin','wb').write(os.urandom(2048*3)); open('$T/vazio.bin','wb').write(b'')"
python3 -I "$AQUI/cifra_original.py" "$T/musica.bin" "$T/py71.cif" 71 "SOM LIVRE" 37
python3 -I "$AQUI/cifra_original.py" "$T/musica.bin" "$T/py200.cif" 200 "X" 5000
python3 -I "$AQUI/cifra_original.py" "$T/exato.bin" "$T/py_exato.cif" 71 "Y" 1
mkdir "$T/u"
fpc -Mobjfpc -Sh -O2 -Fu"$AQUI/../../src" -FU"$T/u" -FE"$T" "$AQUI/teste_musica.lpr" >/dev/null
"$T/teste_musica" "$T"
