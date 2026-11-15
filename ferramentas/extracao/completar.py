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
    if t.startswith('file of'):
        return 'arqtipado'
    if t in ('tipocartao',):
        return 'cartao'
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
             560: ('Lancamento', 'texto'), 572: ('TotalTocadas', 'num')}
# Vetores globais [1..n] de 4 bytes por elemento (AnsiString ou LongInt) que o Ghidra não reconheceu como vetor.
# nome -> (tipo, endereço da posição 0 (= posição 1 - 4) ou None, global logo antes do vetor ou None, n).
# Formas aceitas: *(t *)(&DAT_<pos0> + i * 4), &DAT_<pos0> + i * 4, *(t *)(i * 4 + 0x<pos0>), i * 4 + 0x<pos0>,
# DAT_<pos0 + 4k> (posição k fixa) e (&U_JUKELINUX1_<global antes>)[i]. O nome sem índice (só o que está em
# VETORES_NOME_E_POS1) é a posição 1.
VETORES_GLOBAIS = {
    'MMRITMO': ('texto', 0x092fffac, None, 100),  # ritmos que existem no acervo
    'MMRITMOTOCOU': ('num', 0x0930013c, None, 100),  # vezes que cada ritmo tocou
    'MMLETRA': ('texto', None, 'CDSELEAPAGARX', 100),  # letras iniciais dos CDs
    'MATKARAOKE': ('texto', 0x092f635c, None, 9999),  # arquivos de karaokê
    'MATPROPAGANDA': ('texto', None, 'TOTALPRO', 500),  # imagens e vídeos de propaganda
    'MATFRASES': ('texto', 0x09301bfc, None, 50),  # frases do letreiro (com espaços no fim)
    'MATFRASESORI': ('texto', 0x09301ccc, None, 50),  # frases como foram digitadas
    'LISTA50MUSICASMAISTOCADAS': ('texto', 0x0964721c, None, 50),  # caminho das 50 mais tocadas
}
VETORES_NOME_E_POS1 = ('MATFRASES', 'MATFRASESORI')
# Vetores globais de registros de 8 bytes (TIPOJPG): nome -> (endereço do registro 0, campos por deslocamento, n).
# Forma: *(t *)(i * 8 + 0x<registro 0 + deslocamento do campo>).
VETORES_REGISTRO = {
    'RJ': (0x093008c8, {0: 'Nome', 4: 'Jpg'}, 100),  # ritmosxjgps.txt
    'LJ': (0x09300bf8, {0: 'Nome', 4: 'Jpg'}, 100),  # letrasxjgps.txt
}
# Posições dos Seek em arquivo tipado, em ordem, por rotina (o Ghidra perdeu o Int64 da posição; tiradas do fluxo
# do C: o registro 0 de cada arquivo é o cabeçalho e o laço lê do 1 em diante; gravar crédito novo vai para o fim).
POSICOES_SEEK = {
    'Carregando_Cartoes': ['0', 'local_10', '0', 'local_10', 'local_10'],
    'Gravacreditonocartao': ['local_14', 'local_14', 'local_14'],
    'Lecreditodocartao': ['local_14'],
}
# Outras formas de chegar ao vetor (IDX = o índice): ARQTOCARX + 0x24c é o endereço da posição 0 de MATFRASES.
APELIDOS_VETORES = {'MATFRASES': (r'U_JUKELINUX1_ARQTOCARX \+ IDX \* 4 \+ 0x24c',)}
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
CAST = r'\*\(\s*(?:undefined[124]?|u?int|char|byte)\s*\*\s*\*?\s*\)\s*'
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


