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
    # Nova: modo sem pendrive da própria original (SEMPENDRIVE, das versões "3MJ" e "ROB"): não lê nem grava
    # contadores e créditos no pendrive.
    ('TForm1.FormCreate', "    SEMPENDRIVE := 0;\n    SEMQRCODE := 0;",
     "    SEMPENDRIVE := 1;  // Nova: sem pendrive-chave (modo das versões 3MJ/ROB da original)\n    SEMQRCODE := 0;",
     'a Nova não depende do pendrive-chave (decisão do dono)'),
    ('TForm1.FormCreate', "    if cVar3 then begin\n      SEMPENDRIVE := 0;\n    end;\n    NOMEARQ := PASTA + 'log.txt';",
     "    NOMEARQ := PASTA + 'log.txt';",
     'horasligada.txt religava a trava do pendrive na original; na Nova o modo sem pendrive é fixo'),
    # Sem pendrive não há relógios do pendrive para sincronizar: os do HD mandam.
    ('TForm1.FormActivate', "      OPC := 2;\n",
     "      OPC := 2;\n      if SEMPENDRIVE <> 0 then OPC := 1;  // Nova: sem pendrive, os relógios do HD mandam\n",
     'a sincronização com o pendrive zerava os relógios da jukebox quando o pendrive não respondia'),
    # Nova: sem pendrive, os seriais da chave antiga vêm do HD (serial-da-chave.txt), antes da primeira
    # configuração que os confere.
    ('TForm1.FormCreate', "      NOMEARQ := PASTA + 'bloquearquandotocar.txt';",
     "      if ERROSERIALNUM <> 0 then Serial_Da_Chave_No_Hd;  // Nova: serial da chave antiga guardado no HD\n"
     "      NOMEARQ := PASTA + 'bloquearquandotocar.txt';",
     'a Nova não depende do pendrive-chave (decisão do dono); ver nova.inc'),
    # PROVISÓRIO até a licença nova (fase 6): a trava do pendrive-chave original sai, e a leitura do serial do
    # pendrive (em /dev/disk/by-id) não foi traduzida. Sem isto a Nova para na tela "Erro 13".
    ('TForm1.FormActivate', '''      if ERROSERIALNUM = 0 then begin
        ROTINA_DO_ACTIVATE := 2;''', '''      if ERROSERIALNUM <> 0 then Gravalog('PROVISORIO: trava do pendrive-chave ignorada (' + ERROSERIAL + ')');
      ERROSERIALNUM := 0;  // PROVISÓRIO: sai quando entrar a licença nova
      if ERROSERIALNUM = 0 then begin
        ROTINA_DO_ACTIVATE := 2;''', 'trava do pendrive-chave substituída pela licença nova (fase 6)'),
]
