"""Lista as constantes de texto (_$JUKELINUX1$_LdNNN) do binário original com o conteúdo de cada uma, para trocar
os rótulos __JUKELINUX1__LdNNN do código descompilado pelos textos reais.

ELF de 32 bits sem bibliotecas: lê a .symtab e a seção onde cada símbolo cai. No FPC 2.6 o símbolo LdNNN aponta
para os dados do ansistring; antes dele ficam refcount (-1) e comprimento (4 bytes cada). Constantes curtas
(shortstring) começam pelo byte de comprimento.

Uso: python textos_ld.py jukelinux saida.json
"""
import json
import re
import struct
import sys

D = open(sys.argv[1], 'rb').read()
_, shoff = struct.unpack_from('<II', D, 0x1C)[0], struct.unpack_from('<I', D, 0x20)[0]
shentsize, shnum, shstrndx = struct.unpack_from('<HHH', D, 0x2E)
secs = [struct.unpack_from('<IIIIIIIIII', D, shoff + i * shentsize) for i in range(shnum)]
# (name, type, flags, addr, offset, size, link, info, align, entsize)


def nome_sec(s):
    o = secs[shstrndx][4] + s[0]
    return D[o:D.index(b'\0', o)].decode()


def off_de(addr):
    for s in secs:
        if s[3] and s[3] <= addr < s[3] + s[5] and s[1] != 8:  # 8 = NOBITS
            return s[4] + addr - s[3]
    return None


symtab = next(s for s in secs if s[1] == 2)
strtab = secs[symtab[6]]
textos = {}
for i in range(symtab[5] // 16):
    st_name, st_value, st_size, st_info, _, _ = struct.unpack_from('<IIIBBH', D, symtab[4] + i * 16)
    o = strtab[4] + st_name
    nome = D[o:D.index(b'\0', o)].decode('latin1')
    m = re.fullmatch(r'_\$JUKELINUX1\$_(Ld\d+)', nome)
    if not m:
        continue
    off = off_de(st_value)
    if off is None:
        continue
    ref, n = struct.unpack_from('<iI', D, off - 8)
    if ref == -1 and n < 100000 and D[off + n] == 0:
        raw = D[off:off + n]
    else:  # shortstring
        raw = D[off + 1:off + 1 + D[off]]
    try:
        txt = raw.decode('utf-8')
    except UnicodeDecodeError:
        txt = raw.decode('latin1')
    textos[m.group(1)] = txt

json.dump(dict(sorted(textos.items(), key=lambda kv: int(kv[0][2:]))), open(sys.argv[2], 'w', encoding='utf-8'),
          ensure_ascii=False, indent=0)
print(len(textos), 'textos')