def literal_pascal(t):
    """Texto Pascal entre aspas; caracteres de controle (\\r, \\n...) vão como #13 fora das aspas."""
    partes, atual = [], ''
    for ch in t:
        if ord(ch) < 32:
            if atual:
                partes.append("'" + atual.replace("'", "''") + "'")
                atual = ''
            partes.append(f'#{ord(ch)}')
        else:
            atual += ch
    if atual or not partes:
        partes.append("'" + atual.replace("'", "''") + "'")
    return ''.join(partes)


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
        self.zeradas = []
        # Variável atribuída na linha Pascal anterior: valor de um Write cujo argumento o Ghidra perdeu (registrador).
        self.ultima_atribuida = None
        self.rotinas = {}
        # local_x = "texto" (PChar de um literal) vista antes: pedaço de um fpc_ansistr_concat_multi
        self.literais = {}
        self.seeks = []
        self.vetlocais = set()

    def novo(self):
        t = Tradutor(self.globais, self.locais, self.comps, self.ptrs)
        t.buffers = self.buffers
        t.mult = self.mult
        t.rotinas = self.rotinas
        t.literais = self.literais
        t.seeks = self.seeks
        t.vetlocais = self.vetlocais
        return t

    def substitui_cd(self, c):
        """Troca cada acesso ao acervo (as formas de FORMAS_CD) por um nome CDREF_n, resolvido em resolve()."""
        c = self.substitui_vetores(c)
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

    def substitui_vetores(self, c):
        """Troca cada acesso a um vetor de VETORES_GLOBAIS por um nome CDREF_n (forma 'vglobal')."""
        def ref(nome_v, idx, campo=None):
            nome = f'CDREF_{len(self.cd)}'
            self.cd[nome] = ('vglobal', (nome_v, idx, campo), False)
            return nome
        def fixo(pascal, tipo='texto'):
            nome = f'CDREF_{len(self.cd)}'
            self.cd[nome] = ('fixo', (pascal, tipo), False)
            return nome
        # Cartões (registro TIPOCARTAO de 38 bytes: Codigo String[30] em 0, Valor String[4] em 0x1f, Situacao
        # String[1] em 0x24). MMCARTAO[i] fica em 0x0930303a + i * 0x26; MMCARTAOJADEUCREDITO[i] em 0x09645f9a + i * 0x26;
        # ACARM em 0x09647020.
        def cartao(vetor, campo):
            return lambda m: fixo(f'{vetor}[{self.num_de(self.novo().traduz(m.group(1)))}].{campo}')
        c = re.sub(CAST + r'\(\s*\(int\)&U_JUKELINUX1_VOLUMEPELOPAINEL \+ ' + IDX + r' \* 0x26 \+ 1\s*\)',
                   cartao('MMCARTAO', 'Valor'), c)
        for end_, campo in (('0930303a', 'Codigo'), ('0930305e', 'Situacao')):
            c = re.sub(r'\(&DAT_' + end_ + r'\)\s*\[' + IDX + r' \* 0x26\]', cartao('MMCARTAO', campo), c)
            c = re.sub(r'&DAT_' + end_ + r' \+ ' + IDX + r' \* 0x26\b', cartao('MMCARTAO', campo), c)
        c = re.sub(r'\b' + IDX + r' \* 0x26 \+ 0x9303059\b', cartao('MMCARTAO', 'Valor'), c)
        c = re.sub(r'\b' + IDX + r' \* 0x26 \+ 0x9645f9a\b', cartao('MMCARTAOJADEUCREDITO', 'Codigo'), c)
        # U_JUKELINUX1_MMCARTAO[i * 0x26 + k]: k passa do fim de MMCARTAO (90000 * 38 = 0x342f60) e cai em
        # MMCARTAOJADEUCREDITO[i] (k - 0x342f60 + 38 = deslocamento do campo)
        def apos_mmcartao(m):
            campo = {0: 'Codigo', 31: 'Valor', 36: 'Situacao'}.get(int(m.group(2), 16) - 0x342f60 + 38)
            if campo is None:
                return m.group(0)
            return fixo(f'MMCARTAOJADEUCREDITO[{self.num_de(self.novo().traduz(m.group(1)))}].{campo}')
        c = re.sub(r'U_JUKELINUX1_MMCARTAO\[' + IDX + r' \* 0x26 \+ (0x342f[0-9a-f]{2})\]', apos_mmcartao, c)
        c = re.sub(r'\b0x964703f\b|U_JUKELINUX1_ACARM\[0x1f\]', lambda m: fixo('ACARM.Valor'), c)
        c = re.sub(r'\b0x9647044\b|U_JUKELINUX1_ACARM\[0x24\]', lambda m: fixo('ACARM.Situacao'), c)
        c = re.sub(r'&U_JUKELINUX1_CODIGODOCARTAO\b', 'U_JUKELINUX1_CODIGODOCARTAO', c)
        # vetor de textos na pilha (base + i * 4 + k): NovaVet_<base>[i + k div 4], declarado por vetores_locais
        for base in self.vetlocais:
            def vl(m, base=base):
                idx = self.num_de(self.novo().traduz(m.group(1)))
                k = int(m.group(2), 0) // 4
                return fixo(f'NovaVet_{base[6:]}[{idx}{" + " + str(k) if k > 0 else " - " + str(-k) if k else ""}]')
            corpo = re.escape(base) + r' \+ ' + IDX + r' \* 4 \+ (0x[0-9a-f]+|-?\d+)'
            c = re.sub(CAST + r'\(\s*' + corpo + r'\s*\)', vl, c)
            c = re.sub(r'\b' + corpo, vl, c)
        # (int)&U_JUKELINUX1_G + i * 0x240 + k: byte k do campo G do CD i (o comprimento de um String[n])
        def campo_byte(m):
            g, idx, k = m.group(1), m.group(2), int(m.group(3), 0)
            if g not in GLOBAL_NO_CD:
                return m.group(0)
            campo, tipo = campo_cd(GLOBAL_NO_CD[g] + k)
            return fixo(f'MAT[{self.num_de(self.novo().traduz(idx))}].{campo}', tipo)
        c = re.sub(CAST + r'\(\s*\(int\)&U_JUKELINUX1_(\w+) \+ ' + IDX + r' \* 0x240 \+ (\d+)\s*\)', campo_byte, c)
        # propriedade de componente que o gerador escreveu com "?" (deslocamento conferido à mão): Form1.X.Left?
        c = re.sub(r'\b(Form1\.\w+)\.(Left|Top|Width|Height)\?', lambda m: fixo(f'{m.group(1)}.{m.group(2)}', 'num'), c)
        for nome_v, (base, campos, n) in VETORES_REGISTRO.items():
            for desl, campo in campos.items():
                h = f'{base + desl:x}'
                c = re.sub(CAST + r'\(\s*' + IDX + r' \* 8 \+ 0x' + h + r'\s*\)',
                           lambda m, nv=nome_v, cp=campo: ref(nv, m.group(1), cp), c)
        for nome_v, (tipo, pos0, antes, n) in VETORES_GLOBAIS.items():
            if antes:
                c = re.sub(r'\(&U_JUKELINUX1_' + antes + r'\)\s*\[([^\[\]]+)\]',
                           lambda m, nv=nome_v: ref(nv, m.group(1)), c)
            for alias in APELIDOS_VETORES.get(nome_v, ()):
                c = re.sub(CAST + r'\(\s*' + alias.replace('IDX', IDX) + r'\s*\)', lambda m, nv=nome_v: ref(nv, m.group(1)), c)
            if pos0 is None:
                continue
            h = f'{pos0:08x}'
            c = re.sub(CAST + r'\(\s*&DAT_' + h + r' \+ ' + IDX + r' \* 4\s*\)', lambda m, nv=nome_v: ref(nv, m.group(1)), c)
            c = re.sub(CAST + r'\(\s*' + IDX + r' \* 4 \+ 0x' + h.lstrip('0') + r'\s*\)',
                       lambda m, nv=nome_v: ref(nv, m.group(1)), c)
            c = re.sub(r'&DAT_' + h + r' \+ ' + IDX + r' \* 4\b', lambda m, nv=nome_v: ref(nv, m.group(1)), c)
            c = re.sub(r'\b' + IDX + r' \* 4 \+ 0x' + h.lstrip('0') + r'\b', lambda m, nv=nome_v: ref(nv, m.group(1)), c)

            def fixa(m, nv=nome_v, pos0=pos0, n=n):
                k = (int(m.group(1), 16) - pos0) // 4
                if (int(m.group(1), 16) - pos0) % 4 or not 1 <= k <= n:
                    return m.group(0)
                return ref(nv, str(k))
            c = re.sub(r'\bDAT_(0' + h[1:5] + r'[0-9a-f]{3})\b', fixa, c)
        return c

    def resolve_cd(self, v):
        forma, g, com_k = self.cd[v]
        k_c = None
        if forma == 'fixo':
            return g[0], g[1]
        if forma == 'vglobal':
            idx = self.num_de(self.novo().traduz(g[1]))
            if g[2]:
                return f'{g[0]}[{idx}].{g[2]}', 'texto'
            return f'{g[0]}[{idx}]', VETORES_GLOBAIS[g[0]][0]
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
        c = tira_registradores(c)
        # x div 2^n do Pascal (com sinal) como o compilador escreve: (int)(x + (x >> 0x1f & (2^n - 1)U)) >> n
        c = re.sub(r'\(int\)\((\w+) \+ \(\1 >> 0x1f & (1|3|7|0xf)U\)\) >> ([1-4])',
                   lambda m: f'({m.group(1)} / {2 ** int(m.group(3))})', c)
        # a mesma correção de sinal separada do >> (o >> fica na linha seguinte): só muda para negativos, e os
        # contadores em que aparece não ficam negativos
        c = re.sub(r'^(\w+) \+ \(\1 >> 0x1f & 1U\)$', r'\1', c.strip())
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
        ini = self.i
        self.pega('(')
        ponteiro = False
        while self.olha()[1] != ')':
            k, v = self.pega()
            if v == '*':
                ponteiro = True
            elif not (k == 'nome' and v.lower() in TIPOS_C):
                raise Falha('conversão desconhecida')
        self.pega(')')
        tipos_conv = [t for t in re.findall(r'\w+', ' '.join(v for _, v in self.t[ini:self.i]))]
        e = self.unario()
        if not ponteiro and e[1] == 'char' and any(t in ('byte', 'uint', 'int', 'uchar') for t in tipos_conv):
            return (f'Ord({e[0]})', 'num')
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
            if int(v, 0) == 0:
                return ('0', 'num')  # 0x0 também: os testes de ponteiro nulo comparam com '0'
            return (('$' + v[2:].upper()) if v.startswith('0x') else v, 'num')
        if k == 'texto':
            return (literal_pascal(self.desescapa(v[1:-1])), 'texto')
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
            if self.olha()[1] == '0' and self.olha(1)[1] == ']':
                self.pega()
                self.pega(']')
                if tipo != 'texto':
                    raise Falha('índice')
                return (nome, tipo)
            # caractere de um texto: o C conta do 0, o Pascal do 1
            idx = self.num_de(self.ou())
            self.pega(']')
            if tipo != 'texto':
                raise Falha('índice')
            return (f'{nome}[{idx} + 1]', 'char')
        return (nome, tipo)

    FUNCOES = {
        'SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN': ('FileExists', ('texto',), 'bool'),
        'SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN': ('DirectoryExists', ('texto',), 'bool'),
        'SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT': ('Pos', ('texto', 'texto'), 'num'),
        'SYSTEM_RANDOM_LONGINT__LONGINT': ('Random', ('num',), 'num'),
        'SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT': ('StrToIntDef', ('texto', 'num'), 'num'),
    }
    # Devolvem 0 quando os textos são iguais (as sem _equal também dizem a ordem: CompareStr).
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
            if v in ('fpc_ansistr_compare', 'fpc_shortstr_compare'):
                # ordem (negativo, 0, positivo), usada para ordenar: não só igual/diferente
                return (f'CompareStr({args[0][0]}, {args[1][0]})', 'num')
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
    if re.fullmatch(r'CONCAT31\(.*,\s*1\)', arg.strip()) or arg.strip() == '1':
        return 'True'
    if arg.strip() == '0':
        return 'False'
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
    props = {'CONTROLS_TCONTROL____SETLEFT_LONGINT': 'Left', 'CONTROLS_TCONTROL____SETTOP_LONGINT': 'Top',
             'CONTROLS_TCONTROL____SETWIDTH_LONGINT': 'Width', 'CONTROLS_TCONTROL____SETHEIGHT_LONGINT': 'Height'}
    if nome in props and n == 2:
        comp, _ = componente(args[0], tr)
        return f'Form1.{comp}.{props[nome]} := {tr.num_de(tr.traduz(args[1]))};'
    if nome in ('CONTROLS_TCONTROL____HIDE', 'CONTROLS_TCONTROL____SHOW') and n == 1:
        comp, _ = componente(args[0], tr)
        return f"Form1.{comp}.{'Hide' if nome.endswith('HIDE') else 'Show'};"
    if nome == 'EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE' and n == 2:
        comp, _ = componente(args[0], tr)
        orig, _ = componente(args[1], tr, '.Picture')
        return f'Form1.{comp}.Picture := Form1.{orig}.Picture;'
    if nome == 'SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN' and n == 1:
        return f'DeleteFile({texto_de(args[0], tr)});'
    if nome == 'SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN' and n == 1:
        return f'RemoveDir({texto_de(args[0], tr)});'
    if nome == 'DIALOGS_SHOWMESSAGE_ANSISTRING' and n == 1:
        return f'ShowMessage({texto_de(args[0], tr)});'
    if nome == 'SHELLCTRLS_TCUSTOMSHELLTREEVIEW____GETPATH__ANSISTRING' and n == 2:
        comp, _ = componente(args[0], tr)
        return _atribui(tr, args[1], f'Form1.{comp}.Path', 'texto')
    if nome == 'fpc_write_text_ansistr' and n == 3 and args[0].strip() == '0':
        arq, tipo = tr.resolve(args[1].strip())
        if tipo != 'arquivo':
            raise Falha('Write fora de arquivo texto')
        return f'Write({arq}, {texto_de(args[2], tr)});'
    if nome == 'STDCTRLS_TCUSTOMLABEL____SETALIGNMENT_TALIGNMENT' and n == 2:
        comp, _ = componente(args[0], tr)
        alinha = {'0': 'taLeftJustify', '1': 'taRightJustify', '2': 'taCenter'}.get(args[1].strip())
        if not alinha:
            raise Falha('alinhamento desconhecido')
        return f'Form1.{comp}.Alignment := {alinha};'
    if nome == 'fpc_read_text_ansistr' and n == 2:
        arq, tipo = tr.resolve(args[0].strip())
        if tipo != 'arquivo':
            raise Falha('Read fora de arquivo texto')
        dest, td = tr.destino(args[1])
        if td != 'texto':
            raise Falha('Read em destino não texto')
        return f'Read({arq}, {dest});'
    if nome == 'fpc_shortstr_copy' and n == 4:
        ini, qtd = tr.num_de(tr.traduz(args[1])), tr.num_de(tr.traduz(args[2]))
        return _atribui(tr, args[3], f'Copy({texto_de(args[0], tr)}, {ini}, {qtd})', 'texto')
    tipados = {'OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING': 'AssignFile', 'fpc_reset_typed': 'Reset',
               'FPC_REWRITE_TYPED': 'Rewrite', 'OBJPAS_CLOSEFILE_file': 'CloseFile', 'SYSTEM_SEEK_file_INT64': 'Seek',
               'FPC_TYPED_READ': 'Read', 'FPC_TYPED_WRITE': 'Write'}
    if nome in tipados:
        arg_arq = args[1] if nome in ('FPC_TYPED_READ', 'FPC_TYPED_WRITE') else args[0]
        arq, tipo = tr.resolve(arg_arq.strip())
        if tipo != 'arqtipado':
            raise Falha('arquivo tipado desconhecido')
        rot = tipados[nome]
        if rot == 'AssignFile' and n == 2:
            return f'AssignFile({arq}, {texto_de(args[1], tr)});'
        if rot in ('Reset', 'Rewrite', 'CloseFile'):
            return f'{rot}({arq});'
        if rot == 'Seek' and n == 1:
            # a posição veio em registrador (Int64) e o Ghidra a perdeu: vem da lista POSICOES_SEEK da rotina
            if not tr.seeks:
                raise Falha('posição do Seek desconhecida')
            return f'Seek({arq}, {tr.seeks.pop(0)});  // posição: POSICOES_SEEK'
        if rot in ('Read', 'Write') and n == 3:
            buf, _ = tr.resolve(args[2].strip())
            return f'{rot}({arq}, {buf});'
        raise Falha('arquivo tipado: argumentos')
    if nome == 'fpc_ansistr_concat_multi' and n == 3:
        # (destino, &primeiro, High): os pedaços são locais seguidas na pilha, de 4 em 4 bytes para baixo
        mb = re.fullmatch(r'&(local_)([0-9a-f]+)', args[1].strip())
        if not mb or not re.fullmatch(r'\d+|0x[0-9a-f]+', args[2].strip()):
            raise Falha('concat_multi desconhecido')
        partes = []
        for i in range(int(args[2], 0) + 1):
            v = f'local_{int(mb.group(2), 16) - 4 * i:x}'
            partes.append(tr.literais[v] if v in tr.literais else texto_de(v, tr))
        return _atribui(tr, args[0], ' + '.join(partes), 'texto')
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
        tr.zeradas = [z for z in tr.zeradas if z[0] != destino]
        return _atribui(tr, destino, f'Copy({texto_de(args[0], tr)}, {ini}, {qtd})', 'texto')
    if nome == 'fpc_ansistr_copy' and n == 4:
        ini, qtd = tr.num_de(tr.traduz(args[1])), tr.num_de(tr.traduz(args[2]))
        return _atribui(tr, args[3], f'Copy({texto_de(args[0], tr)}, {ini}, {qtd})', 'texto')
    if nome == 'CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING' and n == 2:
        return _atribui(tr, args[1], _texto_de_comp(*componente(args[0], tr)), 'texto')
    if nome == 'CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING' and n == 2:
        if args[1].strip() in ('0', '0x0'):
            return f"{_texto_de_comp(*componente(args[0], tr))} := '';"
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
    if nome == 'fpc_write_text_ansistr' and n == 2 and args[0].strip() == '0' and tr.ultima_atribuida:
        # o valor ficou no registrador: é o que acabou de ser atribuído na linha anterior
        arq, tipo = tr.resolve(args[1].strip())
        valor, tipo_valor = tr.resolve(tr.ultima_atribuida)
        if tipo != 'arquivo' or tipo_valor != 'texto':
            raise Falha('write sem valor fora do padrão')
        return f'Write({arq}, {valor});'
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
        md = re.fullmatch(r'&?(local_\w+)', args[1].strip())
        mo = re.fullmatch(r'\w+', args[0].strip())
        if md and mo and tr.locais.get(md.group(1).upper()) == 'num' and md.group(1).upper() not in tr.ptrs:
            # o Ghidra declarou a local como número: ela só guarda o texto para a chamada seguinte (apelido)
            origem = tr.ptrs.get(mo.group(0).upper(), mo.group(0))
            if tr.resolve(origem)[1] != 'texto':
                raise Falha('apelido de algo que não é texto')
            tr.ptrs[md.group(1).upper()] = origem
            return f';  // apelido: {md.group(1)} = {origem}'
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
                     r' \+ (0x[0-9a-f]+|\d+)\) \+ (0x[0-9a-f]+)\)\)\s*\((.*)\);$')


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
        if vmt == '0x8c' and len(args) == 3 and not destino:        # TStrings.Put
            return f'{lista}[{tr.num_de(tr.traduz(args[1]))}] := {texto_de(args[2], tr)};'
    if vmt == '0x450' and len(args) == 1 and destino:  # TCustomCheckBox.GetChecked (RadioButton/CheckBox)
        comp, classe = componente(args[0], tr)
        if classe not in ('TRadioButton', 'TCheckBox'):
            raise Falha('Checked fora de RadioButton/CheckBox')
        nome, tipo = tr.resolve(destino)
        if tipo != 'bool':
            raise Falha('Checked em destino não Boolean')
        return f'{nome} := Form1.{comp}.Checked;'
    if obj == 'U_JUKELINUX1_FORM1' and vmt == '0x454' and len(args) == 2 and not destino:  # SetChecked
        comp, classe = componente(args[0], tr)
        if classe not in ('TRadioButton', 'TCheckBox'):
            raise Falha('Checked fora de RadioButton/CheckBox')
        v = args[1].strip()
        valor = 'True' if v == '1' or re.fullmatch(r'CONCAT31\(.*,\s*1\)', v) else \
            'False' if v == '0' or re.search(r'<< 8$|&\s*0xffffff00$', v) else None
        if valor is None:
            raise Falha('Checked: valor desconhecido')
        return f'Form1.{comp}.Checked := {valor};'
    if vmt == '0x480' and len(args) == 1 and not destino:  # TCustomListBox.Clear
        comp, classe = componente(args[0], tr)
        if classe != 'TListBox':
            raise Falha('Clear fora de ListBox')
        return f'Form1.{comp}.Clear;'
    if obj == 'U_JUKELINUX1_FORM1' and vmt == '0x430' and len(args) == 1 and not destino:  # TWinControl.SetFocus
        comp, _ = componente(args[0], tr)
        return f'Nova_Foca(Form1.{comp});'
    if obj == 'U_JUKELINUX1_FORM1' and vmt == '0xd8' and len(args) == 2 and not destino:  # TCustomTimer.SetEnabled
        comp, classe = componente(args[0], tr)
        if classe != 'TTimer':
            raise Falha('SetEnabled fora de TTimer')
        return f'Form1.{comp}.Enabled := {booleano_de_registrador(args[1])};'
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


