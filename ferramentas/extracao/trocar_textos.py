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
RE_CAMPO = re.compile(r'\*\([\w ]+\*\)\(U_JUKELINUX1_FORM1 \+ (0x[0-9a-f]+|\d+)\)')
# Mesmo acesso quando o Ghidra trata o Form1 como vetor de 4 bytes: FORM1[0x272] = deslocamento 0x9c8.
RE_INDICE = re.compile(r'U_JUKELINUX1_FORM1\[(0x[0-9a-f]+)\]')
# Campos internos das classes do LCL 1.2 lidos direto (sem o getter). Os nomes vêm do uso no código: Picture
# vai para TPicture.LoadFromFile, Items para TStrings, e Left/Top/Width aparecem nos cálculos de posição
# (por isso levam '?': são inferidos, não lidos do RTTI).
INTERNOS = {0xe4: 'Font', 0xe8: 'Height?', 0x128: 'Left?', 0x230: 'Top?', 0x23c: 'Width?', 0x278: 'Picture',
            0x364: 'Items'}
RE_INTERNO = re.compile(r'\*\([\w ]+\*\)\((Form1\.\w+) \+ (0x[0-9a-f]+)\)')


def campo(m):
    nome = campos.get(int(m.group(1), 0))
    return f'Form1.{nome}' if nome else m.group(0)


def indice(m):
    desl = int(m.group(1), 16) * 4
    if desl in campos:
        return f'Form1.{campos[desl]}'
    if desl in INTERNOS:
        return f'Form1.{INTERNOS[desl]}'
    return m.group(0)


def interno(m):
    nome = INTERNOS.get(int(m.group(2), 16))
    return f'{m.group(1)}.{nome}' if nome else m.group(0)


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
    # Nos métodos do TForm1 o Ghidra guarda o Self (param_1) numa local: trata essa local como o Form1.
    m = re.search(r'^\s*(local_\w+) = param_1;', novo, re.M)
    selfs = [m.group(1)] if m else []
    if '_TFORM1_' in nome:
        selfs.append('param_1')
    for s in selfs:
        novo = re.sub(r'(\*\*?\(\w+ \*\*?\)\()' + s + r' \+', r'\1U_JUKELINUX1_FORM1 +', novo)
    novo, n2 = RE_CAMPO.subn(campo, novo)
    novo, n3 = RE_INDICE.subn(indice, novo)
    novo, n4 = RE_INTERNO.subn(interno, novo)
    total += n + n2 + n3 + n4
    open(os.path.join(saida, nome), 'w', encoding='utf-8', newline='\n').write(novo)
print(total, 'rótulos trocados')
