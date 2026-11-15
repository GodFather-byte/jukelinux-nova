"""Completa o Pascal gerado por gerar_rotinas.py: converte o que o tradutor deixou como
`if False { C: ... } then` e como linhas `// C: ...`, quando dá para fazer isso com segurança.

Converte:
- condições: comparações (==, !=, <, ...), &&, ||, !, aritmética, STREQ/STRNE (texto), teclas (*local_c, que no
  Pascal já é o valor de Key), '\\0' e ponteiro nulo comparados com variável de tipo conhecido;
- comandos: chamadas do player (MPLAYERCTRL_...: Play, Stop, SetFileName, SetVolume, Playing, Running),
  atribuições simples (variável = expressão), funções da RTL e da LCL mais usadas (texto dos componentes,
  concatenação, conversões de string, FileExists, IntToStr, LoadFromFile...) e os métodos virtuais conferidos
  (Items[i], Items.Count, Items.Add, Items.Clear dos TStrings e Interval dos TTimer);
- acessos ao acervo de CDs (MAT, registro TIPOCD de globais.inc), nas várias formas em que o Ghidra os escreve;
- as condições que o tradutor marcou como incertas (`if False then begin // ?: ...`).

Regra de ouro: só converte se todos os nomes existirem (global em globais.inc, local ou parâmetro da rotina) com
tipo conhecido. Na dúvida, a linha fica como estava. O compilador confere o resto.

A linha convertida guarda o C original: `if (...) { C convertido: ... } then` e `comando;  // C convertido: ...`.
Assim rodar de novo não converte duas vezes, e a contagem de pendências (`// C:` no começo da linha e `{ C:`) só
conta o que falta.

gerar_rotinas.py chama completa_rotina() no fim. Também roda sozinho sobre o arquivo já gerado:
    python completar.py src/globais.inc src/jukelinux1_rotinas.inc
"""

import re
import sys

NUMERICOS = {'byte', 'longint', 'integer', 'word', 'cardinal', 'shortint', 'smallint', 'longword', 'int64',
             'dword', 'qword'}
TEXTO = {'ansistring', 'string', 'shortstring'}


def tipo_base(t):
    t = t.strip().lower()
    if t.startswith('array') or '{revisar}' in t:
        return None
    t = re.sub(r'\s*\{.*\}', '', t)
    if t in NUMERICOS:
        return 'num'
    if t in TEXTO or t.startswith('string['):
        return 'texto'
    if t == 'boolean':
        return 'bool'
    if t == 'char':
        return 'char'
    if t == 'tipocd':
        return 'registro'
    if t == 'text':
        return 'arquivo'
    return None


def le_globais(caminho):
    globais = {}
    for linha in open(caminho, encoding='utf-8'):
        m = re.match(r'\s{2}(\w+): (.+);', linha)
        if m:
            globais[m.group(1).upper()] = tipo_base(m.group(2))
    return globais


def le_locais(texto):
    """Locais (seção var) e parâmetros da rotina, com o tipo de cada um."""
    locais = {}
    cab = texto.split('\n', 1)[0]
    m = re.search(r'\((.*)\)', cab)
    if m:
        for grupo in m.group(1).split(';'):
            grupo = re.sub(r'^\s*(var|const|out)\s+', '', grupo)
            if ':' in grupo:
                nomes, t = grupo.rsplit(':', 1)
                for n in nomes.split(','):
                    locais[n.strip().upper()] = tipo_base(t)
    corpo_var = re.search(r'\nvar\n(.*?)\nbegin\n', texto, re.S)
    if corpo_var:
        for linha in corpo_var.group(1).split('\n'):
            m = re.match(r'\s+([\w, ]+): (.+);', linha)
            if m:
                for n in m.group(1).split(','):
                    locais[n.strip().upper()] = tipo_base(m.group(2))
    return locais


class Falha(Exception):
    pass


# --- Acervo de CDs: MAT[1..8000] of TIPOCD (ver globais.inc) -------------------------------------------------------
# Na original o CD i fica em ARQLOG+0x1f0+i*576 (MAT começa em ARQLOG+0x430). O Ghidra escreve o endereço de um campo
# como ARQLOG + i*0x240 + c, como o endereço absoluto 0x8e91110 + desl + i*0x240, ou a partir de uma global que por acaso
# está naquele endereço, (&G)[i*0x90] (0x90 elementos de 4 bytes = 576). As posições dessas globais vêm da ordem e do
# tamanho em globais.inc; conferidas porque cada uma cai exatamente no começo de um campo ou de uma música.
BASE_ABS_CD = 0x8e91110
BASE_ARQLOG_CD = 0x1f0
GLOBAL_NO_CD = {  # global -> deslocamento dentro do registro
    'PASTACHAVE9': 212, 'PASTACHAVE8': 216, 'PASTACHAVE7': 220, 'PASTACHAVE6': 224, 'PASTACHAVE5': 228,
    'PASTACHAVE4': 232, 'PASTACHAVE3': 236, 'PASTACHAVE2': 240, 'PASTACHAVE1': 244, 'ULTIMOFECHA': 248,
    'ERROSERIAL': 252, 'ERROSERIALNUM': 256, 'LETRASEXE': 260, 'JC_SERIALPENDRIVECON': 264,
    'NOMEDOCLIENTE': 376, 'SERIAL': 380, 'TECLAMUSICAMAIS': 384, 'TECLACDMENOS': 392,
    'ENDERECOSTR': 556, 'BAIRROSTR': 560, 'SELOSSTR': 572,
}
CAMPOS_CD = {0: ('Marca', 'num'), 8: ('Pasta', 'texto'), 12: ('Nome', 'texto'), 16: ('Capa', 'texto'),
             20: ('CapaPequena', 'texto'), 24: ('Genero', 'texto'), 376: ('TotalMusicas', 'num'),
             380: ('Tipo', 'texto'), 384: ('Marca2', 'num'), 556: ('Marca3', 'num'), 558: ('Escolha', 'texto'),
             560: ('Marca4', 'num'), 572: ('TotalTocadas', 'num')}
