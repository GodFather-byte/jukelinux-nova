"""Gera src/jukelinux1_rotinas.inc com as 265 rotinas da original traduzidas por transpilar.py, prontas para compilar:

  - rotinas soltas (MOSTRA_CDS, TELA1...): cabeçalho Pascal tirado do nome completo do FPC (NOME$TIPO$TIPO$$RETORNO),
    declaradas antes com "forward" para a ordem não importar;
  - métodos do TForm1 (os eventos): mesma assinatura do jukelinux1_form.inc (gerar_unit.py), só os que existem
    no formulário;
  - variáveis locais declaradas com o tipo deduzido do uso (texto, Boolean ou LongInt).

Os eventos traduzidos aqui saem do jukelinux1_eventos.inc (gerar_unit.py lê a lista em rotinas_feitas.txt).
Rotinas que já foram reescritas à mão em src/jukelinux1.pas não são geradas.

Uso: python gerar_rotinas.py pasta_c_legivel funcoes.txt componentes.json globais.inc pasta_src
"""
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import transpilar  # noqa: E402
from gerar_unit import assinatura  # noqa: E402

pasta_c, funcoes_txt, comp_json, globais_inc, pasta_src = sys.argv[1:6]
transpilar.carregar_nomes(funcoes_txt)
dados = json.load(open(comp_json, encoding='utf-8'))
eventos = {}
for ev in dados['eventos']:
    eventos[ev['metodo'].upper()] = (ev['metodo'], assinatura(ev))
componentes = {c['nome'].upper() for c in dados['componentes']}

# Tipos das globais (para deduzir o tipo das locais e evitar nomes repetidos).
tipos_globais = {}
for l in open(globais_inc, encoding='utf-8'):
    m = re.match(r'\s+(\w+): (.+);', l)
    if m:
        tipos_globais[m.group(1).upper()] = m.group(2)

pas_manual = open(os.path.join(pasta_src, 'jukelinux1.pas'), encoding='utf-8').read()
feitos_mao = {m.upper() for m in re.findall(r'^(?:procedure|function) (?:TForm1\.)?(\w+)', pas_manual, re.M | re.I)}

TIPOS = {'ANSISTRING': 'AnsiString', 'LONGINT': 'LongInt', 'BOOLEAN': 'Boolean', 'SHORTSTRING': 'ShortString',
         'TOBJECT': 'TObject', 'WORD': 'Word', 'CHAR': 'Char', 'SMALLINT': 'SmallInt', 'INT64': 'Int64',
         'LONGWORD': 'LongWord', 'BYTE': 'Byte', 'DOUBLE': 'Double', 'EXTENDED': 'Extended', 'REAL': 'Real',
         'TDATETIME': 'TDateTime'}


def tipo_local(nome, linhas):
    """Texto, Boolean ou LongInt, pelo jeito como a local aparece no Pascal traduzido."""
    s = '\n'.join(l for l in linhas if re.search(r'\b' + nome + r'\b', l))
    if re.search(r'\b' + nome + r' := (Pos|Length|StrToInt|StrToIntDef|Random|Form1\.\w+\.Count)\b|\b' + nome +
                 r' (<|>|<=|>=) -?\d|\b' + nome + r' [+-] \d|\b' + nome + r' := ' + nome + r' [+-]', s):
        return 'LongInt'
    if re.search(r'\b' + nome + r" := (FileExists|DirectoryExists|Eof|DeleteFile|CreateDir|CopyFile)\b", s):
        return 'Boolean'
    textuais = r"'|IntToStr|Trim|Copy\(|ExtractFile|Caption|Items\[|TimeToStr|DateToStr|UpperCase|LowerCase"
    if re.search(r'\b' + nome + r' := [^;]*(' + textuais + ')', s) or \
       re.search(r'(Caption|AssignFile\(\w+|LoadFromFile\(|Read\(\w+|Gravalog\(|ShowMessage\(|FileExists\(|'
                 r'DirectoryExists\(|Pos\([^,]+)[^;]*\b' + nome + r'\b', s) or \
       re.search(r'\b' + nome + r" (=|<>) '", s):
        return 'AnsiString'
    for g, t in tipos_globais.items():
        if re.search(r'\b' + nome + r' := ' + g + r';', s, re.I) or re.search(r'\b' + g + r' := ' + nome + r';', s, re.I):
            if t in ('AnsiString', 'ShortString', 'Boolean'):
                return t
    if nome.startswith('cVar'):
        return 'Boolean'
    return 'LongInt'


ARQ = r'(AssignFile|Rewrite|Reset|Append|Flush|CloseFile|Readln|Writeln|Read|Write|Eof)\('
retornos = {}  # nome da rotina (minúsculo) -> tipo do resultado, preenchido antes de traduzir


