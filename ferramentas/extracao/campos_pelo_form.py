"""Monta campos_form1.json sem o binário: deslocamento de cada componente publicado do TForm1.

A ordem é a de src/jukelinux1_form.inc (a mesma do .lfm). No binário de 19/01/2018 (LCL 1.2.4, i386)
o TForm ocupa 0x4ec bytes e cada componente é um ponteiro de 4. A âncora é Timerabertura em 0xbc4
(Self do TimeraberturaTimer). Todos os acessos FORM1/in_EAX do C descompilado caem nessa grade.

Uso: python campos_pelo_form.py src/jukelinux1_form.inc campos_form1.json
"""
import json
import re
import sys

BASE = 0x4EC
ANCORA = ('Timerabertura', 0xBC4)

campos_txt = re.findall(r'^\s+(\w+): T\w+;', open(sys.argv[1], encoding='utf-8').read(), re.M)
if not campos_txt:
    raise SystemExit('nenhum campo em ' + sys.argv[1])
idx = campos_txt.index(ANCORA[0])
if BASE + 4 * idx != ANCORA[1]:
    raise SystemExit(f'âncora furada: {ANCORA[0]} daria {hex(BASE + 4 * idx)}, esperado {hex(ANCORA[1])}')

campos = {hex(BASE + 4 * i): nome for i, nome in enumerate(campos_txt)}
json.dump(campos, open(sys.argv[2], 'w', encoding='utf-8'), indent=0)
print(len(campos), 'campos;', ANCORA[0], hex(ANCORA[1]))