# vetores [1..40]: deslocamento do elemento k = base + 4*k
VETORES_CD = {52: ('Caminho', 'texto'), 212: ('Musica', 'texto'), 392: ('Tocadas', 'num')}


def campo_cd(desl):
    """Campo (ou elemento fixo de vetor) no deslocamento desl do registro TIPOCD: (texto pascal, tipo)."""
    if desl in CAMPOS_CD:
        return CAMPOS_CD[desl]
    for base, (nome, tipo) in VETORES_CD.items():
        if (desl - base) % 4 == 0 and 1 <= (desl - base) // 4 <= 40:
            return f'{nome}[{(desl - base) // 4}]', tipo
    raise Falha(f'deslocamento {desl} fora do TIPOCD')


IDX = r'(\((?:[^()]|\([^()]*\))*\)|[A-Za-z_]\w*)'
CAST = r'\*\(\s*(?:undefined[124]?|u?int|char\s*\*)\s*\*\s*\)\s*'
FORMAS_CD = [
    # (regex, como achar o deslocamento, tem índice k?)
    (re.compile(CAST + r'\(\s*U_JUKELINUX1_ARQLOG \+ ' + IDX + r' \* 0x240 \+ (0x[0-9a-f]+)\s*\)'), 'arqlog', False),
    (re.compile(r'U_JUKELINUX1_ARQLOG\[' + IDX + r' \* 0x240 \+ (0x[0-9a-f]+)\]'), 'arqlog', False),
    (re.compile(CAST + r'\(\s*&U_JUKELINUX1_(\w+) \+ ' + IDX + r' \* 0x90\s*\)'), 'global', False),
    (re.compile(r'\(&U_JUKELINUX1_(\w+)\)\s*\[' + IDX + r' \* 0x90 \+ ([^\[\]]+)\]'), 'global', True),
    (re.compile(r'\(&U_JUKELINUX1_(\w+)\)\s*\[' + IDX + r' \* 0x90\]'), 'global', False),
    (re.compile(r'&U_JUKELINUX1_(\w+) \+ ' + IDX + r' \* 0x90 \+ ' + IDX), 'global', True),
    (re.compile(r'&U_JUKELINUX1_(\w+) \+ ' + IDX + r' \* 0x90'), 'global', False),
    (re.compile(IDX + r' \* 0x240 \+ 0x(8e9[0-9a-f]+) \+ ' + IDX + r' \* 4'), 'abs', True),
    (re.compile(IDX + r' \* 0x240 \+ 0x(8e9[0-9a-f]+)'), 'abs', False),
]


def le_componentes(caminho):
    """Classe de cada componente do Form1 (jukelinux1_form.inc)."""
    comps = {}
    for linha in open(caminho, encoding='utf-8'):
        m = re.match(r'\s+(\w+): (T\w+);', linha)
        if m:
            comps[m.group(1).upper()] = m.group(2)
    return comps


# Classes em que o texto do componente é Text; nas outras é Caption.
CLASSES_TEXT = {'TEdit', 'TComboBox', 'TMemo', 'TLabeledEdit', 'TListBox'}


TOKEN = re.compile(r'''
    (?P<esp>\s+)
  | (?P<texto>"(?:\\.|[^"\\])*")
  | (?P<char>'(?:\\.|[^'\\])')
  | (?P<num>0x[0-9a-fA-F]+|\d+)
  | (?P<nome>[A-Za-z_]\w*(?:\.[A-Za-z_]\w*)*)
  | (?P<op>==|!=|<=|>=|&&|\|\||<<|>>|[-+*/%<>!&()\[\],=])
''', re.X)

TIPOS_C = {'char', 'int', 'uint', 'byte', 'bool', 'word', 'dword', 'short', 'ushort', 'long', 'ulong', 'undefined',
           'undefined1', 'undefined2', 'undefined4', 'undefined8', 'uchar', 'longlong', 'ulonglong', 'code'}


def tokens(c):
    pos, saida = 0, []
    while pos < len(c):
        m = TOKEN.match(c, pos)
        if not m:
            raise Falha(f'símbolo desconhecido em {c[pos:pos + 10]!r}')
        pos = m.end()
        if m.lastgroup != 'esp':
            saida.append((m.lastgroup, m.group(0)))
    return saida


