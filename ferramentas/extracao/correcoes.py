"""Correções feitas à mão no Pascal gerado, para casos em que o Ghidra perdeu informação e uma regra geral não
compensa. gerar_rotinas.py aplica cada troca depois de traduzir; se o trecho antigo não aparecer exatamente uma vez,
a geração para (assim uma correção nunca cai no lugar errado).

Formato: (rotina, trecho antigo, trecho novo, motivo).
"""

CORRECOES = [
    ('TForm1.PanelMenu3Click', '    Mostra_Cd_Exclusao;', '    Mostra_Cd_Exclusao(KMATEXCLUI);',
     'o argumento ia no registrador EAX (KMATEXCLUI acabou de receber 1) e o Ghidra não o mostrou'),
]
