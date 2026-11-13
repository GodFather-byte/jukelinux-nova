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


ARQ = r'(AssignFile|Rewrite|Reset|Append|Flush|CloseFile|Readln|Writeln|Read|Write|Eof)\('
retornos = {}  # nome da rotina (minúsculo) -> tipo do resultado, preenchido antes de traduzir
params_rotina = {  # nome da rotina (minúsculo) -> tipos dos parâmetros; as do FPC vêm prontas
    'copyfile': ['AnsiString', 'AnsiString', 'Boolean'], 'fileexists': ['AnsiString'],
    'directoryexists': ['AnsiString'], 'deletefile': ['AnsiString'], 'createdir': ['AnsiString'],
    'removedir': ['AnsiString'], 'renamefile': ['AnsiString', 'AnsiString'], 'pos': ['AnsiString', 'AnsiString'],
    'copy': ['AnsiString', 'LongInt', 'LongInt'], 'strtoint': ['AnsiString'],
    'strtointdef': ['AnsiString', 'LongInt'], 'showmessage': ['AnsiString'], 'inttostr': ['LongInt'],
    'trim': ['AnsiString'], 'uppercase': ['AnsiString'], 'lowercase': ['AnsiString'],
    'extractfileext': ['AnsiString'], 'extractfilename': ['AnsiString'], 'extractfilepath': ['AnsiString'],
}
STR_FUNCS = r'IntToStr|Trim|Copy|ExtractFileExt|ExtractFileName|ExtractFilePath|DateToStr|TimeToStr|UpperCase|LowerCase'
INT_FUNCS = r'Pos|Length|StrToInt|StrToIntDef|Random'
BOOL_FUNCS = r'FileExists|DirectoryExists|Eof|DeleteFile|CreateDir|CopyFile|RemoveDir|RenameFile'


def evidencias(n, s, funcs_texto):
    """(número, texto, Boolean) — se o código usa a local n como número, como texto ou como Boolean."""
    N = r'\b' + n + r'\b'
    K = r'(?<![\w.$#])-?\d+(?![\w.])'  # número de verdade, não o fim de um nome como local_68
    num = re.search(N + r' [+\-*] ' + K + r'|' + K + r' [+\-*] ' + N + r'|' + N +
                    r' (<|>|<=|>=) ' + K + r'|' + K + r' (<|>|<=|>=) ' + N + r'|' + N + r' := -?[1-9]\d*;|' + N + r' := (' +
                    INT_FUNCS + r')\(|' + N + r' := Form1\.\w+\.(Count|ItemIndex);|IntToStr\(' + n + r'\)|Items\[' +
                    n + r'\]|' + N + r' (div|mod) |Copy\([^,]+, ' + n + r'\b', s)
    txt = re.search(N + r" := '|" + N + r" \+ '|' \+ " + n + r'\b|' + N + r' := (' + STR_FUNCS + funcs_texto +
                    r')\(|' + N + r' := [\w.]+\.(Caption|Items\[)|Caption := ' + n + r';|(Gravalog|ShowMessage|' +
                    BOOL_FUNCS + r'|LoadFromFile|AssignFile\(\w+,|Read\(\w+,|Pos\([^,]+,)\s*\(?' + n + r'\)|Pos\(' + n +
                    r',|' + N + r" (=|<>) '|'\s*(=|<>) " + N + r'|Length\(' + n + r'\)|Ord\(' + n + r'\[|Copy\(' + n + r',', s)
    boo = re.search(N + r' := (' + BOOL_FUNCS + r')\(', s)
    return bool(num), bool(txt), bool(boo)


def tipos_locais(locs, linhas, tipos_params=None, tipo_result=None):
    """Tipo de cada local pelas evidências de uso; sem evidência, pela propagação (a := b, a = b).
    Local usada como número e como texto (o compilador original reaproveita o mesmo espaço da pilha) vira Variant."""
    codigo = [x for x in linhas if not x.lstrip().startswith('//')]
    funcs_texto = ''.join('|' + k.title() for k, v in retornos.items() if v in ('AnsiString', 'ShortString'))
    tipos, certo = {}, set()
    for l in locs:
        s = '\n'.join(x for x in codigo if re.search(r'\b' + l + r'\b', x))
        if re.search(ARQ + l + r'\b', s):
            tipos[l] = 'Text'; certo.add(l); continue
        num, txt, boo = evidencias(l, s, funcs_texto)
        txt = txt or l in transpilar.texto_certo
        for mc in re.finditer(r'\b(\w+)\(([^()]*)\)', s):  # passada a parâmetro de texto de uma rotina
            tps_r = params_rotina.get(mc.group(1).lower())
            if tps_r:
                for a, tp in zip(transpilar.args_de(mc.group(2)), tps_r):
                    if a == l and tp == 'AnsiString':
                        txt = True
                    elif a == l and tp == 'LongInt':
                        num = True
        if num and txt:
            tipos[l] = 'Variant'
        elif txt:
            tipos[l] = 'AnsiString'
        elif num:
            tipos[l] = 'LongInt'
        elif boo or l.startswith('cVar'):
            tipos[l] = 'Boolean'
        else:
            tipos[l] = None
            continue
        certo.add(l)
    conhecido = dict(tipos_globais)
    conhecido.update({k.upper(): v for k, v in retornos.items()})
    conhecido.update({'SENDER': 'TObject', 'SELF': 'TForm1', 'RESULT': tipo_result})
    conhecido.update({k.upper(): v for k, v in (tipos_params or {}).items()})
    mudou = True
    while mudou:
        mudou = False
        for x in codigo:
            for m in re.finditer(r'\b(\w+) (:=|=|<>) (\w+)\b(?!\()', x):
                a, b = m.group(1), m.group(3)
                for p, q in ((a, b), (b, a)):
                    if p in tipos and p not in certo and tipos[p] is None:
                        tq = tipos.get(q) or conhecido.get(q.upper())
                        if tq:
                            tipos[p] = {'ShortString': 'AnsiString', 'Byte': 'LongInt'}.get(tq, tq)
                            if tipos[p].startswith('String['):
                                tipos[p] = 'AnsiString'
                            mudou = True
    return {l: (t or 'LongInt') for l, t in tipos.items()}