class Tradutor:
    """Analisa uma expressão C (precedência do C) e devolve (pascal, tipo). tipo: num, texto, bool, char, nulo."""

    def __init__(self, globais, locais, comps=None, ptrs=None):
        self.globais, self.locais = globais, locais
        self.comps = comps or {}
        # Temporárias do Ghidra que guardam o endereço de uma variável (piVar8 = &iStack_...): nome -> variável.
        self.ptrs = ptrs if ptrs is not None else {}
        self.cd = {}
        # Buffers da pilha que recebem um nome de arquivo (FPC_ANSISTR_TO_SHORTSTR) para o AssignFile seguinte.
        self.buffers = {}
        # Variáveis com o deslocamento de um CD já calculado (v := expr * 576): nome -> expressão Pascal do índice.
        self.mult = {}
        # Variável zerada na linha anterior (X := ''): o FPC zera o destino antes de uma função que devolve texto.
        self.zerada = None

    def novo(self):
        t = Tradutor(self.globais, self.locais, self.comps, self.ptrs)
        t.buffers = self.buffers
        t.mult = self.mult
        return t

    def substitui_cd(self, c):
        """Troca cada acesso ao acervo (as formas de FORMAS_CD) por um nome CDREF_n, resolvido em resolve()."""
        for rx, forma, com_k in FORMAS_CD:
            def troca(m, forma=forma, com_k=com_k):
                nome = f'CDREF_{len(self.cd)}'
                self.cd[nome] = (forma, m.groups(), com_k)
                return nome
            c = rx.sub(troca, c)
        for v in self.mult:
            def troca_mult(m, forma):
                nome = f'CDREF_{len(self.cd)}'
                self.cd[nome] = (forma, m.groups(), forma == 'mult_abs_k')
                return nome
            nome_v = r'\b(?i:' + re.escape(v) + r')\b'
            c = re.sub(CAST + r'\(\s*U_JUKELINUX1_ARQLOG \+ (' + nome_v + r') \+ (0x[0-9a-f]+)\s*\)',
                       lambda m: troca_mult(m, 'mult_arqlog'), c)
            c = re.sub(r'(' + nome_v + r') \+ 0x(8e9[0-9a-f]+) \+ ' + IDX + r' \* 4',
                       lambda m: troca_mult(m, 'mult_abs_k'), c)
            c = re.sub(r'(' + nome_v + r') \+ 0x(8e9[0-9a-f]+)', lambda m: troca_mult(m, 'mult_abs'), c)
        c = re.sub(CAST + r'\(\s*(CDREF_\d+)\s*\)', r'\1', c)
        c = re.sub(CAST + r'(CDREF_\d+)\b', r'\1', c)
        c = re.sub(r'\*\(\s*(?:u?int|undefined4)\s*\*\s*\)\s*\(\s*(CDREF_\d+|[A-Za-z_]\w*(?:\[0\])?)\s*\+\s*-4\s*\)',
                   r'COMPRIMENTO_(\1)', c)
        return c

    def resolve_cd(self, v):
        forma, g, com_k = self.cd[v]
        k_c = None
        if forma.startswith('mult_'):
            base = f'MAT[{self.mult[g[0].upper()]}]'
            if forma == 'mult_arqlog':
                desl = int(g[1], 16) - BASE_ARQLOG_CD
            else:
                desl = int(g[1], 16) - BASE_ABS_CD
            if forma == 'mult_abs_k':
                if desl not in VETORES_CD:
                    raise Falha(f'deslocamento {desl} não é vetor do TIPOCD')
                nome, tipo = VETORES_CD[desl]
                return f'{base}.{nome}[{self.num_de(self.novo().traduz(g[2]))}]', tipo
            campo, tipo = campo_cd(desl)
            return f'{base}.{campo}', tipo
        if forma == 'arqlog':
            idx_c, desl = g[0], int(g[1], 16) - BASE_ARQLOG_CD
        elif forma == 'global':
            if g[0].upper() not in GLOBAL_NO_CD:
                raise Falha(f'global {g[0]} não é campo do acervo')
            idx_c, desl = g[1], GLOBAL_NO_CD[g[0].upper()]
            k_c = g[2] if com_k else None
        else:
            idx_c, desl = g[0], int(g[1], 16) - BASE_ABS_CD
            k_c = g[2] if com_k else None
        base = f'MAT[{self.num_de(self.novo().traduz(idx_c))}]'
        if k_c is not None:
            if desl not in VETORES_CD:
                raise Falha(f'deslocamento {desl} não é vetor do TIPOCD')
            nome, tipo = VETORES_CD[desl]
            return f'{base}.{nome}[{self.num_de(self.novo().traduz(k_c))}]', tipo
        if forma == 'abs' and desl == 0:
            return base, 'registro'
        campo, tipo = campo_cd(desl)
        return f'{base}.{campo}', tipo

    def traduz(self, c):
        self.t = tokens(self.substitui_cd(c))
        self.i = 0
        r = self.ou()
        if self.i != len(self.t):
            raise Falha('sobrou ' + str(self.t[self.i:]))
        return r

    def olha(self, k=0):
        return self.t[self.i + k] if self.i + k < len(self.t) else (None, None)

    def pega(self, valor=None):
        tok = self.olha()
        if tok[0] is None or (valor is not None and tok[1] != valor):
            raise Falha(f'esperava {valor}')
        self.i += 1
        return tok

    # --- precedência do C, da menor para a maior ---
    def ou(self):
        e = self.e()
        while self.olha()[1] == '||':
            self.pega()
            d = self.e()
            e = (f'({self.bool_de(e)} or {self.bool_de(d)})', 'bool')
        return e

    def e(self):
        e = self.igualdade()
        while self.olha()[1] == '&&':
            self.pega()
            d = self.igualdade()
            e = (f'({self.bool_de(e)} and {self.bool_de(d)})', 'bool')
        return e

    def igualdade(self):
        e = self.relacao()
        while self.olha()[1] in ('==', '!='):
            op = self.pega()[1]
            d = self.relacao()
            e = self.compara(e, d, '=' if op == '==' else '<>')
        return e

    def relacao(self):
        e = self.desloca()
        while self.olha()[1] in ('<', '>', '<=', '>='):
            op = self.pega()[1]
            d = self.desloca()
            if e[1] != 'num' or d[1] != 'num':
                raise Falha('relação entre não-números')
            e = (f'({e[0]} {op} {d[0]})', 'bool')
        return e

    def desloca(self):
        e = self.soma()
        while self.olha()[1] in ('<<', '>>'):
            op = 'shl' if self.pega()[1] == '<<' else 'shr'
            d = self.soma()
            e = (f'({self.num_de(e)} {op} {self.num_de(d)})', 'num')
        return e

    def soma(self):
        e = self.produto()
        while self.olha()[1] in ('+', '-'):
            op = self.pega()[1]
            d = self.produto()
            if op == '+' and e[1] == 'texto' and d[1] == 'texto':
                e = (f'({e[0]} + {d[0]})', 'texto')
            else:
                e = (f'({self.num_de(e)} {op} {self.num_de(d)})', 'num')
        return e

    def produto(self):
        e = self.unario()
        while self.olha()[1] in ('*', '/', '%'):
            op = {'*': '*', '/': 'div', '%': 'mod'}[self.pega()[1]]
            d = self.unario()
            e = (f'({self.num_de(e)} {op} {self.num_de(d)})', 'num')
        return e

    def unario(self):
        k, v = self.olha()
        if v == '!':
            self.pega()
            e = self.unario()
            return (f'(not {self.bool_de(e)})', 'bool')
        if v == '-':
            self.pega()
            e = self.unario()
            return (f'(-{self.num_de(e)})', 'num')
        if v == '*':
            # Desreferência: só de local já convertida para valor (ex.: *local_c com local_c := Key).
            self.pega()
            k2, v2 = self.olha()
            if k2 != 'nome' or self.olha(1)[1] in ('[', '('):
                raise Falha('desreferência complexa')
            tipo = self.locais.get(v2.upper())
            if tipo not in ('num', 'texto', 'char', 'bool'):
                raise Falha(f'desreferência de {v2}')
            self.pega()
            return (v2, tipo)
        if v == '&':
            raise Falha('endereço (&)')
        if v == '(' and self.eh_conversao():
            return self.conversao()
        return self.posfixo()

    def eh_conversao(self):
        k, v = self.olha(1)
        return k == 'nome' and v.lower() in TIPOS_C

    def conversao(self):
        self.pega('(')
        ponteiro = False
        while self.olha()[1] != ')':
            k, v = self.pega()
            if v == '*':
                ponteiro = True
            elif not (k == 'nome' and v.lower() in TIPOS_C):
                raise Falha('conversão desconhecida')
        self.pega(')')
        e = self.unario()
        if ponteiro:
            if e[0] == '0':
                return ('nulo', 'nulo')
            if e[1] == 'texto':
                return e  # (char *) de um AnsiString: o mesmo texto
            raise Falha('conversão para ponteiro')
        return e

    def posfixo(self):
        k, v = self.pega()
        if v == '(':
            e = self.ou()
            self.pega(')')
            return e
        if k == 'num':
            return (('$' + v[2:].upper()) if v.startswith('0x') else v, 'num')
        if k == 'texto':
            return ("'" + self.desescapa(v[1:-1]).replace("'", "''") + "'", 'texto')
        if k == 'char':
            corpo = self.desescapa(v[1:-1])
            if corpo == '\0':
                return ('zero', 'zero')
            return ("'" + corpo.replace("'", "''") + "'", 'char')
        if k != 'nome':
            raise Falha(f'inesperado {v}')
        if v in ('STREQ', 'STRNE'):
            self.pega('(')
            a = self.ou()
            self.pega(',')
            b = self.ou()
            # O Ghidra às vezes põe argumentos que sobraram nos registradores: ficam só os dois primeiros.
            prof = 0
            while not (self.olha()[1] == ')' and prof == 0):
                k2, v2 = self.pega()
                prof += {'(': 1, ')': -1}.get(v2, 0)
            self.pega(')')
            if a[1] != 'texto' or b[1] != 'texto':
                raise Falha('STREQ sem dois textos')
            return (f"({a[0]} {'=' if v == 'STREQ' else '<>'} {b[0]})", 'bool')
        if self.olha()[1] == '(':
            return self.funcao(v)
        nome, tipo = self.resolve(v)
        if self.olha()[1] == '[':
            # local_x[0]: o Ghidra vê o texto como vetor de um ponteiro.
            self.pega('[')
            idx = self.pega()
            self.pega(']')
            if idx[1] != '0' or tipo != 'texto':
                raise Falha('índice')
        return (nome, tipo)

    FUNCOES = {
        'SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN': ('FileExists', ('texto',), 'bool'),
        'SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN': ('DirectoryExists', ('texto',), 'bool'),
        'SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT': ('Pos', ('texto', 'texto'), 'num'),
        'SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT': ('StrToIntDef', ('texto', 'num'), 'num'),
    }
    # Devolvem 0 quando os textos são iguais.
    COMPARA = {'fpc_ansistr_compare_equal', 'FPC_SHORTSTR_COMPARE_EQUAL', 'fpc_ansistr_compare',
               'fpc_shortstr_compare'}

    def argumentos(self):
        self.pega('(')
        args = []
        if self.olha()[1] == ')':
            self.pega(')')
            return args
        while True:
            args.append(self.ou())
            if self.olha()[1] == ',':
                self.pega(',')
                continue
            self.pega(')')
            return args

    def funcao(self, v):
        if v in self.FUNCOES:
            nome, tipos, ret = self.FUNCOES[v]
            args = self.argumentos()
            if len(args) != len(tipos):
                raise Falha(f'{v}: {len(args)} argumentos')
            for a, t in zip(args, tipos):
                if not (a[1] == t or (t == 'texto' and a[1] == 'char')):
                    raise Falha(f'{v}: argumento {a[1]}')
            return (f'{nome}({", ".join(a[0] for a in args)})', ret)
        if v == 'COMPRIMENTO_':
            args = self.argumentos()
            if len(args) != 1 or args[0][1] != 'texto':
                raise Falha('comprimento de não-texto')
            return (f'Length({args[0][0]})', 'num')
        if v in self.COMPARA:
            args = self.argumentos()
            if len(args) != 2 or {args[0][1], args[1][1]} - {'texto', 'char'}:
                raise Falha(f'{v}: argumentos')
            return (f'Ord({args[0][0]} <> {args[1][0]})', 'num')
        raise Falha(f'chamada de {v}')

    @staticmethod
    def desescapa(s):
        return s.encode('latin-1', 'backslashreplace').decode('unicode_escape')

    def resolve(self, v):
        if v in self.cd:
            return self.resolve_cd(v)
        if v.upper() in self.ptrs:
            return self.resolve(self.ptrs[v.upper()])
        if v.startswith('U_JUKELINUX1_'):
            nome = v[len('U_JUKELINUX1_'):]
            tipo = self.globais.get(nome.upper())
            if tipo is None:
                raise Falha(f'global sem tipo: {nome}')
            return nome, tipo
        if v.startswith('Form1.'):
            raise Falha('propriedade de componente')
        tipo = self.locais.get(v.upper())
        if tipo is None and v.upper() not in self.locais and v.upper() in self.globais:
            # global já escrita sem o prefixo (condições "// ?:" do tradutor)
            tipo = self.globais[v.upper()]
        if tipo is None:
            raise Falha(f'nome desconhecido: {v}')
        return v, tipo

    def destino(self, c):
        """Variável que recebe um resultado (&x, x, x[0], ponteiro conhecido ou campo do acervo)."""
        c = self.substitui_cd(c.strip())
        m = re.fullmatch(r'&?\s*([A-Za-z_]\w*)(\[0\])?', c)
        if not m:
            raise Falha('destino complexo: ' + c)
        return self.resolve(m.group(1))

    # --- conversões de tipo ---
    @staticmethod
    def bool_de(e):
        if e[1] == 'bool':
            return e[0]
        if e[1] == 'num':
            return f'({e[0]} <> 0)'
        raise Falha('valor lógico de ' + e[1])

    @staticmethod
    def num_de(e):
        if e[1] != 'num':
            raise Falha('número de ' + e[1])
        return e[0]

    @staticmethod
    def vazio_para(tipo):
        return {'num': '0', 'texto': "''", 'bool': 'False', 'char': '#0'}.get(tipo)

    def compara(self, a, b, op):
        if a[1] in ('zero', 'nulo'):
            a, b = b, a
        if b[1] in ('zero', 'nulo'):
            v = self.vazio_para(a[1])
            if v is None:
                raise Falha('vazio comparado com ' + a[1])
            return (f'({a[0]} {op} {v})', 'bool')
        if a[1] == 'num' and a[0] == '0' and b[1] == 'texto':
            a, b = b, a
        if a[1] == 'texto' and b[1] == 'num' and b[0] == '0':
            # no C o AnsiString é um ponteiro: "!= 0" quer dizer "não vazio"
            return (f"({a[0]} {op} '')", 'bool')
        if a[1] == b[1] and a[1] in ('num', 'texto', 'char', 'bool'):
            return (f'({a[0]} {op} {b[0]})', 'bool')
        if {a[1], b[1]} == {'texto', 'char'}:
            return (f'({a[0]} {op} {b[0]})', 'bool')
        raise Falha(f'comparação entre {a[1]} e {b[1]}')


