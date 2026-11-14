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
    # Nova: no modo sem pendrive a original exige o jukeu.txt (UUID do HD cifrado, criado na ativação pelo
    # desenvolvedor); essa trava é substituída pela licença nova (fase 6). No lugar dela, os seriais da chave antiga
    # vêm do HD (serial-da-chave.txt, ver nova.inc), antes das configurações que os conferem.
    ('TForm1.FormCreate', "    if SEMPENDRIVE <> 0 then begin\n      NOMEARQ := PASTA + 'jukeu.txt';",
     "    Serial_Da_Chave_No_Hd;  // Nova: serial da chave antiga guardado no HD\n"
     "    if False then begin  // Nova: trava do jukeu.txt (UUID do HD) substituída pela licença nova\n"
     "      NOMEARQ := PASTA + 'jukeu.txt';",
     'a Nova não depende do pendrive-chave nem da ativação do desenvolvedor (decisão do dono)'),
    # PROVISÓRIO até a licença nova (fase 6): a trava do pendrive-chave original sai, e a leitura do serial do
    # pendrive (em /dev/disk/by-id) não foi traduzida. Sem isto a Nova para na tela "Erro 13".
    ('TForm1.FormActivate', '''      if ERROSERIALNUM = 0 then begin
        ROTINA_DO_ACTIVATE := 2;''', '''      if ERROSERIALNUM <> 0 then Gravalog('PROVISORIO: trava do pendrive-chave ignorada (' + ERROSERIAL + ')');
      ERROSERIALNUM := 0;  // PROVISÓRIO: sai quando entrar a licença nova
      if ERROSERIALNUM = 0 then begin
        ROTINA_DO_ACTIVATE := 2;''', 'trava do pendrive-chave substituída pela licença nova (fase 6)'),
    # Nova: laço que lê as pastas dos CDs. O Ghidra usou um buffer da pilha (aiStack_478b58[0]) como texto e montou
    # Pasta com fpc_ansistr_concat_multi(dest, &uStack_478b64, 2) = PASTAMUSICAS + nome + "/"; sem isto nenhum CD
    # entrava no acervo. Reescrito seguindo o C linha a linha.
    ('Carregando_Cds', 'label\n  LAB_0809cd38;\nvar\n',
     'label\n  LAB_0809cd38;\nvar\n  NovaItem: AnsiString;  // Nova: item da lista de pastas (aiStack_478b58[0] no C)\n',
     'texto do item da lista de pastas'),
    ('Carregando_Cds', '    Form1.FileListBox1.Directory := PASTAMUSICAS;\n    KMAT := 0;\n    iVar6 := Form1.FileListBox1.Count;\n    local_8 := 0;\n    if -1 < iVar6 + -1 then begin\n      local_8 := -1;\n      repeat\n        local_8 := local_8 + 1;\n        // C: aiStack_478b58[0] = 0;\n        // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58);\n        if False { C: STRNE(aiStack_478b58[0],"[.]") } then begin\n          // C: aiStack_478b58[0] = 0;\n          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58);\n          if False { C: STRNE(aiStack_478b58[0],"[..]") } then begin\n            KMAT := KMAT + 1;\n            uStack_478b64 := PASTAMUSICAS;\n            // C: aiStack_478b58[0] = 0;\n            // C: piVar8 = aiStack_478b58;\n            iStack_478b68 := \'\';\n            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,&iStack_478b68, piVar8);\n            iVar7 := 0;\n            if iStack_478b68 <> \'\' then begin\n              iVar7 := Length(iStack_478b68);\n            end;\n            iStack_478b68 := \'\';\n            iStack_478b68 := Form1.FileListBox1.Items[local_8];\n            // C: fpc_ansistr_copy(iStack_478b68,2,iVar7 + -2,piVar8);\n            // C: iStack_478b60 = aiStack_478b58[0];\n            // C: puStack_478b5c = "/";\n            // C: fpc_ansistr_concat_multi(U_JUKELINUX1_KMAT * 0x240 + 0x8e91118,&uStack_478b64,2);\n            iStack_478b68 := \'\';\n            // C: piVar8 = &iStack_478b68;\n            // C: aiStack_478b58[0] = 0;\n            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58, piVar8);\n            iVar7 := 0;\n            if False { C: aiStack_478b58[0] != 0 } then begin\n              // C: iVar7 = *(int * )(aiStack_478b58[0] + -4);\n            end;\n            // C: aiStack_478b58[0] = 0;\n            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58);\n            // C: fpc_ansistr_copy(aiStack_478b58[0],2,iVar7 + -2,piVar8);\n            // C: fpc_ansistr_concat(U_JUKELINUX1_KMAT * 0x240 + 0x8e9111c,iStack_478b68, "/");\n            iStack_478b68 := \'\';\n            // C: SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMAT * 0x240 + 0x1fc), &iStack_478b68);\n            iVar7 := KMAT * 576;\n            // C: *(int * )(U_JUKELINUX1_ARQLOG + iVar7 + 0x1fc) = iStack_478b68;\n            // C: iVar7 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT (CONCAT31((int3)((uint)(U_JUKELINUX1_KMAT * 0x240) >> 8),0x2e), *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMAT * 0x240 + 0x1fc));\n            if 0 < iVar7 then begin\n              KMAT := KMAT + -1;\n            end;\n          end;\n        end;\n      until not (local_8 < iVar6 + -1);\n    end;\n',
     "    Form1.FileListBox1.Directory := PASTAMUSICAS;\n    KMAT := 0;\n    iVar6 := Form1.FileListBox1.Count;\n    local_8 := 0;\n    if -1 < iVar6 + -1 then begin\n      local_8 := -1;\n      repeat\n        local_8 := local_8 + 1;\n        // Nova: reescrito à mão seguindo o C (correcoes.py). O Ghidra guardou o item em aiStack_478b58[0] e montou a\n        // pasta com fpc_ansistr_concat_multi na pilha, o que o tradutor não acompanha.\n        NovaItem := Form1.FileListBox1.Items[local_8];\n        if NovaItem <> '[.]' then begin\n          if NovaItem <> '[..]' then begin\n            KMAT := KMAT + 1;\n            NovaItem := Copy(NovaItem, 2, Length(NovaItem) - 2);  // [NOME DA PASTA] -> NOME DA PASTA\n            MAT[KMAT].Pasta := PASTAMUSICAS + NovaItem + '/';\n            MAT[KMAT].Nome := UpperCase(NovaItem + '/');\n            iVar7 := Pos('.', MAT[KMAT].Nome);\n            if 0 < iVar7 then begin\n              KMAT := KMAT + -1;\n            end;\n          end;\n        end;\n      until not (local_8 < iVar6 + -1);\n    end;\n",
     'lê as pastas dos CDs para o acervo (MAT[i].Pasta e .Nome)'),
    # Nova: filtro dos CDs ativos (ritmo inativo ou sem música saem). O C copia os registros para um vetor na pilha
    # (auStack_4654c4) com uma marca de um byte (cStack_478b2c); sem isto TOTALCDS ficava 0. Seguindo o C.
    ('Carregando_Cds', '  NovaItem: AnsiString;  // Nova: item da lista de pastas (aiStack_478b58[0] no C)\n',
     '  NovaItem: AnsiString;  // Nova: item da lista de pastas (aiStack_478b58[0] no C)\n  NovaCds: array of TIPOCD;  // Nova: o vetor auStack_4654c4 do C (CDs ativos), dinâmico para não ir para a pilha\n  NovaInativo: Boolean;  // Nova: a marca cStack_478b2c do C\n',
     'variáveis do filtro dos CDs ativos'),
    ('Carregando_Cds', "    iVar6 := TOTALCDS;\n    iStack_465288 := 0;\n    local_20 := TOTALCDS;\n    if 0 < TOTALCDS then begin\n      local_8 := 0;\n      repeat\n        local_8 := local_8 + 1;\n        // ?: cStack_478b2c := 0;\n        // C: iVar7 = ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0x80)) (Form1.ListBoxRInativo.Items);\n        local_c := 0;\n        if -1 < iVar7 + -1 then begin\n          local_c := -1;\n          repeat\n            local_c := local_c + 1;\n            uStack_478e90 := '';\n            uStack_478e90 := Form1.ListBoxRInativo.Items[local_c];\n            // C: uVar5 = uStack_478e90;\n            iStack_478d8c := '';\n            // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&iStack_478d8c);\n            if iStack_478d8c = uVar5 then begin\n              // ?: cStack_478b2c := 1;\n            end;\n          until not (local_c < iVar7 + -1);\n        end;\n        if False { C: (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] == 0 } then begin\n          // ?: cStack_478b2c := 1;\n        end;\n        if False then begin // ?: cStack_478b2c = 0\n          iStack_465288 := iStack_465288 + 1;\n          // C: fpc_copy_proc(local_8 * 0x240 + 0x8e91110,auStack_4654c4 + iStack_465288 * 0x240, INIT_JUKELINUX1_TIPOCD);\n        end;\n      until not (local_8 < iVar6);\n    end;\n    iVar6 := iStack_465288;\n    TOTALCDS := iStack_465288;\n    local_8 := 1;\n    if 0 < iStack_465288 then begin\n      local_8 := 0;\n      repeat\n        local_8 := local_8 + 1;\n        // C: fpc_copy_proc(auStack_4654c4 + local_8 * 0x240,local_8 * 0x240 + 0x8e91110, INIT_JUKELINUX1_TIPOCD);\n      until not (local_8 < iVar6);\n",
     '    iVar6 := TOTALCDS;\n    iStack_465288 := 0;\n    local_20 := TOTALCDS;\n    // Nova: reescrito à mão seguindo o C (correcoes.py). Tira do acervo os CDs de ritmo inativo e os sem música; o C\n    // usa um vetor de registros na pilha (auStack_4654c4) e a marca cStack_478b2c, que o tradutor não acompanha.\n    SetLength(NovaCds, TOTALCDS + 1);\n    if 0 < TOTALCDS then begin\n      local_8 := 0;\n      repeat\n        local_8 := local_8 + 1;\n        NovaInativo := False;\n        iVar7 := Form1.ListBoxRInativo.Items.Count;\n        local_c := 0;\n        if -1 < iVar7 + -1 then begin\n          local_c := -1;\n          repeat\n            local_c := local_c + 1;\n            if MAT[local_8].Genero = Form1.ListBoxRInativo.Items[local_c] then begin\n              NovaInativo := True;\n            end;\n          until not (local_c < iVar7 + -1);\n        end;\n        if MAT[local_8].TotalMusicas = 0 then begin\n          NovaInativo := True;\n        end;\n        if not NovaInativo then begin\n          iStack_465288 := iStack_465288 + 1;\n          NovaCds[iStack_465288] := MAT[local_8];\n        end;\n      until not (local_8 < iVar6);\n    end;\n    iVar6 := iStack_465288;\n    TOTALCDS := iStack_465288;\n    local_8 := 1;\n    if 0 < iStack_465288 then begin\n      local_8 := 0;\n      repeat\n        local_8 := local_8 + 1;\n        MAT[local_8] := NovaCds[local_8];\n      until not (local_8 < iVar6);\n',
     'filtro dos CDs ativos e TOTALCDS'),
]
