"""Tradutor do C descompilado (já passado por trocar_textos.py) para Pascal, para o subconjunto que a original usa
nas rotinas de tela e de configuração: posições e tamanhos, Show/Hide/BringToFront, textos, imagens, Enabled dos
timers, arquivos de texto (AssignFile/Reset/Readln...), rotinas do FPC (IntToStr, FileExists...), chamadas das
próprias rotinas da JukeLinux (nomes do funcoes.txt), comparações de texto, if/else e atribuições.

O que não reconhece sai como comentário "// C: ..." no ponto exato, para completar à mão. O resultado é um ponto de
partida revisado à mão, não código final.

Uso: python transpilar.py funcao.c funcoes.txt [NomePascal] > saida.pas
"""
import re
import sys

nomes_juke = []
textos, locais, globais, rotulos = [], set(), set(), set()
texto_certo = set()  # locais que com certeza são texto (destino e pedaços de concatenação)


def carregar_nomes(funcoes_txt):
    nomes_juke[:] = [re.sub(r'\(.*', '', l.split(None, 2)[2]).strip()
                     for l in open(funcoes_txt, encoding='utf-8') if l.startswith('0x')]


def guarda(m):
    textos.append(m.group(0))
    return f'@T{len(textos) - 1}@'




def texto_pas(i):
    t = textos[int(i)]
    if t.startswith("'"):  # char C
        c = t[1:-1]
        esc = {'\\0': '#0', '\\x01': '#1', '\\n': '#10', '\\r': '#13', '\\t': '#9', '\\b': '#8', '\\a': '#7', '\\f': '#12', '\\v': '#11', "\\'": "''''", '\\\\': "'\\'"}
        if c in esc:
            return esc[c]
        if c.startswith('\\x'):
            return '#' + str(int(c[2:], 16))
        return "'" + c.replace("'", "''") + "'"
    s = t[1:-1].replace('\\"', '"').replace('\\\\', '\\').replace("'", "''")
    s = s.replace('\\n', "'#10'").replace('\\r', "'#13'")
    return "'" + s + "'"