def concat44(m, tr):
    """local_N = CONCAT44(alta, baixa): o Ghidra juntou duas locais de 4 bytes vizinhas na pilha; a baixa é a própria
    local_N e a alta é a de 4 bytes acima (local_N-4). Partes que só repetem o valor de antes não geram comando."""
    alvo, desl = m.group(1), int(m.group(2), 16)
    alta_c, baixa_c = separa_args(m.group(3))
    vizinha = f'local_{desl - 4:x}'
    comandos = []
    if not re.fullmatch(r'(\(int\))?\s*' + re.escape(alvo), baixa_c.strip()):
        comandos.append(_atribui(tr, alvo, texto_de(baixa_c, tr), 'texto'))
    if not re.fullmatch(re.escape(alvo) + r'\._4_4_', alta_c.strip()):
        comandos.append(_atribui(tr, vizinha, texto_de(alta_c, tr), 'texto'))
    if not comandos:
        raise Falha('CONCAT44 sem mudança')
    return ' '.join(comandos)


RE_REGISTRADORES = re.compile(r'(?:,\s*(?:\w+|\*\*\(int \*\* \)\(U_JUKELINUX1_FORM1 \+ (?:0x[0-9a-f]+|\d+)\)))?'
                              r'\s*,\s*Self\s*,\s*(?:Sender|uVar\d+|param_\d+)\s*\)')


