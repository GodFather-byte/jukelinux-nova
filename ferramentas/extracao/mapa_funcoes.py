"""Lista as funções da unit principal da JukeLinux (símbolos do ELF de 32 bits, que não foi 'limpo')."""
import struct
import sys

exe, saida = sys.argv[1], sys.argv[2]
d = open(exe, 'rb').read()
shoff, = struct.unpack_from('<I', d, 0x20)
shentsize, shnum, shstrndx = struct.unpack_from('<HHH', d, 0x2E)
secs = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * shentsize) for i in range(shnum)]
nomes_sec = secs[shstrndx]
def nome_sec(off): return d[nomes_sec[4] + off:d.index(b'\0', nomes_sec[4] + off)].decode()
symtab = next(s for s in secs if s[1] == 2)
strtab = secs[symtab[6]]
funcs = []
for off in range(symtab[4], symtab[4] + symtab[5], 16):
    st_name, st_value, st_size, st_info, _, _ = struct.unpack_from('<IIIBBH', d, off)
    if st_info & 0xF != 2 or not st_value: continue  # só funções
    nome = d[strtab[4] + st_name:d.index(b'\0', strtab[4] + st_name)].decode('latin1')
    if nome.startswith(('JUKELINUX1_', 'U_JUKELINUX1')) or '_TFORM1_' in nome or nome.startswith('JUKELINUX1$'):
        funcs.append((st_value, st_size, nome))
funcs.sort()


def bonito(n):
    # JUKELINUX1_TFORM1_$__TIMERGRAVAPENDRIVETIMER$TOBJECT -> TForm1.TimerGravaPenDriveTimer(TObject)
    n = n.replace('JUKELINUX1_TFORM1_$__', 'TForm1.').replace('JUKELINUX1_', '')
    if '$' in n:
        base, *args = n.split('$')
        n = f"{base}({', '.join(a for a in args if a)})"
    return n


with open(saida, 'w', encoding='utf-8') as f:
    f.write(f'Funções da unit jukelinux1.pas (programa jukelinux, versão de 19/01/2018) — {len(funcs)} funções\n')
    f.write('endereço   tamanho  nome\n')
    for v, s, n in funcs:
        f.write(f'0x{v:08x} {s:7d}  {bonito(n)}\n')
print(len(funcs), 'funções; maiores:')
for v, s, n in sorted(funcs, key=lambda x: -x[1])[:25]:
    print(f'  {s:7d} bytes  {bonito(n)}')