# --- tabelas ---------------------------------------------------------------------------------------------------
VIRTUAIS = {0xd8: 'Enabled', 0x104: 'Align', 0x10c: 'AutoSize', 0x220: 'Visible'}
ALIGN = {0: 'alNone', 1: 'alTop', 2: 'alBottom', 3: 'alLeft', 4: 'alRight', 5: 'alClient', 6: 'alCustom'}
PROPS = {'SETLEFT': 'Left', 'SETTOP': 'Top', 'SETWIDTH': 'Width', 'SETHEIGHT': 'Height'}
# Rotinas do FPC/LCL: nome Ghidra -> (nome Pascal, tipo). Tipos: p = procedimento, f = função (valor de retorno),
# s = função que devolve string pelo último argumento (&destino).
RTL = {
    'SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN': ('FileExists', 'f'),
    'SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN': ('DirectoryExists', 'f'),
    'SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN': ('DeleteFile', 'f'),
    'SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN': ('CreateDir', 'f'),
    'SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT': ('StrToIntDef', 'f'),
    'SYSUTILS_STRTOINT_ANSISTRING__LONGINT': ('StrToInt', 'f'),
    'SYSUTILS_INTTOSTR_LONGINT__ANSISTRING': ('IntToStr', 's'),
    'SYSUTILS_INTTOSTR_INT64__ANSISTRING': ('IntToStr', 's'),
    'SYSUTILS_TRIM_ANSISTRING__ANSISTRING': ('Trim', 's'),
    'SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING': ('UpperCase', 's'),
    'SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING': ('LowerCase', 's'),
    'SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING': ('TimeToStr', 's'),
    'SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING': ('DateToStr', 's'),
    'SYSUTILS_TIME__TDATETIME': ('Time', 'f'),
    'SYSUTILS_DATE__TDATETIME': ('Date', 'f'),
    'SYSUTILS_NOW__TDATETIME': ('Now', 'f'),
    'SYSUTILS_SLEEP_LONGWORD': ('Sleep', 'p'),
    'SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT': ('Pos', 'f'),
    'SYSTEM_EOF_TEXT__BOOLEAN': ('Eof', 'f'),
    'SYSTEM_RESET_TEXT': ('Reset', 'p'),
    'SYSTEM_REWRITE_TEXT': ('Rewrite', 'p'),
    'SYSTEM_APPEND_TEXT': ('Append', 'p'),
    'SYSTEM_FLUSH_TEXT': ('Flush', 'p'),
    'OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING': ('AssignFile', 'p'),
    'OBJPAS_CLOSEFILE_TEXT': ('CloseFile', 'p'),
    'DIALOGS_SHOWMESSAGE_ANSISTRING': ('ShowMessage', 'p'),
    'fpc_readln_end': ('Readln', 'p'),
    'fpc_writeln_end': ('Writeln', 'p'),
    'fpc_read_text_ansistr': ('Read', 'r'),
    'FORMS_TCUSTOMFORM____CLOSE': ('Close', 'm'),
    'SYSTEM_TOBJECT____FREE': ('Free', 'm'),
    'CONTROLS_TCONTROL____SHOW': ('Show', 'm'),
    'CONTROLS_TCONTROL____HIDE': ('Hide', 'm'),
    'CONTROLS_TCONTROL____BRINGTOFRONT': ('BringToFront', 'm'),
    'CONTROLS_TCONTROL____SENDTOBACK': ('SendToBack', 'm'),
    'CONTROLS_TCONTROL____REPAINT': ('Repaint', 'm'),
    'CONTROLS_TWINCONTROL____SETFOCUS': ('SetFocus', 'm'),
    'FORMS_TSCREEN____GETWIDTH__LONGINT': ('Width', 'g'),
    'FORMS_TSCREEN____GETHEIGHT__LONGINT': ('Height', 'g'),
    'STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT': ('Count', 'g'),
    'STDCTRLS_TCUSTOMCOMBOBOX____GETITEMINDEX__LONGINT': ('ItemIndex', 'g'),
    'CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING': ('Caption', 'g'),
    'CONTROLS_TCONTROL____REFRESH': ('Refresh', 'm'),
    'CONTROLS_TCONTROL____INVALIDATE': ('Invalidate', 'm'),
    'CONTROLS_TCONTROL____UPDATE': ('Update', 'm'),
    'GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR': ('Color', 'a'),
    'GRAPHICS_TFONT____SETSIZE_LONGINT': ('Size', 'a'),
    'GRAPHICS_TFONT____SETNAME_ANSISTRING': ('Name', 'a'),
    'EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN': ('Stretch', 'a'),
    'EXTCTRLS_TCUSTOMIMAGE____SETPROPORTIONAL_BOOLEAN': ('Proportional', 'a'),
    'EXTCTRLS_TCUSTOMIMAGE____SETCENTER_BOOLEAN': ('Center', 'a'),
    'FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING': ('Directory', 'a'),
    'FILECTRL_TCUSTOMFILELISTBOX____SETMASK_ANSISTRING': ('Mask', 'a'),
    'EXTCTRLS_TCUSTOMTIMER____SETENABLED_BOOLEAN': ('Enabled', 'a'),
    'EXTCTRLS_TCUSTOMTIMER____SETINTERVAL_LONGWORD': ('Interval', 'a'),
    'CONTROLS_TCONTROL____SETCOLOR_TCOLOR': ('Color', 'a'),
    'CONTROLS_TCONTROL____SETVISIBLE_BOOLEAN': ('Visible', 'a'),
    'CONTROLS_TCONTROL____SETENABLED_BOOLEAN': ('Enabled', 'a'),
    'SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING': ('ExtractFileExt', 's'),
    'SYSUTILS_EXTRACTFILENAME_ANSISTRING__ANSISTRING': ('ExtractFileName', 's'),
    'SYSUTILS_EXTRACTFILEPATH_ANSISTRING__ANSISTRING': ('ExtractFilePath', 's'),
    'SYSUTILS_FORMATDATETIME_ANSISTRING_TDATETIME__ANSISTRING': ('FormatDateTime', 's'),
    'SYSUTILS_STRTOFLOAT_ANSISTRING__EXTENDED': ('StrToFloat', 'f'),
    'SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN': ('RemoveDir', 'f'),
    'SYSUTILS_RENAMEFILE_ANSISTRING_ANSISTRING__BOOLEAN': ('RenameFile', 'f'),
    'FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN': ('CopyFile', 'f'),
    'SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT': ('Delete', 'p'),
    'SYSTEM_INSERT_ANSISTRING_ANSISTRING_LONGINT': ('Insert', 'p'),
    'SYSTEM_RANDOM_LONGINT__LONGINT': ('Random', 'f'),
    'SYSTEM_RANDOMIZE': ('Randomize', 'p'),
    'SYSTEM_HALT_LONGINT': ('Halt', 'p'),
    'FORMS_TAPPLICATION____PROCESSMESSAGES': ('ProcessMessages', 'm'),
    'FORMS_TAPPLICATION____TERMINATE': ('Terminate', 'm'),
    'PROCESS_TPROCESS____SETCOMMANDLINE_ANSISTRING': ('CommandLine', 'a'),
    'PROCESS_TPROCESS____EXECUTE': ('Execute', 'm'),
}
# Descartes: gerenciamento de memória do FPC.
DESCARTA = r'FPC_FINALIZE\(.+\)|fpc_finalize\(.+\)|FPC_INITIALIZE\(.+\)|fpc_initialize\(.+\)'
# Variáveis globais de outras units que aparecem como argumento.
GLOBAIS_RTL = {'U_FORMS_SCREEN': 'Screen', 'U_CONTROLS_MOUSE': 'Mouse', 'U_FORMS_APPLICATION': 'Application'}



