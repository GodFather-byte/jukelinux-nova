"""Extrai os formulários (telas) Lazarus embutidos num executável: streams binários 'TPF0' viram texto .lfm."""
import os
import struct
import sys

exe, saida = sys.argv[1], sys.argv[2]
d = open(exe, 'rb').read()
os.makedirs(saida, exist_ok=True)


class Leitor:
    def __init__(self, dados, pos):
        self.d, self.p = dados, pos

    def byte(self):
        b = self.d[self.p]; self.p += 1; return b

    def take(self, n):
        v = self.d[self.p:self.p + n]; self.p += n; return v

    def i(self, fmt, n):
        v = struct.unpack_from('<' + fmt, self.d, self.p)[0]; self.p += n; return v

    def sstr(self):
        n = self.byte(); return self.take(n).decode('latin1')


def texto(s):
    if all(32 <= ord(c) < 127 for c in s) and "'" not in s:
        return f"'{s}'"
    partes, atual = [], ''
    for c in s:
        if 32 <= ord(c) < 127 and c != "'":
            atual += c
        else:
            if atual: partes.append(f"'{atual}'"); atual = ''
            partes.append(f"#{ord(c)}" if c != "'" else "''''")
    if atual: partes.append(f"'{atual}'")
    return ''.join(partes) or "''"


def valor(r, ind):
    t = r.byte()
    if t == 0: return 'nil'
    if t == 1:
        itens = []
        while r.d[r.p] != 0: itens.append(valor(r, ind + 2))
        r.byte(); return '(' + ' '.join(itens) + ')'
    if t == 2: return str(r.i('b', 1))
    if t == 3: return str(r.i('h', 2))
    if t == 4: return str(r.i('i', 4))
    if t == 5: r.take(10); return '<extended>'
    if t == 6: return texto(r.sstr())
    if t == 7: return r.sstr()
    if t == 8: return 'False'
    if t == 9: return 'True'
    if t == 10:
        n = r.i('I', 4); b = r.take(n); return f'{{binário {n} bytes}}'
    if t == 11:
        itens = []
        while True:
            s = r.sstr()
            if not s: break
            itens.append(s)
        return '[' + ', '.join(itens) + ']'
    if t in (12, 20):
        n = r.i('I', 4); return texto(r.take(n).decode('utf-8' if t == 20 else 'latin1', 'replace'))
    if t == 13: return 'nil'
    if t == 14:
        linhas = ['<']
        while r.d[r.p] != 0:
            if r.d[r.p] in (2, 3, 4): valor(r, ind)  # ordem do item
            r.byte()  # vaList
            props = []
            while True:
                nome = r.sstr()
                if not nome: break
                props.append(' ' * (ind + 4) + f'{nome} = {valor(r, ind + 4)}')
            linhas.append(' ' * (ind + 2) + 'item'); linhas += props; linhas.append(' ' * (ind + 2) + 'end')
        r.byte(); linhas.append(' ' * ind + '>')
        return '\n'.join(linhas)
    if t == 15: return f'{r.i("f", 4):g}'
    if t in (16, 17, 23): r.take(8); return '<número>'
    if t in (18, 21):
        n = r.i('I', 4); return texto(r.take(2 * n).decode('utf-16-le', 'replace'))
    if t in (19, 22): return str(r.i('q', 8))
    raise ValueError(f'tipo de valor desconhecido {t} em {r.p}')


def objeto(r, ind, linhas):
    flags = ''
    if r.d[r.p] & 0xF0 == 0xF0:
        f = r.byte()
        if f & 2: valor(r, ind)  # posição de herança
        flags = 'inherited ' if f & 1 else ''
    classe = r.sstr(); nome = r.sstr()
    linhas.append(' ' * ind + f'{flags or "object "}{nome}: {classe}')
    while True:
        prop = r.sstr()
        if not prop: break
        linhas.append(' ' * (ind + 2) + f'{prop} = {valor(r, ind + 2)}')
    while r.d[r.p] != 0:
        objeto(r, ind + 2, linhas)
    r.byte()
    linhas.append(' ' * ind + 'end')


pos, achados = 0, 0
while True:
    pos = d.find(b'TPF0', pos)
    if pos < 0: break
    try:
        r = Leitor(d, pos + 4)
        linhas = []
        objeto(r, 0, linhas)
        primeira = linhas[0].split()[1].rstrip(':')
        arq = os.path.join(saida, f'{primeira}.lfm')
        n = 2
        while os.path.exists(arq):
            arq = os.path.join(saida, f'{primeira}_{n}.lfm'); n += 1
        open(arq, 'w', encoding='utf-8').write('\n'.join(linhas) + '\n')
        componentes = sum(1 for l in linhas if l.strip().startswith(('object ', 'inherited ')))
        print(f'{os.path.basename(arq):40s} {componentes:4d} componentes  ({r.p - pos} bytes no executável)')
        achados += 1
        pos = r.p
    except Exception as e:
        pos += 4
print(f'{achados} formulários extraídos')