def tipos_locais(locs, linhas):
    """Tipo de cada local: heurística por linha e depois propagação pelas atribuições (a := b, a := F(...))."""
    tipos = {}
    for l in locs:
        s = '\n'.join(x for x in linhas if re.search(r'\b' + l + r'\b', x) and not x.lstrip().startswith('//'))
        tipos[l] = 'Text' if re.search(ARQ + l + r'\b', s) else tipo_local(l, linhas)
    conhecido = dict(tipos_globais)
    conhecido.update({k.upper(): v for k, v in retornos.items()})
    conhecido.update({'SENDER': 'TObject', 'SELF': 'TForm1'})
    passa = ('AnsiString', 'ShortString', 'TObject', 'TForm1')
    mudou = True
    while mudou:
        mudou = False
        for x in linhas:
            if x.lstrip().startswith('//'):
                continue
            m = re.match(r'\s*(\w+) := (\w+)(\(.*\))?;$', x)
            if not m:
                continue
            a, b = m.group(1), m.group(2)
            tb = tipos.get(b) or conhecido.get(b.upper())
            ta = tipos.get(a) or conhecido.get(a.upper())
            if a in tipos and tb in passa and tipos[a] == 'LongInt':
                tipos[a] = 'AnsiString' if tb == 'ShortString' else tb; mudou = True
            if b in tipos and not m.group(3) and ta in passa and tipos[b] == 'LongInt':
                tipos[b] = 'AnsiString' if ta == 'ShortString' else ta; mudou = True
    return tipos


PALAVRAS = set('''and array begin case const div do downto else end file for function goto if in label mod nil not of or
packed procedure program record repeat set then to type until var while with shl shr xor exit break continue result
true false self form1 sender key shift button x y closeaction node alnone altop albottom alleft alright alclient
'''.split())
RTL_NOMES = {n.lower() for n, _ in transpilar.RTL.values()} | {
    'read', 'write', 'writeln', 'readln', 'copy', 'length', 'inttostr', 'chr', 'ord', 'screen', 'mouse', 'application',
    'assignfile', 'closefile', 'reset', 'rewrite', 'append', 'flush', 'eof'}


def higienizar(linhas, conhecidos):
    """Comenta as linhas com algum nome que não existe no Pascal (sobra do C que o tradutor deixou passar)."""
    saida = []
    for l in linhas:
        cod = l.split('//', 1)[0]
        m_at = re.match(r'\s*(.+?) := ', cod)
        if m_at and not re.fullmatch(r'[A-Za-z_][\w.]*(\[[^\]]+\])?', m_at.group(1).strip()):
            saida.append(l[:len(l) - len(l.lstrip())] + '// ?: ' + l.strip())
            continue
        cod_sem_txt = re.sub(r"'(?:[^']|'')*'|\{[^}]*\}|#\d+", ' ', cod)
        nomes = re.findall(r'(?<![.\w#$])([A-Za-z_]\w*)', cod_sem_txt)
        ruins = [n for n in nomes if n.lower() not in conhecidos and not n.startswith('LAB_')]
        if not ruins:
            saida.append(l)
            continue
        ind = l[:len(l) - len(l.lstrip())]
        s = l.strip()
        m = re.fullmatch(r'(else )?(if|while) (.+) (then|do) begin', s)
        if m:
            saida.append(f'{ind}{m.group(1) or ""}{m.group(2)} False {m.group(4)} begin // ?: {m.group(3)}')
        elif s.startswith('until '):
            saida.append(f'{ind}until True; // ?: {s}')
        else:
            saida.append(f'{ind}// ?: {s}')
    return saida


def parse_nome(simbolo):
    """JUKELINUX1_MENSAGEMJPG$ANSISTRING$LONGINT$ANSISTRING -> ('MENSAGEMJPG', [tipos], retorno)"""
    s = simbolo[len('JUKELINUX1_'):]
    ret = None
    if '$$' in s:
        s, ret = s.split('$$')
    partes = s.split('$')
    return partes[0], partes[1:], ret


for arq in os.listdir(pasta_c):  # tipos de retorno de todas as rotinas, para deduzir o tipo das locais
    if arq.endswith('.c') and not arq.startswith('JUKELINUX1_TFORM1'):
        simb = open(os.path.join(pasta_c, arq), encoding='utf-8').readline()[3:].split('  @')[0].strip()
        if '$$' in simb:
            n, _, r = parse_nome(simb)
            retornos[n.title().lower()] = TIPOS.get(r, r)

