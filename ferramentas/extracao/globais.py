"""Deduz as variáveis globais da unit jukelinux1 (símbolos U_JUKELINUX1_*) com um tipo Pascal provável, pelo tamanho
do símbolo no binário e pelo uso no C descompilado (legível), e grava src/globais.inc.

  tamanho 256 -> ShortString; 1 -> Boolean (ou Byte se aparece em conta); 8 -> TDateTime/TPoint pelo uso;
  4 -> AnsiString se passa por fpc_ansistr_* / concat / comparações de texto, senão LongInt;
  tamanho de TextRec (Text) -> Text; outros -> array de bytes (marcado para revisar).

Uso: python globais.py jukelinux pasta_c_legivel saida.inc
"""
import os
import re
import struct
import sys

D = open(sys.argv[1], 'rb').read()
shoff = struct.unpack_from('<I', D, 0x20)[0]
shentsize, shnum, _ = struct.unpack_from('<HHH', D, 0x2E)
secs = [struct.unpack_from('<IIIIIIIIII', D, shoff + i * shentsize) for i in range(shnum)]
symtab = next(s for s in secs if s[1] == 2)
strtab = secs[symtab[6]]
simbolos = {}
for i in range(symtab[5] // 16):
    st_name, st_value, st_size = struct.unpack_from('<III', D, symtab[4] + i * 16)
    o = strtab[4] + st_name
    nome = D[o:D.index(b'\0', o)].decode('latin1')
    if nome.startswith('U_JUKELINUX1_') and nome != 'U_JUKELINUX1_FORM1':
        simbolos[nome[len('U_JUKELINUX1_'):]] = (st_value, st_size)

indice = {}
for f in os.listdir(sys.argv[2]):
    texto = open(os.path.join(sys.argv[2], f), encoding='utf-8', errors='replace').read()
    for linha in re.sub(r'\n\s+', ' ', texto).split('\n'):  # junta as continuações de linha
        for n in set(re.findall(r'\bU_JUKELINUX1_(\w+)', linha)):
            indice.setdefault(n, []).append(linha)


def usos(n):
    # (&G)[i] e &G + k são acessos ao vetor seguinte na memória (o Ghidra não separa); não dizem o tipo de G.
    return [l for l in indice.get(n, []) if not re.search(r'\(&U_JUKELINUX1_' + n + r'\)\[|&U_JUKELINUX1_' + n + r' \+', l)]


# Tipos conferidos à mão no código descompilado (o tamanho do símbolo engana nesses).
MANUAL = {
    'NOMEMUSICAORIGINALGRANDE': 'AnsiString',  # usada como texto (lê o tamanho em -4); o símbolo tem 160 bytes
}


def tipo(n, tam):
    if n in MANUAL:
        return MANUAL[n]
    u = '\n'.join(usos(n))
    g = 'U_JUKELINUX1_' + n
    if tam == 256:
        return 'ShortString'
    if tam == 1:
        return 'Byte'  # a original grava 0/1 nelas, o que o Boolean do Pascal não aceita
    if tam == 4:
        if re.search(r'fpc_ansistr_\w+\(&?' + re.escape(g) + r'\b|fpc_ansistr_\w+\([^;]*,' + re.escape(g) + r'\b|'
                     # primeiro parâmetro texto (FILEEXISTS_ANSISTRING__...), não resultado (INTTOSTR_LONGINT__ANSISTRING)
                     + re.escape(g) + r' = "|(?<!_)_(ANSISTRING|SHORTSTRING)\w*\(' + re.escape(g) + r'\b|'
                     r'(?i:compare_equal)\w*\s?\([^;()]*' + re.escape(g) + r'\b', u):
            if not re.search(re.escape(g) + r' (<|>|<=|>=|[+-]) \d|' + re.escape(g) + r' == [1-9]', u):
                return 'AnsiString'
        if re.search(r'TPROCESS____\w+\(' + re.escape(g) + r'\b|' + re.escape(g) + r' = \(int \*\)[^;]*TPROCESS', u):
            return 'TProcess'
        return 'LongInt'
    if tam == 8:
        if '_0_4_' in u or '_4_4_' in u:
            return 'TPoint'
        if 'TDATETIME' in u:
            return 'TDateTime'
        return 'Int64'
    if tam in (592, 560, 588, 620, 624) or re.search(r'_TEXT\w*\(' + re.escape(g), u):
        return 'Text'
    if tam == 332:  # FileRec do FPC 2.6 i386
        return 'file'
    # String[N] curta: 1 byte de tamanho + N letras, usada com as rotinas de shortstring.
    if 2 <= tam < 256 and re.search(r'(?i:shortstr)\w*\(&?' + re.escape(g) + r'\b|' + re.escape(g) + r' = "|'
                                   r'(?i:shortstr)\w*\([^;]*,&?' + re.escape(g) + r'\b', u):
        return f'String[{tam - 1}]'
    return f'array[0..{tam - 1}] of Byte {{revisar}}'


linhas = ['{ Variáveis globais da unit jukelinux1 da original, com o tipo deduzido por ferramentas/extracao/globais.py',
          '  (tamanho do símbolo + uso no código descompilado). Os marcados {revisar} ainda não têm o tipo certo. }',
          'var']
for n in sorted(simbolos, key=lambda k: simbolos[k][0]):
    linhas.append(f'  {n}: {tipo(n, simbolos[n][1])};')
open(sys.argv[3], 'w', encoding='utf-8', newline='\n').write('\n'.join(linhas) + '\n')
print(len(simbolos), 'globais')
