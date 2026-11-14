"""Completa o Pascal gerado por gerar_rotinas.py: converte o que o tradutor deixou como
`if False { C: ... } then` e como linhas `// C: ...`, quando dá para fazer isso com segurança.

Converte:
- condições: comparações (==, !=, <, ...), &&, ||, !, aritmética, STREQ/STRNE (texto), teclas (*local_c, que no
  Pascal já é o valor de Key), '\\0' e ponteiro nulo comparados com variável de tipo conhecido;
- comandos: chamadas do player (MPLAYERCTRL_...: Play, Stop, SetFileName, SetVolume, Playing, Running) e
  atribuições simples (variável = expressão).

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

    def __init__(self, globais, locais):
        self.globais, self.locais = globais, locais

    def traduz(self, c):
        self.t = tokens(c)
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
            raise Falha(f'chamada de {v}')
        nome, tipo = self.resolve(v)
        if self.olha()[1] == '[':
            # local_x[0]: o Ghidra vê o texto como vetor de um ponteiro.
            self.pega('[')
            idx = self.pega()
            self.pega(']')
            if idx[1] != '0' or tipo != 'texto':
                raise Falha('índice')
        return (nome, tipo)

    @staticmethod
    def desescapa(s):
        return s.encode('latin-1', 'backslashreplace').decode('unicode_escape')

    def resolve(self, v):
        if v.startswith('U_JUKELINUX1_'):
            nome = v[len('U_JUKELINUX1_'):]
            tipo = self.globais.get(nome.upper())
            if tipo is None:
                raise Falha(f'global sem tipo: {nome}')
            return nome, tipo
        if v.startswith('Form1.'):
            raise Falha('propriedade de componente')
        tipo = self.locais.get(v.upper())
        if tipo is None:
            raise Falha(f'nome desconhecido: {v}')
        return v, tipo

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


def comando(c, tr):
    """Traduz uma linha // C: para um comando Pascal, ou levanta Falha."""
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
    m = re.match(r'^([A-Za-z_]\w*) = (.+);$', c)
    if m and not re.search(r'\b[A-Z]{3,}\w*_\w+\s*\(', m.group(2)):
        nome, tipo = tr.resolve(m.group(1))
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


def completa_rotina(texto, globais, estatistica=None):
    tr = Tradutor(globais, le_locais(texto))
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
        linha = RE_IF.sub(troca_if, linha)
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


def completa_arquivo(globais_inc, rotinas_inc):
    globais = le_globais(globais_inc)
    texto = open(rotinas_inc, encoding='utf-8').read()
    partes = re.split(r'\n(?=(?:procedure|function) [\w.]+\()|\n(?=(?:procedure|function) [\w.]+;\n)', texto)
    est = {}
    novas = []
    for p in partes:
        if re.match(r'(procedure|function) ', p) and not p.split('\n', 1)[0].endswith('forward;'):
            p = completa_rotina(p, globais, est)
        novas.append(p)
    open(rotinas_inc, 'w', encoding='utf-8', newline='\n').write('\n'.join(novas))
    return est


if __name__ == '__main__':
    est = completa_arquivo(sys.argv[1], sys.argv[2])
    print(f"condições convertidas: {est.get('if_convertido', 0)} (ficaram {est.get('if_ficou', 0)}); "
          f"comandos convertidos: {est.get('cmd_convertido', 0)}")