rotinas, metodos, forwards, feitos_eventos = [], [], [], []
for arq in sorted(os.listdir(pasta_c)):
    if not arq.endswith('.c') or arq.startswith(('JUKELINUX1_init', 'JUKELINUX1_finalize')):
        continue
    src = open(os.path.join(pasta_c, arq), encoding='utf-8').read()
    simbolo = src.split('\n', 1)[0][3:].split('  @')[0].strip()
    metodo = simbolo.startswith('JUKELINUX1_TFORM1_$__')
    if metodo:
        nome_ev = simbolo[len('JUKELINUX1_TFORM1_$__'):].split('$')[0]
        if nome_ev not in eventos or nome_ev in feitos_mao:
            continue
        nome, sig = eventos[nome_ev]
        # param_1 = Self; os demais seguem a assinatura do evento.
        params = re.findall(r'(?:var )?(\w+(?:, \w+)*): \w+', sig)
        nomes_p = [p for grupo in params for p in grupo.split(', ')]
        src = re.sub(r'\bparam_1\b', 'Self', src)
        for i, p in enumerate(nomes_p, start=2):
            src = re.sub(r'\bparam_' + str(i) + r'\b', p, src)
        cab = f'procedure TForm1.{nome}{sig};'
        alvo = metodos
        feitos_eventos.append(nome)
    else:
        n, tipos_p, ret = parse_nome(simbolo)
        if n in feitos_mao:
            continue
        nome = n.title()
        tps = [TIPOS.get(t, t) for t in tipos_p]
        args = '; '.join(f'P{i + 1}: {t}' for i, t in enumerate(tps))
        args = f'({args})' if args else ''
        for i in range(len(tps)):
            src = re.sub(r'\bparam_' + str(i + 1) + r'\b', f'P{i + 1}', src)
        if ret:
            tr = TIPOS.get(ret, ret)
            if tr in ('AnsiString', 'ShortString'):  # resultado de texto vem pelo último parâmetro (ponteiro)
                k = len(tps) + 1
                src = re.sub(r'\*param_' + str(k) + r'\b', 'Result', src)
                src = re.sub(r'\bparam_' + str(k) + r'\b', 'Result', src)
            cab = f'function {nome}{args}: {tr};'
        else:
            cab = f'procedure {nome}{args};'
        forwards.append(cab + ' forward;')
        alvo = rotinas
    corpo, locs, _ = transpilar.traduzir(src)
    locs = [l for l in locs if l not in ('Self', 'Result')]
    params_nomes = nomes_p if metodo else [f'P{i + 1}' for i in range(len(tps))]
    conhecidos = (PALAVRAS | RTL_NOMES | {g.lower() for g in tipos_globais} | {c.lower() for c in componentes} |
                  {n.title().lower() for n in transpilar.nomes_juke} | {l.lower() for l in locs} |
                  {p.lower() for p in params_nomes})
    corpo = higienizar(corpo, conhecidos)
    saldo = 0
    for l in corpo:
        c = re.sub(r"'(?:[^']|'')*'|\{[^}]*\}", '', l.split('//', 1)[0])
        saldo += len(re.findall(r'\b(begin|repeat)\b', c, re.I)) - len(re.findall(r'\b(end|until)\b', c, re.I))
    if saldo != 0:
        print(f'AVISO: {simbolo} com begin/end desbalanceado ({saldo:+d}); corpo comentado', file=sys.stderr)
        corpo = ['  // DESBALANCEADO: ' + l.strip() for l in corpo]
    decl = ''
    if locs:
        tipos = tipos_locais(locs, corpo)
        # No C, zerar um texto é pôr nil: "s := 0" vira "s := ''".
        textos_l = {l for l, t in tipos.items() if t in ('AnsiString', 'ShortString')}
        corpo = [re.sub(r'^(\s*)(\w+) := 0;$', lambda m: f"{m.group(1)}{m.group(2)} := '';"
                        if m.group(2) in textos_l else m.group(0), x) for x in corpo]
        por_tipo = {}
        for l, t in tipos.items():
            por_tipo.setdefault(t, []).append(l)
        decl = 'var\n' + ''.join(f'  {", ".join(v)}: {t};\n' for t, v in sorted(por_tipo.items()))
    if transpilar.rotulos:
        decl = 'label\n  ' + ', '.join(sorted(transpilar.rotulos)) + ';\n' + decl
    alvo.append(f'{{ {simbolo} }}\n{cab}\n{decl}begin\n' + '\n'.join(corpo) + '\nend;\n')

with open(os.path.join(pasta_src, 'jukelinux1_rotinas.inc'), 'w', encoding='utf-8', newline='\n') as f:
    f.write('{ Rotinas da JukeLinux original traduzidas do código descompilado por ferramentas/extracao/gerar_rotinas.py.\n'
            '  Linhas "// C:" são comandos que o tradutor não reconheceu e ainda precisam ser escritos à mão.\n'
            '  Ao reescrever uma rotina à mão em jukelinux1.pas, gere de novo: ela sai daqui. }\n\n')
    f.write('\n'.join(forwards) + '\n\n')
    f.write('\n'.join(rotinas) + '\n')
    f.write('\n'.join(metodos))
open(os.path.join(pasta_src, 'rotinas_feitas.txt'), 'w', encoding='utf-8', newline='\n').write('\n'.join(feitos_eventos) + '\n')
pend = sum(x.count('// C:') + x.count('{ C:') for x in rotinas + metodos)
print(f'{len(rotinas)} rotinas, {len(metodos)} métodos, {pend} comandos pendentes')