def args_de(s):
    """Separa os argumentos de uma chamada no nível de cima."""
    out, nivel, cur = [], 0, ''
    for ch in s:
        if ch == ',' and nivel == 0:
            out.append(cur.strip()); cur = ''; continue
        nivel += ch == '('
        nivel -= ch == ')'
        cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def num(m):
    v = int(m.group(0), 16)
    return str(v - 0x100000000 if v >= 0x80000000 else v)


def logico(e):
    """Separa && e || no nível de cima e põe cada lado entre parênteses."""
    partes, nivel, cur, ops, i = [], 0, '', [], 0
    while i < len(e):
        ch = e[i]
        nivel += ch == '('
        nivel -= ch == ')'
        if nivel == 0 and e[i:i + 2] in ('&&', '||'):
            partes.append(cur.strip()); ops.append(' and ' if e[i] == '&' else ' or '); cur = ''; i += 2
            continue
        cur += ch
        i += 1
    partes.append(cur.strip())
    if len(partes) == 1:
        return e
    def par(p):
        p = logico(p[1:-1]) if p.startswith('(') and p.endswith(')') and args_de('(' + p[1:-1] + ')') else p
        return p if re.fullmatch(r'not \w+|\w+', p) else f'({p})'
    out = par(partes[0])
    for op, p in zip(ops, partes[1:]):
        out += op + par(p)
    return out


def expr(e):
    """Expressão C -> Pascal; None se sobrar algo que não dá para traduzir com segurança."""
    e = e.strip()
    if e.startswith('&'):
        e = e[1:]
    m = re.fullmatch(r'(STREQ|STRNE)\((.+)\)', e)
    if m:
        a = args_de(m.group(2))
        if len(a) == 2 and expr(a[0]) and expr(a[1]):
            return f'{expr(a[0])} {"=" if m.group(1) == "STREQ" else "<>"} {expr(a[1])}'
        return None
    c = chamada(e, valor=True)
    if c:
        return c
    e = re.sub(r'\(\(int\)\((\w+(?:\.\w+\?)?) \+ \(\1 >> 0x1f & 1U\)\) >> 1\)', r'(\1 div 2)', e)
    e = re.sub(r'\(\(int\)\((\w+(?:\.\w+\?)?) \+ \(\1 >> 0x1f & 3U\)\) >> 2\)', r'(\1 div 4)', e)
    e = re.sub(r'\b(local_\w+)\[0\]', r'\1', e)
    e = re.sub(r'@DT_(\w+?)_(\w+)', lambda m: f'{m.group(1).title()}ToStr({m.group(2).title()})', e)
    # Letra e tamanho de texto lidos direto da memória: *(byte *)(s + -1 + i) é s[i]; *(int *)(s + -4) é Length(s).
    e = re.sub(r'(?:\(uint\))?\*\(byte \*\)\((\w+) \+ -1 \+ (\w+)\)', r'@ORD(\1,\2)', e)
    e = re.sub(r'\*\(int \*\)\((\w+) \+ -4\)', r'@LEN(\1)', e)
    for k, v in GLOBAIS_RTL.items():
        e = e.replace(k, v)
    e = re.sub(r'\bU_JUKELINUX1_(\w+)', lambda m: globais.add(m.group(1)) or m.group(1), e)
    for l in re.findall(r'\b(?:local_\w+|[a-z]Var\d+|[iu]Stack_\w+)', e):
        locais.add(l)
    e = e.replace('?', '')
    e = re.sub(r'\b0x[0-9a-fA-F]+\b', num, e)
    e = re.sub(r'(?<=\d)U\b', '', e)
    e = logico(e)
    e = e.replace('==', '=').replace('!=', '<>').replace(' / ', ' div ')
    e = re.sub(r'(?<![<>=:])!(?!=)', 'not ', e)
    e = re.sub(r'@T(\d+)@', lambda m: texto_pas(m.group(1)), e)
    e = {'#0': '0', '#1': '1'}.get(e, e)
    e = re.sub(r'(?<=[=<>] )#(\d+)\b', r'\1', e)  # char do C comparado com número
    # operador vírgula do C, ex.: (k = k + 1, k < 501): parênteses com vírgula que não são de chamada
    if re.search(r'(?<![\w\]])\(([^()]*,[^()]*)\)', e):
        return None
    if any(0x08000000 <= int(n) < 0x0a000000 for n in re.findall(r'\b\d{9}\b', e)):
        return None
    if '[' in e:  # índice que sobrou (vetor do C ou campo não identificado)
        return None
    if re.search(r'(^|[(,=<>+\-\s])\*\w', e):  # ponteiro desreferenciado do C
        return None
    if re.search(r'\*\(|>>|<<|\(int\)|\(uint\)|\(char\)|code|extraout|CONCAT|undefined|&|\b[A-Z]+\d*_\w+ ?\(|\bfpc_|'
                 r'\b_\d_\d_|param_|\bFPC_|\(\w+ \*+\)|\bp\w*Var\d+\b|\bDAT_|\ba\w*Stack_|\bpu\w*Stack_', e):
        return None
    e = re.sub(r'@ORD\((\w+),(\w+)\)', r'Ord(\1[\2])', e)
    e = re.sub(r'@LEN\((\w+)\)', r'Length(\1)', e)
    return e