PALAVRAS = set('''and array begin case const div do downto else end file for function goto if in label mod nil not of or
packed procedure program record repeat set then to type until var while with shl shr xor exit break continue result
true false self form1 sender key shift button x y closeaction node alnone altop albottom alleft alright alclient
'''.split())
RTL_NOMES = {n.lower() for n, _ in transpilar.RTL.values()} | {
    'read', 'write', 'writeln', 'readln', 'copy', 'length', 'inttostr', 'chr', 'ord', 'screen', 'mouse', 'application',
    'assignfile', 'closefile', 'reset', 'rewrite', 'append', 'flush', 'eof', 'tprocess', 'tstringlist', 'ord', 'serial_da_chave_no_hd',
    'bsnone', 'bssingle', 'bssizeable', 'bsdialog', 'bstoolwindow', 'bssizetoolwin', 'alcustom'}


def higienizar(linhas, conhecidos):
    """Comenta as linhas com algum nome que não existe no Pascal (sobra do C que o tradutor deixou passar)."""
    saida = []
    for l in linhas:
        # "(*" e "*)" abrem e fecham comentário no Pascal, mesmo vindos do C dentro de um comentário.
        if '//' in l or '{' in l:
            l = l.replace('(*', '( *').replace('*)', '* )')
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
        n, tps0, r = parse_nome(simb)
        params_rotina[n.title().lower()] = [TIPOS.get(x, x) for x in tps0]
        if r:
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
        # Parâmetros var (Key, CloseAction) chegam como ponteiro no C: *Key é o próprio Key no Pascal.
        for p in re.findall(r'var (\w+):', sig):
            src = re.sub(r'\*' + p + r'\b', p, src)
        cab = f'procedure TForm1.{nome}{sig};'
        alvo = metodos
        feitos_eventos.append(nome)
        tipos_params = {}
        for grupo, tp in re.findall(r'(?:var )?(\w+(?:, \w+)*): (\w+)', sig):
            for p in grupo.split(', '):
                tipos_params[p] = tp
        tipo_result = None
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
                # o resultado é gravado por um ponteiro: local_c = Result; p = local_c; *p = valor
                mr = re.search(r'^\s*(local_\w+) = Result;', src, re.M)
                if mr:
                    for pv in [mr.group(1)] + re.findall(r'(\w+) = ' + mr.group(1) + r';', src):
                        src = re.sub(r'\*' + pv + r'\b', 'Result', src)
            cab = f'function {nome}{args}: {tr};'
        else:
            cab = f'procedure {nome}{args};'
        forwards.append(cab + ' forward;')
        alvo = rotinas
        tipos_params = {f'P{i + 1}': t for i, t in enumerate(tps)}
        tipo_result = TIPOS.get(ret, ret) if ret else None
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
        saldo += len(re.findall(r'\b(begin|repeat)\b|^\s*case\b.*\bof$', c, re.I)) - \
            len(re.findall(r'\b(end|until)\b', c, re.I))
    if saldo != 0:
        print(f'AVISO: {simbolo} com begin/end desbalanceado ({saldo:+d}); corpo comentado', file=sys.stderr)
        corpo = ['  // DESBALANCEADO: ' + l.strip() for l in corpo]
    decl = ''
    tipos = tipos_locais(locs, corpo, tipos_params, tipo_result) if locs else {}
    # Ajustes que dependem dos tipos (C não distingue nil, 0, falso e '\0'):
    textos_l = {l.upper() for l, t in tipos.items() if t in ('AnsiString', 'ShortString')}
    textos_l |= {g for g, t in tipos_globais.items() if t in ('AnsiString', 'ShortString') or t.startswith('String[')}
    textos_l |= {p.upper() for p, t in tipos_params.items() if t == 'AnsiString'}
    if tipo_result == 'AnsiString':
        textos_l.add('RESULT')
    boole = {l for l, t in tipos.items() if t == 'Boolean'}
    bytes_g = {g for g, t in tipos_globais.items() if t == 'Byte'}
    chars = {p for p, t in tipos_params.items() if t == 'Char'}
    curtas = {g for g, t in tipos_globais.items() if t == 'ShortString' or t.startswith('String[')}

    def ajusta(x):
        if x.lstrip().startswith('//'):
            return x
        x = re.sub(r'\b(\w+) = 0\b', lambda m: f'not {m.group(1)}' if m.group(1) in boole else m.group(0), x)
        x = re.sub(r'\b(\w+) <> 0\b', lambda m: m.group(1) if m.group(1) in boole else m.group(0), x)
        # texto comparado com 0 é ponteiro nil: s <> 0 -> s <> ''; e "s := 0" zera o texto
        x = re.sub(r'\b(\w+) (=|<>) 0\b', lambda m: f"{m.group(1)} {m.group(2)} ''"
                   if m.group(1).upper() in textos_l else m.group(0), x)
        x = re.sub(r'^(\s*)(\w+) := 0;$', lambda m: f"{m.group(1)}{m.group(2)} := '';"
                   if m.group(2).upper() in textos_l else m.group(0), x)
        # ShortString comparada com um caractere: no C é o byte 0, o tamanho. G = #8 -> Length(G) = 8
        x = re.sub(r'\b(\w+) (=|<>) #?(\d+)\b', lambda m: f'Length({m.group(1)}) {m.group(2)} {m.group(3)}'
                   if m.group(1).upper() in curtas else m.group(0), x)
        # Char comparado com número: Key = 13 -> Key = #13
        x = re.sub(r'\b(\w+) (=|<>) (\d+)\b', lambda m: f'{m.group(1)} {m.group(2)} #{m.group(3)}'
                   if m.group(1) in chars else m.group(0), x)
        # Byte da original recebendo comparação: b := a = 0 -> b := Ord(a = 0)
        m = re.match(r'^(\s*)(\w+) := (.*(=|<>|<|>).*);$', x)
        if m and m.group(2).upper() in bytes_g:
            x = f'{m.group(1)}{m.group(2)} := Ord({m.group(3)});'
        # função Boolean devolvendo número
        m = re.match(r'^(\s*)Result := (\w+); Exit;$', x)
        if m and tipo_result == 'Boolean' and tipos.get(m.group(2)) == 'LongInt':
            x = f'{m.group(1)}Result := {m.group(2)} <> 0; Exit;'
        return x

    corpo = [ajusta(x) for x in corpo]
    if tipos:
        por_tipo = {}
        for l, t in tipos.items():
            por_tipo.setdefault(t, []).append(l)
        decl = 'var\n' + ''.join(f'  {", ".join(v)}: {t};\n' for t, v in sorted(por_tipo.items()))
    if transpilar.rotulos:
        decl = 'label\n  ' + ', '.join(sorted(transpilar.rotulos)) + ';\n' + decl
    alvo.append(f'{{ {simbolo} }}\n{cab}\n{decl}begin\n' + '\n'.join(corpo) + '\nend;\n')

