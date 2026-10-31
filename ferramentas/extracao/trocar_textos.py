"""Deixa o C descompilado legível: troca os rótulos __JUKELINUX1__LdNNN (com ou sem &) pelo texto real entre aspas
(textos_ld.json, de textos_ld.py) e os acessos *(tipo *)(U_JUKELINUX1_FORM1 + 0xNNN) pelo nome do componente
(campos_form1.json, de campos_form1.py). Escreve uma cópia em pasta_saida, mantendo os nomes dos arquivos.

Uso: python trocar_textos.py textos_ld.json campos_form1.json pasta_c pasta_saida
"""
import json
import os
import re
import sys

textos = json.load(open(sys.argv[1], encoding='utf-8'))
campos = {int(k, 16): v for k, v in json.load(open(sys.argv[2], encoding='utf-8')).items()}
entrada, saida = sys.argv[3], sys.argv[4]
os.makedirs(saida, exist_ok=True)
RE = re.compile(r'&?_*JUKELINUX1_*(Ld\d+)\b')
RE_CAMPO = re.compile(r'\*\([\w ]+\*\)\(U_JUKELINUX1_FORM1 \+ (0x[0-9a-f]+)\)')


def campo(m):
    nome = campos.get(int(m.group(1), 16))
    return f'Form1.{nome}' if nome else m.group(0)


def troca(m):
    t = textos.get(m.group(1))
    if t is None:
        return m.group(0)
    return '"' + t.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n').replace('\r', '\\r') + '"'


total = 0
for nome in sorted(os.listdir(entrada)):
    if not nome.endswith('.c'):
        continue
    src = open(os.path.join(entrada, nome), encoding='utf-8', errors='replace').read()
    novo, n = RE.subn(troca, src)
    novo, n2 = RE_CAMPO.subn(campo, novo)
    total += n + n2
    open(os.path.join(saida, nome), 'w', encoding='utf-8', newline='\n').write(novo)
print(total, 'rótulos trocados')