def nome_juke(g):
    """JUKELINUX1_MOSTRA_CDS_ANSISTRING -> (Mostra_Cds, devolve_string_por_ref)."""
    resto = g[len('JUKELINUX1_'):]
    melhor = max((n for n in nomes_juke if '.' not in n and (resto == n or resto.startswith(n + '_'))),
                 key=len, default=None)
    if not melhor:
        return None
    return melhor.title(), resto.endswith('__ANSISTRING') or resto.endswith('__SHORTSTRING')


def chamada(c, valor=False):
    """Traduz uma chamada de rotina; com valor=True só aceita funções (para usar dentro de expressão)."""
    m = re.fullmatch(r'(\w+) ?\((.*)\)', c)
    if not m or len(args_de('(' + m.group(2) + ')')) != 1:  # tem que ser uma chamada só, não "f(a) + g(b)"
        return None
    g, a = m.group(1), args_de(m.group(2))
    ae = [expr(x) for x in a]
    if g.startswith('JUKELINUX1_') and not valor:
        r = nome_juke(g)
        if not r:
            return None
        nome, por_ref = r
        if por_ref and a:
            if None in ae:
                return None
            return f'{ae[-1]} := {nome}({", ".join(ae[:-1])});'
        if None in ae:
            return None
        return f'{nome}({", ".join(ae)});' if ae else f'{nome};'
    if g.startswith('JUKELINUX1_') and valor:
        r = nome_juke(g)
        if r and not r[1] and None not in ae:
            return f'{r[0]}({", ".join(ae)})' if ae else r[0]
        return None
    if g in RTL:
        nome, tipo = RTL[g]
        if tipo == 'f' and None not in ae and (ae or nome in ('Time', 'Date', 'Now')):
            if nome == 'CopyFile' and len(ae) == 3:
                ae[2] = {'1': 'True', '0': 'False'}.get(ae[2], ae[2])
            return f'{nome}({", ".join(ae)})' if ae else nome
        if tipo == 'g' and len(ae) == 1 and ae[0]:
            return f'{ae[0]}.{nome}'
        if valor:
            return None
        if tipo == 'p' and None not in ae:
            return f'{nome}({", ".join(ae)});' if ae else f'{nome};'
        if tipo == 's' and None not in ae:
            return f'{ae[-1]} := {nome}({", ".join(ae[:-1])});'
        if tipo == 'r' and None not in ae and all(re.fullmatch(r'[A-Za-z_][\w.]*', x) for x in ae):
            return f'Read({", ".join(ae)});'
        if tipo == 'm' and len(ae) == 1 and ae[0]:
            return f'{ae[0]}.{nome};'
        if tipo == 'a' and len(ae) == 2 and None not in ae:
            v = ae[1]
            if nome in ('Stretch', 'Proportional', 'Center', 'Enabled', 'Visible') and v in ('0', '1', '#0', '#1'):
                v = 'True' if v in ('1', '#1') else 'False'
            return f'{ae[0]}.{nome} := {v};'
        return None
    if g == 'fpc_char_to_ansistr' and len(a) == 2 and None not in ae:  # (letra, &destino)
        letra = ae[0] if re.fullmatch(r"'.*'|#\d+", ae[0]) else f'Chr({ae[0]})'
        texto_certo.add(ae[1])
        return f'{ae[1]} := {letra};'
    if g == 'fpc_ansistr_copy' and len(a) == 4 and None not in ae:
        return f'{ae[3]} := Copy({ae[0]}, {ae[1]}, {ae[2]});'
    if valor:
        return None
    if g in ('fpc_write_text_ansistr', 'FPC_WRITE_TEXT_SHORTSTR', 'fpc_write_text_sint', 'fpc_write_text_char',
             'fpc_write_text_shortstr', 'fpc_write_text_uint') and len(a) == 3 and ae[1] and ae[2]:
        return f'Write({ae[1]}, {ae[2]});'
    if g == 'FPC_ANSISTR_TO_SHORTSTR' and len(a) == 3 and ae[0] and ae[2]:
        return f'{ae[0]} := {ae[2]};'
    if g in ('fpc_shortstr_to_ansistr', 'fpc_ansistr_assign') and len(a) == 2 and ae[0] and ae[1]:
        return f'{ae[0]} := {ae[1]};'
    if g == 'fpc_pchar_to_ansistr' and len(a) == 2 and ae[1] and re.fullmatch(r'puVar\d+', a[0]):
        return None
    if g == 'fpc_ansistr_concat' and len(a) == 3 and None not in ae:
        texto_certo.update(ae)
        return f'{ae[0]} := {ae[1]} + {ae[2]};'
    if g == 'fpc_ansistr_concat_multi' and len(a) == 3 and ae[0]:
        m2 = re.fullmatch(r'&?local_([0-9a-f]+)', a[1])
        if m2 and a[2].isdigit():
            base = int(m2.group(1), 16)
            partes = [f'local_{base - 4 * i:x}' for i in range(int(a[2]) + 1)]
            locais.update(partes)
            texto_certo.update(partes + [ae[0]])
            return f'{ae[0]} := {" + ".join(partes)};'
    if g == 'GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING' and len(a) == 2 and None not in ae:
        return f'{ae[0]}.LoadFromFile({ae[1]});'
    if g == 'EXTCTRLS_TCUSTOMIMAGE____SETTRANSPARENT_BOOLEAN' and len(a) == 2 and ae[0]:
        return f'{ae[0]}.Transparent := {"True" if a[1] == "1" else "False"};'
    m2 = re.fullmatch(r'CONTROLS_TCONTROL____(SETLEFT|SETTOP|SETWIDTH|SETHEIGHT)_LONGINT', g)
    if m2 and len(a) == 2 and None not in ae:
        return f'{ae[0]}.{PROPS[m2.group(1)]} := {ae[1]};'
    if g == 'CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING' and len(a) == 2 and ae[1] == '0':
        ae[1] = "''"  # texto nil do FPC
    if g == 'CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING' and len(a) == 2 and None not in ae:
        return f'{ae[0]}.Caption := {ae[1]};'
    if g == 'CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING' and len(a) == 2 and None not in ae:
        return f'{ae[1]} := {ae[0]}.Caption;'
    return None