PLAYER = re.compile(r'^(?:(\w+) = )?MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____(\w+?)\s*\((.*)\);$')


def separa_args(s):
    args, prof, atual = [], 0, ''
    for ch in s:
        if ch == ',' and prof == 0:
            args.append(atual.strip())
            atual = ''
            continue
        prof += {'(': 1, '[': 1, ')': -1, ']': -1}.get(ch, 0)
        atual += ch
    if atual.strip():
        args.append(atual.strip())
    return args


def componente(arg, tr, sufixo=''):
    """Form1.X (ou Form1.X.Picture com sufixo) -> (nome, classe), só para componentes do Form1."""
    m = re.fullmatch(r'Form1\.(\w+)' + re.escape(sufixo), arg.strip())
    if not m or m.group(1).upper() not in tr.comps:
        raise Falha('componente desconhecido: ' + arg)
    return m.group(1), tr.comps[m.group(1).upper()]


def texto_de(arg, tr):
    e = tr.traduz(arg)
    if e[1] not in ('texto', 'char'):
        raise Falha('não é texto: ' + arg)
    return e[0]


def booleano_de_registrador(arg):
    """O Ghidra escreve o Boolean passado em registrador como (x & 0xffffff00) = False ou CONCAT31(x, 1) = True."""
    if re.search(r'&\s*0xffffff00\s*$', arg.strip()):
        return 'False'
    if re.fullmatch(r'CONCAT31\(.*,\s*1\)', arg.strip()):
        return 'True'
    raise Falha('booleano desconhecido: ' + arg)