# No C, 0 passado onde a rotina espera texto é o texto vazio (nil): Mensagemjpg('x', 0, 0) -> Mensagemjpg('x', 0, '').
assinaturas = {}
for fw in forwards:
    m = re.match(r'(?:procedure|function) (\w+)(?:\((.*?)\))?', fw)
    assinaturas[m.group(1).lower()] = [p.split(': ')[1] for p in m.group(2).split('; ')] if m.group(2) else []


def arruma_args(linha):
    def troca(m):
        tipos = assinaturas.get(m.group(1).lower())
        if not tipos:
            return m.group(0)
        args = transpilar.args_de(m.group(2))
        if len(args) != len(tipos):
            return m.group(0)
        args = ["''" if a == '0' and t == 'AnsiString' else a for a, t in zip(args, tipos)]
        return f'{m.group(1)}({", ".join(args)})'
    return re.sub(r'\b(\w+)\(([^()]*)\)', troca, linha)


rotinas = ['\n'.join(arruma_args(x) for x in r.split('\n')) for r in rotinas]
from correcoes import CORRECOES  # noqa: E402
metodos = ['\n'.join(arruma_args(x) for x in r.split('\n')) for r in metodos]

for rot, velho, novo, _motivo in CORRECOES:
    lista = metodos if rot.startswith('TForm1.') else rotinas
    alvo_i = [i for i, x in enumerate(lista) if re.search(r'^(procedure|function) ' + re.escape(rot) + r'\b', x, re.M)]
    if len(alvo_i) != 1 or lista[alvo_i[0]].count(velho) != 1:
        raise SystemExit(f'correção não se aplica em {rot}: {velho!r}')
    lista[alvo_i[0]] = lista[alvo_i[0]].replace(velho, novo)

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