def comando(c):
    c = c.strip().rstrip(';').strip()
    if not c:
        return ''
    if c == 'break':
        return 'Break;'
    # Construtor: X = (int *)(*(code *)PTR_UNIT_TCLASSE____CREATE_TCOMPONENT__...)(0,&VMT_UNIT_TCLASSE,dono)
    m = re.fullmatch(r'([\w.]+) = \(\w+ \*\)\(\*\(code \*\)PTR_[A-Z]+_(T\w+?)____CREATE_TCOMPONENT\w*\) ?'
                     r'\(0,&VMT_\w+,(\w+)\)', c)
    if m and expr(m.group(1)):
        classe = {'TPROCESS': 'TProcess', 'TSTRINGLIST': 'TStringList'}.get(m.group(2), m.group(2))
        return f'{expr(m.group(1))} := {classe}.Create(Form1);'
    # TProcess.Execute pela VMT (+0xe0)
    m = re.fullmatch(r'\(\*\*\(code \*\*\)\(\*U_JUKELINUX1_(\w+) \+ 0xe0\)\) ?\(U_JUKELINUX1_\1\)', c)
    if m:
        globais.add(m.group(1))
        return f'{m.group(1)}.Execute;'
    m = re.fullmatch(r'(LAB_\w+)@ROTULO', c)
    if m:
        rotulos.add(m.group(1))
        return f'{m.group(1)}: ;'
    m = re.fullmatch(r'goto (LAB_\w+)', c)
    if m:
        rotulos.add(m.group(1))
        return f'goto {m.group(1)};'
    # if de um comando só, sem chaves: if (c) goto X / break / return
    m = re.fullmatch(r'if ?\((.+)\) (goto LAB_\w+|break|return.*)', c)
    if m:
        cond, inner = condicao(m.group(1)), comando(m.group(2))
        if cond and not inner.startswith('//'):
            return f'if {cond} then begin {inner} end;'
    m = re.fullmatch(r'return (.+)', c)
    if m and expr(m.group(1)):
        return f'Result := {expr(m.group(1))}; Exit;'
    if re.fullmatch(DESCARTA, c):
        return ''
    # TStrings.Get(i, &s) pela VMT (+0x78): s := Lista[i]
    m = re.fullmatch(r'\(\*\*\(code \*\*\)\(\*\*\(int \*\*\)\(.+?\) \+ 0x78\)\)\s*\(([\w.]+\.Items),(.+?),&?(\w+(?:\[0\])?)\)', c)
    if m and expr(m.group(2)) and expr(m.group(3)):
        return f'{expr(m.group(3))} := {m.group(1)}[{expr(m.group(2))}];'
    if re.fullmatch(r'fpc_ansistr_(decr|incr)_ref\(.+\)|fpc_iocheck\(\)|fpc_pushexceptaddr\(.+\)|'
                    r'fpc_popaddrstack\(\)|fpc_reraise\(\)|fpc_initialize\(.+\)|fpc_finalize\(.+\)|return|'
                    r'puVar\d+(\[0\])? = (0|\(\w+ \*\)0x0)|puVar\d+ = &FPC_EMPTYCHAR|local_\w+ = param_\d|'
                    r'uVar\d+ = (extraout_EDX\w*|\(uint3\)\(\(uint\)extraout_EDX\w* >> 8\))', c):
        return ''
    m = re.fullmatch(r'(local_\w+) = \(\w+ \*\)0x0', c)  # texto zerado (ponteiro nil)
    if m:
        locais.add(m.group(1)); texto_certo.add(m.group(1))
        return f"{m.group(1)} := '';"
    r = chamada(c)
    if r:
        return r if r.endswith(';') else r + ';'
    # (**(code **)(**(int **)(...) + OFF))(OBJ, ARG)  -> propriedade virtual
    m = re.fullmatch(r'\(\*\*\(code \*\*\)\((?:\*\*\(int \*\*\)\(.+?\)|\*\(int \*\)[\w.]+) \+ (0x[0-9a-f]+)\)\)'
                     r'\s*\((Form1\.[\w.]+),(.+)\)', c)
    if m:
        prop = VIRTUAIS.get(int(m.group(1), 16))
        if m.group(2).endswith('.Font'):
            prop = {0xa4: 'Size'}.get(int(m.group(1), 16))
            if prop and expr(m.group(3)):
                return f'{m.group(2)}.{prop} := {expr(m.group(3))};'
        arg = m.group(3).strip()
        if re.fullmatch(r'(extraout_EDX\w*|uVar\d+) & 0xffffff00|\(uint\)uVar\d+ << 8', arg):
            arg = '0'
        if re.fullmatch(r'CONCAT31\(\w+,1\)', arg):
            arg = '1'
        if prop == 'Align' and arg.isdigit():
            return f'{m.group(2)}.Align := {ALIGN.get(int(arg), arg)};'
        if prop in ('Enabled', 'AutoSize', 'Visible') and arg in ('0', '1'):
            return f'{m.group(2)}.{prop} := {"True" if arg == "1" else "False"};'
    m = re.fullmatch(r'([\w.]+(?:\[0\])?) = (.+)', c)
    if m and not re.fullmatch(r'(uVar|puVar|extraout_)\w*', m.group(1)):
        a, b = expr(m.group(1)), expr(m.group(2))
        if a and b and re.fullmatch(r'[A-Za-z_][\w.]*', a):  # destino tem de ser um nome, não endereço calculado
            return f'{a} := {b};'
    return '// C: ' + re.sub(r'@T(\d+)@', lambda m: textos[int(m.group(1))], c) + ';'