def _atribui(tr, destino_c, valor, tipo_valor):
    nome, tipo = tr.destino(destino_c)
    if tipo != tipo_valor and not (tipo == 'texto' and tipo_valor == 'char'):
        raise Falha(f'{tipo_valor} em destino {tipo}')
    return f'{nome} := {valor};'


def _texto_de_comp(nome, classe):
    return f'Form1.{nome}.' + ('Text' if classe in CLASSES_TEXT else 'Caption')


def chamada(nome, args, destino, tr):
    """Funções da RTL/LCL que viram comando. Devolve o Pascal ou levanta Falha."""
    n = len(args)
    if destino and nome not in ():
        raise Falha('chamada com resultado: ' + nome)
    if nome == 'fpc_ansistr_concat' and n == 3:
        return _atribui(tr, args[0], f'{texto_de(args[1], tr)} + {texto_de(args[2], tr)}', 'texto')
    if nome == 'fpc_shortstr_to_ansistr' and n == 2:
        return _atribui(tr, args[1], texto_de(args[0], tr), 'texto')
    if nome in ('FPC_ANSISTR_TO_SHORTSTR', 'FPC_SHORTSTR_TO_SHORTSTR') and n == 3:
        buf = args[0].strip()
        if re.fullmatch(r'au?Stack_\w+', buf) and buf.upper() not in tr.locais:
            # buffer da pilha: só guarda o texto; o AssignFile da linha seguinte usa
            tr.buffers[buf] = texto_de(args[2], tr)
            return ';'
        return _atribui(tr, args[0], texto_de(args[2], tr), 'texto')
    if nome == 'OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING' and n == 2:
        arq, tipo = tr.resolve(args[0].strip())
        if tipo != 'arquivo':
            raise Falha('AssignFile fora de arquivo texto')
        buf = args[1].strip()
        if buf not in tr.buffers:
            raise Falha('AssignFile sem o nome do arquivo')
        return f'AssignFile({arq}, {tr.buffers.pop(buf)});'
    if nome == 'fpc_ansistr_copy' and n == 3 and tr.zerada:
        # o Ghidra perdeu o destino (registrador); é a variável zerada logo antes
        ini, qtd = tr.num_de(tr.traduz(args[1])), tr.num_de(tr.traduz(args[2]))
        destino, tr.zerada = tr.zerada, None
        return _atribui(tr, destino, f'Copy({texto_de(args[0], tr)}, {ini}, {qtd})', 'texto')
    if nome == 'fpc_ansistr_copy' and n == 4:
        ini, qtd = tr.num_de(tr.traduz(args[1])), tr.num_de(tr.traduz(args[2]))
        return _atribui(tr, args[3], f'Copy({texto_de(args[0], tr)}, {ini}, {qtd})', 'texto')
    if nome == 'CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING' and n == 2:
        return _atribui(tr, args[1], _texto_de_comp(*componente(args[0], tr)), 'texto')
    if nome == 'CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING' and n == 2:
        return f'{_texto_de_comp(*componente(args[0], tr))} := {texto_de(args[1], tr)};'
    if nome == 'GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING' and n == 2:
        comp, _ = componente(args[0], tr, '.Picture')
        return f'Form1.{comp}.Picture.LoadFromFile({texto_de(args[1], tr)});'
    if nome == 'SYSUTILS_INTTOSTR_LONGINT__ANSISTRING' and n == 2:
        return _atribui(tr, args[1], f'IntToStr({tr.num_de(tr.traduz(args[0]))})', 'texto')
    funcs_texto = {'SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING': 'TrimRight',
                   'SYSUTILS_TRIMLEFT_ANSISTRING__ANSISTRING': 'TrimLeft',
                   'SYSUTILS_TRIM_ANSISTRING__ANSISTRING': 'Trim',
                   'SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING': 'UpperCase',
                   'SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING': 'LowerCase'}
    if nome in funcs_texto and n == 2:
        return _atribui(tr, args[1], f'{funcs_texto[nome]}({texto_de(args[0], tr)})', 'texto')
    if nome == 'EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN' and n == 2:
        comp, _ = componente(args[0], tr)
        return f'Form1.{comp}.Stretch := {booleano_de_registrador(args[1])};'
    posicoes = {'CONTROLS_TCONTROL____SETLEFT_LONGINT': 'Left', 'CONTROLS_TCONTROL____SETTOP_LONGINT': 'Top',
                'CONTROLS_TCONTROL____SETWIDTH_LONGINT': 'Width', 'CONTROLS_TCONTROL____SETHEIGHT_LONGINT': 'Height'}
    if nome in posicoes and n == 2:
        comp, _ = componente(args[0], tr)
        return f'Form1.{comp}.{posicoes[nome]} := {tr.num_de(tr.traduz(args[1]))};'
    if nome == 'FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING' and n == 2:
        comp, _ = componente(args[0], tr)
        return f'Form1.{comp}.Directory := {texto_de(args[1], tr)};'
    if nome in ('fpc_write_text_ansistr', 'fpc_write_text_shortstr', 'fpc_write_text_sint') and n == 3 \
            and args[0].strip() == '0':
        arq, tipo = tr.resolve(args[1].strip())
        if tipo != 'arquivo':
            raise Falha('write fora de arquivo texto')
        e = tr.traduz(args[2])
        if (nome == 'fpc_write_text_sint') != (e[1] == 'num') or e[1] not in ('num', 'texto', 'char'):
            raise Falha('write de tipo inesperado')
        return f'Write({arq}, {e[0]});'
    if nome == 'fpc_pchar_to_ansistr' and n == 2:
        # PChar de um texto (temporária puVar = local_x) de volta para AnsiString
        return _atribui(tr, args[1], texto_de(args[0], tr), 'texto')
    if nome == 'SYSUTILS_RENAMEFILE_ANSISTRING_ANSISTRING__BOOLEAN' and n == 2:
        return f'RenameFile({texto_de(args[0], tr)}, {texto_de(args[1], tr)});'
    if nome == 'FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN' and n == 3:
        # CopyFile(Origem, Destino, PreserveTime) do FileUtil; o Boolean veio em registrador
        return f'CopyFile({texto_de(args[0], tr)}, {texto_de(args[1], tr)}, {booleano_de_registrador(args[2])});'
    if nome == 'fpc_copy_proc' and n == 3 and args[2].strip() == 'INIT_JUKELINUX1_TIPOCD':
        # fpc_copy_proc(Origem, Destino, TypeInfo): na RTL do FPC a origem vem primeiro
        o, to = tr.traduz(args[0])
        d, td = tr.traduz(args[1])
        if td != 'registro' or to != 'registro':
            raise Falha('cópia de registro fora do acervo')
        if 'MAT[' not in d and 'MAT[' not in o:
            raise Falha('cópia entre temporárias')
        return f'{d} := {o};'
    raise Falha('chamada não reconhecida: ' + nome)


