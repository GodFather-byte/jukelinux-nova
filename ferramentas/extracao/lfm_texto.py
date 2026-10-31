"""Converte o formulário binário (TPF0) remontado por form1_ordem.py em .lfm de texto no formato do Lazarus,
com as imagens embutidas inteiras (Picture.Data em hexadecimal), e gera a lista de componentes e eventos.

Uso: python lfm_texto.py form1_exato.bin saida.lfm componentes.json
"""
import json
import struct
import sys

entrada, saida_lfm, saida_json = sys.argv[1], sys.argv[2], sys.argv[3]
D = open(entrada, 'rb').read()
p = 4  # pula 'TPF0'


def b():
    global p
    v = D[p]; p += 1; return v


def take(n):
    global p
    v = D[p:p + n]; p += n; return v


def num(fmt, n):
    global p
    v = struct.unpack_from('<' + fmt, D, p)[0]; p += n; return v


def sstr():
    return take(b()).decode('latin1')


def texto_lfm(s):
    """String no formato do Lazarus: trechos 'ascii' e #nnn para o resto (UTF-8 já decodificado em code points)."""
    if s == '':
        return "''"
    out, cur = [], ''
    for c in s:
        if 32 <= ord(c) < 127 and c != "'":
            cur += c
        else:
            if cur: out.append(f"'{cur}'"); cur = ''
            out.append("''''" if c == "'" else f"#{ord(c)}")
    if cur: out.append(f"'{cur}'")
    return ''.join(out).replace("'''''", "''")


def utf8(raw):
    try:
        return raw.decode('utf-8')
    except UnicodeDecodeError:
        return raw.decode('latin1')


def extended(raw):
    mant, = struct.unpack('<Q', raw[:8]); se, = struct.unpack('<H', raw[8:])
    sinal = -1 if se & 0x8000 else 1; exp = se & 0x7FFF
    if exp == 0 and mant == 0: return '0'
    v = sinal * mant / (1 << 63) * 2.0 ** (exp - 16383)
    return repr(v)


def hexblock(raw, ind):
    h = raw.hex().upper()
    linhas = [h[i:i + 64] for i in range(0, len(h), 64)]
    pad = ' ' * (ind + 2)
    return '{\n' + '\n'.join(pad + l for l in linhas) + '\n' + pad + '}'


def valor(ind, prop=''):
    t = b()
    if t == 0: return 'nil'
    if t == 1:
        it = []
        while D[p] != 0: it.append(valor(ind + 2))
        b(); return '(\n' + '\n'.join(' ' * (ind + 2) + x for x in it) + ')' if it else '()'
    if t == 2: return str(num('b', 1))
    if t == 3: return str(num('h', 2))
    if t == 4: return str(num('i', 4))
    if t == 5: return extended(take(10))
    if t == 6: return texto_lfm(utf8(take(b())))
    if t == 7: return sstr()
    if t == 8: return 'False'
    if t == 9: return 'True'
    if t == 10: n = num('I', 4); return hexblock(take(n), ind)
    if t == 11:
        it = []
        while True:
            s = sstr()
            if not s: break
            it.append(s)
        return '[' + ', '.join(it) + ']'
    if t == 12: n = num('I', 4); return texto_lfm(utf8(take(n)))
    if t == 13: return 'nil'
    if t == 14:
        linhas = ['<']
        while D[p] != 0:
            if D[p] in (2, 3, 4): valor(ind)
            b()
            linhas.append(' ' * (ind + 2) + 'item')
            while True:
                nm = sstr()
                if not nm: break
                linhas.append(' ' * (ind + 4) + f'{nm} = {valor(ind + 4, nm)}')
            linhas.append(' ' * (ind + 2) + 'end')
        b(); linhas[-1] += '>'
        return '\n'.join(linhas)
    if t == 15: return repr(num('f', 4))
    if t == 16: return str(num('q', 8) / 10000)
    if t == 17: return repr(num('d', 8))
    if t in (18, 21): n = num('I', 4); return texto_lfm(take(2 * n).decode('utf-16-le'))
    if t == 19: return str(num('q', 8))
    if t == 20: n = num('I', 4); return texto_lfm(utf8(take(n)))
    if t == 22: return str(num('Q', 8))
    if t == 23: return repr(num('d', 8))
    raise ValueError(f'tipo {t} em {p}')


componentes, eventos = [], []


def objeto(ind, out, pai):
    if D[p] & 0xF0 == 0xF0:
        f = b()
        if f & 2: valor(ind)
    classe = sstr(); nome = sstr()
    out.append(' ' * ind + f'object {nome}: {classe}')
    componentes.append({'nome': nome, 'classe': classe, 'pai': pai})
    while True:
        pr = sstr()
        if not pr: break
        v = valor(ind + 2, pr)
        out.append(' ' * (ind + 2) + f'{pr} = {v}')
        if pr.startswith('On') and '.' not in pr:
            eventos.append({'componente': nome, 'classe': classe, 'evento': pr, 'metodo': v})
    while D[p] != 0:
        objeto(ind + 2, out, nome)
    b()
    out.append(' ' * ind + 'end')


out = []
objeto(0, out, None)
open(saida_lfm, 'w', encoding='utf-8', newline='\n').write('\n'.join(out) + '\n')
json.dump({'componentes': componentes, 'eventos': eventos}, open(saida_json, 'w', encoding='utf-8'),
          ensure_ascii=False, indent=1)
print(f'{len(componentes)} componentes, {len(eventos)} eventos, lido {p} de {len(D)} bytes')