def tira_registradores(c):
    """Argumentos que o Ghidra juntou ao fim de uma chamada (registradores do evento: ..., x, Self, Sender)."""
    return RE_REGISTRADORES.sub(')', c)


def comando(c, tr):
    """Traduz uma linha // C: para um comando Pascal, ou levanta Falha."""
    c = tira_registradores(c)
    # argumentos que o Ghidra juntou ao fim da chamada (registradores do evento): ,param_3,Self,Sender
    c = re.sub(r',\s*param_\d+\s*,\s*Self\s*,\s*Sender\s*\);$', ');', c)
    m = re.match(r'^(local_([0-9a-f]+)) = CONCAT44\((.*)\);$', c)
    if m:
        return concat44(m, tr)
    m = re.match(r'^(\w+) = fpc_setjmp\(\);$', c)
    if m:
        nome, tipo = tr.resolve(m.group(1))
        if tipo != 'num':
            raise Falha('setjmp em destino não numérico')
        return f'{nome} := 0;  // caminho normal do setjmp (as exceções do Pascal fazem o papel do longjmp)'

    m = VIRTUAL.match(c)
    if m:
        return virtual(m, tr)
    # mouse: posição atual (touchscreen) e posição para esconder o cursor
    m = re.match(r'^CONTROLS_TMOUSE____GETCURSORPOS__TPOINT\(U_CONTROLS_MOUSE,&(local_)([0-9a-f]+)\);$', c)
    if m:
        x, y = m.group(1) + m.group(2), f'{m.group(1)}{int(m.group(2), 16) - 4:x}'
        if tr.locais.get(x.upper()) != 'num' or tr.locais.get(y.upper()) != 'num':
            raise Falha('GetCursorPos em locais que não são números')
        # TPoint na pilha: X no endereço menor (local_c), Y logo acima (local_8)
        return f'{x} := Mouse.CursorPos.X; {y} := Mouse.CursorPos.Y;'
    if c == 'CONTROLS_TMOUSE____SETCURSORPOS_TPOINT(U_CONTROLS_MOUSE,&U_JUKELINUX1_MOUSEPOS);':
        return 'Mouse.CursorPos := MOUSEPOS;'
    m = re.match(r'^U_JUKELINUX1_MOUSEPOS\._([04])_4_ = \*\((?:undefined4|int) \* \)\(U_JUKELINUX1_FORM1 \+ (0x[0-9a-f]+)\)'
                 r'(?: \+ (-?\d+))?;$', c)
    if m:
        props = {0xe8: 'Height', 0x128: 'Left', 0x230: 'Top', 0x23c: 'Width'}  # (trocar_textos.INTERNOS)
        prop = props.get(int(m.group(2), 16))
        if not prop:
            raise Falha('propriedade do Form1 desconhecida')
        soma = f' + {m.group(3)}' if m.group(3) and not m.group(3).startswith('-') else (f' - {m.group(3)[1:]}' if m.group(3) else '')
        return f"MOUSEPOS.{'X' if m.group(1) == '0' else 'Y'} := Form1.{prop}{soma};"
    # SetFocus (vmt 0x430): só se o componente puder receber o foco agora (a original dava erro com a tela escondida)
    m = re.match(r'^\(\s*\*\*\(code\s*\*\*\s*\)\(\s*\*U_JUKELINUX1_FORM1 \+ 0x430\)\)\(U_JUKELINUX1_FORM1\);$', c)
    if m:
        return 'Nova_Foca(Form1);'
    m = re.match(r'^\(\s*\*\*\(code\s*\*\*\s*\)\((?:\s*\*\*\(int\s*\*\*\s*\)\(U_JUKELINUX1_FORM1 \+ 0x[0-9a-f]+\)|\s*\*\(int\s*\*\s*\)Form1\.\w+)'
                 r' \+ 0x430\)\)\((Form1\.\w+)\);$', c)
    if m:
        comp, _ = componente(m.group(1), tr)
        return f'Nova_Foca(Form1.{comp});'
    m = re.match(r'^U_JUKELINUX1_(\w+)\._0_2_ = 0x([0-9a-f]{2})01;$', c)
    if m and tr.globais.get(m.group(1).upper()) == 'texto':
        # String[n] curto: byte 0 = tamanho 1, byte 1 = o caractere
        return f'{m.group(1)} := {literal_pascal(chr(int(m.group(2), 16)))};'
    m = re.match(r'^(\w+) = SYSTEM_POS_CHAR_ANSISTRING__LONGINT\s*\((0x[0-9a-f]+|\d+),\s*(.+)\);$', c)
    if m:
        ch = chr(int(m.group(2), 0))
        return _atribui(tr, m.group(1), f'Pos({literal_pascal(ch)}, {texto_de(m.group(3), tr)})', 'num')
    m = re.match(r'^(\w+) = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN\s*\((Form1\.\w+),(.+)\);$', c)
    if m:
        comp, _ = componente(m.group(2), tr)
        if tr.locais.get(m.group(1).upper()) != 'bool':
            raise Falha('Selected em destino não Boolean')
        return f'{m.group(1)} := Form1.{comp}.Selected[{tr.num_de(tr.traduz(m.group(3)))}];'
    # método virtual chamado direto no objeto: ( **(code ** )( *(int * )Form1.X + VMT))(Form1.X, ...)
    m = re.match(r'^\(\s*\*\*\(code\s*\*\*\s*\)\(\s*\*\(int\s*\*\s*\)(Form1\.\w+) \+ (0x[0-9a-f]+)\)\)\s*\((.*)\);$', c)
    if m:
        comp, classe = componente(m.group(1), tr)
        args = separa_args(m.group(3))
        if m.group(2) == '0xdc' and classe == 'TTimer' and len(args) == 2 and args[0].strip() == m.group(1):
            return f'Form1.{comp}.Interval := {tr.num_de(tr.traduz(args[1]))};'
        if m.group(2) == '0x480' and classe == 'TListBox' and len(args) == 1 and args[0].strip() == m.group(1):
            return f'Form1.{comp}.Clear;'
        raise Falha('método virtual direto desconhecido')
    m = re.match(r'^(\w+) = SYSTEM_EOF_file__BOOLEAN\((U_JUKELINUX1_\w+)\);$', c)
    if m:
        arq, tipo = tr.resolve(m.group(2))
        if tipo != 'arqtipado' or tr.locais.get(m.group(1).upper()) != 'bool':
            raise Falha('Eof desconhecido')
        return f'{m.group(1)} := Eof({arq});'
    m = CHAMADA.match(c)
    if m and m.group(2) in tr.rotinas and fecha_no_fim('(' + m.group(3) + ')'):
        return chamada_rotina(m.group(2), separa_args(m.group(3)), m.group(1), tr)
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
    m = re.match(r'^([A-Za-z_]\w*|[^=;]*?\b0x90\b[^=;]*?|[^=;]*?\b0x240\b[^=;]*?'
                 r'|U_JUKELINUX1_MMCARTAO\[[^=;]*?\]|[^=;]*?(?:&DAT_|\* [48] \+ (?:0x|-?\d)|\)\s*\[|\b0x26\b|U_JUKELINUX1_ACARM\[|U_JUKELINUX1_ARQLOG|0x8e9[0-9a-f]+)[^=;]*?)'
                 r' = (.+);$', c)
    if m:
        if m.group(1).upper() in tr.ptrs and m.group(1).upper() not in tr.locais:
            raise Falha('apelido de ponteiro (puVar = x) não é atribuição')
        # destino: variável simples ou campo do acervo ((&G)[i*0x90 + k], ARQLOG + i*0x240 + c, ...)
        nome, tipo = tr.destino(m.group(1))
        e = tr.traduz(m.group(2))
        if e[1] in ('zero', 'nulo') or (e[0] == '0' and tipo == 'texto'):
            v = tr.vazio_para(tipo)
            if v is None:
                raise Falha('vazio para ' + str(tipo))
            return f'{nome} := {v};'
        if e[1] != tipo and not (tipo == 'texto' and e[1] == 'char'):
            raise Falha(f'atribuição de {e[1]} a {tipo}')
        if nome == e[0]:
            return ';  // apelido (a variável já é ela mesma)'
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


