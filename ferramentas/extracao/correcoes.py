"""Correções feitas à mão no Pascal gerado, para casos em que o Ghidra perdeu informação e uma regra geral não
compensa. gerar_rotinas.py aplica cada troca depois de traduzir; se o trecho antigo não aparecer exatamente uma vez,
a geração para (assim uma correção nunca cai no lugar errado).

Formato: (rotina, trecho antigo, trecho novo, motivo).
"""

CORRECOES = [
    ('TForm1.PanelMenu3Click', '    Mostra_Cd_Exclusao;', '    Mostra_Cd_Exclusao(KMATEXCLUI);',
     'o argumento ia no registrador EAX (KMATEXCLUI acabou de receber 1) e o Ghidra não o mostrou'),
    ('TForm1.FormKeyUp', '        CODIGODOCARTAO := 1;', '        CODIGODOCARTAO := Chr(Key);',
     'o C grava o tamanho da ShortString (1) e, na linha seguinte, a tecla no primeiro caractere'),
    ('Carregando_Cds', '''                              iVar4 := iStack_478d8c;
''', '',
     'iVar4 é o mesmo registrador usado como número no resto da rotina; aqui só guarda o texto lido da lista'),
    ('Carregando_Cds', '                              if uStack_478e90 = iVar4 then begin',
     '                              if uStack_478e90 = iStack_478d8c then begin', 'idem'),
]
