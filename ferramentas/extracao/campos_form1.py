"""Lê a tabela de campos publicados do TForm1 (RTTI do FPC 2.6, i386) e grava {deslocamento: nome}, para trocar
os acessos *(FORM1 + 0xNNN) do código descompilado pelo nome do componente.

VMT: +0 tamanho da instância, +8 classe pai, +12 nome, +24 tabela de campos.
Tabela de campos: word quantidade, ponteiro para a tabela de classes, e por campo: longword deslocamento,
word índice da classe, shortstring nome.

Uso: python campos_form1.py jukelinux saida.json
"""
import json
import struct
import sys

D = open(sys.argv[1], 'rb').read()
shoff = struct.unpack_from('<I', D, 0x20)[0]
shentsize, shnum, shstrndx = struct.unpack_from('<HHH', D, 0x2E)
secs = [struct.unpack_from('<IIIIIIIIII', D, shoff + i * shentsize) for i in range(shnum)]


def off_de(addr):
    for s in secs:
        if s[3] and s[3] <= addr < s[3] + s[5] and s[1] != 8:
            return s[4] + addr - s[3]
    raise ValueError(hex(addr))


symtab = next(s for s in secs if s[1] == 2)
strtab = secs[symtab[6]]
vmt = None
for i in range(symtab[5] // 16):
    st_name, st_value = struct.unpack_from('<II', D, symtab[4] + i * 16)
    o = strtab[4] + st_name
    if D[o:D.index(b'\0', o)] == b'VMT_JUKELINUX1_TFORM1':
        vmt = st_value
if vmt is None:
    raise SystemExit('VMT do TForm1 não encontrada')

v = off_de(vmt)
ft = off_de(struct.unpack_from('<I', D, v + 24)[0])
n = struct.unpack_from('<H', D, ft)[0]
p = ft + 2 + 4
campos = {}
for _ in range(n):
    desl, _idx = struct.unpack_from('<IH', D, p); p += 6
    nome = D[p + 1:p + 1 + D[p]].decode('latin1'); p += 1 + D[p]
    campos[hex(desl)] = nome
json.dump(campos, open(sys.argv[2], 'w', encoding='utf-8'), indent=0)
print(n, 'campos; primeiro', next(iter(campos.items())), 'último', list(campos.items())[-1])