# Método virtual: ( **(code ** )( **(int ** )(OBJ + CAMPO) + VMT)) (args)
VIRTUAL = re.compile(r'^(?:(\w+) = )?\(\s*\*\*\(code\s*\*\*\s*\)\(\s*\*\*\(int\s*\*\*\s*\)\((Form1\.\w+|U_JUKELINUX1_FORM1)'
                     r' \+ (0x[0-9a-f]+)\) \+ (0x[0-9a-f]+)\)\)\s*\((.*)\);$')


def virtual(m, tr):
    destino, obj, campo, vmt, args = m.group(1), m.group(2), m.group(3), m.group(4), separa_args(m.group(5))
    if obj.startswith('Form1.') and campo in ('0x364', '0x36c'):
        comp, _ = componente(obj, tr)
        lista = f'Form1.{comp}.Items'
        if not args or comp not in args[0]:
            raise Falha('lista de outro componente')
        if vmt == '0x78' and len(args) in (3, 4) and not destino:   # TStrings.Get
            return _atribui(tr, args[2], f'{lista}[{tr.num_de(tr.traduz(args[1]))}]', 'texto')
        if vmt == '0x80' and len(args) == 1 and destino:            # TStrings.GetCount
            nome, tipo = tr.resolve(destino)
            if tipo != 'num':
                raise Falha('Count em destino não numérico')
            return f'{nome} := {lista}.Count;'
        if vmt == '0xa4' and len(args) == 2 and not destino:        # TStrings.Add
            return f'{lista}.Add({texto_de(args[1], tr)});'
        if vmt == '0xb8' and len(args) == 1 and not destino:        # TStrings.Clear
            return f'{lista}.Clear;'
    if vmt == '0x450' and len(args) == 1 and destino:  # TCustomCheckBox.GetChecked (RadioButton/CheckBox)
        comp, classe = componente(args[0], tr)
        if classe not in ('TRadioButton', 'TCheckBox'):
            raise Falha('Checked fora de RadioButton/CheckBox')
        nome, tipo = tr.resolve(destino)
        if tipo != 'bool':
            raise Falha('Checked em destino não Boolean')
        return f'{nome} := Form1.{comp}.Checked;'
    if obj == 'U_JUKELINUX1_FORM1' and vmt == '0xdc' and len(args) == 2 and not destino:  # TCustomTimer.SetInterval
        comp, classe = componente(args[0], tr)
        if classe != 'TTimer':
            raise Falha('SetInterval fora de TTimer')
        return f'Form1.{comp}.Interval := {tr.num_de(tr.traduz(args[1]))};'
    raise Falha('método virtual desconhecido')