def _separa_topo(s, sep):
    """Divide s em sep (',' ou '&&') fora de parênteses, colchetes e aspas."""
    partes, prof, atual, i, aspas = [], 0, '', 0, False
    while i < len(s):
        ch = s[i]
        if ch == '"' and (i == 0 or s[i - 1] != '\\'):
            aspas = not aspas
        if not aspas and prof == 0 and s.startswith(sep, i):
            partes.append(atual.strip())
            atual = ''
            i += len(sep)
            continue
        if not aspas:
            prof += {'(': 1, '[': 1, ')': -1, ']': -1}.get(ch, 0)
        atual += ch
        i += 1
    partes.append(atual.strip())
    return partes


def _tira_parenteses(s):
    s = s.strip()
    while s.startswith('(') and s.endswith(')') and fecha_no_fim(s):
        s = s[1:-1].strip()
    return s


RE_IF_LINHA = re.compile(r'^(\s*)if False \{ C: (.*) \} then begin\s*$')
NOVA_COND = 'NovaCond'


def condicao_com_virgula(ind, c, tr):
    """`A && (x = x + 1, x == 2)`: o operador vírgula do C executa comandos no meio da condição. Vira uma
    sequência de comandos que guarda o resultado em NovaCond, respeitando o curto-circuito do &&, e o if testa
    NovaCond. Devolve as linhas, ou levanta Falha."""
    termos = _separa_topo(c, '&&')
    if not any(len(_separa_topo(_tira_parenteses(t), ',')) > 1 for t in termos):
        raise Falha('sem operador vírgula')
    linhas = []
    for n, termo in enumerate(termos):
        partes = _separa_topo(_tira_parenteses(termo), ',')
        cmds = []
        for p in partes[:-1]:
            if re.fullmatch(r'\w+ = extraout_\w+', p):
                continue  # registrador que o Ghidra guardou: não é comando do programa
            cmds.append(comando(p + ';', tr))
        teste = tr.bool_de(tr.traduz(partes[-1]))
        corpo = cmds + [f'{NOVA_COND} := {teste};']
        if n == 0:
            linhas += [ind + x for x in corpo]
        else:
            linhas.append(f'{ind}if {NOVA_COND} then begin')
            linhas += [ind + '  ' + x for x in corpo]
            linhas.append(f'{ind}end;')
    linhas.append(f'{ind}if {NOVA_COND} then begin  // C convertido (operador vírgula): {c}')
    return linhas


def declara_nova_cond(texto):
    if NOVA_COND + ' :=' not in texto or re.search(r'\b' + NOVA_COND + r': Boolean;', texto):
        return texto
    corpo = re.search(r'\nvar\n(.*?)\nbegin\n', texto, re.S)
    if not corpo:
        return texto
    decl = f'  {NOVA_COND}: Boolean;  // completar: condição com operador vírgula do C'
    return texto[:corpo.end(1)] + '\n' + decl + texto[corpo.end(1):]


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


def devolve_resultado(texto):
    """Função que devolve texto e em que o Ghidra trocou o resultado por uma local (local_c := Result no começo e
    nenhum Result := depois): a local é o resultado, então ela é devolvida no fim."""
    cab = texto.split('\n', 1)[0]
    m = re.search(r'^\s*(local_\w+) := Result;\s*$', texto, re.M)
    if not cab.startswith('function') or not cab.rstrip().endswith('AnsiString;') or not m \
            or re.search(r'\bResult :=', texto) or re.search(r'\bExit\b', texto):
        return texto
    fim = texto.rstrip().rfind('\nend;')
    if fim < 0:
        return texto
    return (texto[:fim] + f'\n  Result := {m.group(1)};  // completar: {m.group(1)} é o resultado (ponteiro do C)'
            + texto[fim:])

def registro_do_cartao(texto):
    """`ACARM := x;` / `ACARV := x;`: logo depois de `x := '';` é leitura do registro lido do arquivo (o tradutor
    inverteu: x := ACARM.Codigo); senão é gravação do código no registro."""
    linhas = texto.split('\n')
    for i, linha in enumerate(linhas):
        m = re.match(r'^(\s*)(ACARM|ACARV) := (\w+);(.*)$', linha)
        if not m:
            continue
        alvo = 'ACARM.Codigo' if m.group(2) == 'ACARM' else 'ACARV'
        if i and re.match(r'^\s*' + m.group(3) + r" := '';\s*$", linhas[i - 1]):
            linhas[i] = f'{m.group(1)}{m.group(3)} := {alvo};  // completar: leitura do registro do cartão'
        elif m.group(2) == 'ACARM':
            linhas[i] = f'{m.group(1)}ACARM.Codigo := {m.group(3)};{m.group(4)}'
    return '\n'.join(linhas)

RE_VETOR_LOCAL = re.compile(r'\b(local_[0-9a-f]+) \+ [\w()+ -]+? \* 4 \+ (?:0x[0-9a-f]+|-?\d+)')


def vetores_locais(texto):
    """Vetor de textos na pilha do C (local_x + i * 4 + k, com local_x sem ser texto): declara NovaVet_x."""
    locais = le_locais(texto)
    bases = {m.group(1) for linha in texto.split('\n') if re.match(r'^\s*// C: ', linha)
             for m in RE_VETOR_LOCAL.finditer(linha) if locais.get(m.group(1).upper()) != 'texto'}
    corpo = re.search(r'\nvar\n(.*?)\nbegin\n', texto, re.S)
    if not bases or not corpo:
        return texto, bases
    novas = [f'  NovaVet_{b[6:]}: array[-4..4999] of AnsiString;  // completar: vetor de textos na pilha ({b} + i * 4)'
             for b in sorted(bases) if f'NovaVet_{b[6:]}:' not in texto]
    if novas:
        texto = texto[:corpo.end(1)] + '\n' + '\n'.join(novas) + texto[corpo.end(1):]
    return texto, bases