def condicao(c):
    c = c.strip()
    m = re.fullmatch(r'(\w+) (!=|==) (@T\d+@)', c)
    if m and texto_pas(m.group(3)[2:-1]) == '#0':
        v = expr(m.group(1))
        if v and re.fullmatch(r'cVar\d+', v):
            return v if m.group(2) == '!=' else f'not {v}'
        if v:
            return f'{v} <> 0' if m.group(2) == '!=' else f'{v} = 0'
    return expr(c)


def cond_ou_falso(c):
    """Condição traduzida; se não der, False com o C original num comentário (o bloco não roda até revisar)."""
    r = condicao(c)
    if r:
        return r
    return 'False { C: ' + re.sub(r'@T(\d+)@', lambda x: textos[int(x.group(1))], c).replace('}', ')').replace('{', '(') + ' }'



def traduzir(src):
    """Traduz uma função C; devolve (linhas Pascal do corpo, locais usadas, globais usadas)."""
    textos.clear(); locais.clear(); globais.clear(); rotulos.clear(); texto_certo.clear()

    # --- preparo: corpo, textos protegidos, moldura de exceção, comparações ---------------------------------------
    corpo = src[src.index('{', src.index(')')) + 1:src.rindex('}')]
    corpo = re.sub(r'"(?:[^"\\]|\\.)*"', guarda, corpo)
    corpo = re.sub(r"'(?:[^'\\]|\\.)*'", guarda, corpo)
    # Declarações do C no começo do corpo (linhas "tipo [*]nome [n];").
    linhas = corpo.split('\n')
    while linhas and (not linhas[0].strip() or re.fullmatch(r'\s*[\w ]+?\s*\**\s*\w+(\s*\[[0-9a-fx]+\])*;\s*', linhas[0])):
        linhas.pop(0)
    corpo = '\n'.join(linhas)
    m = re.search(r'(\w+) = fpc_setjmp\(\);\s*if \(\1 == 0\) \{', corpo)
    if m:
        v = m.group(1)
        corpo = corpo[:m.start()] + '{' + corpo[m.end():]
        corpo = re.sub(r'if \(' + v + r' != 0\) \{\s*fpc_reraise\(\);\s*\}', '', corpo)
    corpo = re.sub(r'\s+', ' ', corpo)
    # Rótulos de goto viram comandos próprios (senão grudam na chave seguinte).
    corpo = re.sub(r'\b(LAB_\w+):', r'\1@ROTULO;', corpo)
    # Data e hora voltam pela pilha do FPU: "Date(); DateToStr(&s);" -> "s := DateToStr(Date)".
    corpo = re.sub(r'SYSUTILS_(DATE|TIME|NOW)__TDATETIME\(\); SYSUTILS_(DATE|TIME|DATETIME)TOSTR_TDATETIME__ANSISTRING'
                   r'\(&?(\w+)\);', lambda m: f'{m.group(3)} = @DT_{m.group(2)}_{m.group(1)};', corpo)
    # Comparação com um lado só: o outro foi no registrador, e é o valor que acabou de ser atribuído.
    # "X = y; i = fpc_ansistr_compare_equal(Z);" -> "... compare_equal(X,Z)"
    corpo = re.sub(r'(\b[\w.]+) = ([\w.]+); (\w+) = fpc_ansistr_compare_equal\(([\w.]+)\);',
                   r'\1 = \2; \3 = fpc_ansistr_compare_equal(\1,\4);', corpo)
    # iVar = fpc_ansistr_compare_equal(a,b); if (iVar == 0)  ->  if (STREQ(a,b))
    corpo = re.sub(r'(\w+) = (?:fpc_ansistr_compare_equal|FPC_SHORTSTR_COMPARE_EQUAL|fpc_shortstr_compare_equal)'
                   r'\(([^;]+)\);(?: uVar\d+ = [^;]+;)? if \(\1 (==|!=) 0\)',
                   lambda m: f'if ({"STREQ" if m.group(3) == "==" else "STRNE"}({m.group(2)}))', corpo)
    tokens = re.findall(r'[^;{}]*[;{}]', corpo)
    saida, pilha = [], []
    n_case = 0

    def topo_case():
        return pilha and isinstance(pilha[-1], dict)

    def fecha_ramo():
        if topo_case() and pilha[-1]['ramo']:
            saida.append('  ' * len(pilha) + '  end;')
            pilha[-1]['ramo'] = False

    def rotulos_case(t):
        """Tira os prefixos "case N:" / "default:" do comando; abre o ramo do case no Pascal."""
        if not topo_case():
            return t
        vals, default = [], False
        while True:
            m = re.match(r'(case ([^:]+)|default):\s*', t)
            if not m:
                break
            if m.group(2):
                v = expr(m.group(2))
                vals.append(v if v else '0 { C: ' + m.group(2) + ' }')
            else:
                default = True
            t = t[m.end():]
        if vals or default:
            fecha_ramo()
            ind = '  ' * len(pilha)
            saida.append(ind + '  ' + (f'{", ".join(vals)}: begin' if vals else 'else begin'))
            pilha[-1]['ramo'] = True
        return t

    i = 0
    while i < len(tokens):
        t = rotulos_case(tokens[i].strip())
        ind = len(pilha) + 1 + (1 if topo_case() else 0)
        if not t:
            i += 1
            continue
        if t.endswith('{'):
            h = t[:-1].strip()
            m = re.fullmatch(r'(\} )?(else )?if ?\((.+)\)', h)
            if m:
                saida.append('  ' * ind + ('else ' if m.group(2) else '') + f'if {cond_ou_falso(m.group(3))} then begin')
                pilha.append('begin')
            elif h in ('else', '} else'):
                saida.append('  ' * ind + 'else begin')
                pilha.append('begin')
            elif h == 'do':
                saida.append('  ' * ind + 'repeat')
                pilha.append('repeat')
            elif re.fullmatch(r'while ?\( ?true ?\)', h):
                saida.append('  ' * ind + 'while True do begin')
                pilha.append('begin')
            elif re.fullmatch(r'while ?\((.+)\)', h):
                saida.append('  ' * ind + f'while {cond_ou_falso(re.fullmatch(r"while ?[(](.+)[)]", h).group(1))} do begin')
                pilha.append('begin')
            elif re.fullmatch(r'switch ?\((.+)\)', h):
                v = expr(re.fullmatch(r'switch ?\((.+)\)', h).group(1))
                saida.append('  ' * ind + f'case {v if v else "0 { C: " + h + " }"} of')
                n_case += 1
                pilha.append({'tipo': 'case', 'ramo': False, 'rotulo': None, 'n': n_case})
            elif h == '':
                saida.append('  ' * ind + 'begin')
                pilha.append('begin')
            else:
                saida.append('  ' * ind + f'begin // C: {h}')
                pilha.append('begin')
        elif t == '}':
            if topo_case():
                fecha_ramo()
                bloco = pilha.pop()
                saida.append('  ' * (len(pilha) + 1) + 'end;')
                if bloco['rotulo']:
                    saida.append('  ' * (len(pilha) + 1) + f'{bloco["rotulo"]}: ;')
                i += 1
                continue
            tipo = pilha.pop() if pilha else 'begin'
            ind = len(pilha) + 1 + (1 if topo_case() else 0)
            prox = tokens[i + 1].strip() if i + 1 < len(tokens) else ''
            m = re.fullmatch(r'while ?\((.+)\);', prox)
            if tipo == 'repeat' and m:
                c = condicao(m.group(1))
                saida.append('  ' * ind + (f'until not ({c});' if c else 'until True; // C: while (' + m.group(1) + ')'))
                i += 1
            elif tipo == 'repeat':
                saida.append('  ' * ind + 'until False;')
            else:
                saida.append('  ' * ind + 'end;')
        elif t == 'break;' and any(isinstance(p, dict) for p in pilha):
            # break do switch: no fim do ramo só fecha o ramo; mais fundo (dentro de um if), salta para o fim do case
            k = max(j for j, p in enumerate(pilha) if isinstance(p, dict))
            if 'repeat' in pilha[k + 1:] or any(p == 'laco' for p in pilha[k + 1:]):
                saida.append('  ' * ind + 'Break;')
            elif k == len(pilha) - 1:
                fecha_ramo()
            else:
                pilha[k]['rotulo'] = pilha[k]['rotulo'] or f'LAB_FIMCASE{pilha[k]["n"]}'
                rotulos.add(pilha[k]['rotulo'])
                saida.append('  ' * ind + f'goto {pilha[k]["rotulo"]};')
        else:
            r = comando(t)
            if r:
                saida.append('  ' * ind + r)
        i += 1

    for i in range(len(saida) - 1):
        if saida[i].strip() == 'end;' and saida[i + 1].strip().startswith('else'):
            saida[i] = saida[i][:-1]

    usados = sorted(l for l in locais if any(re.search(r'\b' + l + r'\b', s) for s in saida))
    return saida, usados, sorted(globais)


if __name__ == '__main__':
    carregar_nomes(sys.argv[2])
    saida, usados, gl = traduzir(open(sys.argv[1], encoding='utf-8').read())
    print(f'procedure {sys.argv[3]};' if len(sys.argv) > 3 else '')
    if usados:
        print('var\n  ' + ', '.join(usados) + ': {tipo};')
    print('begin')
    print('\n'.join(saida))
    print('end;')
    print('// globais usadas: ' + ', '.join(gl), file=sys.stderr)