CHAMADA = re.compile(r'^(?:(\w+) = )?([A-Za-z_]\w*)\s*\((.*)\);$')


def fecha_no_fim(texto):
    """True se o '(' que abre os argumentos fecha exatamente no fim do texto."""
    prof = 0
    for i, ch in enumerate(texto):
        prof += {'(': 1, ')': -1}.get(ch, 0)
        if prof == 0 and i < len(texto) - 1:
            return False
    return prof == 0


def comando(c, tr):
    """Traduz uma linha // C: para um comando Pascal, ou levanta Falha."""
    m = re.match(r'^(\w+) = fpc_setjmp\(\);$', c)
    if m:
        nome, tipo = tr.resolve(m.group(1))
        if tipo != 'num':
            raise Falha('setjmp em destino não numérico')
        return f'{nome} := 0;  // caminho normal do setjmp (as exceções do Pascal fazem o papel do longjmp)'

    m = VIRTUAL.match(c)
    if m:
        return virtual(m, tr)
    m = CHAMADA.match(c)
    if m and m.group(2) != 'MPLAYERCTRL' and not m.group(2).startswith('MPLAYERCTRL_') \
            and fecha_no_fim('(' + m.group(3) + ')'):
        if not m.group(1):
            return chamada(m.group(2), separa_args(m.group(3)), m.group(1), tr)
    m = PLAYER.match(c)
    if m:
        destino, metodo, args = m.group(1), m.group(2), separa_args(m.group(3))
        alvo = args[0] if args else ''
        if not re.fullmatch(r'Form1\.(Play|playtv)', alvo):
            raise Falha('player desconhecido')
        if metodo == 'STOP' and len(args) == 1 and not destino:
            return f'{alvo}.Stop;'
        if metodo == 'PLAY' and len(args) == 1 and not destino:
            return f'{alvo}.Play;'
        if metodo == 'SETFILENAME_ANSISTRING' and len(args) == 2 and not destino:
            e = tr.traduz(args[1])
            if e[1] != 'texto':
                raise Falha('nome de arquivo não é texto')
            return f'{alvo}.SetFileName({e[0]});'
        if metodo == 'SETVOLUME_LONGINT' and len(args) == 2 and not destino:
            e = tr.traduz(args[1])
            return f'{alvo}.SetVolume({tr.num_de(e)});'
        if metodo in ('PLAYING__BOOLEAN', 'RUNNING__BOOLEAN') and len(args) == 1 and destino:
            if tr.locais.get(destino.upper()) != 'bool':
                raise Falha('destino não é Boolean')
            return f"{destino} := {alvo}.{'Playing' if metodo.startswith('PLAYING') else 'Running'};"
        raise Falha('chamada do player desconhecida')
    m = re.match(r'^([A-Za-z_]\w*|[^=;]*?\b0x90\b[^=;]*?|[^=;]*?\b0x240\b[^=;]*?) = (.+);$', c)
    if m:
        if m.group(1).upper() in tr.ptrs and m.group(1).upper() not in tr.locais:
            raise Falha('apelido de ponteiro (puVar = x) não é atribuição')
        # destino: variável simples ou campo do acervo ((&G)[i*0x90 + k], ARQLOG + i*0x240 + c, ...)
        nome, tipo = tr.destino(m.group(1))
        e = tr.traduz(m.group(2))
        if e[1] in ('zero', 'nulo'):
            v = tr.vazio_para(tipo)
            if v is None:
                raise Falha('vazio para ' + str(tipo))
            return f'{nome} := {v};'
        if e[1] != tipo and not (tipo == 'texto' and e[1] == 'char'):
            raise Falha(f'atribuição de {e[1]} a {tipo}')
        return f'{nome} := {e[0]};'
    raise Falha('comando não reconhecido')


RE_IF = re.compile(r'if False \{ C: (.*?) \} then')
RE_LINHA_C = re.compile(r'^(\s*)// C: (.*)$')


def pascal_para_c(cond):
    """Condição em Pascal (as "// ?:" do tradutor) escrita no C que o Tradutor lê."""
    def troca(m):
        if m.group(1):
            return '"' + m.group(1)[1:-1].replace("''", "'").replace('\\', '\\\\').replace('"', '\\"') + '"'
        op = m.group(2)
        if op:
            return {'<>': '!=', '=': '==', '<=': '<=', '>=': '>=', ':=': ':='}[op]
        return {'and': '&&', 'or': '||', 'not': '!', 'div': '/', 'mod': '%'}[m.group(3).lower()]
    return re.sub(r"('(?:''|[^'])*')|(<>|<=|>=|:=|=)|\b(and|or|not|div|mod)\b", troca, cond, flags=re.I)


