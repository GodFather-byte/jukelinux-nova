"""Remonta o Form1 da JukeLinux na ordem exata: a função init da unit (registro do .lrs) carrega, em sequência,
o endereço de cada pedaço de texto do formulário — inclusive os pedaços repetidos que o compilador guardou só
uma vez. Lendo esses endereços dentro da init, sai o formulário byte a byte."""
import struct
import sys

exe, saida_bin = sys.argv[1], sys.argv[2]
d = open(exe, 'rb').read()

# Cabeçalhos de programa: endereço virtual <-> posição no arquivo.
phoff, = struct.unpack_from('<I', d, 0x1C)
phentsize, phnum = struct.unpack_from('<HH', d, 0x2A)
segs = []
for i in range(phnum):
    p_type, p_offset, p_vaddr, _, p_filesz, *_ = struct.unpack_from('<IIIIII', d, phoff + i * phentsize)
    if p_type == 1: segs.append((p_vaddr, p_offset, p_filesz))
def va_para_off(va):
    for v, o, n in segs:
        if v <= va < v + n: return o + va - v
    return None
def off_para_va(off):
    for v, o, n in segs:
        if o <= off < o + n: return v + off - o
    return None

# Símbolos: a função de inicialização da unit.
shoff, = struct.unpack_from('<I', d, 0x20)
shentsize, shnum, _ = struct.unpack_from('<HHH', d, 0x2E)
secs = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * shentsize) for i in range(shnum)]
symtab = next(s for s in secs if s[1] == 2); strtab = secs[symtab[6]]
init = None
for off in range(symtab[4], symtab[4] + symtab[5], 16):
    n, v, sz, info, _, _ = struct.unpack_from('<IIIBBH', d, off)
    nome = d[strtab[4] + n:d.index(b'\0', strtab[4] + n)].decode('latin1')
    if nome in ('INIT$_JUKELINUX1', 'JUKELINUX1_init', 'init$_JUKELINUX1') or (nome.upper() == 'INIT$_JUKELINUX1'):
        init = (v, sz, nome)
if not init:
    cands = []
    for off in range(symtab[4], symtab[4] + symtab[5], 16):
        n, v, sz, info, _, _ = struct.unpack_from('<IIIBBH', d, off)
        nome = d[strtab[4] + n:d.index(b'\0', strtab[4] + n)].decode('latin1')
        if 'JUKELINUX1' in nome.upper() and 'INIT' in nome.upper(): cands.append((sz, v, nome))
    sz, v, nome = max(cands); init = (v, sz, nome)
print('função de inicialização:', init[2], hex(init[0]), init[1], 'bytes')

# Todos os pedaços de texto (constantes ansistring: refcount -1 + tamanho + dados) a partir do TPF0 do Form1.
ini = d.find(b'TPF0\x06TForm1') - 8
pedacos = {}
p = ini
while d[p:p + 4] == b'\xff\xff\xff\xff':
    ln = struct.unpack_from('<I', d, p + 4)[0]
    pedacos[off_para_va(p + 8)] = d[p + 8:p + 8 + ln]
    p += 8 + ln
    q = p
    while q < p + 16 and d[q:q + 4] != b'\xff\xff\xff\xff': q += 1
    if d[q:q + 4] != b'\xff\xff\xff\xff': break
    p = q
print('pedaços distintos guardados:', len(pedacos))

# Na init, os endereços dos pedaços aparecem como valores imediatos de 32 bits, na ordem do formulário.
codigo = d[va_para_off(init[0]):va_para_off(init[0]) + init[1]]
ordem = []
i = 0
while i <= len(codigo) - 4:
    v = struct.unpack_from('<I', codigo, i)[0]
    if v in pedacos:
        ordem.append(v); i += 4
    else:
        i += 1
print('referências na init:', len(ordem), '| repetidas:', len(ordem) - len(set(ordem)))
dados = b''.join(pedacos[v] for v in ordem)
print('formulário remontado:', len(dados), 'bytes; começa com', dados[:12])
open(saida_bin, 'wb').write(dados)