RE_REPAINT = re.compile(r'^(\s*)// C: \(\s*\*\*\(code \*\* \)\((?:\s*\*\(int \* \)(Form1\.\w+)|\s*\*U_JUKELINUX1_FORM1'
                        r'|\s*\*\*\(int \*\* \)\(U_JUKELINUX1_FORM1 \+ 0x[0-9a-f]+\)) \+ 0x2fc\)\)\s*\((Form1\.\w+|U_JUKELINUX1_FORM1)\);$')
RUIDO = [
    re.compile(r'^\s*// C: fpc_ansistr_(incr|decr)_ref'),                     # contagem de referência do AnsiString
    re.compile(r'^\s*// C: local_\w+\[0\] = (\((?:undefined1?|char) \* \))?0x0;$'),  # zerar temporária antes de usar
    re.compile(r'^\s*// C: local_\w+ = "(?:[^"\\\\]|\\\\.)*";$'),          # literal já usado num concat_multi
    re.compile(r'^\s*// C: a[ci]Stack_\w+\[0\] = 0;$'),                        # idem, nos vetores da pilha reescritos à mão
    re.compile(r'^\s*// C: fpc_ansistr_concat\(&?(local_\w+),&?\1(\[0\])?\);$'),  # concat de um texto com ele mesmo
    re.compile(r'^\s*// C: DEBUGSTART'),
    re.compile(r'^\s*// C: \w+ = (extraout_\w+|Sender);$'),                  # registrador guardado de passagem
]


def limpa_ruido(texto):
    """Tira as linhas // C: que não fazem nada no Pascal e converte o Repaint (vmt 0x2fc) em Refresh: quando o
    Refresh já está na linha de cima (o gerador escreveu os dois), a linha C sai."""
    linhas = texto.split('\n')
    apelido = re.compile(r'^\s*// C: (p[a-z]*Var\d+) = [&\w]+(\[0\])?;$')
    # linhas C que ficam e não são só a definição de um apelido: é nelas que um apelido pode ser usado
    ainda_c = '\n'.join(l for l in linhas if re.match(r'^\s*// C: ', l) and not apelido.match(l)
                         and not any(r.match(l) for r in RUIDO))
    saida = []
    for linha in linhas:
        if any(r.match(linha) for r in RUIDO):
            continue
        m = apelido.match(linha)
        if m and not re.search(r'\b' + m.group(1) + r'\b', ainda_c):
            continue  # apelido de ponteiro que nenhuma linha C que ficou usa
        m = RE_REPAINT.match(linha)
        if m:
            alvo = m.group(3)
            comp = 'FORM1' if alvo == 'U_JUKELINUX1_FORM1' else alvo
            anterior = next((l for l in reversed(saida) if l.strip()), '')
            if anterior.strip().startswith(comp + '.Refresh;'):
                continue
            linha = f'{m.group(1)}{comp}.Refresh;  // C convertido: Repaint (vmt 0x2fc)'
        saida.append(linha)
    return '\n'.join(saida)

def retipa_textos(texto):
    """Local que recebe o texto de um componente (CONTROLS_TCONTROL____GETTEXT) ou de um fpc_shortstr_copy mas que o
    Ghidra declarou como número (e por isso é zerada com := 0): vira AnsiString, e o := 0 vira := ''."""
    temps = set(re.findall(r'GETTEXT__TTRANSLATESTRING\s*\(Form1\.\w+,\s*&?(local_\w+)\)', texto))
    # buffer de texto curto (fpc_shortstr_copy(origem, i, n, buffer)) que o Ghidra declarou como número
    temps |= set(re.findall(r'fpc_shortstr_copy\s*\([^;]*,\s*&?(local_\w+)\);', texto))
    corpo = re.search(r'\nvar\n(.*?)\nbegin\n', texto, re.S)
    if not temps or not corpo:
        return texto
    nums = set()
    for linha in corpo.group(1).split('\n'):
        m = re.match(r'\s+([\w, ]+): (LongInt|Integer|Cardinal|Byte);', linha)
        if m:
            nums |= {n.strip() for n in m.group(1).split(',')}
    temps &= nums
    if not temps:
        return texto
    linhas = []
    for linha in corpo.group(1).split('\n'):
        m = re.match(r'(\s+)([\w, ]+): (.+);$', linha)
        if m and m.group(3) in ('LongInt', 'Integer', 'Cardinal', 'Byte'):
            nomes = [n.strip() for n in m.group(2).split(',') if n.strip() not in temps]
            if not nomes:
                continue
            linha = f'{m.group(1)}{", ".join(nomes)}: {m.group(3)};'
        linhas.append(linha)
    linhas += [f'  {t}: AnsiString;  // completar: guarda texto (o Ghidra a declarou como número)' for t in sorted(temps)]
    texto = texto[:corpo.start(1)] + '\n'.join(linhas) + texto[corpo.end(1):]
    for t in temps:
        texto = re.sub(r'^(\s*)' + t + r' := 0;', r"\1" + t + " := '';", texto, flags=re.M)
    return texto


# Contas em ponto flutuante (x87) que o Ghidra perdeu: os divisores sumiram, mas o padrão é sempre o mesmo.
def _re_horas(primeira):
    return re.compile(
        primeira +
        r"[ ]*// C: SYSUTILS_FLOATTOSTR_EXTENDED__ANSISTRING\(&?(?P<d>\w+)\);\n"
        r"[ ]*(?P=s) := (?P=d);\n"
        r"[ ]*(?:(?P=d) := '';|// C: (?P=d)\[0\] = \(char \* \)0x0;)\n"
        r"[ ]*// C: \w+ = SUB42\([^\n]*\n"
        r"[ ]*// C: \w+ = SYSTEM_POS_CHAR_ANSISTRING__LONGINT[^\n]*\n"
        r"[ ]*\w+ := Copy\((?P=s), 1, \w+ \+ 2\);\n"
        r"[ ]*(?P=s) := (?P=d);\n")


# Contas em ponto flutuante (x87) que o Ghidra perdeu: os divisores sumiram, mas o padrão é sempre o mesmo.
RE_HORAS = [
    _re_horas(r"(?P<ind>[ ]*)// C: \w+ = \([^)]*\) ?SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT ?"
              r"\(U_JUKELINUX1_(?P<s>\w+),0\);\n"),
    _re_horas(r"(?P<ind>[ ]*)\w+ := StrToIntDef\((?P<s>\w+), 0\);\n"),
]
RE_PONTO = re.compile(
    r"(?P<ind>[ ]*)// \?: (?P<v>\w+) := \(longlong\) ROUND\(\(float10\)PORCENTAGEMDOPONTO \* "
    r"\(\(float10\)RELOGIOPARCIAL div ''\)\);\n"
    r"[ ]*// C: U_JUKELINUX1_VALORPONTO = \(int\)(?P=v);\n")


def contas_flutuantes(texto):
    """Horas ligadas (minutos / 60, até 2 casas) e valor do ponto (% do ponto sobre o relógio parcial)."""
    for rx in RE_HORAS:
        texto = rx.sub(lambda m: f"{m['ind']}// Nova: minutos -> horas (conta em ponto flutuante da original)\n"
                                 f"{m['ind']}{m['s']} := Nova_Horas(StrToIntDef({m['s']}, 0));\n", texto)
    texto = RE_PONTO.sub(lambda m: f"{m['ind']}VALORPONTO := Round(PORCENTAGEMDOPONTO * (RELOGIOPARCIAL / 100));"
                                   f"  // Nova: valor do ponto (conta em ponto flutuante da original)\n", texto)
    return texto


# NOMEMUSICAORIGINALGRANDE é um vetor de 40 AnsiString (160 bytes em 0x09301dc0): a posição 1 o Ghidra chamou pelo
# nome, as seguintes de DAT_09301dc4, DAT_09301dc8, ... (o nome original de cada uma das 12 músicas da tela).
NOME_GRANDE = 'NOMEMUSICAORIGINALGRANDE'
END_NOME_GRANDE = 0x09301dc0