RE_TALVEZ = re.compile(r'^(\s*)if False then begin // \?: (.*)$')
RE_PONTEIRO = re.compile(r'^\s*// C: (\w+) = &(\w+);\s*$')


def retipa_temporarias_cd(texto):
    """Uma local copiada de/para um CD com fpc_copy_proc(..., INIT_JUKELINUX1_TIPOCD) é um TIPOCD (o tradutor a
    declarou como número). Tira a local da lista em que está e declara de novo como TIPOCD."""
    temps = set()
    for m in re.finditer(r'fpc_copy_proc\s*\(([^;]*)INIT_JUKELINUX1_TIPOCD\)', texto):
        for a in separa_args(m.group(1).rstrip().rstrip(',')):
            if re.fullmatch(r'local_\w+', a.strip()):
                temps.add(a.strip())
    # rodando de novo: a que já é TIPOCD fica como está
    temps = {t for t in temps if not re.search(r'\b' + t + r': TIPOCD;', texto)}
    if not temps:
        return texto
    corpo = re.search(r'\nvar\n(.*?)\nbegin\n', texto, re.S)
    if not corpo:
        return texto
    linhas = []
    for linha in corpo.group(1).split('\n'):
        m = re.match(r'(\s+)([\w, ]+): (.+);$', linha)
        if m:
            nomes = [n.strip() for n in m.group(2).split(',') if n.strip() not in temps]
            if not nomes:
                continue
            linha = f'{m.group(1)}{", ".join(nomes)}: {m.group(3)};'
        linhas.append(linha)
    linhas += [f'  {t}: TIPOCD;  // completar: copiada de/para MAT com fpc_copy_proc' for t in sorted(temps)]
    return texto[:corpo.start(1)] + '\n'.join(linhas) + texto[corpo.end(1):]


def completa_rotina(texto, globais, estatistica=None, comps=None):
    texto = retipa_temporarias_cd(texto)
    tr = Tradutor(globais, le_locais(texto), comps)
    est = estatistica if estatistica is not None else {}

    def troca_if(m):
        try:
            pascal, tipo = tr.traduz(m.group(1))
            cond = tr.bool_de((pascal, tipo))
        except Falha:
            est['if_ficou'] = est.get('if_ficou', 0) + 1
            return m.group(0)
        est['if_convertido'] = est.get('if_convertido', 0) + 1
        return f'if {cond} {{ C convertido: {m.group(1)} }} then'

    saida = []
    for linha in texto.split('\n'):
        m = RE_PONTEIRO.match(linha)
        if m:
            tr.ptrs[m.group(1).upper()] = m.group(2)
        # puVar5 = local_13c: temporária do Ghidra que só aponta para o texto (PChar de um AnsiString)
        m = re.match(r'^\s*// C: (pu?[a-z]*Var\d+) = (local_\w+|U_JUKELINUX1_\w+);\s*$', linha)
        if m and m.group(1).upper() not in tr.locais:
            tr.ptrs[m.group(1).upper()] = m.group(2)
        m = re.match(r'^\s*(\w+) := (.+) \* 576;\s*$', linha)
        if m:
            tr.mult[m.group(1).upper()] = m.group(2)
        m = RE_TALVEZ.match(linha)
        if m:
            try:
                cond = tr.bool_de(tr.traduz(pascal_para_c(m.group(2))))
                linha = f'{m.group(1)}if {cond} then begin // ? convertido: {m.group(2)}'
                est['talvez_convertido'] = est.get('talvez_convertido', 0) + 1
            except Falha:
                est['talvez_ficou'] = est.get('talvez_ficou', 0) + 1
        linha = RE_IF.sub(troca_if, linha)
        # Última variável zerada (X := '') que nenhuma linha Pascal usou depois: destino perdido de um Copy.
        mz = re.match(r"^\s*(\w+) := '';\s*$", linha)
        if mz:
            tr.zerada = mz.group(1)
        elif tr.zerada and not re.match(r'^\s*//', linha) \
                and re.search(r'\b' + re.escape(tr.zerada) + r'\b', linha.split('//')[0]):
            tr.zerada = None
        m = RE_LINHA_C.match(linha)
        if m:
            try:
                novo = comando(m.group(2).strip(), tr)
                linha = f'{m.group(1)}{novo}  // C convertido: {m.group(2).strip()}'
                est['cmd_convertido'] = est.get('cmd_convertido', 0) + 1
            except Falha:
                pass
        saida.append(linha)
    return '\n'.join(saida)


def completa_arquivo(globais_inc, rotinas_inc, form_inc=None):
    globais = le_globais(globais_inc)
    import os
    form_inc = form_inc or os.path.join(os.path.dirname(rotinas_inc), 'jukelinux1_form.inc')
    comps = le_componentes(form_inc) if os.path.exists(form_inc) else {}
    texto = open(rotinas_inc, encoding='utf-8').read()
    # cabeçalhos: com parâmetros "(", sem parâmetros ";" e funções sem parâmetros ": Tipo;"
    partes = re.split(r'\n(?=(?:procedure|function) [\w.]+\s*[(:;])', texto)
    est = {}
    novas = []
    for p in partes:
        if re.match(r'(procedure|function) ', p) and not p.split('\n', 1)[0].endswith('forward;'):
            p = completa_rotina(p, globais, est, comps)
        novas.append(p)
    open(rotinas_inc, 'w', encoding='utf-8', newline='\n').write('\n'.join(novas))
    return est


if __name__ == '__main__':
    est = completa_arquivo(sys.argv[1], sys.argv[2], sys.argv[3] if len(sys.argv) > 3 else None)
    print(f"condições convertidas: {est.get('if_convertido', 0)} (ficaram {est.get('if_ficou', 0)}); "
          f"incertas convertidas: {est.get('talvez_convertido', 0)} (ficaram {est.get('talvez_ficou', 0)}); "
          f"comandos convertidos: {est.get('cmd_convertido', 0)}")
