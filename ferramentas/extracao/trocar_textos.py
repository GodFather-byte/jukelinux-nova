"""Deixa o C descompilado legível. Escreve uma cópia em pasta_saida, com os mesmos nomes de arquivo.

Troca:
- __JUKELINUX1__LdNNN (com ou sem &) pelo texto entre aspas, quando textos_ld.json tiver a chave
  (textos_ld.py, a partir do binário). Sem o binário o rótulo fica como está.
- o ponteiro do componente pelo nome. No C do Ghidra há dois jeitos:
  *(tipo *)(FORM1 + 0xNNN) e *(tipo *)(in_EAX + 0xNNN) são o componente (o parêntese é o endereço
  do campo; um * lê o ponteiro). U_JUKELINUX1_FORM1[0xIII] já é o ponteiro, com deslocamento III*4.
  Os dois viram Form1.Nome. O * que sobra numa chamada virtual é a VMT.

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

RE_TEXTO = re.compile(r'&?_*JUKELINUX1_*(Ld\d+)\b')
# Um deref: lê o ponteiro guardado no campo. O que sobra (outro *) é a VMT.
RE_ENDERECO = re.compile(
    r'\*\([^)]*\*\)\s*\(\s*(?:U_JUKELINUX1_FORM1|in_EAX)\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)')
# O índice do Ghidra já é o ponteiro do componente; o deslocamento em bytes é índice*4.
RE_INDICE = re.compile(r'U_JUKELINUX1_FORM1\[(0x[0-9a-fA-F]+)\]')


def nome_de(deslocamento):
    nome = campos.get(deslocamento)
    return f'Form1.{nome}' if nome else None


def troca_endereco(m):
    texto = m.group(1)
    desl = int(texto, 16) if texto.lower().startswith('0x') else int(texto)
    return nome_de(desl) or m.group(0)


def troca_indice(m):
    return nome_de(int(m.group(1), 16) * 4) or m.group(0)


def troca_texto(m):
    t = textos.get(m.group(1))
    if t is None:
        return m.group(0)
    trocas[0] += 1
    return '"' + t.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n').replace('\r', '\\r') + '"'


total_c = 0
trocas = [0]
for nome in sorted(os.listdir(entrada)):
    if not nome.endswith('.c'):
        continue
    src = open(os.path.join(entrada, nome), encoding='utf-8', errors='replace').read()
    novo = RE_TEXTO.sub(troca_texto, src)
    novo, n2 = RE_ENDERECO.subn(troca_endereco, novo)
    novo, n3 = RE_INDICE.subn(troca_indice, novo)
    total_c += n2 + n3
    open(os.path.join(saida, nome), 'w', encoding='utf-8', newline='\n').write(novo)
print(trocas[0], 'textos;', total_c, 'componentes')