def _pos_grande(m):
    return (int(m, 16) - END_NOME_GRANDE) // 4 + 1


def vetor_nome_grande(texto):
    rx = r'DAT_(09301d[0-9a-f]{2})'
    v = lambda m: f'{NOME_GRANDE}[{_pos_grande(m)}]'
    # posição 1: o nome sem índice, só no Pascal (o comentário C fica como está)
    linhas = []
    for linha in texto.split('\n'):
        if not re.match(r'^\s*//', linha):
            codigo, sep, coment = linha.partition('//')
            for nome_v in (NOME_GRANDE,) + VETORES_NOME_E_POS1:
                codigo = re.sub(r'\b' + nome_v + r'\b(?!\[)', nome_v + '[1]', codigo)
            linha = codigo + sep + coment
        linhas.append(linha)
    texto = '\n'.join(linhas)
    texto = re.sub(r'^(\s*)// C: ' + rx + r' = (local_\w+)\[0\];$',
                   lambda m: f'{m[1]}{v(m[2])} := {m[3]};  // C convertido: DAT_{m[2]} = {m[3]}[0];', texto, flags=re.M)
    texto = re.sub(r'if False \{ C: ' + rx + r' != 0 \} then',
                   lambda m: f"if {v(m[1])} <> '' {{ C convertido: DAT_{m[1]} != 0 }} then", texto)
    texto = re.sub(r'^(\s*)// C: (\w+) = \*\(int \* \)\(' + rx + r' \+ -4\);$',
                   lambda m: f'{m[1]}{m[2]} := Length({v(m[3])});  // C convertido: tamanho de DAT_{m[3]}', texto, flags=re.M)
    texto = re.sub(r'^(\s*)// C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING \(Form1\.(\w+),' + rx + r'\);$',
                   lambda m: f'{m[1]}Form1.{m[2]}.Caption := {v(m[3])};  // C convertido: SetText(Form1.{m[2]}, DAT_{m[3]})',
                   texto, flags=re.M)
    return texto


def completa_rotina(texto, globais, estatistica=None, comps=None, rotinas=None):
    texto = retipa_temporarias_cd(texto)
    texto = retipa_textos(texto)
    texto = devolve_resultado(texto)
    texto = registro_do_cartao(texto)
    texto = contas_flutuantes(texto)
    # a posição 1 do vetor se traduz como texto comum; vetor_nome_grande põe o [1] no fim
    globais = dict(globais, **{n: 'texto' for n in (NOME_GRANDE,) + VETORES_NOME_E_POS1})
    texto, vetlocais = vetores_locais(texto)
    tr = Tradutor(globais, le_locais(texto), comps)
    tr.vetlocais = vetlocais
    tr.rotinas = rotinas or {}
    mr = re.match(r'(?:procedure|function) ([\w.]+)', texto)
    tr.seeks = list(POSICOES_SEEK.get(mr.group(1), [])) if mr else []
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
        m = re.match(r'^\s*// C: (local_[0-9a-f]+) = ("(?:[^"\\\\]|\\\\.)*");\s*$', linha)
        if m:
            tr.literais[m.group(1)] = tr.traduz(m.group(2))[0]
        m = RE_PONTEIRO.match(linha)
        if m:
            tr.ptrs[m.group(1).upper()] = m.group(2)
        # puVar5 = local_13c: temporária do Ghidra que só aponta para o texto (PChar de um AnsiString)
        m = re.match(r'^\s*// C: (pu?[a-z]*Var\d+) = (local_\w+|U_JUKELINUX1_\w+)(?:\[0\])?;\s*$', linha)
        if m and m.group(1).upper() not in tr.locais:
            tr.ptrs[m.group(1).upper()] = m.group(2)
        # uVar1 = local_354 com uVar1 declarada como número e local_354 texto: o registrador só leva o texto
        m = re.match(r'^\s*// C: ([a-z]{0,3}Var\d+) = (local_\w+)(?:\[0\])?;\s*$', linha)
        if m and tr.locais.get(m.group(1).upper()) in ('num', 'char') and (
                tr.locais.get(m.group(2).upper()) == 'texto' or m.group(2).upper() in tr.ptrs):
            tr.ptrs[m.group(1).upper()] = tr.ptrs.get(m.group(2).upper(), m.group(2))
        # atribuição Pascal a um apelido: ele volta a ser a própria variável
        m = re.match(r'^\s*(\w+) := ', linha)
        if m and m.group(1).upper() in tr.ptrs and m.group(1).upper() in tr.locais:
            del tr.ptrs[m.group(1).upper()]
        m = re.match(r'^\s*(\w+) := (.+) \* 576;\s*$', linha)
        if m:
            tr.mult[m.group(1).upper()] = m.group(2)
        # `// ?: SERIAL + i * 144 := local_x;` logo depois de `local_x := '';`: o tradutor inverteu a leitura de um
        # campo do CD (fpc_shortstr_to_ansistr / fpc_ansistr_assign com o campo como origem).
        m = re.match(r"^(\s*)// \?: (\w+) \+ (\(\w+ \+ \d+\)|\w+) \* 144 := (\w+);\s*$", linha)
        if m and m.group(2) in GLOBAL_NO_CD and saida and \
                re.match(r"^\s*" + re.escape(m.group(4)) + r" := '';\s*$", saida[-1]):
            campo, tipo = campo_cd(GLOBAL_NO_CD[m.group(2)])
            if tipo == 'texto':
                linha = (f'{m.group(1)}{m.group(4)} := MAT[{m.group(3)}].{campo};'
                         f'  // ? convertido (leitura do campo do CD): {linha.strip()[6:]}')
                est['talvez_convertido'] = est.get('talvez_convertido', 0) + 1
        # `// ?: WX := TC_FORMS_SCREEN.Width;` (Screen da LCL) e `// ?: ShowMessage('...');` (texto fixo)
        m = re.match(r"^(\s*)// \?: (\w+) := TC_FORMS_SCREEN\.(Width|Height);\s*$", linha)
        if m and tr.resolve(m.group(2))[1] == 'num':
            linha = f'{m.group(1)}{m.group(2)} := Screen.{m.group(3)};  // ? convertido: {linha.strip()[6:]}'
            est['talvez_convertido'] = est.get('talvez_convertido', 0) + 1
        m = re.match(r"^(\s*)// \?: (ShowMessage\('(?:''|[^'])*'\);)\s*$", linha)
        if m:
            linha = f'{m.group(1)}{m.group(2)}  // ? convertido'
            est['talvez_convertido'] = est.get('talvez_convertido', 0) + 1
        # `// ?: local_1b0 + i * 4 + 12 := valor;`: escrita num vetor de textos da pilha (NovaVet_1b0)
        m = re.match(r"^(\s*)// \?: (local_[0-9a-f]+) \+ (.+?) \* 4 \+ (-?\d+) := (.+);\s*$", linha)
        if m and m.group(2) in tr.vetlocais:
            try:
                valor = tr.traduz(pascal_para_c(m.group(5)))
                idx = tr.num_de(tr.traduz(pascal_para_c(m.group(3))))
                if valor[1] != 'texto':
                    raise Falha('vetor de textos')
                k = int(m.group(4)) // 4
                pos = f'{idx}{" + " + str(k) if k > 0 else " - " + str(-k) if k else ""}'
                linha = f'{m.group(1)}NovaVet_{m.group(2)[6:]}[{pos}] := {valor[0]};  // ? convertido: {linha.strip()[6:]}'
                est['talvez_convertido'] = est.get('talvez_convertido', 0) + 1
            except Falha:
                pass
        # `// ?: TOTALPRO + KPRO := valor;`: escrita num vetor de VETORES_GLOBAIS acessado pela global de antes.
        m = re.match(r"^(\s*)// \?: (\w+) \+ (\w+) := (.+);\s*$", linha)
        antes = {v[2]: k for k, v in VETORES_GLOBAIS.items() if v[2]}
        if m and m.group(2) in antes:
            nome_v = antes[m.group(2)]
            try:
                valor = tr.traduz(pascal_para_c(m.group(4)))
                idx = tr.num_de(tr.traduz(pascal_para_c(m.group(3))))
                if valor[1] != VETORES_GLOBAIS[nome_v][0]:
                    raise Falha('tipo do vetor')
                linha = f'{m.group(1)}{nome_v}[{idx}] := {valor[0]};  // ? convertido: {linha.strip()[6:]}'
                est['talvez_convertido'] = est.get('talvez_convertido', 0) + 1
            except Falha:
                pass
        m = RE_TALVEZ.match(linha)
        if m:
            try:
                cond = tr.bool_de(tr.traduz(pascal_para_c(m.group(2))))
                linha = f'{m.group(1)}if {cond} then begin // ? convertido: {m.group(2)}'
                est['talvez_convertido'] = est.get('talvez_convertido', 0) + 1
            except Falha:
                est['talvez_ficou'] = est.get('talvez_ficou', 0) + 1
        linha = RE_IF.sub(troca_if, linha)
        m = RE_IF_LINHA.match(linha)
        if m and not re.search(r'\belse\s*$', saida[-1] if saida else ''):
            try:
                saida += condicao_com_virgula(m.group(1), m.group(2), tr)
                est['virgula_convertido'] = est.get('virgula_convertido', 0) + 1
                continue
            except Falha:
                pass
        # Última variável zerada (X := '') que nenhuma linha Pascal usou depois: destino perdido de um Copy.
        # (guarda todas as zeradas ainda não usadas: o destino pode ser uma zerada antes de outra)
        # (só temporárias locais, zeradas há no máximo 12 linhas)
        n_linha = len(saida)
        mz = re.match(r"^\s*((?:local|[iu]Stack)_\w+) := '';\s*$", linha)
        if mz:
            tr.zeradas = [z for z in tr.zeradas if z[0] != mz.group(1)] + [(mz.group(1), n_linha)]
        elif tr.zeradas and not re.match(r'^\s*//', linha):
            codigo = linha.split('//')[0]
            tr.zeradas = [z for z in tr.zeradas if not re.search(r'\b' + re.escape(z[0]) + r'\b', codigo)]
        tr.zeradas = [z for z in tr.zeradas if n_linha - z[1] <= 12]
        tr.zerada = tr.zeradas[-1][0] if tr.zeradas else None
        if not re.match(r'^\s*//', linha):
            ma = re.match(r'^\s*(\w+) := [^;]+;', linha)
            tr.ultima_atribuida = ma.group(1) if ma else None
        m = RE_LINHA_C.match(linha)
        if m:
            try:
                novo = comando(m.group(2).strip(), tr)
                linha = f'{m.group(1)}{novo}  // C convertido: {m.group(2).strip()}'
                est['cmd_convertido'] = est.get('cmd_convertido', 0) + 1
            except Falha:
                pass
        saida.append(linha)
    texto = limpa_ruido(vetor_nome_grande(declara_nova_cond('\n'.join(saida))))
    # imagens: a Nova mostra o nome no lugar de uma imagem que falta, em vez de parar a tela com erro (nova.inc)
    return re.sub(r'\b(Form1\.\w+)\.Picture\.LoadFromFile\((.+?)\);', r'Nova_Carrega_Imagem(\1.Picture, \2);', texto)


TIPO_PARAM = {'ansistring': 'texto', 'longint': 'num', 'integer': 'num', 'byte': 'num', 'boolean': 'bool'}


def le_rotinas(texto):
    """Rotinas do próprio programa: nome do Ghidra (JUKELINUX1_X_ANSISTRING__ANSISTRING) -> (nome Pascal, tipos dos
    parâmetros, tipo do resultado ou None), pelos comentários { JUKELINUX1_X$ANSISTRING$$ANSISTRING } dos cabeçalhos."""
    rotinas = {}
    for m in re.finditer(r'\{ (JUKELINUX1_TFORM1_\$__(\w+)\$TOBJECT) \}\nprocedure TForm1\.(\w+)\(Sender: TObject\);', texto):
        # evento do formulário chamado direto (JUKELINUX1_TFORM1____X_TOBJECT(Form1, Sender))
        rotinas[m.group(1).replace('$', '_')] = ('Form1.' + m.group(3), ['evento'], None)
    for m in re.finditer(r'\{ (JUKELINUX1_[\w$]+) \}\n(procedure|function) (\w+)(?:\(([^)]*)\))?(?:: (\w+))?;', texto):
        tipos = []
        for grupo in (m.group(4) or '').split(';'):
            if ':' not in grupo:
                continue
            nomes, tipo = grupo.split(':')
            t = TIPO_PARAM.get(tipo.strip().lower())
            if t is None:
                break
            tipos += [t] * len(nomes.split(','))
        else:
            res = TIPO_PARAM.get((m.group(5) or '').lower()) if m.group(5) else None
            if m.group(5) and res is None:
                continue
            rotinas[m.group(1).replace('$$', '__').replace('$', '_')] = (m.group(3), tipos, res)
    return rotinas


def chamada_rotina(nome, args, destino, tr):
    """Chamada de uma rotina do próprio programa. Função que devolve texto: o resultado vem no último argumento."""
    pascal, tipos, res = tr.rotinas[nome]
    if tipos == ['evento']:
        if len(args) != 2 or destino:
            raise Falha('evento com argumentos')
        return f'{pascal}(Form1);'
    # argumentos de registrador que o Ghidra juntou no fim (Sender, Self, param_n)
    esperado = len(tipos) + (1 if res == 'texto' and not destino else 0)
    while len(args) > esperado and re.fullmatch(r'Sender|Self|param_\d+|extraout_\w+', args[-1].strip()):
        args = args[:-1]
    if res == 'texto' and not destino:
        if len(args) != len(tipos) + 1:
            raise Falha('argumentos da rotina')
        args, dest = args[:-1], args[-1]
    elif len(args) != len(tipos):
        raise Falha('argumentos da rotina')
    valores = []
    for a, t in zip(args, tipos):
        e = tr.traduz(a)
        if e[1] in ('zero', 'nulo') and t in ('texto', 'num'):
            e = (tr.vazio_para(t), t)
        if e[1] != t and not (t == 'texto' and e[1] == 'char'):
            raise Falha(f'argumento {e[1]} para {t}')
        valores.append(e[0])
    texto_chamada = pascal + (f'({", ".join(valores)})' if valores else '')
    if res == 'texto' and not destino:
        return _atribui(tr, dest, texto_chamada, 'texto')
    if destino:
        if res is None:
            raise Falha('procedimento com resultado')
        return _atribui(tr, destino, texto_chamada, res)
    return texto_chamada + ';'


def completa_arquivo(globais_inc, rotinas_inc, form_inc=None):
    globais = le_globais(globais_inc)
    import os
    form_inc = form_inc or os.path.join(os.path.dirname(rotinas_inc), 'jukelinux1_form.inc')
    comps = le_componentes(form_inc) if os.path.exists(form_inc) else {}
    texto = open(rotinas_inc, encoding='utf-8').read()
    # cabeçalhos: com parâmetros "(", sem parâmetros ";" e funções sem parâmetros ": Tipo;"
    partes = re.split(r'\n(?=(?:procedure|function) [\w.]+\s*[(:;])', texto)
    rotinas = le_rotinas(texto)
    est = {}
    novas = []
    for p in partes:
        if re.match(r'(procedure|function) ', p) and not p.split('\n', 1)[0].endswith('forward;'):
            p = completa_rotina(p, globais, est, comps, rotinas)
        novas.append(p)
    open(rotinas_inc, 'w', encoding='utf-8', newline='\n').write('\n'.join(novas))
    return est


if __name__ == '__main__':
    est = completa_arquivo(sys.argv[1], sys.argv[2], sys.argv[3] if len(sys.argv) > 3 else None)
    print(f"condições convertidas: {est.get('if_convertido', 0)} (ficaram {est.get('if_ficou', 0)}); "
          f"incertas convertidas: {est.get('talvez_convertido', 0)} (ficaram {est.get('talvez_ficou', 0)}); "
          f"comandos convertidos: {est.get('cmd_convertido', 0)}")
