{ Rotinas da JukeLinux original traduzidas do código descompilado por ferramentas/extracao/gerar_rotinas.py.
  Linhas "// C:" são comandos que o tradutor não reconheceu e ainda precisam ser escritos à mão.
  Ao reescrever uma rotina à mão em jukelinux1.pas, gere de novo: ela sai daqui. }

procedure Apaga_Cd(P1: LongInt; P2: LongInt); forward;
procedure Ativa_Propaganda; forward;
procedure Backupcartaoccc; forward;
procedure Carregando_Cartoes; forward;
procedure Carregando_Cds; forward;
procedure Carregando_Karaokes; forward;
procedure Carregando_Propagandas; forward;
procedure Cartaocodbar_Bar; forward;
procedure Cartaocodbar_Boate; forward;
procedure Criptabuf; forward;
function Criptasimplesqr(P1: AnsiString): AnsiString; forward;
function Criptasimples(P1: AnsiString): AnsiString; forward;
function Criptasuper2(P1: AnsiString): AnsiString; forward;
function Criptasuper(P1: AnsiString): AnsiString; forward;
function Cripta(P1: AnsiString): AnsiString; forward;
procedure Define_Exibirvideos; forward;
procedure Desativa_Propaganda; forward;
procedure Desativa_Volume_Pelo_Painel; forward;
procedure Descriptabuf; forward;
function Descriptasimplesqr(P1: AnsiString): AnsiString; forward;
function Descriptasimples(P1: AnsiString): AnsiString; forward;
function Descriptasuper2(P1: AnsiString): AnsiString; forward;
function Descriptasuper(P1: AnsiString): AnsiString; forward;
function Descripta(P1: AnsiString): AnsiString; forward;
procedure Descriptografa(P1: AnsiString; P2: AnsiString); forward;
procedure Desselecionamusica; forward;
procedure Desselecionamusica_Todas; forward;
procedure Destravamensagem; forward;
procedure Excluicdpelalista; forward;
procedure Genero_Mais_Tocados; forward;
procedure Gravacreditonocartao(P1: AnsiString; P2: LongInt); forward;
procedure Gravalog(P1: AnsiString); forward;
procedure Grava_Hd_Porcentagem; forward;
procedure Grava_Hd_Relogiogratis; forward;
procedure Grava_Hd_Relogiogratisvip; forward;
procedure Grava_Hd_Relogios; forward;
procedure Grava_Pendrive_Contadores; forward;
procedure Inicia_Tela; forward;
function Lecreditodocartao(P1: AnsiString): LongInt; forward;
procedure Le_Arquivo_De_Cadastro; forward;
procedure Le_Tocados; forward;
procedure Le_Touchscreen_Final; forward;
procedure Le_Touchscreen_Inicial; forward;
procedure Libera_Quantidadesdemusicastocadas; forward;
procedure Mensagemjpg(P1: AnsiString; P2: LongInt; P3: AnsiString); forward;
procedure Mensagemtravadajpg(P1: AnsiString; P2: LongInt; P3: AnsiString); forward;
procedure Mostra_Cds(P1: AnsiString); forward;
procedure Mostra_Cd_Exclusao(P1: LongInt); forward;
procedure Mostra_Fila; forward;
function Mostra_Jpg_Letra(P1: AnsiString): AnsiString; forward;
function Mostra_Jpg_Ritmo(P1: AnsiString): AnsiString; forward;
procedure Mostra_Letras; forward;
procedure Mostra_Musicas(P1: LongInt); forward;
procedure Mostra_Nome_Das_Musicas; forward;
procedure Mostra_Ritmos; forward;
procedure Mostra_Setas(P1: LongInt); forward;
procedure Mostra_Tela_Carregando_Cds; forward;
procedure Mostra_Tela_De_Sorteio; forward;
procedure Presstecla; forward;
procedure Rotina_Cancelar; forward;
procedure Rotina_Creditosvip; forward;
procedure Rotina_Creditos(P1: AnsiString); forward;
procedure Rotina_Menu; forward;
procedure Rotina_Ritmos; forward;
procedure Rotina_Tocar; forward;
procedure Rotina_Volumemais; forward;
procedure Rotina_Volumemenos; forward;
procedure Selecionamusica; forward;
function Strespaco(P1: AnsiString; P2: LongInt): AnsiString; forward;
function Strzero(P1: AnsiString; P2: LongInt): AnsiString; forward;
procedure Tela1; forward;
procedure Tela_De_Autoteste; forward;
function Tem_2X_Musica_Na_Fila: Boolean; forward;
procedure Voltamenu; forward;

{ JUKELINUX1_APAGA_CD$LONGINT$LONGINT }
procedure Apaga_Cd(P1: LongInt; P2: LongInt);
var
  local_1d0, local_1d4: AnsiString;
  cVar1: Boolean;
  iVar3, local_10, local_1a4, local_1b0, local_8, local_c: LongInt;
begin
  local_c := P2;
  local_8 := P1;
  begin
    // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_c * 0x240 + 0x1f8));
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_1d0 := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_1d0[0],"[.]") } then begin
          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_10, local_1d0);
          if False { C: STRNE(local_1d0[0],"[..]") } then begin
            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_10, &local_1d4);
            // C: fpc_ansistr_concat(local_1d0, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_c * 0x240 + 0x1f8), local_1d4);
            cVar1 := FileExists(local_1d0);
            if cVar1 then begin
              local_1a4 := local_1a4 + 1;
              // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_10, &local_1d4);
              // C: fpc_ansistr_concat(local_1b0 + local_1a4 * 4 + 0xc, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_c * 0x240 + 0x1f8), local_1d4);
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    iVar3 := local_1a4;
    local_10 := 1;
    if 0 < local_1a4 then begin
      repeat
        local_10 := local_10 + 1;
        // C: SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN( *(undefined4 * )(local_1b0 + local_10 * 4 + 0xc));
      until not (local_10 < iVar3);
    end;
    // C: SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_c * 0x240 + 0x1f8));
    // C: fpc_ansistr_concat(&local_1d4,"Apagar CD - ", *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_c * 0x240 + 0x1f8));
    Gravalog(local_1d4);
    RELECDS := 1;
    if local_8 = 1 then begin
      Form1.CDE1.Hide;
    end;
    if local_8 = 2 then begin
      Form1.CDE2.Hide;
    end;
    if local_8 = 3 then begin
      Form1.CDE3.Hide;
    end;
    if local_8 = 4 then begin
      Form1.CDE4.Hide;
    end;
    if local_8 = 5 then begin
      Form1.CDE5.Hide;
    end;
    if local_8 = 6 then begin
      Form1.CDE6.Hide;
    end;
  end;
end;

{ JUKELINUX1_ATIVA_PROPAGANDA }
procedure Ativa_Propaganda;
var
  local_30: AnsiString;
  iVar2: LongInt;
begin
  begin
    if TOCANDOMUSICA = 0 then begin
      iVar2 := Pos('TV/Monitor', PROPAGANDA);
      if 0 < iVar2 then begin
        TOCANDOVIDEOTV := 0;
      end;
      if PROPAGANDA = 'Fotos PNG no Monitor' then begin
        Form1.ImagePNG.Show;
      end;
      if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
        Form1.ImageJPG.Show;
      end;
      if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
        Form1.ImageJPG.Show;
      end;
      if PROPAGANDA = 'Fotos para Bar na TV' then begin
        Form1.ImageTV.Show;
      end;
      if PROPAGANDA = 'Fotos para Boate na TV' then begin
        Form1.ImageTV.Show;
      end;
    end
    else begin
      iVar2 := Pos('TV/Monitor', PROPAGANDA);
      if 0 < iVar2 then begin
        Form1.TimerTocandoTv.Enabled := False;
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.playtv);
        Form1.playtv.Hide;
        TOCANDOVIDEOTV := 0;
      end;
      if PROPAGANDA = 'Fotos PNG no Monitor' then begin
        Form1.ImagePNG.Hide;
      end;
      if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
        Form1.ImageJPG.Hide;
      end;
      if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
        Form1.ImageJPG.Hide;
      end;
      if PROPAGANDA = 'Fotos para Bar na TV' then begin
        Form1.ImageTV.Hide;
      end;
      if PROPAGANDA = 'Fotos para Boate na TV' then begin
        Form1.ImageTV.Hide;
      end;
    end;
    Form1.TimerPropaganda.Enabled := True;
    if TOTALPRO = 0 then begin
      Form1.TimerPropaganda.Enabled := False;
      local_30 := 'Nao tem Propagandas na pasta ' + PASTAPROPAGANDA;
      Gravalog(local_30);
    end;
  end;
end;

{ JUKELINUX1_BACKUPCARTAOCCC }
procedure Backupcartaoccc;
var
  local_10, local_3c, local_48, local_8, local_c: AnsiString;
  cVar2: Boolean;
  local_4c, uVar1: LongInt;
  local_40, local_44: Variant;
begin
  begin
    local_3c := PASTACHAVE + 'cartao';
    cVar2 := DirectoryExists(local_3c);
    if not cVar2 then begin
      local_3c := PASTACHAVE + 'cartao';
      CreateDir(local_3c);
      Sleep(100);
    end;
    local_10 := 'cartoes.ccc';
    local_8 := PASTA + 'cartoes.ccc';
    local_48 := PASTACHAVE;
    local_44 := 'cartao/';
    local_40 := local_10;
    local_c := local_48 + local_44 + local_40;
    // C: puVar4 = local_c;
    if False { C: local_c == (undefined1 * )0x0 } then begin
    end;
    // C: fpc_pchar_to_ansistr(puVar4,local_3c);
    // C: uVar1 = local_3c[0];
    // C: puVar4 = local_8;
    if False { C: local_8 == (undefined1 * )0x0 } then begin
    end;
    // C: fpc_pchar_to_ansistr(puVar4,&local_4c);
    // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_4c,uVar1,extraout_ECX & 0xffffff00);
    Sleep(25);
  end;
end;

{ JUKELINUX1_CARREGANDO_CARTOES }
procedure Carregando_Cartoes;
var
  local_150, local_154, local_158, local_168, local_16c, local_18, local_1c, local_258, local_48, local_4c, local_50: AnsiString;
  cVar1: Boolean;
  iVar3, local_10, local_14, local_8, local_c: LongInt;
  local_15c, local_160, local_164, local_25c, local_260: Variant;
begin
  begin
    repeat
      local_c := local_c + 1;
      // C: (&DAT_0930303a)[local_c * 0x26] = 0;
      // C: *(undefined1 * )((int)&U_JUKELINUX1_VOLUMEPELOPAINEL + local_c * 0x26 + 1) = 0;
      // C: (&DAT_0930305e)[local_c * 0x26] = 0;
    until not (local_c < 90000);
    KMMCARTAO := 0;
    Form1.FileListBox1.Directory := PASTA;
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_8 := -1;
      repeat
        local_8 := local_8 + 1;
        local_48 := Form1.FileListBox1.Items[local_8];
        if False { C: STRNE(local_48[0],"[.]") } then begin
          local_48 := Form1.FileListBox1.Items[local_8];
          if False { C: STRNE(local_48[0],"[..]") } then begin
            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8, &local_50);
            local_4c := ExtractFileExt(local_50);
            local_48 := UpperCase(local_4c);
            if local_48 = '.CAR' then begin
              // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8, &local_50);
              NOMEARQ := PASTA + local_50;
              cVar1 := FileExists(NOMEARQ);
              if cVar1 then begin
                local_150 := NOMEARQ;
                // C: OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING(U_JUKELINUX1_ARQCARTAOV,local_150);
                // C: fpc_reset_typed(U_JUKELINUX1_ARQCARTAOV,0x5e);
                // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOV);
                // C: FPC_TYPED_READ(0x5e,U_JUKELINUX1_ARQCARTAOV,U_JUKELINUX1_ACARV);
                while True do begin
                  // C: cVar1 = SYSTEM_EOF_file__BOOLEAN(U_JUKELINUX1_ARQCARTAOV);
                  if cVar1 then begin Break; end;
                  local_10 := local_10 + 1;
                  // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOV);
                  // C: FPC_TYPED_READ(0x5e,U_JUKELINUX1_ARQCARTAOV,U_JUKELINUX1_ACARV);
                  KMMCARTAO := KMMCARTAO + 1;
                  ACARV := local_4c;
                  local_50 := Descriptasuper(local_4c);
                  // C: FPC_ANSISTR_TO_SHORTSTR (&DAT_0930303a + U_JUKELINUX1_KMMCARTAO * 0x26,0x1e,local_50);
                end;
                // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_ARQCARTAOV);
              end;
            end;
          end;
        end;
      until not (local_8 < iVar3 + -1);
    end;
    TOTMMCARTAO := KMMCARTAO;
    NOMEARQ := PASTA + 'cartoes.ccc';
    cVar1 := FileExists(NOMEARQ);
    if not cVar1 then begin
      local_150 := NOMEARQ;
      // C: OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING(U_JUKELINUX1_ARQCARTAOM,local_150);
      // C: FPC_REWRITE_TYPED(U_JUKELINUX1_ARQCARTAOM,0x26);
      local_154 := DateToStr(Date);
      local_50 := Cripta(local_154);
      ACARM := local_50;
      ACARM := local_154;
      local_18 := Descripta(local_154);
      // C: U_JUKELINUX1_ACARM[0x1f] = 0;
      // C: U_JUKELINUX1_ACARM[0x24] = 0;
      // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOM);
      // C: FPC_TYPED_WRITE(0x26,U_JUKELINUX1_ARQCARTAOM,U_JUKELINUX1_ACARM);
      // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_ARQCARTAOM);
    end;
    cVar1 := FileExists(NOMEARQ);
    if cVar1 then begin
      local_150 := NOMEARQ;
      // C: OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING(U_JUKELINUX1_ARQCARTAOM,local_150);
      // C: fpc_reset_typed(U_JUKELINUX1_ARQCARTAOM,0x26);
      // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOM);
      // C: FPC_TYPED_READ(0x26,U_JUKELINUX1_ARQCARTAOM,U_JUKELINUX1_ACARM);
      ACARM := local_154;
      local_18 := Descripta(local_154);
      while True do begin
        // C: cVar1 = SYSTEM_EOF_file__BOOLEAN(U_JUKELINUX1_ARQCARTAOM);
        if cVar1 then begin Break; end;
        local_10 := local_10 + 1;
        // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOM);
        // C: FPC_TYPED_READ(0x26,U_JUKELINUX1_ARQCARTAOM,U_JUKELINUX1_ACARM);
        ACARM := local_154;
        local_1c := Descripta(local_154);
        iVar3 := TOTMMCARTAO;
        local_14 := 1;
        if 0 < TOTMMCARTAO then begin
          repeat
            local_14 := local_14 + 1;
            // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_154);
            if local_154 = local_1c then begin
              // C: fpc_shortstr_to_ansistr(0x964703f,&local_158);
              local_154 := Descripta(local_158);
              // C: FPC_ANSISTR_TO_SHORTSTR(local_14 * 0x26 + 0x9303059,4,local_154);
              // C: fpc_shortstr_to_ansistr(0x9647044,&local_154);
              local_158 := Descripta(local_154);
              // C: FPC_ANSISTR_TO_SHORTSTR(&DAT_0930305e + local_14 * 0x26,1,local_158);
            end;
          until not (local_14 < iVar3);
        end;
        KMMCARTAO := KMMCARTAO + 1;
        ACARM := local_154;
        local_158 := Descriptasuper(local_154);
        // C: FPC_ANSISTR_TO_SHORTSTR(&DAT_0930303a + U_JUKELINUX1_KMMCARTAO * 0x26,0x1e,local_158);
      end;
      // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_ARQCARTAOM);
    end;
    local_158 := PASTA + 'aacartoes.txt';
    local_258 := local_158;
    AssignFile(ARQTEXTO, local_258);
    Rewrite(ARQTEXTO);
    Write(ARQTEXTO, local_18);
    Writeln(ARQTEXTO);
    iVar3 := TOTMMCARTAO;
    local_14 := 1;
    if 0 < TOTMMCARTAO then begin
      repeat
        local_14 := local_14 + 1;
        // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_154);
        local_16c := local_154;
        local_168 := ' - ';
        // C: fpc_shortstr_to_ansistr(local_14 * 0x26 + 0x9303059,&local_25c);
        local_164 := local_25c;
        local_160 := ' - ';
        // C: fpc_shortstr_to_ansistr(&DAT_0930305e + local_14 * 0x26,&local_260);
        local_15c := local_260;
        local_158 := local_16c + local_168 + local_164 + local_160 + local_15c;
        Write(ARQTEXTO, local_158);
        Writeln(ARQTEXTO);
      until not (local_14 < iVar3);
    end;
    CloseFile(ARQTEXTO);
  end;
end;

{ JUKELINUX1_CARREGANDO_CDS }
procedure Carregando_Cds;
label
  LAB_0809cd38;
var
  iStack_478b24, iStack_478b68, iStack_478c6c, iStack_478c70, iStack_478c74, iStack_478c78, iStack_478c7c, iStack_478d8c, local_28, local_34, local_38, uStack_478b20, uStack_478b64, uStack_478c80, uStack_478c84, uStack_478d88, uStack_478d98, uStack_478da0, uStack_478e90, uStack_478e94, uStack_478f98, uStack_478f9c, uVar5: AnsiString;
  cVar1: Boolean;
  iStack_465288, iStack_474c90, iStack_474c94, iStack_474c98, iStack_478b28, iStack_478b60, iVar3, iVar4, iVar6, iVar7, local_10, local_14, local_18, local_1c, local_20, local_24, local_278, local_2c, local_30, local_8, local_c, uStack_478d94: LongInt;
begin
  // C: aiStack_474c8c[0] = 0;
  uStack_478b20 := '';
  iStack_478b24 := '';
  uStack_478f9c := '';
  uStack_478f98 := '';
  uStack_478e94 := '';
  uStack_478e90 := '';
  iStack_478d8c := '';
  uStack_478d88 := '';
  uStack_478c84 := '';
  uStack_478c80 := '';
  iStack_478c7c := '';
  iStack_478c78 := '';
  iStack_478c74 := '';
  iStack_478c70 := '';
  iStack_478c6c := '';
  iStack_478b68 := '';
  // C: aiStack_478b58[0] = 0;
  begin
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    Form1.LabelLendo.Font.Color := 16777215;
    repeat
      local_8 := local_8 + 1;
      // C: U_JUKELINUX1_ARQLOG[local_8 * 0x240 + 0x1f0] = 0;
      iVar6 := local_8 * 576;
      // C: *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar6 + 0x1f8) = 0;
      iVar6 := local_8 * 576;
      // C: *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar6 + 0x1fc) = 0;
      iVar6 := local_8 * 576;
      // C: *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar6 + 0x200) = 0;
      iVar6 := local_8 * 576;
      // C: *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar6 + 0x204) = 0;
      // C: U_JUKELINUX1_ARQLOG[local_8 * 0x240 + 0x208] = 0;
      repeat
        iVar6 := local_c + 1;
        iVar7 := local_8 * 576;
        local_c := iVar6;
        // C: *(undefined4 * )(iVar7 + 0x8e91144 + iVar6 * 4) = 0;
      until not (local_c < 40);
      repeat
        iVar7 := local_8;
        iVar6 := local_c + 1;
        local_c := iVar6;
        // C: (&U_JUKELINUX1_PASTACHAVE9)[iVar7 * 0x90 + iVar6] = 0;
      until not (local_c < 40);
      // C: (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] = 0;
      // C: *(undefined1 * )(&U_JUKELINUX1_SERIAL + local_8 * 0x90) = 0;
      // C: *(undefined1 * )(&U_JUKELINUX1_TECLAMUSICAMAIS + local_8 * 0x90) = 0;
      repeat
        local_c := local_c + 1;
        // C: (&U_JUKELINUX1_TECLACDMENOS)[local_8 * 0x90 + local_c] = 0;
      until not (local_c < 40);
      // C: *(undefined1 * )(&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x90) = 0;
      // C: *(undefined1 * )((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) = 0;
      // C: *(undefined1 * )(&U_JUKELINUX1_BAIRROSTR + local_8 * 0x90) = 0;
      // C: (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] = 0;
    until not (local_8 < 8000);
    Form1.LabelLendo.Caption := 'Lendos as Pastas dos CDS e DVDs';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    cVar1 := DirectoryExists(PASTAMUSICAS);
    if not cVar1 then begin
      CreateDir(PASTAMUSICAS);
    end;
    Form1.FileListBox1.Directory := PASTAMUSICAS;
    KMAT := 0;
    iVar6 := Form1.FileListBox1.Count;
    if -1 < iVar6 + -1 then begin
      local_8 := -1;
      repeat
        local_8 := local_8 + 1;
        // C: aiStack_478b58[0] = 0;
        // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58);
        if False { C: STRNE(aiStack_478b58[0],"[.]") } then begin
          // C: aiStack_478b58[0] = 0;
          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58);
          if False { C: STRNE(aiStack_478b58[0],"[..]") } then begin
            KMAT := KMAT + 1;
            uStack_478b64 := PASTAMUSICAS;
            // C: aiStack_478b58[0] = 0;
            // C: piVar8 = aiStack_478b58;
            iStack_478b68 := '';
            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,&iStack_478b68, piVar8);
            iVar7 := 0;
            if iStack_478b68 <> '' then begin
              // C: iVar7 = *(int * )(iStack_478b68 + -4);
            end;
            iStack_478b68 := '';
            iStack_478b68 := Form1.FileListBox1.Items[local_8];
            // C: fpc_ansistr_copy(iStack_478b68,2,iVar7 + -2,piVar8);
            // C: iStack_478b60 = aiStack_478b58[0];
            // C: puStack_478b5c = "/";
            // C: fpc_ansistr_concat_multi(U_JUKELINUX1_KMAT * 0x240 + 0x8e91118,&uStack_478b64,2);
            iStack_478b68 := '';
            // C: piVar8 = &iStack_478b68;
            // C: aiStack_478b58[0] = 0;
            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58, piVar8);
            iVar7 := 0;
            if False { C: aiStack_478b58[0] != 0 } then begin
              // C: iVar7 = *(int * )(aiStack_478b58[0] + -4);
            end;
            // C: aiStack_478b58[0] = 0;
            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,aiStack_478b58);
            // C: fpc_ansistr_copy(aiStack_478b58[0],2,iVar7 + -2,piVar8);
            // C: fpc_ansistr_concat(U_JUKELINUX1_KMAT * 0x240 + 0x8e9111c,iStack_478b68, "/");
            iStack_478b68 := '';
            // C: SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMAT * 0x240 + 0x1fc), &iStack_478b68);
            iVar7 := KMAT * 576;
            // C: *(int * )(U_JUKELINUX1_ARQLOG + iVar7 + 0x1fc) = iStack_478b68;
            // C: iVar7 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT (CONCAT31((int3)((uint)(U_JUKELINUX1_KMAT * 0x240) >> 8),0x2e), *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMAT * 0x240 + 0x1fc));
            if 0 < iVar7 then begin
              KMAT := KMAT + -1;
            end;
          end;
        end;
      until not (local_8 < iVar6 + -1);
    end;
    TOTALCDS := KMAT;
    Form1.LabelLendo.Caption := 'Lendos as Musicas dos CDs e DVDs';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    iVar6 := TOTALCDS;
    if 0 < TOTALCDS then begin
      repeat
        local_8 := local_8 + 1;
        iStack_478b68 := '';
        iStack_478b68 := PASTA + 'ultimocdlido.txt';
        // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478c68,0xff,iStack_478b68);
        // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478c68);
        Rewrite(ARQTEXTO);
        // C: fpc_write_text_ansistr (0,U_JUKELINUX1_ARQTEXTO, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8));
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        // C: cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8));
        if cVar1 then begin
          // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8));
          KMATMUSICA := 0;
          iVar7 := Form1.FileListBox1.Count;
          if -1 < iVar7 + -1 then begin
            local_c := -1;
            repeat
              local_c := local_c + 1;
              iStack_478b68 := '';
              iStack_478b68 := Form1.FileListBox1.Items[local_c];
              if False { C: STRNE(iStack_478b68,"[.]") } then begin
                iStack_478b68 := '';
                // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c,&iStack_478b68 );
                if False { C: STRNE(iStack_478b68,"[..]") } then begin
                  iStack_478b68 := '';
                  iStack_478c6c := '';
                  iStack_478c70 := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c70);
                  iStack_478c6c := ExtractFileExt(iStack_478c70);
                  iStack_478b68 := UpperCase(iStack_478c6c);
                  // C: iVar3 = fpc_ansistr_compare_equal(iStack_478b68,".MP3");
                  if (iVar3 = 0) and (KMATMUSICA + 1 < 41) then begin
                    KMATMUSICA := KMATMUSICA + 1;
                    iStack_478c70 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c70);
                    // C: fpc_ansistr_concat(local_8 * 0x240 + 0x8e91144 + U_JUKELINUX1_KMATMUSICA * 4, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), iStack_478c70);
                    iStack_478c70 := '';
                    // C: piVar8 = &iStack_478c70;
                    iStack_478c6c := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c6c,piVar8);
                    iVar3 := 0;
                    if iStack_478c6c <> '' then begin
                      // C: iVar3 = *(int * )(iStack_478c6c + -4);
                    end;
                    iStack_478c6c := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c6c);
                    // C: fpc_ansistr_copy(iStack_478c6c,1,iVar3 + -4,piVar8);
                    iVar4 := local_8;
                    iVar3 := KMATMUSICA;
                    // C: fpc_ansistr_decr_ref (&U_JUKELINUX1_PASTACHAVE9 + local_8 * 0x90 + U_JUKELINUX1_KMATMUSICA);
                    // C: (&U_JUKELINUX1_PASTACHAVE9)[iVar4 * 0x90 + iVar3] = iStack_478c70;
                    // C: FPC_SHORTSTR_TO_SHORTSTR (&U_JUKELINUX1_SERIAL + local_8 * 0x90,3,"CD");
                  end;
                  iStack_478c70 := '';
                  iStack_478c6c := '';
                  iStack_478c74 := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c74);
                  iStack_478c6c := ExtractFileExt(iStack_478c74);
                  iStack_478c70 := UpperCase(iStack_478c6c);
                  // C: iVar3 = fpc_ansistr_compare_equal(iStack_478c70,".MPG");
                  if (iVar3 = 0) and (KMATMUSICA + 1 < 41) then begin
                    KMATMUSICA := KMATMUSICA + 1;
                    iStack_478c74 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c74);
                    // C: fpc_ansistr_concat(local_8 * 0x240 + 0x8e91144 + U_JUKELINUX1_KMATMUSICA * 4, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), iStack_478c74);
                    iStack_478c74 := '';
                    // C: piVar8 = &iStack_478c74;
                    iStack_478c70 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c70,piVar8);
                    iVar3 := 0;
                    if iStack_478c70 <> '' then begin
                      // C: iVar3 = *(int * )(iStack_478c70 + -4);
                    end;
                    iStack_478c70 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c70);
                    // C: fpc_ansistr_copy(iStack_478c70,1,iVar3 + -4,piVar8);
                    iVar4 := local_8;
                    iVar3 := KMATMUSICA;
                    // C: fpc_ansistr_decr_ref (&U_JUKELINUX1_PASTACHAVE9 + local_8 * 0x90 + U_JUKELINUX1_KMATMUSICA);
                    // C: (&U_JUKELINUX1_PASTACHAVE9)[iVar4 * 0x90 + iVar3] = iStack_478c74;
                    // C: FPC_SHORTSTR_TO_SHORTSTR (&U_JUKELINUX1_SERIAL + local_8 * 0x90,3,"DVD");
                  end;
                  iStack_478c74 := '';
                  iStack_478c70 := '';
                  iStack_478c78 := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c78);
                  iStack_478c70 := ExtractFileExt(iStack_478c78);
                  iStack_478c74 := UpperCase(iStack_478c70);
                  // C: iVar3 = fpc_ansistr_compare_equal(iStack_478c74,".MP4");
                  if (iVar3 = 0) and (KMATMUSICA + 1 < 41) then begin
                    KMATMUSICA := KMATMUSICA + 1;
                    iStack_478c78 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c78);
                    // C: fpc_ansistr_concat(local_8 * 0x240 + 0x8e91144 + U_JUKELINUX1_KMATMUSICA * 4, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), iStack_478c78);
                    iStack_478c78 := '';
                    // C: piVar8 = &iStack_478c78;
                    iStack_478c74 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c74,piVar8);
                    iVar3 := 0;
                    if iStack_478c74 <> '' then begin
                      // C: iVar3 = *(int * )(iStack_478c74 + -4);
                    end;
                    iStack_478c74 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c74);
                    // C: fpc_ansistr_copy(iStack_478c74,1,iVar3 + -4,piVar8);
                    iVar4 := local_8;
                    iVar3 := KMATMUSICA;
                    // C: fpc_ansistr_decr_ref (&U_JUKELINUX1_PASTACHAVE9 + local_8 * 0x90 + U_JUKELINUX1_KMATMUSICA);
                    // C: (&U_JUKELINUX1_PASTACHAVE9)[iVar4 * 0x90 + iVar3] = iStack_478c78;
                    // C: FPC_SHORTSTR_TO_SHORTSTR (&U_JUKELINUX1_SERIAL + local_8 * 0x90,3,"DVD");
                  end;
                  iStack_478c78 := '';
                  iStack_478c74 := '';
                  iStack_478c7c := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c7c);
                  iStack_478c74 := ExtractFileExt(iStack_478c7c);
                  iStack_478c78 := UpperCase(iStack_478c74);
                  // C: iVar3 = fpc_ansistr_compare_equal(iStack_478c78,".MKV");
                  if (iVar3 = 0) and (KMATMUSICA + 1 < 41) then begin
                    KMATMUSICA := KMATMUSICA + 1;
                    iStack_478c7c := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c7c);
                    // C: fpc_ansistr_concat(local_8 * 0x240 + 0x8e91144 + U_JUKELINUX1_KMATMUSICA * 4, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), iStack_478c7c);
                    iStack_478c7c := '';
                    // C: piVar8 = &iStack_478c7c;
                    iStack_478c78 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c78,piVar8);
                    iVar3 := 0;
                    if iStack_478c78 <> '' then begin
                      // C: iVar3 = *(int * )(iStack_478c78 + -4);
                    end;
                    iStack_478c78 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c78);
                    // C: fpc_ansistr_copy(iStack_478c78,1,iVar3 + -4,piVar8);
                    iVar4 := local_8;
                    iVar3 := KMATMUSICA;
                    // C: fpc_ansistr_decr_ref (&U_JUKELINUX1_PASTACHAVE9 + local_8 * 0x90 + U_JUKELINUX1_KMATMUSICA);
                    // C: (&U_JUKELINUX1_PASTACHAVE9)[iVar4 * 0x90 + iVar3] = iStack_478c7c;
                    // C: FPC_SHORTSTR_TO_SHORTSTR (&U_JUKELINUX1_SERIAL + local_8 * 0x90,3,"DVD");
                  end;
                  iStack_478c7c := '';
                  iStack_478c78 := '';
                  uStack_478c80 := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c80);
                  iStack_478c78 := ExtractFileExt(uStack_478c80);
                  iStack_478c7c := UpperCase(iStack_478c78);
                  // C: iVar3 = fpc_ansistr_compare_equal(iStack_478c7c,".WMA");
                  if (iVar3 = 0) and (KMATMUSICA + 1 < 41) then begin
                    KMATMUSICA := KMATMUSICA + 1;
                    uStack_478c80 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c80);
                    // C: fpc_ansistr_concat(local_8 * 0x240 + 0x8e91144 + U_JUKELINUX1_KMATMUSICA * 4, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478c80);
                    uStack_478c80 := '';
                    // C: puVar9 = &uStack_478c80;
                    iStack_478c7c := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c7c,puVar9);
                    iVar3 := 0;
                    if iStack_478c7c <> '' then begin
                      // C: iVar3 = *(int * )(iStack_478c7c + -4);
                    end;
                    iStack_478c7c := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478c7c);
                    // C: fpc_ansistr_copy(iStack_478c7c,1,iVar3 + -4,puVar9);
                    iVar4 := local_8;
                    iVar3 := KMATMUSICA;
                    // C: fpc_ansistr_decr_ref (&U_JUKELINUX1_PASTACHAVE9 + local_8 * 0x90 + U_JUKELINUX1_KMATMUSICA);
                    // C: (&U_JUKELINUX1_PASTACHAVE9)[iVar4 * 0x90 + iVar3] = uStack_478c80;
                    // C: FPC_SHORTSTR_TO_SHORTSTR (&U_JUKELINUX1_SERIAL + local_8 * 0x90,3,"CD");
                  end;
                  uStack_478c80 := '';
                  iStack_478c7c := '';
                  uStack_478c84 := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c84);
                  iStack_478c7c := ExtractFileExt(uStack_478c84);
                  uStack_478c80 := UpperCase(iStack_478c7c);
                  if uStack_478c80 = '.JPG' then begin
                    uStack_478c84 := '';
                    uStack_478c80 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c80);
                    uStack_478c84 := ExtractFileName(uStack_478c80);
                    if uStack_478c84 = 'capapequena.jpg' then begin
                      uStack_478c84 := '';
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c84);
                      // C: fpc_ansistr_concat(local_8 * 0x240 + 0x8e91124, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478c84);
                    end
                    else begin
                      uStack_478c84 := '';
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c84);
                      // C: fpc_ansistr_concat(local_8 * 0x240 + 0x8e91120, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478c84);
                    end;
                  end;
                  uStack_478c84 := '';
                  uStack_478c80 := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c80);
                  uStack_478c84 := UpperCase(uStack_478c80);
                  if uStack_478c84 = 'GENERO.TXT' then begin
                    uStack_478c84 := '';
                    uStack_478c80 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c80);
                    // C: fpc_ansistr_concat(&uStack_478c84, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478c80);
                    cVar1 := FileExists(uStack_478c84);
                    if cVar1 then begin
                      uStack_478c84 := '';
                      uStack_478c80 := '';
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478c80);
                      // C: fpc_ansistr_concat(&uStack_478c84, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478c80);
                      // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478d84,0xff,uStack_478c84);
                      // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478d84);
                      Reset(ARQTEXTO);
                      Read(ARQTEXTO, local_28);
                      Readln(ARQTEXTO);
                      CloseFile(ARQTEXTO);
                      uStack_478c84 := '';
                      // C: puVar9 = &uStack_478c84;
                      uStack_478c80 := '';
                      uStack_478c80 := UpperCase(local_28);
                      // C: fpc_ansistr_copy(uStack_478c80,1,2,puVar9);
                      if uStack_478c84 = 'AX' then begin
                        iVar3 := 0;
                        if False { C: local_28 != (char * )0x0 } then begin
                          // C: iVar3 = *(int * )(local_28 + -4);
                        end;
                        if iVar3 = 3 then begin
                          local_28 := 'AXE';
                        end;
                      end;
                      uStack_478c84 := '';
                      // C: puVar9 = &uStack_478c84;
                      uStack_478d88 := '';
                      uStack_478d88 := UpperCase(local_28);
                      // C: fpc_ansistr_copy(uStack_478d88,1,4,puVar9);
                      if uStack_478c84 = 'FORR' then begin
                        iVar3 := 0;
                        if False { C: local_28 != (char * )0x0 } then begin
                          // C: iVar3 = *(int * )(local_28 + -4);
                        end;
                        if iVar3 = 5 then begin
                          local_28 := 'FORRO';
                        end;
                      end;
                      // C: iVar3 = fpc_ansistr_compare_equal(U_JUKELINUX1_LETRASEXE,"BRG");
                      if iVar3 <> 0 then begin
                        uStack_478d88 := '';
                        // C: puVar9 = &uStack_478d88;
                        uStack_478c84 := '';
                        uStack_478c84 := UpperCase(local_28);
                        // C: fpc_ansistr_copy(uStack_478c84,1,6,puVar9);
                        if uStack_478d88 = 'REEGAE' then begin
                          local_28 := 'REGGAE';
                        end;
                      end;
                      uStack_478d88 := '';
                      // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&uStack_478d88);
                      if uStack_478d88 <> ' LANCAMENTOS' then begin
                        uStack_478d88 := '';
                        uStack_478d88 := UpperCase(local_28);
                        // C: FPC_ANSISTR_TO_SHORTSTR(local_8 * 0x240 + 0x8e91128,0x1e,uStack_478d88);
                      end;
                    end;
                  end;
                  uStack_478d88 := '';
                  uStack_478c84 := '';
                  iStack_478d8c := '';
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &iStack_478d8c);
                  uStack_478c84 := ExtractFileExt(iStack_478d8c);
                  uStack_478d88 := UpperCase(uStack_478c84);
                  if uStack_478d88 = '.ATU' then begin
                    iStack_478d8c := '';
                    iStack_478d8c := PASTA + 'apagaatu.txt';
                    cVar1 := FileExists(iStack_478d8c);
                    if cVar1 then begin
                      iStack_478d8c := '';
                      uStack_478d88 := '';
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478d88);
                      // C: fpc_ansistr_concat(&iStack_478d8c, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478d88);
                      DeleteFile(iStack_478d8c);
                    end;
                    iStack_478d8c := '';
                    uStack_478d88 := '';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478d88);
                    // C: fpc_ansistr_concat(&iStack_478d8c, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478d88);
                    cVar1 := FileExists(iStack_478d8c);
                    if cVar1 then begin
                      iStack_478d8c := '';
                      uStack_478d88 := '';
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_c, &uStack_478d88);
                      // C: fpc_ansistr_concat(&iStack_478d8c, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8), uStack_478d88);
                      // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478e8c,0xff,iStack_478d8c);
                      // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478e8c);
                      Reset(ARQTEXTO);
                      Read(ARQTEXTO, uStack_478b20);
                      Readln(ARQTEXTO);
                      Read(ARQTEXTO, iStack_478b24);
                      Readln(ARQTEXTO);
                      CloseFile(ARQTEXTO);
                      // ?: BAIRROSTR + local_8 * 144 := iStack_478b24;
                      iStack_478b28 := StrToIntDef(uStack_478b20, 0);
                      iStack_478d8c := '';
                      iStack_478d8c := iStack_478b24;
                      // C: uVar5 = 0;
                      if iStack_478b24 <> '' then begin
                        // C: uVar5 = *(undefined4 * )(iStack_478b24 + -4);
                      end;
                      // C: SYSUTILS_STRTODATE_PCHAR_LONGINT_ANSISTRING_CHAR__TDATETIME (iStack_478b24,uVar5,PTR___SYSUTILS__Ld2_08d69698,0);
                      // ?: uStack_478d94 := (double)in_ST0;
                      // ?: in_ST0 := in_ST2;
                      // ?: in_ST2 := in_ST4;
                      // ?: in_ST4 := in_ST6;
                      // ?: in_ST6 := in_ST7;
                      Date;
                      // ?: in_ST7 := in_ST6;
                      // C: iVar3 = DATEUTILS_DAYSBETWEEN_TDATETIME_TDATETIME__LONGINT();
                      if iVar3 < iStack_478b28 then begin
                        iStack_478d8c := '';
                        // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&iStack_478d8c);
                        if iStack_478d8c = '' then begin
                          // C: *(undefined2 * )((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) = 0x5301;
                          iStack_478d8c := '';
                          iStack_478d8c := UpperCase(' LANCAMENTOS');
                          // C: FPC_ANSISTR_TO_SHORTSTR(local_8 * 0x240 + 0x8e91128,0x1e,iStack_478d8c);
                        end
                        else begin
                          // ?: cStack_478b2c := 0;
                          // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0x80) )(Form1.ListBoxRInativo.Items);
                          if -1 < iVar3 + -1 then begin
                            local_10 := -1;
                            repeat
                              local_10 := local_10 + 1;
                              iStack_478d8c := '';
                              iStack_478d8c := Form1.ListBoxRInativo.Items[local_10];
                              uStack_478e90 := '';
                              // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&uStack_478e90);
                              if uStack_478e90 = iStack_478d8c then begin
                                // ?: cStack_478b2c := 1;
                              end;
                            until not (local_10 < iVar3 + -1);
                          end;
                          if False then begin // ?: cStack_478b2c = 0
                            // C: *(undefined2 * )((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) = 0x5301;
                            uStack_478e90 := '';
                            uStack_478e90 := UpperCase(' LANCAMENTOS');
                            // C: FPC_ANSISTR_TO_SHORTSTR(local_8 * 0x240 + 0x8e91128,0x1e,uStack_478e90);
                          end;
                        end;
                      end
                      else begin
                        // C: *(undefined2 * )((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) = 0x4e01;
                      end;
                    end;
                  end;
                end;
              end;
            until not (local_c < iVar7 + -1);
          end;
          // C: (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] = U_JUKELINUX1_KMATMUSICA;
          // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x200));
          if cVar1 then begin
            // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x204));
            if cVar1 then begin goto LAB_0809cd38; end;
          end;
          // C: (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] = 0;
        end;
        LAB_0809cd38: ;
      until not (local_8 < iVar6);
    end;
    iVar6 := TOTALCDS;
    iStack_465288 := 0;
    local_20 := TOTALCDS;
    if 0 < TOTALCDS then begin
      repeat
        local_8 := local_8 + 1;
        // ?: cStack_478b2c := 0;
        // C: iVar7 = ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0x80)) (Form1.ListBoxRInativo.Items);
        if -1 < iVar7 + -1 then begin
          local_c := -1;
          repeat
            local_c := local_c + 1;
            uStack_478e90 := '';
            uStack_478e90 := Form1.ListBoxRInativo.Items[local_c];
            // C: uVar5 = uStack_478e90;
            iStack_478d8c := '';
            // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&iStack_478d8c);
            if iStack_478d8c = uVar5 then begin
              // ?: cStack_478b2c := 1;
            end;
          until not (local_c < iVar7 + -1);
        end;
        if False { C: (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] == 0 } then begin
          // ?: cStack_478b2c := 1;
        end;
        if False then begin // ?: cStack_478b2c = 0
          iStack_465288 := iStack_465288 + 1;
          // C: fpc_copy_proc(local_8 * 0x240 + 0x8e91110,auStack_4654c4 + iStack_465288 * 0x240, INIT_JUKELINUX1_TIPOCD);
        end;
      until not (local_8 < iVar6);
    end;
    iVar6 := iStack_465288;
    TOTALCDS := iStack_465288;
    local_8 := 1;
    if 0 < iStack_465288 then begin
      repeat
        local_8 := local_8 + 1;
        // C: fpc_copy_proc(auStack_4654c4 + local_8 * 0x240,local_8 * 0x240 + 0x8e91110, INIT_JUKELINUX1_TIPOCD);
      until not (local_8 < iVar6);
    end;
    Form1.LabelLendo.Caption := 'Ordenando os CDs e DVDs';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    local_20 := TOTALCDS;
    repeat
      local_2c := 0;
      iVar6 := local_20 + -1;
      local_8 := 1;
      if 0 < iVar6 then begin
        repeat
          local_8 := local_8 + 1;
          uStack_478e90 := '';
          uStack_478e90 := Copy(ORDEMDOSCDS, 1, 1);
          if uStack_478e90 = 'R' then begin
            uStack_478e90 := '';
            // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&uStack_478e90);
            // C: fpc_ansistr_concat(&local_34,uStack_478e90, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1fc));
            uStack_478e90 := '';
            // C: fpc_shortstr_to_ansistr((local_8 + 1) * 0x240 + 0x8e91128,&uStack_478e90);
            // C: fpc_ansistr_concat(&local_38,uStack_478e90, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 1) * 0x240 + 0x1fc));
          end;
          uStack_478e90 := '';
          uStack_478e90 := Copy(ORDEMDOSCDS, 1, 1);
          if uStack_478e90 = 'A' then begin
            iVar7 := local_8 * 576;
            // C: local_34 = *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar7 + 0x1fc);
            iVar7 := (local_8 + 1) * 576;
            // C: local_38 = *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar7 + 0x1fc);
          end;
          // C: iVar7 = fpc_ansistr_compare(local_34,local_38);
          if 0 < iVar7 then begin
            // C: fpc_copy_proc(local_8 * 0x240 + 0x8e91110,local_278,INIT_JUKELINUX1_TIPOCD);
            // C: fpc_copy_proc((local_8 + 1) * 0x240 + 0x8e91110,local_8 * 0x240 + 0x8e91110, INIT_JUKELINUX1_TIPOCD);
            // C: fpc_copy_proc(local_278,(local_8 + 1) * 0x240 + 0x8e91110,INIT_JUKELINUX1_TIPOCD);
            local_2c := 1;
          end;
        until not (local_8 < iVar6);
      end;
      local_20 := local_20 + -1;
    until not (local_2c <> 0);
    uStack_478e90 := '';
    uStack_478e90 := PASTA + 'tocados.txt';
    cVar1 := FileExists(uStack_478e90);
    iVar6 := TOTALCDS;
    if cVar1 then begin
      local_18 := 1;
      if 0 < TOTALCDS then begin
        repeat
          local_18 := local_18 + 1;
          // C: (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90] = 0;
        until not (local_18 < iVar6);
      end;
      uStack_478e90 := '';
      uStack_478e90 := PASTA + 'tocados.txt';
      // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478e8c,0xff,uStack_478e90);
      // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478e8c);
      Reset(ARQTEXTO);
      while True do begin
        cVar1 := Eof(ARQTEXTO);
        if cVar1 then begin Break; end;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        iVar6 := TOTALCDS;
        local_24 := local_24 + 1;
        local_18 := 1;
        if 0 < TOTALCDS then begin
          repeat
            local_18 := local_18 + 1;
            // C: iVar7 = (&U_JUKELINUX1_NOMEDOCLIENTE)[local_18 * 0x90];
            local_1c := 1;
            if 0 < iVar7 then begin
              repeat
                local_1c := local_1c + 1;
                // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * )(local_18 * 0x240 + 0x8e91144 + local_1c * 4), U_JUKELINUX1_TEXTO);
                if iVar3 = 0 then begin
                  // C: (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90] = (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90] + 1;
                  // C: (&U_JUKELINUX1_TECLACDMENOS)[local_18 * 0x90 + local_1c] = (&U_JUKELINUX1_TECLACDMENOS)[local_18 * 0x90 + local_1c] + 1;
                end;
              until not (local_1c < iVar7);
            end;
          until not (local_18 < iVar6);
        end;
      end;
      CloseFile(ARQTEXTO);
      iVar6 := TOTALCDS;
      if 0 < local_24 then begin
        local_18 := 1;
        if 0 < TOTALCDS then begin
          repeat
            local_18 := local_18 + 1;
            iVar3 := local_18 * 576;
            iVar7 := local_18;
            // C: aiStack_474c8c[iVar7 + 8000] = *(int * )(U_JUKELINUX1_ARQLOG + iVar3 + 0x1f8);
            // C: aiStack_474c8c[local_18] = (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90];
          until not (local_18 < iVar6);
        end;
        local_20 := TOTALCDS;
        repeat
          local_2c := 0;
          iVar6 := local_20 + -1;
          local_8 := 1;
          if 0 < iVar6 then begin
            repeat
              iVar3 := local_8;
              iVar7 := local_8 + 1;
              // C: iStack_474c90 = aiStack_474c8c[iVar7];
              // C: iStack_474c94 = aiStack_474c8c[local_8 + 2];
              if iStack_474c90 < iStack_474c94 then begin
                iVar4 := local_8 + 8001;
                local_8 := iVar7;
                iVar7 := local_8;
                // C: aiStack_474c8c[0] = aiStack_474c8c[iVar3 + 0x1f41];
                // C: iStack_474c98 = aiStack_474c8c[local_8];
                iVar3 := local_8;
                // C: aiStack_474c8c[iVar3 + 8000] = aiStack_474c8c[iVar7 + 0x1f41];
                // C: aiStack_474c8c[local_8] = aiStack_474c8c[local_8 + 1];
                iVar7 := local_8;
                // C: aiStack_474c8c[iVar7 + 0x1f41] = aiStack_474c8c[0];
                // C: aiStack_474c8c[local_8 + 1] = iStack_474c98;
                local_2c := 1;
                iVar7 := local_8;
              end;
              local_8 := iVar7;
            until not (local_8 < iVar6);
          end;
          local_20 := local_20 + -1;
        until not (local_2c <> 0);
        local_20 := TOTALCDS;
        local_10 := TOTALCDS;
        repeat
          iVar6 := TOTALCDS;
          local_c := local_c + 1;
          if False { C: 0 < aiStack_474c8c[local_c] } then begin
            local_8 := 1;
            if 0 < TOTALCDS then begin
              repeat
                local_8 := local_8 + 1;
                if local_24 < 51 then begin
                  // C: iVar7 = fpc_ansistr_compare_equal (aiStack_474c8c[local_c + 8000], *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8));
                  if iVar7 = 0 then begin
                    local_14 := local_14 + 1;
                    // C: fpc_copy_proc(local_8 * 0x240 + 0x8e91110,auStack_4654c4 + local_14 * 0x240, INIT_JUKELINUX1_TIPOCD);
                    local_10 := local_10 + 1;
                    // C: fpc_copy_proc(local_8 * 0x240 + 0x8e91110,local_10 * 0x240 + 0x8e91110, INIT_JUKELINUX1_TIPOCD);
                    // C: FPC_SHORTSTR_TO_SHORTSTR(local_10 * 0x240 + 0x8e91128,0x1e,"50+TOCADOS");
                    uStack_478e90 := '';
                    uStack_478e90 := Copy(ORDEMDOSCDS, 1, 1);
                    if uStack_478e90 = 'A' then begin
                      // C: puStack_478da4 = " ";
                      uStack_478e90 := '';
                      uStack_478e90 := IntToStr(local_c);
                      uStack_478da0 := uStack_478e90;
                      // ?: pcStack_478d9c := 'o. - ';
                      uStack_478e94 := '';
                      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(aiStack_474c8c[local_c],&uStack_478e94);
                      uStack_478d98 := uStack_478e94;
                      // C: uStack_478d94 = (double)CONCAT44( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x1fc), "x - ");
                      // C: fpc_ansistr_concat_multi(local_10 * 0x240 + 0x8e9111c,&puStack_478da4,5);
                    end
                    else begin
                      uStack_478e94 := '';
                      uStack_478e94 := IntToStr(local_c);
                      uStack_478da0 := uStack_478e94;
                      // ?: pcStack_478d9c := 'o. - ';
                      uStack_478e90 := '';
                      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(aiStack_474c8c[local_c],&uStack_478e90);
                      uStack_478d98 := uStack_478e90;
                      // C: uStack_478d94 = (double)CONCAT44( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x1fc), "x - ");
                      // C: fpc_ansistr_concat_multi(local_10 * 0x240 + 0x8e9111c,&uStack_478da0,4);
                    end;
                    local_24 := local_24 + 1;
                  end;
                end;
              until not (local_8 < iVar6);
            end;
          end;
        until not (local_c < 50);
        TOTALCDS := local_10;
        // C: aiStack_478b1c[0] = 0;
        repeat
          local_18 := local_18 + 1;
          if False { C: 0 < aiStack_474c8c[local_18] } then begin
            // C: iVar6 = aiStack_46534c[local_18 * 0x90];
            local_1c := 1;
            if 0 < iVar6 then begin
              repeat
                iVar3 := local_18;
                iVar7 := local_1c + 1;
                local_1c := iVar7;
                if False { C: 0 < aiStack_46533c[local_18 * 0x90 + iVar7] } then begin
                  // C: aiStack_478b1c[0] = aiStack_478b1c[0] + 1;
                  // C: iVar4 = aiStack_478b1c[0];
                  // C: aiStack_478b1c[iVar4 + 2000] = aiStack_465490[iVar3 * 0x90 + iVar7];
                  // C: aiStack_478b1c[aiStack_478b1c[0]] = aiStack_46533c[local_18 * 0x90 + local_1c];
                end;
              until not (local_1c < iVar6);
            end;
          end;
        until not (local_18 < 50);
        local_20 := 50;
        repeat
          local_2c := 0;
          iVar6 := local_20 + -1;
          local_8 := 1;
          if 0 < iVar6 then begin
            repeat
              iVar3 := local_8;
              iVar7 := local_8 + 1;
              // C: iStack_474c90 = aiStack_478b1c[iVar7];
              // C: iStack_474c94 = aiStack_478b1c[local_8 + 2];
              if iStack_474c90 < iStack_474c94 then begin
                iVar4 := local_8 + 2001;
                local_8 := iVar7;
                iVar7 := local_8;
                // C: aiStack_474c8c[0] = aiStack_478b1c[iVar3 + 0x7d1];
                // C: iStack_474c98 = aiStack_478b1c[local_8];
                iVar3 := local_8;
                // C: aiStack_478b1c[iVar3 + 2000] = aiStack_478b1c[iVar7 + 0x7d1];
                // C: aiStack_478b1c[local_8] = aiStack_478b1c[local_8 + 1];
                iVar7 := local_8;
                // C: aiStack_478b1c[iVar7 + 0x7d1] = aiStack_474c8c[0];
                // C: aiStack_478b1c[local_8 + 1] = iStack_474c98;
                local_2c := 1;
                iVar7 := local_8;
              end;
              local_8 := iVar7;
            until not (local_8 < iVar6);
          end;
          local_20 := local_20 + -1;
        until not (local_2c <> 0);
        TOTALMG := 0;
        uStack_478e94 := '';
        uStack_478e94 := PASTA + '50musicasmaistocadas.txt';
        // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478f94,0xff,uStack_478e94);
        // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478f94);
        Rewrite(ARQTEXTO);
        repeat
          iVar7 := local_8;
          iVar6 := local_8 + 1;
          if False { C: 0 < aiStack_478b1c[iVar6] } then begin
            iVar3 := local_8 + 2001;
            local_8 := iVar6;
            iVar6 := local_8;
            // C: *(int * )(&DAT_0964721c + iVar6 * 4) = aiStack_478b1c[iVar7 + 0x7d1];
            TOTALMG := TOTALMG + 1;
            // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO,aiStack_478b1c[local_8 + 2000]);
            Writeln(ARQTEXTO);
            uStack_478e94 := '';
            // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(aiStack_478b1c[local_8],&uStack_478e94);
            Write(ARQTEXTO, uStack_478e94);
            Writeln(ARQTEXTO);
            iVar6 := local_8;
          end;
          local_8 := iVar6;
        until not (local_8 < 50);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        uStack_478e94 := '';
        uStack_478e94 := PASTA + 'limitedasmusicasmaistocadas.txt';
        cVar1 := FileExists(uStack_478e94);
        if not cVar1 then begin
          uStack_478e94 := '';
          uStack_478e94 := PASTA + 'limitedasmusicasmaistocadas.txt';
          // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478f94,0xff,uStack_478e94);
          // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478f94);
          Rewrite(ARQTEXTO);
          TEXTO := '50';
          Write(ARQTEXTO, '50');
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
        uStack_478e94 := '';
        uStack_478e94 := PASTA + 'limitedasmusicasmaistocadas.txt';
        cVar1 := FileExists(uStack_478e94);
        if cVar1 then begin
          uStack_478e94 := '';
          uStack_478e94 := PASTA + 'limitedasmusicasmaistocadas.txt';
          // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478f94,0xff,uStack_478e94);
          // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478f94);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
        LIMITEARQ := StrToIntDef(TEXTO, 50);
        if LIMITEARQ < TOTALMG then begin
          TOTALMG := LIMITEARQ;
        end;
        uStack_478e94 := '';
        uStack_478e94 := PASTA + 'inciarpela50maistocada.txt';
        cVar1 := FileExists(uStack_478e94);
        if not cVar1 then begin
          uStack_478e94 := '';
          uStack_478e94 := PASTA + 'inciarpela50maistocada.txt';
          // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478f94,0xff,uStack_478e94);
          // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478f94);
          Rewrite(ARQTEXTO);
          Write(ARQTEXTO, 48);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
        uStack_478e94 := '';
        uStack_478e94 := PASTA + 'inciarpela50maistocada.txt';
        cVar1 := FileExists(uStack_478e94);
        if cVar1 then begin
          uStack_478e94 := '';
          uStack_478e94 := PASTA + 'inciarpela50maistocada.txt';
          // C: FPC_ANSISTR_TO_SHORTSTR(auStack_478f94,0xff,uStack_478e94);
          // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_478f94);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
        POSMG := 0;
        POSMG := StrToIntDef(TEXTO, 0);
        if TOTALMG < POSMG then begin
          POSMG := 0;
        end;
      end;
    end;
    Form1.LabelLendo.Caption := 'Ordenando os CDs e DVDs';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    local_20 := TOTALCDS;
    repeat
      local_2c := 0;
      iVar6 := local_20 + -1;
      local_8 := 1;
      if 0 < iVar6 then begin
        repeat
          local_8 := local_8 + 1;
          uStack_478e94 := '';
          uStack_478e94 := Copy(ORDEMDOSCDS, 1, 1);
          if uStack_478e94 = 'R' then begin
            uStack_478e94 := '';
            // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&uStack_478e94);
            local_34 := uStack_478e94;
            uStack_478e94 := '';
            // C: fpc_shortstr_to_ansistr((local_8 + 1) * 0x240 + 0x8e91128,&uStack_478e94);
            local_38 := uStack_478e94;
          end;
          uStack_478e94 := '';
          uStack_478e94 := Copy(ORDEMDOSCDS, 1, 1);
          if uStack_478e94 = 'A' then begin
            iVar7 := local_8 * 576;
            // C: local_34 = *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar7 + 0x1fc);
            iVar7 := (local_8 + 1) * 576;
            // C: local_38 = *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar7 + 0x1fc);
          end;
          // C: iVar7 = fpc_ansistr_compare(local_34,local_38);
          if 0 < iVar7 then begin
            // C: fpc_copy_proc(local_8 * 0x240 + 0x8e91110,local_278,INIT_JUKELINUX1_TIPOCD);
            // C: fpc_copy_proc((local_8 + 1) * 0x240 + 0x8e91110,local_8 * 0x240 + 0x8e91110, INIT_JUKELINUX1_TIPOCD);
            // C: fpc_copy_proc(local_278,(local_8 + 1) * 0x240 + 0x8e91110,INIT_JUKELINUX1_TIPOCD);
            local_2c := 1;
          end;
        until not (local_8 < iVar6);
      end;
      local_20 := local_20 + -1;
    until not (local_2c <> 0);
    Form1.LabelLendo.Caption := 'Lendo Letras dos CDS e DVDs';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    KL := 0;
    repeat
      KL := KL + 1;
      iVar6 := KL;
      // C: (&U_JUKELINUX1_CDSELEAPAGARX)[iVar6] = 0;
      iVar6 := TOTALCDS;
    until not (KL < 100);
    TOTALMMLETRA := 0;
    local_8 := 1;
    if 0 < TOTALCDS then begin
      repeat
        local_8 := local_8 + 1;
        local_30 := 0;
        repeat
          local_c := local_c + 1;
          uStack_478e94 := '';
          // C: SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[local_c],&uStack_478e94);
          // C: uVar5 = uStack_478e94;
          uStack_478f98 := '';
          uStack_478f9c := '';
          // C: fpc_ansistr_copy( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1fc),1,1, &uStack_478f9c);
          uStack_478f98 := LowerCase(uStack_478f9c);
          if uStack_478f98 = uVar5 then begin
            local_30 := 1;
          end;
        until not (local_c < 100);
        if (local_30 = 0) and (TOTALMMLETRA < 101) then begin
          TOTALMMLETRA := TOTALMMLETRA + 1;
          uStack_478f9c := '';
          uStack_478f98 := '';
          // C: fpc_ansistr_copy( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1fc),1,1, &uStack_478f98);
          uStack_478f9c := LowerCase(uStack_478f98);
          iVar7 := TOTALMMLETRA;
          // C: (&U_JUKELINUX1_CDSELEAPAGARX)[iVar7] = uStack_478f9c;
        end;
      until not (local_8 < iVar6);
    end;
    uStack_478f9c := '';
    uStack_478f9c := PASTA + 'letras.txt';
    // C: FPC_ANSISTR_TO_SHORTSTR(auStack_47909c,0xff,uStack_478f9c);
    // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_47909c);
    Rewrite(ARQTEXTO);
    iVar6 := TOTALMMLETRA;
    local_8 := 1;
    if 0 < TOTALMMLETRA then begin
      repeat
        local_8 := local_8 + 1;
        // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO,(&U_JUKELINUX1_CDSELEAPAGARX)[local_8]);
        Writeln(ARQTEXTO);
      until not (local_8 < iVar6);
    end;
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    Form1.LabelLendo.Caption := 'Lendos as Generos Musicais dos CDS e DVDs';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    KR := 0;
    repeat
      KR := KR + 1;
      iVar6 := KR;
      // C: *(undefined4 * )(&DAT_092fffac + iVar6 * 4) = 0;
      iVar6 := TOTALCDS;
    until not (KR < 100);
    TOTALMMRITMO := 0;
    local_8 := 1;
    if 0 < TOTALCDS then begin
      repeat
        local_8 := local_8 + 1;
        local_30 := 0;
        repeat
          local_c := local_c + 1;
          uStack_478f9c := '';
          // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&uStack_478f9c);
          // C: iVar7 = fpc_ansistr_compare_equal (uStack_478f9c,*(undefined4 * )(&DAT_092fffac + local_c * 4));
          if iVar7 = 0 then begin
            local_30 := 1;
          end;
        until not (local_c < 100);
        if (local_30 = 0) and (TOTALMMRITMO < 101) then begin
          TOTALMMRITMO := TOTALMMRITMO + 1;
          uStack_478f9c := '';
          // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&uStack_478f9c);
          iVar7 := TOTALMMRITMO;
          // C: *(undefined4 * )(&DAT_092fffac + iVar7 * 4) = uStack_478f9c;
        end;
      until not (local_8 < iVar6);
    end;
    // C: ( **(code ** )( **(int ** )(Form1.ListBoxRAtivo + 0x364) + 0xb8)) (Form1.ListBoxRAtivo.Items);
    // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG1 + 0x36c) + 0xb8)) ( *(undefined4 * )(Form1.ComboBoxMG1 + 0x36c));
    // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG2 + 0x36c) + 0xb8)) ( *(undefined4 * )(Form1.ComboBoxMG2 + 0x36c));
    // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG3 + 0x36c) + 0xb8)) ( *(undefined4 * )(Form1.ComboBoxMG3 + 0x36c));
    // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG4 + 0x36c) + 0xb8)) ( *(undefined4 * )(Form1.ComboBoxMG4 + 0x36c));
    // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG5 + 0x36c) + 0xb8)) ( *(undefined4 * )(Form1.ComboBoxMG5 + 0x36c));
    // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG6 + 0x36c) + 0xb8)) ( *(undefined4 * )(Form1.ComboBoxMG6 + 0x36c));
    uStack_478f9c := '';
    uStack_478f9c := PASTA + 'ritmos.txt';
    // C: FPC_ANSISTR_TO_SHORTSTR(auStack_47909c,0xff,uStack_478f9c);
    // C: OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING(U_JUKELINUX1_ARQTEXTO,auStack_47909c);
    Rewrite(ARQTEXTO);
    iVar6 := TOTALMMRITMO;
    local_8 := 1;
    if 0 < TOTALMMRITMO then begin
      repeat
        local_8 := local_8 + 1;
        // C: ( **(code ** )( **(int ** )(Form1.ListBoxRAtivo + 0x364) + 0xa4)) (Form1.ListBoxRAtivo.Items, *(undefined4 * )(&DAT_092fffac + local_8 * 4));
        // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG1 + 0x36c) + 0xa4)) ( *(undefined4 * )(Form1.ComboBoxMG1 + 0x36c), *(undefined4 * )(&DAT_092fffac + local_8 * 4));
        // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG2 + 0x36c) + 0xa4)) ( *(undefined4 * )(Form1.ComboBoxMG2 + 0x36c), *(undefined4 * )(&DAT_092fffac + local_8 * 4));
        // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG3 + 0x36c) + 0xa4)) ( *(undefined4 * )(Form1.ComboBoxMG3 + 0x36c), *(undefined4 * )(&DAT_092fffac + local_8 * 4));
        // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG4 + 0x36c) + 0xa4)) ( *(undefined4 * )(Form1.ComboBoxMG4 + 0x36c), *(undefined4 * )(&DAT_092fffac + local_8 * 4));
        // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG5 + 0x36c) + 0xa4)) ( *(undefined4 * )(Form1.ComboBoxMG5 + 0x36c), *(undefined4 * )(&DAT_092fffac + local_8 * 4));
        // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG6 + 0x36c) + 0xa4)) ( *(undefined4 * )(Form1.ComboBoxMG6 + 0x36c), *(undefined4 * )(&DAT_092fffac + local_8 * 4));
        // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO,*(undefined4 * )(&DAT_092fffac + local_8 * 4));
        Writeln(ARQTEXTO);
      until not (local_8 < iVar6);
    end;
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
  end;
  uStack_478f9c := '';
  uStack_478f98 := '';
  uStack_478e94 := '';
  uStack_478e90 := '';
  iStack_478d8c := '';
  uStack_478d88 := '';
  uStack_478c84 := '';
  uStack_478c80 := '';
  iStack_478c7c := '';
  iStack_478c78 := '';
  iStack_478c74 := '';
  iStack_478c70 := '';
  iStack_478c6c := '';
  iStack_478b68 := '';
  // C: aiStack_478b58[0] = 0;
  // C: aiStack_474c8c[0] = 0;
  uStack_478b20 := '';
  iStack_478b24 := '';
end;

{ JUKELINUX1_CARREGANDO_KARAOKES }
procedure Carregando_Karaokes;
var
  local_34, local_38: AnsiString;
  cVar1: Boolean;
  iVar3, local_8, uVar5: LongInt;
begin
  begin
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    Form1.LabelLendo.Font.Color := 16777215;
    Form1.LabelLendo.Caption := 'Lendos as Pastas dos Karaokes';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    cVar1 := DirectoryExists(PASTAKARAOKES);
    if not cVar1 then begin
      CreateDir(PASTAKARAOKES);
    end;
    Form1.FileListBox1.Directory := PASTAKARAOKES;
    repeat
      iVar3 := local_8 + 1;
      local_8 := iVar3;
      // C: *(undefined4 * )(&DAT_092f635c + iVar3 * 4) = 0;
    until not (local_8 < 8000);
    KMATKARAOKE := 0;
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_8 := -1;
      repeat
        local_8 := local_8 + 1;
        local_34 := Form1.FileListBox1.Items[local_8];
        if False { C: STRNE(local_34[0],"[.]") } then begin
          local_34 := Form1.FileListBox1.Items[local_8];
          if False { C: STRNE(local_34[0],"[..]") } then begin
            KMATKARAOKE := KMATKARAOKE + 1;
            // C: puVar6 = local_34;
            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_8,&local_38,puVar6);
            // C: uVar5 = 0;
            if local_38 <> '' then begin
              // C: uVar5 = *(undefined4 * )(local_38 + -4);
            end;
            local_38 := Form1.FileListBox1.Items[local_8];
            // C: fpc_ansistr_copy(local_38,1,uVar5,puVar6);
            // C: fpc_ansistr_concat(&DAT_092f635c + U_JUKELINUX1_KMATKARAOKE * 4, U_JUKELINUX1_PASTAKARAOKES,local_34[0]);
          end;
        end;
      until not (local_8 < iVar3 + -1);
    end;
    TOTALKARAOKES := KMATKARAOKE;
  end;
end;

{ JUKELINUX1_CARREGANDO_PROPAGANDAS }
procedure Carregando_Propagandas;
var
  local_38, local_3c, local_40, local_c: AnsiString;
  cVar1: Boolean;
  iVar3, iVar4, local_8: LongInt;
begin
  begin
    KPRO := 0;
    repeat
      KPRO := KPRO + 1;
      iVar3 := KPRO;
      // C: (&U_JUKELINUX1_TOTALPRO)[iVar3] = 0;
    until not (KPRO < 500);
    PASTAPROPAGANDA := PASTA + 'propagandapngmonitor/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandajpgbarmonitor1366/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandajpgboatemonitor1366/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandajpgbarmonitor1024/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandajpgboatemonitor1024/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandajpgbartv/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandajpgboatetv/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandampgbartv/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandampgboatetv/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandampgbartv/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandampgboatetv/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    PASTAPROPAGANDA := PASTA + 'propagandapadraoaprova/';
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    if RESOLUCAO = 1024 then begin
      if PROPAGANDA = 'Fotos PNG no Monitor' then begin
        PROPAGANDA := 'Fotos para Bar no Monitor';
        Form1.ImagePNG.Hide;
      end;
    end;
    if PROPAGANDA = 'Sem Propaganda' then begin
      PASTAPROPAGANDA := PASTA;
    end;
    if PROPAGANDA = 'Fotos PNG no Monitor' then begin
      PASTAPROPAGANDA := PASTA + 'propagandapngmonitor/';
      local_c := '.PNG';
    end;
    if RESOLUCAO = 1366 then begin
      if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
        PASTAPROPAGANDA := PASTA + 'propagandajpgbarmonitor1366/';
        local_c := '.JPG';
      end;
      if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
        PASTAPROPAGANDA := PASTA + 'propagandajpgboatemonitor1366/';
        local_c := '.JPG';
      end;
    end;
    if RESOLUCAO = 1024 then begin
      if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
        PASTAPROPAGANDA := PASTA + 'propagandajpgbarmonitor1024/';
        local_c := '.JPG';
      end;
      if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
        PASTAPROPAGANDA := PASTA + 'propagandajpgboatemonitor1024/';
        local_c := '.JPG';
      end;
    end;
    if RESOLUCAO = 1440 then begin
      if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
        PASTAPROPAGANDA := PASTA + 'propagandajpgbarmonitor1366/';
        local_c := '.JPG';
      end;
      if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
        PASTAPROPAGANDA := PASTA + 'propagandajpgboatemonitor1366/';
        local_c := '.JPG';
      end;
    end;
    if PROPAGANDA = 'Fotos para Bar na TV' then begin
      PASTAPROPAGANDA := PASTA + 'propagandajpgbartv/';
      local_c := '.JPG';
    end;
    if PROPAGANDA = 'Fotos para Boate na TV' then begin
      PASTAPROPAGANDA := PASTA + 'propagandajpgboatetv/';
      local_c := '.JPG';
    end;
    if PROPAGANDA = 'Videos para Bar na TV/Monitor' then begin
      PASTAPROPAGANDA := PASTA + 'propagandampgbartv/';
      local_c := '.MPG';
    end;
    if PROPAGANDA = 'Videos para Boate na TV/Monitor' then begin
      PASTAPROPAGANDA := PASTA + 'propagandampgboatetv/';
      local_c := '.MPG';
    end;
    if PROPAGANDA = 'Videos para Bar na TV/Monitor enquanto Toca CD' then begin
      PASTAPROPAGANDA := PASTA + 'propagandampgbartv/';
      local_c := '.MPG';
    end;
    if PROPAGANDA = 'Videos para Boate na TV/Monitor enquanto Toca CD' then begin
      PASTAPROPAGANDA := PASTA + 'propagandampgboatetv/';
      local_c := '.MPG';
    end;
    if PROPAGANDA = 'Videos Padrao Aprova' then begin
      PASTAPROPAGANDA := PASTA + 'propagandapadraoaprova/';
      local_c := '.MPG';
    end;
    Form1.LabelLendo.Caption := 'Lendos as Propagandas';
    // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    cVar1 := DirectoryExists(PASTAPROPAGANDA);
    if not cVar1 then begin
      CreateDir(PASTAPROPAGANDA);
    end;
    Form1.FileListBox1.Directory := PASTAPROPAGANDA;
    KPRO := 0;
    TOTALPRO := 0;
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_8 := -1;
      repeat
        local_8 := local_8 + 1;
        local_38 := Form1.FileListBox1.Items[local_8];
        if False { C: STRNE(local_38[0],"[.]") } then begin
          local_38 := Form1.FileListBox1.Items[local_8];
          if False { C: STRNE(local_38[0],"[..]") } then begin
            local_40 := Form1.FileListBox1.Items[local_8];
            local_3c := ExtractFileExt(local_40);
            local_38 := UpperCase(local_3c);
            // C: iVar4 = fpc_ansistr_compare_equal(local_38[0],local_c);
            if False { C: (iVar4 == 0) && (U_JUKELINUX1_KPRO = U_JUKELINUX1_KPRO + 1, U_JUKELINUX1_KPRO < 0x1f5) } then begin
              local_40 := Form1.FileListBox1.Items[local_8];
              // ?: TOTALPRO + KPRO := PASTAPROPAGANDA + local_40;
            end;
          end;
        end;
      until not (local_8 < iVar3 + -1);
    end;
    TOTALPRO := KPRO;
    // C: ( **(code ** )( *(int * )Form1.TimerPropaganda + 0xdc))(Form1.TimerPropaganda,1);
    POSPRO := 0;
    if PROPAGANDA = 'Sem Propaganda' then begin
      Form1.TimerPropaganda.Enabled := False;
      if RESOLUCAO = 1024 then begin
        local_40 := PASTAPROPAGANDA + 'fundoempresamonitor1024.jpg';
        cVar1 := FileExists(local_40);
        if cVar1 then begin
          local_40 := PASTAPROPAGANDA + 'fundoempresamonitor1024.jpg';
          Form1.ImageJPG.Picture.LoadFromFile(local_40);
          Form1.ImageJPG.Show;
        end;
      end
      else begin
        local_40 := PASTAPROPAGANDA + 'fundoempresamonitor.jpg';
        cVar1 := FileExists(local_40);
        if cVar1 then begin
          local_40 := PASTAPROPAGANDA + 'fundoempresamonitor.jpg';
          Form1.ImageJPG.Picture.LoadFromFile(local_40);
          Form1.ImageJPG.Show;
        end;
      end;
      local_40 := PASTAPROPAGANDA + 'fundoempresatv.jpg';
      cVar1 := FileExists(local_40);
      if cVar1 then begin
        local_40 := PASTAPROPAGANDA + 'fundoempresatv.jpg';
        Form1.ImageTV.Picture.LoadFromFile(local_40);
        Form1.ImageTV.Show;
      end;
    end
    else begin
      if PROPAGANDA = 'Fotos PNG no Monitor' then begin
        Form1.ImagePNG.Show;
        Form1.ImagePNG.BringToFront;
      end;
      if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
        Form1.ImageJPG.Show;
        Form1.ImageJPG.BringToFront;
      end;
      if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
        Form1.ImageJPG.Show;
        Form1.ImageJPG.BringToFront;
      end;
      if PROPAGANDA = 'Fotos para Bar na TV' then begin
        Form1.ImageTV.Show;
      end;
      if PROPAGANDA = 'Fotos para Boate na TV' then begin
        Form1.ImageTV.Show;
      end;
      if PROPAGANDA = 'Fotos para Bar na TV enquanto Toca CD' then begin
        Form1.ImageTV.Hide;
      end;
      if PROPAGANDA = 'Fotos para Boate na TV enquanto Toca CD' then begin
        Form1.ImageTV.Hide;
      end;
    end;
    if TOTALPRO = 0 then begin
      Form1.TimerPropaganda.Enabled := False;
      local_40 := 'Nao tem Propagandas na pasta ' + PASTAPROPAGANDA;
      Gravalog(local_40);
    end;
  end;
end;

{ JUKELINUX1_CARTAOCODBAR_BAR }
procedure Cartaocodbar_Bar;
var
  local_24c, local_250, local_350, local_354, local_358, local_35c: AnsiString;
  iVar4, local_10, local_14, local_148, local_18, local_1c, local_20, local_248, local_8, local_c, uVar1: LongInt;
begin
  begin
    // C: fpc_shortstr_copy(&U_JUKELINUX1_CODIGODOCARTAO,1,8,local_148);
    // C: FPC_SHORTSTR_TO_SHORTSTR(&U_JUKELINUX1_CODIGODOCARTAO,0x14,local_148);
    iVar4 := TOTMMCARTAO;
    if Length(CODIGODOCARTAO) = 8 then begin
      local_8 := 0;
      local_c := 1;
      if 0 < TOTMMCARTAO then begin
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_copy(&U_JUKELINUX1_CODIGODOCARTAO,1,8,local_148);
          // C: fpc_shortstr_copy(&DAT_0930303a + local_c * 0x26,1,8,local_248);
          if local_248 = local_148 then begin
            local_1c := local_c;
            local_8 := 1;
          end;
        until not (local_c < iVar4);
      end;
      if local_8 <> 0 then begin
        if ESTANOMENU = 0 then begin
          if PULSOSPARACARTAO = 0 then begin
            // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_1c * 0x26,&local_24c);
            CREDITOSCARTAO := Lecreditodocartao(local_24c);
            if CREDITOSCARTAO < 1 then begin
              Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
              Form1.PanelCJ.Top := Form1.Height;
              Form1.CreditoCJ.Font.Color := 12632256;
              Form1.ImageBonus.Hide;
              Form1.ImageGratis.Hide;
              Form1.PanelCJ.Show;
              Form1.PanelCJ.BringToFront;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              local_250 := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_250;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_250);
              Form1.CreditoCJSombra.Caption := local_250;
              repeat
                local_14 := local_14 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_14 < 150);
              local_250 := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_250;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_250);
              Form1.CreditoCJSombra.Caption := local_250;
              Form1.CreditoCJ.Font.Color := 255;
              Form1.CreditoCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc))(Form1.CreditoCJ);
              Form1.CreditoCJSombra.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc))(Form1.CreditoCJSombra);
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(1000);
              repeat
                local_14 := local_14 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + 1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_14 < 150);
              Form1.PanelCJ.Hide;
            end
            else begin
              Form1.TimerPiscaCreditos.Enabled := False;
              Form1.LabelCreditos.Show;
              // C: ( **(code ** )( *(int * )Form1.LabelCreditos + 0x2fc))(Form1.LabelCreditos);
              Form1.LabelCreditos.Font.Color := 16777215;
              Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
              Form1.PanelCJ.Top := Form1.Height;
              Form1.CreditoCJ.Font.Color := 12632256;
              Form1.ImageBonus.Hide;
              Form1.ImageGratis.Hide;
              Form1.PanelCJ.Show;
              Form1.PanelCJ.BringToFront;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              local_250 := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_250;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_250);
              Form1.CreditoCJSombra.Caption := local_250;
              repeat
                local_14 := local_14 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_14 < 150);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(1000);
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSCARTAO := CREDITOSCARTAO + -1;
                local_18 := 1;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSCARTAO := CREDITOSCARTAO + -1;
                local_18 := 1;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSCARTAO := CREDITOSCARTAO + -2;
                local_18 := 1;
              end;
              local_250 := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_250;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_250);
              Form1.CreditoCJSombra.Caption := local_250;
              Form1.CreditoCJ.Font.Color := 255;
              Form1.CreditoCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc))(Form1.CreditoCJ);
              Form1.CreditoCJSombra.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc))(Form1.CreditoCJSombra);
              Rotina_Creditos('Cartao');
              iVar4 := -local_18;
              // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_1c * 0x26,&local_24c);
              Gravacreditonocartao(local_24c, iVar4);
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(2000);
              repeat
                local_14 := local_14 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + 1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_14 < 150);
              Form1.PanelCJ.Hide;
            end;
          end
          else if CREDITOS < 1 then begin
            PULSOSPARACARTAO := 0;
          end
          else begin
            if PULSOSPARACARTAO = 1 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 1;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 2;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 0;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 2 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 2;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 4;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 1;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 3 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 3;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 6;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 1;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 4 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 4;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 8;
                CREDITOSBONUS := 0;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 2;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 5 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 5;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 10;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 2;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 6 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 6;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 12;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 3;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 7 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 6;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 14;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 3;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 8 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 8;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 16;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 4;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 9 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 9;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 18;
                CREDITOSBONUS := 1;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 4;
                CREDITOSBONUS := 0;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 10 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 10;
                CREDITOSBONUS := 2;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 20;
                CREDITOSBONUS := 3;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 5;
                CREDITOSBONUS := 1;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 20 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 20;
                CREDITOSBONUS := 5;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 40;
                CREDITOSBONUS := 10;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 10;
                CREDITOSBONUS := 2;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 50 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 50;
                CREDITOSBONUS := 10;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 100;
                CREDITOSBONUS := 20;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 25;
                CREDITOSBONUS := 5;
              end;
              local_20 := 1;
            end;
            if PULSOSPARACARTAO = 100 then begin
              if REAISXMUSICAS = '1x1' then begin
                CREDITOSPARACARTAO := 100;
                CREDITOSBONUS := 20;
              end;
              if REAISXMUSICAS = '1x2' then begin
                CREDITOSPARACARTAO := 200;
                CREDITOSBONUS := 40;
              end;
              if REAISXMUSICAS = '2x1' then begin
                CREDITOSPARACARTAO := 50;
                CREDITOSBONUS := 10;
              end;
              local_20 := 1;
            end;
            if 0 < CREDITOSPARACARTAO then begin
              Form1.TimerPiscaCreditos.Enabled := False;
              Form1.LabelCreditos.Show;
              // C: ( **(code ** )( *(int * )Form1.LabelCreditos + 0x2fc))(Form1.LabelCreditos);
              Form1.LabelCreditos.Font.Color := 16777215;
              // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_1c * 0x26,&local_24c);
              CREDITOSCARTAO := Lecreditodocartao(local_24c);
              Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
              Form1.PanelCJ.Top := Form1.Height;
              Form1.CreditoCJ.Font.Color := 12632256;
              Form1.ImageBonus.Hide;
              Form1.ImageGratis.Hide;
              Form1.PanelCJ.Show;
              Form1.PanelCJ.BringToFront;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              local_250 := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_250;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_250);
              Form1.CreditoCJSombra.Caption := local_250;
              repeat
                local_14 := local_14 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_14 < 150);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(1500);
              Form1.ImageBonus.Hide;
              Form1.ImageGratis.Hide;
              // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_1c * 0x26,&local_24c);
              Gravacreditonocartao(local_24c, CREDITOSPARACARTAO + CREDITOSBONUS);
              iVar4 := CREDITOSPARACARTAO;
              local_10 := 1;
              if 0 < CREDITOSPARACARTAO then begin
                repeat
                  local_10 := local_10 + 1;
                  CREDITOS := CREDITOS + -1;
                  local_250 := IntToStr(CREDITOS);
                  Form1.LabelCreditos.Caption := local_250;
                  Form1.LabelCreditos.Font.Color := 255;
                  CREDITOSCARTAO := CREDITOSCARTAO + 1;
                  local_250 := IntToStr(CREDITOSCARTAO);
                  Form1.CreditoCJ.Caption := local_250;
                  // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.CreditoCJ,&local_250);
                  Form1.CreditoCJSombra.Caption := local_250;
                  Form1.CreditoCJ.Font.Color := 16711680;
                  Form1.CreditoCJ.Refresh;
                  // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc)) (Form1.CreditoCJ);
                  Form1.CreditoCJSombra.Refresh;
                  // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc)) (Form1.CreditoCJSombra);
                  FORM1.Refresh;
                  // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
                  Sleep(350);
                  Presstecla;
                until not (local_10 < iVar4);
              end;
              Form1.LabelCreditos.Font.Color := 16777215;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              NOMEARQ := PASTA + 'creditos.txt';
              local_350 := NOMEARQ;
              AssignFile(ARQTEXTO, local_350);
              Rewrite(ARQTEXTO);
              local_354 := IntToStr(CREDITOS);
              local_24c := Cripta(local_354);
              Write(ARQTEXTO, local_24c);
              Writeln(ARQTEXTO);
              local_354 := Cripta(JC_SERIALPENDRIVE);
              Write(ARQTEXTO, local_354);
              Writeln(ARQTEXTO);
              Flush(ARQTEXTO);
              CloseFile(ARQTEXTO);
              if SEMPENDRIVE = 0 then begin
                local_24c := PASTACHAVE + 'creditos.txt';
                // C: puVar5 = local_24c;
                if False { C: local_24c == (undefined1 * )0x0 } then begin
                end;
                // C: fpc_pchar_to_ansistr(puVar5,&local_354);
                // C: uVar1 = local_354;
                local_35c := PASTA + 'creditos.txt';
                // C: puVar5 = local_35c;
                if False { C: local_35c == (undefined1 * )0x0 } then begin
                end;
                // C: fpc_pchar_to_ansistr(puVar5,&local_358);
                // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_358,uVar1,extraout_ECX & 0xffffff00);
              end;
              if 0 < CREDITOSBONUS then begin
                FORM1.Refresh;
                // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
                Sleep(1500);
                iVar4 := CREDITOSBONUS;
                local_10 := 1;
                if 0 < CREDITOSBONUS then begin
                  repeat
                    local_10 := local_10 + 1;
                    Form1.ImageGratis.Show;
                    CREDITOSCARTAO := CREDITOSCARTAO + 1;
                    local_250 := IntToStr(CREDITOSCARTAO);
                    Form1.CreditoCJ.Caption := local_250;
                    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.CreditoCJ,&local_250);
                    Form1.CreditoCJSombra.Caption := local_250;
                    Form1.CreditoCJ.Font.Color := 16711680;
                    Form1.CreditoCJ.Refresh;
                    // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc)) (Form1.CreditoCJ);
                    Form1.CreditoCJSombra.Refresh;
                    // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc)) (Form1.CreditoCJSombra);
                    FORM1.Refresh;
                    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
                    Sleep(350);
                    Presstecla;
                  until not (local_10 < iVar4);
                end;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
                FORM1.Refresh;
                // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              end;
              Sleep(3000);
              repeat
                local_14 := local_14 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + 1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_14 < 150);
              Form1.PanelCJ.Hide;
              CREDITOSPARACARTAO := 0;
              CREDITOSBONUS := 0;
              PULSOSPARACARTAO := 0;
            end;
          end;
        end
        else begin
          // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_1c * 0x26,&local_358);
          CREDITOSCARTAO := Lecreditodocartao(local_358);
          Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
          Form1.PanelCJ.Top := Form1.Height;
          Form1.CreditoCJ.Font.Color := 12632256;
          Form1.ImageBonus.Hide;
          Form1.ImageGratis.Hide;
          Form1.PanelCJ.Show;
          Form1.PanelCJ.BringToFront;
          Form1.PanelCJ.Refresh;
          // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
          local_250 := IntToStr(CREDITOSCARTAO);
          Form1.CreditoCJ.Caption := local_250;
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_250);
          Form1.CreditoCJSombra.Caption := local_250;
          repeat
            local_14 := local_14 + 1;
            Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
            Form1.PanelCJ.Refresh;
            // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
          until not (local_14 < 150);
          FORM1.Refresh;
          // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
          Sleep(500);
          Form1.ImageGratis.Show;
          CREDITOSCARTAO := CREDITOSCARTAO + 2;
          local_250 := IntToStr(CREDITOSCARTAO);
          Form1.CreditoCJ.Caption := local_250;
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_250);
          Form1.CreditoCJSombra.Caption := local_250;
          Form1.CreditoCJ.Font.Color := 16711680;
          Form1.CreditoCJ.Refresh;
          // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc))(Form1.CreditoCJ);
          Form1.CreditoCJSombra.Refresh;
          // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc))(Form1.CreditoCJSombra);
          // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_1c * 0x26,&local_358);
          Gravacreditonocartao(local_358, 2);
          Form1.PanelCJ.Refresh;
          // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
          FORM1.Refresh;
          // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
          Sleep(500);
          Form1.PanelCJ.Hide;
          PULSOSPARACARTAO := 0;
        end;
      end;
    end;
    CODIGODOCARTAO := '';
    LENDOCODIGODOCARTAO := 0;
  end;
end;

{ JUKELINUX1_CARTAOCODBAR_BOATE }
procedure Cartaocodbar_Boate;
var
  local_248, local_24c: AnsiString;
  iVar3, local_10, local_14, local_144, local_18, local_1c, local_244, local_8, local_c: LongInt;
begin
  begin
    // C: fpc_shortstr_copy(&U_JUKELINUX1_CODIGODOCARTAO,1,8,local_144);
    // C: FPC_SHORTSTR_TO_SHORTSTR(&U_JUKELINUX1_CODIGODOCARTAO,0x14,local_144);
    iVar3 := TOTMMCARTAO;
    if Length(CODIGODOCARTAO) = 8 then begin
      local_8 := 0;
      local_c := 1;
      if 0 < TOTMMCARTAO then begin
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_copy(&U_JUKELINUX1_CODIGODOCARTAO,1,8,local_144);
          // C: fpc_shortstr_copy(&DAT_0930303a + local_c * 0x26,1,8,local_244);
          if local_244 = local_144 then begin
            local_14 := local_c;
            local_8 := 1;
          end;
        until not (local_c < iVar3);
      end;
      if local_8 <> 0 then begin
        if ESTANOMENU = 0 then begin
          if PULSOSPARACARTAO < 5 then begin
            // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_248);
            CREDITOSCARTAO := Lecreditodocartao(local_248);
            if CREDITOSCARTAO < 1 then begin
              Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
              Form1.PanelCJ.Top := Form1.Height;
              Form1.CreditoCJ.Font.Color := 12632256;
              Form1.ImageBonus.Hide;
              Form1.ImageGratis.Hide;
              Form1.PanelCJ.Show;
              Form1.PanelCJ.BringToFront;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              local_24c := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_24c;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
              Form1.CreditoCJSombra.Caption := local_24c;
              repeat
                local_10 := local_10 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_10 < 150);
              local_24c := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_24c;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
              Form1.CreditoCJSombra.Caption := local_24c;
              Form1.CreditoCJ.Font.Color := 255;
              Form1.CreditoCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc))(Form1.CreditoCJ);
              Form1.CreditoCJSombra.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc))(Form1.CreditoCJSombra);
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(1000);
              repeat
                local_10 := local_10 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + 1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_10 < 150);
              Form1.PanelCJ.Hide;
            end
            else begin
              Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
              Form1.PanelCJ.Top := Form1.Height;
              Form1.CreditoCJ.Font.Color := 12632256;
              Form1.ImageBonus.Hide;
              Form1.ImageGratis.Hide;
              Form1.PanelCJ.Show;
              Form1.PanelCJ.BringToFront;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              local_24c := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_24c;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
              Form1.CreditoCJSombra.Caption := local_24c;
              repeat
                local_10 := local_10 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_10 < 150);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(1000);
              CREDITOSCARTAO := CREDITOSCARTAO + -1;
              local_24c := IntToStr(CREDITOSCARTAO);
              Form1.CreditoCJ.Caption := local_24c;
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
              Form1.CreditoCJSombra.Caption := local_24c;
              Form1.CreditoCJ.Font.Color := 255;
              Form1.CreditoCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc))(Form1.CreditoCJ);
              Form1.CreditoCJSombra.Refresh;
              // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc))(Form1.CreditoCJSombra);
              Rotina_Creditos('Cartao');
              // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_248);
              Gravacreditonocartao(local_248, -1);
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(2000);
              repeat
                local_10 := local_10 + 1;
                Form1.PanelCJ.Top := Form1.PanelCJ.Top + 1;
                Form1.PanelCJ.Refresh;
                // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
              until not (local_10 < 150);
              Form1.PanelCJ.Hide;
            end;
          end
          else begin
            // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_248);
            CREDITOSCARTAO := Lecreditodocartao(local_248);
            Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
            Form1.PanelCJ.Top := Form1.Height;
            Form1.CreditoCJ.Font.Color := 12632256;
            Form1.ImageBonus.Hide;
            Form1.ImageGratis.Hide;
            Form1.PanelCJ.Show;
            Form1.PanelCJ.BringToFront;
            Form1.PanelCJ.Refresh;
            // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
            local_24c := IntToStr(CREDITOSCARTAO);
            Form1.CreditoCJ.Caption := local_24c;
            // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
            Form1.CreditoCJSombra.Caption := local_24c;
            repeat
              local_10 := local_10 + 1;
              Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
            until not (local_10 < 150);
            FORM1.Refresh;
            // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
            Sleep(1500);
            Form1.ImageBonus.Show;
            CREDITOSCARTAO := CREDITOSCARTAO + PULSOSPARACARTAO div 5;
            local_24c := IntToStr(CREDITOSCARTAO);
            Form1.CreditoCJ.Caption := local_24c;
            // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
            Form1.CreditoCJSombra.Caption := local_24c;
            Form1.CreditoCJ.Font.Color := 16711680;
            Form1.CreditoCJ.Refresh;
            // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc))(Form1.CreditoCJ);
            Form1.CreditoCJSombra.Refresh;
            // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc))(Form1.CreditoCJSombra);
            // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_248);
            Gravacreditonocartao(local_248, PULSOSPARACARTAO div 5);
            Form1.PanelCJ.Refresh;
            // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
            FORM1.Refresh;
            // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
            Sleep(3000);
            repeat
              local_10 := local_10 + 1;
              Form1.PanelCJ.Top := Form1.PanelCJ.Top + 1;
              Form1.PanelCJ.Refresh;
              // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
            until not (local_10 < 150);
            Form1.PanelCJ.Hide;
            PULSOSPARACARTAO := 0;
          end;
        end
        else begin
          local_1c := 0;
          KMMCC := 0;
          repeat
            KMMCC := KMMCC + 1;
            // C: iVar3 = FPC_SHORTSTR_COMPARE_EQUAL (&DAT_0930303a + local_14 * 0x26,U_JUKELINUX1_KMMCC * 0x26 + 0x9645f9a );
            if iVar3 = 0 then begin
              local_1c := 1;
            end;
          until not (KMMCC < 100);
          // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_248);
          CREDITOSCARTAO := Lecreditodocartao(local_248);
          Form1.PanelCJ.Left := Form1.LabelCreditos.Left + -270;
          Form1.PanelCJ.Top := Form1.Height;
          Form1.CreditoCJ.Font.Color := 12632256;
          Form1.ImageBonus.Hide;
          Form1.ImageGratis.Hide;
          Form1.PanelCJ.Show;
          Form1.PanelCJ.BringToFront;
          Form1.PanelCJ.Refresh;
          // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
          Form1.CreditoCJ.Font.Size := 56;
          Form1.CreditoCJSombra.Font.Size := 56;
          Form1.CreditoCJ.Top := 20;
          Form1.CreditoCJSombra.Top := 22;
          local_24c := IntToStr(CREDITOSCARTAO);
          Form1.CreditoCJ.Caption := local_24c;
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
          Form1.CreditoCJSombra.Caption := local_24c;
          repeat
            local_10 := local_10 + 1;
            Form1.PanelCJ.Top := Form1.PanelCJ.Top + -1;
            Form1.PanelCJ.Refresh;
            // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
          until not (local_10 < 150);
          FORM1.Refresh;
          // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
          Sleep(500);
          if local_1c = 0 then begin
            Form1.ImageGratis.Show;
          end;
          if local_1c = 0 then begin
            CREDITOSCARTAO := CREDITOSCARTAO + QTDCREDITOSGRATIS;
            Form1.CreditoCJ.Font.Size := 56;
            Form1.CreditoCJSombra.Font.Size := 56;
            Form1.CreditoCJ.Top := 20;
            Form1.CreditoCJSombra.Top := 22;
            local_24c := IntToStr(CREDITOSCARTAO);
            Form1.CreditoCJ.Caption := local_24c;
          end
          else begin
            Form1.CreditoCJ.Font.Size := 16;
            Form1.CreditoCJSombra.Font.Size := 16;
            Form1.CreditoCJ.Top := 40;
            Form1.CreditoCJSombra.Top := 42;
            Form1.CreditoCJ.Caption := 'Limite Excedido';
          end;
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CreditoCJ,&local_24c);
          Form1.CreditoCJSombra.Caption := local_24c;
          Form1.CreditoCJ.Font.Color := 16711680;
          Form1.CreditoCJ.Refresh;
          // C: ( **(code ** )( *(int * )Form1.CreditoCJ + 0x2fc))(Form1.CreditoCJ);
          Form1.CreditoCJSombra.Refresh;
          // C: ( **(code ** )( *(int * )Form1.CreditoCJSombra + 0x2fc))(Form1.CreditoCJSombra);
          if local_1c = 0 then begin
            // C: fpc_shortstr_to_ansistr(&DAT_0930303a + local_14 * 0x26,&local_248);
            Gravacreditonocartao(local_248, QTDCREDITOSGRATIS);
            local_18 := 0;
            KMMCC := 0;
            repeat
              KMMCC := KMMCC + 1;
              if local_18 = 0 then begin
                // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KMMCC * 0x26 + 0x9645f9a,&local_248);
                if local_248 = '' then begin
                  // C: FPC_SHORTSTR_TO_SHORTSTR (U_JUKELINUX1_KMMCC * 0x26 + 0x9645f9a,0x1e, &DAT_0930303a + local_14 * 0x26);
                  local_18 := 1;
                end;
              end;
            until not (KMMCC < 100);
          end;
          Form1.PanelCJ.Refresh;
          // C: ( **(code ** )( *(int * )Form1.PanelCJ + 0x2fc))(Form1.PanelCJ);
          FORM1.Refresh;
          // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
          Sleep(500);
          Form1.PanelCJ.Hide;
          Form1.CreditoCJ.Font.Size := 56;
          Form1.CreditoCJSombra.Font.Size := 56;
          Form1.CreditoCJ.Top := 20;
          Form1.CreditoCJSombra.Top := 22;
          PULSOSPARACARTAO := 0;
        end;
      end;
    end;
    CODIGODOCARTAO := '';
    LENDOCODIGODOCARTAO := 0;
  end;
end;

{ JUKELINUX1_CRIPTABUF }
procedure Criptabuf;
var
  iVar1, local_8: LongInt;
begin
  repeat
    iVar1 := local_8 + 1;
    // C: acStack_808[local_8] = U_JUKELINUX1_TIMER1BUF[local_8] + (char)iVar1 + (char)U_JUKELINUX1_CHAVECRIPTOGRAFICA;
    local_8 := iVar1;
  until not (iVar1 < 2048);
  repeat
    iVar1 := local_8 + 1;
    // C: U_JUKELINUX1_TIMER1BUF[local_8] = acStack_808[local_8];
    local_8 := iVar1;
  until not (iVar1 < 2048);
end;

{ JUKELINUX1_CRIPTASIMPLESQR$ANSISTRING$$ANSISTRING }
function Criptasimplesqr(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr( *(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) + 0x19,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: puVar1 = local_c;
    // C: *puVar1 = local_14;
  end;
end;

{ JUKELINUX1_CRIPTASIMPLES$ANSISTRING$$ANSISTRING }
function Criptasimples(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr( *(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) + 7,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: puVar1 = local_c;
    // C: *puVar1 = local_14;
  end;
end;

{ JUKELINUX1_CRIPTASUPER2$ANSISTRING$$ANSISTRING }
function Criptasuper2(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) + local_10 + 4,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    local_8 := local_14;
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) + local_10 + 3,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: piVar1 = local_c;
    // C: *piVar1 = local_14;
  end;
end;

{ JUKELINUX1_CRIPTASUPER$ANSISTRING$$ANSISTRING }
function Criptasuper(P1: AnsiString): AnsiString;
var
  local_20, local_8, local_c: AnsiString;
  iVar2, local_10, local_14: LongInt;
  local_18, local_1c, local_4c: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    Randomize;
    local_10 := Random(99999);
    local_20 := IntToStr(local_10);
    local_4c := Strzero(local_20, 5);
    local_20 := local_4c;
    iVar2 := 0;
    if local_4c <> 0 then begin
      // C: iVar2 = *(int * )(local_4c[0] + -4);
    end;
    local_14 := 1;
    if 0 < iVar2 then begin
      repeat
        local_14 := local_14 + 1;
        // C: fpc_char_to_ansistr((uint)*(byte * )(local_20 + -1 + local_14) + local_14 + 0x46,local_4c);
        local_1c := local_1c + local_4c;
      until not (local_14 < iVar2);
    end;
    iVar2 := 0;
    if local_8 <> '' then begin
      // C: iVar2 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_14 := 1;
    if 0 < iVar2 then begin
      repeat
        local_14 := local_14 + 1;
        // C: fpc_char_to_ansistr((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_14) + local_14 + 0x48,local_4c);
        local_18 := local_18 + local_4c;
      until not (local_14 < iVar2);
    end;
    local_c := local_1c + local_18;
  end;
end;

{ JUKELINUX1_CRIPTA$ANSISTRING$$ANSISTRING }
function Cripta(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) + local_10 + 0x11,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: puVar1 = local_c;
    // C: *puVar1 = local_14;
  end;
end;

{ JUKELINUX1_DEFINE_EXIBIRVIDEOS }
procedure Define_Exibirvideos;
begin
  if EXIBIRVIDEOSNO = 'MONITOR' then begin
    if RESOLUCAO = 1366 then begin
      POSL := 38;
      POST := 307;
      POSW := 363;
      POSH := 208;
    end;
    if RESOLUCAO = 1024 then begin
      POSL := 19;
      POST := 320;
      POSW := 183;
      POSH := 160;
    end;
    if RESOLUCAO = 1440 then begin
      POSL := 38;
      POST := 392;
      POSW := 363;
      POSH := 208;
    end;
    Form1.Play.Left := POSL;
    Form1.Play.Top := POST;
    Form1.Play.Width := POSW;
    Form1.Play.Height := POSH;
    Form1.Play.Hide;
  end;
  if EXIBIRVIDEOSNO = 'TV' then begin
    POSL := RESOLUCAO;
    POST := 0;
    POSW := RESOLUCAOTVX;
    POSH := RESOLUCAOTVY;
    Form1.Play.Left := RESOLUCAO;
    Form1.Play.Top := POST;
    Form1.Play.Width := POSW;
    Form1.Play.Height := POSH;
    Form1.Play.Hide;
    Form1.PanelTV.Left := Form1.Play.Left;
    Form1.PanelTV.Top := Form1.Play.Top;
    Form1.PanelTV.Height := Form1.Play.Height;
    Form1.PanelTV.Width := Form1.Play.Width;
    Form1.ImageTV.Align := alClient;
    Form1.PanelTV.Show;
  end;
end;

{ JUKELINUX1_DESATIVA_PROPAGANDA }
procedure Desativa_Propaganda;
var
  iVar1: LongInt;
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xba8) + 0xd8)) (Form1.TimerPropaganda,param_2 & 0xffffff00);
  iVar1 := Pos('TV/Monitor', PROPAGANDA);
  if 0 < iVar1 then begin
    Form1.TimerTocandoTv.Enabled := False;
    // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.playtv);
    Form1.playtv.Hide;
    TOCANDOVIDEOTV := 0;
  end;
  if PROPAGANDA = 'Fotos PNG no Monitor' then begin
    Form1.ImagePNG.Hide;
  end;
  if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
    Form1.ImageJPG.Hide;
  end;
  if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
    Form1.ImageJPG.Hide;
  end;
  if PROPAGANDA = 'Fotos para Bar na TV' then begin
    Form1.ImageTV.Hide;
  end;
  if PROPAGANDA = 'Fotos para Boate na TV' then begin
    Form1.ImageTV.Hide;
  end;
  if (ESTANOMENU = 0) and (TOCANDOMUSICADVD = 0) then begin
    if PROPAGANDA = 'Videos para Bar na TV/Monitor enquanto Toca CD' then begin
      TOCANDOVIDEOTV := 0;
      Form1.ImageTV.Show;
      Form1.TimerPropaganda.Enabled := True;
    end;
    if PROPAGANDA = 'Videos para Boate na TV/Monitor enquanto Toca CD' then begin
      TOCANDOVIDEOTV := 0;
      Form1.ImageTV.Show;
      Form1.TimerPropaganda.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_DESATIVA_VOLUME_PELO_PAINEL }
procedure Desativa_Volume_Pelo_Painel;
begin
  RODAVOLUME := 0;
  TECLAANTERIORRODAVOLUME := '';
  VOLUMEATIVADO := 0;
  Form1.TimerDesativaVolume.Enabled := False;
  Destravamensagem;
end;

{ JUKELINUX1_DESCRIPTABUF }
procedure Descriptabuf;
var
  iVar1, local_8: LongInt;
begin
  repeat
    iVar1 := local_8 + 1;
    // C: acStack_808[local_8] = (U_JUKELINUX1_TIMER1BUF[local_8] - (char)iVar1) - (char)U_JUKELINUX1_CHAVECRIPTOGRAFICA;
    local_8 := iVar1;
  until not (iVar1 < 2048);
  repeat
    iVar1 := local_8 + 1;
    // C: U_JUKELINUX1_TIMER1BUF[local_8] = acStack_808[local_8];
    local_8 := iVar1;
  until not (iVar1 < 2048);
end;

{ JUKELINUX1_DESCRIPTASIMPLESQR$ANSISTRING$$ANSISTRING }
function Descriptasimplesqr(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr( *(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) - 0x19,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: puVar1 = local_c;
    // C: *puVar1 = local_14;
  end;
end;

{ JUKELINUX1_DESCRIPTASIMPLES$ANSISTRING$$ANSISTRING }
function Descriptasimples(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr( *(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) - 7,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: puVar1 = local_c;
    // C: *puVar1 = local_14;
  end;
end;

{ JUKELINUX1_DESCRIPTASUPER2$ANSISTRING$$ANSISTRING }
function Descriptasuper2(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr(((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) - local_10) + -4,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    local_8 := local_14;
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr(((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) - local_10) + -3,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: piVar1 = local_c;
    // C: *piVar1 = local_14;
  end;
end;

{ JUKELINUX1_DESCRIPTASUPER$ANSISTRING$$ANSISTRING }
function Descriptasuper(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar4, local_10, uVar3: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    // C: uVar3 = 0;
    if local_8 <> '' then begin
      // C: uVar3 = *(undefined4 * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_40 := Copy(local_8, 6, uVar3);
    local_8 := local_40;
    iVar4 := 0;
    if local_8 <> '' then begin
      // C: iVar4 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar4 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr(((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) - local_10) + -0x48,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar4);
    end;
    // C: puVar1 = local_c;
    // C: *puVar1 = local_14;
  end;
end;

{ JUKELINUX1_DESCRIPTA$ANSISTRING$$ANSISTRING }
function Descripta(P1: AnsiString): AnsiString;
var
  local_8, local_c: AnsiString;
  iVar3, local_10: LongInt;
  local_14, local_40: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    iVar3 := 0;
    if local_8 <> '' then begin
      // C: iVar3 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    local_10 := 1;
    if 0 < iVar3 then begin
      repeat
        local_10 := local_10 + 1;
        // C: fpc_char_to_ansistr(((uint)*(byte * )(U_JUKELINUX1_FORM1 + -1 + local_10) - local_10) + -0x11,local_40);
        local_14 := local_14 + local_40;
      until not (local_10 < iVar3);
    end;
    // C: puVar1 = local_c;
    // C: *puVar1 = local_14;
  end;
end;

{ JUKELINUX1_DESCRIPTOGRAFA$ANSISTRING$ANSISTRING }
procedure Descriptografa(P1: AnsiString; P2: AnsiString);
var
  local_13c, local_38, local_3c, local_8, local_c: AnsiString;
  iVar2, uVar4: LongInt;
begin
  local_c := P2;
  local_8 := P1;
  begin
    ORIGEM := local_8;
    DESTINO := '';
    if local_c = 'NORMAL' then begin
      iVar2 := 0;
      if ORIGEM <> '' then begin
        // C: iVar2 = *(int * )(U_JUKELINUX1_ORIGEM + -4);
      end;
      if 0 < iVar2 then begin
        local_3c := ExtractFileExt(ORIGEM);
        local_38 := UpperCase(local_3c);
        if local_38 = '.MP3' then begin
          DESTINO := PASTA + 'tocarcd.mp3';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.MPG' then begin
          DESTINO := PASTA + 'tocardvd.mpg';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.WMA' then begin
          DESTINO := PASTA + 'tocarcd.wma';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.MKV' then begin
          DESTINO := PASTA + 'tocardvd.mkv';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.MP4' then begin
          DESTINO := PASTA + 'tocardvd.mp4';
        end;
      end;
    end;
    if local_c = 'PALHINHA' then begin
      iVar2 := 0;
      if ORIGEM <> '' then begin
        // C: iVar2 = *(int * )(U_JUKELINUX1_ORIGEM + -4);
      end;
      if 0 < iVar2 then begin
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.MP3' then begin
          DESTINO := PASTA + 'tocarcdpalhinha.mp3';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.MPG' then begin
          DESTINO := PASTA + 'tocardvdpalhinha.mpg';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.WMA' then begin
          DESTINO := PASTA + 'tocarcdpalhinha.wma';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.MKV' then begin
          DESTINO := PASTA + 'tocardvdpalhinha.mkv';
        end;
        local_38 := ExtractFileExt(ORIGEM);
        local_3c := UpperCase(local_38);
        if local_3c = '.MP4' then begin
          DESTINO := PASTA + 'tocardvdpalhinha.mp4';
          // C: uVar4 = extraout_ECX_01;
        end;
      end;
    end;
    iVar2 := 0;
    if DESTINO <> '' then begin
      // C: iVar2 = *(int * )(U_JUKELINUX1_DESTINO + -4);
    end;
    if 0 < iVar2 then begin
      if CHAVECRIPTOGRAFICA = 0 then begin
        ESTADESCRIPTOGRAFANDO := 1;
        // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (U_JUKELINUX1_ORIGEM,U_JUKELINUX1_DESTINO,uVar4 & 0xffffff00);
        ESTADESCRIPTOGRAFANDO := 0;
      end
      else begin
        ESTADESCRIPTOGRAFANDO := 1;
        ERROTOCAR := 0;
        TIMER1ORIGEM := ORIGEM;
        // C: SYSUTILS_CHANGEFILEEXT_ANSISTRING_ANSISTRING__ANSISTRING (U_JUKELINUX1_DESTINO,".INF",&local_3c);
        TIMER1DESTINOINF := local_3c;
        TIMER1DESTINOMP3 := DESTINO;
        local_13c := TIMER1ORIGEM;
        // C: OBJPAS_ASSIGNFILE_file_SHORTSTRING(U_JUKELINUX1_TIMER1FROMORIGEM,local_13c);
        // C: SYSTEM_RESET_file_LONGINT(U_JUKELINUX1_TIMER1FROMORIGEM,1);
        local_13c := TIMER1DESTINOINF;
        // C: OBJPAS_ASSIGNFILE_file_SHORTSTRING(U_JUKELINUX1_TIMER1TODESTINOINF,local_13c);
        // C: SYSTEM_REWRITE_file_LONGINT(U_JUKELINUX1_TIMER1TODESTINOINF,1);
        local_13c := TIMER1DESTINOMP3;
        // C: OBJPAS_ASSIGNFILE_file_SHORTSTRING(U_JUKELINUX1_TIMER1TODESTINOMP3,local_13c);
        // C: SYSTEM_REWRITE_file_LONGINT(U_JUKELINUX1_TIMER1TODESTINOMP3,1);
        // C: SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT (U_JUKELINUX1_TIMER1FROMORIGEM,U_JUKELINUX1_TIMER1BUFINI,10, &U_JUKELINUX1_TIMER1NUMREAD);
        // C: fpc_chararray_to_ansistr(U_JUKELINUX1_TIMER1BUFINI,9,extraout_ECX_02 & 0xffffff00,local_38);
        local_3c := Trim(local_38);
        TIMER1TAMINT := StrToIntDef(local_3c, 0);
        if 0 < TIMER1TAMINT then begin
          // C: U_JUKELINUX1_TIMER1GRAVADORA = (undefined1 * )0x0;
          TIMER1K := 0;
          repeat
            TIMER1K := TIMER1K + 1;
            // C: SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT (U_JUKELINUX1_TIMER1FROMORIGEM,&U_JUKELINUX1_TIMER1BUFUM,1, &U_JUKELINUX1_TIMER1NUMREAD);
            // C: fpc_chararray_to_ansistr (&U_JUKELINUX1_TIMER1BUFUM,0,extraout_ECX_03 & 0xffffff00,&local_3c);
            TIMER1GRAVADORA := TIMER1GRAVADORA + local_3c;
          until not (TIMER1K < 30);
          local_3c := Descripta(TIMER1GRAVADORA);
          iVar2 := TIMER1TAMINT;
          TIMER1GRAVADORA := local_3c;
          TIMER1K := 1;
          if 0 < TIMER1TAMINT then begin
            TIMER1K := 0;
            repeat
              TIMER1K := TIMER1K + 1;
              // C: SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT (U_JUKELINUX1_TIMER1FROMORIGEM,&U_JUKELINUX1_TIMER1BUFUM,1, &U_JUKELINUX1_TIMER1NUMREAD);
              // C: SYSTEM_BLOCKWRITE_file_formal_LONGINT_LONGINT (U_JUKELINUX1_TIMER1TODESTINOINF,&U_JUKELINUX1_TIMER1BUFUM, U_JUKELINUX1_TIMER1NUMREAD,&U_JUKELINUX1_TIMER1NUMWRITTEN);
            until not (TIMER1K < iVar2);
          end;
          repeat
            // C: SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT (U_JUKELINUX1_TIMER1FROMORIGEM,U_JUKELINUX1_TIMER1BUF,0x800, &U_JUKELINUX1_TIMER1NUMREAD);
            Descriptabuf;
            // C: SYSTEM_BLOCKWRITE_file_formal_LONGINT_LONGINT (U_JUKELINUX1_TIMER1TODESTINOMP3,U_JUKELINUX1_TIMER1BUF, U_JUKELINUX1_TIMER1NUMREAD,&U_JUKELINUX1_TIMER1NUMWRITTEN);
            if TIMER1NUMREAD = 0 then begin Break; end;
          until not (TIMER1NUMWRITTEN = TIMER1NUMREAD);
          // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_TIMER1FROMORIGEM);
          // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_TIMER1TODESTINOMP3);
          // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_TIMER1TODESTINOINF);
          // C: puVar3 = U_JUKELINUX1_TIMER1DESTINOINF;
          if False { C: U_JUKELINUX1_TIMER1DESTINOINF == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar3,&local_3c);
          DeleteFile(local_3c);
        end;
        ESTADESCRIPTOGRAFANDO := 0;
      end;
    end;
  end;
end;

{ JUKELINUX1_DESSELECIONAMUSICA }
procedure Desselecionamusica;
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xd8)) (Form1.TimerNomeMusicaGrande,param_2 & 0xffffff00);
  case MUSICASELECIONADAPOSTELA of
    1: begin
      Form1.Musica1.Font.Color := CORLETRAFUNDO;
    end;
    2: begin
      Form1.Musica2.Font.Color := CORLETRAFUNDO;
    end;
    3: begin
      Form1.Musica3.Font.Color := CORLETRAFUNDO;
    end;
    4: begin
      Form1.Musica4.Font.Color := CORLETRAFUNDO;
    end;
    5: begin
      Form1.Musica5.Font.Color := CORLETRAFUNDO;
    end;
    6: begin
      Form1.Musica6.Font.Color := CORLETRAFUNDO;
    end;
    7: begin
      Form1.Musica7.Font.Color := CORLETRAFUNDO;
    end;
    8: begin
      Form1.Musica8.Font.Color := CORLETRAFUNDO;
    end;
    9: begin
      Form1.Musica9.Font.Color := CORLETRAFUNDO;
    end;
    10: begin
      Form1.Musica10.Font.Color := CORLETRAFUNDO;
    end;
    11: begin
      Form1.Musica11.Font.Color := CORLETRAFUNDO;
    end;
    12: begin
      Form1.Musica12.Font.Color := CORLETRAFUNDO;
    end;
  end;
  MUSICASELECIONADAANT := MUSICASELECIONADAPOSTELA;
end;

{ JUKELINUX1_DESSELECIONAMUSICA_TODAS }
procedure Desselecionamusica_Todas;
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xd8)) (Form1.TimerNomeMusicaGrande,param_2 & 0xffffff00);
  Form1.Musica1.Font.Color := CORLETRAFUNDO;
  Form1.Musica2.Font.Color := CORLETRAFUNDO;
  Form1.Musica3.Font.Color := CORLETRAFUNDO;
  Form1.Musica4.Font.Color := CORLETRAFUNDO;
  Form1.Musica5.Font.Color := CORLETRAFUNDO;
  Form1.Musica6.Font.Color := CORLETRAFUNDO;
  Form1.Musica7.Font.Color := CORLETRAFUNDO;
  Form1.Musica8.Font.Color := CORLETRAFUNDO;
  Form1.Musica9.Font.Color := CORLETRAFUNDO;
  Form1.Musica10.Font.Color := CORLETRAFUNDO;
  Form1.Musica11.Font.Color := CORLETRAFUNDO;
  Form1.Musica12.Font.Color := CORLETRAFUNDO;
  MUSICASELECIONADAANT := MUSICASELECIONADAPOSTELA;
end;

{ JUKELINUX1_DESTRAVAMENSAGEM }
procedure Destravamensagem;
begin
  if MOSTRANDOSETABAIXO = -1 then begin
    Form1.SetaBaixo.Show;
    MOSTRANDOSETABAIXO := 1;
  end;
  Form1.TimerEscondeMsg.Enabled := False;
  Form1.Imagemsg.Hide;
  Form1.LabelMsg1.Hide;
end;

{ JUKELINUX1_EXCLUICDPELALISTA }
procedure Excluicdpelalista;
var
  local_10e0, local_10e4, local_10e8, local_10f4, local_10f8, local_fe0, local_fe8, local_ff0: AnsiString;
  cVar2: Boolean;
  iVar1, iVar4, local_7d4, local_7d8, local_7dc, local_fac, local_fb0, local_fb4: LongInt;
  local_10ec, local_10f0, local_fe4, local_fec: Variant;
begin
  begin
    local_fe0 := NOMEPASTACDNOVOLISTA + 'listadeexclusao.txt';
    cVar2 := FileExists(local_fe0);
    if cVar2 then begin
      local_fe0 := NOMEPASTACDNOVOLISTA + 'listadeexclusao.txt';
      local_10e0 := local_fe0;
      AssignFile(ARQTEXTO, local_10e0);
      Reset(ARQTEXTO);
      while True do begin
        cVar2 := Eof(ARQTEXTO);
        if cVar2 then begin Break; end;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_7dc := local_7dc + 1;
        iVar1 := local_7dc;
        // C: *(undefined4 * )(local_7d4 + iVar1 * 4 + -4) = U_JUKELINUX1_TEXTO;
      end;
      CloseFile(ARQTEXTO);
      local_fec := 'Exclusão Automática de ';
      local_fe0 := IntToStr(local_7dc);
      local_fe8 := local_fe0;
      local_fe4 := ' CDs/DVDs';
      local_10e4 := local_fec + local_fe8 + local_fe4;
      Form1.LabelMusTot.Caption := local_10e4;
      // C: ( **(code ** )( *(int * )Form1.LabelMusTot + 0x2fc))(Form1.LabelMusTot);
      iVar1 := local_7dc;
      local_7d8 := 1;
      if 0 < local_7dc then begin
        repeat
          local_7d8 := local_7d8 + 1;
          local_fec := PASTAMUSICAS;
          // C: local_fe8 = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
          local_fe4 := '/';
          local_fe0 := local_fec + local_fe8 + local_fe4;
          cVar2 := DirectoryExists(local_fe0);
          if cVar2 then begin
            local_fec := PASTAMUSICAS;
            // C: local_fe8 = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
            local_fe4 := '/capapequena.jpg';
            local_fe0 := local_fec + local_fe8 + local_fe4;
            cVar2 := FileExists(local_fe0);
            if cVar2 then begin
              local_fec := PASTAMUSICAS;
              // C: local_fe8 = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
              local_fe4 := '/capapequena.jpg';
              local_fe0 := local_fec + local_fe8 + local_fe4;
              Form1.ImageMusR.Picture.LoadFromFile(local_fe0);
            end;
            // C: ( **(code ** )( *(int * )Form1.ImageMusR + 0x2fc))(Form1.ImageMusR);
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.LabelMusR,*(undefined4 * )(local_7d4 + local_7d8 * 4 + -4));
            // C: ( **(code ** )( *(int * )Form1.LabelMusR + 0x2fc))(Form1.LabelMusR);
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.LabelMusNomeCD,*(undefined4 * )(local_7d4 + local_7d8 * 4 + -4));
            // C: ( **(code ** )( *(int * )Form1.LabelMusNomeCD + 0x2fc))(Form1.LabelMusNomeCD);
            local_fec := PASTAMUSICAS;
            // C: local_fe8 = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
            local_fe4 := '/capa.jpg';
            local_fe0 := local_fec + local_fe8 + local_fe4;
            cVar2 := FileExists(local_fe0);
            if cVar2 then begin
              local_fec := PASTAMUSICAS;
              // C: local_fe8 = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
              local_fe4 := '/capa.jpg';
              local_fe0 := local_fec + local_fe8 + local_fe4;
              Form1.ImageMusCapa.Picture.LoadFromFile(local_fe0);
            end;
            // C: ( **(code ** )( *(int * )Form1.ImageMusCapa + 0x2fc))(Form1.ImageMusCapa);
            local_fec := PASTAMUSICAS;
            // C: local_fe8 = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
            local_fe4 := '/';
            local_fe0 := local_fec + local_fe8 + local_fe4;
            Form1.FileListBox1.Directory := local_fe0;
            iVar4 := Form1.FileListBox1.Count;
            if -1 < iVar4 + -1 then begin
              local_fb4 := -1;
              repeat
                local_fb4 := local_fb4 + 1;
                local_fe0 := Form1.FileListBox1.Items[local_fb4];
                if False { C: STRNE(local_fe0[0],"[.]") } then begin
                  local_fe0 := Form1.FileListBox1.Items[local_fb4];
                  if False { C: STRNE(local_fe0[0],"[..]") } then begin
                    local_ff0 := PASTAMUSICAS;
                    // C: local_fec = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
                    local_fe8 := '/';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_fb4, &local_10e8);
                    local_fe4 := local_10e8;
                    local_fe0 := local_ff0 + local_fec + local_fe8 + local_fe4;
                    cVar2 := FileExists(local_fe0);
                    if cVar2 then begin
                      local_fb0 := local_fb0 + 1;
                      local_ff0 := PASTAMUSICAS;
                      // C: local_fec = *(undefined ** )(local_7d4 + local_7d8 * 4 + -4);
                      local_fe8 := '/';
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_fb4, &local_10e8);
                      local_fe4 := local_10e8;
                      // ?: local_fac + local_fb0 * 4 + -4 := local_ff0 + local_fec + local_fe8 + local_fe4;
                    end;
                  end;
                end;
              until not (local_fb4 < iVar4 + -1);
            end;
            iVar4 := local_fb0;
            local_fb4 := 1;
            if 0 < local_fb0 then begin
              repeat
                local_fb4 := local_fb4 + 1;
                // C: SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN ( *(undefined4 * )(local_fac + local_fb4 * 4 + -4));
                // C: fpc_ansistr_concat(&local_10e4,"Excluindo:\r", *(undefined4 * )(local_fac + local_fb4 * 4 + -4));
                Form1.LabelMusCopia.Caption := local_10e4;
                // C: ( **(code ** )( *(int * )Form1.LabelMusCopia + 0x2fc))(Form1.LabelMusCopia);
                // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              until not (local_fb4 < iVar4);
            end;
            // C: fpc_ansistr_concat(&local_10e8,U_JUKELINUX1_PASTAMUSICAS, *(undefined4 * )(local_7d4 + local_7d8 * 4 + -4));
            RemoveDir(local_10e8);
            local_10f4 := 'Exclusao Automatica do CD/DVD - ';
            // C: local_10f0 = (char * )U_JUKELINUX1_NOMEPASTACDNOVO;
            // C: local_10ec = *(char ** )(local_7d4 + local_7d8 * 4 + -4);
            local_10e8 := local_10f4 + local_10f0 + local_10ec;
            Gravalog(local_10e8);
            local_10f4 := 'Ok, Excluido ';
            local_10e8 := IntToStr(local_7d8);
            local_10f0 := local_10e8;
            local_10ec := ' CDs/DVDs da Lista';
            local_10f8 := local_10f4 + local_10f0 + local_10ec;
            Form1.LabelMusNomeCD.Caption := local_10f8;
            // C: ( **(code ** )( *(int * )Form1.LabelMusNomeCD + 0x2fc))(Form1.LabelMusNomeCD);
            // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
            Sleep(100);
            RELECDS := 1;
          end;
        until not (local_7d8 < iVar1);
      end;
    end;
    local_10f4 := 'Ok, Apagado ';
    local_10e8 := IntToStr(local_7dc);
    local_10f0 := local_10e8;
    local_10ec := ' CDs/DVDs da Lista de Exclusao';
    local_10f8 := local_10f4 + local_10f0 + local_10ec;
    Form1.LabelPress1.Caption := local_10f8;
    FORM1.Refresh;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    Sleep(2000);
  end;
end;

{ JUKELINUX1_GENERO_MAIS_TOCADOS }
procedure Genero_Mais_Tocados;
var
  local_13c, local_3c, local_48, local_4c: AnsiString;
  cVar3: Boolean;
  iVar1, iVar2, iVar5, local_10, local_8, local_c: LongInt;
  local_140, local_40, local_44: Variant;
begin
  begin
    local_3c := PASTA + 'tocados.txt';
    cVar3 := FileExists(local_3c);
    iVar2 := TOTALCDS;
    if cVar3 then begin
      local_8 := 1;
      if 0 < TOTALCDS then begin
        repeat
          local_8 := local_8 + 1;
          // C: (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] = 0;
        until not (local_8 < iVar2);
      end;
      local_3c := PASTA + 'tocados.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Reset(ARQTEXTO);
      while True do begin
        cVar3 := Eof(ARQTEXTO);
        if cVar3 then begin Break; end;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        iVar2 := TOTALCDS;
        local_8 := 1;
        if 0 < TOTALCDS then begin
          repeat
            local_8 := local_8 + 1;
            // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90];
            local_c := 1;
            if 0 < iVar1 then begin
              repeat
                local_c := local_c + 1;
                // C: iVar5 = fpc_ansistr_compare_equal ( *(undefined4 * )(local_8 * 0x240 + 0x8e91144 + local_c * 4), U_JUKELINUX1_TEXTO);
                if iVar5 = 0 then begin
                  // C: (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] = (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] + 1;
                end;
              until not (local_c < iVar1);
            end;
          until not (local_8 < iVar2);
        end;
      end;
      CloseFile(ARQTEXTO);
    end;
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x854) + 0x480)) (Form1.ListBoxRGeneros);
    iVar2 := TOTALMMRITMO;
    if 0 < TOTALMMRITMO then begin
      repeat
        local_10 := local_10 + 1;
        // C: *(undefined4 * )(&DAT_0930013c + local_10 * 4) = 0;
      until not (local_10 < iVar2);
    end;
    iVar2 := TOTALMMRITMO;
    if 0 < TOTALMMRITMO then begin
      repeat
        iVar1 := TOTALCDS;
        local_10 := local_10 + 1;
        local_8 := 1;
        if 0 < TOTALCDS then begin
          repeat
            local_8 := local_8 + 1;
            // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,local_3c);
            // C: iVar5 = fpc_ansistr_compare_equal (local_3c[0],*(undefined4 * )(&DAT_092fffac + local_10 * 4));
            if iVar5 = 0 then begin
              // C: *(int * )(&DAT_0930013c + local_10 * 4) = *(int * )(&DAT_0930013c + local_10 * 4) + (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90];
            end;
          until not (local_8 < iVar1);
        end;
      until not (local_10 < iVar2);
    end;
    iVar2 := TOTALMMRITMO;
    local_10 := 1;
    if 0 < TOTALMMRITMO then begin
      repeat
        local_10 := local_10 + 1;
        // C: local_4c = *(undefined4 * )(&DAT_092fffac + local_10 * 4);
        local_48 := ' (';
        // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ( *(undefined4 * )(&DAT_0930013c + local_10 * 4),&local_140);
        local_44 := local_140;
        local_40 := ')';
        local_3c := local_4c + local_48 + local_44 + local_40;
        // C: ( **(code ** )( **(int ** )(Form1.ListBoxRGeneros + 0x364) + 0xa4)) (Form1.ListBoxRGeneros.Items,local_3c[0]);
      until not (local_10 < iVar2);
    end;
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x858) + 0x480)) (Form1.ListBoxRCds);
  end;
end;

{ JUKELINUX1_GRAVACREDITONOCARTAO$ANSISTRING$LONGINT }
procedure Gravacreditonocartao(P1: AnsiString; P2: LongInt);
var
  local_10, local_150, local_154, local_158, local_168, local_20, local_258, local_25c, local_28, local_8: AnsiString;
  cVar1: Boolean;
  local_14, local_18, local_24, local_c: LongInt;
  local_15c, local_160, local_164: Variant;
begin
  local_c := P2;
  local_8 := P1;
  begin
    local_24 := 0;
    local_20 := PASTA + 'cartoes.ccc';
    cVar1 := FileExists(local_20);
    if not cVar1 then begin
      local_168 := 'Erro: Falta o Arquivo CARTOESPP.CCC ao gravar ';
      local_158 := IntToStr(local_c);
      local_164 := local_158;
      local_160 := ' creditos no cartao:';
      local_15c := local_8;
      local_25c := local_168 + local_164 + local_160 + local_15c;
      Gravalog(local_25c);
    end
    else begin
      local_150 := local_20;
      // C: OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING(U_JUKELINUX1_ARQCARTAOM,local_150);
      // C: fpc_reset_typed(U_JUKELINUX1_ARQCARTAOM,0x26);
      while True do begin
        // C: cVar1 = SYSTEM_EOF_file__BOOLEAN(U_JUKELINUX1_ARQCARTAOM);
        if cVar1 then begin Break; end;
        // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOM);
        // C: FPC_TYPED_READ(0x26,U_JUKELINUX1_ARQCARTAOM,U_JUKELINUX1_ACARM);
        ACARM := local_154;
        local_28 := Descripta(local_154);
        if local_8 = local_28 then begin
          // C: fpc_shortstr_to_ansistr(0x964703f,&local_154);
          local_10 := Descripta(local_154);
          local_18 := StrToIntDef(local_10, 0);
          local_158 := IntToStr(local_18 + local_c);
          local_154 := Cripta(local_158);
          // C: FPC_ANSISTR_TO_SHORTSTR(0x964703f,4,local_154);
          local_158 := Cripta('N');
          // C: FPC_ANSISTR_TO_SHORTSTR(0x9647044,1,local_158);
          // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOM);
          // C: FPC_TYPED_WRITE(0x26,U_JUKELINUX1_ARQCARTAOM,U_JUKELINUX1_ACARM);
          local_24 := 1;
        end;
        local_14 := local_14 + 1;
      end;
      // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_ARQCARTAOM);
      if local_24 = 0 then begin
        local_258 := local_20;
        // C: OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING(U_JUKELINUX1_ARQCARTAOM,local_258);
        // C: fpc_reset_typed(U_JUKELINUX1_ARQCARTAOM,0x26);
        local_158 := Cripta(local_8);
        ACARM := local_158;
        local_25c := IntToStr(local_c);
        local_158 := Cripta(local_25c);
        // C: FPC_ANSISTR_TO_SHORTSTR(0x964703f,4,local_158);
        local_25c := Cripta('N');
        // C: FPC_ANSISTR_TO_SHORTSTR(0x9647044,1,local_25c);
        // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOM);
        // C: FPC_TYPED_WRITE(0x26,U_JUKELINUX1_ARQCARTAOM,U_JUKELINUX1_ACARM);
        // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_ARQCARTAOM);
      end;
      Backupcartaoccc;
    end;
  end;
end;

{ JUKELINUX1_GRAVALOG$ANSISTRING }
procedure Gravalog(P1: AnsiString);
var
  local_134, local_138, local_13c, local_140, local_144, local_34, local_38, local_48, local_8: AnsiString;
  cVar1: Boolean;
  local_3c, local_40, local_44: Variant;
begin
  local_8 := P1;
  // C: fpc_ansistr_incr_ref();
  begin
    local_34 := PASTA + 'log.txt';
    cVar1 := FileExists(local_34);
    if cVar1 then begin
      local_34 := PASTA + 'log.txt';
      local_134 := local_34;
      AssignFile(ARQLOG, local_134);
      Append(ARQLOG);
      local_138 := DateToStr(Date);
      local_48 := local_138;
      local_44 := ' ';
      local_13c := TimeToStr(Time);
      local_40 := local_13c;
      local_3c := ' - ';
      local_38 := local_8;
      local_34 := local_48 + local_44 + local_40 + local_3c + local_38;
      Write(ARQLOG, local_34);
      Writeln(ARQLOG);
      Flush(ARQLOG);
      CloseFile(ARQLOG);
    end;
    local_13c := PASTAPRINCIPAL + 'Imagens/linuxmint.png';
    cVar1 := FileExists(local_13c);
    if cVar1 then begin
      local_13c := PASTAPRINCIPAL + 'Imagens/linuxmint.png';
      local_134 := local_13c;
      AssignFile(ARQLOG, local_134);
      Append(ARQLOG);
      local_140 := DateToStr(Date);
      local_48 := local_140;
      local_44 := ' ';
      local_144 := TimeToStr(Time);
      local_40 := local_144;
      local_3c := ' - ';
      local_38 := local_8;
      local_138 := local_48 + local_44 + local_40 + local_3c + local_38;
      local_13c := Criptasimples(local_138);
      Write(ARQLOG, local_13c);
      Writeln(ARQLOG);
      Flush(ARQLOG);
      CloseFile(ARQLOG);
    end;
  end;
end;

{ JUKELINUX1_GRAVA_HD_PORCENTAGEM }
procedure Grava_Hd_Porcentagem;
var
  local_380, local_384: AnsiString;
  local_254: Text;
begin
  begin
    local_384 := PASTA + 'porcentagemdoponto.txt';
    local_380 := local_384;
    AssignFile(local_254, local_380);
    Rewrite(local_254);
    Write(local_254, PORCENTAGEMDOPONTOSTR);
    Writeln(local_254);
    Flush(local_254);
    CloseFile(local_254);
  end;
end;

{ JUKELINUX1_GRAVA_HD_RELOGIOGRATIS }
procedure Grava_Hd_Relogiogratis;
var
  local_284, local_384: AnsiString;
  local_254: Text;
begin
  begin
    local_284 := IntToStr(RELOGIOGRATIS);
    RELOGIOGRATISSTR := local_284;
    local_284 := PASTA + 'relogiogratis.txt';
    local_384 := local_284;
    AssignFile(local_254, local_384);
    Rewrite(local_254);
    local_284 := Cripta(RELOGIOGRATISSTR);
    Write(local_254, local_284);
    Writeln(local_254);
    Flush(local_254);
    CloseFile(local_254);
  end;
end;

{ JUKELINUX1_GRAVA_HD_RELOGIOGRATISVIP }
procedure Grava_Hd_Relogiogratisvip;
var
  local_284, local_384: AnsiString;
  local_254: Text;
begin
  begin
    local_284 := IntToStr(RELOGIOGRATISVIP);
    RELOGIOGRATISVIPSTR := local_284;
    local_284 := PASTA + 'relogiogratisvip.txt';
    local_384 := local_284;
    AssignFile(local_254, local_384);
    Rewrite(local_254);
    local_284 := Cripta(RELOGIOGRATISVIPSTR);
    Write(local_254, local_284);
    Writeln(local_254);
    Flush(local_254);
    CloseFile(local_254);
  end;
end;

{ JUKELINUX1_GRAVA_HD_RELOGIOS }
procedure Grava_Hd_Relogios;
var
  local_258, local_25c, local_384, local_388: AnsiString;
  local_254: Text;
begin
  begin
    local_258 := IntToStr(RELOGIOTOTAL);
    RELOGIOTOTALSTR := local_258;
    local_25c := Cripta(local_258);
    local_388 := PASTA + 'relogiototal.txt';
    local_384 := local_388;
    AssignFile(local_254, local_384);
    Rewrite(local_254);
    Write(local_254, local_25c);
    Writeln(local_254);
    Flush(local_254);
    CloseFile(local_254);
    local_258 := IntToStr(RELOGIOPARCIAL);
    RELOGIOPARCIALSTR := local_258;
    local_25c := Cripta(local_258);
    local_388 := PASTA + 'relogioparcial.txt';
    local_384 := local_388;
    AssignFile(local_254, local_384);
    Rewrite(local_254);
    Write(local_254, local_25c);
    Writeln(local_254);
    Flush(local_254);
    CloseFile(local_254);
  end;
end;

{ JUKELINUX1_GRAVA_PENDRIVE_CONTADORES }
procedure Grava_Pendrive_Contadores;
var
  local_290, local_294, local_298, local_29c, local_2a0, local_2a4, local_2a8, local_2ac, local_2b0, local_2b4, local_2b8, local_2bc, local_2c0, local_390, local_398, local_39c, local_3a0, local_3a4: AnsiString;
  cVar1: Boolean;
  iVar3, local_8, local_c: LongInt;
  local_264: Text;
  local_10, local_394: Variant;
begin
  begin
    local_290 := PASTACHAVE + 'jukebox.contadores';
    cVar1 := FileExists(local_290);
    if not cVar1 then begin
      if SEMPENDRIVE = 0 then begin
        ShowMessage('O / não Esta Conectado ou Esta Faltando o Arquivo jukebox.contadores');
      end;
      JAGRAVOUNOPENDRIVE := 0;
    end
    else begin
      local_290 := PASTACHAVE + 'jukebox.contadores';
      local_390 := local_290;
      AssignFile(local_264, local_390);
      Rewrite(local_264);
      local_290 := Criptasuper2(JC_SERIALPENDRIVECON);
      Write(local_264, local_290);
      Writeln(local_264);
      local_10 := Criptasuper2(JC_SERIALPENDRIVECON);
      local_394 := IntToStr(RELOGIOTOTAL);
      local_290 := Criptasuper2(local_394);
      Write(local_264, local_290);
      Writeln(local_264);
      local_290 := IntToStr(RELOGIOTOTAL);
      local_394 := Criptasuper2(local_290);
      local_10 := local_10 + local_394;
      local_290 := IntToStr(RELOGIOPARCIAL);
      local_394 := Criptasuper2(local_290);
      Write(local_264, local_394);
      Writeln(local_264);
      local_290 := IntToStr(RELOGIOPARCIAL);
      local_394 := Criptasuper2(local_290);
      local_10 := local_10 + local_394;
      local_290 := IntToStr(PORCENTAGEMDOPONTO);
      local_394 := Criptasuper2(local_290);
      Write(local_264, local_394);
      Writeln(local_264);
      local_290 := IntToStr(PORCENTAGEMDOPONTO);
      local_394 := Criptasuper2(local_290);
      local_10 := local_10 + local_394;
      local_290 := IntToStr(RELOGIOGRATIS);
      local_394 := Criptasuper2(local_290);
      Write(local_264, local_394);
      Writeln(local_264);
      local_290 := IntToStr(RELOGIOGRATIS);
      local_394 := Criptasuper2(local_290);
      local_10 := local_10 + local_394;
      local_290 := IntToStr(RELOGIOGRATISVIP);
      local_394 := Criptasuper2(local_290);
      Write(local_264, local_394);
      Writeln(local_264);
      local_290 := IntToStr(RELOGIOGRATISVIP);
      local_394 := Criptasuper2(local_290);
      local_10 := local_10 + local_394;
      iVar3 := 0;
      if local_10 <> 0 then begin
        // C: iVar3 = *(int * )(local_10 + -4);
      end;
      local_8 := 1;
      if 0 < iVar3 then begin
        repeat
          local_8 := local_8 + 1;
          // C: local_c = (uint)*(byte * )(local_10 + -1 + local_8) + local_c;
        until not (local_8 < iVar3);
      end;
      local_394 := IntToStr(local_c);
      local_10 := local_394;
      local_394 := Criptasuper2(local_10);
      Write(local_264, local_394);
      Writeln(local_264);
      Flush(local_264);
      CloseFile(local_264);
      local_2c0 := 'Gravando no PenDrive os Contadores: ';
      local_2bc := PASTACHAVE;
      local_2b8 := 'jukebox.contadores: RT=';
      local_398 := IntToStr(RELOGIOTOTAL);
      local_290 := Strzero(local_398, 6);
      local_2b4 := local_290;
      local_2b0 := ' RP=';
      local_39c := IntToStr(RELOGIOPARCIAL);
      local_398 := Strzero(local_39c, 6);
      local_2ac := local_398;
      local_2a8 := ' %=';
      local_39c := IntToStr(PORCENTAGEMDOPONTO);
      local_2a4 := local_39c;
      local_2a0 := ' RG=';
      local_3a0 := IntToStr(RELOGIOGRATIS);
      local_29c := local_3a0;
      local_298 := ' RGVIP=';
      local_3a4 := IntToStr(RELOGIOGRATISVIP);
      local_294 := local_3a4;
      // C: fpc_ansistr_concat_multi(&local_394,&local_2c0,0xb);
      Gravalog(local_394);
      JAGRAVOUNOPENDRIVE := 0;
    end;
  end;
end;

{ JUKELINUX1_INICIA_TELA }
procedure Inicia_Tela;
var
  local_30, local_34, local_38, local_44, local_48: AnsiString;
  cVar1: Boolean;
  local_3c, local_40: Variant;
begin
  begin
    Gravalog('Inico da Rotina: Inicia_Tela');
    Define_Exibirvideos;
    Gravalog('Rotina Inicia_Tela: Define_ExibirVideos');
    Carregando_Cartoes;
    Gravalog('Rotina Inicia_Tela: Carregando_Cartoes');
    Mostra_Tela_Carregando_Cds;
    Gravalog('Rotina Inicia_Tela: Mostra_Tela_Carregando_Cds');
    Gravalog('Rotina Inicia_Tela: Inicio-Carregando_Cds');
    Carregando_Cds;
    Form1.FileListBox1.Top := 1400;
    Form1.FileListBox1.Visible := False;
    Gravalog('Rotina Inicia_Tela: Fim-Carregando_Cds');
    Gravalog('Rotina Inicia_Tela: Inicio-Carregando_Karaokes');
    Form1.FileListBox1.Visible := True;
    Carregando_Karaokes;
    Form1.FileListBox1.Visible := False;
    Gravalog('Rotina Inicia_Tela: Fim-Carregando_Karaokes');
    Gravalog('Rotina Inicia_Tela: Tela_De_AutoTeste');
    if AUTOTESTE = 'Sim' then begin
      Tela_De_Autoteste;
    end;
    Gravalog('Rotina Inicia_Tela: Tela_De_AutoTeste');
    local_30 := PASTA + 'apagaatu.txt';
    cVar1 := FileExists(local_30);
    if cVar1 then begin
      local_34 := PASTA + 'apagaatu.txt';
      // C: puVar4 = local_34;
      if False { C: local_34 == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar4,local_30);
      DeleteFile(local_30);
      Gravalog('Rotina ApagaAtu');
      ShowMessage('Foram Apagados os arquivos .ATU, Carregue novamente o Software');
      FORM1.Close;
    end;
    Form1.TimerCadastro.Enabled := True;
    Tela1;
    Gravalog('Inicio da Rotina Carregando_Propagandas');
    Carregando_Propagandas;
    Ativa_Propaganda;
    KMAT := -4;
    MUSICASELECIONADA := 0;
    MUSICASELECIONADAPOSTELA := 0;
    MUSICASELECIONADATS := 0;
    if RESOLUCAO = 1366 then begin
      TAMANHOMUSICAGRANDE := 30;
    end;
    if RESOLUCAO = 1024 then begin
      TAMANHOMUSICAGRANDE := 22;
    end;
    if RESOLUCAO = 1440 then begin
      TAMANHOMUSICAGRANDE := 30;
    end;
    SOMAMUSICAGRANDE := 0;
    MOSTRANDORITMOS := 0;
    MOSTRANDOLETRAS := 0;
    Mostra_Cds(' ');
    Mostra_Nome_Das_Musicas;
    Mostra_Fila;
    Form1.TimerNomeMusicaGrande.Enabled := True;
    if LIMITARVOLUMESTR <> '0' then begin
      Form1.TimerVolume22hs.Enabled := True;
    end;
    if 0 < TOTALFRASE then begin
      Form1.TimerFrases.Enabled := True;
    end;
    Form1.TimerTocar.Enabled := True;
    Form1.TimerTocar.Enabled := True;
    if TEMPOPARAPAGINARSOZINHO = 0 then begin
      Form1.TimerPaginaSozinho.Enabled := False;
    end
    else begin
      Form1.TimerPaginaSozinho.Enabled := True;
    end;
    if MUSICAGRATIS = 'Sem Musica Gratis' then begin
      Form1.TimerMusicaGratis.Enabled := False;
    end
    else begin
      Form1.TimerMusicaGratis.Enabled := True;
    end;
    Form1.TimerUmMinuto.Enabled := True;
    if (BLOQUEARQUANDOTOCAR <> -1) and (BLOQUEARQUANDOTOCAR <= QUANTIDADESDEMUSICASTOCADAS) then begin
      if (QUANTIDADESDEMUSICASTOCADAS = 0) and (BLOQUEARQUANDOTOCAR = 0) then begin
        Form1.PanelBloqueio.Caption := 'Sistema Bloqueado, Entre no Menu e Digite a Senha';
      end
      else begin
        local_44 := 'Tocou ';
        local_30 := IntToStr(QUANTIDADESDEMUSICASTOCADAS);
        local_40 := local_30;
        local_3c := ' Músicas, Sistema Bloqueado';
        local_38 := local_44 + local_40 + local_3c;
        Form1.PanelBloqueio.Caption := local_38;
      end;
      Form1.PanelBloqueio.Left := Form1.Left + 50;
      Form1.PanelBloqueio.Top := Form1.Top + 50;
      Form1.PanelBloqueio.Width := Form1.Width + -100;
      Form1.PanelBloqueio.Height := Form1.Height + -100;
      Form1.PanelBloqueio.Show;
      Form1.PanelBloqueio.BringToFront;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.PanelBloqueio,&local_48);
      Gravalog(local_48);
    end;
    Gravalog('Inicio da Operacao do Software JukeLinux (SetFocus no Form)');
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x430))(U_JUKELINUX1_FORM1);
  end;
end;

{ JUKELINUX1_LECREDITODOCARTAO$ANSISTRING$$LONGINT }
function Lecreditodocartao(P1: AnsiString): LongInt;
var
  local_10, local_148, local_14c, local_1c, local_20, local_8: AnsiString;
  cVar1: Boolean;
  local_14, local_18, local_c: LongInt;
begin
  local_8 := P1;
  // C: fpc_ansistr_incr_ref();
  begin
    local_1c := PASTA + 'cartoes.ccc';
    cVar1 := FileExists(local_1c);
    if not cVar1 then begin
      local_14c := 'Erro: Falta o Arquivo CARTOESPP.CCC ao ler os creditos do cartao:' + local_8;
      Gravalog(local_14c);
    end
    else begin
      local_148 := local_1c;
      // C: OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING(U_JUKELINUX1_ARQCARTAOM,local_148);
      // C: fpc_reset_typed(U_JUKELINUX1_ARQCARTAOM,0x26);
      while True do begin
        // C: cVar1 = SYSTEM_EOF_file__BOOLEAN(U_JUKELINUX1_ARQCARTAOM);
        if cVar1 then begin Break; end;
        // C: SYSTEM_SEEK_file_INT64(U_JUKELINUX1_ARQCARTAOM);
        // C: FPC_TYPED_READ(0x26,U_JUKELINUX1_ARQCARTAOM,U_JUKELINUX1_ACARM);
        ACARM := local_14c;
        local_20 := Descripta(local_14c);
        if local_8 = local_20 then begin
          // C: fpc_shortstr_to_ansistr(0x964703f,&local_14c);
          local_10 := Descripta(local_14c);
          local_18 := StrToIntDef(local_10, 0);
          local_c := local_18;
        end;
        local_14 := local_14 + 1;
      end;
      // C: OBJPAS_CLOSEFILE_file(U_JUKELINUX1_ARQCARTAOM);
    end;
  end;
  Result := local_c; Exit;
end;

{ JUKELINUX1_LE_ARQUIVO_DE_CADASTRO }
procedure Le_Arquivo_De_Cadastro;
var
  local_134, local_34, local_8: AnsiString;
  cVar1: Boolean;
begin
  begin
    local_34 := PASTACHAVE + 'jukebox.cadastro';
    cVar1 := FileExists(local_34);
    if cVar1 then begin
      local_34 := PASTACHAVE + 'jukebox.cadastro';
      local_134 := local_34;
      AssignFile(ARQTEXTO, local_134);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      JC_CODIGODAMAQUINA := local_8;
      // C: fpc_ansistr_incr_ref();
      CODIGODAMAQUINASTR := JC_CODIGODAMAQUINA;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      NOMEDOPONTOSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      CLIENTESTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      RGSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      CPFSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      TELEFONESSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      ENDERECOSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      BAIRROSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      CIDADESTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      DATADAINSTALACAOSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      SELOSSTR := local_8;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_8 := Descriptasimples(TEXTO);
      CloseFile(ARQTEXTO);
    end;
  end;
end;

{ JUKELINUX1_LE_TOCADOS }
procedure Le_Tocados;
var
  local_13c, local_3c, local_48, local_4c: AnsiString;
  cVar2: Boolean;
  iVar1, iVar4, iVar5, local_10, local_8, local_c: LongInt;
  local_140, local_40, local_44: Variant;
begin
  begin
    Form1.LabelListaTocados.Show;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    FORM1.Refresh;
    local_3c := PASTA + 'tocados.txt';
    cVar2 := FileExists(local_3c);
    if cVar2 then begin
      local_3c := PASTA + 'tocados.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Reset(ARQTEXTO);
      while True do begin
        cVar2 := Eof(ARQTEXTO);
        if cVar2 then begin Break; end;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        iVar1 := TOTALCDS;
        local_8 := 1;
        if 0 < TOTALCDS then begin
          repeat
            local_8 := local_8 + 1;
            // C: iVar5 = (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90];
            local_c := 1;
            if 0 < iVar5 then begin
              repeat
                local_c := local_c + 1;
                // C: iVar4 = fpc_ansistr_compare_equal ( *(undefined4 * )(local_8 * 0x240 + 0x8e91144 + local_c * 4), U_JUKELINUX1_TEXTO);
                if iVar4 = 0 then begin
                  // C: (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] = (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] + 1;
                end;
              until not (local_c < iVar5);
            end;
          until not (local_8 < iVar1);
        end;
      end;
      CloseFile(ARQTEXTO);
    end;
    // C: ( **(code ** )( *(int * )Form1.ListBoxRGeneros + 0x480))(Form1.ListBoxRGeneros);
    iVar1 := TOTALMMRITMO;
    if 0 < TOTALMMRITMO then begin
      repeat
        local_10 := local_10 + 1;
        // C: *(undefined4 * )(&DAT_0930013c + local_10 * 4) = 0;
      until not (local_10 < iVar1);
    end;
    iVar1 := TOTALMMRITMO;
    if 0 < TOTALMMRITMO then begin
      repeat
        iVar5 := TOTALCDS;
        local_10 := local_10 + 1;
        local_8 := 1;
        if 0 < TOTALCDS then begin
          repeat
            local_8 := local_8 + 1;
            // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,local_3c);
            // C: iVar4 = fpc_ansistr_compare_equal (local_3c[0],*(undefined4 * )(&DAT_092fffac + local_10 * 4));
            if iVar4 = 0 then begin
              // C: *(int * )(&DAT_0930013c + local_10 * 4) = *(int * )(&DAT_0930013c + local_10 * 4) + (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90];
            end;
          until not (local_8 < iVar5);
        end;
      until not (local_10 < iVar1);
    end;
    iVar1 := TOTALMMRITMO;
    local_10 := 1;
    if 0 < TOTALMMRITMO then begin
      repeat
        local_10 := local_10 + 1;
        // C: iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("50+TOCADOS",*(undefined4 * )(&DAT_092fffac + local_10 * 4));
        if iVar5 = 0 then begin
          // C: local_4c = *(undefined4 * )(&DAT_092fffac + local_10 * 4);
          local_48 := ' (';
          // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ( *(undefined4 * )(&DAT_0930013c + local_10 * 4),&local_140);
          local_44 := local_140;
          local_40 := ')';
          local_3c := local_4c + local_48 + local_44 + local_40;
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRGeneros + 0x364) + 0xa4)) (Form1.ListBoxRGeneros.Items,local_3c[0]);
        end
        else begin
          // C: fpc_ansistr_concat(&local_140,*(undefined4 * )(&DAT_092fffac + local_10 * 4), " (---)");
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRGeneros + 0x364) + 0xa4)) (Form1.ListBoxRGeneros.Items,local_140);
        end;
      until not (local_10 < iVar1);
    end;
    // C: ( **(code ** )( *(int * )Form1.ListBoxRCds + 0x480))(Form1.ListBoxRCds);
    Form1.LabelListaTocados.Hide;
    // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
    FORM1.Refresh;
  end;
end;

{ JUKELINUX1_LE_TOUCHSCREEN_FINAL }
procedure Le_Touchscreen_Final;
var
  local_8, local_c: LongInt;
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb58) + 0xd8)) (Form1.TimerUmMilesegundo,param_2 & 0xffffff00);
  P_VELOCIDADE_FINAL := TEMPOEMMILLESEGUNDOS;
  // C: CONTROLS_TMOUSE____GETCURSORPOS__TPOINT(U_CONTROLS_MOUSE,&local_c);
  P_FINAL_X := local_c;
  // C: CONTROLS_TMOUSE____GETCURSORPOS__TPOINT(U_CONTROLS_MOUSE,&local_c);
  P_FINAL_Y := local_8;
  P_DESLOCAMENTO_X := P_FINAL_X - P_INICIAL_X;
  P_DESLOCAMENTO_Y := local_8 - P_INICIAL_Y;
end;

{ JUKELINUX1_LE_TOUCHSCREEN_INICIAL }
procedure Le_Touchscreen_Inicial;
var
  local_8, local_c: LongInt;
begin
  // C: CONTROLS_TMOUSE____GETCURSORPOS__TPOINT(U_CONTROLS_MOUSE,&local_c);
  P_INICIAL_X := local_c;
  // C: CONTROLS_TMOUSE____GETCURSORPOS__TPOINT(U_CONTROLS_MOUSE,&local_c);
  P_INICIAL_Y := local_8;
  P_FINAL_X := 0;
  P_FINAL_Y := 0;
  P_DESLOCAMENTO_X := 0;
  P_DESLOCAMENTO_Y := 0;
  P_VELOCIDADE_FINAL := 0;
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb58) + 0xdc)) (Form1.TimerUmMilesegundo,1);
  Form1.TimerUmMilesegundo.Enabled := True;
end;

{ JUKELINUX1_LIBERA_QUANTIDADESDEMUSICASTOCADAS }
procedure Libera_Quantidadesdemusicastocadas;
var
  local_12c, local_130: AnsiString;
begin
  begin
    QUANTIDADESDEMUSICASTOCADAS := 0;
    local_130 := PASTA + 'jukelinux.txt';
    local_12c := local_130;
    AssignFile(ARQTEXTO, local_12c);
    Rewrite(ARQTEXTO);
    local_130 := Criptasuper2(JC_SERIALPENDRIVECON);
    Write(ARQTEXTO, local_130);
    Writeln(ARQTEXTO);
    local_130 := Criptasuper2('0');
    Write(ARQTEXTO, local_130);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    Form1.PanelBloqueio.Hide;
  end;
end;

{ JUKELINUX1_MENSAGEMJPG$ANSISTRING$LONGINT$ANSISTRING }
procedure Mensagemjpg(P1: AnsiString; P2: LongInt; P3: AnsiString);
var
  local_10, local_3c, local_8: AnsiString;
  cVar1: Boolean;
  local_c: LongInt;
begin
  local_10 := P3;
  local_c := P2;
  local_8 := P1;
  begin
    local_3c := PASTA + local_8;
    cVar1 := FileExists(local_3c);
    if cVar1 then begin
      if 0 < MOSTRANDOSETABAIXO then begin
        Form1.SetaBaixo.Hide;
        MOSTRANDOSETABAIXO := -1;
      end;
      local_3c := PASTA + local_8;
      Form1.Imagemsg.Picture.LoadFromFile(local_3c);
      Form1.Imagemsg.Left := Form1.Musica1.Left;
      Form1.Imagemsg.Top := Form1.Musica1.Top;
      Form1.Imagemsg.Width := Form1.Musica1.Width;
      Form1.Imagemsg.Height := 370;
      Form1.Imagemsg.Show;
      LIMPAMSG := 1;
      if local_8 = 'mensagem1366-ultimocd.jpg' then begin
        LIMPAMSG := 0;
      end;
      if local_8 = 'mensagem1366-primeirocd.jpg' then begin
        LIMPAMSG := 0;
      end;
      if local_8 = 'mensagem1024-primeirocd.jpg' then begin
        LIMPAMSG := 0;
      end;
      if local_8 = 'mensagem1024-ultimocd.jpg' then begin
        LIMPAMSG := 0;
      end;
      if local_c = 0 then begin
        Form1.LabelMsg1.Hide;
      end;
      if local_c = 1 then begin
        Form1.LabelMsg1.Left := Form1.Imagemsg.Left + 45;
        Form1.LabelMsg1.Top := Form1.Imagemsg.Top + 168;
        Form1.LabelMsg1.Height := Form1.Imagemsg.Height + -160;
        Form1.LabelMsg1.Width := Form1.Imagemsg.Width + -100;
        Form1.LabelMsg1.Font.Color := 16777215;
        if RESOLUCAO = 1366 then begin
          Form1.LabelMsg1.Font.Size := 26;
        end;
        if RESOLUCAO = 1440 then begin
          Form1.LabelMsg1.Font.Size := 26;
        end;
        if RESOLUCAO = 1024 then begin
          Form1.LabelMsg1.Font.Size := 26;
        end;
        Form1.LabelMsg1.Caption := local_10;
        Form1.LabelMsg1.Show;
      end;
      if local_c = 2 then begin
        Form1.LabelMsg1.Left := Form1.Imagemsg.Left + 45;
        Form1.LabelMsg1.Top := Form1.Imagemsg.Top + 133;
        Form1.LabelMsg1.Height := Form1.Imagemsg.Height + -160;
        Form1.LabelMsg1.Width := Form1.Imagemsg.Width + -100;
        Form1.LabelMsg1.Font.Color := 65535;
        if RESOLUCAO = 1366 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        if RESOLUCAO = 1440 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        Form1.LabelMsg1.Caption := local_10;
        Form1.LabelMsg1.Show;
      end;
      if local_c = 3 then begin
        Form1.LabelMsg1.Hide;
        Form1.CapaSelecionadaMsg.Top := Form1.CapaSelecionada.Top;
        if RESOLUCAO = 1366 then begin
          Form1.CapaSelecionadaMsg.Left := Form1.Imagemsg.Left + 130;
        end;
        if RESOLUCAO = 1440 then begin
          Form1.CapaSelecionadaMsg.Left := Form1.Imagemsg.Left + 130;
        end;
        if RESOLUCAO = 1024 then begin
          Form1.CapaSelecionadaMsg.Left := Form1.Imagemsg.Left + 10;
        end;
        Form1.CapaSelecionadaMsg.Width := 357;
        Form1.CapaSelecionadaMsg.Height := 322;
        Form1.CDSelecionadoMsg.Top := Form1.CDSelecionado.Top;
        Form1.CDSelecionadoMsg.Left := Form1.CapaSelecionadaMsg.Left + 51;
        Form1.CDSelecionadoMsg.Width := 290;
        Form1.CDSelecionadoMsg.Height := 290;
        Form1.ImageSetaMsg.Top := Form1.CapaSelecionadaMsg.Top + 120;
        Form1.ImageSetaMsg.Left := Form1.CapaSelecionadaMsg.Left + 330;
        Form1.ImageSetaMsg.Width := 100;
        Form1.ImageSetaMsg.Height := 100;
        local_3c := Mostra_Jpg_Ritmo(local_10);
        Form1.CDSelecionadoMsg.Picture.LoadFromFile(local_3c);
        Form1.ImageSetaMsg.Show;
        Form1.ImageSetaMsg.BringToFront;
        Form1.CDSelecionadoMsg.Show;
        Form1.CDSelecionadoMsg.BringToFront;
        Form1.CapaSelecionadaMsg.Show;
        Form1.CapaSelecionadaMsg.BringToFront;
        FORM1.Refresh;
        // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      end;
      if local_c = 4 then begin
        Form1.LabelMsg1.Hide;
        Form1.CapaSelecionadaMsg.Top := Form1.CapaSelecionada.Top;
        if RESOLUCAO = 1366 then begin
          Form1.CapaSelecionadaMsg.Left := Form1.Imagemsg.Left + 130;
        end;
        if RESOLUCAO = 1440 then begin
          Form1.CapaSelecionadaMsg.Left := Form1.Imagemsg.Left + 130;
        end;
        if RESOLUCAO = 1024 then begin
          Form1.CapaSelecionadaMsg.Left := Form1.Imagemsg.Left + 10;
        end;
        Form1.CapaSelecionadaMsg.Width := 357;
        Form1.CapaSelecionadaMsg.Height := 322;
        Form1.CDSelecionadoMsg.Top := Form1.CDSelecionado.Top;
        Form1.CDSelecionadoMsg.Left := Form1.CapaSelecionadaMsg.Left + 51;
        Form1.CDSelecionadoMsg.Width := 290;
        Form1.CDSelecionadoMsg.Height := 290;
        Form1.ImageSetaMsg.Top := Form1.CapaSelecionadaMsg.Top + 120;
        Form1.ImageSetaMsg.Left := Form1.CapaSelecionadaMsg.Left + 330;
        Form1.ImageSetaMsg.Width := 100;
        Form1.ImageSetaMsg.Height := 100;
        local_3c := Mostra_Jpg_Letra(local_10);
        Form1.CDSelecionadoMsg.Picture.LoadFromFile(local_3c);
        Form1.ImageSetaMsg.Show;
        Form1.ImageSetaMsg.BringToFront;
        Form1.CDSelecionadoMsg.Show;
        Form1.CDSelecionadoMsg.BringToFront;
        Form1.CapaSelecionadaMsg.Show;
        Form1.CapaSelecionadaMsg.BringToFront;
        FORM1.Refresh;
        // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      end;
      if local_c = 5 then begin
        Form1.LabelMsg1.Left := Form1.Imagemsg.Left + 45;
        Form1.LabelMsg1.Top := Form1.Imagemsg.Top + 133;
        Form1.LabelMsg1.Height := Form1.Imagemsg.Height + -160;
        Form1.LabelMsg1.Width := Form1.Imagemsg.Width + -100;
        Form1.LabelMsg1.Font.Color := 16777215;
        if RESOLUCAO = 1366 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        if RESOLUCAO = 1440 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        if RESOLUCAO = 1024 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        Form1.LabelMsg1.Caption := local_10;
        Form1.LabelMsg1.Show;
      end;
      if LIMPAMSG = 0 then begin
        // C: ( **(code ** )( *(int * )Form1.TimerEscondeMsg + 0xdc))(Form1.TimerEscondeMsg,500);
      end
      else begin
        // C: ( **(code ** )( *(int * )Form1.TimerEscondeMsg + 0xdc)) (Form1.TimerEscondeMsg,U_JUKELINUX1_TEMPOEM1);
      end;
      Form1.TimerEscondeMsg.Enabled := False;
      Form1.TimerEscondeMsg.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_MENSAGEMTRAVADAJPG$ANSISTRING$LONGINT$ANSISTRING }
procedure Mensagemtravadajpg(P1: AnsiString; P2: LongInt; P3: AnsiString);
var
  local_10, local_3c, local_8: AnsiString;
  cVar1: Boolean;
  local_c: LongInt;
begin
  local_10 := P3;
  local_c := P2;
  local_8 := P1;
  begin
    local_3c := PASTA + local_8;
    cVar1 := FileExists(local_3c);
    if cVar1 then begin
      if 0 < MOSTRANDOSETABAIXO then begin
        Form1.SetaBaixo.Hide;
        MOSTRANDOSETABAIXO := -1;
      end;
      local_3c := PASTA + local_8;
      Form1.Imagemsg.Picture.LoadFromFile(local_3c);
      Form1.Imagemsg.Left := Form1.Musica1.Left;
      Form1.Imagemsg.Top := Form1.Musica1.Top;
      Form1.Imagemsg.Width := Form1.Musica1.Width;
      Form1.Imagemsg.Height := 370;
      Form1.Imagemsg.Show;
      if local_c = 0 then begin
        Form1.LabelMsg1.Hide;
      end;
      if local_c = 3 then begin
        Form1.LabelMsg1.Left := Form1.Imagemsg.Left + 45;
        Form1.LabelMsg1.Top := Form1.Imagemsg.Top + 128;
        Form1.LabelMsg1.Height := Form1.Imagemsg.Height + -160;
        Form1.LabelMsg1.Width := Form1.Imagemsg.Width + -100;
        Form1.LabelMsg1.Font.Color := 16777215;
        if RESOLUCAO = 1366 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        if RESOLUCAO = 1440 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        if RESOLUCAO = 1024 then begin
          Form1.LabelMsg1.Font.Size := 60;
        end;
        Form1.LabelMsg1.Caption := local_10;
        Form1.LabelMsg1.Show;
      end;
    end;
  end;
end;

{ JUKELINUX1_MOSTRA_CDS$ANSISTRING }
procedure Mostra_Cds(P1: AnsiString);
label
  LAB_080a5430, LAB_080a5602, LAB_080a57e2, LAB_080a59c2, LAB_080a5bd2, LAB_080a6ae6, LAB_080a6cca, LAB_080a6eae, LAB_080a7092, LAB_080a733c, LAB_080a91e6;
var
  local_34, local_38, local_8: AnsiString;
  iVar1, iVar2, uVar3: LongInt;
begin
  local_8 := P1;
  // C: fpc_ansistr_incr_ref();
  // C: iVar1 = fpc_setjmp();
  if iVar1 <> 0 then begin goto LAB_080a91e6; end;
  local_34 := Copy(ORDEMDOSCDS, 1, 1);
  if local_34 = 'R' then begin
    if TRAVADODENTRODORITMO = '' then begin
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      TRAVADODENTRODORITMO := local_34;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      RITMODOCD := local_34;
    end;
    if local_8 = ' ' then begin
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      TRAVADODENTRODORITMO := local_34;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      RITMODOCD := local_34;
    end;
    // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
    RITMODOCD := local_34;
    MMCCDDSS := 0;
    if local_34 = TRAVADODENTRODORITMO then begin
      MMCCDDSS := 1;
    end;
    if FORMADEPAGINACAO = 'Continua' then begin
      MMCCDDSS := 1;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      TRAVADODENTRODORITMO := local_34;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      RITMODOCD := local_34;
    end;
    if MMCCDDSS = 0 then begin
      if local_8 = '+' then begin
        if SENTIDODAPAGINACAO = 'Anti-Horário' then begin
          KMAT := KMAT + 1;
        end;
        if SENTIDODAPAGINACAO = 'Horário' then begin
          KMAT := KMAT + -1;
        end;
      end;
      if local_8 = '-' then begin
        if SENTIDODAPAGINACAO = 'Anti-Horário' then begin
          KMAT := KMAT + -1;
        end;
        if SENTIDODAPAGINACAO = 'Horário' then begin
          KMAT := KMAT + 1;
        end;
      end;
    end
    else begin
      if SEGURANDOTECLA < 8 then begin
        MOSTRAPAGINANDOCDS := 1;
      end
      else if 14 < SEGURANDOTECLA then begin
        if LETRASEXE = '3MJ' then begin
          MOSTRAPAGINANDOCDS := 0;
        end
        else begin
          MOSTRAPAGINANDOCDS := 1;
        end;
      end;
      if MOSTRAPAGINANDOCDS <> 0 then begin
        if KMAT < 1 then begin
          LAB_080a5430: ;
          Form1.CDMenos5.Hide;
          Form1.ImgLanMenos5.Hide;
          Form1.Img50Menos5.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KMAT * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a5430; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos5,extraout_EDX & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos5.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMAT * 0x240 + 0x204));
          Form1.CDMenos5.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL (U_JUKELINUX1_KMAT * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMenos5.Show;
          end
          else begin
            Form1.ImgLanMenos5.Hide;
          end;
          // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KMAT * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Menos5.Show;
          end
          else begin
            Form1.Img50Menos5.Hide;
          end;
          // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KMAT * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL (U_JUKELINUX1_KMAT * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMenos5.Hide;
          end;
        end;
        if KMAT + 1 < 1 then begin
          LAB_080a5602: ;
          Form1.CDMenos4.Hide;
          Form1.ImgLanMenos4.Hide;
          Form1.Img50Menos4.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a5602; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos4,extraout_EDX_00 & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos4.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 1) * 0x240 + 0x204));
          Form1.CDMenos4.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMenos4.Show;
          end
          else begin
            Form1.ImgLanMenos4.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Menos4.Show;
          end
          else begin
            Form1.Img50Menos4.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMenos4.Hide;
          end;
        end;
        if KMAT + 2 < 1 then begin
          LAB_080a57e2: ;
          Form1.CDMenos3.Hide;
          Form1.ImgLanMenos3.Hide;
          Form1.Img50Menos3.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a57e2; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos3,extraout_EDX_01 & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos3.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 2) * 0x240 + 0x204));
          Form1.CDMenos3.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMenos3.Show;
          end
          else begin
            Form1.ImgLanMenos3.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Menos3.Show;
          end
          else begin
            Form1.Img50Menos3.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMenos3.Hide;
          end;
        end;
        if KMAT + 3 < 1 then begin
          LAB_080a59c2: ;
          Form1.CDMenos2.Hide;
          Form1.ImgLanMenos2.Hide;
          Form1.Img50Menos2.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a59c2; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos2,extraout_EDX_02 & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos2.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 3) * 0x240 + 0x204));
          Form1.CDMenos2.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMenos2.Show;
          end
          else begin
            Form1.ImgLanMenos2.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Menos2.Show;
          end
          else begin
            Form1.Img50Menos2.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMenos2.Hide;
          end;
        end;
        if 0 < KMAT + 4 then begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e91128,local_34);
          if local_34 = TRAVADODENTRODORITMO then begin
            // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos1,extraout_EDX_03 & 0xffffff00);
            // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos1.Picture, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 4) * 0x240 + 0x204));
            Form1.CDMenos1.Show;
            // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e9133e,"S");
            if iVar2 = 0 then begin
              Form1.ImgLanMenos1.Show;
            end
            else begin
              Form1.ImgLanMenos1.Hide;
            end;
            // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e91128,local_34);
            if local_34 = '50+TOCADOS' then begin
              Form1.Img50Menos1.Show;
            end
            else begin
              Form1.Img50Menos1.Hide;
            end;
            // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e91128,local_34);
            // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
            if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e9133e,"S") , iVar2 == 0) } then begin
              Form1.ImgLanMenos1.Hide;
            end;
            goto LAB_080a5bd2;
          end;
        end;
        Form1.CDMenos1.Hide;
        Form1.ImgLanMenos1.Hide;
        Form1.Img50Menos1.Hide;
      end;
      LAB_080a5bd2: ;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDSelecionado.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x200));
      local_38 := IntToStr(KMAT + 5);
      Form1.NumCD.Caption := local_38;
      iVar2 := 0;
      if False { C: *(int * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc) != 0 } then begin
        // C: iVar2 = *(int * )( *(int * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc) + -4);
      end;
      // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc),1,iVar2 + -1 ,&local_38);
      Form1.NomeDoCD.Caption := local_38;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      RITMODOCD := local_34;
      // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc),1,1,local_34 );
      LETRADOCD := local_34;
      // ?: SERIAL + (KMAT + 5) * 144 := local_34;
      if local_34 = 'DVD' then begin
        Form1.LabelCDDVD.Caption := 'DVD';
        Form1.LabelCDDVD1.Font.Color := 65535;
        Form1.ImgDVD.Show;
      end
      else begin
        Form1.LabelCDDVD.Caption := 'CD';
        Form1.LabelCDDVD1.Font.Color := 16777215;
        Form1.ImgDVD.Hide;
      end;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelCDDVD,&local_38);
      Form1.LabelCDDVD1.Caption := local_38;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,&local_38);
      Form1.LabelRitmo.Caption := local_38;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelRitmo,&local_38);
      Form1.LabelRitmo1.Caption := local_38;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLan.Show;
      end
      else begin
        Form1.ImgLan.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50.Show;
      end
      else begin
        Form1.Img50.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
        Form1.ImgLan.Hide;
      end;
      if SEGURANDOTECLA < 8 then begin
        Form1.ImageSetasPaginacao1.Hide;
        Form1.ImageSetasPaginacao2.Hide;
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica1, (&U_JUKELINUX1_PASTACHAVE8)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2, (&U_JUKELINUX1_PASTACHAVE7)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3, (&U_JUKELINUX1_PASTACHAVE6)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4, (&U_JUKELINUX1_PASTACHAVE5)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5, (&U_JUKELINUX1_PASTACHAVE4)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6, (&U_JUKELINUX1_PASTACHAVE3)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7, (&U_JUKELINUX1_PASTACHAVE2)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8, (&U_JUKELINUX1_PASTACHAVE1)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9, (&U_JUKELINUX1_ULTIMOFECHA)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10, (&U_JUKELINUX1_ERROSERIAL)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11, (&U_JUKELINUX1_ERROSERIALNUM)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12, (&U_JUKELINUX1_LETRASEXE)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica1,local_34);
        NOMEMUSICAORIGINALGRANDE := local_34;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica2,local_34);
        // C: DAT_09301dc4 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica3,local_34);
        // C: DAT_09301dc8 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica4,local_34);
        // C: DAT_09301dcc = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica5,local_34);
        // C: DAT_09301dd0 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica6,local_34);
        // C: DAT_09301dd4 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica7,local_34);
        // C: DAT_09301dd8 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica8,local_34);
        // C: DAT_09301ddc = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica9,local_34);
        // C: DAT_09301de0 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica10,local_34);
        // C: DAT_09301de4 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica11,local_34);
        // C: DAT_09301de8 = local_34[0];
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica12,local_34);
        // C: DAT_09301dec = local_34[0];
        Form1.Musica1.Show;
        Form1.Musica2.Show;
        Form1.Musica3.Show;
        Form1.Musica4.Show;
        Form1.Musica5.Show;
        Form1.Musica6.Show;
        Form1.Musica7.Show;
        Form1.Musica8.Show;
        Form1.Musica9.Show;
        Form1.Musica10.Show;
        Form1.Musica11.Show;
        Form1.Musica12.Show;
        Form1.LabelLM1.Hide;
        Form1.LabelLM2.Hide;
        Form1.LabelLM3.Hide;
        MOSTRANDOLETRANAPAGINACAO := 0;
        iVar2 := 0;
        if False { C: (&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] != 0 } then begin
          // C: iVar2 = *(int * )((&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] + -4 );
        end;
        if 0 < iVar2 then begin
          Form1.SetaBaixo.Show;
          MOSTRANDOSETABAIXO := 1;
        end;
        Form1.NomeDoCD.Show;
        Mostra_Musicas(KMAT + 5);
      end
      else begin
        Form1.Musica1.Hide;
        Form1.Musica2.Hide;
        Form1.Musica3.Hide;
        Form1.Musica4.Hide;
        Form1.Musica5.Hide;
        Form1.Musica6.Hide;
        Form1.Musica7.Hide;
        Form1.Musica8.Hide;
        Form1.Musica9.Hide;
        Form1.Musica10.Hide;
        Form1.Musica11.Hide;
        Form1.Musica12.Hide;
        Form1.LabelLM3.Caption := RITMODOCD;
        Form1.LabelLM1.Show;
        Form1.LabelLM2.Show;
        Form1.LabelLM3.Show;
        if LETRASEXE = '3MJ' then begin
          // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc),1,1, &local_38);
          Form1.LabelLM1.Caption := local_38;
        end
        else begin
          // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc),1,2, &local_38);
          Form1.LabelLM1.Caption := local_38;
        end;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelLM1,&local_38);
        Form1.LabelLM2.Caption := local_38;
        Form1.SetaBaixo.Hide;
        MOSTRANDOSETABAIXO := 0;
        Form1.NomeDoCD.Hide;
        if ESTAPAGINANDOPARA = '+' then begin
          if SENTIDODAPAGINACAO = 'Anti-Horário' then begin
            Form1.ImageSetasPaginacao1.Hide;
            Form1.ImageSetasPaginacao2.Show;
          end;
          if SENTIDODAPAGINACAO = 'Horário' then begin
            Form1.ImageSetasPaginacao1.Show;
            Form1.ImageSetasPaginacao2.Hide;
          end;
        end;
        if ESTAPAGINANDOPARA = '-' then begin
          if SENTIDODAPAGINACAO = 'Anti-Horário' then begin
            Form1.ImageSetasPaginacao1.Show;
            Form1.ImageSetasPaginacao2.Hide;
          end;
          if SENTIDODAPAGINACAO = 'Horário' then begin
            Form1.ImageSetasPaginacao1.Hide;
            Form1.ImageSetasPaginacao2.Show;
          end;
        end;
        Form1.ImageSetasPaginacao1.BringToFront;
        Form1.ImageSetasPaginacao2.BringToFront;
        MOSTRANDOLETRANAPAGINACAO := 1;
        // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbc0) + 0xdc)) (Form1.TimerMostraNomeDeMusicas,500);
        Form1.TimerMostraNomeDeMusicas.Enabled := False;
        Form1.TimerMostraNomeDeMusicas.Enabled := True;
      end;
      if MOSTRAPAGINANDOCDS <> 0 then begin
        if TOTALCDS < KMAT + 6 then begin
          LAB_080a6ae6: ;
          Form1.CDMais1.Hide;
          Form1.ImgLanMais1.Hide;
          Form1.Img50Mais1.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a6ae6; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais1,extraout_EDX_05 & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais1.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 6) * 0x240 + 0x204));
          Form1.CDMais1.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMais1.Show;
          end
          else begin
            Form1.ImgLanMais1.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Mais1.Show;
          end
          else begin
            Form1.Img50Mais1.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMais1.Hide;
          end;
        end;
        if TOTALCDS < KMAT + 7 then begin
          LAB_080a6cca: ;
          Form1.CDMais2.Hide;
          Form1.ImgLanMais2.Hide;
          Form1.Img50Mais2.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a6cca; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais2,extraout_EDX_06 & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais2.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 7) * 0x240 + 0x204));
          Form1.CDMais2.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMais2.Show;
          end
          else begin
            Form1.ImgLanMais2.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Mais2.Show;
          end
          else begin
            Form1.Img50Mais2.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMais2.Hide;
          end;
        end;
        if TOTALCDS < KMAT + 8 then begin
          LAB_080a6eae: ;
          Form1.CDMais3.Hide;
          Form1.ImgLanMais3.Hide;
          Form1.Img50Mais3.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a6eae; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais3,extraout_EDX_07 & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais3.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 8) * 0x240 + 0x204));
          Form1.CDMais3.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMais3.Show;
          end
          else begin
            Form1.ImgLanMais3.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Mais3.Show;
          end
          else begin
            Form1.Img50Mais3.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMais3.Hide;
          end;
        end;
        if TOTALCDS < KMAT + 9 then begin
          LAB_080a7092: ;
          Form1.CDMais4.Hide;
          Form1.ImgLanMais4.Hide;
          Form1.Img50Mais4.Hide;
        end
        else begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e91128,local_34);
          if local_34 <> TRAVADODENTRODORITMO then begin goto LAB_080a7092; end;
          // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais4,extraout_EDX_08 & 0xffffff00);
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais4.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 9) * 0x240 + 0x204));
          Form1.CDMais4.Show;
          // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e9133e,"S");
          if iVar2 = 0 then begin
            Form1.ImgLanMais4.Show;
          end
          else begin
            Form1.ImgLanMais4.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e91128,local_34);
          if local_34 = '50+TOCADOS' then begin
            Form1.Img50Mais4.Show;
          end
          else begin
            Form1.Img50Mais4.Hide;
          end;
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e91128,local_34);
          // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
          if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
            Form1.ImgLanMais4.Hide;
          end;
        end;
        if KMAT + 10 <= TOTALCDS then begin
          // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e91128,local_34);
          if local_34 = TRAVADODENTRODORITMO then begin
            // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais5,extraout_EDX_09 & 0xffffff00);
            // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais5.Picture, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 10) * 0x240 + 0x204));
            Form1.CDMais5.Show;
            // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e9133e,"S");
            if iVar2 = 0 then begin
              Form1.ImgLanMais5.Show;
            end
            else begin
              Form1.ImgLanMais5.Hide;
            end;
            // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e91128,local_34);
            if local_34 = '50+TOCADOS' then begin
              Form1.Img50Mais5.Show;
            end
            else begin
              Form1.Img50Mais5.Hide;
            end;
            // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e91128,local_34);
            // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
            if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e9133e,"S" ), iVar2 == 0) } then begin
              Form1.ImgLanMais5.Hide;
            end;
            goto LAB_080a733c;
          end;
        end;
        Form1.CDMais5.Hide;
        Form1.ImgLanMais5.Hide;
        Form1.Img50Mais5.Hide;
      end;
    end;
  end;
  LAB_080a733c: ;
  local_34 := Copy(ORDEMDOSCDS, 1, 1);
  if local_34 = 'A' then begin
    // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
    RITMODOCD := local_34;
    MMCCDDSS := 1;
    if KMAT < 1 then begin
      Form1.CDMenos5.Hide;
      Form1.ImgLanMenos5.Hide;
      Form1.Img50Menos5.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos5,extraout_EDX_10 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos5.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMAT * 0x240 + 0x204));
      Form1.CDMenos5.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL(U_JUKELINUX1_KMAT * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMenos5.Show;
      end
      else begin
        Form1.ImgLanMenos5.Hide;
      end;
      // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KMAT * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Menos5.Show;
      end
      else begin
        Form1.Img50Menos5.Hide;
      end;
      // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KMAT * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL (U_JUKELINUX1_KMAT * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_12, iVar2 == 0) } then begin
        Form1.ImgLanMenos5.Hide;
      end;
    end;
    if KMAT + 1 < 1 then begin
      Form1.CDMenos4.Hide;
      Form1.ImgLanMenos4.Hide;
      Form1.Img50Menos4.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos4,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos4.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 1) * 0x240 + 0x204));
      Form1.CDMenos4.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMenos4.Show;
      end
      else begin
        Form1.ImgLanMenos4.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Menos4.Show;
      end
      else begin
        Form1.Img50Menos4.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 1) * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_16, iVar2 == 0) } then begin
        Form1.ImgLanMenos4.Hide;
      end;
    end;
    if KMAT + 2 < 1 then begin
      Form1.CDMenos3.Hide;
      Form1.ImgLanMenos3.Hide;
      Form1.Img50Menos3.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos3,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos3.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 2) * 0x240 + 0x204));
      Form1.CDMenos3.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMenos3.Show;
      end
      else begin
        Form1.ImgLanMenos3.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Menos3.Show;
      end
      else begin
        Form1.Img50Menos3.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 2) * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_20, iVar2 == 0) } then begin
        Form1.ImgLanMenos3.Hide;
      end;
    end;
    if KMAT + 3 < 1 then begin
      Form1.CDMenos2.Hide;
      Form1.ImgLanMenos2.Hide;
      Form1.Img50Menos2.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos2,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos2.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 3) * 0x240 + 0x204));
      Form1.CDMenos2.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMenos2.Show;
      end
      else begin
        Form1.ImgLanMenos2.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Menos2.Show;
      end
      else begin
        Form1.Img50Menos2.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 3) * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_24, iVar2 == 0) } then begin
        Form1.ImgLanMenos2.Hide;
      end;
    end;
    if KMAT + 4 < 1 then begin
      Form1.CDMenos1.Hide;
      Form1.ImgLanMenos1.Hide;
      Form1.Img50Menos1.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMenos1,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMenos1.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 4) * 0x240 + 0x204));
      Form1.CDMenos1.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMenos1.Show;
      end
      else begin
        Form1.ImgLanMenos1.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Menos1.Show;
      end
      else begin
        Form1.Img50Menos1.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 4) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
        Form1.ImgLanMenos1.Hide;
      end;
    end;
    // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDSelecionado.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x200));
    local_38 := IntToStr(KMAT + 5);
    Form1.NumCD.Caption := local_38;
    iVar2 := 0;
    if False { C: *(int * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc) != 0 } then begin
      // C: iVar2 = *(int * )( *(int * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc) + -4);
    end;
    // C: fpc_ansistr_copy( *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc), 1,iVar2 + -1,&local_38);
    Form1.NomeDoCD.Caption := local_38;
    // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
    RITMODOCD := local_34;
    // C: fpc_ansistr_copy( *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc), 1,1,local_34);
    LETRADOCD := local_34;
    // ?: SERIAL + (KMAT + 5) * 144 := local_34;
    if local_34 = 'DVD' then begin
      Form1.LabelCDDVD.Caption := 'DVD';
      Form1.LabelCDDVD1.Font.Color := 65535;
      Form1.ImgDVD.Show;
    end
    else begin
      Form1.LabelCDDVD.Caption := 'CD';
      Form1.LabelCDDVD1.Font.Color := 16777215;
      Form1.ImgDVD.Hide;
    end;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelCDDVD,&local_38);
    Form1.LabelCDDVD1.Caption := local_38;
    // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,&local_38);
    Form1.LabelRitmo.Caption := local_38;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelRitmo,&local_38);
    Form1.LabelRitmo1.Caption := local_38;
    // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e9133e,"S");
    if iVar2 = 0 then begin
      Form1.ImgLan.Show;
    end
    else begin
      Form1.ImgLan.Hide;
    end;
    // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
    if local_34 = '50+TOCADOS' then begin
      Form1.Img50.Show;
    end
    else begin
      Form1.Img50.Hide;
    end;
    // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91128,local_34);
    // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
    if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
      Form1.ImgLan.Hide;
    end;
    if SEGURANDOTECLA < 4 then begin
      Form1.ImageSetasPaginacao1.Hide;
      Form1.ImageSetasPaginacao2.Hide;
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica1, (&U_JUKELINUX1_PASTACHAVE8)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2, (&U_JUKELINUX1_PASTACHAVE7)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3, (&U_JUKELINUX1_PASTACHAVE6)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4, (&U_JUKELINUX1_PASTACHAVE5)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5, (&U_JUKELINUX1_PASTACHAVE4)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6, (&U_JUKELINUX1_PASTACHAVE3)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7, (&U_JUKELINUX1_PASTACHAVE2)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8, (&U_JUKELINUX1_PASTACHAVE1)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9, (&U_JUKELINUX1_ULTIMOFECHA)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10, (&U_JUKELINUX1_ERROSERIAL)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11, (&U_JUKELINUX1_ERROSERIALNUM)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12, (&U_JUKELINUX1_LETRASEXE)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica1,local_34);
      NOMEMUSICAORIGINALGRANDE := local_34;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica2,local_34);
      // C: DAT_09301dc4 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica3,local_34);
      // C: DAT_09301dc8 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica4,local_34);
      // C: DAT_09301dcc = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica5,local_34);
      // C: DAT_09301dd0 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica6,local_34);
      // C: DAT_09301dd4 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica7,local_34);
      // C: DAT_09301dd8 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica8,local_34);
      // C: DAT_09301ddc = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica9,local_34);
      // C: DAT_09301de0 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica10,local_34);
      // C: DAT_09301de4 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica11,local_34);
      // C: DAT_09301de8 = local_34[0];
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica12,local_34);
      // C: DAT_09301dec = local_34[0];
      Form1.Musica1.Show;
      Form1.Musica2.Show;
      Form1.Musica3.Show;
      Form1.Musica4.Show;
      Form1.Musica5.Show;
      Form1.Musica6.Show;
      Form1.Musica7.Show;
      Form1.Musica8.Show;
      Form1.Musica9.Show;
      Form1.Musica10.Show;
      Form1.Musica11.Show;
      Form1.Musica12.Show;
      Form1.LabelLM1.Hide;
      Form1.LabelLM2.Hide;
      Form1.LabelLM3.Hide;
      MOSTRANDOLETRANAPAGINACAO := 0;
      iVar2 := 0;
      if False { C: (&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] != 0 } then begin
        // C: iVar2 = *(int * )((&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] + -4);
      end;
      if 0 < iVar2 then begin
        Form1.SetaBaixo.Show;
        MOSTRANDOSETABAIXO := 1;
      end;
      Form1.NomeDoCD.Show;
      Mostra_Musicas(KMAT + 5);
    end
    else begin
      Form1.Musica1.Hide;
      Form1.Musica2.Hide;
      Form1.Musica3.Hide;
      Form1.Musica4.Hide;
      Form1.Musica5.Hide;
      Form1.Musica6.Hide;
      Form1.Musica7.Hide;
      Form1.Musica8.Hide;
      Form1.Musica9.Hide;
      Form1.Musica10.Hide;
      Form1.Musica11.Hide;
      Form1.Musica12.Hide;
      Form1.LabelLM3.Caption := RITMODOCD;
      Form1.LabelLM1.Show;
      Form1.LabelLM2.Show;
      Form1.LabelLM3.Show;
      if LETRASEXE = '3MJ' then begin
        // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc),1,1, &local_38);
        Form1.LabelLM1.Caption := local_38;
      end
      else begin
        // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 5) * 0x240 + 0x1fc),1,2, &local_38);
        Form1.LabelLM1.Caption := local_38;
      end;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelLM1,&local_38);
      Form1.LabelLM2.Caption := local_38;
      Form1.SetaBaixo.Hide;
      MOSTRANDOSETABAIXO := 0;
      Form1.NomeDoCD.Hide;
      if ESTAPAGINANDOPARA = '+' then begin
        if SENTIDODAPAGINACAO = 'Anti-Horário' then begin
          Form1.ImageSetasPaginacao1.Hide;
          Form1.ImageSetasPaginacao2.Show;
        end;
        if SENTIDODAPAGINACAO = 'Horário' then begin
          Form1.ImageSetasPaginacao1.Show;
          Form1.ImageSetasPaginacao2.Hide;
        end;
      end;
      if ESTAPAGINANDOPARA = '-' then begin
        if SENTIDODAPAGINACAO = 'Anti-Horário' then begin
          Form1.ImageSetasPaginacao1.Show;
          Form1.ImageSetasPaginacao2.Hide;
        end;
        if SENTIDODAPAGINACAO = 'Horário' then begin
          Form1.ImageSetasPaginacao1.Hide;
          Form1.ImageSetasPaginacao2.Show;
        end;
      end;
      Form1.ImageSetasPaginacao1.BringToFront;
      Form1.ImageSetasPaginacao2.BringToFront;
      MOSTRANDOLETRANAPAGINACAO := 1;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbc0) + 0xdc)) (Form1.TimerMostraNomeDeMusicas,500);
      Form1.TimerMostraNomeDeMusicas.Enabled := False;
      Form1.TimerMostraNomeDeMusicas.Enabled := True;
    end;
    if TOTALCDS < KMAT + 6 then begin
      Form1.CDMais1.Hide;
      Form1.ImgLanMais1.Hide;
      Form1.Img50Mais1.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais1,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais1.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 6) * 0x240 + 0x204));
      Form1.CDMais1.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMais1.Show;
      end
      else begin
        Form1.ImgLanMais1.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Mais1.Show;
      end
      else begin
        Form1.Img50Mais1.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 6) * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_31, iVar2 == 0) } then begin
        Form1.ImgLanMais1.Hide;
      end;
    end;
    if TOTALCDS < KMAT + 7 then begin
      Form1.CDMais2.Hide;
      Form1.ImgLanMais2.Hide;
      Form1.Img50Mais2.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais2,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais2.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 7) * 0x240 + 0x204));
      Form1.CDMais2.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMais2.Show;
      end
      else begin
        Form1.ImgLanMais2.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Mais2.Show;
      end
      else begin
        Form1.Img50Mais2.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 7) * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_35, iVar2 == 0) } then begin
        Form1.ImgLanMais2.Hide;
      end;
    end;
    if TOTALCDS < KMAT + 8 then begin
      Form1.CDMais3.Hide;
      Form1.ImgLanMais3.Hide;
      Form1.Img50Mais3.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais3,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais3.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 8) * 0x240 + 0x204));
      Form1.CDMais3.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMais3.Show;
      end
      else begin
        Form1.ImgLanMais3.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Mais3.Show;
      end
      else begin
        Form1.Img50Mais3.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 8) * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_39, iVar2 == 0) } then begin
        Form1.ImgLanMais3.Hide;
      end;
    end;
    if TOTALCDS < KMAT + 9 then begin
      Form1.CDMais4.Hide;
      Form1.ImgLanMais4.Hide;
      Form1.Img50Mais4.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais4,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais4.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 9) * 0x240 + 0x204));
      Form1.CDMais4.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMais4.Show;
      end
      else begin
        Form1.ImgLanMais4.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Mais4.Show;
      end
      else begin
        Form1.Img50Mais4.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 9) * 0x240 + 0x8e9133e,"S"), uVar3 = extraout_EDX_43, iVar2 == 0) } then begin
        Form1.ImgLanMais4.Hide;
      end;
    end;
    if TOTALCDS < KMAT + 10 then begin
      Form1.CDMais5.Hide;
      Form1.ImgLanMais5.Hide;
      Form1.Img50Mais5.Hide;
    end
    else begin
      // C: EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN (Form1.CDMais5,uVar3 & 0xffffff00);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDMais5.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMAT + 10) * 0x240 + 0x204));
      Form1.CDMais5.Show;
      // C: iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e9133e,"S");
      if iVar2 = 0 then begin
        Form1.ImgLanMais5.Show;
      end
      else begin
        Form1.ImgLanMais5.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e91128,local_34);
      if local_34 = '50+TOCADOS' then begin
        Form1.Img50Mais5.Show;
      end
      else begin
        Form1.Img50Mais5.Hide;
      end;
      // C: fpc_shortstr_to_ansistr((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e91128,local_34);
      // C: iVar2 = fpc_ansistr_compare_equal(local_34[0],"50+TOCADOS");
      if False { C: (iVar2 == 0) && (iVar2 = FPC_SHORTSTR_COMPARE_EQUAL ((U_JUKELINUX1_KMAT + 10) * 0x240 + 0x8e9133e,"S"), iVar2 == 0) } then begin
        Form1.ImgLanMais5.Hide;
      end;
    end;
  end;
  LAB_080a91e6: ;
  if iVar1 <> 0 then begin
  end;
end;

{ JUKELINUX1_MOSTRA_CD_EXCLUSAO$LONGINT }
procedure Mostra_Cd_Exclusao(P1: LongInt);
var
  local_38, local_48, local_58, local_5c, local_60, local_64, local_68, local_6c, local_70, local_78, local_88, local_90, local_98, local_a8, local_b0, local_b8, local_c0, local_c8, local_d8: AnsiString;
  cVar3: Boolean;
  iVar5, local_8, local_c, local_e0, uVar1: LongInt;
  local_3c, local_40, local_44, local_4c, local_50, local_54, local_74, local_7c, local_80, local_84, local_8c, local_94, local_9c, local_a0, local_a4, local_ac, local_b4, local_bc, local_c4, local_cc, local_d0, local_d4, local_dc: Variant;
begin
  local_8 := P1;
  begin
    Form1.LabelE1.Caption := '';
    Form1.LabelE2.Caption := '';
    Form1.LabelE3.Caption := '';
    Form1.LabelE4.Caption := '';
    Form1.LabelE5.Caption := '';
    Form1.LabelE6.Caption := '';
    // C: local_5c = "Exclusão de CDs e DVDs - [";
    // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&local_60);
    local_58 := local_60;
    local_54 := ' - ';
    local_64 := IntToStr(local_8);
    local_50 := local_64;
    local_4c := ' a ';
    local_68 := IntToStr(local_8 + 5);
    local_48 := local_68;
    local_44 := ' / ';
    local_6c := IntToStr(TOTALCDS);
    local_40 := local_6c;
    local_3c := ']';
    local_38 := local_5c + local_58 + local_54 + local_50 + local_4c + local_48 + local_44 + local_40 + local_3c;
    Form1.LabelETit.Caption := local_38;
    // C: cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x204));
    if not cVar3 then begin
      Form1.CDE1.Hide;
      Form1.ButtonEX1.Hide;
      Form1.ComboBoxMG1.Hide;
    end
    else begin
      Form1.ButtonEX1.Show;
      Form1.ComboBoxMG1.Show;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDE1.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x204));
      Form1.CDE1.Show;
      // ?: SERIAL + local_8 * 144 := local_6c;
      local_5c := local_6c;
      local_58 := ' Tocou: ';
      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING((&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90],&local_68);
      local_54 := local_68;
      local_50 := ''#13'';
      local_4c := 'De: ';
      // ?: BAIRROSTR + local_8 * 144 := local_64;
      local_48 := local_64;
      local_38 := local_5c + local_58 + local_54 + local_50 + local_4c + local_48;
      Form1.LabelE1.Caption := local_38;
      if False { C: STREQ(local_8 * 0x240 + 0x8e9133e,"S") } then begin
        Form1.ImgLanE1.Show;
      end
      else begin
        Form1.ImgLanE1.Hide;
      end;
      // C: iVar5 = ( **(code ** )( **(int ** )(Form1.ComboBoxMG1 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBoxMG1 + 0x36c));
      if -1 < iVar5 + -1 then begin
        local_c := -1;
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_to_ansistr(local_8 * 0x240 + 0x8e91128,&local_6c);
          // C: puVar2 = local_6c;
          // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG1 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG1 + 0x36c),local_c,&local_68 );
          if False { C: STREQ(local_68,puVar2) } then begin
            // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG1 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG1 + 0x36c),local_c, &local_70);
            Form1.ComboBoxMG1.Caption := local_70;
          end;
        until not (local_c < iVar5 + -1);
      end;
    end;
    // C: cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 1) * 0x240 + 0x204));
    if not cVar3 then begin
      Form1.CDE2.Hide;
      Form1.ButtonEX2.Hide;
      Form1.ComboBoxMG2.Hide;
    end
    else begin
      Form1.ButtonEX2.Show;
      Form1.ComboBoxMG2.Show;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDE2.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 1) * 0x240 + 0x204));
      Form1.CDE2.Show;
      // ?: SERIAL + (local_8 + 1) * 144 := local_6c;
      local_88 := local_6c;
      local_84 := ' Tocou: ';
      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ((&U_JUKELINUX1_SELOSSTR)[(local_8 + 1) * 0x90],&local_68);
      local_80 := local_68;
      local_7c := ''#13'';
      local_78 := 'De: ';
      // ?: BAIRROSTR + (local_8 + 1) * 144 := local_8c;
      local_74 := local_8c;
      local_70 := local_88 + local_84 + local_80 + local_7c + local_78 + local_74;
      Form1.LabelE2.Caption := local_70;
      if False { C: STREQ((local_8 + 1) * 0x240 + 0x8e9133e,"S") } then begin
        Form1.ImgLanE2.Show;
      end
      else begin
        Form1.ImgLanE2.Hide;
      end;
      // C: iVar5 = ( **(code ** )( **(int ** )(Form1.ComboBoxMG2 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBoxMG2 + 0x36c));
      if -1 < iVar5 + -1 then begin
        local_c := -1;
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_to_ansistr((local_8 + 1) * 0x240 + 0x8e91128,&local_8c);
          // C: puVar2 = local_8c;
          // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG2 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG2 + 0x36c),local_c,&local_90 );
          if False { C: STREQ(local_90,puVar2) } then begin
            // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG2 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG2 + 0x36c),local_c, &local_70);
            Form1.ComboBoxMG2.Caption := local_70;
          end;
        until not (local_c < iVar5 + -1);
      end;
    end;
    // C: cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 2) * 0x240 + 0x204));
    if not cVar3 then begin
      Form1.CDE3.Hide;
      Form1.ButtonEX3.Hide;
      Form1.ComboBoxMG3.Hide;
    end
    else begin
      Form1.ButtonEX3.Show;
      Form1.ComboBoxMG3.Show;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDE3.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 2) * 0x240 + 0x204));
      Form1.CDE3.Show;
      // ?: SERIAL + (local_8 + 2) * 144 := local_90;
      local_88 := local_90;
      local_84 := ' Tocou: ';
      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ((&U_JUKELINUX1_SELOSSTR)[(local_8 + 2) * 0x90],&local_8c);
      local_80 := local_8c;
      local_7c := ''#13'';
      local_78 := 'De: ';
      // ?: BAIRROSTR + (local_8 + 2) * 144 := local_94;
      local_74 := local_94;
      local_70 := local_88 + local_84 + local_80 + local_7c + local_78 + local_74;
      Form1.LabelE3.Caption := local_70;
      if False { C: STREQ((local_8 + 2) * 0x240 + 0x8e9133e,"S") } then begin
        Form1.ImgLanE3.Show;
      end
      else begin
        Form1.ImgLanE3.Hide;
      end;
      // C: iVar5 = ( **(code ** )( **(int ** )(Form1.ComboBoxMG3 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBoxMG3 + 0x36c));
      if -1 < iVar5 + -1 then begin
        local_c := -1;
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_to_ansistr((local_8 + 2) * 0x240 + 0x8e91128,&local_94);
          // C: puVar2 = local_94;
          // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG3 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG3 + 0x36c),local_c,&local_90 );
          if False { C: STREQ(local_90,puVar2) } then begin
            // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG3 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG3 + 0x36c),local_c, &local_98);
            Form1.ComboBoxMG3.Caption := local_98;
          end;
        until not (local_c < iVar5 + -1);
      end;
    end;
    // C: cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 3) * 0x240 + 0x204));
    if not cVar3 then begin
      Form1.CDE4.Hide;
      Form1.ButtonEX4.Hide;
      Form1.ComboBoxMG4.Hide;
    end
    else begin
      Form1.ButtonEX4.Show;
      Form1.ComboBoxMG4.Show;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDE4.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 3) * 0x240 + 0x204));
      Form1.CDE4.Show;
      // ?: SERIAL + (local_8 + 3) * 144 := local_94;
      local_b0 := local_94;
      local_ac := ' Tocou: ';
      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ((&U_JUKELINUX1_SELOSSTR)[(local_8 + 3) * 0x90],&local_90);
      local_a8 := local_90;
      local_a4 := ''#13'';
      local_a0 := 'De: ';
      // ?: BAIRROSTR + (local_8 + 3) * 144 := local_b4;
      local_9c := local_b4;
      local_98 := local_b0 + local_ac + local_a8 + local_a4 + local_a0 + local_9c;
      Form1.LabelE4.Caption := local_98;
      if False { C: STREQ((local_8 + 3) * 0x240 + 0x8e9133e,"S") } then begin
        Form1.ImgLanE4.Show;
      end
      else begin
        Form1.ImgLanE4.Hide;
      end;
      // C: iVar5 = ( **(code ** )( **(int ** )(Form1.ComboBoxMG4 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBoxMG4 + 0x36c));
      if -1 < iVar5 + -1 then begin
        local_c := -1;
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_to_ansistr((local_8 + 3) * 0x240 + 0x8e91128,&local_b4);
          // C: puVar2 = local_b4;
          // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG4 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG4 + 0x36c),local_c,&local_b8 );
          if False { C: STREQ(local_b8,puVar2) } then begin
            // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG4 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG4 + 0x36c),local_c, &local_98);
            Form1.ComboBoxMG4.Caption := local_98;
          end;
        until not (local_c < iVar5 + -1);
      end;
    end;
    // C: cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 4) * 0x240 + 0x204));
    if not cVar3 then begin
      Form1.CDE5.Hide;
      Form1.ButtonEX5.Hide;
      Form1.ComboBoxMG5.Hide;
    end
    else begin
      Form1.ButtonEX5.Show;
      Form1.ComboBoxMG5.Show;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDE5.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 4) * 0x240 + 0x204));
      Form1.CDE5.Show;
      // ?: SERIAL + (local_8 + 4) * 144 := local_b8;
      local_b0 := local_b8;
      local_ac := ' Tocou: ';
      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ((&U_JUKELINUX1_SELOSSTR)[(local_8 + 4) * 0x90],&local_b4);
      local_a8 := local_b4;
      local_a4 := ''#13'';
      local_a0 := 'De: ';
      // ?: BAIRROSTR + (local_8 + 4) * 144 := local_bc;
      local_9c := local_bc;
      local_98 := local_b0 + local_ac + local_a8 + local_a4 + local_a0 + local_9c;
      Form1.LabelE5.Caption := local_98;
      if False { C: STREQ((local_8 + 4) * 0x240 + 0x8e9133e,"S") } then begin
        Form1.ImgLanE5.Show;
      end
      else begin
        Form1.ImgLanE5.Hide;
      end;
      // C: iVar5 = ( **(code ** )( **(int ** )(Form1.ComboBoxMG5 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBoxMG5 + 0x36c));
      if -1 < iVar5 + -1 then begin
        local_c := -1;
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_to_ansistr((local_8 + 4) * 0x240 + 0x8e91128,&local_bc);
          // C: puVar2 = local_bc;
          // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG5 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG5 + 0x36c),local_c,&local_b8 );
          if False { C: STREQ(local_b8,puVar2) } then begin
            // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG5 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG5 + 0x36c),local_c, &local_c0);
            Form1.ComboBoxMG5.Caption := local_c0;
          end;
        until not (local_c < iVar5 + -1);
      end;
    end;
    // C: cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 5) * 0x240 + 0x204));
    if not cVar3 then begin
      Form1.CDE6.Hide;
      Form1.ButtonEX6.Hide;
      Form1.ComboBoxMG6.Hide;
    end
    else begin
      Form1.ButtonEX6.Show;
      Form1.ComboBoxMG6.Show;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDE6.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_8 + 5) * 0x240 + 0x204));
      Form1.CDE6.Show;
      // ?: SERIAL + (local_8 + 5) * 144 := local_bc;
      local_d8 := local_bc;
      local_d4 := ' Tocou: ';
      // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ((&U_JUKELINUX1_SELOSSTR)[(local_8 + 5) * 0x90],&local_b8);
      local_d0 := local_b8;
      local_cc := ''#13'';
      local_c8 := 'De: ';
      // ?: BAIRROSTR + (local_8 + 5) * 144 := local_dc;
      local_c4 := local_dc;
      local_c0 := local_d8 + local_d4 + local_d0 + local_cc + local_c8 + local_c4;
      Form1.LabelE6.Caption := local_c0;
      if False { C: STREQ((local_8 + 5) * 0x240 + 0x8e9133e,"S") } then begin
        Form1.ImgLanE6.Show;
      end
      else begin
        Form1.ImgLanE6.Hide;
      end;
      // C: iVar5 = ( **(code ** )( **(int ** )(Form1.ComboBoxMG6 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBoxMG6 + 0x36c));
      if -1 < iVar5 + -1 then begin
        local_c := -1;
        repeat
          local_c := local_c + 1;
          // C: fpc_shortstr_to_ansistr((local_8 + 5) * 0x240 + 0x8e91128,&local_dc);
          // C: uVar1 = local_dc;
          // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG6 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG6 + 0x36c),local_c,&local_e0 );
          if local_e0 = uVar1 then begin
            // C: ( **(code ** )( **(int ** )(Form1.ComboBoxMG6 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBoxMG6 + 0x36c),local_c, &local_c0);
            Form1.ComboBoxMG6.Caption := local_c0;
          end;
        until not (local_c < iVar5 + -1);
      end;
    end;
  end;
end;

{ JUKELINUX1_MOSTRA_FILA }
procedure Mostra_Fila;
var
  local_134, local_138, local_13c, local_140, local_144, local_148, local_14c, local_150, local_34: AnsiString;
  cVar1: Boolean;
  local_8, uVar4: LongInt;
begin
  begin
    local_34 := PASTA + 'tocar.txt';
    cVar1 := FileExists(local_34);
    if cVar1 then begin
      SELECIONADAS := 0;
      local_34 := PASTA + 'tocar.txt';
      local_134 := local_34;
      AssignFile(ARQTOCAR, local_134);
      Reset(ARQTOCAR);
      local_8 := 0;
      while True do begin
        cVar1 := Eof(ARQTOCAR);
        if cVar1 then begin Break; end;
        Read(ARQTOCAR, TEXTO);
        Readln(ARQTOCAR);
        cVar1 := FileExists(TEXTO);
        if not cVar1 then begin
          // C: uVar4 = 0;
          if TEXTO <> '' then begin
            // C: uVar4 = *(undefined4 * )(U_JUKELINUX1_TEXTO + -4);
          end;
          local_34 := Copy(TEXTO, 2, uVar4);
          cVar1 := FileExists(local_34);
          if not cVar1 then begin
            local_8 := 1;
          end;
        end;
        SELECIONADAS := SELECIONADAS + 1;
      end;
      CloseFile(ARQTOCAR);
      if local_8 <> 0 then begin
        local_34 := PASTA + 'tocar.txt';
        local_134 := local_34;
        AssignFile(ARQTOCAR, local_134);
        Reset(ARQTOCAR);
        local_34 := PASTA + 'tocarx.txt';
        local_134 := local_34;
        AssignFile(ARQTOCARX, local_134);
        Rewrite(ARQTOCARX);
        while True do begin
          cVar1 := Eof(ARQTOCAR);
          if cVar1 then begin Break; end;
          Read(ARQTOCAR, TEXTO);
          Readln(ARQTOCAR);
          cVar1 := FileExists(TEXTO);
          if cVar1 then begin
            Write(ARQTOCARX, TEXTO);
            Writeln(ARQTOCARX);
          end;
          SELECIONADAS := SELECIONADAS + 1;
        end;
        CloseFile(ARQTOCAR);
        CloseFile(ARQTOCARX);
        local_138 := PASTA + 'tocar.txt';
        // C: puVar3 = local_138;
        if False { C: local_138 == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar3,local_34);
        // C: uVar4 = local_34[0];
        local_140 := PASTA + 'tocarx.txt';
        // C: puVar3 = local_140;
        if False { C: local_140 == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar3,&local_13c);
        // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_13c,uVar4,extraout_ECX & 0xffffff00);
        SELECIONADAS := 0;
        local_13c := PASTA + 'tocar.txt';
        local_134 := local_13c;
        AssignFile(ARQTOCAR, local_134);
        Reset(ARQTOCAR);
        while True do begin
          cVar1 := Eof(ARQTOCAR);
          if cVar1 then begin Break; end;
          Read(ARQTOCAR, TEXTO);
          Readln(ARQTOCAR);
          SELECIONADAS := SELECIONADAS + 1;
        end;
        CloseFile(ARQTOCAR);
        if SEMPENDRIVE = 0 then begin
          local_144 := PASTACHAVE + 'tocar.txt';
          // C: puVar3 = local_144;
          if False { C: local_144 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar3,&local_13c);
          // C: uVar4 = local_13c;
          local_14c := PASTA + 'tocar.txt';
          // C: puVar3 = local_14c;
          if False { C: local_14c == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar3,&local_148);
          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_148,uVar4,extraout_ECX_00 & 0xffffff00);
        end;
      end;
      if SELECIONADAS < 100 then begin
        local_13c := IntToStr(SELECIONADAS);
        local_148 := Strzero(local_13c, 2);
        local_150 := 'Fila ' + local_148;
        Form1.LabelFila.Caption := local_150;
      end
      else begin
        local_13c := IntToStr(SELECIONADAS);
        local_148 := Strzero(local_13c, 3);
        local_150 := 'Fila' + local_148;
        Form1.LabelFila.Caption := local_150;
      end;
    end;
  end;
end;

{ JUKELINUX1_MOSTRA_JPG_LETRA$ANSISTRING$$ANSISTRING }
function Mostra_Jpg_Letra(P1: AnsiString): AnsiString;
var
  local_3c, local_48, local_8, local_c: AnsiString;
  cVar2: Boolean;
  iVar1, iVar4: LongInt;
  local_40, local_44: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    local_c := PASTA + 'letras/naotemjpgletra.jpg';
    iVar1 := TOTALLJ;
    KLJ := 1;
    if 0 < TOTALLJ then begin
      KLJ := 0;
      repeat
        KLJ := KLJ + 1;
        local_3c := UpperCase(local_8);
        // C: iVar4 = fpc_ansistr_compare_equal (local_3c[0],*(undefined4 * )(U_JUKELINUX1_KLJ * 8 + 0x9300bf8));
        if iVar4 = 0 then begin
          local_48 := PASTA;
          local_44 := 'letras/';
          // C: local_40 = *(undefined4 * )(U_JUKELINUX1_KLJ * 8 + 0x9300bfc);
          local_3c := local_48 + local_44 + local_40;
          cVar2 := FileExists(local_3c);
          if cVar2 then begin
            local_48 := PASTA;
            local_44 := 'letras/';
            // C: local_40 = *(undefined4 * )(U_JUKELINUX1_KLJ * 8 + 0x9300bfc);
            local_c := local_48 + local_44 + local_40;
          end;
        end;
      until not (KLJ < iVar1);
    end;
  end;
end;

{ JUKELINUX1_MOSTRA_JPG_RITMO$ANSISTRING$$ANSISTRING }
function Mostra_Jpg_Ritmo(P1: AnsiString): AnsiString;
var
  local_3c, local_48, local_8, local_c: AnsiString;
  cVar2: Boolean;
  iVar1, iVar4: LongInt;
  local_40, local_44: Variant;
begin
  local_c := Result;
  local_8 := P1;
  begin
    local_c := PASTA + 'ritmos/naotemjpgritmo.jpg';
    iVar1 := TOTALRJ;
    KRJ := 1;
    if 0 < TOTALRJ then begin
      KRJ := 0;
      repeat
        KRJ := KRJ + 1;
        // C: iVar4 = fpc_ansistr_compare_equal(local_8,*(undefined4 * )(U_JUKELINUX1_KRJ * 8 + 0x93008c8));
        if iVar4 = 0 then begin
          local_48 := PASTA;
          local_44 := 'ritmos/';
          // C: local_40 = *(undefined4 * )(U_JUKELINUX1_KRJ * 8 + 0x93008cc);
          local_3c := local_48 + local_44 + local_40;
          cVar2 := FileExists(local_3c);
          if cVar2 then begin
            local_48 := PASTA;
            local_44 := 'ritmos/';
            // C: local_40 = *(undefined4 * )(U_JUKELINUX1_KRJ * 8 + 0x93008cc);
            local_c := local_48 + local_44 + local_40;
          end;
        end;
      until not (KRJ < iVar1);
    end;
  end;
end;

{ JUKELINUX1_MOSTRA_LETRAS }
procedure Mostra_Letras;
var
  local_30: AnsiString;
begin
  begin
    // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA],local_30);
    Form1.CDSelecionado.Picture.LoadFromFile(local_30);
    if NUMLETRASELECIONADA + -1 < 1 then begin
      Form1.CDMenos1.Hide;
    end
    else begin
      Form1.CDMenos1.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + -1],local_30);
      Form1.CDMenos1.Picture.LoadFromFile(local_30);
      Form1.CDMenos1.Show;
    end;
    if NUMLETRASELECIONADA + -2 < 1 then begin
      Form1.CDMenos2.Hide;
    end
    else begin
      Form1.CDMenos2.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + -2],local_30);
      Form1.CDMenos2.Picture.LoadFromFile(local_30);
      Form1.CDMenos2.Show;
    end;
    if NUMLETRASELECIONADA + -3 < 1 then begin
      Form1.CDMenos3.Hide;
    end
    else begin
      Form1.CDMenos3.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + -3],local_30);
      Form1.CDMenos3.Picture.LoadFromFile(local_30);
      Form1.CDMenos3.Show;
    end;
    if NUMLETRASELECIONADA + -4 < 1 then begin
      Form1.CDMenos4.Hide;
    end
    else begin
      Form1.CDMenos4.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + -4],local_30);
      Form1.CDMenos4.Picture.LoadFromFile(local_30);
      Form1.CDMenos4.Show;
    end;
    if NUMLETRASELECIONADA + -5 < 1 then begin
      Form1.CDMenos5.Hide;
    end
    else begin
      Form1.CDMenos5.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + -5],local_30);
      Form1.CDMenos5.Picture.LoadFromFile(local_30);
      Form1.CDMenos5.Show;
    end;
    if TOTALMMLETRA < NUMLETRASELECIONADA + 1 then begin
      Form1.CDMais1.Hide;
    end
    else begin
      Form1.CDMais1.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + 1],local_30);
      Form1.CDMais1.Picture.LoadFromFile(local_30);
      Form1.CDMais1.Show;
    end;
    if TOTALMMLETRA < NUMLETRASELECIONADA + 2 then begin
      Form1.CDMais2.Hide;
    end
    else begin
      Form1.CDMais2.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + 2],local_30);
      Form1.CDMais2.Picture.LoadFromFile(local_30);
      Form1.CDMais2.Show;
    end;
    if TOTALMMLETRA < NUMLETRASELECIONADA + 3 then begin
      Form1.CDMais3.Hide;
    end
    else begin
      Form1.CDMais3.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + 3],local_30);
      Form1.CDMais3.Picture.LoadFromFile(local_30);
      Form1.CDMais3.Show;
    end;
    if TOTALMMLETRA < NUMLETRASELECIONADA + 4 then begin
      Form1.CDMais4.Hide;
    end
    else begin
      Form1.CDMais4.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + 4],local_30);
      Form1.CDMais4.Picture.LoadFromFile(local_30);
      Form1.CDMais4.Show;
    end;
    if TOTALMMLETRA < NUMLETRASELECIONADA + 5 then begin
      Form1.CDMais5.Hide;
    end
    else begin
      Form1.CDMais5.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA + 5],local_30);
      Form1.CDMais5.Picture.LoadFromFile(local_30);
      Form1.CDMais5.Show;
    end;
  end;
end;

{ JUKELINUX1_MOSTRA_MUSICAS$LONGINT }
procedure Mostra_Musicas(P1: LongInt);
var
  iVar1, iVar2, local_c: LongInt;
begin
  Desselecionamusica;
  MUSICASELECIONADA := 0;
  MUSICASELECIONADAPOSTELA := 0;
  MUSICASELECIONADATS := 0;
  Selecionamusica;
  Form1.Musica1.Caption := '';
  Form1.Musica2.Caption := '';
  Form1.Musica3.Caption := '';
  Form1.Musica4.Caption := '';
  Form1.Musica5.Caption := '';
  Form1.Musica6.Caption := '';
  Form1.Musica7.Caption := '';
  Form1.Musica8.Caption := '';
  Form1.Musica9.Caption := '';
  Form1.Musica10.Caption := '';
  Form1.Musica11.Caption := '';
  Form1.Musica12.Caption := '';
  // C: iVar2 = (&U_JUKELINUX1_NOMEDOCLIENTE)[P1 * 0x90];
  if 0 < iVar2 then begin
    repeat
      iVar1 := local_c + 1;
      case local_c of
        0: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica1, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        1: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        2: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        3: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        4: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        5: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        6: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        7: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        8: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        9: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        10: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
        11: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12, (&U_JUKELINUX1_PASTACHAVE9)[P1 * 0x90 + iVar1]);
        end;
      end;
      local_c := iVar1;
    until not (iVar1 < iVar2);
  end;
  Mostra_Setas(P1);
end;

{ JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS }
procedure Mostra_Nome_Das_Musicas;
begin
  SEGURANDOTECLA := 0;
  MOSTRANDOLETRANAPAGINACAO := 0;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica1, (&U_JUKELINUX1_PASTACHAVE8)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica1.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2, (&U_JUKELINUX1_PASTACHAVE7)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica2.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3, (&U_JUKELINUX1_PASTACHAVE6)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica3.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4, (&U_JUKELINUX1_PASTACHAVE5)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica4.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5, (&U_JUKELINUX1_PASTACHAVE4)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica5.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6, (&U_JUKELINUX1_PASTACHAVE3)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica6.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7, (&U_JUKELINUX1_PASTACHAVE2)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica7.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8, (&U_JUKELINUX1_PASTACHAVE1)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica8.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9, (&U_JUKELINUX1_ULTIMOFECHA)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica9.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10, (&U_JUKELINUX1_ERROSERIAL)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica10.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11, (&U_JUKELINUX1_ERROSERIALNUM)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica11.Show;
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12, (&U_JUKELINUX1_LETRASEXE)[(U_JUKELINUX1_KMAT + 5) * 0x90]);
  Form1.Musica12.Show;
  Form1.LabelLM1.Hide;
  Form1.LabelLM2.Hide;
  Form1.LabelLM3.Hide;
  Mostra_Setas(KMAT + 5);
end;

{ JUKELINUX1_MOSTRA_RITMOS }
procedure Mostra_Ritmos;
var
  local_30: AnsiString;
begin
  begin
    // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_NUMRITMOSELECIONADO * 4),local_30);
    Form1.CDSelecionado.Picture.LoadFromFile(local_30);
    if NUMRITMOSELECIONADO + -1 < 1 then begin
      Form1.CDMenos1.Hide;
    end
    else begin
      Form1.CDMenos1.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + -1) * 4), local_30);
      Form1.CDMenos1.Picture.LoadFromFile(local_30);
      Form1.CDMenos1.Show;
    end;
    if NUMRITMOSELECIONADO + -2 < 1 then begin
      Form1.CDMenos2.Hide;
    end
    else begin
      Form1.CDMenos2.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + -2) * 4), local_30);
      Form1.CDMenos2.Picture.LoadFromFile(local_30);
      Form1.CDMenos2.Show;
    end;
    if NUMRITMOSELECIONADO + -3 < 1 then begin
      Form1.CDMenos3.Hide;
    end
    else begin
      Form1.CDMenos3.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + -3) * 4), local_30);
      Form1.CDMenos3.Picture.LoadFromFile(local_30);
      Form1.CDMenos3.Show;
    end;
    if NUMRITMOSELECIONADO + -4 < 1 then begin
      Form1.CDMenos4.Hide;
    end
    else begin
      Form1.CDMenos4.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + -4) * 4), local_30);
      Form1.CDMenos4.Picture.LoadFromFile(local_30);
      Form1.CDMenos4.Show;
    end;
    if NUMRITMOSELECIONADO + -5 < 1 then begin
      Form1.CDMenos5.Hide;
    end
    else begin
      Form1.CDMenos5.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + -5) * 4), local_30);
      Form1.CDMenos5.Picture.LoadFromFile(local_30);
      Form1.CDMenos5.Show;
    end;
    if TOTALMMRITMO < NUMRITMOSELECIONADO + 1 then begin
      Form1.CDMais1.Hide;
    end
    else begin
      Form1.CDMais1.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + 1) * 4), local_30);
      Form1.CDMais1.Picture.LoadFromFile(local_30);
      Form1.CDMais1.Show;
    end;
    if TOTALMMRITMO < NUMRITMOSELECIONADO + 2 then begin
      Form1.CDMais2.Hide;
    end
    else begin
      Form1.CDMais2.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + 2) * 4), local_30);
      Form1.CDMais2.Picture.LoadFromFile(local_30);
      Form1.CDMais2.Show;
    end;
    if TOTALMMRITMO < NUMRITMOSELECIONADO + 3 then begin
      Form1.CDMais3.Hide;
    end
    else begin
      Form1.CDMais3.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + 3) * 4), local_30);
      Form1.CDMais3.Picture.LoadFromFile(local_30);
      Form1.CDMais3.Show;
    end;
    if TOTALMMRITMO < NUMRITMOSELECIONADO + 4 then begin
      Form1.CDMais4.Hide;
    end
    else begin
      Form1.CDMais4.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + 4) * 4), local_30);
      Form1.CDMais4.Picture.LoadFromFile(local_30);
      Form1.CDMais4.Show;
    end;
    if TOTALMMRITMO < NUMRITMOSELECIONADO + 5 then begin
      Form1.CDMais5.Hide;
    end
    else begin
      Form1.CDMais5.Stretch := True;
      // C: JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING ( *(undefined4 * )(&DAT_092fffac + (U_JUKELINUX1_NUMRITMOSELECIONADO + 5) * 4), local_30);
      Form1.CDMais5.Picture.LoadFromFile(local_30);
      Form1.CDMais5.Show;
    end;
  end;
end;

{ JUKELINUX1_MOSTRA_SETAS$LONGINT }
procedure Mostra_Setas(P1: LongInt);
var
  local_34, local_38: AnsiString;
  local_8: LongInt;
begin
  local_8 := P1;
  begin
    if False { C: (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] < 0xd } then begin
      Form1.SetaBaixo.Hide;
      MOSTRANDOSETABAIXO := 0;
      Form1.TimerPiscaSeta.Enabled := False;
    end
    else begin
      Form1.SetaBaixo.Show;
      MOSTRANDOSETABAIXO := 1;
      Form1.TimerPiscaSeta.Enabled := True;
    end;
    // ?: SERIAL + local_8 * 144 := local_34;
    if local_34 = 'DVD' then begin
      Form1.LabelCDDVD.Caption := 'DVD';
    end
    else begin
      Form1.LabelCDDVD.Caption := 'CD';
    end;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelCDDVD,&local_38);
    Form1.LabelCDDVD1.Caption := local_38;
  end;
end;

{ JUKELINUX1_MOSTRA_TELA_CARREGANDO_CDS }
procedure Mostra_Tela_Carregando_Cds;
label
  LAB_080ae298, LAB_080ae417, LAB_080ae769;
var
  local_30, local_38, local_48, local_4c, local_50, local_54, local_58, local_5c, local_68, local_78, local_88, local_8c, local_94: AnsiString;
  cVar1: Boolean;
  iVar2: LongInt;
  local_34, local_3c, local_40, local_44, local_60, local_64, local_6c, local_70, local_74, local_7c, local_80, local_84, local_90: Variant;
begin
  // C: iVar2 = fpc_setjmp();
  if iVar2 <> 0 then begin goto LAB_080ae769; end;
  Form1.ImageLendo.Align := alClient;
  if LETRASEXE = 'LLM' then begin
    LAB_080ae298: ;
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo1.Picture);
  end
  else begin
    if LETRASEXE = 'CAR' then begin goto LAB_080ae298; end;
    if LETRASEXE = '3MJ' then begin goto LAB_080ae298; end;
    if LETRASEXE = 'ROB' then begin goto LAB_080ae298; end;
  end;
  if LETRASEXE = 'DIN' then begin
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo1.Picture);
  end;
  if LETRASEXE = 'BRG' then begin
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo2.Picture);
  end;
  if LETRASEXE = 'LIV' then begin
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo3.Picture);
  end;
  if LETRASEXE = 'RRD' then begin
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo4.Picture);
  end;
  if LETRASEXE = 'DPB' then begin
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo5.Picture);
  end;
  if LETRASEXE = 'MAC' then begin
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo6.Picture);
  end;
  if LETRASEXE = 'TRO' then begin
    LAB_080ae417: ;
    // C: EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE (Form1.ImageLendo, Form1.ImageLendo7.Picture);
  end
  else begin
    if LETRASEXE = 'FLA' then begin goto LAB_080ae417; end;
  end;
  Form1.PanelLendo.Left := 0;
  Form1.PanelLendo.Top := 0;
  Form1.PanelLendo.Width := RESOLUCAO;
  Form1.PanelLendo.Height := RESOLUCAOALTURA;
  Form1.PanelLendo.Show;
  Form1.PanelLendo.BringToFront;
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb10) + 0x2fc)) (Form1.PanelLendo);
  Form1.PanelVersao.Left := 0;
  Form1.PanelVersao.Top := 0;
  Form1.PanelVersao.Width := RESOLUCAO;
  local_4c := ' ';
  local_48 := VERSAO;
  local_44 := '     Data do Computador: ';
  local_50 := DateToStr(Date);
  local_40 := local_50;
  local_3c := '  ';
  // C: puVar4 = &local_54;
  local_58 := TimeToStr(Time);
  // C: fpc_ansistr_copy(local_58,1,5,puVar4);
  local_38 := local_54;
  local_34 := 'hs';
  local_30 := local_4c + local_48 + local_44 + local_40 + local_3c + local_38 + local_34;
  Form1.PanelVersao.Caption := local_30;
  local_58 := PASTA + 'naomostra';
  cVar1 := FileExists(local_58);
  if (not cVar1) and (-1 < BLOQUEARQUANDOTOCAR) then begin
    local_88 := ' ';
    local_84 := VERSAO;
    // C: local_80 = " -  [ ";
    local_58 := IntToStr(QUANTIDADESDEMUSICASTOCADAS);
    local_7c := local_58;
    local_78 := '/';
    local_54 := IntToStr(BLOQUEARQUANDOTOCAR);
    local_74 := local_54;
    local_70 := ' ]     Data do Computador: ';
    local_8c := DateToStr(Date);
    local_6c := local_8c;
    local_68 := '  ';
    // C: puVar4 = &local_90;
    local_94 := TimeToStr(Time);
    // C: fpc_ansistr_copy(local_94,1,5,puVar4);
    local_64 := local_90;
    local_60 := 'hs';
    local_5c := local_88 + local_84 + local_80 + local_7c + local_78 + local_74 + local_70 + local_6c + local_68 + local_64 + local_60;
    Form1.PanelVersao.Caption := local_5c;
  end;
  LAB_080ae769: ;
  if iVar2 <> 0 then begin
  end;
end;

{ JUKELINUX1_MOSTRA_TELA_DE_SORTEIO }
procedure Mostra_Tela_De_Sorteio;
var
  local_164, local_168, local_16c, local_170, local_174, local_18, local_64: AnsiString;
  cVar2: Boolean;
  iVar4, local_14, local_28, local_8, local_c, uVar1: LongInt;
begin
  begin
    if TOCANDOPALHINHA <> 0 then begin
      Form1.Play.Hide;
    end;
    if TOCANDOMUSICADVD <> 0 then begin
      Form1.Play.Hide;
    end;
    if TOCANDOVIDEOTV <> 0 then begin
      Form1.playtv.Hide;
    end;
    Form1.TimerPiscaCreditos.Enabled := False;
    Form1.LabelCreditos.Show;
    // C: ( **(code ** )( *(int * )Form1.LabelCreditos + 0x2fc))(Form1.LabelCreditos);
    Form1.LabelCreditos.Font.Color := 16777215;
    local_18 := '1';
    if SORTEIODECREDITOS = '2 Reais' then begin
      if RESOLUCAO = 1024 then begin
        local_64 := PASTA + 'sorteio1024_2reais.jpg';
        cVar2 := FileExists(local_64);
        if cVar2 then begin
          local_64 := PASTA + 'sorteio1024_2reais.jpg';
          Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          local_18 := 'ok';
        end;
      end;
      if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
        local_64 := PASTA + 'sorteio1366_2reais.jpg';
        cVar2 := FileExists(local_64);
        if cVar2 then begin
          local_64 := PASTA + 'sorteio1366_2reais.jpg';
          Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          local_18 := 'ok';
        end;
      end;
    end;
    if SORTEIODECREDITOS = '5 Reais' then begin
      if RESOLUCAO = 1024 then begin
        local_64 := PASTA + 'sorteio1024_5reais.jpg';
        cVar2 := FileExists(local_64);
        if cVar2 then begin
          local_64 := PASTA + 'sorteio1024_5reais.jpg';
          Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          local_18 := 'ok';
        end;
      end;
      if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
        local_64 := PASTA + 'sorteio1366_5reais.jpg';
        cVar2 := FileExists(local_64);
        if cVar2 then begin
          local_64 := PASTA + 'sorteio1366_5reais.jpg';
          Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          local_18 := 'ok';
        end;
      end;
    end;
    if SORTEIODECREDITOS = '10 Reais' then begin
      if RESOLUCAO = 1024 then begin
        local_64 := PASTA + 'sorteio1024_10reais.jpg';
        cVar2 := FileExists(local_64);
        if cVar2 then begin
          local_64 := PASTA + 'sorteio1024_10reais.jpg';
          Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          local_18 := 'ok';
        end;
      end;
      if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
        local_64 := PASTA + 'sorteio1366_10reais.jpg';
        cVar2 := FileExists(local_64);
        if cVar2 then begin
          local_64 := PASTA + 'sorteio1366_10reais.jpg';
          Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          local_18 := 'ok';
        end;
      end;
    end;
    if RESOLUCAO = 1024 then begin
      local_64 := PASTA + 'sorteio1024_cds.jpg';
      cVar2 := FileExists(local_64);
      if cVar2 then begin
        local_18 := 'ok';
      end;
    end;
    if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
      local_64 := PASTA + 'sorteio1366_cds.jpg';
      cVar2 := FileExists(local_64);
      if cVar2 then begin
        local_18 := 'ok';
      end;
    end;
    if local_18 = 'ok' then begin
      Form1.ImageSorteio.Align := alClient;
      Form1.PanelSorteio.BringToFront;
      if RESOLUCAO = 1366 then begin
        Form1.PanelSorteio.Top := 185;
        Form1.PanelSorteio.Left := 1;
        Form1.PanelSorteio.Width := 1366;
        Form1.PanelSorteio.Height := 393;
      end;
      if RESOLUCAO = 1440 then begin
        Form1.PanelSorteio.Top := 260;
        Form1.PanelSorteio.Left := 28;
        Form1.PanelSorteio.Width := 1366;
        Form1.PanelSorteio.Height := 393;
      end;
      if RESOLUCAO = 1024 then begin
        Form1.PanelSorteio.Top := 185;
        Form1.PanelSorteio.Left := 1;
        Form1.PanelSorteio.Width := 1024;
        Form1.PanelSorteio.Height := 385;
      end;
      Form1.CDSorteio1.Hide;
      Form1.CDSorteio2.Hide;
      Form1.CDSorteio3.Hide;
      Form1.CDSorteio4.Hide;
      Form1.CapaSorteio1.Hide;
      Form1.CapaSorteio2.Hide;
      Form1.CapaSorteio3.Hide;
      Form1.CapaSorteio4.Hide;
      Form1.PanelSorteio.Show;
      // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      FORM1.Refresh;
      Sleep(1200);
      if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
        local_64 := PASTA + 'sorteio1366_cds.jpg';
        Form1.ImageSorteio.Picture.LoadFromFile(local_64);
      end;
      if RESOLUCAO = 1024 then begin
        local_64 := PASTA + 'sorteio1024_cds.jpg';
        Form1.ImageSorteio.Picture.LoadFromFile(local_64);
      end;
      Form1.ImageSorteio.SendToBack;
      if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
        Form1.CapaSorteio1.Left := 72;
        Form1.CapaSorteio1.Top := 180;
        Form1.CapaSorteio2.Left := 412;
        Form1.CapaSorteio2.Top := 180;
        Form1.CapaSorteio3.Left := 762;
        Form1.CapaSorteio3.Top := 180;
        Form1.CapaSorteio4.Left := 1102;
        Form1.CapaSorteio4.Top := 180;
      end;
      if RESOLUCAO = 1024 then begin
        Form1.CapaSorteio1.Left := 32;
        Form1.CapaSorteio1.Top := 180;
        Form1.CapaSorteio2.Left := 292;
        Form1.CapaSorteio2.Top := 180;
        Form1.CapaSorteio3.Left := 552;
        Form1.CapaSorteio3.Top := 180;
        Form1.CapaSorteio4.Left := 802;
        Form1.CapaSorteio4.Top := 180;
      end;
      local_64 := PASTA + 'interrogacao.jpg';
      cVar2 := FileExists(local_64);
      if cVar2 then begin
        local_64 := PASTA + 'interrogacao.jpg';
        Form1.CDSorteio1.Picture.LoadFromFile(local_64);
        local_64 := PASTA + 'interrogacao.jpg';
        Form1.CDSorteio2.Picture.LoadFromFile(local_64);
        local_64 := PASTA + 'interrogacao.jpg';
        Form1.CDSorteio3.Picture.LoadFromFile(local_64);
        local_64 := PASTA + 'interrogacao.jpg';
        Form1.CDSorteio4.Picture.LoadFromFile(local_64);
      end;
      Form1.CDSorteio1.Left := Form1.CapaSorteio1.Left + 23;
      Form1.CDSorteio1.Top := Form1.CapaSorteio1.Top + 8;
      Form1.CDSorteio2.Left := Form1.CapaSorteio2.Left + 23;
      Form1.CDSorteio2.Top := Form1.CapaSorteio2.Top + 8;
      Form1.CDSorteio3.Left := Form1.CapaSorteio3.Left + 23;
      Form1.CDSorteio3.Top := Form1.CapaSorteio3.Top + 8;
      Form1.CDSorteio4.Left := Form1.CapaSorteio4.Left + 23;
      Form1.CDSorteio4.Top := Form1.CapaSorteio4.Top + 8;
      Form1.CDSorteio1.Show;
      Form1.CDSorteio2.Show;
      Form1.CDSorteio3.Show;
      Form1.CDSorteio4.Show;
      Form1.CapaSorteio1.Show;
      Form1.CapaSorteio2.Show;
      Form1.CapaSorteio3.Show;
      Form1.CapaSorteio4.Show;
      // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      FORM1.Refresh;
      Sleep(400);
      Randomize;
      local_c := Random(TOTALCDS + -10);
      if local_c = 0 then begin
        local_c := 1;
      end;
      // C: local_28[0] = SYSTEM_RANDOM_LONGINT__LONGINT(3);
      // C: local_28[1] = SYSTEM_RANDOM_LONGINT__LONGINT(3);
      // C: local_28[2] = SYSTEM_RANDOM_LONGINT__LONGINT(3);
      // C: local_28[3] = SYSTEM_RANDOM_LONGINT__LONGINT(3);
      if PREMIOU = 0 then begin
        PREMIOU := 1;
        // C: local_28[2] = local_28[0];
        if SORTEIODECREDITOS = '5 Reais' then begin
          // C: local_28[1] = local_28[0];
        end;
      end
      else begin
        PREMIOU := 0;
      end;
      if SORTEIODECREDITOS = '10 Reais' then begin
        // C: local_28[1] = local_28[0];
        // C: local_28[2] = local_28[0];
        // C: local_28[3] = local_28[0];
      end;
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDSorteio1.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_c + local_28[0]) * 0x240 + 0x204));
      Form1.CDSorteio1.Show;
      // C: ( **(code ** )( *(int * )Form1.CDSorteio1 + 0x2fc))(Form1.CDSorteio1);
      Sleep(100);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDSorteio2.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_c + local_28[1]) * 0x240 + 0x204));
      Form1.CDSorteio2.Show;
      // C: ( **(code ** )( *(int * )Form1.CDSorteio2 + 0x2fc))(Form1.CDSorteio2);
      Sleep(100);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDSorteio3.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_c + local_28[2]) * 0x240 + 0x204));
      Form1.CDSorteio3.Show;
      // C: ( **(code ** )( *(int * )Form1.CDSorteio3 + 0x2fc))(Form1.CDSorteio3);
      Sleep(100);
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.CDSorteio4.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (local_c + local_28[3]) * 0x240 + 0x204));
      Form1.CDSorteio4.Show;
      // C: ( **(code ** )( *(int * )Form1.CDSorteio4 + 0x2fc))(Form1.CDSorteio4);
      // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      FORM1.Refresh;
      Sleep(500);
      repeat
        local_8 := local_8 + 1;
        // C: aiStack_3c[local_8] = 0;
      until not (local_8 < 4);
      repeat
        iVar4 := local_8 + 1;
        if False { C: aiStack_3c[local_8 + 5] == 0 } then begin
          // C: aiStack_3c[1] = aiStack_3c[1] + 1;
        end;
        if False { C: aiStack_3c[local_8 + 5] == 1 } then begin
          // C: aiStack_3c[2] = aiStack_3c[2] + 1;
        end;
        if False { C: aiStack_3c[local_8 + 5] == 2 } then begin
          // C: aiStack_3c[3] = aiStack_3c[3] + 1;
        end;
        if False { C: aiStack_3c[local_8 + 5] == 3 } then begin
          // C: aiStack_3c[4] = aiStack_3c[4] + 1;
        end;
        local_8 := iVar4;
      until not (iVar4 < 4);
      repeat
        local_8 := local_8 + 1;
        if False { C: aiStack_3c[local_8] == 1 } then begin
          // C: aiStack_3c[local_8] = 0;
        end;
      until not (local_8 < 4);
      repeat
        local_8 := local_8 + 1;
      until not (local_8 < 4);
      repeat
        local_8 := local_8 + 1;
        if False { C: aiStack_3c[local_8] == 3 } then begin
          local_14 := 1;
        end;
      until not (local_8 < 4);
      repeat
        local_8 := local_8 + 1;
        if False { C: aiStack_3c[local_8] == 4 } then begin
          local_14 := 2;
        end;
      until not (local_8 < 4);
      if local_14 = 1 then begin
        if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
          local_64 := PASTA + 'sorteio1366_ganhou1credito.jpg';
          cVar2 := FileExists(local_64);
          if cVar2 then begin
            local_64 := PASTA + 'sorteio1366_ganhou1credito.jpg';
            Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          end;
        end;
        if RESOLUCAO = 1024 then begin
          local_64 := PASTA + 'sorteio1024_ganhou1credito.jpg';
          cVar2 := FileExists(local_64);
          if cVar2 then begin
            local_64 := PASTA + 'sorteio1024_ganhou1credito.jpg';
            Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          end;
        end;
      end;
      if local_14 = 2 then begin
        if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
          local_64 := PASTA + 'sorteio1366_ganhou2creditos.jpg';
          cVar2 := FileExists(local_64);
          if cVar2 then begin
            local_64 := PASTA + 'sorteio1366_ganhou2creditos.jpg';
            Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          end;
        end;
        if RESOLUCAO = 1024 then begin
          local_64 := PASTA + 'sorteio1024_ganhou2creditos.jpg';
          cVar2 := FileExists(local_64);
          if cVar2 then begin
            local_64 := PASTA + 'sorteio1024_ganhou2creditos.jpg';
            Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          end;
        end;
      end;
      if local_14 = 0 then begin
        local_64 := PASTA + 'sorteio1366_quemsabenaproxima.jpg';
        cVar2 := FileExists(local_64);
        if cVar2 then begin
          local_64 := PASTA + 'sorteio1366_quemsabenaproxima.jpg';
          Form1.ImageSorteio.Picture.LoadFromFile(local_64);
        end;
        if (RESOLUCAO = 1366) or (RESOLUCAO = 1440) then begin
          local_64 := PASTA + 'sorteio1366_quemsabenaproxima.jpg';
          cVar2 := FileExists(local_64);
          if cVar2 then begin
            local_64 := PASTA + 'sorteio1366_quemsabenaproxima.jpg';
            Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          end;
        end;
        if RESOLUCAO = 1024 then begin
          local_64 := PASTA + 'sorteio1024_quemsabenaproxima.jpg';
          cVar2 := FileExists(local_64);
          if cVar2 then begin
            local_64 := PASTA + 'sorteio1024_quemsabenaproxima.jpg';
            Form1.ImageSorteio.Picture.LoadFromFile(local_64);
          end;
        end;
      end;
      // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      FORM1.Refresh;
      if 0 < local_14 then begin
        CREDITOS := CREDITOS + local_14;
        NOMEARQ := PASTA + 'creditos.txt';
        local_164 := NOMEARQ;
        AssignFile(ARQTEXTO, local_164);
        Rewrite(ARQTEXTO);
        local_168 := IntToStr(CREDITOS);
        local_64 := Cripta(local_168);
        Write(ARQTEXTO, local_64);
        Writeln(ARQTEXTO);
        local_168 := Cripta(JC_SERIALPENDRIVE);
        Write(ARQTEXTO, local_168);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        if SEMPENDRIVE = 0 then begin
          local_64 := PASTACHAVE + 'creditos.txt';
          // C: puVar5 = local_64[0];
          if False { C: local_64[0] == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar5,&local_168);
          // C: uVar1 = local_168;
          local_170 := PASTA + 'creditos.txt';
          // C: puVar5 = local_170;
          if False { C: local_170 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar5,&local_16c);
          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_16c,uVar1,extraout_ECX & 0xffffff00);
        end;
        local_174 := IntToStr(CREDITOS);
        Form1.LabelCreditos.Caption := local_174;
        Form1.LabelCreditos.Font.Color := 65280;
        Form1.TimerPiscaCreditos.Enabled := False;
        Form1.TimerPiscaCreditos.Enabled := True;
        MOSTRANDOCREDITO := 1;
      end;
      Sleep(2000);
      Form1.PanelSorteio.Hide;
      if TOCANDOPALHINHA <> 0 then begin
        Form1.Play.Show;
      end;
      if TOCANDOMUSICADVD <> 0 then begin
        Form1.Play.Show;
      end;
      if TOCANDOVIDEOTV <> 0 then begin
        Form1.playtv.Show;
      end;
      if 0 < PULSOSPARASORTEIO then begin
        Form1.TimerSorteio.Enabled := True;
      end;
    end
    else begin
      if local_18 = '1' then begin
        local_16c := 'Nao Encontrado a Imagem de Fundo para o Sorteio de ' + SORTEIODECREDITOS;
        Gravalog(local_16c);
      end;
      if local_18 = '2' then begin
        // C: JUKELINUX1_GRAVALOG_ANSISTRING("Nao Encontrado a Imagem de Fundo [sorteio1366_cds.jpg] para o Sorteio");
      end;
    end;
  end;
end;

{ JUKELINUX1_PRESSTECLA }
procedure Presstecla;
begin
  TEMPOEMSEGUNDOS := 0;
  TEMPOEMSEGUNDOSPAGINARSOZINHO := 0;
  if LIMPAMSG <> 0 then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xba0) + 0xdc)) (Form1.TimerEscondeMsg,1);
  end;
  if LIMPAMSG = 0 then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xba0) + 0xdc)) (Form1.TimerEscondeMsg, (int)(U_JUKELINUX1_TEMPOEM1 + (U_JUKELINUX1_TEMPOEM1 >> 0x1f & 1U)) >> 1);
  end;
  if TOCANDOMUSICA <> 0 then begin
    if TOCANDOTIPO = 'DVD' then begin
      if EXIBIRVIDEOSNO = 'MONITOR' then begin
        if Form1.Play.Left = 0 then begin
          Form1.Play.Left := POSL;
          Form1.Play.Top := POST;
          Form1.Play.Width := POSW;
          Form1.Play.Height := POSH;
          Form1.Play.AutoSize := False;
          Form1.Play.Show;
          Form1.TimerRodaDisplay.Enabled := True;
          Form1.TimerNomeMusicaGrande.Enabled := True;
          Form1.TimerPiscaSeta.Enabled := True;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc)) (Form1.TimerTelaCheia,5000);
          Form1.TimerTelaCheia.Enabled := False;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc)) (Form1.TimerTelaCheia,5000);
          Form1.TimerTelaCheia.Enabled := True;
          ESTAEMTELACHEIA := 0;
        end
        else begin
          Form1.TimerTelaCheia.Enabled := False;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc)) (Form1.TimerTelaCheia,5000);
          Form1.TimerTelaCheia.Enabled := True;
        end;
      end;
    end;
  end;
end;

{ JUKELINUX1_ROTINA_CANCELAR }
procedure Rotina_Cancelar;
var
  local_30: AnsiString;
  cVar4: Boolean;
  iVar1, iVar2, iVar3: LongInt;
begin
  begin
    MUDOUDECDOUMUSICA := 1;
    // C: cVar4 = MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAYING__BOOLEAN (Form1.Play);
    if cVar4 then begin
      Presstecla;
      if TOCANDOMUSICAGRATIS = 0 then begin
        if RESOLUCAO = 1366 then begin
          Mensagemjpg('mensagem1366-musicacanceladopelocliente.jpg', 0, '');
        end;
        if RESOLUCAO = 1440 then begin
          Mensagemjpg('mensagem1366-musicacanceladopelocliente.jpg', 0, '');
        end;
        if RESOLUCAO = 1024 then begin
          Mensagemjpg('mensagem1024-musicacanceladopelocliente.jpg', 0, '');
        end;
        Gravalog('Musica Cancelada pelo Cliente');
      end
      else begin
        if RESOLUCAO = 1366 then begin
          Mensagemjpg('mensagem1366-fimdamusicagratis.jpg', 0, '');
        end;
        if RESOLUCAO = 1440 then begin
          Mensagemjpg('mensagem1366-fimdamusicagratis.jpg', 0, '');
        end;
        if RESOLUCAO = 1024 then begin
          Mensagemjpg('mensagem1024-fimdamusicagratis.jpg', 0, '');
        end;
        Gravalog('Fim da Musica Gratis ou Inicio De Uma Musica Paga');
      end;
      Form1.TimerTocando.Enabled := False;
      // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.Play);
      Form1.Play.Hide;
      TOCANDOMUSICA := 0;
      TOCANDOMUSICADVD := 0;
      TOCANDOMUSICAGRATIS := 0;
      Form1.PanelCDTocando.Hide;
      Ativa_Propaganda;
      local_30 := PASTA + 'tocando.txt';
      DeleteFile(local_30);
      iVar3 := TOTALFRASE;
      TOCANDOTIPO := '';
      KFRASE := 1;
      if 0 < TOTALFRASE then begin
        KFRASE := 0;
        repeat
          KFRASE := KFRASE + 1;
          iVar1 := KFRASE;
          iVar2 := KFRASE;
          // C: *(undefined4 * )(U_JUKELINUX1_ARQTOCARX + iVar2 * 4 + 0x24c) = *(undefined4 * )(iVar1 * 4 + 0x9301ccc);
        until not (KFRASE < iVar3);
      end;
      POSFRASE := 0;
      Form1.TimerTocar.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_ROTINA_CREDITOSVIP }
procedure Rotina_Creditosvip;
var
  local_130, local_134, local_138, local_13c, local_140, local_30: AnsiString;
  uVar1: LongInt;
begin
  begin
    if CREDITOSVIP < 1 then begin
      if RESOLUCAO = 1366 then begin
        Mensagemjpg('mensagem1366-acabaramseuscreditosgratisvip.jpg', 0, '');
      end;
      if RESOLUCAO = 1440 then begin
        Mensagemjpg('mensagem1366-acabaramseuscreditosgratisvip.jpg', 0, '');
      end;
      if RESOLUCAO = 1024 then begin
        Mensagemjpg('mensagem1024-acabaramseuscreditosgratisvip.jpg', 0, '');
      end;
    end
    else begin
      Presstecla;
      CREDITOSVIP := CREDITOSVIP + -1;
      if RESOLUCAO = 1366 then begin
        local_30 := IntToStr(CREDITOSVIP);
        Mensagemjpg('mensagem1366-vocetemcreditosgratisvip.jpg', 2, local_30);
      end;
      if RESOLUCAO = 1440 then begin
        local_30 := IntToStr(CREDITOSVIP);
        Mensagemjpg('mensagem1366-vocetemcreditosgratisvip.jpg', 2, local_30);
      end;
      if RESOLUCAO = 1024 then begin
        local_30 := IntToStr(CREDITOSVIP);
        Mensagemjpg('mensagem1024-vocetemcreditosgratisvip.jpg', 2, local_30);
      end;
      CREDITOS := CREDITOS + 1;
      NOMEARQ := PASTA + 'creditos.txt';
      local_130 := NOMEARQ;
      AssignFile(ARQTEXTO, local_130);
      Rewrite(ARQTEXTO);
      local_134 := IntToStr(CREDITOS);
      local_30 := Cripta(local_134);
      Write(ARQTEXTO, local_30);
      Writeln(ARQTEXTO);
      local_134 := Cripta(JC_SERIALPENDRIVE);
      Write(ARQTEXTO, local_134);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      if SEMPENDRIVE = 0 then begin
        local_30 := PASTACHAVE + 'creditos.txt';
        // C: puVar3 = local_30[0];
        if False { C: local_30[0] == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar3,&local_134);
        // C: uVar1 = local_134;
        local_13c := PASTA + 'creditos.txt';
        // C: puVar3 = local_13c;
        if False { C: local_13c == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar3,&local_138);
        // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_138,uVar1,extraout_ECX & 0xffffff00);
      end;
      NOMEARQ := PASTA + 'creditosvip.txt';
      local_130 := NOMEARQ;
      AssignFile(ARQTEXTO, local_130);
      Rewrite(ARQTEXTO);
      local_134 := IntToStr(CREDITOSVIP);
      local_138 := Cripta(local_134);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      local_138 := Cripta(JC_SERIALPENDRIVE);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      local_140 := IntToStr(CREDITOS);
      Form1.LabelCreditos.Caption := local_140;
    end;
  end;
end;

{ JUKELINUX1_ROTINA_CREDITOS$ANSISTRING }
procedure Rotina_Creditos(P1: AnsiString);
var
  local_130, local_134, local_138, local_13c, local_140, local_144, local_148, local_158, local_244, local_248, local_24c, local_8: AnsiString;
  iVar3, uVar1: LongInt;
  local_14c, local_150, local_154: Variant;
begin
  local_8 := P1;
  // C: fpc_ansistr_incr_ref();
  begin
    if SENHAOK = 0 then begin
      if local_8 = 'Cartao' then begin
        if REAISXMUSICAS = '1x1' then begin
          CREDITOS := CREDITOS + 1;
        end;
        if REAISXMUSICAS = '1x2' then begin
          CREDITOS := CREDITOS + 1;
        end;
        if REAISXMUSICAS = '1x1, 2x3, 5x10' then begin
          CREDITOS := CREDITOS + 1;
        end;
        // C: iVar3 = fpc_ansistr_compare_equal(U_JUKELINUX1_REAISXMUSICAS,"2x1");
        if False { C: (iVar3 == 0) && (U_JUKELINUX1_CREDITOSTEMP = U_JUKELINUX1_CREDITOSTEMP + 1, U_JUKELINUX1_CREDITOSTEMP == 2) } then begin
          CREDITOS := CREDITOS + 1;
          CREDITOSTEMP := 0;
        end;
      end;
      if local_8 = 'Normal' then begin
        if REAISXMUSICAS = '1x1' then begin
          CREDITOS := CREDITOS + 1;
        end;
        if REAISXMUSICAS = '1x2' then begin
          CREDITOS := CREDITOS + 2;
        end;
        if REAISXMUSICAS = '1x1, 2x3, 5x10' then begin
          CREDITOSCEDULAS := CREDITOSCEDULAS + 1;
          CREDITOS := CREDITOS + 1;
          Form1.TimerCedulas.Enabled := False;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc)) (Form1.TimerTelaCheia,2000);
          Form1.TimerCedulas.Enabled := True;
        end;
        // C: iVar3 = fpc_ansistr_compare_equal(U_JUKELINUX1_REAISXMUSICAS,"2x1");
        if False { C: (iVar3 == 0) && (U_JUKELINUX1_CREDITOSTEMP = U_JUKELINUX1_CREDITOSTEMP + 1, U_JUKELINUX1_CREDITOSTEMP == 2) } then begin
          CREDITOS := CREDITOS + 1;
          CREDITOSTEMP := 0;
        end;
      end;
      NOMEARQ := PASTA + 'creditos.txt';
      local_130 := NOMEARQ;
      AssignFile(ARQTEXTO, local_130);
      Rewrite(ARQTEXTO);
      local_138 := IntToStr(CREDITOS);
      local_134 := Cripta(local_138);
      Write(ARQTEXTO, local_134);
      Writeln(ARQTEXTO);
      local_138 := Cripta(JC_SERIALPENDRIVE);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      if SEMPENDRIVE = 0 then begin
        local_134 := PASTACHAVE + 'creditos.txt';
        // C: puVar4 = local_134;
        if False { C: local_134 == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar4,&local_138);
        // C: uVar1 = local_138;
        local_140 := PASTA + 'creditos.txt';
        // C: puVar4 = local_140;
        if False { C: local_140 == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar4,&local_13c);
        // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_13c,uVar1,extraout_ECX & 0xffffff00);
      end;
      local_144 := IntToStr(CREDITOS);
      Form1.LabelCreditos.Caption := local_144;
      Form1.LabelCreditos.Font.Color := 65280;
      Form1.TimerPiscaCreditos.Enabled := False;
      Form1.TimerPiscaCreditos.Enabled := True;
      MOSTRANDOCREDITO := 1;
      if local_8 = 'Normal' then begin
        RELOGIOTOTAL := RELOGIOTOTAL + 1;
        local_13c := PASTA + 'relogiototal.txt';
        local_244 := local_13c;
        AssignFile(ARQTEXTO, local_244);
        Rewrite(ARQTEXTO);
        local_13c := IntToStr(RELOGIOTOTAL);
        RELOGIOTOTALSTR := local_13c;
        local_13c := Cripta(RELOGIOTOTALSTR);
        RELOGIOTOTALSTR := local_13c;
        // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        RELOGIOPARCIAL := RELOGIOPARCIAL + 1;
        local_13c := PASTA + 'relogioparcial.txt';
        local_244 := local_13c;
        AssignFile(ARQTEXTO, local_244);
        Rewrite(ARQTEXTO);
        local_13c := IntToStr(RELOGIOPARCIAL);
        RELOGIOPARCIALSTR := local_13c;
        local_13c := Cripta(RELOGIOPARCIALSTR);
        RELOGIOPARCIALSTR := local_13c;
        // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        // C: local_158 = "+1 Credito - [Total=";
        local_248 := IntToStr(RELOGIOTOTAL);
        local_154 := local_248;
        local_150 := ' Parcial=';
        local_24c := IntToStr(RELOGIOPARCIAL);
        local_14c := local_24c;
        local_148 := ']';
        local_13c := local_158 + local_154 + local_150 + local_14c + local_148;
        Gravalog(local_13c);
      end;
      if local_8 = 'Normal' then begin
        PALHINHASPORREAL := PALHINHASPORREAL + PALHINHASPORREALCONFIG;
        PULSOSPARACARTAO := PULSOSPARACARTAO + 1;
        PULSOSPARASORTEIO := PULSOSPARASORTEIO + 1;
        // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb68) + 0xd8)) (Form1.TimerSorteio, U_JUKELINUX1_PALHINHASPORREALCONFIG & 0xffffff00);
        Form1.TimerSorteio.Enabled := True;
      end;
      Form1.TimerGravaPenDrive.Enabled := False;
      Form1.TimerGravaPenDrive.Enabled := True;
      JAGRAVOUNOPENDRIVE := 1;
    end
    else begin
      CREDITOSTESTE := CREDITOSTESTE + 1;
      local_24c := IntToStr(CREDITOSTESTE);
      local_144 := 'Créditos de Teste de Noteiro e/ou Moedeiro: ' + local_24c;
      Form1.LabelPress3.Caption := local_144;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x870) + 0x2fc)) (Form1.LabelPress3);
    end;
  end;
end;

{ JUKELINUX1_ROTINA_MENU }
procedure Rotina_Menu;
var
  local_15c, local_30, local_34, local_38, local_40, local_48, local_50, local_54, local_58, local_5c: AnsiString;
  cVar1: Boolean;
  local_3c, local_44, local_4c: Variant;
begin
  begin
    if ESTANOMENU = 0 then begin
      Presstecla;
      if ESTADIGITANDOSENHA = 0 then begin
        ZERA50 := 0;
        ESTANOMENU := 1;
        Desativa_Propaganda;
        ALTEROUPRO := 0;
        RELECDS := 0;
        PRESS2XPARAZERAR := 0;
        if RESOLUCAO = 1366 then begin
          local_30 := PASTA + 'menu1366.jpg';
          cVar1 := FileExists(local_30);
          if cVar1 then begin
            local_30 := PASTA + 'menu1366.jpg';
            Form1.ImageFundoMenu.Picture.LoadFromFile(local_30);
          end;
        end;
        if RESOLUCAO = 1024 then begin
          local_30 := PASTA + 'menu1024.jpg';
          cVar1 := FileExists(local_30);
          if cVar1 then begin
            local_30 := PASTA + 'menu1024.jpg';
            Form1.ImageFundoMenu.Picture.LoadFromFile(local_30);
          end;
        end;
        if RESOLUCAO = 1440 then begin
          local_30 := PASTA + 'menu1440.jpg';
          cVar1 := FileExists(local_30);
          if cVar1 then begin
            local_30 := PASTA + 'menu1440.jpg';
            Form1.ImageFundoMenu.Picture.LoadFromFile(local_30);
          end;
        end;
        Form1.ImageFundoMenu.Align := alClient;
        Form1.PanelMenu.Left := 0;
        Form1.PanelMenu.Top := 0;
        Form1.PanelMenu.Width := RESOLUCAO;
        Form1.PanelMenu.Height := RESOLUCAOALTURA;
        Form1.PanelMusRelogio.Hide;
        Form1.PanelUpgrade1.Hide;
        CREDITOSTESTE := 0;
        Form1.LabelListaTocados.Hide;
        Form1.LabelPress3.Caption := 'Coloque Créditos para Testar Noteiro e Moedeiro';
        Form1.LabelPress1.Caption := 'Pressione o Botão MÚSICA para Carregar a Atualização/Upg';
        Form1.LabelPress3.Show;
        Form1.Labelversao.Caption := VERSAO;
        local_40 := LETRASEXE;
        local_3c := ' ';
        local_38 := JC_CODIGODAMAQUINA;
        local_34 := local_40 + local_3c + local_38;
        Form1.LabelCliente.Caption := local_34;
        local_54 := DateToStr(Date);
        local_50 := local_54;
        local_4c := '  ';
        // C: puVar4 = &local_58;
        local_5c := TimeToStr(Time);
        // C: fpc_ansistr_copy(local_5c,1,5,puVar4);
        local_48 := local_58;
        local_44 := 'hs';
        local_34 := local_50 + local_4c + local_48 + local_44;
        Form1.LabelMDataHora.Caption := local_34;
        Voltamenu;
        Form1.EditSenha.Caption := '';
        SENHAOK := 1;
        Form1.PanelSenha.Width := 416;
        Form1.PanelSenha.Height := 308;
        if RESOLUCAO = 1024 then begin
          Form1.PanelSenha.Left := 230;
          Form1.PanelSenha.Top := 140;
        end;
        if RESOLUCAO = 1366 then begin
          Form1.PanelSenha.Left := 230;
          Form1.PanelSenha.Top := 140;
        end;
        if RESOLUCAO = 1440 then begin
          Form1.PanelSenha.Left := 230;
          Form1.PanelSenha.Top := 140;
        end;
        if CHAVEDEINSTALACAO = 0 then begin
          Form1.RadioButton1.Hide;
          Form1.RadioButton2.Hide;
        end
        else begin
          Form1.RadioButton1.Show;
          Form1.RadioButton2.Show;
        end;
        Form1.LabelCliente.Font.Color := 16777215;
        Form1.PanelSenha.Show;
        Form1.LabelMenuDSErro.Hide;
        Form1.PanelSenha.BringToFront;
        Form1.PanelMenu.Show;
        // C: ( **(code ** )( *(int * )Form1.EditSenha + 0x430))(Form1.EditSenha);
        Form1.LabelPress.Font.Color := 16777215;
        Form1.LabelPress1.Font.Color := 16777215;
        Form1.LabelPress2.Font.Color := 16777215;
        // C: JUKELINUX1_TFORM1____PANELMENU2CLICK_TOBJECT(U_JUKELINUX1_FORM1,U_JUKELINUX1_FORM1);
        // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.LabelNaoQR,Form1.ImageQrcode.Left?);
        // C: CONTROLS_TCONTROL____SETTOP_LONGINT (Form1.LabelNaoQR,Form1.ImageQrcode.Top?);
        Form1.LabelNaoQR.Show;
        // C: CONTROLS_TCONTROL____HIDE(Form1.ImageQrcode);
        if SEMQRCODE = 0 then begin
          Form1.LabelNaoQR.Caption := 'Aguarde, Gerando QRCode...';
        end
        else begin
          Form1.LabelNaoQR.Caption := 'QRCode Desativado';
        end;
        FORM1.Refresh;
        // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
        // C: JUKELINUX1_TFORM1____BUTTONQRCLICK_TOBJECT(U_JUKELINUX1_FORM1,U_JUKELINUX1_FORM1);
        ESTADIGITANDOSENHA := 1;
      end;
    end
    else begin
      if ESTADIGITANDOSENHA = 2 then begin
        SENHAOK := 0;
        if RELECDS <> 0 then begin
          Mostra_Tela_Carregando_Cds;
          NOMEARQ := PASTA + 'ritmosinativos.txt';
          cVar1 := FileExists(NOMEARQ);
          if not cVar1 then begin
            local_15c := NOMEARQ;
            AssignFile(ARQTEXTO, local_15c);
            Rewrite(ARQTEXTO);
            Flush(ARQTEXTO);
            CloseFile(ARQTEXTO);
          end;
          cVar1 := FileExists(NOMEARQ);
          if cVar1 then begin
            // C: ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0xb8)) (Form1.ListBoxRInativo.Items);
            local_15c := NOMEARQ;
            AssignFile(ARQTEXTO, local_15c);
            Reset(ARQTEXTO);
            while True do begin
              cVar1 := Eof(ARQTEXTO);
              if cVar1 then begin Break; end;
              Read(ARQTEXTO, TEXTO);
              Readln(ARQTEXTO);
              // C: ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0xa4)) (Form1.ListBoxRInativo.Items,U_JUKELINUX1_TEXTO);
            end;
            CloseFile(ARQTEXTO);
          end;
          Form1.FileListBox1.Visible := True;
          Carregando_Cds;
          Form1.FileListBox1.Visible := False;
          Form1.PanelLendo.Hide;
          KMAT := -4;
          MUSICASELECIONADA := 0;
          MUSICASELECIONADAPOSTELA := 0;
          MUSICASELECIONADATS := 0;
          if RESOLUCAO = 1366 then begin
            TAMANHOMUSICAGRANDE := 30;
          end;
          if RESOLUCAO = 1024 then begin
            TAMANHOMUSICAGRANDE := 22;
          end;
          if RESOLUCAO = 1440 then begin
            TAMANHOMUSICAGRANDE := 30;
          end;
          SOMAMUSICAGRANDE := 0;
          MOSTRANDORITMOS := 0;
          MOSTRANDOLETRAS := 0;
          Mostra_Cds(' ');
          Mostra_Nome_Das_Musicas;
          Mostra_Fila;
          Form1.TimerNomeMusicaGrande.Enabled := True;
        end;
        Form1.TimerConfigInterface.Enabled := False;
        TEMPOPALHINHA := 0;
        ESTANOMENU := 0;
        ESTADIGITANDOSENHA := 0;
        Form1.PanelMenu.Hide;
        if ALTEROUPRO <> 0 then begin
          Carregando_Propagandas;
        end;
        Ativa_Propaganda;
      end;
      if ESTADIGITANDOSENHA = 1 then begin
        // C: JUKELINUX1_TFORM1____LABELENTRARNOMENUCLICK_TOBJECT(U_JUKELINUX1_FORM1,U_JUKELINUX1_FORM1);
      end;
    end;
  end;
end;

{ JUKELINUX1_ROTINA_RITMOS }
procedure Rotina_Ritmos;
var
  local_150, local_154, local_158, local_15c, local_160, local_164, local_30, local_34, local_38, local_48, local_4c, local_50, local_58, local_64: AnsiString;
  iVar3, iVar4, uVar1: LongInt;
  local_3c, local_40, local_44, local_54, local_5c, local_60: Variant;
begin
  begin
    if ESTANOMENU = 0 then begin
      if FORMADESELECIONARRITMO = 'Paginando' then begin
        Form1.NomeDoCD.Hide;
        Form1.ImgLan.Hide;
        Form1.ImgLanMenos1.Hide;
        Form1.ImgLanMenos2.Hide;
        Form1.ImgLanMenos3.Hide;
        Form1.ImgLanMenos4.Hide;
        Form1.ImgLanMenos5.Hide;
        Form1.ImgLanMais1.Hide;
        Form1.ImgLanMais2.Hide;
        Form1.ImgLanMais3.Hide;
        Form1.ImgLanMais4.Hide;
        Form1.ImgLanMais5.Hide;
        Form1.Img50.Hide;
        Form1.Img50Menos1.Hide;
        Form1.Img50Menos2.Hide;
        Form1.Img50Menos3.Hide;
        Form1.Img50Menos4.Hide;
        Form1.Img50Menos5.Hide;
        Form1.Img50Mais1.Hide;
        Form1.Img50Mais2.Hide;
        Form1.Img50Mais3.Hide;
        Form1.Img50Mais4.Hide;
        Form1.Img50Mais5.Hide;
        local_30 := Copy(ORDEMDOSCDS, 1, 1);
        if local_30 = 'R' then begin
          if MOSTRANDORITMOS = 0 then begin
            Desselecionamusica;
            MUSICASELECIONADA := 0;
            MUSICASELECIONADAPOSTELA := 0;
            MUSICASELECIONADATS := 0;
            Selecionamusica;
            iVar3 := TOTALMMRITMO;
            RITMOSELECIONADO := RITMODOCD;
            NUMRITMOSELECIONADO := 0;
            KR := 1;
            if 0 < TOTALMMRITMO then begin
              KR := 0;
              repeat
                KR := KR + 1;
                // C: iVar4 = fpc_ansistr_compare_equal (U_JUKELINUX1_RITMOSELECIONADO, *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_KR * 4));
                if iVar4 = 0 then begin
                  NUMRITMOSELECIONADO := KR;
                end;
              until not (KR < iVar3);
            end;
            Mostra_Ritmos;
            MOSTRANDORITMOS := 1;
            Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
            if RESOLUCAO = 1366 then begin
              Mensagemtravadajpg('mensagem1366-useassetasparaselecionarogenero.jpg', 0, '');
            end;
            if RESOLUCAO = 1440 then begin
              Mensagemtravadajpg('mensagem1366-useassetasparaselecionarogenero.jpg', 0, '');
            end;
            if RESOLUCAO = 1024 then begin
              Mensagemtravadajpg('mensagem1024-useassetasparaselecionarogenero.jpg', 0, '');
            end;
          end
          else begin
            Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
            iVar4 := NUMRITMOSELECIONADO;
            // C: fpc_ansistr_incr_ref ( *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_NUMRITMOSELECIONADO * 4));
            iVar3 := TOTALCDS;
            // C: U_JUKELINUX1_RITMOESCOLHIDO = *(undefined4 * )(&DAT_092fffac + iVar4 * 4);
            POSICAORITMO := 0;
            KKRITMO := 1;
            if 0 < TOTALCDS then begin
              KKRITMO := 0;
              repeat
                KKRITMO := KKRITMO + 1;
                // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KKRITMO * 0x240 + 0x8e91128,local_30);
                // C: iVar4 = fpc_ansistr_compare_equal(local_30[0],U_JUKELINUX1_RITMOESCOLHIDO);
                if (iVar4 = 0) and (POSICAORITMO = 0) then begin
                  POSICAORITMO := KKRITMO;
                end;
              until not (KKRITMO < iVar3);
            end;
            if POSICAORITMO = 0 then begin
              KMAT := 1;
            end
            else begin
              KMAT := POSICAORITMO + -5;
            end;
            MUSICASELECIONADA := 0;
            MUSICASELECIONADAPOSTELA := 0;
            MUSICASELECIONADATS := 0;
            MOSTRANDORITMOS := 0;
            MOSTRANDOLETRAS := 0;
            Mostra_Cds(' ');
            Mostra_Nome_Das_Musicas;
            Destravamensagem;
          end;
        end;
        local_30 := Copy(ORDEMDOSCDS, 1, 1);
        if local_30 = 'A' then begin
          if MOSTRANDOLETRAS = 0 then begin
            Desselecionamusica;
            MUSICASELECIONADA := 0;
            MUSICASELECIONADAPOSTELA := 0;
            MUSICASELECIONADATS := 0;
            Selecionamusica;
            local_30 := LowerCase(LETRADOCD);
            iVar3 := TOTALMMLETRA;
            LETRASELECIONADA := local_30;
            NUMLETRASELECIONADA := 0;
            KL := 1;
            if 0 < TOTALMMLETRA then begin
              KL := 0;
              repeat
                KL := KL + 1;
                // C: iVar4 = fpc_ansistr_compare_equal (U_JUKELINUX1_LETRASELECIONADA, (&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_KL]);
                if iVar4 = 0 then begin
                  NUMLETRASELECIONADA := KL;
                end;
              until not (KL < iVar3);
            end;
            Mostra_Letras;
            MOSTRANDOLETRAS := 1;
            Form1.TimerSelecionaLetraAutomatico.Enabled := False;
            if RESOLUCAO = 1366 then begin
              Mensagemtravadajpg('mensagem1366-useassetasparaselecionaraletra.jpg', 0, '');
            end;
            if RESOLUCAO = 1440 then begin
              Mensagemtravadajpg('mensagem1366-useassetasparaselecionaraletra.jpg', 0, '');
            end;
            if RESOLUCAO = 1024 then begin
              Mensagemtravadajpg('mensagem1024-useassetasparaselecionaraletra.jpg', 0, '');
            end;
          end
          else begin
            Form1.TimerSelecionaLetraAutomatico.Enabled := False;
            // C: SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA],local_30);
            iVar3 := TOTALCDS;
            LETRAESCOLHIDA := local_30;
            POSICAOLETRA := 0;
            KKLETRA := 1;
            if 0 < TOTALCDS then begin
              KKLETRA := 0;
              repeat
                KKLETRA := KKLETRA + 1;
                // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KKLETRA * 0x240 + 0x1fc),1,1, &local_34);
                local_30 := LowerCase(local_34);
                // C: iVar4 = fpc_ansistr_compare_equal(local_30[0],U_JUKELINUX1_LETRAESCOLHIDA);
                if (iVar4 = 0) and (POSICAOLETRA = 0) then begin
                  POSICAOLETRA := KKLETRA;
                end;
              until not (KKLETRA < iVar3);
            end;
            if POSICAOLETRA = 0 then begin
              KMAT := 1;
            end
            else begin
              KMAT := POSICAOLETRA + -5;
            end;
            MUSICASELECIONADA := 0;
            MUSICASELECIONADAPOSTELA := 0;
            MUSICASELECIONADATS := 0;
            MOSTRANDORITMOS := 0;
            MOSTRANDOLETRAS := 0;
            Mostra_Cds(' ');
            Mostra_Nome_Das_Musicas;
            Destravamensagem;
          end;
        end;
      end;
      if FORMADESELECIONARRITMO = 'Um Toque' then begin
        local_34 := Copy(ORDEMDOSCDS, 1, 1);
        if local_34 = 'R' then begin
          Desselecionamusica;
          MUSICASELECIONADA := 0;
          MUSICASELECIONADAPOSTELA := 0;
          MUSICASELECIONADATS := 0;
          Selecionamusica;
          iVar3 := TOTALMMRITMO;
          RITMOSELECIONADO := RITMODOCD;
          NUMRITMOSELECIONADO := 0;
          KR := 1;
          if 0 < TOTALMMRITMO then begin
            KR := 0;
            repeat
              KR := KR + 1;
              // C: iVar4 = fpc_ansistr_compare_equal (U_JUKELINUX1_RITMOSELECIONADO, *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_KR * 4));
              if iVar4 = 0 then begin
                NUMRITMOSELECIONADO := KR;
              end;
            until not (KR < iVar3);
          end;
          NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 1;
          if TOTALMMRITMO < NUMRITMOSELECIONADO then begin
            NUMRITMOSELECIONADO := 1;
          end;
          if RESOLUCAO = 1366 then begin
            // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1366-fundopreto.jpg",3, *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_NUMRITMOSELECIONADO * 4));
          end;
          if RESOLUCAO = 1440 then begin
            // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1366-fundopreto.jpg",3, *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_NUMRITMOSELECIONADO * 4));
          end;
          if RESOLUCAO = 1024 then begin
            // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1024-fundopreto.jpg",3, *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_NUMRITMOSELECIONADO * 4));
          end;
          iVar4 := NUMRITMOSELECIONADO;
          // C: fpc_ansistr_incr_ref ( *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_NUMRITMOSELECIONADO * 4));
          iVar3 := TOTALCDS;
          // C: U_JUKELINUX1_RITMOESCOLHIDO = *(undefined4 * )(&DAT_092fffac + iVar4 * 4);
          POSICAORITMO := 0;
          KKRITMO := 1;
          if 0 < TOTALCDS then begin
            KKRITMO := 0;
            repeat
              KKRITMO := KKRITMO + 1;
              // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KKRITMO * 0x240 + 0x8e91128,&local_34);
              // C: iVar4 = fpc_ansistr_compare_equal(local_34,U_JUKELINUX1_RITMOESCOLHIDO);
              if (iVar4 = 0) and (POSICAORITMO = 0) then begin
                POSICAORITMO := KKRITMO;
              end;
            until not (KKRITMO < iVar3);
          end;
          if POSICAORITMO = 0 then begin
            KMAT := 1;
          end
          else begin
            KMAT := POSICAORITMO + -5;
          end;
          MUSICASELECIONADA := 0;
          MUSICASELECIONADAPOSTELA := 0;
          MUSICASELECIONADATS := 0;
          MOSTRANDORITMOS := 0;
          MOSTRANDOLETRAS := 0;
          Mostra_Cds(' ');
          Mostra_Nome_Das_Musicas;
        end;
        local_34 := Copy(ORDEMDOSCDS, 1, 1);
        if local_34 = 'A' then begin
          Desselecionamusica;
          MUSICASELECIONADA := 0;
          MUSICASELECIONADAPOSTELA := 0;
          MUSICASELECIONADATS := 0;
          Selecionamusica;
          local_34 := LowerCase(LETRADOCD);
          iVar3 := TOTALMMLETRA;
          LETRASELECIONADA := local_34;
          NUMLETRASELECIONADA := 0;
          KL := 1;
          if 0 < TOTALMMLETRA then begin
            KL := 0;
            repeat
              KL := KL + 1;
              // C: iVar4 = fpc_ansistr_compare_equal (U_JUKELINUX1_LETRASELECIONADA, (&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_KL]);
              if iVar4 = 0 then begin
                NUMLETRASELECIONADA := KL;
              end;
            until not (KL < iVar3);
          end;
          NUMLETRASELECIONADA := NUMLETRASELECIONADA + 1;
          if TOTALMMLETRA < NUMLETRASELECIONADA then begin
            NUMLETRASELECIONADA := 1;
          end;
          if RESOLUCAO = 1366 then begin
            // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1366-fundopreto.jpg",4, (&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA]);
          end;
          if RESOLUCAO = 1440 then begin
            // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1366-fundopreto.jpg",4, (&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA]);
          end;
          if RESOLUCAO = 1024 then begin
            // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1024-fundopreto.jpg",4, (&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA]);
          end;
          // C: SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA],&local_34);
          iVar3 := TOTALCDS;
          LETRAESCOLHIDA := local_34;
          POSICAOLETRA := 0;
          KKLETRA := 1;
          if 0 < TOTALCDS then begin
            KKLETRA := 0;
            repeat
              KKLETRA := KKLETRA + 1;
              // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KKLETRA * 0x240 + 0x1fc),1,1, local_30);
              local_34 := LowerCase(local_30);
              // C: iVar4 = fpc_ansistr_compare_equal(local_34,U_JUKELINUX1_LETRAESCOLHIDA);
              if (iVar4 = 0) and (POSICAOLETRA = 0) then begin
                POSICAOLETRA := KKLETRA;
              end;
            until not (KKLETRA < iVar3);
          end;
          if POSICAOLETRA = 0 then begin
            KMAT := 1;
          end
          else begin
            KMAT := POSICAOLETRA + -5;
          end;
          MUSICASELECIONADA := 0;
          MUSICASELECIONADAPOSTELA := 0;
          MUSICASELECIONADATS := 0;
          MOSTRANDORITMOS := 0;
          MOSTRANDOLETRAS := 0;
          Mostra_Cds(' ');
          Mostra_Nome_Das_Musicas;
        end;
      end;
    end
    else if SENHAOK = 1 then begin
      if (QTDCREDITOSGRATIS = 0) and (QTDCREDITOSGRATISVIP = 0) then begin
        Form1.LabelPress2.Caption := 'Está Configurado no Menu Sem Créditos Grátis';
      end
      else begin
        // C: ppuVar6 = &local_34;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelPress2,local_30);
        // C: fpc_ansistr_copy(local_30[0],1,9,ppuVar6);
        if local_34 = 'Pressione' then begin
          Form1.LabelPress2.Font.Color := 65280;
          if (0 < QTDCREDITOSGRATIS) and (0 < QTDCREDITOSGRATISVIP) then begin
            local_4c := 'Ok, ';
            local_34 := IntToStr(QTDCREDITOSGRATIS);
            local_48 := local_34;
            local_44 := ' Créditos Gratis + ';
            local_30 := IntToStr(QTDCREDITOSGRATISVIP);
            local_40 := local_30;
            local_3c := ' VIPs';
            local_38 := local_4c + local_48 + local_44 + local_40 + local_3c;
            Form1.LabelPress2.Caption := local_38;
          end;
          if (0 < QTDCREDITOSGRATIS) and (QTDCREDITOSGRATISVIP = 0) then begin
            local_44 := 'Ok, ';
            local_50 := IntToStr(QTDCREDITOSGRATIS);
            local_40 := local_50;
            local_3c := ' Créditos Gratis';
            local_38 := local_44 + local_40 + local_3c;
            Form1.LabelPress2.Caption := local_38;
          end;
          if (QTDCREDITOSGRATIS = 0) and (0 < QTDCREDITOSGRATISVIP) then begin
            local_44 := 'Ok, ';
            local_50 := IntToStr(QTDCREDITOSGRATISVIP);
            local_40 := local_50;
            local_3c := ' Créditos Grátis VIPs';
            local_38 := local_44 + local_40 + local_3c;
            Form1.LabelPress2.Caption := local_38;
          end;
          RELOGIOGRATIS := RELOGIOGRATIS + QTDCREDITOSGRATIS;
          local_50 := IntToStr(RELOGIOGRATIS);
          RELOGIOGRATISSTR := local_50;
          local_50 := PASTA + 'relogiogratis.txt';
          local_150 := local_50;
          AssignFile(ARQTEXTO, local_150);
          Rewrite(ARQTEXTO);
          local_50 := Cripta(RELOGIOGRATISSTR);
          Write(ARQTEXTO, local_50);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          RELOGIOGRATISVIP := RELOGIOGRATISVIP + QTDCREDITOSGRATISVIP;
          local_50 := IntToStr(RELOGIOGRATISVIP);
          RELOGIOGRATISVIPSTR := local_50;
          local_50 := PASTA + 'relogiogratisvip.txt';
          local_150 := local_50;
          AssignFile(ARQTEXTO, local_150);
          Rewrite(ARQTEXTO);
          local_50 := Cripta(RELOGIOGRATISVIPSTR);
          Write(ARQTEXTO, local_50);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          CREDITOS := CREDITOS + QTDCREDITOSGRATIS;
          NOMEARQ := PASTA + 'creditos.txt';
          local_150 := NOMEARQ;
          AssignFile(ARQTEXTO, local_150);
          Rewrite(ARQTEXTO);
          local_154 := IntToStr(CREDITOS);
          local_50 := Cripta(local_154);
          Write(ARQTEXTO, local_50);
          Writeln(ARQTEXTO);
          local_154 := Cripta(JC_SERIALPENDRIVE);
          Write(ARQTEXTO, local_154);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          if SEMPENDRIVE = 0 then begin
            local_50 := PASTACHAVE + 'creditos.txt';
            // C: puVar5 = local_50;
            if False { C: local_50 == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar5,&local_154);
            // C: uVar1 = local_154;
            local_15c := PASTA + 'creditos.txt';
            // C: puVar5 = local_15c;
            if False { C: local_15c == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar5,&local_158);
            // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_158,uVar1,extraout_ECX & 0xffffff00);
          end;
          CREDITOSVIP := CREDITOSVIP + QTDCREDITOSGRATISVIP;
          NOMEARQ := PASTA + 'creditosvip.txt';
          local_150 := NOMEARQ;
          AssignFile(ARQTEXTO, local_150);
          Rewrite(ARQTEXTO);
          local_154 := IntToStr(CREDITOSVIP);
          local_158 := Cripta(local_154);
          Write(ARQTEXTO, local_158);
          Writeln(ARQTEXTO);
          local_158 := Cripta(JC_SERIALPENDRIVE);
          Write(ARQTEXTO, local_158);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          local_160 := IntToStr(CREDITOS);
          Form1.LabelCreditos.Caption := local_160;
          local_64 := 'Menu - ';
          local_154 := IntToStr(QTDCREDITOSGRATIS);
          local_60 := local_154;
          local_5c := ' Credito Gratis  + ';
          local_164 := IntToStr(QTDCREDITOSGRATISVIP);
          local_58 := local_164;
          local_54 := ' VIPs';
          local_158 := local_64 + local_60 + local_5c + local_58 + local_54;
          Gravalog(local_158);
          Form1.TimerGravaPenDrive.Enabled := False;
          Form1.TimerGravaPenDrive.Enabled := True;
          JAGRAVOUNOPENDRIVE := 1;
        end;
      end;
    end;
  end;
end;

{ JUKELINUX1_ROTINA_TOCAR }
procedure Rotina_Tocar;
var
  local_12c, local_130, local_134, local_138, local_13c, local_140, local_240, local_244, local_248: AnsiString;
  cVar2: Boolean;
  iVar4, iVar5, uVar1: LongInt;
begin
  begin
    if REAISXMUSICAS = 'Livre' then begin
      CREDITOS := 1;
    end;
    if ESTANOMENU = 0 then begin
      // C: iVar4 = *(int * )((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_MUSICASELECIONADA * 4);
      iVar5 := 0;
      if iVar4 <> 0 then begin
        // C: iVar5 = *(int * )(iVar4 + -4);
      end;
      if iVar5 < 1 then begin
        Presstecla;
        if RESOLUCAO = 1366 then begin
          Mensagemjpg('mensagem1366-selecioneumamusica.jpg', 0, '');
        end;
        if RESOLUCAO = 1440 then begin
          Mensagemjpg('mensagem1366-selecioneumamusica.jpg', 0, '');
        end;
        if RESOLUCAO = 1024 then begin
          Mensagemjpg('mensagem1024-selecioneumamusica.jpg', 0, '');
        end;
      end
      else begin
        if (TOCANDOMUSICA <> 0) and (TOCANDOMUSICAGRATIS <> 0) then begin
          Rotina_Cancelar;
        end;
        if CREDITOS < 1 then begin
          if RESOLUCAO = 1366 then begin
            Mensagemjpg('mensagem1366-coloquecreditos1.jpg', 0, '');
          end;
          if RESOLUCAO = 1440 then begin
            Mensagemjpg('mensagem1366-coloquecreditos1.jpg', 0, '');
          end;
          if RESOLUCAO = 1024 then begin
            Mensagemjpg('mensagem1024-coloquecreditos1.jpg', 0, '');
          end;
        end
        else if 0 < MUSICASELECIONADA then begin
          cVar2 := Tem_2X_Musica_Na_Fila;
          if not cVar2 then begin
            CREDITOS := CREDITOS + -1;
            PULSOSPARACARTAO := 0;
            local_130 := PASTA + 'creditos.txt';
            local_12c := local_130;
            AssignFile(ARQTEXTO, local_12c);
            Rewrite(ARQTEXTO);
            local_130 := IntToStr(CREDITOS);
            CREDITOSSTR := local_130;
            local_130 := Cripta(CREDITOSSTR);
            CREDITOSSTR := local_130;
            // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
            Writeln(ARQTEXTO);
            local_130 := Cripta(JC_SERIALPENDRIVE);
            Write(ARQTEXTO, local_130);
            Writeln(ARQTEXTO);
            Flush(ARQTEXTO);
            CloseFile(ARQTEXTO);
            local_134 := IntToStr(CREDITOS);
            Form1.LabelCreditos.Caption := local_134;
            if SEMPENDRIVE = 0 then begin
              local_138 := PASTACHAVE + 'creditos.txt';
              // C: puVar6 = local_138;
              if False { C: local_138 == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar6,&local_130);
              // C: puVar6 = local_130;
              local_140 := PASTA + 'creditos.txt';
              // C: puVar7 = local_140;
              if False { C: local_140 == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar7,&local_13c);
              // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_13c,puVar6,extraout_ECX & 0xffffff00);
            end;
            Form1.LabelCreditos.Font.Color := 255;
            Form1.TimerPiscaCreditos.Enabled := False;
            Form1.TimerPiscaCreditos.Enabled := True;
            MOSTRANDOCREDITO := 1;
            local_13c := PASTA + 'tocar.txt';
            cVar2 := FileExists(local_13c);
            if cVar2 then begin
              local_13c := PASTA + 'tocar.txt';
              local_240 := local_13c;
              AssignFile(ARQTOCAR, local_240);
              Append(ARQTOCAR);
              // C: fpc_write_text_ansistr (0,U_JUKELINUX1_ARQTOCAR, *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_MUSICASELECIONADA * 4));
              Writeln(ARQTOCAR);
              Flush(ARQTOCAR);
              CloseFile(ARQTOCAR);
              if SEMPENDRIVE = 0 then begin
                local_130 := PASTACHAVE + 'tocar.txt';
                // C: puVar6 = local_130;
                if False { C: local_130 == (undefined1 * )0x0 } then begin
                end;
                // C: fpc_pchar_to_ansistr(puVar6,&local_13c);
                // C: uVar1 = local_13c;
                local_248 := PASTA + 'tocar.txt';
                // C: puVar6 = local_248;
                if False { C: local_248 == (undefined1 * )0x0 } then begin
                end;
                // C: fpc_pchar_to_ansistr(puVar6,&local_244);
                // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_244,uVar1,extraout_ECX_00 & 0xffffff00);
              end;
            end;
            // C: fpc_ansistr_concat(&local_244,"Musica Selecionada ", (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_MUSICASELECIONADA]);
            Gravalog(local_244);
            if RESOLUCAO = 1366 then begin
              // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1366-voceselecionouamusica.jpg",1, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_MUSICASELECIONADA]);
            end;
            if RESOLUCAO = 1440 then begin
              // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1366-voceselecionouamusica.jpg",1, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_MUSICASELECIONADA]);
            end;
            if RESOLUCAO = 1024 then begin
              // C: JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING ("mensagem1024-voceselecionouamusica.jpg",1, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_MUSICASELECIONADA]);
            end;
            Mostra_Fila;
          end
          else begin
            if RESOLUCAO = 1366 then begin
              Mensagemjpg('mensagem1366-estamusicaesta2xconsecutivasnafila.jpg', 0, '');
            end;
            if RESOLUCAO = 1440 then begin
              Mensagemjpg('mensagem1366-estamusicaesta2xconsecutivasnafila.jpg', 0, '');
            end;
            if RESOLUCAO = 1024 then begin
              Mensagemjpg('mensagem1024-estamusicaesta2xconsecutivasnafila.jpg', 0, '');
            end;
          end;
        end;
      end;
    end
    else if SENHAOK = 1 then begin
      PRESS2XPARAZERAR := PRESS2XPARAZERAR + 1;
      if PRESS2XPARAZERAR < 2 then begin
        Form1.LabelPress.Caption := 'Pressione "OK" Novamente para Zerar o Relogio Parcial';
      end;
      if 1 < PRESS2XPARAZERAR then begin
        // C: JUKELINUX1_TFORM1____BUTTONZRPCLICK_TOBJECT(U_JUKELINUX1_FORM1,U_JUKELINUX1_FORM1);
      end;
    end;
  end;
end;

{ JUKELINUX1_ROTINA_VOLUMEMAIS }
procedure Rotina_Volumemais;
var
  local_130, local_30: AnsiString;
  iVar2: LongInt;
begin
  begin
    Form1.TimerDesativaVolume.Enabled := False;
    Form1.TimerDesativaVolume.Enabled := True;
    if TEMPOPARAAUMENTARVOLUME = 0 then begin
      TEMPOPARAAUMENTARVOLUME := 1;
      Form1.TimerAcionaVolume.Enabled := False;
      Form1.TimerAcionaVolume.Enabled := True;
      VOLUMELIMITADONAOAUMENTA := 0;
      if (VOLUMELIMITADO <> 0) and (LIMITARVOLUME < VOLUME + 1) then begin
        if AUMENTAVOLUMECOMUMTOQUE = 'Um Toque' then begin
          TOQUEVOLUMEMAIS := 0;
          Form1.TimerVolumeMais.Enabled := False;
        end;
        VOLUMELIMITADONAOAUMENTA := 1;
        if RESOLUCAO = 1366 then begin
          local_30 := IntToStr(VOLUME);
          Mensagemtravadajpg('mensagem1366-volumelimitado.jpg', 3, local_30);
        end;
        if RESOLUCAO = 1440 then begin
          local_30 := IntToStr(VOLUME);
          Mensagemtravadajpg('mensagem1366-volumelimitado.jpg', 3, local_30);
        end;
        if RESOLUCAO = 1024 then begin
          local_30 := IntToStr(VOLUME);
          Mensagemtravadajpg('mensagem1024-volumelimitado.jpg', 3, local_30);
        end;
      end;
      if VOLUMELIMITADONAOAUMENTA = 0 then begin
        VOLUME := VOLUME + INTERVALOVOLUME;
        if 100 < VOLUME then begin
          VOLUME := 100;
          // C: iVar2 = fpc_ansistr_compare_equal (U_JUKELINUX1_AUMENTAVOLUMECOMUMTOQUE,"Um Toque");
          if iVar2 = 0 then begin
            TOQUEVOLUMEMAIS := 0;
            Form1.TimerVolumeMais.Enabled := False;
          end;
        end;
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME);
        if ESTAEMTELACHEIA = 0 then begin
          if RESOLUCAO = 1366 then begin
            local_30 := IntToStr(VOLUME);
            Mensagemtravadajpg('mensagem1366-volume.jpg', 3, local_30);
          end;
          if RESOLUCAO = 1440 then begin
            local_30 := IntToStr(VOLUME);
            Mensagemtravadajpg('mensagem1366-volume.jpg', 3, local_30);
          end;
          if RESOLUCAO = 1024 then begin
            local_30 := IntToStr(VOLUME);
            Mensagemtravadajpg('mensagem1024-volume.jpg', 3, local_30);
          end;
        end;
        local_30 := PASTA + 'volume.txt';
        local_130 := local_30;
        AssignFile(ARQTEXTO, local_130);
        Rewrite(ARQTEXTO);
        local_30 := IntToStr(VOLUME);
        Write(ARQTEXTO, local_30);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
    end;
  end;
end;

{ JUKELINUX1_ROTINA_VOLUMEMENOS }
procedure Rotina_Volumemenos;
var
  local_130, local_30: AnsiString;
begin
  begin
    Form1.TimerDesativaVolume.Enabled := False;
    Form1.TimerDesativaVolume.Enabled := True;
    if TEMPOPARAAUMENTARVOLUME = 0 then begin
      TEMPOPARAAUMENTARVOLUME := 1;
      Form1.TimerAcionaVolume.Enabled := False;
      Form1.TimerAcionaVolume.Enabled := True;
      VOLUME := VOLUME - INTERVALOVOLUME;
      if VOLUME < 5 then begin
        VOLUME := 5;
      end;
      if VOLUME = 5 then begin
        if AUMENTAVOLUMECOMUMTOQUE = 'Um Toque' then begin
          TOQUEVOLUMEMENOS := 0;
          Form1.TimerVolumeMenos.Enabled := False;
        end;
      end;
      // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME);
      if ESTAEMTELACHEIA = 0 then begin
        if RESOLUCAO = 1366 then begin
          local_30 := IntToStr(VOLUME);
          Mensagemtravadajpg('mensagem1366-volume.jpg', 3, local_30);
        end;
        if RESOLUCAO = 1440 then begin
          local_30 := IntToStr(VOLUME);
          Mensagemtravadajpg('mensagem1366-volume.jpg', 3, local_30);
        end;
        if RESOLUCAO = 1024 then begin
          local_30 := IntToStr(VOLUME);
          Mensagemtravadajpg('mensagem1024-volume.jpg', 3, local_30);
        end;
      end;
      local_30 := PASTA + 'volume.txt';
      local_130 := local_30;
      AssignFile(ARQTEXTO, local_130);
      Rewrite(ARQTEXTO);
      local_30 := IntToStr(VOLUME);
      Write(ARQTEXTO, local_30);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
  end;
end;

{ JUKELINUX1_SELECIONAMUSICA }
procedure Selecionamusica;
var
  local_30: AnsiString;
  iVar1: LongInt;
begin
  begin
    if ALTEROUMUSICAGRANDE <> 0 then begin
      SOMAMUSICAGRANDE := 0;
      case MUSICASELECIONADAANT of
        1: begin
          Form1.Musica1.Caption := NOMEMUSICAORIGINALGRANDE;
        end;
        2: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2,DAT_09301dc4);
        end;
        3: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3,DAT_09301dc8);
        end;
        4: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4,DAT_09301dcc);
        end;
        5: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5,DAT_09301dd0);
        end;
        6: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6,DAT_09301dd4);
        end;
        7: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7,DAT_09301dd8);
        end;
        8: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8,DAT_09301ddc);
        end;
        9: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9,DAT_09301de0);
        end;
        10: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10,DAT_09301de4);
        end;
        11: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11,DAT_09301de8);
        end;
        12: begin
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12,DAT_09301dec);
        end;
      end;
    end;
    case MUSICASELECIONADAPOSTELA of
      0: begin
        Form1.Musica1.Font.Color := CORLETRA;
      end;
      1: begin
        Form1.Musica1.Font.Color := CORLETRA;
      end;
      2: begin
        Form1.Musica2.Font.Color := CORLETRA;
      end;
      3: begin
        Form1.Musica3.Font.Color := CORLETRA;
      end;
      4: begin
        Form1.Musica4.Font.Color := CORLETRA;
      end;
      5: begin
        Form1.Musica5.Font.Color := CORLETRA;
      end;
      6: begin
        Form1.Musica6.Font.Color := CORLETRA;
      end;
      7: begin
        Form1.Musica7.Font.Color := CORLETRA;
      end;
      8: begin
        Form1.Musica8.Font.Color := CORLETRA;
      end;
      9: begin
        Form1.Musica9.Font.Color := CORLETRA;
      end;
      10: begin
        Form1.Musica10.Font.Color := CORLETRA;
      end;
      11: begin
        Form1.Musica11.Font.Color := CORLETRA;
      end;
      12: begin
        Form1.Musica12.Font.Color := CORLETRA;
      end;
    end;
    if (MUSICASELECIONADAPOSTELA = 12) and (12 < MUSICASELECIONADA) then begin
      POSTELAFAIXA := MUSICASELECIONADA + -12;
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica1, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_MUSICASELECIONADA + -0xb]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 2]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 3]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 4]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 5]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 6]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 7]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 8]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 9]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 10]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 0xb]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 0xc]);
    end;
    iVar1 := POSTELAFAIXA;
    if (MUSICASELECIONADAPOSTELA = 0) and (0 < MUSICASELECIONADA) then begin
      POSTELAFAIXA := POSTELAFAIXA + -1;
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica1, (&U_JUKELINUX1_PASTACHAVE9)[(U_JUKELINUX1_KMAT + 5) * 0x90 + iVar1]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 2]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 3]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 4]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 5]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 6]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 7]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 8]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 9]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 10]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 0xb]);
      // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12, (&U_JUKELINUX1_PASTACHAVE9) [(U_JUKELINUX1_KMAT + 5) * 0x90 + U_JUKELINUX1_POSTELAFAIXA + 0xc]);
      if MUSICASELECIONADAPOSTELA = 0 then begin
        MUSICASELECIONADAPOSTELA := 1;
      end;
    end;
    if MUSICASELECIONADA = 0 then begin
      Form1.Musica1.Font.Color := CORLETRAFUNDO;
    end;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica1,local_30);
    NOMEMUSICAORIGINALGRANDE := local_30;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica2,local_30);
    // C: DAT_09301dc4 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica3,local_30);
    // C: DAT_09301dc8 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica4,local_30);
    // C: DAT_09301dcc = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica5,local_30);
    // C: DAT_09301dd0 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica6,local_30);
    // C: DAT_09301dd4 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica7,local_30);
    // C: DAT_09301dd8 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica8,local_30);
    // C: DAT_09301ddc = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica9,local_30);
    // C: DAT_09301de0 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica10,local_30);
    // C: DAT_09301de4 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica11,local_30);
    // C: DAT_09301de8 = local_30[0];
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica12,local_30);
    // C: DAT_09301dec = local_30[0];
    Form1.TimerNomeMusicaGrande.Enabled := True;
  end;
end;

{ JUKELINUX1_STRESPACO$ANSISTRING$LONGINT$$ANSISTRING }
function Strespaco(P1: AnsiString; P2: LongInt): AnsiString;
var
  local_10: AnsiString;
  iVar3, local_14, local_18, local_c: LongInt;
  local_1c, local_8: Variant;
begin
  local_10 := Result;
  local_c := P2;
  local_8 := P1;
  begin
    local_1c := local_8;
    if local_8 <> 0 then begin
      // C: local_18 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    iVar3 := local_c - local_18;
    local_14 := 1;
    if 0 < iVar3 then begin
      repeat
        local_14 := local_14 + 1;
        local_8 := local_8 + ' ';
      until not (local_14 < iVar3);
    end;
    local_1c := local_8 + local_1c;
    // C: piVar1 = local_10;
    // C: *piVar1 = local_1c;
  end;
end;

{ JUKELINUX1_STRZERO$ANSISTRING$LONGINT$$ANSISTRING }
function Strzero(P1: AnsiString; P2: LongInt): AnsiString;
var
  local_10: AnsiString;
  iVar3, local_14, local_18, local_c: LongInt;
  local_1c, local_8: Variant;
begin
  local_10 := Result;
  local_c := P2;
  local_8 := P1;
  begin
    local_1c := local_8;
    if local_8 <> 0 then begin
      // C: local_18 = *(int * )(U_JUKELINUX1_FORM1 + -4);
    end;
    iVar3 := local_c - local_18;
    local_14 := 1;
    if 0 < iVar3 then begin
      repeat
        local_14 := local_14 + 1;
        local_8 := local_8 + '0';
      until not (local_14 < iVar3);
    end;
    local_1c := local_8 + local_1c;
    // C: piVar1 = local_10;
    // C: *piVar1 = local_1c;
  end;
end;

{ JUKELINUX1_TELA1 }
procedure Tela1;
var
  local_44, local_48: AnsiString;
  cVar1: Boolean;
  local_10, local_14, local_18, local_8, local_c: LongInt;
begin
  begin
    Gravalog('Inicio da Rotina Tela1');
    Form1.PanelLendo.Hide;
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb1c) + 0x21c)) (Form1.PanelTela1,0);
    CORLETRA := 65280;
    CORLETRAFUNDO := 16777215;
    Form1.PanelTela1.Top := 0;
    Form1.ImageTela1.Align := alClient;
    if RESOLUCAO = 1024 then begin
      local_44 := PASTA + 'tela1024.bmp';
      cVar1 := FileExists(local_44);
      if cVar1 then begin
        local_44 := PASTA + 'tela1024.bmp';
        Form1.ImageTela1.Picture.LoadFromFile(local_44);
      end;
    end;
    if RESOLUCAO = 1366 then begin
      local_44 := PASTA + 'tela1366.bmp';
      cVar1 := FileExists(local_44);
      if cVar1 then begin
        local_44 := PASTA + 'tela1366.bmp';
        Form1.ImageTela1.Picture.LoadFromFile(local_44);
      end;
    end;
    if RESOLUCAO = 1440 then begin
      local_44 := PASTA + 'tela1440.bmp';
      cVar1 := FileExists(local_44);
      if cVar1 then begin
        local_44 := PASTA + 'tela1440.bmp';
        Form1.ImageTela1.Picture.LoadFromFile(local_44);
      end;
    end;
    Form1.PanelTela1.Left := 0;
    Form1.PanelTela1.Top := 0;
    Form1.PanelTela1.Width := RESOLUCAO;
    Form1.PanelTela1.Height := RESOLUCAOALTURA;
    Form1.PanelTela1.Show;
    Form1.PanelTela1.BringToFront;
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb1c) + 0x2fc)) (Form1.PanelTela1);
    if RESOLUCAO = 1366 then begin
      local_c := 180;
      local_10 := 25;
    end;
    if RESOLUCAO = 1024 then begin
      local_c := 170;
      local_10 := 20;
    end;
    if RESOLUCAO = 1440 then begin
      local_c := 180;
      local_10 := 40;
      local_14 := 132;
    end;
    Form1.CapaSelecionada.Left := (RESOLUCAO - Form1.CapaSelecionada.Width) + -5;
    Form1.CapaSelecionada.Top := (local_14 div 2) + 223;
    Form1.CapaSelecionada.Height := 322;
    Form1.CapaSelecionada.Width := 357;
    Form1.CDSelecionado.Left := Form1.CapaSelecionada.Left + 50;
    Form1.CDSelecionado.Top := Form1.CapaSelecionada.Top + 17;
    Form1.CDSelecionado.Height := 290;
    Form1.CDSelecionado.Width := 290;
    Form1.LabelCreditos.Left := Form1.CapaSelecionada.Left + 165;
    Form1.LabelCreditos.Top := Form1.CapaSelecionada.Top + 399;
    local_48 := IntToStr(CREDITOS);
    Form1.LabelCreditos.Caption := local_48;
    Form1.NumCD.Left := Form1.CapaSelecionada.Left + 290;
    Form1.NumCD.Top := Form1.CapaSelecionada.Top + -20;
    Form1.NomeDoCD.Left := Form1.CapaSelecionada.Left + 10;
    Form1.NomeDoCD.Top := Form1.CapaSelecionada.Top + 317;
    Form1.LabelCDDVD.Left := Form1.CapaSelecionada.Left + 191;
    Form1.LabelCDDVD.Top := Form1.CapaSelecionada.Top + -155;
    Form1.LabelCDDVD.Width := 129;
    Form1.LabelCDDVD.Height := 38;
    Form1.LabelCDDVD1.Left := Form1.LabelCDDVD.Left + 1;
    Form1.LabelCDDVD1.Top := Form1.LabelCDDVD.Top + 2;
    Form1.LabelCDDVD1.Width := Form1.LabelCDDVD.Width;
    Form1.LabelCDDVD1.Height := Form1.LabelCDDVD.Height;
    Form1.LabelRitmo.Left := Form1.CapaSelecionada.Left + 175;
    Form1.LabelRitmo.Top := Form1.CapaSelecionada.Top + -70;
    Form1.LabelRitmo.Width := 162;
    Form1.LabelRitmo.Height := 47;
    Form1.LabelRitmo1.Left := Form1.LabelRitmo.Left + 1;
    Form1.LabelRitmo1.Top := Form1.LabelRitmo.Top + 1;
    Form1.LabelRitmo1.Width := Form1.LabelRitmo.Width;
    Form1.LabelRitmo1.Height := Form1.LabelRitmo.Height;
    if RESOLUCAO = 1366 then begin
      Form1.SetaBaixo.Left := Form1.CapaSelecionada.Left + -540;
      Form1.SetaBaixo.Top := Form1.CapaSelecionada.Top + 315;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.SetaBaixo.Left := Form1.CapaSelecionada.Left + -410;
      Form1.SetaBaixo.Top := Form1.CapaSelecionada.Top + 315;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.SetaBaixo.Left := Form1.CapaSelecionada.Left + -590;
      Form1.SetaBaixo.Top := Form1.CapaSelecionada.Top + 315;
    end;
    Form1.SetaBaixo.Hide;
    Form1.TimerPiscaSeta.Enabled := False;
    Form1.Musica12.BringToFront;
    Form1.Musica11.BringToFront;
    Form1.Imagemsg.BringToFront;
    Form1.ImagePNG.BringToFront;
    Form1.LabelMsg1.BringToFront;
    MOSTRANDOSETABAIXO := 0;
    local_18 := 30;
    local_8 := 130;
    Form1.Musica1.Top := Form1.CapaSelecionada.Top + -20;
    if RESOLUCAO = 1366 then begin
      Form1.Musica1.Left := Form1.CapaSelecionada.Left + -570;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.Musica1.Left := Form1.CapaSelecionada.Left - (570 - local_8);
    end;
    if RESOLUCAO = 1440 then begin
      Form1.Musica1.Left := Form1.CapaSelecionada.Left + -620;
    end;
    Form1.Musica1.AutoSize := False;
    if RESOLUCAO = 1366 then begin
      Form1.Musica1.Width := 540;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.Musica1.Width := 540 - local_8;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.Musica1.Width := 540;
    end;
    Form1.Musica2.Top := Form1.CapaSelecionada.Top + -20 + local_18;
    Form1.Musica2.Left := Form1.Musica1.Left;
    Form1.Musica2.AutoSize := False;
    Form1.Musica2.Width := Form1.Musica1.Width;
    Form1.Musica3.Top := Form1.CapaSelecionada.Top + -20 + local_18 * 2;
    Form1.Musica3.Left := Form1.Musica1.Left;
    Form1.Musica3.AutoSize := False;
    Form1.Musica3.Width := Form1.Musica1.Width;
    Form1.Musica4.Top := local_18 * 3 + Form1.CapaSelecionada.Top + -20;
    Form1.Musica4.Left := Form1.Musica1.Left;
    Form1.Musica4.AutoSize := False;
    Form1.Musica4.Width := Form1.Musica1.Width;
    Form1.Musica5.Top := Form1.CapaSelecionada.Top + -20 + local_18 * 4;
    Form1.Musica5.Left := Form1.Musica1.Left;
    Form1.Musica5.AutoSize := False;
    Form1.Musica5.Width := Form1.Musica1.Width;
    Form1.Musica6.Top := local_18 * 5 + Form1.CapaSelecionada.Top + -20;
    Form1.Musica6.Left := Form1.Musica1.Left;
    Form1.Musica6.AutoSize := False;
    Form1.Musica6.Width := Form1.Musica1.Width;
    Form1.Musica7.Top := local_18 * 6 + Form1.CapaSelecionada.Top + -20;
    Form1.Musica7.Left := Form1.Musica1.Left;
    Form1.Musica7.AutoSize := False;
    Form1.Musica7.Width := Form1.Musica1.Width;
    Form1.Musica8.Top := local_18 * 7 + Form1.CapaSelecionada.Top + -20;
    Form1.Musica8.Left := Form1.Musica1.Left;
    Form1.Musica8.AutoSize := False;
    Form1.Musica8.Width := Form1.Musica1.Width;
    Form1.Musica9.Top := Form1.CapaSelecionada.Top + -20 + local_18 * 8;
    Form1.Musica9.Left := Form1.Musica1.Left;
    Form1.Musica9.AutoSize := False;
    Form1.Musica9.Width := Form1.Musica1.Width;
    Form1.Musica10.Top := local_18 * 9 + Form1.CapaSelecionada.Top + -20;
    Form1.Musica10.Left := Form1.Musica1.Left;
    Form1.Musica10.AutoSize := False;
    Form1.Musica10.Width := Form1.Musica1.Width;
    Form1.Musica11.Top := local_18 * 10 + Form1.CapaSelecionada.Top + -20;
    Form1.Musica11.Left := Form1.Musica1.Left;
    Form1.Musica11.AutoSize := False;
    Form1.Musica11.Width := Form1.Musica1.Width;
    Form1.Musica12.Top := local_18 * 11 + Form1.CapaSelecionada.Top + -20;
    Form1.Musica12.Left := Form1.Musica1.Left;
    Form1.Musica12.AutoSize := False;
    Form1.Musica12.Width := Form1.Musica1.Width;
    if RESOLUCAO = 1366 then begin
      Form1.LabelLM1.Top := Form1.CapaSelecionada.Top + 50;
      Form1.LabelLM1.Left := Form1.CapaSelecionada.Left + -445;
      Form1.LabelLM2.Top := Form1.LabelLM1.Top + 2;
      Form1.LabelLM2.Left := Form1.LabelLM1.Left + 2;
      Form1.LabelLM3.Width := Form1.LabelLM1.Width + 140;
      Form1.LabelLM3.Left := Form1.LabelLM1.Left + -30;
      Form1.LabelLM3.Top := Form1.LabelLM1.Top + 180;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.LabelLM1.Top := Form1.CapaSelecionada.Top + 50;
      Form1.LabelLM1.Left := Form1.CapaSelecionada.Left + -375;
      Form1.LabelLM2.Top := Form1.LabelLM1.Top + 2;
      Form1.LabelLM2.Left := Form1.LabelLM1.Left + 2;
      Form1.LabelLM3.Width := Form1.LabelLM1.Width + 140;
      Form1.LabelLM3.Left := Form1.LabelLM1.Left + -20;
      Form1.LabelLM3.Top := Form1.LabelLM1.Top + 180;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.LabelLM1.Top := Form1.CapaSelecionada.Top + 50;
      Form1.LabelLM1.Left := Form1.CapaSelecionada.Left + -485;
      Form1.LabelLM2.Top := Form1.LabelLM1.Top + 2;
      Form1.LabelLM2.Left := Form1.LabelLM1.Left + 2;
      Form1.LabelLM3.Width := Form1.LabelLM1.Width + 140;
      Form1.LabelLM3.Left := Form1.LabelLM1.Left + -30;
      Form1.LabelLM3.Top := Form1.LabelLM1.Top + 180;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.LabelFila.Left := 28;
      Form1.LabelFila.Top := 535;
      Form1.ShapeFila.Top := Form1.LabelFila.Top;
      Form1.ShapeFila.Left := Form1.LabelFila.Left;
      Form1.ShapeFilaNum.Left := Form1.LabelFila.Left + Form1.ShapeFila.Width;
      Form1.ShapeFilaNum.Top := Form1.ShapeFila.Top;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.LabelFila.Left := 61;
      Form1.LabelFila.Top := 515;
      Form1.ShapeFila.Top := Form1.LabelFila.Top;
      Form1.ShapeFila.Left := Form1.LabelFila.Left;
      Form1.ShapeFilaNum.Left := Form1.LabelFila.Left + Form1.ShapeFila.Width;
      Form1.ShapeFilaNum.Top := Form1.ShapeFila.Top;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.LabelFila.Left := 28;
      Form1.LabelFila.Top := 619;
      Form1.ShapeFila.Top := Form1.LabelFila.Top;
      Form1.ShapeFila.Left := Form1.LabelFila.Left;
      Form1.ShapeFilaNum.Left := Form1.LabelFila.Left + Form1.ShapeFila.Width;
      Form1.ShapeFilaNum.Top := Form1.ShapeFila.Top;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.ShapeDisplay.Top := 212;
      Form1.ShapeDisplay.Left := 30;
      Form1.ShapeDisplay.Width := 381;
      Form1.ShapeDisplay.Height := 60;
      Form1.LabelDisplay.Top := Form1.ShapeDisplay.Top + 9;
      Form1.LabelDisplay.Left := Form1.ShapeDisplay.Left + 7;
      Form1.LabelDisplay.Width := 365;
      Form1.LabelDisplay.Height := 45;
      Form1.LabelDisplay.Font.Size := 26;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.ShapeDisplay.Top := 267;
      Form1.ShapeDisplay.Left := 15;
      Form1.ShapeDisplay.Width := 192;
      Form1.ShapeDisplay.Height := 35;
      Form1.LabelDisplay.Top := Form1.ShapeDisplay.Top + 5;
      Form1.LabelDisplay.Left := Form1.ShapeDisplay.Left + 3;
      Form1.LabelDisplay.Width := 185;
      Form1.LabelDisplay.Height := 28;
      Form1.LabelDisplay.Font.Size := 16;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ShapeDisplay.Top := 277;
      Form1.ShapeDisplay.Left := 30;
      Form1.ShapeDisplay.Width := 381;
      Form1.ShapeDisplay.Height := 60;
      Form1.LabelDisplay.Top := Form1.ShapeDisplay.Top + 9;
      Form1.LabelDisplay.Left := Form1.ShapeDisplay.Left + 7;
      Form1.LabelDisplay.Width := 365;
      Form1.LabelDisplay.Height := 45;
      Form1.LabelDisplay.Font.Size := 26;
    end;
    Form1.ImageSetabrgCima.Hide;
    Form1.ImageSetabrgBaixo.Hide;
    if RESOLUCAO = 1024 then begin
      Form1.ImageSetabrgCima.Left := 353;
      Form1.ImageSetabrgCima.Top := 44;
      Form1.ImageSetabrgBaixo.Left := 353;
      Form1.ImageSetabrgBaixo.Top := 622;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.ImageSetabrgCima.Left := 673;
      Form1.ImageSetabrgCima.Top := 44;
      Form1.ImageSetabrgBaixo.Left := 673;
      Form1.ImageSetabrgBaixo.Top := 622;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImageSetabrgCima.Left := 723;
      Form1.ImageSetabrgCima.Top := 44;
      Form1.ImageSetabrgBaixo.Left := 723;
      Form1.ImageSetabrgBaixo.Top := 752;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.ImageSetabrgBaixo.Left := 353;
      Form1.ImageSetabrgBaixo.Top := 44;
      Form1.ImageSetabrgCima.Left := 353;
      Form1.ImageSetabrgCima.Top := 622;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.ImageSetabrgBaixo.Left := 673;
      Form1.ImageSetabrgBaixo.Top := 44;
      Form1.ImageSetabrgCima.Left := 673;
      Form1.ImageSetabrgCima.Top := 622;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImageSetabrgBaixo.Left := 723;
      Form1.ImageSetabrgBaixo.Top := 44;
      Form1.ImageSetabrgCima.Left := 723;
      Form1.ImageSetabrgCima.Top := 752;
    end;
    Form1.CapaMenos1.Top := (local_14 div 4) + 52;
    Form1.CapaMenos1.Left := Form1.CapaSelecionada.Left + -25;
    Form1.CapaMenos1.Height := 160;
    Form1.CapaMenos1.Width := 174;
    Form1.CDMenos1.Top := Form1.CapaMenos1.Top + 8;
    Form1.CDMenos1.Left := Form1.CapaMenos1.Left + 23;
    Form1.CDMenos1.Height := 145;
    Form1.CDMenos1.Width := 145;
    Form1.CapaMenos2.Top := 15;
    Form1.CapaMenos2.Left := Form1.CapaMenos1.Left - (local_c + local_10);
    Form1.CapaMenos2.Height := 160;
    Form1.CapaMenos2.Width := 174;
    Form1.CDMenos2.Top := Form1.CapaMenos2.Top + 8;
    Form1.CDMenos2.Left := Form1.CapaMenos2.Left + 23;
    Form1.CDMenos2.Height := 145;
    Form1.CDMenos2.Width := 145;
    Form1.CapaMenos3.Top := 15;
    Form1.CapaMenos3.Left := Form1.CapaMenos2.Left - (local_c + local_10 * 2);
    Form1.CapaMenos3.Height := 160;
    Form1.CapaMenos3.Width := 174;
    Form1.CDMenos3.Top := Form1.CapaMenos3.Top + 8;
    Form1.CDMenos3.Left := Form1.CapaMenos3.Left + 23;
    Form1.CDMenos3.Height := 145;
    Form1.CDMenos3.Width := 145;
    Form1.CapaMenos4.Top := 15;
    Form1.CapaMenos4.Left := Form1.CapaMenos3.Left - (local_c + local_10 * 2);
    Form1.CapaMenos4.Height := 160;
    Form1.CapaMenos4.Width := 174;
    Form1.CDMenos4.Top := Form1.CapaMenos4.Top + 8;
    Form1.CDMenos4.Left := Form1.CapaMenos4.Left + 23;
    Form1.CDMenos4.Height := 145;
    Form1.CDMenos4.Width := 145;
    Form1.CapaMenos5.Top := 15;
    Form1.CapaMenos5.Left := Form1.CapaMenos4.Left - (local_c + local_10 * 2);
    Form1.CapaMenos5.Height := 160;
    Form1.CapaMenos5.Width := 174;
    Form1.CDMenos5.Top := Form1.CapaMenos5.Top + 8;
    Form1.CDMenos5.Left := Form1.CapaMenos5.Left + 23;
    Form1.CDMenos5.Height := 145;
    Form1.CDMenos5.Width := 145;
    Form1.CapaMais1.Top := (local_14 + 560) - (local_14 div 4);
    Form1.CapaMais1.Left := Form1.CapaSelecionada.Left + -25;
    Form1.CapaMais1.Height := 160;
    Form1.CapaMais1.Width := 174;
    Form1.CDMais1.Top := Form1.CapaMais1.Top + 8;
    Form1.CDMais1.Left := Form1.CapaMais1.Left + 23;
    Form1.CDMais1.Height := 145;
    Form1.CDMais1.Width := 145;
    Form1.CapaMais2.Top := local_14 + 593;
    Form1.CapaMais2.Left := Form1.CapaMais1.Left - (local_c + local_10);
    Form1.CapaMais2.Height := 160;
    Form1.CapaMais2.Width := 174;
    Form1.CDMais2.Top := Form1.CapaMais2.Top + 8;
    Form1.CDMais2.Left := Form1.CapaMais2.Left + 23;
    Form1.CDMais2.Height := 145;
    Form1.CDMais2.Width := 145;
    Form1.CapaMais3.Top := local_14 + 593;
    Form1.CapaMais3.Left := Form1.CapaMais2.Left - (local_c + local_10 * 2);
    Form1.CapaMais3.Height := 160;
    Form1.CapaMais3.Width := 174;
    Form1.CDMais3.Top := Form1.CapaMais3.Top + 8;
    Form1.CDMais3.Left := Form1.CapaMais3.Left + 23;
    Form1.CDMais3.Height := 145;
    Form1.CDMais3.Width := 145;
    Form1.CapaMais4.Top := local_14 + 593;
    Form1.CapaMais4.Left := Form1.CapaMais3.Left - (local_c + local_10 * 2);
    Form1.CapaMais4.Height := 160;
    Form1.CapaMais4.Width := 174;
    Form1.CDMais4.Top := Form1.CapaMais4.Top + 8;
    Form1.CDMais4.Left := Form1.CapaMais4.Left + 23;
    Form1.CDMais4.Height := 145;
    Form1.CDMais4.Width := 145;
    Form1.CapaMais5.Top := local_14 + 593;
    Form1.CapaMais5.Left := Form1.CapaMais4.Left - (local_c + local_10 * 2);
    Form1.CapaMais5.Height := 160;
    Form1.CapaMais5.Width := 174;
    Form1.CDMais5.Top := Form1.CapaMais5.Top + 8;
    Form1.CDMais5.Left := Form1.CapaMais5.Left + 23;
    Form1.CDMais5.Height := 145;
    Form1.CDMais5.Width := 145;
    if RESOLUCAO = 1366 then begin
      Form1.ImagePNG.Left := 2;
      Form1.ImagePNG.Top := 191;
      Form1.ImagePNG.Width := 500;
      Form1.ImagePNG.Height := 400;
      Form1.ImagePNG.BringToFront;
      Form1.ImagePNG.Transparent := True;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImagePNG.Left := 2;
      Form1.ImagePNG.Top := 276;
      Form1.ImagePNG.Width := 500;
      Form1.ImagePNG.Height := 400;
      Form1.ImagePNG.BringToFront;
      Form1.ImagePNG.Transparent := True;
    end;
    Form1.ImagePNG.Hide;
    if RESOLUCAO = 1366 then begin
      Form1.ImageJPG.Left := 38;
      Form1.ImageJPG.Top := 307;
      Form1.ImageJPG.Width := 363;
      Form1.ImageJPG.Height := 207;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.ImageJPG.Left := 19;
      Form1.ImageJPG.Top := 320;
      Form1.ImageJPG.Width := 183;
      Form1.ImageJPG.Height := 160;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImageJPG.Left := 38;
      Form1.ImageJPG.Top := 392;
      Form1.ImageJPG.Width := 363;
      Form1.ImageJPG.Height := 207;
    end;
    Form1.ImageJPG.Hide;
    if RESOLUCAO = 1366 then begin
      Form1.PanelCDTocando.Left := 38;
      Form1.PanelCDTocando.Top := 307;
      Form1.PanelCDTocando.Width := 363;
      Form1.PanelCDTocando.Height := 209;
      Form1.ImageTocando.Align := alClient;
      Form1.ImageCAPATocando.Left := 176;
      Form1.ImageCAPATocando.Top := 3;
      Form1.ImageCDTocando.Left := 199;
      Form1.ImageCDTocando.Top := 11;
      Form1.LabelNomedaMusicaTocando.Left := 4;
      Form1.LabelNomedaMusicaTocando.Top := 165;
      Form1.LabelNomedaMusicaTocando1.Left := 3;
      Form1.LabelNomedaMusicaTocando1.Top := 163;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.PanelCDTocando.Left := 21;
      Form1.PanelCDTocando.Top := 320;
      Form1.PanelCDTocando.Width := 183;
      Form1.PanelCDTocando.Height := 160;
      Form1.ImageTocando.Hide;
      Form1.ImageCAPATocando.Left := 4;
      Form1.ImageCAPATocando.Top := 0;
      Form1.ImageCDTocando.Left := 26;
      Form1.ImageCDTocando.Top := 8;
      Form1.LabelNomedaMusicaTocando.Hide;
      Form1.LabelNomedaMusicaTocando1.Hide;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.PanelCDTocando.Left := 38;
      Form1.PanelCDTocando.Top := 390;
      Form1.PanelCDTocando.Width := 363;
      Form1.PanelCDTocando.Height := 209;
      Form1.ImageTocando.Align := alClient;
      Form1.ImageCAPATocando.Left := 176;
      Form1.ImageCAPATocando.Top := 3;
      Form1.ImageCDTocando.Left := 199;
      Form1.ImageCDTocando.Top := 11;
      Form1.LabelNomedaMusicaTocando.Left := 4;
      Form1.LabelNomedaMusicaTocando.Top := 165;
      Form1.LabelNomedaMusicaTocando1.Left := 3;
      Form1.LabelNomedaMusicaTocando1.Top := 163;
    end;
    Form1.PanelCDTocando.Hide;
    if RESOLUCAO = 1366 then begin
      Form1.ImgLan.Left := 1012;
      Form1.ImgLan.Top := 232;
      Form1.ImgDVD.Left := 1226;
      Form1.ImgDVD.Top := 419;
      Form1.ImgLanMenos1.Left := 982;
      Form1.ImgLanMenos1.Top := 55;
      Form1.ImgLanMenos2.Left := 776;
      Form1.ImgLanMenos2.Top := 18;
      Form1.ImgLanMenos3.Left := 546;
      Form1.ImgLanMenos3.Top := 18;
      Form1.ImgLanMenos4.Left := 316;
      Form1.ImgLanMenos4.Top := 18;
      Form1.ImgLanMenos5.Left := 86;
      Form1.ImgLanMenos5.Top := 18;
      Form1.ImgLanMais1.Left := 982;
      Form1.ImgLanMais1.Top := 563;
      Form1.ImgLanMais2.Left := 776;
      Form1.ImgLanMais2.Top := 596;
      Form1.ImgLanMais3.Left := 546;
      Form1.ImgLanMais3.Top := 596;
      Form1.ImgLanMais4.Left := 316;
      Form1.ImgLanMais4.Top := 596;
      Form1.ImgLanMais5.Left := 86;
      Form1.ImgLanMais5.Top := 596;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.ImgLan.Left := 670;
      Form1.ImgLan.Top := 232;
      Form1.ImgDVD.Left := 884;
      Form1.ImgDVD.Top := 419;
      Form1.ImgLanMenos1.Left := 640;
      Form1.ImgLanMenos1.Top := 55;
      Form1.ImgLanMenos2.Left := 449;
      Form1.ImgLanMenos2.Top := 18;
      Form1.ImgLanMenos3.Left := 239;
      Form1.ImgLanMenos3.Top := 18;
      Form1.ImgLanMenos4.Left := 29;
      Form1.ImgLanMenos4.Top := 18;
      Form1.ImgLanMenos5.Left := -181;
      Form1.ImgLanMenos5.Top := 18;
      Form1.ImgLanMais1.Left := 640;
      Form1.ImgLanMais1.Top := 563;
      Form1.ImgLanMais2.Left := 449;
      Form1.ImgLanMais2.Top := 596;
      Form1.ImgLanMais3.Left := 239;
      Form1.ImgLanMais3.Top := 596;
      Form1.ImgLanMais4.Left := 29;
      Form1.ImgLanMais4.Top := 596;
      Form1.ImgLanMais5.Left := -181;
      Form1.ImgLanMais5.Top := 596;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImgLan.Left := 1086;
      Form1.ImgLan.Top := 298;
      Form1.ImgDVD.Left := 1300;
      Form1.ImgDVD.Top := 485;
      Form1.ImgLanMenos1.Left := 1055;
      Form1.ImgLanMenos1.Top := 87;
      Form1.ImgLanMenos2.Left := 834;
      Form1.ImgLanMenos2.Top := 17;
      Form1.ImgLanMenos3.Left := 574;
      Form1.ImgLanMenos3.Top := 18;
      Form1.ImgLanMenos4.Left := 314;
      Form1.ImgLanMenos4.Top := 18;
      Form1.ImgLanMenos5.Left := 54;
      Form1.ImgLanMenos5.Top := 18;
      Form1.ImgLanMais1.Left := 1055;
      Form1.ImgLanMais1.Top := 661;
      Form1.ImgLanMais2.Left := 834;
      Form1.ImgLanMais2.Top := 727;
      Form1.ImgLanMais3.Left := 574;
      Form1.ImgLanMais3.Top := 727;
      Form1.ImgLanMais4.Left := 314;
      Form1.ImgLanMais4.Top := 727;
      Form1.ImgLanMais5.Left := 54;
      Form1.ImgLanMais5.Top := 727;
    end;
    Form1.ImgLan.Hide;
    Form1.ImgDVD.Hide;
    Form1.ImgLanMenos1.Hide;
    Form1.ImgLanMenos2.Hide;
    Form1.ImgLanMenos3.Hide;
    Form1.ImgLanMenos4.Hide;
    Form1.ImgLanMenos5.Hide;
    Form1.ImgLanMais1.Hide;
    Form1.ImgLanMais2.Hide;
    Form1.ImgLanMais3.Hide;
    Form1.ImgLanMais4.Hide;
    Form1.ImgLanMais5.Hide;
    Form1.Img50.Left := Form1.ImgLan.Left;
    Form1.Img50.Top := Form1.ImgLan.Top;
    Form1.Img50Menos1.Left := Form1.ImgLanMenos1.Left;
    Form1.Img50Menos1.Top := Form1.ImgLanMenos1.Top;
    Form1.Img50Menos2.Left := Form1.ImgLanMenos2.Left;
    Form1.Img50Menos2.Top := Form1.ImgLanMenos2.Top;
    Form1.Img50Menos3.Left := Form1.ImgLanMenos3.Left;
    Form1.Img50Menos3.Top := Form1.ImgLanMenos3.Top;
    Form1.Img50Menos4.Left := Form1.ImgLanMenos4.Left;
    Form1.Img50Menos4.Top := Form1.ImgLanMenos4.Top;
    Form1.Img50Menos5.Left := Form1.ImgLanMenos5.Left;
    Form1.Img50Menos5.Top := Form1.ImgLanMenos5.Top;
    Form1.Img50Mais1.Left := Form1.ImgLanMais1.Left;
    Form1.Img50Mais1.Top := Form1.ImgLanMais1.Top;
    Form1.Img50Mais2.Left := Form1.ImgLanMais2.Left;
    Form1.Img50Mais2.Top := Form1.ImgLanMais2.Top;
    Form1.Img50Mais3.Left := Form1.ImgLanMais3.Left;
    Form1.Img50Mais3.Top := Form1.ImgLanMais3.Top;
    Form1.Img50Mais4.Left := Form1.ImgLanMais4.Left;
    Form1.Img50Mais4.Top := Form1.ImgLanMais4.Top;
    Form1.Img50Mais5.Left := Form1.ImgLanMais5.Left;
    Form1.Img50Mais5.Top := Form1.ImgLanMais5.Top;
    Form1.Img50.Hide;
    Form1.Img50Menos1.Hide;
    Form1.Img50Menos2.Hide;
    Form1.Img50Menos3.Hide;
    Form1.Img50Menos4.Hide;
    Form1.Img50Menos5.Hide;
    Form1.Img50Mais1.Hide;
    Form1.Img50Mais2.Hide;
    Form1.Img50Mais3.Hide;
    Form1.Img50Mais4.Hide;
    Form1.Img50Mais5.Hide;
    if RESOLUCAO = 1366 then begin
      Form1.ImageSetasPaginacao1.Left := 810;
      Form1.ImageSetasPaginacao1.Top := 135;
      Form1.ImageSetasPaginacao1.Width := 210;
      Form1.ImageSetasPaginacao1.Height := 500;
      Form1.ImageSetasPaginacao2.Left := 810;
      Form1.ImageSetasPaginacao2.Top := 135;
      Form1.ImageSetasPaginacao2.Width := 210;
      Form1.ImageSetasPaginacao2.Height := 500;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.ImageSetasPaginacao1.Left := 468;
      Form1.ImageSetasPaginacao1.Top := 135;
      Form1.ImageSetasPaginacao1.Width := 210;
      Form1.ImageSetasPaginacao1.Height := 500;
      Form1.ImageSetasPaginacao2.Left := 468;
      Form1.ImageSetasPaginacao2.Top := 135;
      Form1.ImageSetasPaginacao2.Width := 210;
      Form1.ImageSetasPaginacao2.Height := 500;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImageSetasPaginacao1.Left := 850;
      Form1.ImageSetasPaginacao1.Top := 155;
      Form1.ImageSetasPaginacao1.Width := 240;
      Form1.ImageSetasPaginacao1.Height := 600;
      Form1.ImageSetasPaginacao2.Left := 850;
      Form1.ImageSetasPaginacao2.Top := 155;
      Form1.ImageSetasPaginacao2.Width := 240;
      Form1.ImageSetasPaginacao2.Height := 600;
    end;
    Form1.ImageSetasPaginacao1.Hide;
    Form1.ImageSetasPaginacao2.Hide;
  end;
end;

{ JUKELINUX1_TELA_DE_AUTOTESTE }
procedure Tela_De_Autoteste;
var
  local_4b0, local_4b4, local_4b8, local_4bc, local_4c0, local_4c4, local_68c, local_78c, local_790, local_794, local_798, local_79c, local_7a0: AnsiString;
  cVar1: Boolean;
  iVar3, local_4c8, local_658, local_65c, local_660, local_8, local_c: LongInt;
  local_25c, local_4ac: Text;
begin
  begin
    Form1.PanelAutoTeste.Width := 637;
    Form1.PanelAutoTeste.Height := 567;
    iVar3 := RESOLUCAO - Form1.PanelAutoTeste.Width;
    // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.PanelAutoTeste,(int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1);
    iVar3 := Form1.Height - Form1.PanelAutoTeste.Height;
    // C: CONTROLS_TCONTROL____SETTOP_LONGINT (Form1.PanelAutoTeste,(int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1);
    Form1.PanelAutoTeste.Show;
    local_68c := PASTA + 'autoteste1.txt';
    cVar1 := FileExists(local_68c);
    if not cVar1 then begin
      Form1.LabelLendo.Caption := 'Aguarde o Auto Teste dos CDS';
      // C: ( **(code ** )( *(int * )Form1.LabelLendo + 0x2fc))(Form1.LabelLendo);
      FORM1.Refresh;
      // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      local_794 := PASTA + 'autoteste1.txt';
      local_78c := local_794;
      AssignFile(ARQTEXTO, local_78c);
      Rewrite(ARQTEXTO);
      iVar3 := TOTALCDS;
      local_8 := 1;
      if 0 < TOTALCDS then begin
        repeat
          local_8 := local_8 + 1;
          local_794 := IntToStr(local_8);
          Write(ARQTEXTO, local_794);
          Writeln(ARQTEXTO);
          // C: fpc_write_text_ansistr (0,U_JUKELINUX1_ARQTEXTO, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8));
          Writeln(ARQTEXTO);
          Write(ARQTEXTO, 120);
          Writeln(ARQTEXTO);
        until not (local_8 < iVar3);
      end;
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      local_794 := PASTA + 'autoteste2.txt';
      local_78c := local_794;
      AssignFile(ARQTEXTO, local_78c);
      Rewrite(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      iVar3 := TOTALCDS;
      local_8 := 1;
      if 0 < TOTALCDS then begin
        repeat
          local_8 := local_8 + 1;
          local_794 := PASTA + 'autoteste2.txt';
          local_78c := local_794;
          AssignFile(ARQTEXTO, local_78c);
          Append(ARQTEXTO);
          local_794 := IntToStr(local_8);
          Write(ARQTEXTO, local_794);
          Writeln(ARQTEXTO);
          // C: fpc_write_text_ansistr (0,U_JUKELINUX1_ARQTEXTO, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8));
          Writeln(ARQTEXTO);
          // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.LabelAT2, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8));
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageAT1.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x200));
          // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageAT2.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x204));
          Write(ARQTEXTO, 'ok');
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
        until not (local_8 < iVar3);
      end;
      local_79c := PASTA + 'autoteste1.txt';
      // C: puVar5 = local_79c;
      if False { C: local_79c == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar5,&local_794);
      DeleteFile(local_794);
      local_7a0 := PASTA + 'autoteste2.txt';
      // C: puVar5 = local_7a0;
      if False { C: local_7a0 == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar5,&local_794);
      DeleteFile(local_794);
      Form1.PanelAutoTeste.Hide;
    end
    else begin
      local_68c := PASTA + 'autoteste1.txt';
      cVar1 := FileExists(local_68c);
      if cVar1 then begin
        local_68c := PASTA + 'autoteste2.txt';
        cVar1 := FileExists(local_68c);
        if cVar1 then begin
          Form1.LabelAT3.Caption := 'Aguarde, Excluindo CD com Erro';
          local_68c := PASTA + 'autoteste1.txt';
          local_78c := local_68c;
          AssignFile(local_25c, local_78c);
          Reset(local_25c);
          local_68c := PASTA + 'autoteste2.txt';
          local_78c := local_68c;
          AssignFile(local_4ac, local_78c);
          Reset(local_4ac);
          while True do begin
            cVar1 := Eof(local_4ac);
            if cVar1 then begin Break; end;
            Read(local_25c, local_4b0);
            Readln(local_25c);
            Read(local_25c, local_4b4);
            Readln(local_25c);
            Read(local_25c, local_4b8);
            Readln(local_25c);
            Read(local_4ac, local_4bc);
            Readln(local_4ac);
            Read(local_4ac, local_4c0);
            Readln(local_4ac);
            Read(local_4ac, local_4c4);
            Readln(local_4ac);
            local_c := local_c + 1;
          end;
          CloseFile(local_25c);
          CloseFile(local_4ac);
          if local_c < TOTALCDS then begin
            local_660 := local_c + 1;
            // C: fpc_ansistr_concat(&local_790,"CD/DVD com Erro:", *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_660 * 0x240 + 0x1f8));
            Form1.LabelAT2.Caption := local_790;
            // C: ( **(code ** )( *(int * )Form1.LabelAT2 + 0x2fc))(Form1.LabelAT2);
            // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_660 * 0x240 + 0x1f8));
            iVar3 := Form1.FileListBox1.Count;
            if -1 < iVar3 + -1 then begin
              local_4c8 := -1;
              repeat
                local_4c8 := local_4c8 + 1;
                local_68c := Form1.FileListBox1.Items[local_4c8];
                if False { C: STRNE(local_68c[0],"[.]") } then begin
                  local_68c := Form1.FileListBox1.Items[local_4c8];
                  if False { C: STRNE(local_68c[0],"[..]") } then begin
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_4c8, &local_794);
                    // C: fpc_ansistr_concat(local_68c, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_660 * 0x240 + 0x1f8),local_794);
                    cVar1 := FileExists(local_68c);
                    if cVar1 then begin
                      local_65c := local_65c + 1;
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_4c8, &local_794);
                      // C: fpc_ansistr_concat(local_658 + local_65c * 4 + -4, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + local_660 * 0x240 + 0x1f8), local_794);
                    end;
                  end;
                end;
              until not (local_4c8 < iVar3 + -1);
            end;
            iVar3 := local_65c;
            local_4c8 := 1;
            if 0 < local_65c then begin
              repeat
                local_4c8 := local_4c8 + 1;
                // C: SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN ( *(undefined4 * )(local_658 + local_4c8 * 4 + -4));
              until not (local_4c8 < iVar3);
            end;
            // C: SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_660 * 0x240 + 0x1f8));
            // C: fpc_ansistr_concat(&local_794,"AUTO TESTE - Apagado o CD com Erro - ", *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_660 * 0x240 + 0x1f8));
            Gravalog(local_794);
            local_68c := PASTA + 'autoteste1.txt';
            // C: puVar5 = local_68c[0];
            if False { C: local_68c[0] == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar5,&local_794);
            DeleteFile(local_794);
            local_798 := PASTA + 'autoteste2.txt';
            // C: puVar5 = local_798;
            if False { C: local_798 == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar5,&local_794);
            DeleteFile(local_794);
            Carregando_Cds;
            Form1.PanelAutoTeste.Hide;
          end;
        end;
      end;
    end;
  end;
end;

{ JUKELINUX1_TEM_2X_MUSICA_NA_FILA$$BOOLEAN }
function Tem_2X_Musica_Na_Fila: Boolean;
var
  local_10, local_14, local_140, local_40, local_c: AnsiString;
  cVar1: Boolean;
  iVar2, iVar3, iVar4, local_8: LongInt;
begin
  // C: iVar2 = fpc_setjmp();
  iVar3 := MUSICASELECIONADA;
  if iVar2 = 0 then begin
    iVar4 := (KMAT + 5) * 576;
    // C: local_c = *(undefined4 * )(iVar4 + 0x8e91144 + iVar3 * 4);
    local_40 := PASTA + 'tocando.txt';
    cVar1 := FileExists(local_40);
    if not cVar1 then begin
    end
    else begin
      local_40 := PASTA + 'tocando.txt';
      local_140 := local_40;
      AssignFile(ARQTEXTO, local_140);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, local_14);
      Readln(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    local_40 := PASTA + 'tocar.txt';
    cVar1 := FileExists(local_40);
    if cVar1 then begin
      local_40 := PASTA + 'tocar.txt';
      local_140 := local_40;
      AssignFile(ARQTOCAR, local_140);
      Reset(ARQTOCAR);
      while True do begin
        cVar1 := Eof(ARQTOCAR);
        if cVar1 then begin Break; end;
        Read(ARQTOCAR, local_10);
        Readln(ARQTOCAR);
      end;
      CloseFile(ARQTOCAR);
    end;
    iVar3 := 0;
    if local_14 <> '' then begin
      // C: iVar3 = *(int * )(local_14 + -4);
    end;
    if 0 < iVar3 then begin
      iVar3 := 0;
      if local_10 <> '' then begin
        // C: iVar3 = *(int * )(local_10 + -4);
      end;
      if iVar3 = 0 then begin
        if local_14 = local_c then begin
          local_8 := 1;
        end;
      end;
    end;
    iVar3 := 0;
    if local_10 <> '' then begin
      // C: iVar3 = *(int * )(local_10 + -4);
    end;
    if 0 < iVar3 then begin
      if local_10 = local_c then begin
        local_8 := 1;
      end;
    end;
  end;
  if iVar2 <> 0 then begin
  end;
  Result := local_8 <> 0; Exit;
end;

{ JUKELINUX1_VOLTAMENU }
procedure Voltamenu;
begin
  Form1.PanelMenu1c.Hide;
  Form1.PanelMenu1grande.Hide;
  Form1.PanelMenu1grande.Left := 237;
  Form1.PanelMenu1grande.Top := 30;
  if RESOLUCAO = 1024 then begin
    Form1.PanelMenu1grande.Width := 753;
    Form1.PanelMenu1grande.Height := 702;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.PanelMenu1grande.Width := 1095;
    Form1.PanelMenu1grande.Height := 702;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.PanelMenu1grande.Width := 1170;
    Form1.PanelMenu1grande.Height := 837;
  end;
  Form1.LabelSairDoMenu1.Top := 10;
  if RESOLUCAO = 1024 then begin
    Form1.LabelSairDoMenu1.Left := 489;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.LabelSairDoMenu1.Left := 837;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.LabelSairDoMenu1.Left := 902;
  end;
  Form1.LabelSairDoMenu1.Left := 489;
  Form1.PanelMenu2c.Hide;
  Form1.PanelMenu2grande.Hide;
  Form1.PanelMenu2grande.Left := 237;
  Form1.PanelMenu2grande.Top := 30;
  if RESOLUCAO = 1024 then begin
    Form1.PanelMenu2grande.Width := 753;
    Form1.PanelMenu2grande.Height := 702;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.PanelMenu2grande.Width := 1095;
    Form1.PanelMenu2grande.Height := 702;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.PanelMenu2grande.Width := 1170;
    Form1.PanelMenu2grande.Height := 837;
  end;
  Form1.LabelSairDoMenu2.Top := 10;
  if RESOLUCAO = 1024 then begin
    Form1.LabelSairDoMenu2.Left := 489;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.LabelSairDoMenu2.Left := 837;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.LabelSairDoMenu2.Left := 902;
  end;
  Form1.LabelSairDoMenu2.Left := 489;
  Form1.PanelMenu3c.Hide;
  Form1.PanelMenu3grande.Hide;
  Form1.PanelMenu3grande.Left := 237;
  Form1.PanelMenu3grande.Top := 30;
  if RESOLUCAO = 1024 then begin
    Form1.PanelMenu3grande.Width := 753;
    Form1.PanelMenu3grande.Height := 702;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.PanelMenu3grande.Width := 1095;
    Form1.PanelMenu3grande.Height := 702;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.PanelMenu3grande.Width := 1170;
    Form1.PanelMenu3grande.Height := 837;
  end;
  Form1.LabelSairDoMenu3.Top := 10;
  if RESOLUCAO = 1024 then begin
    Form1.LabelSairDoMenu3.Left := 489;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.LabelSairDoMenu3.Left := 837;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.LabelSairDoMenu3.Left := 902;
  end;
  Form1.PanelMenu4c.Hide;
  Form1.PanelMenu4grande.Hide;
  Form1.PanelMenu4grande.Left := 237;
  Form1.PanelMenu4grande.Top := 30;
  if RESOLUCAO = 1024 then begin
    Form1.PanelMenu4grande.Width := 753;
    Form1.PanelMenu4grande.Height := 702;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.PanelMenu4grande.Width := 1095;
    Form1.PanelMenu4grande.Height := 702;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.PanelMenu4grande.Width := 1170;
    Form1.PanelMenu4grande.Height := 837;
  end;
  Form1.LabelSairDoMenu4.Top := 10;
  if RESOLUCAO = 1024 then begin
    Form1.LabelSairDoMenu4.Left := 489;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.LabelSairDoMenu4.Left := 837;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.LabelSairDoMenu4.Left := 902;
  end;
  Form1.PanelMenu5c.Hide;
  Form1.PanelMenu5grande.Hide;
  Form1.PanelMenu5grande.Left := 237;
  Form1.PanelMenu5grande.Top := 30;
  if RESOLUCAO = 1024 then begin
    Form1.PanelMenu5grande.Width := 753;
    Form1.PanelMenu5grande.Height := 702;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.PanelMenu5grande.Width := 1095;
    Form1.PanelMenu5grande.Height := 702;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.PanelMenu5grande.Width := 1170;
    Form1.PanelMenu5grande.Height := 837;
  end;
  Form1.LabelSairDoMenu5.Top := 10;
  if RESOLUCAO = 1024 then begin
    Form1.LabelSairDoMenu5.Left := 489;
  end;
  if RESOLUCAO = 1366 then begin
    Form1.LabelSairDoMenu5.Left := 837;
  end;
  if RESOLUCAO = 1440 then begin
    Form1.LabelSairDoMenu5.Left := 902;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS0CLICK$TOBJECT }
procedure TForm1.BS0Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '0';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS10CLICK$TOBJECT }
procedure TForm1.BS10Click(Sender: TObject);
begin
  // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.EditSenha,0,param_3,Self,Sender);
end;

{ JUKELINUX1_TFORM1_$__BS1CLICK$TOBJECT }
procedure TForm1.BS1Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '1';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS2CLICK$TOBJECT }
procedure TForm1.BS2Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '2';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS3CLICK$TOBJECT }
procedure TForm1.BS3Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '3';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS4CLICK$TOBJECT }
procedure TForm1.BS4Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '4';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS5CLICK$TOBJECT }
procedure TForm1.BS5Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '5';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS6CLICK$TOBJECT }
procedure TForm1.BS6Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '6';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS7CLICK$TOBJECT }
procedure TForm1.BS7Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '7';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS8CLICK$TOBJECT }
procedure TForm1.BS8Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '8';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BS9CLICK$TOBJECT }
procedure TForm1.BS9Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_3c);
    local_38 := local_3c + '9';
    Form1.EditSenha.Caption := local_38;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTON1CLICK$TOBJECT }
procedure TForm1.Button1Click(Sender: TObject);
var
  local_3c: AnsiString;
  local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    FOTOPNG := FOTOPNG + 1;
    if FOTOPNG = 5 then begin
      FOTOPNG := 1;
    end;
    if FOTOPNG = 1 then begin
      local_3c := PASTA + 'png1.png';
      Form1.ImageGrandePng.Picture.LoadFromFile(local_3c);
    end;
    if FOTOPNG = 2 then begin
      local_3c := PASTA + 'png2.png';
      Form1.ImageGrandePng.Picture.LoadFromFile(local_3c);
    end;
    if FOTOPNG = 3 then begin
      local_3c := PASTA + 'png3.png';
      Form1.ImageGrandePng.Picture.LoadFromFile(local_3c);
    end;
    if FOTOPNG = 4 then begin
      local_3c := PASTA + 'png4.png';
      Form1.ImageGrandePng.Picture.LoadFromFile(local_3c);
    end;
    Form1.ImageGrandePng.BringToFront;
    Form1.ImageGrandePng.Top := 0;
    Form1.ImageGrandePng.Width := 1366;
    Form1.ImageGrandePng.Height := 768;
    Form1.ImageGrandePng.Left := -1366;
    Form1.ImageGrandePng.Show;
    repeat
      local_10 := local_10 + 1;
      Form1.ImageGrandePng.Left := Form1.ImageGrandePng.Left + 10;
    until not (local_10 < 136);
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONATIVARCLICK$TOBJECT }
procedure TForm1.ButtonAtivarClick(Sender: TObject);
label
  LAB_080cc102;
var
  local_17c, local_180, local_184, local_188, local_18c, local_198, local_1c, local_20, local_24, local_28, local_28c, local_2c, local_30, local_34, local_38, local_3c, local_40, local_44, local_48, local_78, local_7c, local_88, local_8c, uVar1: AnsiString;
  iVar3, local_10, local_4c: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_190, local_194, local_290, local_80, local_84: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    local_48 := Copy(FORMULACONTRASENHA, 1, 2);
    local_4c := StrToIntDef(local_48, 3);
    local_4c := local_4c + 1;
    // C: puVar6 = local_1c;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenhaAtivacao,local_78);
    // C: fpc_ansistr_copy(local_78[0],local_4c,4,puVar6);
    local_20 := Copy(local_1c, 1, 2);
    local_24 := Copy(local_1c, 3, 2);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelAtivacao2,local_78);
    // C: local_4c = SYSTEM_POS_CHAR_ANSISTRING__LONGINT(0x2d,local_78[0]);
    local_4c := local_4c + 1;
    // C: ppuVar7 = &local_30;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelAtivacao2,local_78);
    // C: fpc_ansistr_copy(local_78[0],local_4c,2,ppuVar7);
    // C: ppuVar7 = &local_34;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelAtivacao2,local_78);
    // C: fpc_ansistr_copy(local_78[0],local_4c + 2,2,ppuVar7);
    // C: ppuVar7 = &local_38;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelAtivacao2,local_78);
    // C: fpc_ansistr_copy(local_78[0],local_4c + 5,2,ppuVar7);
    // C: ppuVar7 = &local_3c;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelAtivacao2,local_78);
    // C: fpc_ansistr_copy(local_78[0],local_4c + 7,2,ppuVar7);
    // C: ppuVar7 = &local_40;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelAtivacao2,local_78);
    // C: fpc_ansistr_copy(local_78[0],local_4c + 10,2,ppuVar7);
    // C: ppuVar7 = &local_44;
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelAtivacao2,local_78);
    // C: fpc_ansistr_copy(local_78[0],local_4c + 0xc,2,ppuVar7);
    local_78 := Copy(FORMULACONTRASENHA, 3, 1);
    if local_78 = '1' then begin
      local_78 := Copy(FORMULACONTRASENHA, 4, 1);
      if local_78 = '=' then begin
        local_28 := local_30;
      end;
      local_78 := Copy(FORMULACONTRASENHA, 4, 1);
      if local_78 = '/' then begin
        iVar3 := StrToIntDef(local_30, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_28 := IntToStr(local_10);
      end;
      local_78 := Copy(FORMULACONTRASENHA, 4, 1);
      if local_78 = 'x' then begin
        local_78 := Copy(local_30, 1, 1);
        // C: uVar1 = local_78[0];
        local_7c := Copy(local_30, 2, 1);
        local_28 := local_7c + uVar1;
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 3, 1);
    if local_7c = '2' then begin
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '=' then begin
        local_28 := local_34;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_34, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_28 := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_34, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_34, 2, 1);
        // C: fpc_ansistr_concat(&local_28,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 3, 1);
    if local_7c = '3' then begin
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '=' then begin
        local_28 := local_38;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_38, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_28 := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_38, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_38, 2, 1);
        // C: fpc_ansistr_concat(&local_28,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 3, 1);
    if local_7c = '4' then begin
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '=' then begin
        local_28 := local_3c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_3c, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_28 := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_3c, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_3c, 2, 1);
        // C: fpc_ansistr_concat(&local_28,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 3, 1);
    if local_7c = '5' then begin
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '=' then begin
        local_28 := local_40;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_40, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_28 := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_40, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_40, 2, 1);
        // C: fpc_ansistr_concat(&local_28,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 3, 1);
    if local_7c = '6' then begin
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '=' then begin
        local_28 := local_44;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_44, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_28 := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 4, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_44, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_44, 2, 1);
        // C: fpc_ansistr_concat(&local_28,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 5, 1);
    if local_7c = '1' then begin
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '=' then begin
        local_2c := local_30;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_30, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_2c := IntToStr(local_10);
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_30, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_30, 2, 1);
        // C: fpc_ansistr_concat(&local_2c,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 5, 1);
    if local_7c = '2' then begin
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '=' then begin
        local_2c := local_34;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_34, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_2c := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_34, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_34, 2, 1);
        // C: fpc_ansistr_concat(&local_2c,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 5, 1);
    if local_7c = '3' then begin
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '=' then begin
        local_2c := local_38;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_38, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_2c := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_38, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_38, 2, 1);
        // C: fpc_ansistr_concat(&local_2c,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 5, 1);
    if local_7c = '4' then begin
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '=' then begin
        local_2c := local_3c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_3c, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_2c := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_3c, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_3c, 2, 1);
        // C: fpc_ansistr_concat(&local_2c,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 5, 1);
    if local_7c = '5' then begin
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '=' then begin
        local_2c := local_40;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_40, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_2c := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_40, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_40, 2, 1);
        // C: fpc_ansistr_concat(&local_2c,local_78[0],puVar5);
      end;
    end;
    local_7c := Copy(FORMULACONTRASENHA, 5, 1);
    if local_7c = '6' then begin
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '=' then begin
        local_2c := local_44;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = '/' then begin
        iVar3 := StrToIntDef(local_44, 50);
        // C: local_10 = (int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1;
        local_7c := IntToStr(local_10);
        local_2c := local_7c;
      end;
      local_7c := Copy(FORMULACONTRASENHA, 6, 1);
      if local_7c = 'x' then begin
        local_7c := Copy(local_44, 1, 1);
        // C: puVar5 = local_7c;
        local_78 := Copy(local_44, 2, 1);
        // C: fpc_ansistr_concat(&local_2c,local_78[0],puVar5);
      end;
    end;
    if local_20 = local_28 then begin
      if local_24 = local_2c then begin
        if ATIVACAO = 'pendrive' then begin
          NOMEARQ := PASTA + 'jukelinux.ini';
          local_17c := NOMEARQ;
          AssignFile(ARQTEXTO, local_17c);
          Rewrite(ARQTEXTO);
          local_7c := Cripta(JC_SERIALPENDRIVE);
          Write(ARQTEXTO, local_7c);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          // C: local_88 = "Contra Senha Correta, Gravado a Nova Chave do PenDrive na HD [";
          local_84 := JC_SERIALPENDRIVE;
          local_80 := ']';
          local_7c := local_88 + local_84 + local_80;
          Gravalog(local_7c);
          if JC_RELOGIOTOTALSTR <> '0' then begin
            Gravalog('ROTINA EXECUTADA APOS ATIVACAO DE PENDRIVE NOVO - ANTES DE DESLIGAR');
            Gravalog('ATENCAO: Foi Mudado de PENDRIVE CHAVE');
            local_8c := 'PenDrive Novo=';
            local_88 := JC_SERIALPENDRIVE;
            local_84 := '  PenDrive Anterior=';
            // C: local_80 = (char * )U_JUKELINUX1_JC_INI;
            local_7c := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_7c);
            // C: local_88 = "Relógios do PenDrive [";
            local_84 := JC_SERIALPENDRIVE;
            local_80 := '] Sao Diferentes dos Relogios da Jukebox';
            local_7c := local_88 + local_84 + local_80;
            Gravalog(local_7c);
            Gravalog('                   Jukebox   PenDrive');
            local_8c := 'Relogio Total....: ';
            local_180 := Strzero(RELOGIOTOTALSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_184 := Strzero(JC_RELOGIOTOTALSTR, 6);
            // C: local_80 = (char * )local_184;
            local_7c := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_7c);
            local_8c := 'Relogio Parcial..: ';
            local_180 := Strzero(RELOGIOPARCIALSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_7c := Strzero(JC_RELOGIOPARCIALSTR, 6);
            local_80 := local_7c;
            local_184 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_184);
            local_8c := 'Relogio Gratis...: ';
            local_180 := Strzero(RELOGIOGRATISSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_7c := Strzero(JC_RELOGIOGRATISSTR, 6);
            local_80 := local_7c;
            local_184 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_184);
            local_8c := 'Relogio GratisVIP: ';
            local_180 := Strzero(RELOGIOGRATISVIPSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_7c := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
            local_80 := local_7c;
            local_184 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_184);
            RELOGIOTOTALSTR := JC_RELOGIOTOTALSTR;
            RELOGIOPARCIALSTR := JC_RELOGIOPARCIALSTR;
            PORCENTAGEMDOPONTOSTR := JC_PORCENTAGEMDOPONTOSTR;
            RELOGIOGRATISSTR := JC_RELOGIOGRATISSTR;
            RELOGIOGRATISVIPSTR := JC_RELOGIOGRATISVIPSTR;
            RELOGIOTOTAL := StrToIntDef(RELOGIOTOTALSTR, 0);
            RELOGIOPARCIAL := StrToIntDef(RELOGIOPARCIALSTR, 0);
            PORCENTAGEMDOPONTO := StrToIntDef(PORCENTAGEMDOPONTOSTR, 30);
            RELOGIOGRATIS := StrToIntDef(RELOGIOGRATISSTR, 0);
            RELOGIOGRATISVIP := StrToIntDef(RELOGIOGRATISVIPSTR, 0);
            Grava_Hd_Relogios;
            Grava_Hd_Porcentagem;
            Grava_Hd_Relogiogratis;
            Grava_Hd_Relogiogratisvip;
            Gravalog('Ajustado os Relogios da jukebox');
            Gravalog('                   Jukebox   PenDrive');
            local_8c := 'Relogio Total....: ';
            local_180 := Strzero(RELOGIOTOTALSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_7c := Strzero(JC_RELOGIOTOTALSTR, 6);
            local_80 := local_7c;
            local_184 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_184);
            local_8c := 'Relogio Parcial..: ';
            local_180 := Strzero(RELOGIOPARCIALSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_7c := Strzero(JC_RELOGIOPARCIALSTR, 6);
            local_80 := local_7c;
            local_184 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_184);
            local_8c := 'Relogio Gratis...: ';
            local_180 := Strzero(RELOGIOGRATISSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_7c := Strzero(JC_RELOGIOGRATISSTR, 6);
            local_80 := local_7c;
            local_184 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_184);
            local_8c := 'Relogio GratisVIP: ';
            local_180 := Strzero(RELOGIOGRATISVIPSTR, 6);
            local_88 := local_180;
            local_84 := '    ';
            local_7c := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
            local_80 := local_7c;
            local_184 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_184);
          end;
          if SEMPENDRIVE = 0 then begin
            local_180 := PASTACHAVE + 'creditos.txt';
            // C: pcVar4 = local_180;
            if False { C: local_180 == (char * )0x0 } then begin
              // C: pcVar4 = &FPC_EMPTYCHAR;
            end;
            // C: fpc_pchar_to_ansistr(pcVar4,&local_184);
            DeleteFile(local_184);
            local_7c := PASTACHAVE + 'tocar.txt';
            // C: puVar5 = local_7c;
            if False { C: local_7c == (undefined * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar5,&local_184);
            DeleteFile(local_184);
          end;
          CREDITOS := 0;
          NOMEARQ := PASTA + 'creditos.txt';
          local_17c := NOMEARQ;
          AssignFile(ARQTEXTO, local_17c);
          Rewrite(ARQTEXTO);
          local_188 := IntToStr(CREDITOS);
          local_184 := Cripta(local_188);
          Write(ARQTEXTO, local_184);
          Writeln(ARQTEXTO);
          local_188 := Cripta(JC_SERIALPENDRIVE);
          Write(ARQTEXTO, local_188);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          local_18c := IntToStr(CREDITOS);
          Form1.LabelCreditos.Caption := local_18c;
          Form1.LabelCreditos.Font.Color := 65280;
          // C: JUKELINUX1_TFORM1____BUTTONZERARFILACLICK_TOBJECT(local_c,U_JUKELINUX1_FORM1);
          Form1.PanelErro.Align := alClient;
          Form1.LabelErro1.Caption := 'Ativação';
          Form1.LabelErro2.Caption := 'OK';
          ERROSERIAL := 'Ativação OK, Desligue e Ligue a Jukebox';
          Form1.MemoErro.Caption := 'Ativação OK, Desligue e Ligue a Jukebox';
          Form1.PanelErro.Show;
          Form1.PanelErro.BringToFront;
        end;
        if ATIVACAO = 'livre' then begin
          local_188 := PASTA + 'reaisxmusicas.txt';
          local_28c := local_188;
          AssignFile(ARQTEXTO, local_28c);
          Rewrite(ARQTEXTO);
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.ComboBox1,&local_188);
          REAISXMUSICAS := local_188;
          // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          // C: local_198 = "Alteracao no Menu - ReaisXMusicas = [";
          local_194 := REAISXMUSICAS;
          local_190 := '] com Digitacao de Contra Senha Correta';
          local_188 := local_198 + local_194 + local_190;
          Gravalog(local_188);
        end;
        Form1.PanelAtivacao.Hide;
        goto LAB_080cc102;
      end;
    end;
    // C: local_198 = "Numero Digitado Errado [";
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenhaAtivacao,&local_290);
    local_194 := local_290;
    local_190 := ']';
    local_188 := local_198 + local_194 + local_190;
    Gravalog(local_188);
    ShowMessage('Número Errado...');
    Form1.EditSenhaAtivacao.Caption := '';
  end;
  LAB_080cc102: ;
end;

{ JUKELINUX1_TFORM1_$__BUTTONCARREGARCDCLICK$TOBJECT }
procedure TForm1.ButtonCarregarCDClick(Sender: TObject);
var
  local_1fa0, local_1fa8, local_1fac, local_1fb0: AnsiString;
  local_c: TForm1;
  local_8: TObject;
  local_1fa4: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Form1.PanelCarregarMusica.Left := 20;
    Form1.PanelCarregarMusica.Top := 59;
    Form1.PanelCarregarMusica.Width := 704;
    Form1.PanelCarregarMusica.Height := 614;
    Form1.PanelCarregarMusica.Show;
    Form1.PanelCarregarMusica.BringToFront;
    Form1.ButtonMusCarregar.Visible := True;
    Form1.ButtonMusCarregar.Caption := 'Carregar CDs/DVDs Novos';
    // C: local_1fac = "Quantidade de Dias a Partir de Hoje [";
    local_1fb0 := DateToStr(Date);
    local_1fa8 := local_1fb0;
    local_1fa4 := '] para os CDs/DVDs que Serão Carregados Permanecerem no Gênero Lançamentos';
    local_1fa0 := local_1fac + local_1fa8 + local_1fa4;
    Form1.LabelMusDias.Caption := local_1fa0;
    Form1.LabelMusHD.Hide;
    Form1.LabelMusAtu.Hide;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONCOQRCODECLICK$TOBJECT }
procedure TForm1.ButtonCOQrCodeClick(Sender: TObject);
begin
  Form1.PanelCadastro.Hide;
  ALTERANDOFRASES := 0;
  // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x430))(U_JUKELINUX1_FORM1);
end;

{ JUKELINUX1_TFORM1_$__BUTTONEA1CLICK$TOBJECT }
procedure TForm1.ButtonEA1Click(Sender: TObject);
var
  local_1d0, local_1d4: AnsiString;
  cVar1: Boolean;
  iVar3, local_10, local_1a4, local_1b0, uVar5: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Form1.FileListBox1.Directory := CDSELEAPAGAR;
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_1d0 := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_1d0[0],"[.]") } then begin
          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_10, local_1d0);
          if False { C: STRNE(local_1d0[0],"[..]") } then begin
            // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_10, &local_1d4);
            local_1d0 := CDSELEAPAGAR + local_1d4;
            cVar1 := FileExists(local_1d0);
            if cVar1 then begin
              local_1a4 := local_1a4 + 1;
              // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_10, &local_1d4);
              // ?: local_1b0 + local_1a4 * 4 + 12 := CDSELEAPAGAR + local_1d4;
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    iVar3 := local_1a4;
    local_10 := 1;
    if 0 < local_1a4 then begin
      repeat
        local_10 := local_10 + 1;
        // C: SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN( *(undefined4 * )(local_1b0 + local_10 * 4 + 0xc));
      until not (local_10 < iVar3);
    end;
    RemoveDir(CDSELEAPAGAR);
    local_1d4 := 'Apagado CD pela Lista- ' + CDSELEAPAGAR;
    Gravalog(local_1d4);
    RELECDS := 1;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ListBoxRCds + 0x364) + 0x80)) (Form1.ListBoxRCds.Items);
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        // C: puVar6 = &local_1d4;
        // C: ( **(code ** )( **(int ** )(Form1.ListBoxRCds + 0x364) + 0x78)) (Form1.ListBoxRCds.Items,local_10,local_1d0, puVar6);
        // C: uVar5 = 0;
        if local_1d0 <> '' then begin
          // C: uVar5 = *(undefined4 * )(local_1d0[0] + -4);
        end;
        local_1d0 := Form1.ListBoxRCds.Items[local_10];
        // C: fpc_ansistr_copy(local_1d0[0],10,uVar5,puVar6);
        if local_1d4 = CDSELEAPAGARX then begin
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRCds + 0x364) + 0x8c)) (Form1.ListBoxRCds.Items,local_10, "--------------");
        end;
      until not (local_10 < iVar3 + -1);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONEACLICK$TOBJECT }
procedure TForm1.ButtonEAClick(Sender: TObject);
var
  local_138, local_13c: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ListBoxRAtivo + 0x364) + 0x80)) (Form1.ListBoxRAtivo.Items);
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        // C: cVar1 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN (Form1.ListBoxRAtivo,local_10);
        if cVar1 then begin
          local_13c := PASTA + 'ritmosinativos.txt';
          local_138 := local_13c;
          AssignFile(ARQTEXTO, local_138);
          Append(ARQTEXTO);
          local_13c := Form1.ListBoxRAtivo.Items[local_10];
          Write(ARQTEXTO, local_13c);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRAtivo + 0x364) + 0x8c)) (Form1.ListBoxRAtivo.Items,local_10,"-----" );
          RELECDS := 1;
        end;
      until not (local_10 < iVar3 + -1);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONEICLICK$TOBJECT }
procedure TForm1.ButtonEIClick(Sender: TObject);
var
  local_138, local_13c: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0x80)) (Form1.ListBoxRInativo.Items);
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        // C: cVar1 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN (Form1.ListBoxRInativo,local_10);
        if cVar1 then begin
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0x8c)) (Form1.ListBoxRInativo.Items,local_10,"-----" );
        end;
      until not (local_10 < iVar3 + -1);
    end;
    local_13c := PASTA + 'ritmosinativos.txt';
    local_138 := local_13c;
    AssignFile(ARQTEXTO, local_138);
    Rewrite(ARQTEXTO);
    iVar3 := Form1.ListBoxRInativo.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_13c := Form1.ListBoxRInativo.Items[local_10];
        if local_13c <> '-----' then begin
          local_13c := Form1.ListBoxRInativo.Items[local_10];
          Write(ARQTEXTO, local_13c);
          Writeln(ARQTEXTO);
        end;
      until not (local_10 < iVar3 + -1);
    end;
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    RELECDS := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONEO1CLICK$TOBJECT }
procedure TForm1.ButtonEO1Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  iVar1 := KMATEXCLUI;
  KMATEXCLUI := KMATEXCLUI + -6;
  if KMATEXCLUI < 1 then begin
    KMATEXCLUI := iVar1;
  end
  else begin
    // C: JUKELINUX1_MOSTRA_CD_EXCLUSAO_LONGINT(U_JUKELINUX1_KMATEXCLUI,Sender,param_3,Self,Sender);
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONEO2CLICK$TOBJECT }
procedure TForm1.ButtonEO2Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  iVar1 := KMATEXCLUI;
  KMATEXCLUI := KMATEXCLUI + 6;
  if TOTALCDS < KMATEXCLUI then begin
    KMATEXCLUI := iVar1;
  end
  else begin
    // C: JUKELINUX1_MOSTRA_CD_EXCLUSAO_LONGINT(U_JUKELINUX1_KMATEXCLUI,Sender,param_3,Self,Sender);
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONEO3CLICK$TOBJECT }
procedure TForm1.ButtonEO3Click(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  iVar2, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    local_38 := Copy(ORDEMDOSCDS, 1, 1);
    if local_38 = 'R' then begin
      // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KMATEXCLUI * 0x240 + 0x8e91128,local_38);
      iVar2 := TOTALMMRITMO;
      RITMOSELECIONADO := local_38;
      NUMRITMOSELECIONADO := 0;
      KR := 1;
      if 0 < TOTALMMRITMO then begin
        KR := 0;
        repeat
          KR := KR + 1;
          // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_RITMOSELECIONADO, *(undefined4 * )(&DAT_092fffac + U_JUKELINUX1_KR * 4));
          if iVar3 = 0 then begin
            NUMRITMOSELECIONADO := KR;
          end;
        until not (KR < iVar2);
      end;
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 1;
      if TOTALMMRITMO < NUMRITMOSELECIONADO then begin
        NUMRITMOSELECIONADO := 1;
      end;
      iVar3 := NUMRITMOSELECIONADO;
      iVar2 := TOTALCDS;
      // C: U_JUKELINUX1_RITMOESCOLHIDO = *(undefined4 * )(&DAT_092fffac + iVar3 * 4);
      POSICAORITMO := 0;
      KKRITMO := 1;
      if 0 < TOTALCDS then begin
        KKRITMO := 0;
        repeat
          KKRITMO := KKRITMO + 1;
          // C: fpc_shortstr_to_ansistr(U_JUKELINUX1_KKRITMO * 0x240 + 0x8e91128,local_38);
          // C: iVar3 = fpc_ansistr_compare_equal(local_38[0],U_JUKELINUX1_RITMOESCOLHIDO);
          if (iVar3 = 0) and (POSICAORITMO = 0) then begin
            POSICAORITMO := KKRITMO;
          end;
        until not (KKRITMO < iVar2);
      end;
      if POSICAORITMO = 0 then begin
        KMATEXCLUI := 1;
      end
      else begin
        KMATEXCLUI := POSICAORITMO;
      end;
      Mostra_Cd_Exclusao(KMATEXCLUI);
    end;
    local_38 := Copy(ORDEMDOSCDS, 1, 1);
    if local_38 = 'A' then begin
      // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMATEXCLUI * 0x240 + 0x1fc),1,1, &local_3c);
      local_38 := LowerCase(local_3c);
      iVar2 := TOTALMMLETRA;
      LETRASELECIONADA := local_38;
      NUMLETRASELECIONADA := 0;
      KL := 1;
      if 0 < TOTALMMLETRA then begin
        KL := 0;
        repeat
          KL := KL + 1;
          // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_LETRASELECIONADA, (&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_KL]);
          if iVar3 = 0 then begin
            NUMLETRASELECIONADA := KL;
          end;
        until not (KL < iVar2);
      end;
      NUMLETRASELECIONADA := NUMLETRASELECIONADA + 1;
      if TOTALMMLETRA < NUMLETRASELECIONADA then begin
        NUMLETRASELECIONADA := 1;
      end;
      // C: SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING ((&U_JUKELINUX1_CDSELEAPAGARX)[U_JUKELINUX1_NUMLETRASELECIONADA],&local_3c);
      iVar2 := TOTALCDS;
      LETRAESCOLHIDA := local_3c;
      POSICAOLETRA := 0;
      KKLETRA := 1;
      if 0 < TOTALCDS then begin
        KKLETRA := 0;
        repeat
          KKLETRA := KKLETRA + 1;
          // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KKLETRA * 0x240 + 0x1fc),1,1, local_38);
          local_3c := LowerCase(local_38);
          // C: iVar3 = fpc_ansistr_compare_equal(local_3c,U_JUKELINUX1_LETRAESCOLHIDA);
          if (iVar3 = 0) and (POSICAOLETRA = 0) then begin
            POSICAOLETRA := KKLETRA;
          end;
        until not (KKLETRA < iVar2);
      end;
      if POSICAOLETRA = 0 then begin
        KMATEXCLUI := 1;
      end
      else begin
        KMATEXCLUI := POSICAOLETRA;
      end;
      Mostra_Cd_Exclusao(KMATEXCLUI);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONESCONDERRITMOSCLICK$TOBJECT }
procedure TForm1.ButtonEsconderRitmosClick(Sender: TObject);
begin
  // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.PanelEsconderRitmos,0x14,param_3,Self,Sender);
  Form1.PanelEsconderRitmos.Top := 59;
  Form1.PanelEsconderRitmos.Width := 704;
  Form1.PanelEsconderRitmos.Height := 614;
  Form1.PanelEsconderRitmos.Show;
  Form1.PanelEsconderRitmos.BringToFront;
end;

{ JUKELINUX1_TFORM1_$__BUTTONEX1CLICK$TOBJECT }
procedure TForm1.ButtonEX1Click(Sender: TObject);
begin
  // C: JUKELINUX1_APAGA_CD_LONGINT_LONGINT(1,U_JUKELINUX1_KMATEXCLUI,param_3,Self,Sender);
end;

{ JUKELINUX1_TFORM1_$__BUTTONEX2CLICK$TOBJECT }
procedure TForm1.ButtonEX2Click(Sender: TObject);
begin
  // C: JUKELINUX1_APAGA_CD_LONGINT_LONGINT(2,U_JUKELINUX1_KMATEXCLUI + 1,param_3,Self,Sender);
end;

{ JUKELINUX1_TFORM1_$__BUTTONEX3CLICK$TOBJECT }
procedure TForm1.ButtonEX3Click(Sender: TObject);
begin
  // C: JUKELINUX1_APAGA_CD_LONGINT_LONGINT(3,U_JUKELINUX1_KMATEXCLUI + 2,param_3,Self,Sender);
end;

{ JUKELINUX1_TFORM1_$__BUTTONEX4CLICK$TOBJECT }
procedure TForm1.ButtonEX4Click(Sender: TObject);
begin
  // C: JUKELINUX1_APAGA_CD_LONGINT_LONGINT(4,U_JUKELINUX1_KMATEXCLUI + 3,param_3,Self,Sender);
end;

{ JUKELINUX1_TFORM1_$__BUTTONEX5CLICK$TOBJECT }
procedure TForm1.ButtonEX5Click(Sender: TObject);
begin
  // C: JUKELINUX1_APAGA_CD_LONGINT_LONGINT(5,U_JUKELINUX1_KMATEXCLUI + 4,param_3,Self,Sender);
end;

{ JUKELINUX1_TFORM1_$__BUTTONEX6CLICK$TOBJECT }
procedure TForm1.ButtonEX6Click(Sender: TObject);
begin
  // C: JUKELINUX1_APAGA_CD_LONGINT_LONGINT(6,U_JUKELINUX1_KMATEXCLUI + 5,param_3,Self,Sender);
end;

{ JUKELINUX1_TFORM1_$__BUTTONEXCLUIRCDS1CLICK$TOBJECT }
procedure TForm1.ButtonExcluirCDs1Click(Sender: TObject);
begin
  // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.PanelEsconderRitmos1,0x14,param_3,Self,Sender);
  Form1.PanelEsconderRitmos1.Top := 59;
  Form1.PanelEsconderRitmos1.Width := 704;
  Form1.PanelEsconderRitmos1.Height := 614;
  Form1.PanelEsconderRitmos1.Show;
  Form1.PanelEsconderRitmos1.BringToFront;
end;

{ JUKELINUX1_TFORM1_$__BUTTONEXCLUIRCDSCLICK$TOBJECT }
procedure TForm1.ButtonExcluirCDsClick(Sender: TObject);
begin
  // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.PanelExcluirMusica,0x14,param_3,Self,Sender);
  Form1.PanelExcluirMusica.Top := 59;
  Form1.PanelExcluirMusica.Width := 704;
  Form1.PanelExcluirMusica.Height := 614;
  Form1.PanelExcluirMusica.Show;
  Form1.PanelExcluirMusica.BringToFront;
end;

{ JUKELINUX1_TFORM1_$__BUTTONGRAVAROSDADOSCLICK$TOBJECT }
procedure TForm1.ButtonGravarOsDadosClick(Sender: TObject);
var
  local_4c0, local_4c4, local_4f4, local_4f8, local_508, local_514, local_5f4, local_5f8: AnsiString;
  cVar1: Boolean;
  iVar3, local_10, local_14, local_18, local_4f0: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_4fc, local_500, local_504, local_50c, local_510: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CodigodaMaquina,local_4f0);
    iVar3 := 0;
    if local_4f0 <> 0 then begin
      // C: iVar3 = *(int * )(local_4f0[0] + -4);
    end;
    if iVar3 = 0 then begin
      ShowMessage('Informe o Código da Máquina');
      local_18 := 1;
    end;
    local_4f4 := PASTA + 'cadastroobrigatorio.txt';
    cVar1 := FileExists(local_4f4);
    if cVar1 then begin
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.NomeDoPonto,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe o Nome do Ponto');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Cliente,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe nome do Cliente');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.RG,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe o RG ');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CPF,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe o CPF ');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Telefones,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe os Telefones');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Endereco,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe o Endereco');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Bairro,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe o Bairro');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Cidade,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe o Cidade');
          local_18 := 1;
        end;
      end;
      if local_18 = 0 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.DataDaInstalacao,local_4f0);
        iVar3 := 0;
        if local_4f0 <> 0 then begin
          // C: iVar3 = *(int * )(local_4f0[0] + -4);
        end;
        if iVar3 = 0 then begin
          ShowMessage('Informe a Data da Instalação');
          local_18 := 1;
        end;
      end;
    end;
    if local_18 = 0 then begin
      Form1.ButtonGravarOsDados.Caption := 'Aguarde...';
      // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      local_4f4 := PASTACHAVE + 'jukebox.cadastro';
      local_5f4 := local_4f4;
      AssignFile(ARQTEXTO, local_5f4);
      Rewrite(ARQTEXTO);
      local_4f4 := Criptasuper2(JC_SERIALPENDRIVE);
      TEXTO := local_4f4;
      // C: fpc_ansistr_incr_ref();
      // C: local_4c0[0] = U_JUKELINUX1_TEXTO;
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CodigodaMaquina,&local_5f8);
      local_4f4 := Criptasimples(local_5f8);
      TEXTO := local_4f4;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.NomeDoPonto,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Cliente,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.RG,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.CPF,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Telefones,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Endereco,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Bairro,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Cidade,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.DataDaInstalacao,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Selos,&local_4f4);
      local_5f8 := Criptasimples(local_4f4);
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_5f8 := Criptasimples('ok');
      TEXTO := local_5f8;
      // C: fpc_ansistr_concat(local_4c0,local_4c0[0]);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      iVar3 := 0;
      if local_4c0 <> '' then begin
        // C: iVar3 = *(int * )(local_4c0[0] + -4);
      end;
      local_14 := 1;
      if 0 < iVar3 then begin
        repeat
          local_14 := local_14 + 1;
          // C: local_10 = (uint)*(byte * )(local_4c0[0] + -1 + local_14) + local_10;
        until not (local_14 < iVar3);
      end;
      local_5f8 := IntToStr(local_10);
      // C: local_4c0[0] = local_5f8;
      local_5f8 := Criptasuper2(local_4c0);
      TEXTO := local_5f8;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      Le_Arquivo_De_Cadastro;
      Form1.PanelCOTeste.Hide;
      local_514 := 'JukeLinux ';
      local_510 := VERSAO;
      local_50c := '   Data:';
      local_5f8 := DateToStr(Date);
      local_508 := local_5f8;
      local_504 := '   Hora:';
      local_4f4 := TimeToStr(Time);
      local_500 := local_4f4;
      local_4fc := '   Máquina:';
      local_4f8 := JC_CODIGODAMAQUINA;
      local_4c4 := local_514 + local_510 + local_50c + local_508 + local_504 + local_500 + local_4fc + local_4f8;
      local_508 := local_4c4;
      local_504 := '   NomeDoPonto:';
      local_500 := NOMEDOPONTOSTR;
      local_4fc := '   Cliente:';
      local_4f8 := CLIENTESTR;
      local_4c4 := local_508 + local_504 + local_500 + local_4fc + local_4f8;
      local_510 := local_4c4;
      local_50c := '   RG:';
      local_508 := RGSTR;
      local_504 := '   CPF:';
      local_500 := CPFSTR;
      local_4fc := '   Telefones:';
      local_4f8 := TELEFONESSTR;
      local_4c4 := local_510 + local_50c + local_508 + local_504 + local_500 + local_4fc + local_4f8;
      local_508 := local_4c4;
      local_504 := '   Endereco:';
      local_500 := ENDERECOSTR;
      local_4fc := '   Bairro:';
      local_4f8 := BAIRROSTR;
      local_4c4 := local_508 + local_504 + local_500 + local_4fc + local_4f8;
      local_508 := local_4c4;
      local_504 := '   Cidade:';
      local_500 := CIDADESTR;
      local_4fc := '   DataDaInstalacao:';
      local_4f8 := DATADAINSTALACAOSTR;
      local_4c4 := local_508 + local_504 + local_500 + local_4fc + local_4f8;
      local_500 := local_4c4;
      local_4fc := '   Selos:';
      local_4f8 := SELOSSTR;
      local_4c4 := local_500 + local_4fc + local_4f8;
      // C: fpc_ansistr_concat(&local_5f8,U_JUKELINUX1_PASTA,"qrcode.txt");
      local_5f4 := local_5f8;
      AssignFile(ARQTEXTO, local_5f4);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, local_4c4);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
      // C: fpc_ansistr_concat(&local_5f8,U_JUKELINUX1_PASTA,"qrcode.sh");
      CMD.CommandLine := local_5f8;
      // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
      CMD.Free;
      Sleep(2000);
      // C: fpc_ansistr_concat(&local_5f8,U_JUKELINUX1_PASTA,"qrcode.jpg");
      cVar1 := FileExists(local_5f8);
      if cVar1 then begin
        // C: fpc_ansistr_concat(&local_5f8,U_JUKELINUX1_PASTA,"qrcode.jpg");
        // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageQrcode1.Picture,local_5f8);
      end;
      // C: CONTROLS_TCONTROL____SETLEFT_LONGINT(Form1.PanelQrcodeCadastro,0x1f8);
      // C: CONTROLS_TCONTROL____SETTOP_LONGINT(Form1.PanelQrcodeCadastro,0x104);
      // C: CONTROLS_TCONTROL____SHOW(Form1.PanelQrcodeCadastro);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONINT1CLICK$TOBJECT }
procedure TForm1.ButtonInt1Click(Sender: TObject);
var
  local_134, local_138: AnsiString;
  cVar1: Boolean;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    NOMEARQ := PASTA + 'interfaceteclado.txt';
    local_134 := NOMEARQ;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    Write(ARQTEXTO, '74');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '73');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '72');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '70');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '71');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '75');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '81');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '65');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '78');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '79');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '67');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 48);
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '66');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 48);
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '-----------------');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Musica+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Musica-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CD+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CD-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Ritmo');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Tocar');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Cancelar');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Credito');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'C.Remoto+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'C.Remoto-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Menu');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CreditoGratisVIP');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Credito2');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Karaoke');
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    Sleep(500);
    cVar1 := FileExists(NOMEARQ);
    if cVar1 then begin
      local_134 := NOMEARQ;
      AssignFile(ARQTEXTO, local_134);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMUSICAMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMUSICAMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACDMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACDMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLARITMO := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLATOCAR := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACANCELAR := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITO := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACRMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACRMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMENU := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITOGRATISVIP := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITO2 := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAKARAOKE := StrToIntDef(TEXTOTECLA, 0);
      CloseFile(ARQTEXTO);
      local_138 := IntToStr(TECLAMUSICAMAIS);
      Form1.EditMusicaMais.Caption := local_138;
      local_138 := IntToStr(TECLAMUSICAMENOS);
      Form1.EditMusicaMenos.Caption := local_138;
      local_138 := IntToStr(TECLACDMAIS);
      Form1.EditCDMais.Caption := local_138;
      local_138 := IntToStr(TECLACDMENOS);
      Form1.EditCDMenos.Caption := local_138;
      local_138 := IntToStr(TECLARITMO);
      Form1.EditRitmo.Caption := local_138;
      local_138 := IntToStr(TECLATOCAR);
      Form1.EditTocar.Caption := local_138;
      local_138 := IntToStr(TECLACANCELAR);
      Form1.EditCancelar.Caption := local_138;
      local_138 := IntToStr(TECLACREDITO);
      Form1.EditCredito.Caption := local_138;
      local_138 := IntToStr(TECLACRMAIS);
      Form1.EditCRMais.Caption := local_138;
      local_138 := IntToStr(TECLACRMENOS);
      Form1.EditCRMenos.Caption := local_138;
      local_138 := IntToStr(TECLAMENU);
      Form1.EditMenuTecla.Caption := local_138;
      local_138 := IntToStr(TECLACREDITOGRATISVIP);
      Form1.EditCreditoVIP.Caption := local_138;
      local_138 := IntToStr(TECLACREDITO2);
      Form1.EditCredito2.Caption := local_138;
      local_138 := IntToStr(TECLAKARAOKE);
      Form1.EditKaraoke.Caption := local_138;
    end;
    Gravalog('Menu - Configurada a Interface Modelo LL PS2');
    Form1.ButtonInterface.Caption := 'Ok, Letras da Interface Salvas';
    Form1.LabelIntInfo.Caption := 'Interface já está ReConfigurada - LL PS2';
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONINT2CLICK$TOBJECT }
procedure TForm1.ButtonInt2Click(Sender: TObject);
var
  local_134, local_138: AnsiString;
  cVar1: Boolean;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    NOMEARQ := PASTA + 'interfaceteclado.txt';
    local_134 := NOMEARQ;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    Write(ARQTEXTO, '79');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '81');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '87');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '88');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '73');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '82');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '76');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '90');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '86');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '75');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '13');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 48);
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 48);
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 48);
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '-----------------');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Musica+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Musica-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CD+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CD-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Ritmo');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Tocar');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Cancelar');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Credito');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'C.Remoto+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'C.Remoto-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Menu');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CreditoGratisVIP');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Credito2');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Karaoke');
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    Sleep(500);
    cVar1 := FileExists(NOMEARQ);
    if cVar1 then begin
      local_134 := NOMEARQ;
      AssignFile(ARQTEXTO, local_134);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMUSICAMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMUSICAMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACDMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACDMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLARITMO := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLATOCAR := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACANCELAR := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITO := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACRMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACRMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMENU := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITOGRATISVIP := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITO2 := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAKARAOKE := StrToIntDef(TEXTOTECLA, 0);
      CloseFile(ARQTEXTO);
      local_138 := IntToStr(TECLAMUSICAMAIS);
      Form1.EditMusicaMais.Caption := local_138;
      local_138 := IntToStr(TECLAMUSICAMENOS);
      Form1.EditMusicaMenos.Caption := local_138;
      local_138 := IntToStr(TECLACDMAIS);
      Form1.EditCDMais.Caption := local_138;
      local_138 := IntToStr(TECLACDMENOS);
      Form1.EditCDMenos.Caption := local_138;
      local_138 := IntToStr(TECLARITMO);
      Form1.EditRitmo.Caption := local_138;
      local_138 := IntToStr(TECLATOCAR);
      Form1.EditTocar.Caption := local_138;
      local_138 := IntToStr(TECLACANCELAR);
      Form1.EditCancelar.Caption := local_138;
      local_138 := IntToStr(TECLACREDITO);
      Form1.EditCredito.Caption := local_138;
      local_138 := IntToStr(TECLACRMAIS);
      Form1.EditCRMais.Caption := local_138;
      local_138 := IntToStr(TECLACRMENOS);
      Form1.EditCRMenos.Caption := local_138;
      local_138 := IntToStr(TECLAMENU);
      Form1.EditMenuTecla.Caption := local_138;
      local_138 := IntToStr(TECLACREDITOGRATISVIP);
      Form1.EditCreditoVIP.Caption := local_138;
      local_138 := IntToStr(TECLACREDITO2);
      Form1.EditCredito2.Caption := local_138;
      local_138 := IntToStr(TECLAKARAOKE);
      Form1.EditKaraoke.Caption := local_138;
    end;
    Gravalog('Menu - Configurada a Interface Modelo LL USB');
    Form1.ButtonInterface.Caption := 'Ok, Letras da Interface Salvas';
    Form1.LabelIntInfo.Caption := 'Interface já está ReConfigurada - LL USB';
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONINTERFACECLICK$TOBJECT }
procedure TForm1.ButtonInterfaceClick(Sender: TObject);
var
  local_134, local_138, local_13c, local_140, local_144, local_148: AnsiString;
  cVar2: Boolean;
  uVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Gravalog('Menu - Salvo a Alteracao das Teclas da Interface');
    local_138 := PASTA + 'interfaceteclado.txt';
    local_134 := local_138;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditMusicaMais,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditMusicaMenos,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCDMais,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCDMenos,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditRitmo,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditTocar,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCancelar,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCredito,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCRMais,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCRMenos,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditMenuTecla,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCreditoVIP,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCredito2,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, '---------------');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Musica+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Musica-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CD+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'CD-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Ritmo');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Tocar');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Cancelar');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Credito');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'C.Remoto+');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'C.Remoto-');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Menu');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Crédito Grátis VIP');
    Writeln(ARQTEXTO);
    Write(ARQTEXTO, 'Credito2');
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    Form1.ButtonInterface.Caption := 'Ok, Letras da Interface Salvas';
    Form1.LabelIntInfo.Caption := 'Interface já está ReConfigurada';
    Form1.TimerConfigInterface.Enabled := False;
    if LETRASEXE = 'BRG' then begin
      local_13c := PASTACHAVE + 'interfaceteclado.txt';
      // C: puVar5 = local_13c;
      if False { C: local_13c == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar5,&local_138);
      // C: uVar1 = local_138;
      local_144 := PASTA + 'interfaceteclado.txt';
      // C: puVar5 = local_144;
      if False { C: local_144 == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar5,&local_140);
      // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_140,uVar1,extraout_ECX & 0xffffff00);
      Gravalog('Gravou Automaticamente o Arquivo "interfaceteclado.txt" do HD para o Pendrive');
    end;
    local_140 := PASTA + 'interfaceteclado.txt';
    cVar2 := FileExists(local_140);
    if cVar2 then begin
      local_140 := PASTA + 'interfaceteclado.txt';
      local_134 := local_140;
      AssignFile(ARQTEXTO, local_134);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMUSICAMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMUSICAMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACDMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACDMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLARITMO := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLATOCAR := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACANCELAR := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITO := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACRMAIS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACRMENOS := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLAMENU := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITOGRATISVIP := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      TECLACREDITO2 := StrToIntDef(TEXTOTECLA, 0);
      Read(ARQTEXTO, TEXTOTECLA);
      Readln(ARQTEXTO);
      CloseFile(ARQTEXTO);
      local_148 := IntToStr(TECLAMUSICAMAIS);
      Form1.EditMusicaMais.Caption := local_148;
      local_148 := IntToStr(TECLAMUSICAMENOS);
      Form1.EditMusicaMenos.Caption := local_148;
      local_148 := IntToStr(TECLACDMAIS);
      Form1.EditCDMais.Caption := local_148;
      local_148 := IntToStr(TECLACDMENOS);
      Form1.EditCDMenos.Caption := local_148;
      local_148 := IntToStr(TECLARITMO);
      Form1.EditRitmo.Caption := local_148;
      local_148 := IntToStr(TECLATOCAR);
      Form1.EditTocar.Caption := local_148;
      local_148 := IntToStr(TECLACANCELAR);
      Form1.EditCancelar.Caption := local_148;
      local_148 := IntToStr(TECLACREDITO);
      Form1.EditCredito.Caption := local_148;
      local_148 := IntToStr(TECLACRMAIS);
      Form1.EditCRMais.Caption := local_148;
      local_148 := IntToStr(TECLACRMENOS);
      Form1.EditCRMenos.Caption := local_148;
      local_148 := IntToStr(TECLAMENU);
      Form1.EditMenuTecla.Caption := local_148;
      local_148 := IntToStr(TECLACREDITOGRATISVIP);
      Form1.EditCreditoVIP.Caption := local_148;
      local_148 := IntToStr(TECLACREDITO2);
      Form1.EditCredito2.Caption := local_148;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONMUSCARREGARCLICK$TOBJECT }
procedure TForm1.ButtonMusCarregarClick(Sender: TObject);
var
  local_1004, local_1008, local_1014, local_1018, local_101c, local_1028, local_102c, local_111c, local_1128, local_1130, local_1138, local_ff0, local_ff4, local_ff8: AnsiString;
  cVar2: Boolean;
  iVar4, iVar5, iVar6, local_10, local_14, local_18, local_1c, local_20, local_fc0, local_fc4, local_fd0, uVar7: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_1000, local_100c, local_1010, local_1020, local_1024, local_1120, local_1124, local_112c, local_1134, local_ffc: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCC,local_ff0);
    iVar4 := 0;
    if local_ff0 <> '' then begin
      // C: iVar4 = *(int * )(local_ff0[0] + -4);
    end;
    if 0 < iVar4 then begin
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditCC,local_ff0);
      NOMEPASTACDNOVO := local_ff0 + '/';
    end;
    Form1.LabelMusNomeCD.Caption := '';
    iVar4 := 0;
    if PERIODOSTR <> '' then begin
      // C: iVar4 = *(int * )(U_JUKELINUX1_PERIODOSTR + -4);
    end;
    if iVar4 < 1 then begin
      if SENHAOK = 1 then begin
        Form1.LabelMusTot.Caption := 'Selecione o Periodo';
        Form1.LabelMusR.Caption := 'Entre no Menu de Músicas e Primeiro Selecione o Periodo';
      end
      else begin
        ShowMessage('Selecione o Periodo');
      end;
    end
    else begin
      cVar2 := DirectoryExists(NOMEPASTACDNOVO);
      if not cVar2 then begin
        if SENHAOK = 1 then begin
          Form1.LabelMusTot.Caption := 'Pasta Não Existe';
          // C: local_1130 = "Pasta [";
          local_112c := NOMEPASTACDNOVO;
          local_1128 := '] Não Existe, Este Pendrive não é de Músicas ou Não tem a pasta musicas.';
          local_101c := local_1130 + local_112c + local_1128;
          Form1.LabelMusR.Caption := local_101c;
        end
        else begin
          // C: local_1130 = "Pasta [";
          local_112c := NOMEPASTACDNOVO;
          local_1128 := '] Não Existe';
          local_1138 := local_1130 + local_112c + local_1128;
          ShowMessage(local_1138);
        end;
      end
      else begin
        Form1.ButtonMusCarregar.Visible := False;
        Form1.ButtonMusCarregar.Caption := 'Aguarde, Lendo Atualização...';
        Form1.LabelMusTot.Caption := 'Aguarde, Lendo Atualização...';
        FORM1.Refresh;
        // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
        Form1.FileListBox1.Directory := NOMEPASTACDNOVO;
        iVar4 := Form1.FileListBox1.Count;
        if -1 < iVar4 + -1 then begin
          local_18 := -1;
          repeat
            local_18 := local_18 + 1;
            local_ff4 := Form1.FileListBox1.Items[local_18];
            if False { C: STRNE(local_ff4,"[.]") } then begin
              local_ff4 := Form1.FileListBox1.Items[local_18];
              if False { C: STRNE(local_ff4,"[..]") } then begin
                local_1c := local_1c + 1;
                local_ff8 := Form1.FileListBox1.Items[local_18];
                iVar5 := 0;
                if local_ff8 <> '' then begin
                  // C: iVar5 = *(int * )(local_ff8 + -4);
                end;
                local_ff8 := Form1.FileListBox1.Items[local_18];
                // C: fpc_ansistr_copy(local_ff8,2,iVar5 + -2);
                iVar5 := local_1c;
                // C: *(undefined4 * )(local_fc0 + iVar5 * 4 + 0x7cc) = local_ff4;
              end;
            end;
          until not (local_18 < iVar4 + -1);
        end;
        iVar4 := local_1c;
        local_20 := local_1c;
        if 0 < local_1c then begin
          repeat
            local_18 := local_18 + 1;
            local_1004 := NOMEPASTACDNOVO;
            // C: local_1000 = *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc);
            local_ffc := '/';
            local_ff8 := local_1004 + local_1000 + local_ffc;
            Form1.FileListBox1.Directory := local_ff8;
            iVar5 := Form1.FileListBox1.Count;
            if -1 < iVar5 + -1 then begin
              local_14 := -1;
              repeat
                local_14 := local_14 + 1;
                local_ff8 := Form1.FileListBox1.Items[local_14];
                if False { C: STRNE(local_ff8,"[.]") } then begin
                  local_ff8 := Form1.FileListBox1.Items[local_14];
                  if False { C: STRNE(local_ff8,"[..]") } then begin
                    local_1014 := NOMEPASTACDNOVO;
                    // C: local_1010 = *(int * )(local_fc0 + local_18 * 4 + 0x7cc);
                    local_100c := '/';
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                    // C: uVar7 = 0;
                    if local_1018 <> '' then begin
                      // C: uVar7 = *(undefined4 * )(local_1018 + -4);
                    end;
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                    // C: fpc_ansistr_copy(local_1018,1,uVar7);
                    local_1008 := local_ff8;
                    ORIGEM := local_1014 + local_1010 + local_100c + local_1008;
                    if SENHAOK = 1 then begin
                      local_ff8 := ExtractFileExt(ORIGEM);
                      local_1018 := UpperCase(local_ff8);
                      if local_1018 = '.JPG' then begin
                        local_ff8 := ExtractFileName(ORIGEM);
                        local_1018 := UpperCase(local_ff8);
                        if local_1018 = 'CAPAPEQUENA.JPG' then begin
                          iVar6 := local_18;
                          // C: *(undefined1 ** )(local_fd0 + iVar6 * 4 + 0xc) = U_JUKELINUX1_ORIGEM;
                        end;
                      end;
                    end;
                    if SENHAOK = 2 then begin
                      local_ff8 := ExtractFileExt(ORIGEM);
                      local_1018 := UpperCase(local_ff8);
                      if local_1018 = '.JPG' then begin
                        local_ff8 := ExtractFileName(ORIGEM);
                        local_1018 := UpperCase(local_ff8);
                        if local_1018 = 'CAPA.JPG' then begin
                          iVar6 := local_18;
                          // C: *(undefined1 ** )(local_fd0 + iVar6 * 4 + 0xc) = U_JUKELINUX1_ORIGEM;
                        end;
                      end;
                    end;
                  end;
                end;
              until not (local_14 < iVar5 + -1);
            end;
          until not (local_18 < iVar4);
        end;
        iVar4 := local_20;
        local_18 := 1;
        if 0 < local_20 then begin
          repeat
            local_18 := local_18 + 1;
            // C: local_fc4[0] = '\x01';
            // C: cVar2 = ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x6a0) + 0x450)) (Form1.CheckBoxSubstituir);
            if not cVar2 then begin
              // C: fpc_ansistr_concat(&local_1018,U_JUKELINUX1_PASTAMUSICAS, *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc));
              cVar2 := DirectoryExists(local_1018);
              if cVar2 then begin
                // C: local_fc4[0] = '\0';
              end;
            end;
            if local_fc4 <> 0 then begin
              // C: fpc_ansistr_concat(&local_1018,U_JUKELINUX1_PASTAMUSICAS, *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc));
              cVar2 := DirectoryExists(local_1018);
              if not cVar2 then begin
                // C: fpc_ansistr_concat(&local_1018,U_JUKELINUX1_PASTAMUSICAS, *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc));
                CreateDir(local_1018);
                Sleep(200);
              end;
              // C: fpc_ansistr_concat(&local_1018,U_JUKELINUX1_PASTAMUSICAS, *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc));
              cVar2 := DirectoryExists(local_1018);
              if cVar2 then begin
                local_1014 := 'Aguarde, Copiando ';
                local_1018 := IntToStr(local_18);
                local_1010 := local_1018;
                local_100c := '/';
                local_ff8 := IntToStr(local_20);
                local_1008 := local_ff8;
                local_101c := local_1014 + local_1010 + local_100c + local_1008;
                Form1.LabelMusNomeCD.Caption := local_101c;
                // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x904) + 0x2fc))(Form1.LabelMusNomeCD);
                local_1014 := 'Aguarde, Copiando ';
                local_1018 := IntToStr(local_18);
                local_1010 := local_1018;
                local_100c := '/';
                local_ff8 := IntToStr(local_20);
                local_1008 := local_ff8;
                local_101c := local_1014 + local_1010 + local_100c + local_1008;
                Form1.LabelMusTot.Caption := local_101c;
                // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x8bc) + 0x2fc))(Form1.LabelMusTot);
                // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageMusCapa.Picture, *(undefined4 * )(local_fd0 + local_18 * 4 + 0xc));
                // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageMusR.Picture, *(undefined4 * )(local_fd0 + local_18 * 4 + 0xc));
                FORM1.Refresh;
                // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
                local_1004 := NOMEPASTACDNOVO;
                // C: local_1000 = *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc);
                local_ffc := '/';
                local_1018 := local_1004 + local_1000 + local_ffc;
                Form1.FileListBox1.Directory := local_1018;
                local_1130 := PASTAMUSICAS;
                local_112c := '/';
                // C: local_1128 = *(undefined ** )(local_fc0 + local_18 * 4 + 0x7cc);
                local_1124 := '/';
                local_1120 := 'novo.atu';
                local_1018 := local_1130 + local_112c + local_1128 + local_1124 + local_1120;
                local_111c := local_1018;
                AssignFile(ARQTEXTO, local_111c);
                Rewrite(ARQTEXTO);
                Write(ARQTEXTO, PERIODOSTR);
                Writeln(ARQTEXTO);
                local_1018 := DateToStr(Date);
                Write(ARQTEXTO, local_1018);
                Writeln(ARQTEXTO);
                Flush(ARQTEXTO);
                CloseFile(ARQTEXTO);
                iVar5 := Form1.FileListBox1.Count;
                if -1 < iVar5 + -1 then begin
                  local_14 := -1;
                  repeat
                    local_14 := local_14 + 1;
                    // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                    if False { C: STRNE(local_1018,"[.]") } then begin
                      // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                      if False { C: STRNE(local_1018,"[..]") } then begin
                        // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1134);
                        // C: uVar7 = 0;
                        if False { C: local_1134 != (char * )0x0 } then begin
                          // C: uVar7 = *(undefined4 * )(local_1134 + -4);
                        end;
                        // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1134);
                        // C: fpc_ansistr_copy(local_1134,1,uVar7);
                        iVar6 := Pos('.ATU', local_1018);
                        if iVar6 = 0 then begin
                          local_102c := NOMEPASTACDNOVO;
                          // C: local_1028 = *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc);
                          local_1024 := '/';
                          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                          // C: uVar7 = 0;
                          if local_1018 <> '' then begin
                            // C: uVar7 = *(undefined4 * )(local_1018 + -4);
                          end;
                          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                          // C: fpc_ansistr_copy(local_1018,1,uVar7);
                          local_1020 := local_1134;
                          ORIGEM := local_102c + local_1028 + local_1024 + local_1020;
                          local_102c := PASTAMUSICAS;
                          // C: local_1028 = *(undefined4 * )(local_fc0 + local_18 * 4 + 0x7cc);
                          local_1024 := '/';
                          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                          // C: uVar7 = 0;
                          if local_1018 <> '' then begin
                            // C: uVar7 = *(undefined4 * )(local_1018 + -4);
                          end;
                          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                          // C: fpc_ansistr_copy(local_1018,1,uVar7);
                          local_1020 := local_1134;
                          DESTINO := local_102c + local_1028 + local_1024 + local_1020;
                          local_1130 := 'CD/DVD: ';
                          // C: local_112c = *(char ** )(local_fc0 + local_18 * 4 + 0x7cc);
                          local_1128 := ''#13'';
                          local_1124 := 'COPIANDO ARQUIVO: ';
                          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                          // C: uVar7 = 0;
                          if local_1018 <> '' then begin
                            // C: uVar7 = *(undefined4 * )(local_1018 + -4);
                          end;
                          // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_14, &local_1018);
                          // C: fpc_ansistr_copy(local_1018,1,uVar7);
                          local_1120 := local_1134;
                          local_101c := local_1130 + local_112c + local_1128 + local_1124 + local_1120;
                          Form1.LabelMusCopia.Caption := local_101c;
                          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x8c4) + 0x2fc)) (Form1.LabelMusCopia);
                          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelMusCopia,&local_101c);
                          Form1.LabelMusR.Caption := local_101c;
                          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x8c0) + 0x2fc)) (Form1.LabelMusR);
                          FORM1.Refresh;
                          // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
                          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa2c) + 0x2fc)) (Form1.PanelCarregarMusica);
                          // C: puVar8 = U_JUKELINUX1_DESTINO;
                          if False { C: U_JUKELINUX1_DESTINO == (undefined1 * )0x0 } then begin
                          end;
                          // C: fpc_pchar_to_ansistr(puVar8,&local_1134);
                          // C: pcVar1 = local_1134;
                          // C: puVar8 = U_JUKELINUX1_ORIGEM;
                          if False { C: U_JUKELINUX1_ORIGEM == (undefined1 * )0x0 } then begin
                          end;
                          // C: fpc_pchar_to_ansistr(puVar8,&local_1138);
                          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_1138,pcVar1,1);
                          local_10 := local_10 + 1;
                        end;
                      end;
                    end;
                  until not (local_14 < iVar5 + -1);
                end;
              end;
            end;
          until not (local_18 < iVar4);
        end;
        if 0 < local_10 then begin
          local_1138 := PASTA + 'ultimaatualizacao.txt';
          local_111c := local_1138;
          AssignFile(ARQTEXTO, local_111c);
          Rewrite(ARQTEXTO);
          local_1138 := DateToStr(Date);
          Write(ARQTEXTO, local_1138);
          Writeln(ARQTEXTO);
          local_1138 := IntToStr(local_20);
          Write(ARQTEXTO, local_1138);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
        if local_10 < 1 then begin
          RELECDS := 1;
          Form1.ButtonMusCarregar.Caption := 'Copia OK';
          Form1.LabelMusCopia.Caption := 'Todos os CDs/DVDs da Atualização já existem na Máquina';
          Form1.LabelMusTot.Caption := 'Todos os CDs/DVDs da Atualização já existem na Máquina';
          Form1.LabelMusR.Caption := '';
          Form1.LabelPress1.Caption := 'Todos os CDs/DVDs da Atualização  ou já existem na Máquina';
          Form1.PanelMusRelogio.Hide;
        end
        else begin
          RELECDS := 1;
          Form1.ButtonMusCarregar.Caption := 'Copia OK';
          Form1.LabelMusCopia.Caption := 'Copia OK';
          Form1.LabelMusTot.Caption := 'Copia OK';
          Form1.LabelMusR.Caption := '';
          Form1.PanelMusRelogio.Hide;
          Form1.PanelUpgrade1.Hide;
        end;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelMusNomeCD,&local_101c);
        local_1138 := 'Menu - Carregando Musicas do PenDrive - ' + local_101c;
        Gravalog(local_1138);
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONMUSEXCLUIRAUTOCLICK$TOBJECT }
procedure TForm1.ButtonMusExcluirAutoClick(Sender: TObject);
begin
  Excluicdpelalista;
end;

{ JUKELINUX1_TFORM1_$__BUTTONOKSENHACLICK$TOBJECT }
procedure TForm1.ButtonOkSenhaClick(Sender: TObject);
var
  local_10, local_13c, local_140, local_144, local_148, local_248, local_24c, local_250, local_258, local_25c, local_350, local_354, local_358, local_3c: AnsiString;
  cVar1: Boolean;
  local_c: TForm1;
  local_8: TObject;
  local_254: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    if CHAVEDEINSTALACAO <> 0 then begin
      // C: cVar1 = ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa8c) + 0x450))(Form1.RadioButton2);
      if cVar1 then begin
        local_3c := PASTA + 'jukesm.txt';
        cVar1 := FileExists(local_3c);
        if not cVar1 then begin
          local_3c := PASTA + 'jukesm.txt';
          local_13c := local_3c;
          AssignFile(ARQTEXTO, local_13c);
          Rewrite(ARQTEXTO);
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.EditSenha,&local_140);
          local_3c := Cripta(local_140);
          Write(ARQTEXTO, local_3c);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.EditSenha,&local_144);
          local_140 := 'Menu - Criado a Senha Master = ' + local_144;
          Gravalog(local_140);
          ShowMessage('Ok, Criado a Senha Master');
        end;
      end;
      local_140 := PASTA + 'jukes.txt';
      cVar1 := FileExists(local_140);
      if cVar1 then begin
        local_140 := PASTA + 'jukesm.txt';
        cVar1 := FileExists(local_140);
        if cVar1 then begin
          local_148 := PASTA + 'instalacao.txt';
          // C: puVar3 = local_148;
          if False { C: local_148 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar3,&local_140);
          DeleteFile(local_140);
          CHAVEDEINSTALACAO := 0;
          ShowMessage('Senha e Senha Master Gravadas');
          ESTADIGITANDOSENHA := 2;
          Rotina_Menu;
        end;
      end;
      // C: cVar1 = ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa88) + 0x450))(Form1.RadioButton1);
      if cVar1 then begin
        local_140 := PASTA + 'jukes.txt';
        cVar1 := FileExists(local_140);
        if not cVar1 then begin
          local_140 := PASTA + 'jukes.txt';
          local_248 := local_140;
          AssignFile(ARQTEXTO, local_248);
          Rewrite(ARQTEXTO);
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.EditSenha,&local_24c);
          local_140 := Cripta(local_24c);
          Write(ARQTEXTO, local_140);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.EditSenha,&local_144);
          local_24c := 'Menu - Criado a Senha = ' + local_144;
          Gravalog(local_24c);
          ShowMessage('Ok, Criado a Senha');
          // C: JUKELINUX1_TFORM1____BS10CLICK_TOBJECT(local_c,local_8);
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa8c) + 0x454))(Form1.RadioButton2,1);
        end;
      end;
    end;
    if CHAVEDEINSTALACAO = 0 then begin
      local_24c := PASTA + 'jukes.txt';
      cVar1 := FileExists(local_24c);
      if not cVar1 then begin
        Gravalog('Nao Encontrado o Arquivo de Senha');
        ShowMessage('Não Encontrado o Arquivo de Senha');
      end
      else begin
        local_24c := PASTA + 'jukes.txt';
        local_248 := local_24c;
        AssignFile(ARQTEXTO, local_248);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, local_10);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_24c := Descripta(local_10);
        local_10 := local_24c;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditSenha,&local_250);
        if local_250 = local_10 then begin
          MENUMASTER := 0;
          Form1.EditSenha.Caption := '';
          SENHAOK := 2;
          Form1.LabelCliente.Font.Color := 16777215;
          Form1.PanelSenha.Hide;
          Libera_Quantidadesdemusicastocadas;
        end
        else begin
          local_24c := PASTA + 'jukesm.txt';
          cVar1 := FileExists(local_24c);
          if not cVar1 then begin
            Gravalog('Nao Encontrado o Arquivo de SenhaMaster');
            ShowMessage('Não Encontrado o Arquivo de SenhaMaster');
          end
          else begin
            local_24c := PASTA + 'jukesm.txt';
            local_350 := local_24c;
            AssignFile(ARQTEXTO, local_350);
            Reset(ARQTEXTO);
            Read(ARQTEXTO, local_10);
            Readln(ARQTEXTO);
            CloseFile(ARQTEXTO);
            local_24c := Descripta(local_10);
            local_10 := local_24c;
            // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.EditSenha,&local_250);
            if local_250 = local_10 then begin
              MENUMASTER := 1;
              Form1.EditSenha.Caption := '';
              SENHAOK := 2;
              Form1.LabelCliente.Font.Color := 255;
              Form1.PanelSenha.Hide;
              Libera_Quantidadesdemusicastocadas;
            end
            else begin
              // C: local_25c = "Menu - Digitada Senha Errada [";
              // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.EditSenha,&local_358);
              local_258 := local_358;
              local_254 := ']';
              local_354 := local_25c + local_258 + local_254;
              Gravalog(local_354);
              Form1.LabelMenuDSErro.Show;
              // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x948) + 0x2fc))(Form1.LabelMenuDSErro);
              Form1.TimerSenhaErrada.Enabled := False;
              // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb84) + 0xdc)) (Form1.TimerSenhaErrada,1000);
              Form1.TimerSenhaErrada.Enabled := True;
              Form1.EditSenha.Caption := '';
            end;
          end;
        end;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONQRCLICK$TOBJECT }
procedure TForm1.ButtonQRClick(Sender: TObject);
var
  local_10, local_14, local_16c, local_170, local_174, local_178, local_18, local_188, local_190, local_1c, local_20, local_24, local_28, local_288, local_290, local_294, local_2c, local_30, local_6c, local_78, local_88, local_8c, uVar4: AnsiString;
  cVar1: Boolean;
  iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_17c, local_180, local_184, local_18c, local_28c, local_70, local_74, local_7c, local_80, local_84: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN("naoqrcode.txt");
    if not cVar1 then begin
      if SEMQRCODE = 0 then begin
        local_14 := '-';
        local_18 := '-';
        local_1c := '-';
        local_20 := '-';
        local_24 := '-';
        local_28 := '-';
        local_6c := PASTA + 'ultimofechamento.txt';
        cVar1 := FileExists(local_6c);
        if cVar1 then begin
          local_6c := PASTA + 'ultimofechamento.txt';
          local_16c := local_6c;
          AssignFile(ARQTEXTO, local_16c);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, local_14);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, local_18);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, local_1c);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, local_20);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, local_24);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, local_28);
          Readln(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
        local_6c := PASTA + 'ultimaatualizacao.txt';
        cVar1 := FileExists(local_6c);
        if cVar1 then begin
          local_6c := PASTA + 'ultimaatualizacao.txt';
          local_16c := local_6c;
          AssignFile(ARQTEXTO, local_16c);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, ULTIMAATU);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, QTDCDSDAULTIMAATU);
          Readln(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
        local_2c := DateToStr(Date);
        local_30 := TimeToStr(Time);
        local_6c := IntToStr(MINUTOSLIGADA);
        MINUTOSLIGADASTR := local_6c;
        // C: local_70 = (undefined * ) SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT(U_JUKELINUX1_MINUTOSLIGADASTR,0);
        // C: SYSUTILS_FLOATTOSTR_EXTENDED__ANSISTRING(local_6c);
        MINUTOSLIGADASTR := local_6c;
        // C: uVar4 = SUB42(local_6c,0);
        // C: iVar3 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT (CONCAT31((int3)((uint)local_6c >> 8),0x2e),U_JUKELINUX1_MINUTOSLIGADASTR);
        uVar4 := Copy(MINUTOSLIGADASTR, 1, iVar3 + 2);
        MINUTOSLIGADASTR := local_6c;
        local_8c := 'JukeLinux ';
        local_88 := VERSAO;
        local_84 := '   Data:';
        // C: local_80 = (char * )local_2c;
        local_7c := '   Hora:';
        // C: local_78 = (undefined * )local_30;
        local_74 := '   Máquina:';
        // C: local_70 = (undefined * )U_JUKELINUX1_JC_CODIGODAMAQUINA;
        local_10 := local_8c + local_88 + local_84 + local_80 + local_7c + local_78 + local_74 + local_70;
        local_8c := local_10;
        local_88 := '   RelogioTotal:';
        local_6c := IntToStr(RELOGIOTOTAL);
        // C: local_84 = (char * )local_6c[0];
        local_80 := '   RelogioParcial:';
        local_170 := IntToStr(RELOGIOPARCIAL);
        // C: local_7c = (char * )local_170;
        local_78 := '    ';
        local_174 := IntToStr(PORCENTAGEMDOPONTO);
        // C: local_74 = (undefined * )local_174;
        local_70 := '%';
        local_10 := local_8c + local_88 + local_84 + local_80 + local_7c + local_78 + local_74 + local_70;
        local_88 := local_10;
        local_84 := '   ValorEmpresa:';
        local_174 := IntToStr(RELOGIOPARCIAL - VALORPONTO);
        // C: local_80 = (char * )local_174;
        local_7c := '   ValorPonto:';
        local_170 := IntToStr(VALORPONTO);
        // C: local_78 = (undefined * )local_170;
        local_74 := '   RelógioGrátis:';
        local_6c := IntToStr(RELOGIOGRATIS);
        // C: local_70 = (undefined * )local_6c[0];
        local_10 := local_88 + local_84 + local_80 + local_7c + local_78 + local_74 + local_70;
        local_190 := local_10;
        local_18c := '   RelogioGrátisVIP:';
        local_174 := IntToStr(RELOGIOGRATISVIP);
        local_188 := local_174;
        local_184 := '   HorasLigadaDesteoÚltimoFechamento:';
        local_180 := MINUTOSLIGADASTR;
        local_17c := 'hs    DataDoÚltimoFechamento:';
        local_178 := local_1c;
        local_10 := local_190 + local_18c + local_188 + local_184 + local_180 + local_17c + local_178;
        local_190 := local_10;
        local_18c := '   UltimaAtualizacaoDeCds:';
        local_188 := ULTIMAATU;
        local_184 := '   QtdDeCdsAtualizados:';
        local_180 := QTDCDSDAULTIMAATU;
        local_10 := local_190 + local_18c + local_188 + local_184 + local_180;
        // C: fpc_ansistr_concat(&local_174,U_JUKELINUX1_PASTA,"qrcode.txt");
        local_290 := local_174;
        AssignFile(ARQTEXTO, local_290);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, local_10);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
        // C: fpc_ansistr_concat(&local_174,U_JUKELINUX1_PASTA,"qrcode.sh");
        CMD.CommandLine := local_174;
        // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
        CMD.Free;
        Sleep(2000);
      end;
      // C: fpc_ansistr_concat(&local_174,U_JUKELINUX1_PASTA,"qrcode.jpg");
      cVar1 := FileExists(local_174);
      if not cVar1 then begin
        // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.LabelNaoQR, Form1.ImageQrcode.Left?);
        // C: CONTROLS_TCONTROL____SETTOP_LONGINT (Form1.LabelNaoQR, Form1.ImageQrcode.Top?);
        Form1.LabelNaoQR.Show;
      end
      else begin
        Form1.LabelNaoQR.Hide;
        // C: fpc_ansistr_concat(&local_174,U_JUKELINUX1_PASTA,"qrcode.jpg");
        // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageQrcode.Picture,local_174);
        // C: CONTROLS_TCONTROL____SHOW(Form1.ImageQrcode);
        // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.LabelNaoQR, Form1.ImageQrcode.Left? + 0x32);
        // C: CONTROLS_TCONTROL____SETTOP_LONGINT (Form1.LabelNaoQR, Form1.ImageQrcode.Top? + Form1.ImageQrcode.Height? + 0x14);
        local_290 := local_2c;
        local_28c := '    ';
        local_288 := local_30;
        local_294 := local_290 + local_28c + local_288;
        Form1.LabelNaoQR.Caption := local_294;
        Form1.LabelNaoQR.Show;
      end;
    end
    else begin
      Form1.LabelNaoQR.Hide;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONQRCODECADASTROMENUCLICK$TOBJECT }
procedure TForm1.ButtonQrCodeCadastroMenuClick(Sender: TObject);
var
  local_10, local_160, local_48, local_58, local_5c, local_60: AnsiString;
  cVar1: Boolean;
  local_c: TForm1;
  local_8: TObject;
  local_3c, local_40, local_44, local_4c, local_50, local_54: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    local_58 := 'JukeLinux ';
    local_54 := VERSAO;
    local_50 := '   Data:';
    local_5c := DateToStr(Date);
    local_4c := local_5c;
    local_48 := '   Hora:';
    local_60 := TimeToStr(Time);
    local_44 := local_60;
    local_40 := '   Máquina:';
    local_3c := JC_CODIGODAMAQUINA;
    local_10 := local_58 + local_54 + local_50 + local_4c + local_48 + local_44 + local_40 + local_3c;
    local_4c := local_10;
    local_48 := '   NomeDoPonto:';
    local_44 := NOMEDOPONTOSTR;
    local_40 := '   Cliente:';
    local_3c := CLIENTESTR;
    local_10 := local_4c + local_48 + local_44 + local_40 + local_3c;
    local_54 := local_10;
    local_50 := '   RG:';
    local_4c := RGSTR;
    local_48 := '   CPF:';
    local_44 := CPFSTR;
    local_40 := '   Telefones:';
    local_3c := TELEFONESSTR;
    local_10 := local_54 + local_50 + local_4c + local_48 + local_44 + local_40 + local_3c;
    local_4c := local_10;
    local_48 := '   Endereco:';
    local_44 := ENDERECOSTR;
    local_40 := '   Bairro:';
    local_3c := BAIRROSTR;
    local_10 := local_4c + local_48 + local_44 + local_40 + local_3c;
    local_4c := local_10;
    local_48 := '   Cidade:';
    local_44 := CIDADESTR;
    local_40 := '   DataDaInstalacao:';
    local_3c := DATADAINSTALACAOSTR;
    local_10 := local_4c + local_48 + local_44 + local_40 + local_3c;
    local_44 := local_10;
    local_40 := '   Selos:';
    local_3c := SELOSSTR;
    local_10 := local_44 + local_40 + local_3c;
    // C: fpc_ansistr_concat(&local_60,U_JUKELINUX1_PASTA,"qrcode.txt");
    local_160 := local_60;
    AssignFile(ARQTEXTO, local_160);
    Rewrite(ARQTEXTO);
    Write(ARQTEXTO, local_10);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
    // C: fpc_ansistr_concat(&local_60,U_JUKELINUX1_PASTA,"qrcode.sh");
    CMD.CommandLine := local_60;
    // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
    CMD.Free;
    Sleep(2000);
    // C: fpc_ansistr_concat(&local_60,U_JUKELINUX1_PASTA,"qrcode.jpg");
    cVar1 := FileExists(local_60);
    if cVar1 then begin
      // C: fpc_ansistr_concat(&local_60,U_JUKELINUX1_PASTA,"qrcode.jpg");
      // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageQrcode2.Picture,local_60);
    end;
    // C: CONTROLS_TCONTROL____SETLEFT_LONGINT(Form1.PanelQrcodeCadastro1,0x165);
    // C: CONTROLS_TCONTROL____SETTOP_LONGINT(Form1.PanelQrcodeCadastro1,0x39);
    // C: CONTROLS_TCONTROL____SHOW(Form1.PanelQrcodeCadastro1);
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONSALVARFRASESCLICK$TOBJECT }
procedure TForm1.ButtonSalvarFrasesClick(Sender: TObject);
var
  local_134: AnsiString;
  cVar3: Boolean;
  iVar1, iVar2, local_138: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    if ALTERANDOFRASES = 0 then begin
      Form1.ButtonSalvarFrases.Caption := 'Salvar as Frases';
      ALTERANDOFRASES := 1;
      Form1.EditFrase1.Visible := True;
      Form1.EditFrase2.Visible := True;
      Form1.EditFrase3.Visible := True;
      Form1.EditFrase4.Visible := True;
      Form1.EditFrase5.Visible := True;
      Form1.EditFrase6.Visible := True;
      Form1.EditFrase7.Visible := True;
      Form1.EditFrase8.Visible := True;
      Form1.EditFrase9.Visible := True;
      Form1.EditFrase10.Visible := True;
    end
    else begin
      ALTERANDOFRASES := 0;
      Form1.EditFrase1.Visible := False;
      Form1.EditFrase2.Visible := False;
      Form1.EditFrase3.Visible := False;
      Form1.EditFrase4.Visible := False;
      Form1.EditFrase5.Visible := False;
      Form1.EditFrase6.Visible := False;
      Form1.EditFrase7.Visible := False;
      Form1.EditFrase8.Visible := False;
      Form1.EditFrase9.Visible := False;
      Form1.EditFrase10.Visible := False;
      NOMEARQ := PASTA + 'frases.txt';
      local_134 := NOMEARQ;
      AssignFile(ARQTEXTO, local_134);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase1,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase2,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase3,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase4,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase5,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase6,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase7,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase8,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase9,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.EditFrase10,&local_138);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_134 := NOMEARQ;
        AssignFile(ARQTEXTO, local_134);
        Reset(ARQTEXTO);
        KFRASE := 0;
        while True do begin
          cVar3 := Eof(ARQTEXTO);
          if cVar3 then begin Break; end;
          KFRASE := KFRASE + 1;
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          // C: fpc_ansistr_concat(U_JUKELINUX1_KFRASE * 4 + 0x9301bfc,U_JUKELINUX1_TEXTO, "            ");
          iVar1 := KFRASE;
          // C: fpc_ansistr_incr_ref ( *(undefined4 * )(U_JUKELINUX1_ARQTOCARX + U_JUKELINUX1_KFRASE * 4 + 0x24c));
          iVar2 := KFRASE;
          // C: *(undefined4 * )(iVar2 * 4 + 0x9301ccc) = *(undefined4 * )(U_JUKELINUX1_ARQTOCARX + iVar1 * 4 + 0x24c);
        end;
        CloseFile(ARQTEXTO);
        TOTALFRASE := KFRASE;
        POSFRASE := 0;
      end;
      Form1.ButtonSalvarFrases.Caption := 'Clique Aqui para Alterar as Frases';
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONUPGRADECLICK$TOBJECT }
procedure TForm1.ButtonUpgradeClick(Sender: TObject);
var
  local_1ac, local_1b0, local_1b4, local_1e0, local_1e4, local_1e8, local_1f4, local_1f8, local_1fc, local_200, local_208, local_210, uVar1: AnsiString;
  cVar2: Boolean;
  iVar4, iVar5, local_19c, local_1a0, local_1a4, local_1a8: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_1ec, local_1f0, local_204, local_20c: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    cVar2 := DirectoryExists(NOMEPASTAUPGRADE);
    if not cVar2 then begin
      local_200 := 'Não Encontrado o Pendrive: ' + NOMEPASTAUPGRADE;
      Form1.LabelUpg.Caption := local_200;
    end
    else begin
      Form1.FileListBox1.Directory := NOMEPASTAUPGRADE;
      iVar4 := Form1.FileListBox1.Count;
      if -1 < iVar4 + -1 then begin
        local_1a0 := -1;
        repeat
          local_1a0 := local_1a0 + 1;
          local_1e0 := Form1.FileListBox1.Items[local_1a0];
          if False { C: STRNE(local_1e0[0],"[.]") } then begin
            local_1e0 := Form1.FileListBox1.Items[local_1a0];
            if False { C: STRNE(local_1e0[0],"[..]") } then begin
              local_1a4 := local_1a4 + 1;
              local_1e0 := Form1.FileListBox1.Items[local_1a0];
              // C: iVar5 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT(0x5b,local_1e0[0]);
              if iVar5 = 0 then begin
                if local_1a4 < 101 then begin
                  local_1e0 := Form1.FileListBox1.Items[local_1a0];
                  iVar5 := local_1a4;
                  // C: *(undefined4 * )(local_19c + iVar5 * 4 + -4) = local_1e0[0];
                end;
              end
              else begin
                local_1a4 := local_1a4 + -1;
              end;
            end;
          end;
        until not (local_1a0 < iVar4 + -1);
      end;
      iVar4 := local_1a4;
      local_1a0 := 1;
      if 0 < local_1a4 then begin
        repeat
          local_1a0 := local_1a0 + 1;
          // C: fpc_ansistr_concat(&local_1ac,U_JUKELINUX1_NOMEPASTAUPGRADE, *(undefined4 * )(local_19c + local_1a0 * 4 + -4));
          // C: fpc_ansistr_concat(&local_1b0,"//home/jkb/upgrade/", *(undefined4 * )(local_19c + local_1a0 * 4 + -4));
          // C: puVar6 = local_1b0;
          if False { C: local_1b0 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar6,local_1e0);
          // C: uVar1 = local_1e0[0];
          // C: puVar6 = local_1ac;
          if False { C: local_1ac == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar6,&local_1e4);
          CopyFile(local_1e4, uVar1, True);
          local_1e8 := 'Copiando: ' + local_1b0;
          Form1.LabelUpg.Caption := local_1e8;
          FORM1.Refresh;
          // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
          Sleep(500);
        until not (local_1a0 < iVar4);
      end;
      local_1f4 := 'Copiado ';
      local_1e4 := IntToStr(local_1a4);
      local_1f0 := local_1e4;
      local_1ec := ' Arquivo(s) da Pasta Jukelinux';
      local_1e8 := local_1f4 + local_1f0 + local_1ec;
      Form1.LabelUpg.Caption := local_1e8;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelUpg,&local_1e8);
      Form1.LabelUpgrade1.Caption := local_1e8;
      Sleep(500);
      FORM1.Refresh;
      // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      repeat
        local_1a8 := local_1a8 + 1;
        if local_1a8 = 1 then begin
          local_1b4 := 'ritmos/';
        end;
        if local_1a8 = 2 then begin
          local_1b4 := 'letras/';
        end;
        if local_1a8 = 3 then begin
          local_1b4 := 'propagandapngmonitor/';
        end;
        if local_1a8 = 4 then begin
          local_1b4 := 'propagandajpgbarmonitor1366/';
        end;
        if local_1a8 = 5 then begin
          local_1b4 := 'propagandajpgboatemonitor1366/';
        end;
        if local_1a8 = 6 then begin
          local_1b4 := 'propagandajpgbarmonitor1024/';
        end;
        if local_1a8 = 7 then begin
          local_1b4 := 'propagandajpgboatemonitor1024/';
        end;
        if local_1a8 = 8 then begin
          local_1b4 := 'propagandajpgbartv/';
        end;
        if local_1a8 = 9 then begin
          local_1b4 := 'propagandajpgboatetv/';
        end;
        if local_1a8 = 10 then begin
          local_1b4 := 'propagandampgbartv/';
        end;
        if local_1a8 = 11 then begin
          local_1b4 := 'propagandampgboatetv/';
        end;
        if local_1a8 = 12 then begin
          local_1b4 := 'propagandampgbartv/';
        end;
        if local_1a8 = 13 then begin
          local_1b4 := 'propagandampgboatetv/';
        end;
        if local_1a8 = 14 then begin
          local_1b4 := 'propagandapadraoaprova/';
        end;
        local_1f8 := NOMEPASTAUPGRADE + local_1b4;
        Form1.FileListBox1.Directory := local_1f8;
        iVar4 := Form1.FileListBox1.Count;
        if -1 < iVar4 + -1 then begin
          local_1a0 := -1;
          repeat
            local_1a0 := local_1a0 + 1;
            local_1f8 := Form1.FileListBox1.Items[local_1a0];
            if False { C: STRNE(local_1f8,"[.]") } then begin
              local_1f8 := Form1.FileListBox1.Items[local_1a0];
              if False { C: STRNE(local_1f8,"[..]") } then begin
                local_1a4 := local_1a4 + 1;
                local_1f8 := Form1.FileListBox1.Items[local_1a0];
                // C: iVar5 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT(0x5b,local_1f8);
                if (iVar5 = 0) and (local_1a4 < 101) then begin
                  // C: ( **(code ** )( **(int ** )(Form1.FileListBox1 + 0x364) + 0x78)) (Form1.FileListBox1.Items,local_1a0,&local_1f8 );
                  iVar5 := local_1a4;
                  // C: *(undefined4 * )(local_19c + iVar5 * 4 + -4) = local_1f8;
                end;
              end;
            end;
          until not (local_1a0 < iVar4 + -1);
        end;
        iVar4 := local_1a4;
        local_1a0 := 1;
        if 0 < local_1a4 then begin
          repeat
            local_1a0 := local_1a0 + 1;
            local_1f4 := NOMEPASTAUPGRADE;
            local_1f0 := local_1b4;
            // C: local_1ec = *(char ** )(local_19c + local_1a0 * 4 + -4);
            local_1ac := local_1f4 + local_1f0 + local_1ec;
            local_1f4 := '//home/jkb/jukelinux/';
            local_1f0 := local_1b4;
            // C: local_1ec = *(char ** )(local_19c + local_1a0 * 4 + -4);
            local_1b0 := local_1f4 + local_1f0 + local_1ec;
            // C: puVar6 = local_1b0;
            if False { C: local_1b0 == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar6,&local_1f8);
            // C: uVar1 = local_1f8;
            // C: puVar6 = local_1ac;
            if False { C: local_1ac == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar6,&local_1fc);
            CopyFile(local_1fc, uVar1, True);
            local_200 := 'Copiando: ' + local_1b0;
            Form1.LabelUpg.Caption := local_200;
            Sleep(100);
            FORM1.Refresh;
            // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
          until not (local_1a0 < iVar4);
        end;
        local_210 := 'Copiado ';
        local_1fc := IntToStr(local_1a4);
        local_20c := local_1fc;
        local_208 := ' Arquivo(s) da pasta ';
        local_204 := local_1b4;
        local_200 := local_210 + local_20c + local_208 + local_204;
        Form1.LabelUpg.Caption := local_200;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelUpg,&local_200);
        Form1.LabelUpgrade1.Caption := local_200;
        Sleep(500);
        FORM1.Refresh;
        // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
      until not (local_1a8 < 14);
      Form1.LabelUpg.Caption := 'UPGRADE OK, Desligue e Ligue Novamente a Jukebox';
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONXMLCLICK$TOBJECT }
procedure TForm1.ButtonXMLClick(Sender: TObject);
var
  local_10, local_150, local_154, local_158, local_48, local_4c, local_50, local_58, local_5c, uVar1: AnsiString;
  cVar2: Boolean;
  local_14: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44, local_54: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    cVar2 := DirectoryExists(NOMEPASTAXMLAPROVA);
    if not cVar2 then begin
      local_158 := 'Não Encontrado o Pendrive: ' + NOMEPASTAXMLAPROVA;
      Form1.LabelUpg.Caption := local_158;
    end
    else begin
      local_48 := NOMEPASTAXMLAPROVA;
      local_44 := JC_CODIGODAMAQUINA;
      local_40 := '/';
      local_10 := local_48 + local_44 + local_40;
      cVar2 := DirectoryExists(local_10);
      if not cVar2 then begin
        CreateDir(local_10);
        Sleep(1000);
      end;
      cVar2 := DirectoryExists(local_10);
      if cVar2 then begin
        local_4c := local_10 + 'tocadosaprova.txt';
        cVar2 := FileExists(local_4c);
        if not cVar2 then begin
          local_4c := PASTA + 'tocadosaprova_anterior.txt';
          // C: uVar1 = local_4c;
          local_50 := PASTA + 'tocadosaprova.txt';
          CopyFile(local_50, uVar1, True);
          local_50 := local_10 + 'tocadosaprova.txt';
          // C: uVar1 = local_50;
          local_4c := PASTA + 'tocadosaprova.txt';
          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_4c,uVar1,extraout_ECX & 0xffffff00);
          local_50 := PASTA + 'tocadosaprova.txt';
          local_150 := local_50;
          AssignFile(ARQTEXTO, local_150);
          Rewrite(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          local_14 := local_14 + 1;
        end
        else begin
          Form1.LabelUpg.Caption := 'ERRO: Este Pendrive já tem Arquivos XML Gravados';
        end;
        local_50 := local_10 + 'tocadosablf.txt';
        cVar2 := FileExists(local_50);
        if not cVar2 then begin
          local_50 := PASTA + 'tocadosablf_anterior.txt';
          // C: uVar1 = local_50;
          local_154 := PASTA + 'tocadosablf.txt';
          CopyFile(local_154, uVar1, True);
          local_154 := local_10 + 'tocadosaablf.txt';
          // C: uVar1 = local_154;
          local_50 := PASTA + 'tocadosablf.txt';
          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_50,uVar1,extraout_ECX_00 & 0xffffff00);
          local_154 := PASTA + 'tocadosablf.txt';
          local_150 := local_154;
          AssignFile(ARQTEXTO, local_150);
          Rewrite(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          local_14 := local_14 + 1;
        end
        else begin
          Form1.LabelUpg.Caption := 'ERRO: Este Pendrive já tem Arquivos XML Gravados';
        end;
      end;
      if local_14 = 2 then begin
        local_5c := 'OK, Salvo os arquivos XML da Jukebox ';
        local_58 := JC_CODIGODAMAQUINA;
        local_54 := ' no Pendrive';
        local_158 := local_5c + local_58 + local_54;
        Form1.LabelUpg.Caption := local_158;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONZERA50CLICK$TOBJECT }
procedure TForm1.ButtonZera50Click(Sender: TObject);
var
  local_138, local_38: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    if ZERA50 = 2 then begin
      local_38 := PASTA + 'tocados.txt';
      DeleteFile(local_38);
      NOMEARQ := PASTA + 'tocados.txt';
      local_138 := NOMEARQ;
      AssignFile(ARQTEXTO, local_138);
      Rewrite(ARQTEXTO);
      local_38 := DateToStr(Date);
      Write(ARQTEXTO, local_38);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      Form1.ButtonZera50.Caption := 'Lista Foi Zerada';
      ZERA50 := 3;
    end;
    if ZERA50 = 1 then begin
      Form1.ButtonZera50.Caption := 'Clique Novamente Aqui';
      ShowMessage('Clique Novamente em Zerar Lista');
      ZERA50 := 2;
    end;
    if ZERA50 = 0 then begin
      Form1.ButtonZera50.Caption := 'Para Zerar Clique Aqui';
      ShowMessage('Para Zerar a Lista dos 50 CDs/DVDs + Tocados, Clique Novamente em Zerar Lista');
      ZERA50 := 1;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONZERACADASTROCLICK$TOBJECT }
procedure TForm1.ButtonZeraCadastroClick(Sender: TObject);
var
  local_10, local_144, local_44: AnsiString;
  cVar1: Boolean;
  iVar3, local_14, local_18: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    local_44 := PASTACHAVE + 'jukebox.cadastro';
    cVar1 := FileExists(local_44);
    if cVar1 then begin
      local_44 := PASTACHAVE + 'jukebox.cadastro';
      local_144 := local_44;
      AssignFile(ARQTEXTO, local_144);
      Rewrite(ARQTEXTO);
      local_44 := Criptasuper2(JC_SERIALPENDRIVE);
      TEXTO := local_44;
      // C: fpc_ansistr_incr_ref();
      local_10 := TEXTO;
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples(CODIGODAMAQUINASTR);
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      local_44 := Criptasimples('zerado');
      TEXTO := local_44;
      // C: fpc_ansistr_concat(&local_10,local_10);
      Write(ARQTEXTO, TEXTO);
      Writeln(ARQTEXTO);
      iVar3 := 0;
      if local_10 <> '' then begin
        // C: iVar3 = *(int * )(local_10 + -4);
      end;
      local_18 := 1;
      if 0 < iVar3 then begin
        repeat
          local_18 := local_18 + 1;
          // C: local_14 = (uint)*(byte * )(local_10 + -1 + local_18) + local_14;
        until not (local_18 < iVar3);
      end;
      local_44 := IntToStr(local_14);
      local_10 := local_44;
      local_44 := Criptasuper2(local_10);
      TEXTO := local_44;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: CONTROLS_TCONTROL____HIDE(Form1.ImageQrcode2);
      Form1.LabelQrCodeMenu.Caption := 'Desligar e Ligar a Jukebox';
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONZERARCREDITOSCLICK$TOBJECT }
procedure TForm1.ButtonZerarCreditosClick(Sender: TObject);
var
  local_134, local_138, local_13c, local_144, local_148: AnsiString;
  local_140, uVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    CREDITOS := 0;
    NOMEARQ := PASTA + 'creditos.txt';
    local_134 := NOMEARQ;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    local_13c := IntToStr(CREDITOS);
    local_138 := Cripta(local_13c);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    local_13c := Cripta(JC_SERIALPENDRIVE);
    Write(ARQTEXTO, local_13c);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    if SEMPENDRIVE = 0 then begin
      local_138 := PASTACHAVE + 'creditos.txt';
      // C: puVar3 = local_138;
      if False { C: local_138 == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar3,&local_13c);
      // C: uVar1 = local_13c;
      local_144 := PASTA + 'creditos.txt';
      // C: puVar3 = local_144;
      if False { C: local_144 == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar3,&local_140);
      // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_140,uVar1,extraout_ECX & 0xffffff00);
    end;
    local_148 := IntToStr(CREDITOS);
    Form1.LabelCreditos.Caption := local_148;
    Form1.ButtonZerarCreditos.Caption := 'Créditos Zerados';
    Gravalog('Zerado os Creditos pelo Menu');
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONZERARFILACLICK$TOBJECT }
procedure TForm1.ButtonZerarFilaClick(Sender: TObject);
var
  local_134, local_13c, local_144: AnsiString;
  local_138, local_140, uVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    NOMEARQ := PASTA + 'tocar.txt';
    local_134 := NOMEARQ;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    if SEMPENDRIVE = 0 then begin
      local_13c := PASTACHAVE + 'tocar.txt';
      // C: puVar3 = local_13c;
      if False { C: local_13c == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar3,&local_138);
      // C: uVar1 = local_138;
      local_144 := PASTA + 'tocar.txt';
      // C: puVar3 = local_144;
      if False { C: local_144 == (undefined1 * )0x0 } then begin
      end;
      // C: fpc_pchar_to_ansistr(puVar3,&local_140);
      // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_140,uVar1,extraout_ECX & 0xffffff00);
    end;
    Mostra_Fila;
    Form1.ButtonZerarFila.Caption := 'Fila Zerada';
    Gravalog('Zerado a Fila pelo Menu');
  end;
end;

{ JUKELINUX1_TFORM1_$__BUTTONZRPCLICK$TOBJECT }
procedure TForm1.ButtonZRPClick(Sender: TObject);
var
  local_138, local_13c, local_140, local_158, local_15c, local_38, local_48, local_4c, uVar3: AnsiString;
  iVar2, local_14c: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_150, local_154, local_3c, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelPress,local_38);
    if local_38 = 'OK, Relógio Parcial Zerado' then begin
      Rotina_Menu;
    end
    else begin
      Gravalog('Zerou o Relogio Parcial na Opcao do Menu');
      local_13c := PASTA + 'ultimofechamento.txt';
      local_138 := local_13c;
      AssignFile(ARQTEXTO, local_138);
      Rewrite(ARQTEXTO);
      local_13c := IntToStr(RELOGIOTOTAL);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      local_13c := IntToStr(RELOGIOPARCIAL);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      local_13c := DateToStr(Date);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      local_13c := TimeToStr(Time);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      local_13c := IntToStr(PORCENTAGEMDOPONTO);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      local_13c := IntToStr(MINUTOSLIGADA);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      local_13c := PASTA + 'relogioparcial.txt';
      local_138 := local_13c;
      AssignFile(ARQTEXTO, local_138);
      Rewrite(ARQTEXTO);
      RELOGIOPARCIALSTR := '0';
      local_13c := Cripta(RELOGIOPARCIALSTR);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      RELOGIOPARCIAL := 0;
      local_13c := PASTA + 'minutosligada.txt';
      local_138 := local_13c;
      AssignFile(ARQTEXTO, local_138);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, 48);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      MINUTOSLIGADA := 0;
      local_13c := IntToStr(MINUTOSLIGADA);
      MINUTOSLIGADASTR := local_13c;
      // C: local_3c = (char * )SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT (U_JUKELINUX1_MINUTOSLIGADASTR,0);
      // C: SYSUTILS_FLOATTOSTR_EXTENDED__ANSISTRING(&local_13c);
      MINUTOSLIGADASTR := local_13c;
      // C: uVar3 = SUB42(&local_13c,0);
      // C: iVar2 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT (CONCAT31((int3)((uint)&local_13c >> 8),0x2e),U_JUKELINUX1_MINUTOSLIGADASTR);
      uVar3 := Copy(MINUTOSLIGADASTR, 1, iVar2 + 2);
      MINUTOSLIGADASTR := local_13c;
      local_4c := 'Relógio Parcial.: R$ ';
      local_13c := IntToStr(RELOGIOPARCIAL);
      local_48 := local_13c;
      // C: local_44 = ",00  [";
      local_40 := MINUTOSLIGADASTR;
      local_3c := 'hs Ligada]';
      local_140 := local_4c + local_48 + local_44 + local_40 + local_3c;
      Form1.LabelRP.Caption := local_140;
      // ?: local_14c := (longlong) ROUND((float10)PORCENTAGEMDOPONTO * ((float10)RELOGIOPARCIAL div ''));
      // C: U_JUKELINUX1_VALORPONTO = (int)local_14c;
      local_44 := 'Valor do Ponto: R$ ';
      local_13c := IntToStr(VALORPONTO);
      local_40 := local_13c;
      local_3c := ',00';
      local_140 := local_44 + local_40 + local_3c;
      Form1.LabelVP.Caption := local_140;
      local_158 := 'Valor da Empresa: R$ ';
      local_15c := IntToStr(RELOGIOPARCIAL - VALORPONTO);
      local_154 := local_15c;
      local_150 := ',00';
      local_140 := local_158 + local_154 + local_150;
      Form1.LabelVE.Caption := local_140;
      Form1.TimerGravaPenDrive.Enabled := False;
      Form1.TimerGravaPenDrive.Enabled := True;
      JAGRAVOUNOPENDRIVE := 1;
      Form1.LabelPress.Font.Color := 65280;
      Form1.LabelPress.Caption := 'OK, Relógio Parcial Zerado';
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAE1CLICK$TOBJECT }
procedure TForm1.CapaE1Click(Sender: TObject);
begin

end;

{ JUKELINUX1_TFORM1_$__CAPAMAIS1CLICK$TOBJECT }
procedure TForm1.CapaMais1Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if KMAT + 5 < TOTALCDS then begin
      KMAT := KMAT + 1;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + 1 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 1;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMAIS2CLICK$TOBJECT }
procedure TForm1.CapaMais2Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if KMAT + 6 < TOTALCDS then begin
      KMAT := KMAT + 2;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + 2 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 2;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMAIS3CLICK$TOBJECT }
procedure TForm1.CapaMais3Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if KMAT + 7 < TOTALCDS then begin
      KMAT := KMAT + 3;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + 3 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 3;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMAIS4CLICK$TOBJECT }
procedure TForm1.CapaMais4Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if KMAT + 8 < TOTALCDS then begin
      KMAT := KMAT + 4;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + 4 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 4;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMAIS5CLICK$TOBJECT }
procedure TForm1.CapaMais5Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if KMAT + 9 < TOTALCDS then begin
      KMAT := KMAT + 5;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + 5 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 5;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMENOS1CLICK$TOBJECT }
procedure TForm1.CapaMenos1Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if -5 < KMAT + -1 then begin
      KMAT := KMAT + -1;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + -1 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + -1;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMENOS2CLICK$TOBJECT }
procedure TForm1.CapaMenos2Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if -5 < KMAT + -2 then begin
      KMAT := KMAT + -2;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + -2 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + -2;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMENOS3CLICK$TOBJECT }
procedure TForm1.CapaMenos3Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if -5 < KMAT + -3 then begin
      KMAT := KMAT + -3;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + -3 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + -3;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMENOS4CLICK$TOBJECT }
procedure TForm1.CapaMenos4Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if -5 < KMAT + -4 then begin
      KMAT := KMAT + -4;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + -4 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + -4;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPAMENOS5CLICK$TOBJECT }
procedure TForm1.CapaMenos5Click(Sender: TObject);
var
  iVar1: LongInt;
begin
  if MOSTRANDORITMOS = 0 then begin
    if -5 < KMAT + -5 then begin
      KMAT := KMAT + -5;
      Mostra_Cds(' ');
    end;
  end
  else begin
    // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FORMADESELECIONARRITMO,"Paginando",param_3,Self, Sender);
    if (iVar1 = 0) and (NUMRITMOSELECIONADO + -5 <= TOTALMMRITMO) then begin
      NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + -5;
      Mostra_Ritmos;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
      Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__CAPASELECIONADACLICK$TOBJECT }
procedure TForm1.CapaSelecionadaClick(Sender: TObject);
begin
  Rotina_Tocar;
end;

{ JUKELINUX1_TFORM1_$__CHECKBOX1CHANGE$TOBJECT }
procedure TForm1.CheckBox1Change(Sender: TObject);
var
  cVar1: Boolean;
begin
  // C: cVar1 = ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x5b0) + 0x450))(Form1.CheckBox1);
  if cVar1 then begin
    Form1.ShellTreeViewCC.Show;
    Form1.EditCC.Show;
  end;
end;

{ JUKELINUX1_TFORM1_$__CHECKBOXRESOLUCAOMONITORCHANGE$TOBJECT }
procedure TForm1.CheckBoxResolucaoMonitorChange(Sender: TObject);
var
  local_134, local_138: AnsiString;
  cVar1: Boolean;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: cVar1 = ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x69c) + 0x450))(Form1.CheckBoxResolucaoMonitor);
    if cVar1 then begin
      local_138 := PASTA + 'alterarresolucaodolinux.txt';
      local_134 := local_138;
      AssignFile(ARQTEXTO, local_134);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, 83);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    // C: cVar1 = ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x69c) + 0x450))(Form1.CheckBoxResolucaoMonitor);
    if not cVar1 then begin
      local_138 := PASTA + 'alterarresolucaodolinux.txt';
      local_134 := local_138;
      AssignFile(ARQTEXTO, local_134);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, 78);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX10CHANGE$TOBJECT }
procedure TForm1.ComboBox10Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox10 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox10 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox10,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox10 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox10 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'cartaojukebox.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox10,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Cartao Jukebox = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox10,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox10,&local_140);
      CARTAOJUKEBOX := local_140;
    end
    else begin
      Form1.ComboBox10.Caption := CARTAOJUKEBOX;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX11CHANGE$TOBJECT }
procedure TForm1.ComboBox11Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox11 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox11 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox11,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox11 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox11 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'selecaomusicagratis.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox11,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox11,&local_3c);
      SELECAOMG := local_3c;
      // C: local_48 = "Alteracao no Menu - Seleção de Musica Gratis = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox11,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
    end
    else begin
      Form1.ComboBox11.Caption := SELECAOMG;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX12CHANGE$TOBJECT }
procedure TForm1.ComboBox12Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox12 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox12 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox12,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox12 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox12 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'sentidodapaginacao.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox12,&local_3c);
      SENTIDODAPAGINACAO := local_3c;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Sentido da Paginacao  = [";
      local_44 := SENTIDODAPAGINACAO;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
    end
    else begin
      Form1.ComboBox12.Caption := SENTIDODAPAGINACAO;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX13CHANGE$TOBJECT }
procedure TForm1.ComboBox13Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox13 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox13 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox13,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox13 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox13 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'sorteiodecreditos.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox13,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox13,&local_3c);
      SORTEIODECREDITOS := local_3c;
      // C: local_48 = "Alteracao no Menu - Sorteio de Creditos = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox13,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
    end
    else begin
      Form1.ComboBox13.Caption := SORTEIODECREDITOS;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX14CHANGE$TOBJECT }
procedure TForm1.ComboBox14Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox14 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox14 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox14,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox14 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox14 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'palhinhamusical.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox14,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Palhinha Musical = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox14,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox14,&local_140);
      PALHINHAMUSICAL := local_140;
    end
    else begin
      Form1.ComboBox14.Caption := PALHINHAMUSICAL;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX15CHANGE$TOBJECT }
procedure TForm1.ComboBox15Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox15 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox15 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox15,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox15 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox15 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'formadepaginacao.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox15,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox15,&local_3c);
      FORMADEPAGINACAO := local_3c;
      // C: local_48 = "Alteracao no Menu - Forma De Paginacao= [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox15,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
    end
    else begin
      Form1.ComboBox15.Caption := FORMADEPAGINACAO;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX16CHANGE$TOBJECT }
procedure TForm1.ComboBox16Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox16 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox16 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox16,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox16 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox16 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'aumentavolumecomumtoque.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox16,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox16,&local_3c);
      AUMENTAVOLUMECOMUMTOQUE := local_3c;
      // C: local_48 = "Alteracao no Menu - Aumentavolumecomumtoque = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox16,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
    end
    else begin
      Form1.ComboBox16.Caption := AUMENTAVOLUMECOMUMTOQUE;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX18CHANGE$TOBJECT }
procedure TForm1.ComboBox18Change(Sender: TObject);
var
  local_13c, local_140, local_144, local_3c, local_48: AnsiString;
  local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox18,local_3c);
    local_10 := StrToIntDef(local_3c, -1);
    if local_10 < 0 then begin
      local_144 := IntToStr(QTDCREDITOSGRATIS);
      Form1.ComboBox18.Caption := local_144;
    end
    else begin
      local_3c := PASTA + 'qtdcreditosgratis.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox18,&local_140);
      local_3c := Cripta(local_140);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Qtd de Creditos Gratis no Fechamento de Caixa = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox18,local_3c);
      local_44 := local_3c;
      local_40 := ']';
      local_140 := local_48 + local_44 + local_40;
      Gravalog(local_140);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox18,&local_140);
      QTDCREDITOSGRATIS := StrToIntDef(local_140, 0);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX19CHANGE$TOBJECT }
procedure TForm1.ComboBox19Change(Sender: TObject);
var
  local_13c, local_140, local_144, local_3c, local_48: AnsiString;
  local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox19,local_3c);
    local_10 := StrToIntDef(local_3c, -1);
    if local_10 < 0 then begin
      local_144 := IntToStr(QTDCREDITOSGRATISVIP);
      Form1.ComboBox19.Caption := local_144;
    end
    else begin
      local_3c := PASTA + 'qtdcreditosgratisvip.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox19,&local_140);
      local_3c := Cripta(local_140);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Qtd de Creditos Gratis VIP no Fechamento de Caixa = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox19,local_3c);
      local_44 := local_3c;
      local_40 := ']';
      local_140 := local_48 + local_44 + local_40;
      Gravalog(local_140);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox19,&local_140);
      QTDCREDITOSGRATISVIP := StrToIntDef(local_140, 0);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX1CHANGE$TOBJECT }
procedure TForm1.ComboBox1Change(Sender: TObject);
var
  local_188, local_38, local_3c, local_48, local_4c, local_58, local_68, local_74, local_78, local_7c, local_80, local_84, local_88, local_94, uVar1: AnsiString;
  iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44, local_50, local_54, local_5c, local_60, local_64, local_6c, local_70, local_8c, local_90: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox1 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox1 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox1,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox1 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox1 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox1,local_38);
      if local_38 = 'Livre' then begin
        // C: local_48 = "Tentativa de Alteracao no Menu - ReaisXMusicas = [";
        local_44 := REAISXMUSICAS;
        local_40 := '] - ***Solicitado a Contra Senha***';
        local_3c := local_48 + local_44 + local_40;
        Gravalog(local_3c);
        Randomize;
        KR1 := Random(99);
        if KR1 < 20 then begin
          KR1 := KR1 + 20;
        end;
        Randomize;
        KR2 := Random(99);
        if KR2 < 20 then begin
          KR2 := KR2 + 36;
        end;
        Randomize;
        KR3 := Random(59);
        if KR3 < 20 then begin
          KR3 := KR3 + 22;
        end;
        Randomize;
        KR4 := Random(79);
        if KR4 < 20 then begin
          KR4 := KR4 + 19;
        end;
        Randomize;
        KR5 := Random(49);
        if KR5 < 20 then begin
          KR5 := KR5 + 39;
        end;
        Randomize;
        KR6 := Random(39);
        if KR6 < 20 then begin
          KR6 := KR6 + 23;
        end;
        if KR1 = KR2 then begin
          KR2 := KR2 + 13;
        end;
        if 100 < KR2 then begin
          KR2 := KR2 + -25;
        end;
        if 100 < KR2 then begin
          KR2 := 20;
        end;
        if KR3 = KR4 then begin
          KR3 := KR3 + 19;
        end;
        if 100 < KR4 then begin
          KR4 := KR4 + -28;
        end;
        if 100 < KR4 then begin
          KR4 := 30;
        end;
        if KR5 = KR6 then begin
          KR5 := KR5 + 13;
        end;
        if 100 < KR6 then begin
          KR6 := KR6 + -29;
        end;
        if 100 < KR6 then begin
          KR2 := 40;
        end;
        Form1.LabelAtivacao1.Caption := 'Alteração p/ Créditos Livre';
        ATIVACAO := 'livre';
        local_74 := CODIGODAMAQUINASTR;
        local_70 := '-';
        local_3c := IntToStr(KR1);
        local_6c := local_3c;
        local_78 := IntToStr(KR2);
        local_68 := local_78;
        local_64 := '-';
        local_7c := IntToStr(KR3);
        local_60 := local_7c;
        local_80 := IntToStr(KR4);
        local_5c := local_80;
        local_58 := '-';
        local_84 := IntToStr(KR5);
        local_54 := local_84;
        local_88 := IntToStr(KR6);
        local_50 := local_88;
        local_4c := local_74 + local_70 + local_6c + local_68 + local_64 + local_60 + local_5c + local_58 + local_54 + local_50;
        Form1.LabelAtivacao2.Caption := local_4c;
        Form1.PanelErro.Hide;
        Form1.PanelAtivacao.Align := alClient;
        Form1.PanelAtivacao.Show;
        Form1.PanelAtivacao.BringToFront;
        // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9c0) + 0x430))(Form1.EditSenhaAtivacao);
      end
      else begin
        local_88 := PASTA + 'reaisxmusicas.txt';
        local_188 := local_88;
        AssignFile(ARQTEXTO, local_188);
        Rewrite(ARQTEXTO);
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox1,&local_88);
        REAISXMUSICAS := local_88;
        // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        // C: local_94 = "Alteracao no Menu - ReaisXMusicas = [";
        local_90 := REAISXMUSICAS;
        local_8c := ']';
        local_88 := local_94 + local_90 + local_8c;
        Gravalog(local_88);
      end;
    end
    else begin
      Form1.ComboBox1.Caption := REAISXMUSICAS;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX20CHANGE$TOBJECT }
procedure TForm1.ComboBox20Change(Sender: TObject);
var
  local_134, local_138, local_140, local_38, local_48: AnsiString;
  local_c: TForm1;
  local_8: TObject;
  local_13c, local_3c, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    local_138 := PASTA + 'resolucaotv.txt';
    local_134 := local_138;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox20,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox21,&local_138);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    // C: local_48 = "Alteracao no Menu - ResolucaoTV = [";
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox20,&local_13c);
    local_44 := local_13c;
    local_40 := 'x';
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox21,&local_140);
    local_3c := local_140;
    local_38 := ']';
    local_138 := local_48 + local_44 + local_40 + local_3c + local_38;
    Gravalog(local_138);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox20,&local_140);
    RESOLUCAOTVX := StrToIntDef(local_140, 800);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox21,&local_140);
    RESOLUCAOTVY := StrToIntDef(local_140, 600);
    Define_Exibirvideos;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX22CHANGE$TOBJECT }
procedure TForm1.ComboBox22Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox22 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox22 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox22,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox22 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox22 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'autoteste.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox22,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - AutoTeste ao Ligar = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox22,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox22,&local_140);
      AUTOTESTE := local_140;
    end
    else begin
      Form1.ComboBox22.Caption := AUTOTESTE;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX23CHANGE$TOBJECT }
procedure TForm1.ComboBox23Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox23 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox23 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox23,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox23 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox23 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'volumepelopainel.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox23,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - VolumePeloPainel = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox23,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox23,&local_140);
      VOLUMEPELOPAINEL := local_140;
    end
    else begin
      Form1.ComboBox23.Caption := VOLUMEPELOPAINEL;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX2CHANGE$TOBJECT }
procedure TForm1.ComboBox2Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox2 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox2 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox2,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox2 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox2 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'exibirvideosno.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox2,&local_3c);
      EXIBIRVIDEOSNO := local_3c;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - ExibirVideosNo = [";
      local_44 := EXIBIRVIDEOSNO;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      Define_Exibirvideos;
    end
    else begin
      Form1.ComboBox2.Caption := EXIBIRVIDEOSNO;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX3CHANGE$TOBJECT }
procedure TForm1.ComboBox3Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox3 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox3 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox3,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox3 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox3 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'ordemdoscds.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox3,&local_3c);
      ORDEMDOSCDS := local_3c;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - OrdemDosCds = [";
      local_44 := ORDEMDOSCDS;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      Desselecionamusica;
      MUSICASELECIONADA := 0;
      MUSICASELECIONADAPOSTELA := 0;
      MUSICASELECIONADATS := 0;
      Selecionamusica;
      Carregando_Cds;
      KMAT := -4;
      MUSICASELECIONADA := 0;
      MUSICASELECIONADAPOSTELA := 0;
      MUSICASELECIONADATS := 0;
      if RESOLUCAO = 1366 then begin
        TAMANHOMUSICAGRANDE := 30;
      end;
      if RESOLUCAO = 1024 then begin
        TAMANHOMUSICAGRANDE := 22;
      end;
      if RESOLUCAO = 1440 then begin
        TAMANHOMUSICAGRANDE := 30;
      end;
      SOMAMUSICAGRANDE := 0;
      MOSTRANDORITMOS := 0;
      MOSTRANDOLETRAS := 0;
      Mostra_Cds(' ');
      Mostra_Nome_Das_Musicas;
      Mostra_Fila;
    end
    else begin
      Form1.ComboBox3.Caption := ORDEMDOSCDS;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX4CHANGE$TOBJECT }
procedure TForm1.ComboBox4Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox4 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox4 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox4,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox4 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox4 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'musicagratis.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox4,&local_3c);
      MUSICAGRATIS := local_3c;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - MusicaGratis= [";
      local_44 := MUSICAGRATIS;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      if MUSICAGRATIS = 'Sem Musica Gratis' then begin
        Form1.TimerMusicaGratis.Enabled := False;
      end
      else begin
        Form1.TimerMusicaGratis.Enabled := True;
      end;
      TOCANDOMUSICAGRATIS := 0;
    end
    else begin
      Form1.ComboBox4.Caption := MUSICAGRATIS;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX5CHANGE$TOBJECT }
procedure TForm1.ComboBox5Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox5 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox5 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox5,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox5 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox5 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'propaganda.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox5,&local_3c);
      PROPAGANDA := local_3c;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Propaganda= [";
      local_44 := PROPAGANDA;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      ALTEROUPRO := 1;
    end
    else begin
      Form1.ComboBox5.Caption := PROPAGANDA;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX6CHANGE$TOBJECT }
procedure TForm1.ComboBox6Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox6 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox6 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox6,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox6 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox6 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'limitarvolume.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox6,&local_3c);
      LIMITARVOLUMEOPC := local_3c;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox6,&local_3c);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      local_3c := Copy(LIMITARVOLUMEOPC, 1, 1);
      if local_3c = 'N' then begin
        // C: U_JUKELINUX1_LIMITARVOLUMESTR._0_2_ = 0x3001;
      end
      else begin
        local_3c := Copy(LIMITARVOLUMEOPC, 19, 2);
        LIMITARVOLUMESTR := local_3c;
      end;
      LIMITARVOLUMESTR := local_3c;
      LIMITARVOLUME := StrToIntDef(local_3c, 100);
      // C: local_48 = "Alteracao no Menu - LimitarVolume= [";
      local_44 := LIMITARVOLUMEOPC;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
    end
    else begin
      Form1.ComboBox6.Caption := LIMITARVOLUMEOPC;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX7CHANGE$TOBJECT }
procedure TForm1.ComboBox7Change(Sender: TObject);
var
  local_13c, local_140, local_144, local_148, local_248, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox7 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox7 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox7,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox7 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox7 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'resolucao.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox7,&local_3c);
      RESOLUCAOOPC := local_3c;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox7,&local_140);
      if local_140 = 'Automatico' then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox7,&local_144);
        Write(ARQTEXTO, local_144);
        Writeln(ARQTEXTO);
      end
      else begin
        // C: puVar5 = &local_3c;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox7,&local_144);
        // C: fpc_ansistr_copy(local_144,1,4,puVar5);
        Write(ARQTEXTO, local_3c);
        Writeln(ARQTEXTO);
      end;
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Resolucao = [";
      // C: puVar5 = &local_3c;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox7,&local_148);
      // C: fpc_ansistr_copy(local_148,1,4,puVar5);
      local_44 := local_3c;
      local_40 := ']';
      local_144 := local_48 + local_44 + local_40;
      Gravalog(local_144);
      // C: puVar5 = &local_148;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox7,&local_144);
      // C: fpc_ansistr_copy(local_144,1,4,puVar5);
      if local_148 = '1024' then begin
        if PROPAGANDA = 'Fotos PNG no Monitor' then begin
          PROPAGANDA := 'Fotos para Bar no Monitor';
          local_148 := PASTA + 'propaganda.txt';
          local_248 := local_148;
          AssignFile(ARQTEXTO, local_248);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          CloseFile(ARQTEXTO);
          Form1.ComboBox5.Caption := TEXTO;
        end;
      end;
      ShowMessage('ATENÇÃO: a Resolução da Tela será Alterada após a Jukebox Ser Desligada e Ligada Novamente');
    end
    else begin
      Form1.ComboBox7.Caption := RESOLUCAOOPC;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX8CHANGE$TOBJECT }
procedure TForm1.ComboBox8Change(Sender: TObject);
var
  local_13c, local_140, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_144, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox8 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox8 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox8,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox8 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox8 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'bloquearquandotocar.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox8,&local_3c);
      BLOQUEARQUANDOTOCAROPC := local_3c;
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox8,&local_140);
      if local_140 = 'Não Bloquear Nunca' then begin
        TEXTO := '-1';
      end
      else begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox8,&local_3c);
        TEXTO := local_3c;
      end;
      local_3c := Criptasuper2(JC_SERIALPENDRIVECON);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      local_3c := Criptasuper2(TEXTO);
      Write(ARQTEXTO, local_3c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Bloquear Quando Tocas (Musicas) = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox8,&local_144);
      local_44 := local_144;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
      BLOQUEARQUANDOTOCAR := StrToIntDef(TEXTO, -1);
    end
    else begin
      Form1.ComboBox8.Caption := BLOQUEARQUANDOTOCAROPC;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOX9CHANGE$TOBJECT }
procedure TForm1.ComboBox9Change(Sender: TObject);
var
  local_13c, local_3c, local_48, uVar1: AnsiString;
  iVar3, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_140, local_40, local_44: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OKC := 0;
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ComboBox9 + 0x36c) + 0x80)) ( *(undefined4 * )(Form1.ComboBox9 + 0x36c));
    KKC := 0;
    if -1 < iVar3 + -1 then begin
      KKC := -1;
      repeat
        KKC := KKC + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox9,local_38);
        // C: uVar1 = local_38[0];
        // C: ( **(code ** )( **(int ** )(Form1.ComboBox9 + 0x36c) + 0x78)) ( *(undefined4 * )(Form1.ComboBox9 + 0x36c),U_JUKELINUX1_KKC,&local_3c);
        if local_3c = uVar1 then begin
          OKC := 1;
        end;
      until not (KKC < iVar3 + -1);
    end;
    if OKC = 1 then begin
      local_3c := PASTA + 'formadeselecionarritmo.txt';
      local_13c := local_3c;
      AssignFile(ARQTEXTO, local_13c);
      Rewrite(ARQTEXTO);
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox9,&local_3c);
      FORMADESELECIONARRITMO := local_3c;
      // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      // C: local_48 = "Alteracao no Menu - Forma De Selecionar Ritmo = [";
      // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBox9,&local_140);
      local_44 := local_140;
      local_40 := ']';
      local_3c := local_48 + local_44 + local_40;
      Gravalog(local_3c);
    end
    else begin
      Form1.ComboBox9.Caption := FORMADESELECIONARRITMO;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOXMG1CHANGE$TOBJECT }
procedure TForm1.ComboBoxMG1Change(Sender: TObject);
var
  local_140, local_3c, local_40: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMATEXCLUI * 0x240 + 0x1f8));
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_3c := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_3c[0],"[.]") } then begin
          local_3c := Form1.FileListBox1.Items[local_10];
          if False { C: STRNE(local_3c[0],"[..]") } then begin
            local_40 := Form1.FileListBox1.Items[local_10];
            local_3c := UpperCase(local_40);
            if local_3c = 'GENERO.TXT' then begin
              local_3c := Form1.FileListBox1.Items[local_10];
              // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMATEXCLUI * 0x240 + 0x1f8), local_3c[0]);
              cVar1 := FileExists(local_40);
              if cVar1 then begin
                local_3c := Form1.FileListBox1.Items[local_10];
                // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMATEXCLUI * 0x240 + 0x1f8), local_3c[0]);
                DeleteFile(local_40);
              end;
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KMATEXCLUI * 0x240 + 0x1f8), "genero.txt");
    local_140 := local_40;
    AssignFile(ARQTEXTO, local_140);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBoxMG1,&local_40);
    Write(ARQTEXTO, local_40);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    RELECDS := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOXMG2CHANGE$TOBJECT }
procedure TForm1.ComboBoxMG2Change(Sender: TObject);
var
  local_140, local_3c, local_40: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 1) * 0x240 + 0x1f8));
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_3c := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_3c[0],"[.]") } then begin
          local_3c := Form1.FileListBox1.Items[local_10];
          if False { C: STRNE(local_3c[0],"[..]") } then begin
            local_40 := Form1.FileListBox1.Items[local_10];
            local_3c := UpperCase(local_40);
            if local_3c = 'GENERO.TXT' then begin
              local_3c := Form1.FileListBox1.Items[local_10];
              // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 1) * 0x240 + 0x1f8),local_3c[0]);
              cVar1 := FileExists(local_40);
              if cVar1 then begin
                local_3c := Form1.FileListBox1.Items[local_10];
                // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 1) * 0x240 + 0x1f8),local_3c[0]);
                DeleteFile(local_40);
              end;
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 1) * 0x240 + 0x1f8), "genero.txt");
    local_140 := local_40;
    AssignFile(ARQTEXTO, local_140);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBoxMG2,&local_40);
    Write(ARQTEXTO, local_40);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    RELECDS := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOXMG3CHANGE$TOBJECT }
procedure TForm1.ComboBoxMG3Change(Sender: TObject);
var
  local_140, local_3c, local_40: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 2) * 0x240 + 0x1f8));
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_3c := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_3c[0],"[.]") } then begin
          local_3c := Form1.FileListBox1.Items[local_10];
          if False { C: STRNE(local_3c[0],"[..]") } then begin
            local_40 := Form1.FileListBox1.Items[local_10];
            local_3c := UpperCase(local_40);
            if local_3c = 'GENERO.TXT' then begin
              local_3c := Form1.FileListBox1.Items[local_10];
              // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 2) * 0x240 + 0x1f8),local_3c[0]);
              cVar1 := FileExists(local_40);
              if cVar1 then begin
                local_3c := Form1.FileListBox1.Items[local_10];
                // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 2) * 0x240 + 0x1f8),local_3c[0]);
                DeleteFile(local_40);
              end;
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 2) * 0x240 + 0x1f8), "genero.txt");
    local_140 := local_40;
    AssignFile(ARQTEXTO, local_140);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBoxMG3,&local_40);
    Write(ARQTEXTO, local_40);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    RELECDS := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOXMG4CHANGE$TOBJECT }
procedure TForm1.ComboBoxMG4Change(Sender: TObject);
var
  local_140, local_3c, local_40: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 3) * 0x240 + 0x1f8));
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_3c := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_3c[0],"[.]") } then begin
          local_3c := Form1.FileListBox1.Items[local_10];
          if False { C: STRNE(local_3c[0],"[..]") } then begin
            local_40 := Form1.FileListBox1.Items[local_10];
            local_3c := UpperCase(local_40);
            if local_3c = 'GENERO.TXT' then begin
              local_3c := Form1.FileListBox1.Items[local_10];
              // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 3) * 0x240 + 0x1f8),local_3c[0]);
              cVar1 := FileExists(local_40);
              if cVar1 then begin
                local_3c := Form1.FileListBox1.Items[local_10];
                // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 3) * 0x240 + 0x1f8),local_3c[0]);
                DeleteFile(local_40);
              end;
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 3) * 0x240 + 0x1f8), "genero.txt");
    local_140 := local_40;
    AssignFile(ARQTEXTO, local_140);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBoxMG4,&local_40);
    Write(ARQTEXTO, local_40);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    RELECDS := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOXMG5CHANGE$TOBJECT }
procedure TForm1.ComboBoxMG5Change(Sender: TObject);
var
  local_140, local_3c, local_40: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 4) * 0x240 + 0x1f8));
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_3c := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_3c[0],"[.]") } then begin
          local_3c := Form1.FileListBox1.Items[local_10];
          if False { C: STRNE(local_3c[0],"[..]") } then begin
            local_40 := Form1.FileListBox1.Items[local_10];
            local_3c := UpperCase(local_40);
            if local_3c = 'GENERO.TXT' then begin
              local_3c := Form1.FileListBox1.Items[local_10];
              // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 4) * 0x240 + 0x1f8),local_3c[0]);
              cVar1 := FileExists(local_40);
              if cVar1 then begin
                local_3c := Form1.FileListBox1.Items[local_10];
                // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 4) * 0x240 + 0x1f8),local_3c[0]);
                DeleteFile(local_40);
              end;
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 4) * 0x240 + 0x1f8), "genero.txt");
    local_140 := local_40;
    AssignFile(ARQTEXTO, local_140);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBoxMG5,&local_40);
    Write(ARQTEXTO, local_40);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    RELECDS := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOXMG6CHANGE$TOBJECT }
procedure TForm1.ComboBoxMG6Change(Sender: TObject);
var
  local_140, local_3c, local_40: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING (Form1.FileListBox1, *(undefined4 * )(U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 5) * 0x240 + 0x1f8));
    iVar3 := Form1.FileListBox1.Count;
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        local_3c := Form1.FileListBox1.Items[local_10];
        if False { C: STRNE(local_3c[0],"[.]") } then begin
          local_3c := Form1.FileListBox1.Items[local_10];
          if False { C: STRNE(local_3c[0],"[..]") } then begin
            local_40 := Form1.FileListBox1.Items[local_10];
            local_3c := UpperCase(local_40);
            if local_3c = 'GENERO.TXT' then begin
              local_3c := Form1.FileListBox1.Items[local_10];
              // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 5) * 0x240 + 0x1f8),local_3c[0]);
              cVar1 := FileExists(local_40);
              if cVar1 then begin
                local_3c := Form1.FileListBox1.Items[local_10];
                // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 5) * 0x240 + 0x1f8),local_3c[0]);
                DeleteFile(local_40);
              end;
            end;
          end;
        end;
      until not (local_10 < iVar3 + -1);
    end;
    // C: fpc_ansistr_concat(&local_40, *(undefined4 * ) (U_JUKELINUX1_ARQLOG + (U_JUKELINUX1_KMATEXCLUI + 5) * 0x240 + 0x1f8), "genero.txt");
    local_140 := local_40;
    AssignFile(ARQTEXTO, local_140);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBoxMG6,&local_40);
    Write(ARQTEXTO, local_40);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    RELECDS := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__COMBOBOXMUSPERIODOCHANGE$TOBJECT }
procedure TForm1.ComboBoxMusPeriodoChange(Sender: TObject);
begin

end;

{ JUKELINUX1_TFORM1_$__COMBOBOXPORCENTOCHANGE$TOBJECT }
procedure TForm1.ComboBoxPorcentoChange(Sender: TObject);
var
  local_134, local_138, local_38, local_40: AnsiString;
  local_c: TForm1;
  local_8: TObject;
  local_3c: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    local_138 := PASTA + 'porcentagemdoponto.txt';
    local_134 := local_138;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.ComboBoxPorcento,&local_138);
    PORCENTAGEMDOPONTOSTR := local_138;
    // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
    // C: local_40 = "Alteracao no Menu - PorcentagemDoPonto = [";
    local_3c := PORCENTAGEMDOPONTOSTR;
    local_38 := ']';
    local_138 := local_40 + local_3c + local_38;
    Gravalog(local_138);
    PORCENTAGEMDOPONTO := StrToIntDef(PORCENTAGEMDOPONTOSTR, 30);
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCANCELARKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCancelarKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'cancelar';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCDMAISKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCDMaisKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'cd+';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCDMENOSKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCDMenosKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'cd-';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCREDITO2KEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCredito2KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'credito2';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCREDITOKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCreditoKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'credito';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCREDITOVIPKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCreditoVIPKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'VIP';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCRMAISKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCRMaisKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'cr+';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITCRMENOSKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditCRMenosKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'cr-';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITMENUTECLAKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditMenuTeclaKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'menu';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITMUSICAMAISKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditMusicaMaisKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'musica+';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITMUSICAMENOSKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditMusicaMenosKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'musica-';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITRITMOKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditRitmoKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'ritmo';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITSENHAATIVACAOKEYPRESS$TOBJECT$CHAR }
procedure TForm1.EditSenhaAtivacaoKeyPress(Sender: TObject; var Key: Char);
begin
  if Key = #13 then begin
    // C: JUKELINUX1_TFORM1____BUTTONATIVARCLICK_TOBJECT(Self,U_JUKELINUX1_FORM1);
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITSENHAKEYPRESS$TOBJECT$CHAR }
procedure TForm1.EditSenhaKeyPress(Sender: TObject; var Key: Char);
begin
  if (Key = #13) and (ESTADIGITANDOSENHA = 2) then begin
    // C: JUKELINUX1_TFORM1____BUTTONOKSENHACLICK_TOBJECT(Self,U_JUKELINUX1_FORM1);
  end;
end;

{ JUKELINUX1_TFORM1_$__EDITTOCARKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.EditTocarKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING( *local_c,local_3c);
    TEMPTECLA := local_3c;
    FUNCAOTECLA := 'tocar';
    Form1.TimerConfigInterface.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__FORMACTIVATE$TOBJECT }
procedure TForm1.FormActivate(Sender: TObject);
var
  local_104, local_1f4, local_1f8, local_1fc, local_200, local_3c, local_40, local_44, local_48, local_58, local_68, local_6c, local_70, local_74, local_78, local_7c, local_88, local_8c, local_90, local_94, local_98, local_a8, local_ac, local_b0, local_b8, local_c0, local_c4, local_c8, local_d8, local_dc, local_e0, local_e8, local_f0, local_f4, local_f8: AnsiString;
  cVar1: Boolean;
  iVar3, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_100, local_4c, local_50, local_54, local_5c, local_60, local_64, local_80, local_84, local_9c, local_a0, local_a4, local_b4, local_bc, local_cc, local_d0, local_d4, local_e4, local_ec, local_fc: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    if ROTINA_DO_ACTIVATE = 1 then begin
      local_40 := IntToStr(ROTINA_DO_ACTIVATE);
      local_3c := 'Inico da Rotina Activate: ' + local_40;
      Gravalog(local_3c);
      if ERROSERIALNUM = 0 then begin
        ROTINA_DO_ACTIVATE := 2;
      end
      else begin
        Form1.PanelErro.Align := alClient;
        Form1.LabelErro1.Caption := 'Erro';
        local_44 := IntToStr(ERROSERIALNUM);
        Form1.LabelErro2.Caption := local_44;
        Form1.MemoErro.Caption := ERROSERIAL;
        Form1.PanelErro.Show;
        Form1.PanelErro.BringToFront;
        if ERROSERIALNUM = 9 then begin
          MUSICAGRATIS := 'Sem Musica Gratis';
          Randomize;
          KR1 := Random(99);
          if KR1 < 20 then begin
            KR1 := KR1 + 20;
          end;
          Randomize;
          KR2 := Random(95);
          if KR2 < 20 then begin
            KR2 := KR2 + 36;
          end;
          Randomize;
          KR3 := Random(59);
          if KR3 < 20 then begin
            KR3 := KR3 + 22;
          end;
          Randomize;
          KR4 := Random(79);
          if KR4 < 20 then begin
            KR4 := KR4 + 19;
          end;
          Randomize;
          KR5 := Random(49);
          if KR5 < 20 then begin
            KR5 := KR5 + 39;
          end;
          Randomize;
          KR6 := Random(79);
          if KR6 < 20 then begin
            KR6 := KR6 + 23;
          end;
          if KR1 = KR2 then begin
            KR2 := KR2 + 13;
          end;
          if 100 < KR2 then begin
            KR2 := KR2 + -25;
          end;
          if 100 < KR2 then begin
            KR2 := 20;
          end;
          if KR3 = KR4 then begin
            KR3 := KR3 + 19;
          end;
          if 100 < KR4 then begin
            KR4 := KR4 + -28;
          end;
          if 100 < KR4 then begin
            KR4 := 30;
          end;
          if KR5 = KR6 then begin
            KR5 := KR5 + 13;
          end;
          if 100 < KR6 then begin
            KR6 := KR6 + -29;
          end;
          if 100 < KR6 then begin
            KR2 := 40;
          end;
          Form1.LabelAtivacao1.Caption := 'Troca de PenDrive Chave';
          ATIVACAO := 'pendrive';
          local_6c := CODIGODAMAQUINASTR;
          local_68 := '-';
          local_40 := IntToStr(KR1);
          local_64 := local_40;
          local_3c := IntToStr(KR2);
          local_60 := local_3c;
          local_5c := '-';
          local_70 := IntToStr(KR3);
          local_58 := local_70;
          local_74 := IntToStr(KR4);
          local_54 := local_74;
          local_50 := '-';
          local_78 := IntToStr(KR5);
          local_4c := local_78;
          local_7c := IntToStr(KR6);
          local_48 := local_7c;
          local_44 := local_6c + local_68 + local_64 + local_60 + local_5c + local_58 + local_54 + local_50 + local_4c + local_48;
          Form1.LabelAtivacao2.Caption := local_44;
          Form1.PanelErro.Hide;
          Form1.PanelAtivacao.Align := alClient;
          Form1.PanelAtivacao.Show;
          Form1.PanelAtivacao.BringToFront;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9c0) + 0x430))(Form1.EditSenhaAtivacao);
        end;
      end;
    end;
    if ROTINA_DO_ACTIVATE = 2 then begin
      local_78 := IntToStr(ROTINA_DO_ACTIVATE);
      local_7c := 'Inico da Rotina Activate: ' + local_78;
      Gravalog(local_7c);
      OPC := 2;
      // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_JC_RELOGIOTOTALSTR,U_JUKELINUX1_RELOGIOTOTALSTR);
      if False { C: (((iVar3 == 0) && (iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_JC_RELOGIOPARCIALSTR,U_JUKELINUX1_RELOGIOPARCIALSTR), iVar3 == 0)) && (iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_JC_RELOGIOGRATISSTR,U_JUKELINUX1_RELOGIOGRATISSTR), iVar3 == 0)) && (iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_JC_RELOGIOGRATISVIPSTR,U_JUKELINUX1_RELOGIOGRATISVIPSTR), iVar3 == 0) } then begin
        OPC := 1;
      end;
      if OPC = 1 then begin
        // C: local_50 = "Relogios do PenDrive [";
        local_4c := JC_SERIALPENDRIVE;
        local_48 := '] e da Jukebox estao Iguais';
        local_7c := local_50 + local_4c + local_48;
        Gravalog(local_7c);
        Gravalog('                   Jukebox   PenDrive');
        local_54 := 'Relogio Total....: ';
        local_78 := Strzero(RELOGIOTOTALSTR, 6);
        local_50 := local_78;
        local_4c := '    ';
        local_74 := Strzero(JC_RELOGIOTOTALSTR, 6);
        local_48 := local_74;
        local_7c := local_54 + local_50 + local_4c + local_48;
        Gravalog(local_7c);
        local_8c := 'Relogio Parcial..: ';
        local_78 := Strzero(RELOGIOPARCIALSTR, 6);
        local_88 := local_78;
        local_84 := '    ';
        local_74 := Strzero(JC_RELOGIOPARCIALSTR, 6);
        local_80 := local_74;
        local_7c := local_8c + local_88 + local_84 + local_80;
        Gravalog(local_7c);
        local_8c := 'Relogio Gratis...: ';
        local_90 := Strzero(RELOGIOGRATISSTR, 6);
        local_88 := local_90;
        local_84 := '    ';
        local_94 := Strzero(JC_RELOGIOGRATISSTR, 6);
        // C: local_80 = (char * )local_94;
        local_7c := local_8c + local_88 + local_84 + local_80;
        Gravalog(local_7c);
        local_8c := 'Relogio GratisVIP: ';
        local_90 := Strzero(RELOGIOGRATISVIPSTR, 6);
        local_88 := local_90;
        local_84 := '    ';
        local_7c := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
        local_80 := local_7c;
        local_94 := local_8c + local_88 + local_84 + local_80;
        Gravalog(local_94);
      end
      else begin
        // C: iVar3 = fpc_ansistr_compare_equal(U_JUKELINUX1_JC_CODIGODAMAQUINA,"0");
        PENDRIVEZERADO := Ord(iVar3 = 0);
        if False then begin // ?: (bool)PENDRIVEZERADO
          Gravalog('Pendrive Zerado assume os Relogios da Jukebox');
          // C: fpc_ansistr_concat(&local_94,"[PENDRIVE CHAVE ZERADO] : ",U_JUKELINUX1_JC_SERIALPENDRIVE);
          Gravalog(local_94);
          Gravalog('                   Jukebox   PenDrive');
          local_8c := 'Relogio Total....: ';
          local_90 := Strzero(RELOGIOTOTALSTR, 6);
          local_88 := local_90;
          local_84 := '    ';
          local_7c := Strzero(JC_RELOGIOTOTALSTR, 6);
          local_80 := local_7c;
          local_94 := local_8c + local_88 + local_84 + local_80;
          Gravalog(local_94);
          local_8c := 'Relogio Parcial..: ';
          local_90 := Strzero(RELOGIOPARCIALSTR, 6);
          local_88 := local_90;
          local_84 := '    ';
          local_7c := Strzero(JC_RELOGIOPARCIALSTR, 6);
          local_80 := local_7c;
          local_94 := local_8c + local_88 + local_84 + local_80;
          Gravalog(local_94);
          local_8c := 'Relogio Gratis...: ';
          local_90 := Strzero(RELOGIOGRATISSTR, 6);
          local_88 := local_90;
          local_84 := '    ';
          local_7c := Strzero(JC_RELOGIOGRATISSTR, 6);
          local_80 := local_7c;
          local_94 := local_8c + local_88 + local_84 + local_80;
          Gravalog(local_94);
          local_8c := 'Relogio GratisVIP: ';
          local_90 := Strzero(RELOGIOGRATISVIPSTR, 6);
          local_88 := local_90;
          local_84 := '    ';
          local_7c := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
          local_80 := local_7c;
          local_94 := local_8c + local_88 + local_84 + local_80;
          Gravalog(local_94);
          Grava_Pendrive_Contadores;
          Gravalog('Ajustado os Relogios do PenDrive');
        end
        else begin
          if JC_INI = JC_SERIALPENDRIVE then begin
            if JC_RELOGIOTOTAL < RELOGIOTOTAL then begin
              local_10 := 1;
            end;
            if JC_RELOGIOGRATIS < RELOGIOGRATIS then begin
              local_10 := 1;
            end;
            if JC_RELOGIOGRATISVIP < RELOGIOGRATISVIP then begin
              local_10 := 1;
            end;
            if RELOGIOTOTAL < JC_RELOGIOTOTAL then begin
              local_10 := 2;
            end;
            if RELOGIOPARCIAL < JC_RELOGIOPARCIAL then begin
              local_10 := 2;
            end;
            if RELOGIOGRATIS < JC_RELOGIOGRATIS then begin
              local_10 := 2;
            end;
            if RELOGIOGRATISVIP < JC_RELOGIOGRATISVIP then begin
              local_10 := 2;
            end;
            if local_10 = 1 then begin
              Gravalog('A Jukebox Foi Desligada ou o Software Fechado antes de 3 segundos apos o credito, e nao deu tempo para gravar no pendrive');
              // C: fpc_ansistr_concat(&local_f4,"[MESMO PENDRIVE CHAVE] : ",U_JUKELINUX1_JC_SERIALPENDRIVE);
              Gravalog(local_f4);
              // C: local_100 = "Relogios do PenDrive [";
              local_fc := JC_SERIALPENDRIVE;
              local_f8 := '] Sao Diferentes dos Relogios da Jukebox';
              local_f4 := local_100 + local_fc + local_f8;
              Gravalog(local_f4);
              Gravalog('                   Jukebox   PenDrive');
              local_104 := 'Relogio Total....: ';
              local_1f8 := Strzero(RELOGIOTOTALSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_1fc := Strzero(JC_RELOGIOTOTALSTR, 6);
              // C: local_f8 = (char * )local_1fc;
              local_f4 := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_f4);
              local_104 := 'Relogio Parcial..: ';
              local_1f8 := Strzero(RELOGIOPARCIALSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOPARCIALSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio Gratis...: ';
              local_1f8 := Strzero(RELOGIOGRATISSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOGRATISSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio GratisVIP: ';
              local_1f8 := Strzero(RELOGIOGRATISVIPSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              Grava_Pendrive_Contadores;
              Gravalog('Ajustado os Relogios do PenDrive');
            end;
            if local_10 = 2 then begin
              Gravalog('ATENCAO: Relogios da Jukebox estao Menores que o do PenDrive');
              // C: local_100 = "Relogios do PenDrive [";
              local_fc := JC_SERIALPENDRIVE;
              local_f8 := '] Sao Diferentes dos Relogios da Jukebox';
              local_1fc := local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              Gravalog('                   Jukebox   PenDrive');
              local_104 := 'Relogio Total....: ';
              local_1f8 := Strzero(RELOGIOTOTALSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOTOTALSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio Parcial..: ';
              local_1f8 := Strzero(RELOGIOPARCIALSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOPARCIALSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio Gratis...: ';
              local_1f8 := Strzero(RELOGIOGRATISSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOGRATISSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio GratisVIP: ';
              local_1f8 := Strzero(RELOGIOGRATISVIPSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              RELOGIOTOTALSTR := JC_RELOGIOTOTALSTR;
              RELOGIOPARCIALSTR := JC_RELOGIOPARCIALSTR;
              PORCENTAGEMDOPONTOSTR := JC_PORCENTAGEMDOPONTOSTR;
              RELOGIOGRATISSTR := JC_RELOGIOGRATISSTR;
              RELOGIOGRATISVIPSTR := JC_RELOGIOGRATISVIPSTR;
              RELOGIOTOTAL := StrToIntDef(RELOGIOTOTALSTR, 0);
              RELOGIOPARCIAL := StrToIntDef(RELOGIOPARCIALSTR, 0);
              PORCENTAGEMDOPONTO := StrToIntDef(PORCENTAGEMDOPONTOSTR, 30);
              RELOGIOGRATIS := StrToIntDef(RELOGIOGRATISSTR, 0);
              RELOGIOGRATISVIP := StrToIntDef(RELOGIOGRATISVIPSTR, 0);
              Grava_Hd_Relogios;
              Grava_Hd_Porcentagem;
              Grava_Hd_Relogiogratis;
              Grava_Hd_Relogiogratisvip;
              Gravalog('Ajustado os Relogios da jukebox');
              Gravalog('                   Jukebox   PenDrive');
              local_104 := 'Relogio Total....: ';
              local_1f8 := Strzero(RELOGIOTOTALSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOTOTALSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio Parcial..: ';
              local_1f8 := Strzero(RELOGIOPARCIALSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOPARCIALSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio Gratis...: ';
              local_1f8 := Strzero(RELOGIOGRATISSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOGRATISSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
              local_104 := 'Relogio GratisVIP: ';
              local_1f8 := Strzero(RELOGIOGRATISVIPSTR, 6);
              local_100 := local_1f8;
              local_fc := '    ';
              local_f4 := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
              // C: local_f8 = (char * )local_f4;
              local_1fc := local_104 + local_100 + local_fc + local_f8;
              Gravalog(local_1fc);
            end;
          end
          else begin
            Gravalog('ATENCAO: Foi Mudado de PENDRIVE CHAVE');
            local_8c := 'PenDrive Novo=';
            local_88 := JC_SERIALPENDRIVE;
            local_84 := '  PenDrive Anterior=';
            // C: local_80 = (char * )U_JUKELINUX1_JC_INI;
            local_94 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_94);
            // C: local_88 = "Relógios do PenDrive [";
            local_84 := JC_SERIALPENDRIVE;
            local_80 := '] SAo Diferentes dos Relogios da Jukebox';
            local_94 := local_88 + local_84 + local_80;
            Gravalog(local_94);
            Gravalog('                   Jukebox   PenDrive');
            local_8c := 'Relogio Total....: ';
            local_90 := Strzero(RELOGIOTOTALSTR, 6);
            local_88 := local_90;
            local_84 := '    ';
            local_98 := Strzero(JC_RELOGIOTOTALSTR, 6);
            local_80 := local_98;
            local_94 := local_8c + local_88 + local_84 + local_80;
            Gravalog(local_94);
            local_a8 := 'Relogio Parcial..: ';
            local_94 := Strzero(RELOGIOPARCIALSTR, 6);
            // C: local_a4 = (char * )local_94;
            local_a0 := '    ';
            local_ac := Strzero(JC_RELOGIOPARCIALSTR, 6);
            local_9c := local_ac;
            local_98 := local_a8 + local_a4 + local_a0 + local_9c;
            Gravalog(local_98);
            local_a8 := 'Relogio Gratis...: ';
            local_98 := Strzero(RELOGIOGRATISSTR, 6);
            local_a4 := local_98;
            local_a0 := '    ';
            local_b0 := Strzero(JC_RELOGIOGRATISSTR, 6);
            local_9c := local_b0;
            local_ac := local_a8 + local_a4 + local_a0 + local_9c;
            Gravalog(local_ac);
            local_c0 := 'Relogio GratisVIP: ';
            local_ac := Strzero(RELOGIOGRATISVIPSTR, 6);
            local_bc := local_ac;
            local_b8 := '    ';
            local_c4 := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
            local_b4 := local_c4;
            local_b0 := local_c0 + local_bc + local_b8 + local_b4;
            Gravalog(local_b0);
            RELOGIOTOTALSTR := JC_RELOGIOTOTALSTR;
            RELOGIOPARCIALSTR := JC_RELOGIOPARCIALSTR;
            PORCENTAGEMDOPONTOSTR := JC_PORCENTAGEMDOPONTOSTR;
            RELOGIOGRATISSTR := JC_RELOGIOGRATISSTR;
            RELOGIOGRATISVIPSTR := JC_RELOGIOGRATISVIPSTR;
            RELOGIOTOTAL := StrToIntDef(RELOGIOTOTALSTR, 0);
            RELOGIOPARCIAL := StrToIntDef(RELOGIOPARCIALSTR, 0);
            PORCENTAGEMDOPONTO := StrToIntDef(PORCENTAGEMDOPONTOSTR, 30);
            RELOGIOGRATIS := StrToIntDef(RELOGIOGRATISSTR, 0);
            RELOGIOGRATISVIP := StrToIntDef(RELOGIOGRATISVIPSTR, 0);
            Grava_Hd_Relogios;
            Grava_Hd_Porcentagem;
            Grava_Hd_Relogiogratis;
            Grava_Hd_Relogiogratisvip;
            Gravalog('Ajustado os Relogios da jukebox');
            Gravalog('                   Jukebox   PenDrive');
            local_c0 := 'Relogio Total....: ';
            local_b0 := Strzero(RELOGIOTOTALSTR, 6);
            local_bc := local_b0;
            local_b8 := '    ';
            local_c8 := Strzero(JC_RELOGIOTOTALSTR, 6);
            local_b4 := local_c8;
            local_c4 := local_c0 + local_bc + local_b8 + local_b4;
            Gravalog(local_c4);
            local_d8 := 'Relogio Parcial..: ';
            local_c4 := Strzero(RELOGIOPARCIALSTR, 6);
            local_d4 := local_c4;
            local_d0 := '    ';
            local_dc := Strzero(JC_RELOGIOPARCIALSTR, 6);
            local_cc := local_dc;
            local_c8 := local_d8 + local_d4 + local_d0 + local_cc;
            Gravalog(local_c8);
            local_d8 := 'Relogio Gratis...: ';
            local_c8 := Strzero(RELOGIOGRATISSTR, 6);
            local_d4 := local_c8;
            local_d0 := '    ';
            local_e0 := Strzero(JC_RELOGIOGRATISSTR, 6);
            local_cc := local_e0;
            local_dc := local_d8 + local_d4 + local_d0 + local_cc;
            Gravalog(local_dc);
            local_f0 := 'Relogio GratisVIP: ';
            local_dc := Strzero(RELOGIOGRATISVIPSTR, 6);
            local_ec := local_dc;
            local_e8 := '    ';
            local_f4 := Strzero(JC_RELOGIOGRATISVIPSTR, 6);
            local_e4 := local_f4;
            local_e0 := local_f0 + local_ec + local_e8 + local_e4;
            Gravalog(local_e0);
            NOMEARQ := PASTA + 'jukelinux.ini';
            local_1f4 := NOMEARQ;
            AssignFile(ARQTEXTO, local_1f4);
            Rewrite(ARQTEXTO);
            local_f4 := Cripta(JC_SERIALPENDRIVE);
            Write(ARQTEXTO, local_f4);
            Writeln(ARQTEXTO);
            Flush(ARQTEXTO);
            CloseFile(ARQTEXTO);
            local_f4 := 'Gravado a Nova Chave na HD: ' + JC_SERIALPENDRIVE;
            Gravalog(local_f4);
          end;
        end;
      end;
      ROTINA_DO_ACTIVATE := 3;
    end;
    if ROTINA_DO_ACTIVATE = 3 then begin
      local_1f8 := IntToStr(ROTINA_DO_ACTIVATE);
      local_1fc := 'Inico da Rotina Activate: ' + local_1f8;
      Gravalog(local_1fc);
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb14) + 0x21c))(Form1.Panelabertura,0);
      Form1.Panelabertura.BringToFront;
      Form1.Panelabertura.Left := 0;
      Form1.Panelabertura.Top := 0;
      Form1.Panelabertura.Width := RESOLUCAO;
      Form1.Panelabertura.Height := RESOLUCAOALTURA;
      Form1.Labelrodape.Font.Color := 16777215;
      Form1.Labelrodape.Caption := 'Pressione qualquer tecla para visualizar por mais 10 segundos';
      Form1.Labelabertura.AutoSize := False;
      // ?: Form1.Labelabertura.Align := alCustom;
      Form1.Labelabertura.Width := RESOLUCAO;
      Form1.Labelabertura.Left := 1;
      // C: STDCTRLS_TCUSTOMLABEL____SETALIGNMENT_TALIGNMENT(Form1.Labelabertura,2);
      iVar3 := Form1.Panelabertura.Height;
      // C: CONTROLS_TCONTROL____SETTOP_LONGINT (Form1.Labelabertura,(int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1);
      Form1.Labelabertura.Font.Color := 16777215;
      Form1.Labelabertura.Caption := NOMEDOCLIENTE;
      Form1.Labelabertura1.AutoSize := False;
      // ?: Form1.Labelabertura1.Align := alCustom;
      Form1.Labelabertura1.Width := RESOLUCAO;
      Form1.Labelabertura1.Left := 1;
      // C: STDCTRLS_TCUSTOMLABEL____SETALIGNMENT_TALIGNMENT(Form1.Labelabertura1,2);
      iVar3 := Form1.Panelabertura.Height;
      Form1.Labelabertura1.Top := (iVar3 div 2) + 20;
      Form1.Labelabertura1.Font.Color := 16777215;
      local_200 := 'S/N: ' + SERIAL;
      Form1.Labelabertura1.Caption := local_200;
      TEMPOABERTURA := 5;
      local_1fc := PASTA + 'charlestempo.txt';
      cVar1 := FileExists(local_1fc);
      if cVar1 then begin
        TEMPOABERTURA := 1;
      end;
      Form1.Labelaberturatempo.Font.Color := 16777215;
      local_200 := IntToStr(TEMPOABERTURA);
      Form1.Labelaberturatempo.Caption := local_200;
      TELAABERTURA := 1;
      Form1.Panelabertura.Show;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb14) + 0x2fc))(Form1.Panelabertura);
      PRESSIONADOTECLA := 0;
      TOCANDOMUSICA := 0;
      TOCANDOMUSICADVD := 0;
      TOCANDOMUSICAGRATIS := 0;
      ROTINA_DO_ACTIVATE := 4;
    end;
    if ROTINA_DO_ACTIVATE = 4 then begin
      Form1.Timerabertura.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__FORMCLOSE$TOBJECT$TCLOSEACTION }
procedure TForm1.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin
  if JAGRAVOUNOPENDRIVE = 1 then begin
    Grava_Pendrive_Contadores;
  end;
  // C: JUKELINUX1_GRAVALOG_ANSISTRING("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Saiu do Software pela Funcao [FORMCLOSE] <<<<<<<");
end;

{ JUKELINUX1_TFORM1_$__FORMCREATE$TOBJECT }
procedure TForm1.FormCreate(Sender: TObject);
var
  local_208, local_20c, local_2fc, local_300, local_304, local_308, local_318, local_408, local_40c, local_410, local_414, local_418, local_428, local_438, local_440, local_514, local_518, local_51c, local_520, local_528, local_52c, local_620, local_624, local_628, local_630, local_634, local_638, local_63c, local_73c, local_740, local_748, local_74c, local_750, local_754, local_758, local_768, local_858, local_85c, local_860, local_864, local_868, local_e8, local_ec: AnsiString;
  cVar3: Boolean;
  iVar5, iVar8, local_10, local_100, local_104, local_108, local_10c, local_14, local_18, local_1c, local_1e0, local_62c, local_744, local_e4, local_f0, local_f8, local_fc, uVar2: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_200, local_204, local_30c, local_310, local_314, local_41c, local_420, local_424, local_42c, local_430, local_434, local_43c, local_524, local_75c, local_760, local_764, local_f4: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    LETRASEXE := '3MJ';
    LETRASEXE := 'BRG';
    LETRASEXE := 'TRO';
    LETRASEXE := 'FLA';
    LETRASEXE := 'MAC';
    LETRASEXE := 'DPB';
    LETRASEXE := 'SMP';
    LETRASEXE := 'LLM';
    LETRASEXE := 'LIV';
    LETRASEXE := 'RRD';
    LETRASEXE := 'CAR';
    LETRASEXE := 'SIL';
    LETRASEXE := 'HGR';
    LETRASEXE := 'DIN';
    LETRASEXE := '3MJ';
    LETRASEXE := 'LLM';
    LETRASEXE := 'ROB';
    LETRASEXE := 'DPB';
    SEMPENDRIVE := 0;
    SEMQRCODE := 0;
    if 'DPB' = '3MJ' then begin
      SEMPENDRIVE := 1;
    end;
    if LETRASEXE = 'ROB' then begin
      SEMPENDRIVE := 1;
    end;
    Form1.PanelSorteio.Hide;
    Form1.TimerSetaVermelha.Enabled := False;
    Form1.TimerVolumeMais.Enabled := False;
    Form1.TimerVolumeMenos.Enabled := False;
    Form1.TimerDesativaVolume.Enabled := False;
    Form1.TimerUmMilesegundo.Enabled := False;
    Form1.TimerTouchScreen.Enabled := False;
    Form1.TimerPalhinha.Enabled := False;
    Form1.TimerPalhinhaTocando.Enabled := False;
    Form1.Timerabertura.Enabled := False;
    Form1.TimerCadastro.Enabled := False;
    Form1.TimerPaginaMenos.Enabled := False;
    Form1.TimerPaginaMais.Enabled := False;
    Form1.TimerMostraNomeDeMusicas.Enabled := False;
    Form1.Timer1.Enabled := False;
    Form1.TimerPiscaSeta.Enabled := False;
    Form1.TimerPiscaCreditos.Enabled := False;
    Form1.TimerGravaPenDrive.Enabled := False;
    Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
    Form1.TimerSelecionaLetraAutomatico.Enabled := False;
    Form1.TimerPropaganda.Enabled := False;
    Form1.TimerPaginaSozinho.Enabled := False;
    Form1.TimerEscondeMsg.Enabled := False;
    Form1.TimerRodaDisplay.Enabled := False;
    Form1.TimerFrases.Enabled := False;
    Form1.TimerNomeMusicaGrande.Enabled := False;
    Form1.TimerTocar.Enabled := False;
    Form1.TimerTocando.Enabled := False;
    Form1.TimerTelaCheia.Enabled := False;
    Form1.TimerSenhaErrada.Enabled := False;
    Form1.TimerMusicaGratis.Enabled := False;
    Form1.Timer1Minuto.Enabled := False;
    Form1.TimerVolume22hs.Enabled := False;
    Form1.TimerConfigInterface.Enabled := False;
    Form1.TimerAcionaVolume.Enabled := False;
    Form1.TimerUmMinuto.Enabled := False;
    Form1.TimerTocandoTv.Enabled := False;
    Form1.TimerCedulas.Enabled := False;
    Form1.TimerTocandoPalhinhaESeleTocar.Enabled := False;
    Form1.ImageGrandePng.Hide;
    FOTOPNG := 0;
    Form1.Button1.Hide;
    Form1.PanelSorteio.Hide;
    Form1.Panel1.Hide;
    Form1.PanelAutoTeste.Hide;
    Form1.PanelBloqueio.Hide;
    Form1.PanelAtivacao.Hide;
    Form1.Panelabertura.Hide;
    Form1.PanelErro.Hide;
    Form1.PanelLendo.Hide;
    Form1.PanelCadastro.Hide;
    Form1.Imagemsg.Hide;
    Form1.LabelMsg1.Hide;
    Form1.Play.Hide;
    Form1.PanelMenu.Hide;
    Form1.ImageSetaMsg.Hide;
    Form1.CDSelecionadoMsg.Hide;
    Form1.CapaSelecionadaMsg.Hide;
    Form1.ImageLendo1.Hide;
    Form1.ImageLendo2.Hide;
    Form1.ImageLendo3.Hide;
    Form1.ImageLendo4.Hide;
    Form1.ImageLendo5.Hide;
    Form1.ImageLendo6.Hide;
    Form1.ImageLendo7.Hide;
    VERSAO := 'Versão de 08/05/2014';
    VERSAO := 'Versão de 27/05/2014';
    VERSAO := 'Versão de 06/06/2014';
    VERSAO := 'Versão de 14/06/2014';
    VERSAO := 'Versão de 18/06/2014';
    VERSAO := 'Versão de 24/06/2014';
    VERSAO := 'Versão de 26/06/2014';
    VERSAO := 'Versao de 02/07/2014';
    VERSAO := 'Versao de 04/07/2014';
    VERSAO := 'Versao de 17/07/2014';
    VERSAO := 'Versão de 06/08/2014';
    VERSAO := 'Versao de 26/08/2014';
    VERSAO := 'Versao de 06/10/2014';
    VERSAO := 'Versao de 10/10/2014';
    VERSAO := 'Versao de 12/10/2014';
    VERSAO := 'Versao de 18/11/2014';
    VERSAO := 'Versao de 01/12/2014';
    VERSAO := 'Versao de 13/01/2015';
    VERSAO := 'Versao de 18/01/2015';
    VERSAO := 'Versao de 26/01/2015';
    VERSAO := 'Versao de 27/01/2015';
    VERSAO := 'Versao de 29/01/2015';
    VERSAO := 'Versao de 12/02/2015';
    VERSAO := 'Versao de 10/02/2015';
    VERSAO := 'Versao de 24/02/2015';
    VERSAO := 'Versao de 27/02/2015';
    VERSAO := 'Versao de 01/03/2015';
    VERSAO := 'Versao de 02/03/2015';
    VERSAO := 'Versao de 05/03/2015';
    VERSAO := 'Versao de 17/03/2015';
    VERSAO := 'Versao de 30/03/2015';
    VERSAO := 'Versao de 02/04/2015';
    VERSAO := 'Versao de 05/04/2015';
    VERSAO := 'Versao de 07/04/2015';
    VERSAO := 'Versao de 08/04/2015';
    VERSAO := 'Versao de 14/04/2015';
    VERSAO := 'Versao de 16/04/2015';
    VERSAO := 'Versao de 05/05/2015';
    VERSAO := 'Versao de 06/05/2015';
    VERSAO := 'Versao de 12/05/2015';
    VERSAO := 'Versao de 14/05/2015';
    VERSAO := 'Versao de 20/05/2015';
    VERSAO := 'Versao de 21/05/2015';
    VERSAO := 'Versao de 04/06/2015';
    VERSAO := 'Versao de 07/06/2015';
    VERSAO := 'Versao de 14/06/2015';
    VERSAO := 'Versao de 22/06/2015';
    VERSAO := 'Versao de 24/06/2015';
    VERSAO := 'Versao de 02/07/2015';
    VERSAO := 'Versao de 15/07/2015';
    VERSAO := 'Versao de 23/07/2015';
    VERSAO := 'Versao de 28/07/2015';
    VERSAO := 'Versao de 04/08/2015';
    VERSAO := 'Versao de 05/08/2015';
    VERSAO := 'Versao de 11/08/2015';
    VERSAO := 'Versao de 19/08/2015';
    VERSAO := 'Versao de 24/08/2015';
    VERSAO := 'Versao de 15/09/2015';
    VERSAO := 'Versao de 01/03/2016';
    VERSAO := 'Versao de 08/03/2016';
    VERSAO := 'Versao de 26/09/2017';
    VERSAO := 'Versao de 19/01/2018';
    MANDOUTOCARTOCANDOPALHINHA := 0;
    CODIGODAMAQUINASTR := '???';
    JAGRAVOUNOPENDRIVE := 0;
    MOSTRANDOLETRANAPAGINACAO := 0;
    SEGURANDOTECLA := 0;
    ESTANOMENU := 0;
    ESTADIGITANDOSENHA := 0;
    DIMINUERESOLUCAO := 0;
    ESTADESCRIPTOGRAFANDO := 0;
    TOCANDOMUSICA := 0;
    TOCANDOMUSICADVD := 0;
    ALTEROUMUSICAGRANDE := 0;
    ESTAEMTELACHEIA := 0;
    CREDITOSTEMP := 0;
    CREDITOSCEDULAS := 0;
    TEMPOEMSEGUNDOS := 0;
    TEMPOEMSEGUNDOSPAGINARSOZINHO := 0;
    TEMPOPARAAUMENTARVOLUME := 0;
    ALTERANDOFRASES := 0;
    RELECDS := 0;
    CHAVEDEINSTALACAO := 0;
    TOCANDOVIDEOTV := 0;
    ALTEROUPRO := 0;
    LENDOCODIGODOCARTAO := 0;
    CODIGODOCARTAO := '';
    PULSOSPARACARTAO := 0;
    ZERA50 := 0;
    TOCANDOPALHINHA := 0;
    RODAVOLUME := 0;
    TECLAANTERIORRODAVOLUME := '';
    VOLUMEATIVADO := 0;
    // C: U_JUKELINUX1_MOUSEPOS._0_4_ = *(undefined4 * )(U_JUKELINUX1_FORM1 + 0x23c);
    // C: U_JUKELINUX1_MOUSEPOS._4_4_ = *(int * )(U_JUKELINUX1_FORM1 + 0xe8) + -5;
    // C: CONTROLS_TMOUSE____SETCURSORPOS_TPOINT(U_CONTROLS_MOUSE,&U_JUKELINUX1_MOUSEPOS);
    NOMEARQ := '//home/jkb/jukelinux/pastas.txt';
    cVar3 := DirectoryExists('//home/jkb/jukelinux/');
    if not cVar3 then begin
      // ?: ShowMessage('O Software Roda Somente na Pasta //home/jkb/jukelinux/');
    end
    else begin
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_2fc := NOMEARQ;
        AssignFile(ARQTEXTO, local_2fc);
        Rewrite(ARQTEXTO);
        PASTAPRINCIPAL := '//home/jkb/';
        PASTA := '//home/jkb/jukelinux/';
        PASTAMUSICAS := '//home/jkb/musicas/';
        Write(ARQTEXTO, PASTAPRINCIPAL);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, PASTA);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, PASTAMUSICAS);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_2fc := NOMEARQ;
        AssignFile(ARQTEXTO, local_2fc);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, PASTAPRINCIPAL);
        Readln(ARQTEXTO);
        Read(ARQTEXTO, PASTA);
        Readln(ARQTEXTO);
        Read(ARQTEXTO, PASTAMUSICAS);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
    end;
    NOMEARQ := '//home/jkb/jukelinux/pastakaraoke.txt';
    cVar3 := DirectoryExists('//home/jkb/jukelinux/');
    if not cVar3 then begin
      // ?: ShowMessage('O Software Roda Somente na Pasta //home/jkb/jukelinux/');
    end
    else begin
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_2fc := NOMEARQ;
        AssignFile(ARQTEXTO, local_2fc);
        Rewrite(ARQTEXTO);
        PASTAKARAOKES := '//home/jkb/karaoke/';
        Write(ARQTEXTO, '//home/jkb/karaoke/');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_2fc := NOMEARQ;
        AssignFile(ARQTEXTO, local_2fc);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, PASTAKARAOKES);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
    end;
    NOMEARQ := PASTA + 'horasligada.txt';
    cVar3 := FileExists(NOMEARQ);
    if cVar3 then begin
      SEMPENDRIVE := 0;
    end;
    NOMEARQ := PASTA + 'log.txt';
    cVar3 := FileExists(NOMEARQ);
    if not cVar3 then begin
      local_2fc := NOMEARQ;
      AssignFile(ARQLOG, local_2fc);
      Rewrite(ARQLOG);
      local_304 := DateToStr(Date);
      local_20c := local_304;
      local_208 := ' ';
      local_308 := TimeToStr(Time);
      local_204 := local_308;
      local_200 := ' - Arquivo de Log foi Criado Nesta Data';
      local_300 := local_20c + local_208 + local_204 + local_200;
      Write(ARQLOG, local_300);
      Writeln(ARQLOG);
      Flush(ARQLOG);
      CloseFile(ARQLOG);
    end;
    local_308 := PASTAPRINCIPAL + 'Imagens/';
    cVar3 := DirectoryExists(local_308);
    if cVar3 then begin
      local_308 := PASTAPRINCIPAL + 'Imagens/linuxmint.png';
      cVar3 := FileExists(local_308);
      if not cVar3 then begin
        local_308 := PASTAPRINCIPAL + 'Imagens/linuxmint.png';
        local_408 := local_308;
        AssignFile(ARQLOG, local_408);
        Rewrite(ARQLOG);
        local_304 := DateToStr(Date);
        local_318 := local_304;
        local_314 := ' ';
        local_300 := TimeToStr(Time);
        local_310 := local_300;
        local_30c := ' - Arquivo de Log foi Criado Nesta Data';
        local_308 := local_318 + local_314 + local_310 + local_30c;
        Write(ARQLOG, local_308);
        Writeln(ARQLOG);
        Flush(ARQLOG);
        CloseFile(ARQLOG);
      end;
    end;
    Gravalog(' ');
    // C: JUKELINUX1_GRAVALOG_ANSISTRING(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    local_308 := 'Inicou o Software de Jukebox ' + VERSAO;
    Gravalog(local_308);
    NOMEARQ := PASTA + 'resolucaotv.txt';
    cVar3 := FileExists(NOMEARQ);
    if not cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, '800');
      Writeln(ARQTEXTO);
      Write(ARQTEXTO, '600');
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    cVar3 := FileExists(NOMEARQ);
    if cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      RESOLUCAOTVX := StrToIntDef(TEXTO, 800);
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      RESOLUCAOTVY := StrToIntDef(TEXTO, 600);
      CloseFile(ARQTEXTO);
    end;
    local_40c := IntToStr(RESOLUCAOTVX);
    Form1.ComboBox20.Caption := local_40c;
    local_40c := IntToStr(RESOLUCAOTVY);
    Form1.ComboBox21.Caption := local_40c;
    NOMEARQ := PASTA + 'exibirvideosno.txt';
    cVar3 := FileExists(NOMEARQ);
    if not cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, 'MONITOR');
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    cVar3 := FileExists(NOMEARQ);
    if cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, EXIBIRVIDEOSNO);
      Readln(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    Form1.ComboBox2.Caption := EXIBIRVIDEOSNO;
    RESOLUCAO := 0;
    // C: U_JUKELINUX1_RESOLUCAOSTR = (undefined * )0x0;
    NOMEARQ := PASTA + 'resolucao.txt';
    cVar3 := FileExists(NOMEARQ);
    if not cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, 'Automatico');
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    cVar3 := FileExists(NOMEARQ);
    if cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, RESOLUCAOOPC);
      Readln(ARQTEXTO);
      RESOLUCAOSTR := RESOLUCAOOPC;
      RESOLUCAO := StrToIntDef(RESOLUCAOOPC, 0);
      CloseFile(ARQTEXTO);
    end;
    NOMEARQ := PASTA + 'alterarresolucaodolinux.txt';
    cVar3 := FileExists(NOMEARQ);
    if not cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Rewrite(ARQTEXTO);
      Write(ARQTEXTO, 78);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    cVar3 := FileExists(NOMEARQ);
    if cVar3 then begin
      local_408 := NOMEARQ;
      AssignFile(ARQTEXTO, local_408);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, ALTERARRESOLUCAODOLINUX);
      Readln(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    local_10c := 0;
    // ?: WX := TC_FORMS_SCREEN.Width;
    // ?: HX := TC_FORMS_SCREEN.Height;
    RX := 'erro';
    if (WX = 1024) and (HX = 768) then begin
      RX := 'ok';
    end;
    if (WX = 1366) and (HX = 768) then begin
      RX := 'ok';
    end;
    if (WX = 1440) and (HX = 900) then begin
      RX := 'ok';
    end;
    if RX = 'erro' then begin
      if RESOLUCAOSTR = 'Automatico' then begin
        // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
        CMD.CommandLine := 'xrandr -s 1024x768';
        // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
        CMD.Free;
        RESOLUCAO := 1024;
        RESOLUCAOSTR := '1024';
        local_410 := 'Ajustou a Resolucao do linux para: ' + RESOLUCAOSTR;
        Gravalog(local_410);
      end
      else begin
        local_10c := 1;
      end;
    end;
    if RX = 'ok' then begin
      if RESOLUCAOSTR = 'Automatico' then begin
        if WX <> RESOLUCAO then begin
          RESOLUCAO := WX;
          NOMEARQ := PASTA + 'resolucao.txt';
          cVar3 := FileExists(NOMEARQ);
          if not cVar3 then begin
            local_408 := NOMEARQ;
            AssignFile(ARQTEXTO, local_408);
            Rewrite(ARQTEXTO);
            Write(ARQTEXTO, 'Automatico');
            Writeln(ARQTEXTO);
            Flush(ARQTEXTO);
            CloseFile(ARQTEXTO);
          end;
          local_410 := 'Ajustou a Resolucao da Jukebox para: Automatico-' + RESOLUCAOSTR;
          Gravalog(local_410);
        end;
      end
      else begin
        local_10c := 1;
      end;
    end;
    if local_10c <> 0 then begin
      if ALTERARRESOLUCAODOLINUX = 'S' then begin
        if RESOLUCAO = 1024 then begin
          // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
          CMD.CommandLine := 'xrandr -s 1024x768';
          // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
          CMD.Free;
        end;
        if RESOLUCAO = 1366 then begin
          // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
          CMD.CommandLine := 'xrandr -s 1366x768';
          // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
          CMD.Free;
        end;
        if RESOLUCAO = 1440 then begin
          // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
          CMD.CommandLine := 'xrandr -s 1440x900';
          // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
          CMD.Free;
        end;
      end;
    end;
    if RESOLUCAO = 1024 then begin
      Form1.ComboBox7.Caption := '1024x768 (4:3)';
      RESOLUCAOALTURA := 768;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.ComboBox7.Caption := '1366x768 (16:9)';
      RESOLUCAOALTURA := 768;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ComboBox7.Caption := '1440x900 (16:10)';
      RESOLUCAOALTURA := 900;
    end;
    if RESOLUCAOSTR = 'Automatico' then begin
      Form1.ComboBox7.Caption := 'Automatico';
      if RESOLUCAO = 1024 then begin
        RESOLUCAOALTURA := 768;
      end;
      if RESOLUCAO = 1366 then begin
        RESOLUCAOALTURA := 768;
      end;
      if RESOLUCAO = 1440 then begin
        RESOLUCAOALTURA := 900;
      end;
    end;
    // C: FORMS_TCUSTOMFORM____SETFORMBORDERSTYLE_TFORMBORDERSTYLE(U_JUKELINUX1_FORM1,0);
    FORM1.Left := 0;
    FORM1.Top := 0;
    if EXIBIRVIDEOSNO = 'MONITOR' then begin
      FORM1.Width := RESOLUCAO;
      FORM1.Height := RESOLUCAOALTURA;
    end
    else begin
      FORM1.Width := RESOLUCAO + RESOLUCAOTVX;
      if RESOLUCAOTVY < RESOLUCAOALTURA then begin
        FORM1.Height := RESOLUCAOALTURA;
      end;
      if RESOLUCAOALTURA < RESOLUCAOTVY then begin
        FORM1.Height := RESOLUCAOTVY;
      end;
    end;
    // C: U_JUKELINUX1_MOUSEPOS._0_4_ = *(undefined4 * )(U_JUKELINUX1_FORM1 + 0x23c);
    // C: U_JUKELINUX1_MOUSEPOS._4_4_ = *(int * )(U_JUKELINUX1_FORM1 + 0xe8) + -5;
    // C: CONTROLS_TMOUSE____SETCURSORPOS_TPOINT(U_CONTROLS_MOUSE,&U_JUKELINUX1_MOUSEPOS);
    local_414 := IntToStr(RESOLUCAO);
    local_410 := 'Resolucao: ' + local_414;
    Gravalog(local_410);
    local_414 := PASTA + 'inicio.txt';
    cVar3 := FileExists(local_414);
    if cVar3 then begin
      local_414 := PASTA + 'inicio.txt';
      DeleteFile(local_414);
    end;
    local_414 := PASTA + 'inicio.txt';
    cVar3 := FileExists(local_414);
    if not cVar3 then begin
      // C: U_JUKELINUX1_CMD = (int * )( *(code * )PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0) (0,&VMT_PROCESS_TPROCESS,local_c);
      local_414 := PASTA + 'inicio.sh';
      CMD.CommandLine := local_414;
      // C: ( **(code ** )( *U_JUKELINUX1_CMD + 0xe0))(U_JUKELINUX1_CMD);
      CMD.Free;
      Sleep(3000);
      local_414 := PASTA + 'inicio.txt';
      cVar3 := FileExists(local_414);
      if not cVar3 then begin
        ERROSERIALNUM := 2;
        local_428 := 'ERRO: ';
        local_414 := IntToStr(ERROSERIALNUM);
        local_424 := local_414;
        local_420 := ' - Executado o inicio.sh e nao foi criado o arquivo ';
        local_41c := PASTA;
        local_418 := 'inicio.txt';
        ERROSERIAL := local_428 + local_424 + local_420 + local_41c + local_418;
        Gravalog(ERROSERIAL);
      end
      else begin
        local_414 := PASTA + 'inicio.txt';
        local_514 := local_414;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        while True do begin
          cVar3 := Eof(ARQTEXTO);
          if cVar3 then begin Break; end;
          iVar5 := local_10 + 1;
          local_10 := iVar5;
          // C: fpc_read_text_ansistr(U_JUKELINUX1_ARQTEXTO,local_e4 + iVar5 * 4 + -4);
          Readln(ARQTEXTO);
        end;
        CloseFile(ARQTEXTO);
        local_414 := PASTA + 'inicio.txt';
        DeleteFile(local_414);
        repeat
          local_10 := local_10 + 1;
          // C: iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("usb-",*(undefined4 * )(local_e4 + local_10 * 4 + -4));
          if 0 < iVar5 then begin
            // C: local_fc = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("usb-",*(undefined4 * )(local_e4 + local_10 * 4 + -4) );
            if False { C: local_e8 == (char * )0x0 } then begin
              // C: iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("-0:0",*(undefined4 * )(local_e4 + local_10 * 4 + -4));
              // C: fpc_ansistr_copy( *(undefined4 * )(local_e4 + local_10 * 4 + -4),local_fc, iVar5 - local_fc);
            end
            else begin
              // C: iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("-0:0",*(undefined4 * )(local_e4 + local_10 * 4 + -4));
              // C: fpc_ansistr_copy( *(undefined4 * )(local_e4 + local_10 * 4 + -4),local_fc, iVar5 - local_fc);
            end;
            ERROSERIAL := '';
            ERROSERIALNUM := 0;
            local_f8 := local_f8 + 1;
          end;
        until not (local_10 < 50);
        // C: local_f8 = (int)(local_f8 + (local_f8 >> 0x1f & 1U)) >> 1;
        // C: U_JUKELINUX1_SERIALUUIDHD = (char * )0x0;
        repeat
          local_10 := local_10 + 1;
          // C: iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("ata-",*(undefined4 * )(local_e4 + local_10 * 4 + -4));
          if 0 < iVar5 then begin
            // C: local_fc = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("ata-",*(undefined4 * )(local_e4 + local_10 * 4 + -4) );
            if False { C: U_JUKELINUX1_SERIALUUIDHD == (char * )0x0 } then begin
              // C: iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT (" ->",*(undefined4 * )(local_e4 + local_10 * 4 + -4));
              // C: fpc_ansistr_copy( *(undefined4 * )(local_e4 + local_10 * 4 + -4),local_fc, iVar5 - local_fc);
              SERIALUUIDHD := local_414;
            end;
          end;
        until not (local_10 < 50);
        if ERROSERIAL <> '' then begin
          ERROSERIALNUM := 1;
          local_428 := 'ERRO: ';
          local_414 := IntToStr(ERROSERIALNUM);
          local_424 := local_414;
          local_420 := ' - Nao Encontrado no arquivo ';
          local_41c := PASTA;
          local_418 := 'inicio.txt o texto "usb-" entao nao deve ter PenDrive Conectado';
          ERROSERIAL := local_428 + local_424 + local_420 + local_41c + local_418;
          Gravalog(ERROSERIAL);
        end;
      end;
    end
    else begin
      ERROSERIALNUM := 3;
      local_428 := 'ERRO: ';
      local_414 := IntToStr(ERROSERIALNUM);
      local_424 := local_414;
      local_420 := ' - Nao Foi Possivel Apagar o Arquivo ';
      local_41c := PASTA;
      local_418 := 'inicio.txt para ser Recriado';
      ERROSERIAL := local_428 + local_424 + local_420 + local_41c + local_418;
      Gravalog(ERROSERIAL);
    end;
    if ERROSERIALNUM = 0 then begin
      local_414 := PASTA + 'versao.txt';
      cVar3 := FileExists(local_414);
      if not cVar3 then begin
        VERSAODOLINUX := 17;
        local_420 := 'VersaoDoLinux: Nao Encontrado Arquivo: ';
        local_41c := PASTA;
        // C: local_418 = "versao.txt - [11]";
        local_518 := local_420 + local_41c + local_418;
        Gravalog(local_518);
      end
      else begin
        local_414 := PASTA + 'versao.txt';
        local_514 := local_414;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        VERSAODOLINUX := 17;
        if TEXTO = '2.6.38-8-generic' then begin
          VERSAODOLINUX := 11;
        end;
        if TEXTO = '3.2.0-23-generic' then begin
          VERSAODOLINUX := 13;
        end;
        if TEXTO = '3.13.0-24-generic' then begin
          VERSAODOLINUX := 17;
        end;
        if TEXTO = '3.13.0-37-generic' then begin
          VERSAODOLINUX := 17;
        end;
        if TEXTO = '3.8.0-19-generic' then begin
          VERSAODOLINUX := 17;
        end;
        local_518 := IntToStr(VERSAODOLINUX);
        local_414 := 'VersaoDoLinux: ' + local_518;
        Gravalog(local_414);
      end;
      if (VERSAODOLINUX = 11) or (VERSAODOLINUX = 13) then begin
        PASTACHAVE := '//media/chave/';
        local_518 := PASTA + 'chave_.txt';
        cVar3 := FileExists(local_518);
        if cVar3 then begin
          PASTACHAVE := '//media/chave_/';
        end;
        NOMEARQPENFECHA := '//media/FECHAMENTO/fechamento/pendrivefechamento.arq';
        NOMEPASTAFECHA := '//media/FECHAMENTO/fechamento/';
        NOMEPASTACDNOVO := '//media/MUSICAS/musicas/';
        NOMEPASTAUPGRADE := '//media/UPGRADE/upgrade/';
        NOMEPASTACDNOVOLISTA := '//media/MUSICAS/';
        NOMEPASTAXMLAPROVA := '//media/XML/aprova/';
        ULTIMOFECHA := 0;
      end;
      if VERSAODOLINUX = 17 then begin
        PASTACHAVE := '//media/jkb/chave/';
        PASTACHAVE1 := '//media/jkb/chave1/';
        PASTACHAVE2 := '//media/jkb/chave2/';
        PASTACHAVE3 := '//media/jkb/chave3/';
        PASTACHAVE4 := '//media/jkb/chave4/';
        PASTACHAVE5 := '//media/jkb/chave5/';
        PASTACHAVE6 := '//media/jkb/chave6/';
        PASTACHAVE7 := '//media/jkb/chave7/';
        PASTACHAVE8 := '//media/jkb/chave8/';
        PASTACHAVE9 := '//media/jkb/chave9/';
        PASTACHAVE10 := '//media/jkb/chave10/';
        PASTACHAVE11 := '//media/jkb/chave11/';
        PASTACHAVE12 := '//media/jkb/chave12/';
        PASTACHAVE13 := '//media/jkb/chave13/';
        PASTACHAVE14 := '//media/jkb/chave14/';
        PASTACHAVE15 := '//media/jkb/chave15/';
        NOMEARQPENFECHA := '//media/jkb/FECHAMENTO/fechamento/pendrivefechamento.arq';
        NOMEPASTAFECHA := '//media/jkb/FECHAMENTO/fechamento/';
        NOMEPASTACDNOVO := '//media/jkb/MUSICAS/musicas/';
        NOMEPASTAUPGRADE := '//media/jkb/UPGRADE/upgrade/';
        NOMEPASTACDNOVOLISTA := '//media/jkb/MUSICAS/';
        NOMEPASTAXMLAPROVA := '//media/jkb/XML/aprova/';
        ULTIMOFECHA := 0;
      end;
      cVar3 := DirectoryExists('//home/jkb/upgrade/');
      if not cVar3 then begin
        CreateDir('//home/jkb/upgrade/');
      end;
    end;
    if ERROSERIALNUM = 0 then begin
      local_518 := PASTACHAVE + 'jukebox.chave';
      cVar3 := FileExists(local_518);
      if not cVar3 then begin
        local_518 := PASTACHAVE1 + 'jukebox.chave';
        cVar3 := FileExists(local_518);
        if not cVar3 then begin
          local_518 := PASTACHAVE2 + 'jukebox.chave';
          cVar3 := FileExists(local_518);
          if not cVar3 then begin
            local_518 := PASTACHAVE3 + 'jukebox.chave';
            cVar3 := FileExists(local_518);
            if not cVar3 then begin
              local_518 := PASTACHAVE4 + 'jukebox.chave';
              cVar3 := FileExists(local_518);
              if not cVar3 then begin
                local_518 := PASTACHAVE5 + 'jukebox.chave';
                cVar3 := FileExists(local_518);
                if not cVar3 then begin
                  local_518 := PASTACHAVE6 + 'jukebox.chave';
                  cVar3 := FileExists(local_518);
                  if not cVar3 then begin
                    local_518 := PASTACHAVE7 + 'jukebox.chave';
                    cVar3 := FileExists(local_518);
                    if not cVar3 then begin
                      local_518 := PASTACHAVE8 + 'jukebox.chave';
                      cVar3 := FileExists(local_518);
                      if not cVar3 then begin
                        local_518 := PASTACHAVE9 + 'jukebox.chave';
                        cVar3 := FileExists(local_518);
                        if not cVar3 then begin
                          local_518 := PASTACHAVE10 + 'jukebox.chave';
                          cVar3 := FileExists(local_518);
                          if not cVar3 then begin
                            local_518 := PASTACHAVE11 + 'jukebox.chave';
                            cVar3 := FileExists(local_518);
                            if not cVar3 then begin
                              local_518 := PASTACHAVE12 + 'jukebox.chave';
                              cVar3 := FileExists(local_518);
                              if not cVar3 then begin
                                local_518 := PASTACHAVE13 + 'jukebox.chave';
                                cVar3 := FileExists(local_518);
                                if not cVar3 then begin
                                  local_518 := PASTACHAVE14 + 'jukebox.chave';
                                  cVar3 := FileExists(local_518);
                                  if not cVar3 then begin
                                    local_518 := PASTACHAVE15 + 'jukebox.chave';
                                    cVar3 := FileExists(local_518);
                                    if cVar3 then begin
                                      PASTACHAVE := PASTACHAVE15;
                                    end;
                                  end
                                  else begin
                                    PASTACHAVE := PASTACHAVE14;
                                  end;
                                end
                                else begin
                                  PASTACHAVE := PASTACHAVE13;
                                end;
                              end
                              else begin
                                PASTACHAVE := PASTACHAVE12;
                              end;
                            end
                            else begin
                              PASTACHAVE := PASTACHAVE11;
                            end;
                          end
                          else begin
                            PASTACHAVE := PASTACHAVE10;
                          end;
                        end
                        else begin
                          PASTACHAVE := PASTACHAVE9;
                        end;
                      end
                      else begin
                        PASTACHAVE := PASTACHAVE8;
                      end;
                    end
                    else begin
                      PASTACHAVE := PASTACHAVE7;
                    end;
                  end
                  else begin
                    PASTACHAVE := PASTACHAVE6;
                  end;
                end
                else begin
                  PASTACHAVE := PASTACHAVE5;
                end;
              end
              else begin
                PASTACHAVE := PASTACHAVE4;
              end;
            end
            else begin
              PASTACHAVE := PASTACHAVE3;
            end;
          end
          else begin
            PASTACHAVE := PASTACHAVE2;
          end;
        end
        else begin
          PASTACHAVE := PASTACHAVE1;
        end;
      end;
      repeat
        local_518 := PASTACHAVE + 'jukebox.chave';
        cVar3 := FileExists(local_518);
        if not cVar3 then begin
          ERROSERIALNUM := 5;
          local_428 := 'ERRO: ';
          local_518 := IntToStr(ERROSERIALNUM);
          local_424 := local_518;
          local_420 := ' - Nao Encontrado o arquivo ';
          local_41c := PASTACHAVE;
          local_418 := 'jukebox.chave';
          ERROSERIAL := local_428 + local_424 + local_420 + local_41c + local_418;
          Gravalog(ERROSERIAL);
        end
        else begin
          local_518 := PASTACHAVE + 'jukebox.chave';
          local_514 := local_518;
          AssignFile(ARQTEXTO, local_514);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          local_518 := Descriptasuper2(TEXTO);
          JC_SERIALPENDRIVE := local_518;
          local_f4 := TEXTO;
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          local_518 := Descriptasuper2(TEXTO);
          JC_LETRAS := local_518;
          local_f4 := TEXTO;
          iVar5 := 0;
          if False { C: U_JUKELINUX1_TEXTO != (char * )0x0 } then begin
            // C: iVar5 = *(int * )(U_JUKELINUX1_TEXTO + -4);
          end;
          local_1c := 1;
          if 0 < iVar5 then begin
            repeat
              iVar8 := local_1c + 1;
              // C: local_18 = (uint)(byte)U_JUKELINUX1_TEXTO[local_1c] + local_18;
              local_1c := iVar8;
            until not (iVar8 < iVar5);
          end;
          local_f4 := IntToStr(local_18);
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          local_518 := Descriptasuper2(TEXTO);
          JC_DIGITO := local_518;
          CloseFile(ARQTEXTO);
          if local_f4 = JC_DIGITO then begin
            ERROSERIALNUM := 0;
            ERROSERIAL := '';
          end
          else begin
            ERROSERIALNUM := 4;
            local_438 := 'ERRO: ';
            local_518 := IntToStr(ERROSERIALNUM);
            local_434 := local_518;
            local_430 := ' - Digito de Checagem do arquivo ';
            local_42c := PASTACHAVE;
            // C: local_428 = "jukebox.chave diferente, [";
            local_424 := local_f4;
            local_420 := ' <> ';
            local_41c := JC_DIGITO;
            local_418 := ']';
            ERROSERIAL := local_438 + local_434 + local_430 + local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
            Gravalog(ERROSERIAL);
          end;
        end;
        if ERROSERIALNUM = 0 then begin
          local_14 := 51;
          local_420 := 'Leitura Ok do Arquivo: ';
          local_41c := PASTACHAVE;
          local_418 := 'jukebox.chave';
          local_518 := local_420 + local_41c + local_418;
          Gravalog(local_518);
        end;
        local_14 := local_14 + 1;
        Sleep(100);
      until not (local_14 < 51);
      if ERROSERIALNUM = 0 then begin
        local_f0 := 0;
        if JC_SERIALPENDRIVE = local_e8 then begin
          local_f0 := 1;
        end;
        if JC_SERIALPENDRIVE = local_ec then begin
          local_f0 := 1;
          local_e8 := local_ec;
        end;
        if local_f0 = 0 then begin
          ERROSERIALNUM := 10;
          if local_f8 < 2 then begin
            local_438 := 'ERRO: ';
            local_51c := IntToStr(ERROSERIALNUM);
            local_434 := local_51c;
            local_430 := ' - Serial do PenDrive Nao Confere com o Serial do arquivo ';
            local_42c := PASTACHAVE;
            // C: local_428 = "jukebox.chave [";
            local_424 := local_e8;
            local_420 := ' <> ';
            local_41c := JC_SERIALPENDRIVE;
            local_418 := ']';
            ERROSERIAL := local_438 + local_434 + local_430 + local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
          end
          else begin
            local_440 := 'ERRO: ';
            local_518 := IntToStr(ERROSERIALNUM);
            local_43c := local_518;
            // C: local_438 = " - <<< ATENCAO: Foram Detectados ";
            local_51c := IntToStr(local_f8);
            local_434 := local_51c;
            // C: local_430 = " Dispositivos USB >>> - Serial do PenDrive Nao Confere com o Serial do arquivo ";
            local_42c := PASTACHAVE;
            // C: local_428 = "jukebox.chave [";
            local_424 := local_e8;
            local_420 := ' <> ';
            local_41c := JC_SERIALPENDRIVE;
            local_418 := ']';
            ERROSERIAL := local_440 + local_43c + local_438 + local_434 + local_430 + local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
          end;
          Gravalog(ERROSERIAL);
        end
        else begin
          local_518 := PASTACHAVE + 'jukebox.contadores';
          cVar3 := FileExists(local_518);
          if not cVar3 then begin
            ERROSERIALNUM := 8;
            local_428 := 'ERRO: ';
            local_518 := IntToStr(ERROSERIALNUM);
            local_424 := local_518;
            local_420 := ' - Arquivo ';
            local_41c := PASTACHAVE;
            local_418 := 'jukebox.contadores nao Existe';
            ERROSERIAL := local_428 + local_424 + local_420 + local_41c + local_418;
            Gravalog(ERROSERIAL);
          end
          else begin
            local_518 := PASTACHAVE + 'jukebox.contadores';
            local_514 := local_518;
            AssignFile(ARQTEXTO, local_514);
            Reset(ARQTEXTO);
            Read(ARQTEXTO, TEXTO);
            Readln(ARQTEXTO);
            local_518 := Descriptasuper2(TEXTO);
            JC_SERIALPENDRIVECON := local_518;
            local_f4 := TEXTO;
            Read(ARQTEXTO, TEXTO);
            Readln(ARQTEXTO);
            local_518 := Descriptasuper2(TEXTO);
            JC_RELOGIOTOTALSTR := local_518;
            local_f4 := local_f4 + TEXTO;
            Read(ARQTEXTO, TEXTO);
            Readln(ARQTEXTO);
            local_518 := Descriptasuper2(TEXTO);
            JC_RELOGIOPARCIALSTR := local_518;
            local_f4 := local_f4 + TEXTO;
            Read(ARQTEXTO, TEXTO);
            Readln(ARQTEXTO);
            local_518 := Descriptasuper2(TEXTO);
            JC_PORCENTAGEMDOPONTOSTR := local_518;
            local_f4 := local_f4 + TEXTO;
            Read(ARQTEXTO, TEXTO);
            Readln(ARQTEXTO);
            local_518 := Descriptasuper2(TEXTO);
            JC_RELOGIOGRATISSTR := local_518;
            local_f4 := local_f4 + TEXTO;
            Read(ARQTEXTO, TEXTO);
            Readln(ARQTEXTO);
            local_518 := Descriptasuper2(TEXTO);
            JC_RELOGIOGRATISVIPSTR := local_518;
            local_f4 := local_f4 + TEXTO;
            iVar5 := 0;
            if False { C: local_f4 != (char * )0x0 } then begin
              // C: iVar5 = *(int * )(local_f4 + -4);
            end;
            local_1c := 1;
            if 0 < iVar5 then begin
              repeat
                iVar8 := local_1c + 1;
                // C: local_18 = (uint)(byte)local_f4[local_1c] + local_18;
                local_1c := iVar8;
              until not (iVar8 < iVar5);
            end;
            local_518 := IntToStr(local_18);
            local_f4 := local_518;
            Read(ARQTEXTO, TEXTO);
            Readln(ARQTEXTO);
            local_518 := Descriptasuper2(TEXTO);
            JC_DIGITOCON := local_518;
            CloseFile(ARQTEXTO);
            if local_f4 = JC_DIGITOCON then begin
              ERROSERIALNUM := 0;
              ERROSERIAL := '';
              JC_RELOGIOTOTAL := StrToIntDef(JC_RELOGIOTOTALSTR, 0);
              JC_RELOGIOPARCIAL := StrToIntDef(JC_RELOGIOPARCIALSTR, 0);
              JC_RELOGIOGRATIS := StrToIntDef(JC_RELOGIOGRATISSTR, 0);
              JC_RELOGIOGRATISVIP := StrToIntDef(JC_RELOGIOGRATISVIPSTR, 0);
              local_420 := 'Leitura Ok do Arquivo: ';
              local_41c := PASTACHAVE;
              local_418 := 'jukebox.contadoes';
              local_518 := local_420 + local_41c + local_418;
              Gravalog(local_518);
              local_518 := PASTACHAVE + 'jukebox.cadastro';
              cVar3 := FileExists(local_518);
              if not cVar3 then begin
                ERROSERIALNUM := 11;
                local_428 := 'ERRO: ';
                local_518 := IntToStr(ERROSERIALNUM);
                local_424 := local_518;
                // C: local_420 = " - Nao Encontrado o arquivo [";
                local_41c := PASTACHAVE;
                local_418 := 'jukebox.cadastro]';
                ERROSERIAL := local_428 + local_424 + local_420 + local_41c + local_418;
                Gravalog(ERROSERIAL);
              end
              else begin
                Le_Arquivo_De_Cadastro;
              end;
            end
            else begin
              ERROSERIALNUM := 6;
              local_438 := 'ERRO: ';
              local_518 := IntToStr(ERROSERIALNUM);
              local_434 := local_518;
              local_430 := ' - Digito de Checagem do arquivo ';
              local_42c := PASTACHAVE;
              // C: local_428 = "jukebox.contadores diferente, [";
              local_424 := local_f4;
              local_420 := ' <> ';
              local_41c := JC_DIGITOCON;
              local_418 := ']';
              ERROSERIAL := local_438 + local_434 + local_430 + local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
              Gravalog(ERROSERIAL);
            end;
            if ERROSERIALNUM = 0 then begin
              if JC_SERIALPENDRIVECON = local_e8 then begin
                ERROSERIALNUM := 0;
                ERROSERIAL := '';
              end
              else begin
                ERROSERIALNUM := 7;
                local_438 := 'ERRO: ';
                local_518 := IntToStr(ERROSERIALNUM);
                local_434 := local_518;
                local_430 := ' - Serial do PenDrive Nao Confere com o Serial do arquivo ';
                local_42c := PASTACHAVE;
                // C: local_428 = "jukebox.contadores [";
                local_424 := local_e8;
                local_420 := '<>';
                local_41c := JC_SERIALPENDRIVECON;
                local_418 := ']';
                ERROSERIAL := local_438 + local_434 + local_430 + local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
                Gravalog(ERROSERIAL);
              end;
            end;
          end;
          if ERROSERIALNUM = 0 then begin
            local_518 := PASTA + 'jukelinux.ini';
            cVar3 := FileExists(local_518);
            if not cVar3 then begin
              NOMEARQ := PASTA + 'jukelinux.ini';
              local_514 := NOMEARQ;
              AssignFile(ARQTEXTO, local_514);
              Rewrite(ARQTEXTO);
              local_518 := Cripta(JC_SERIALPENDRIVE);
              Write(ARQTEXTO, local_518);
              Writeln(ARQTEXTO);
              Flush(ARQTEXTO);
              CloseFile(ARQTEXTO);
              local_514 := NOMEARQ;
              AssignFile(ARQTEXTO, local_514);
              Reset(ARQTEXTO);
              Read(ARQTEXTO, TEXTO);
              Readln(ARQTEXTO);
              local_518 := Descripta(TEXTO);
              JC_INI := local_518;
              CloseFile(ARQTEXTO);
              ERROSERIALNUM := 0;
              ERROSERIAL := '';
              local_518 := 'Gravado a Primeira Vez a Chave na HD: ' + JC_SERIALPENDRIVE;
              Gravalog(local_518);
            end
            else begin
              NOMEARQ := PASTA + 'jukelinux.ini';
              local_514 := NOMEARQ;
              AssignFile(ARQTEXTO, local_514);
              Reset(ARQTEXTO);
              Read(ARQTEXTO, TEXTO);
              Readln(ARQTEXTO);
              local_518 := Descripta(TEXTO);
              JC_INI := local_518;
              CloseFile(ARQTEXTO);
              local_518 := PASTA + 'edson.txt';
              cVar3 := FileExists(local_518);
              if cVar3 then begin
                JC_INI := JC_SERIALPENDRIVE;
              end;
              if JC_INI = JC_SERIALPENDRIVE then begin
                ERROSERIALNUM := 0;
                ERROSERIAL := '';
                if JC_LETRAS = LETRASEXE then begin
                  // C: local_420 = "Todas as Chaves [";
                  local_41c := JC_LETRAS;
                  local_418 := '] OK';
                  local_518 := local_420 + local_41c + local_418;
                  Gravalog(local_518);
                end
                else begin
                  ERROSERIALNUM := 12;
                  local_42c := 'ERRO: ';
                  local_518 := IntToStr(ERROSERIALNUM);
                  local_428 := local_518;
                  local_424 := ' - Este PenDrive é do Cliente ';
                  local_420 := JC_LETRAS;
                  local_41c := ' e o Software é do Cliente ';
                  local_418 := LETRASEXE;
                  ERROSERIAL := local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
                  Gravalog(ERROSERIAL);
                end;
              end
              else begin
                ERROSERIALNUM := 9;
                local_430 := 'ERRO: ';
                local_518 := IntToStr(ERROSERIALNUM);
                local_42c := local_518;
                // C: local_428 = " - Este PenDrive Nao e desta JukeBox [HD=";
                local_424 := JC_INI;
                local_420 := ' <> PENDRIVE=';
                local_41c := JC_SERIALPENDRIVE;
                local_418 := '] ***Solicitado a Contra Senha***';
                ERROSERIAL := local_430 + local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
                Gravalog(ERROSERIAL);
              end;
            end;
          end;
        end;
      end;
    end;
    NOMEARQ := PASTA + 'contrasenha.txt';
    cVar3 := FileExists(NOMEARQ);
    if not cVar3 then begin
      local_514 := NOMEARQ;
      AssignFile(ARQTEXTO, local_514);
      Rewrite(ARQTEXTO);
      if LETRASEXE = 'ROB' then begin
        local_51c := Cripta('031=2=');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = '3MJ' then begin
        local_51c := Cripta('031/2/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'LLM' then begin
        local_51c := Cripta('031/6/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'LIV' then begin
        local_51c := Cripta('031/6/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'CAR' then begin
        local_51c := Cripta('025/6/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'HGR' then begin
        local_51c := Cripta('041/6/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'RRD' then begin
        local_51c := Cripta('041/3/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'SIL' then begin
        local_51c := Cripta('031/3=');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'DPB' then begin
        local_51c := Cripta('042/3/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'TRO' then begin
        local_51c := Cripta('045/6/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'FLA' then begin
        local_51c := Cripta('045/6/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'BRG' then begin
        local_51c := Cripta('021/6=');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'MAC' then begin
        local_51c := Cripta('055/6/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      if LETRASEXE = 'DIN' then begin
        local_51c := Cripta('023/4/');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
      end;
      local_51c := Cripta(LETRASEXE);
      Write(ARQTEXTO, local_51c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
    end;
    cVar3 := FileExists(NOMEARQ);
    if cVar3 then begin
      local_514 := NOMEARQ;
      AssignFile(ARQTEXTO, local_514);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      Read(ARQTEXTO, TEXTO1);
      Readln(ARQTEXTO);
      CloseFile(ARQTEXTO);
      local_51c := Descripta(TEXTO);
      FORMULACONTRASENHA := local_51c;
      local_51c := Descripta(TEXTO1);
      TEXTO2 := local_51c;
      if local_51c <> LETRASEXE then begin
        ERROSERIALNUM := 13;
        local_430 := 'ERRO: ';
        local_51c := IntToStr(ERROSERIALNUM);
        local_42c := local_51c;
        // C: local_428 = " - Chave Nao Confere [";
        local_424 := TEXTO2;
        local_420 := '<>';
        local_41c := LETRASEXE;
        local_418 := '] - ContraSenha';
        ERROSERIAL := local_430 + local_42c + local_428 + local_424 + local_420 + local_41c + local_418;
        local_428 := 'ERRO: ';
        local_518 := IntToStr(ERROSERIALNUM);
        local_424 := local_518;
        // C: local_420 = " - Chave Nao Confere [";
        local_41c := TEXTO2;
        local_418 := '] - ContraSenha';
        local_51c := local_428 + local_424 + local_420 + local_41c + local_418;
        Gravalog(local_51c);
      end;
    end;
    if SEMPENDRIVE <> 0 then begin
      NOMEARQ := PASTA + 'jukeu.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_51c := PASTA + 'roberto.txt';
        cVar3 := FileExists(local_51c);
        if not cVar3 then begin
          ERROSERIALNUM := 30;
          local_420 := 'ERRO: ';
          local_51c := IntToStr(ERROSERIALNUM);
          local_41c := local_51c;
          local_418 := ' - Falta Chave UUID HD';
          ERROSERIAL := local_420 + local_41c + local_418;
          local_420 := 'ERRO: ';
          local_518 := IntToStr(ERROSERIALNUM);
          local_41c := local_518;
          local_418 := ' - Falta Chave UUID HD';
          local_51c := local_420 + local_41c + local_418;
          Gravalog(local_51c);
        end
        else begin
          local_514 := NOMEARQ;
          AssignFile(ARQTEXTO, local_514);
          Rewrite(ARQTEXTO);
          local_51c := Cripta(SERIALUUIDHD);
          Write(ARQTEXTO, local_51c);
          Writeln(ARQTEXTO);
          local_424 := LETRASEXE;
          local_420 := LETRASEXE;
          local_41c := SERIALUUIDHD;
          local_418 := LETRASEXE;
          local_518 := local_424 + local_420 + local_41c + local_418;
          local_51c := Cripta(local_518);
          Write(ARQTEXTO, local_51c);
          Writeln(ARQTEXTO);
          local_51c := Cripta(LETRASEXE);
          Write(ARQTEXTO, local_51c);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          local_51c := PASTA + 'roberto.txt';
          DeleteFile(local_51c);
        end;
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_51c := Descripta(TEXTO);
        SERIALUUIDHDARQ := local_51c;
        if local_51c = SERIALUUIDHD then begin
          ERROSERIALNUM := 0;
        end
        else begin
          ERROSERIALNUM := 33;
          local_420 := 'ERRO: ';
          local_51c := IntToStr(ERROSERIALNUM);
          local_41c := local_51c;
          local_418 := ' - Chave UUID HD Não Confere';
          ERROSERIAL := local_420 + local_41c + local_418;
          local_420 := 'ERRO: ';
          local_518 := IntToStr(ERROSERIALNUM);
          local_41c := local_518;
          local_418 := ' - Chave UUID HD Não Confere';
          local_51c := local_420 + local_41c + local_418;
          Gravalog(local_51c);
        end;
      end;
    end;
    if ERROSERIALNUM = 0 then begin
      local_51c := PASTA + 'instalacao.txt';
      cVar3 := FileExists(local_51c);
      if cVar3 then begin
        CHAVEDEINSTALACAO := 1;
        Gravalog('ChaveDeinstalacao: True');
      end;
      NOMEARQ := PASTA + 'doublebuffered.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        // C: *(undefined1 * )(U_JUKELINUX1_FORM1 + 0x33e) = 0;
        Gravalog('Doublebuffered: false');
      end
      else begin
        // C: *(undefined1 * )(U_JUKELINUX1_FORM1 + 0x33e) = 1;
        Gravalog('Doublebuffered: True');
      end;
      NOMEARQ := PASTA + 'minutosligada.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 48);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        MINUTOSLIGADA := StrToIntDef(TEXTO, 0);
      end;
      NOMEARQ := PASTA + 'chavecriptografica.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Rewrite(ARQTEXTO);
        if LETRASEXE = '3MJ' then begin
          Write(ARQTEXTO, '77');
          Writeln(ARQTEXTO);
        end
        else begin
          Write(ARQTEXTO, '71');
          Writeln(ARQTEXTO);
        end;
        Write(ARQTEXTO, '----');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'LL  = 71');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '3MJ = 77');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        CHAVECRIPTOGRAFICA := StrToIntDef(TEXTO, 71);
      end;
      NOMEARQ := PASTA + 'ritmosinativos.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Rewrite(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        // C: ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0xb8)) (Form1.ListBoxRInativo.Items);
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        while True do begin
          cVar3 := Eof(ARQTEXTO);
          if cVar3 then begin Break; end;
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRInativo + 0x364) + 0xa4)) (Form1.ListBoxRInativo.Items,U_JUKELINUX1_TEXTO);
        end;
        CloseFile(ARQTEXTO);
      end;
      NOMEARQ := PASTA + 'intervalovolume.txt';
      INTERVALOVOLUME := 1;
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 49);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        INTERVALOVOLUME := StrToIntDef(TEXTO, 1);
      end;
      NOMEARQ := PASTA + 'tempoparapaginar.txt';
      TEMPOTT := 4;
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 52);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        TEMPOTT := StrToIntDef(TEXTO, 4);
        if TEMPOTT = 0 then begin
          TEMPOTT := 4;
        end;
      end;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbcc) + 0xdc)) (Form1.TimerPaginaMais,U_JUKELINUX1_TEMPOTT);
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbd0) + 0xdc)) (Form1.TimerPaginaMenos,U_JUKELINUX1_TEMPOTT);
      NOMEARQ := PASTA + 'bloquearquandotocar.txt';
      BLOQUEARQUANDOTOCAR := 0;
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Rewrite(ARQTEXTO);
        local_51c := Criptasuper2(JC_SERIALPENDRIVECON);
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
        local_51c := Criptasuper2('-1');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_514 := NOMEARQ;
        AssignFile(ARQTEXTO, local_514);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO1);
        Readln(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        BLOQUEARQUANDOTOCAROPC := TEXTO;
        local_51c := Descriptasuper2(TEXTO1);
        TEXTO1 := local_51c;
        if False { C: STREQ(U_JUKELINUX1_JC_SERIALPENDRIVECON) } then begin
          local_51c := Descriptasuper2(TEXTO);
          TEXTO := local_51c;
          BLOQUEARQUANDOTOCAR := StrToIntDef(local_51c, 0);
        end
        else begin
          BLOQUEARQUANDOTOCAR := 0;
        end;
        local_520 := IntToStr(BLOQUEARQUANDOTOCAR);
        Form1.ComboBox8.Caption := local_520;
        if BLOQUEARQUANDOTOCAR = -1 then begin
          Form1.ComboBox8.Caption := 'Não Bloquear Nunca';
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.ComboBox8,&local_51c);
          BLOQUEARQUANDOTOCAROPC := local_51c;
        end;
      end;
      NOMEARQ := PASTA + 'jukelinux.txt';
      QUANTIDADESDEMUSICASTOCADAS := 0;
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        local_51c := Criptasuper2(JC_SERIALPENDRIVECON);
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
        local_51c := Criptasuper2('0');
        Write(ARQTEXTO, local_51c);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO1);
        Readln(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_51c := Descriptasuper2(TEXTO1);
        TEXTO1 := local_51c;
        if False { C: STREQ(U_JUKELINUX1_JC_SERIALPENDRIVECON) } then begin
          local_51c := Descriptasuper2(TEXTO);
          TEXTO := local_51c;
          QUANTIDADESDEMUSICASTOCADAS := StrToIntDef(local_51c, 0);
        end
        else begin
          QUANTIDADESDEMUSICASTOCADAS := 10000;
        end;
      end;
      NOMEARQ := PASTA + 'formadeselecionarritmo.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Paginando');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        FORMADESELECIONARRITMO := TEXTO;
        Form1.ComboBox9.Caption := TEXTO;
      end;
      NOMEARQ := PASTA + 'tempoparaselecionarritmo.txt';
      TEMPOSRA := 2000;
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '2000');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        TEMPOSRA := StrToIntDef(TEXTO, 2000);
        if TEMPOSRA = 0 then begin
          TEMPOSRA := 2000;
        end;
      end;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbb0) + 0xdc)) (Form1.TimerSelecionaRitmoAutomatico,U_JUKELINUX1_TEMPOSRA);
      NOMEARQ := PASTA + 'cartaojukebox.txt';
      CARTAOJUKEBOX := 'Desativado';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Desativado');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        CARTAOJUKEBOX := TEXTO;
        Form1.ComboBox10.Caption := TEXTO;
      end;
      KMMCC := 0;
      repeat
        KMMCC := KMMCC + 1;
        // C: U_JUKELINUX1_MMCARTAO[U_JUKELINUX1_KMMCC * 0x26 + 0x342f3a] = 0;
        // C: U_JUKELINUX1_MMCARTAO[U_JUKELINUX1_KMMCC * 0x26 + 0x342f59] = 0;
        // C: U_JUKELINUX1_MMCARTAO[U_JUKELINUX1_KMMCC * 0x26 + 0x342f5e] = 0;
      until not (KMMCC < 100);
      NOMEARQ := PASTA + 'selecaomusicagratis.txt';
      SELECAOMG := 'Aleatoria';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Aleatoria');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, SELECAOMG);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        Form1.ComboBox11.Caption := SELECAOMG;
      end;
      NOMEARQ := PASTA + 'tempodeexposicaodamensagem1.txt';
      TEMPOEM1 := 2500;
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '2500');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        TEMPOEM1 := StrToIntDef(TEXTO, 2500);
      end;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbb0) + 0xdc)) (Form1.TimerSelecionaRitmoAutomatico,U_JUKELINUX1_TEMPOSRA);
      NOMEARQ := PASTA + 'tempotelacheia.txt';
      TEMPOTELACHEIA := 5000;
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '5000');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        TEMPOTELACHEIA := StrToIntDef(TEXTO, 5000);
      end;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc)) (Form1.TimerTelaCheia,U_JUKELINUX1_TEMPOTELACHEIA);
      NOMEARQ := PASTA + 'sorteiodecreditos.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Sem Sorteio');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        SORTEIODECREDITOS := TEXTO;
        Form1.ComboBox13.Caption := TEXTO;
      end;
      PULSOSPARASORTEIO := 0;
      PREMIOU := 0;
      NOMEARQ := PASTA + 'palhinhamusical.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Sem Palhinha Musical');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        PALHINHAMUSICAL := TEXTO;
        Form1.ComboBox14.Caption := TEXTO;
      end;
      TEMPOPARAINICIARAPALHINHA := 5;
      NOMEARQ := PASTA + 'tempoparainiciarpalhinhamusical.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 53);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        TEMPOPARAINICIARAPALHINHA := StrToIntDef(TEXTO, 5);
      end;
      if PALHINHAMUSICAL <> 'Sem Palhinha Musical' then begin
        Form1.TimerPalhinha.Enabled := True;
        MUSICAQUEJATOCOUAPALHINHA := '';
        PALHINHASPORREAL := 0;
        if PALHINHAMUSICAL = 'Palhinha de 10 Segundos' then begin
          TEMPODEINTRODUCAOMUSICAL := 10;
        end;
        if PALHINHAMUSICAL = 'Palhinha de 15 Segundos' then begin
          TEMPODEINTRODUCAOMUSICAL := 15;
        end;
        if PALHINHAMUSICAL = 'Palhinha de 20 Segundos' then begin
          TEMPODEINTRODUCAOMUSICAL := 20;
        end;
        if PALHINHAMUSICAL = 'Palhinha de 25 Segundos' then begin
          TEMPODEINTRODUCAOMUSICAL := 25;
        end;
        if PALHINHAMUSICAL = 'Palhinha de 30 Segundos' then begin
          TEMPODEINTRODUCAOMUSICAL := 30;
        end;
      end;
      ORIGEMPALHINHAANTERIOR := '';
      ORIGEMPALHINHA := ' ';
      PARARPALHINHA := 0;
      Form1.ShapePalhinha.Hide;
      Form1.ImagePalhinha.Hide;
      Form1.LabelQtdPalhinha.Hide;
      Form1.LabelTempoAindaTocandoAPalhinha.Hide;
      TEMPOPALHINHA := 0;
      NOMEARQ := PASTA + 'palhinhaporreal.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 54);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        PALHINHASPORREALCONFIG := StrToIntDef(TEXTO, 6);
      end;
      NOMEARQ := PASTA + 'serial.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '???');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, SERIAL);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        if SERIAL = '???' then begin
          SERIAL := LETRASEXE;
        end;
        // C: U_JUKELINUX1_NOMEDOCLIENTE = "L&&L Millenium Ltda";
        SERIAL := SERIAL + JC_CODIGODAMAQUINA;
      end;
      NOMEARQ := PASTA + 'alterarresolucaodolinux.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 83);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        if TEXTO = 'S' then begin
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x69c) + 0x454)) (Form1.CheckBoxResolucaoMonitor,CONCAT31(uVar9,1));
        end
        else begin
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x69c) + 0x454)) (Form1.CheckBoxResolucaoMonitor,(uint)uVar9 << 8);
        end;
      end;
      NOMEARQ := PASTA + 'limitarvolume.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Não Limitar Volume');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, LIMITARVOLUMEOPC);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        Form1.ComboBox6.Caption := LIMITARVOLUMEOPC;
        // C: fpc_ansistr_copy(U_JUKELINUX1_LIMITARVOLUMEOPC,1,1);
        if local_51c = 'N' then begin
          // C: U_JUKELINUX1_LIMITARVOLUMESTR._0_2_ = 0x3001;
        end
        else begin
          // C: fpc_ansistr_copy(U_JUKELINUX1_LIMITARVOLUMEOPC,0x13,2);
          LIMITARVOLUMESTR := local_51c;
        end;
        LIMITARVOLUMESTR := local_51c;
        LIMITARVOLUME := StrToIntDef(local_51c, 100);
      end;
      VOLUMELIMITADO := 0;
      NOMEARQ := PASTA + 'ordemdoscds.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Ritmo + Alfabetica');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        ORDEMDOSCDS := TEXTO;
        Form1.ComboBox3.Caption := TEXTO;
      end;
      NOMEARQ := PASTA + 'sentidodapaginacao.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Anti-Horário');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        SENTIDODAPAGINACAO := TEXTO;
        Form1.ComboBox12.Caption := TEXTO;
      end;
      NOMEARQ := PASTA + 'periodolancamento.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '45');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, PERIODOSTR);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      Form1.ComboBoxMusPeriodo.Caption := PERIODOSTR;
      local_51c := PASTA + 'ultimaatualizacao.txt';
      cVar3 := FileExists(local_51c);
      if not cVar3 then begin
        local_51c := PASTA + 'ultimaatualizacao.txt';
        local_620 := local_51c;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 45);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 45);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      local_51c := PASTA + 'ultimaatualizacao.txt';
      cVar3 := FileExists(local_51c);
      if cVar3 then begin
        local_51c := PASTA + 'ultimaatualizacao.txt';
        local_620 := local_51c;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, ULTIMAATU);
        Readln(ARQTEXTO);
        Read(ARQTEXTO, QTDCDSDAULTIMAATU);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      local_52c := ULTIMAATU;
      local_528 := ' Qtd. de Cds: ';
      local_524 := QTDCDSDAULTIMAATU;
      local_520 := local_52c + local_528 + local_524;
      Form1.LabelMusUltima2.Caption := local_520;
      NOMEARQ := PASTA + 'ritmosxjgps.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'AXE');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'axe.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'BLACK');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'black.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'BREGA');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'brega.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'DANCE E TECNO');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'dance e tecno.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'FLASHBACK');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'flashback.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'FORRO');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'forro.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'FUNK');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'funk.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'GOSPEL');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'gospel.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'INTERNACIONAL');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'internacional.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'LAMBADAO');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'lambadao.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, ' LANCAMENTOS');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'lancamentos.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'MPB');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'mpb.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'PAGODE');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'pagode.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'RAP');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'rap.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'RAP/FUNK');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'rap-funk.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'FUNK');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'funk.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'REGGAE');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'reggae.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'ROCK');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'rock.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'SAMBA/PAGODE');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'samba-pagode.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'SERTANEJO');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'sertanejo.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'SERTANEJO RAIZ');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'sertanejo raiz.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'NOSTALGIA');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'nostalgia.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'INFANTIL');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'infantil.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '50+TOCADOS');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '50maistocados.jpg');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        KRJ := 0;
        while True do begin
          cVar3 := Eof(ARQTEXTO);
          if cVar3 then begin Break; end;
          Read(ARQTEXTO, TEXTO1);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, TEXTO2);
          Readln(ARQTEXTO);
          KRJ := KRJ + 1;
          iVar5 := KRJ;
          // C: *(char ** )(iVar5 * 8 + 0x93008c8) = U_JUKELINUX1_TEXTO1;
          iVar5 := KRJ;
          // C: *(char ** )(iVar5 * 8 + 0x93008cc) = U_JUKELINUX1_TEXTO2;
        end;
        TOTALRJ := KRJ;
        CloseFile(ARQTEXTO);
      end;
      NOMEARQ := PASTA + 'letrasxjgps.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 48);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '0.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 49);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '1.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 50);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '2.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 51);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '3.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 52);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '4.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 53);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '5.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 54);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '6.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 55);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '7.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 56);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '8.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 57);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '9.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 65);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'a.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 66);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'b.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 67);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'c.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 68);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'd.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 69);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'e.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 70);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'f.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 71);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'g.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 72);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'h.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 73);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'i.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 74);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'j.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 75);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'k.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 76);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'l.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 77);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'm.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 78);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'n.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 79);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'o.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 80);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'p.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 81);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'q.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 82);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'r.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 83);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 's.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 84);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 't.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 85);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'u.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 86);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'v.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 87);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'w.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 88);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'x.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 89);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'y.jpg');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 90);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'z.jpg');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        KLJ := 0;
        while True do begin
          cVar3 := Eof(ARQTEXTO);
          if cVar3 then begin Break; end;
          Read(ARQTEXTO, TEXTO1);
          Readln(ARQTEXTO);
          Read(ARQTEXTO, TEXTO2);
          Readln(ARQTEXTO);
          KLJ := KLJ + 1;
          iVar5 := KLJ;
          // C: *(char ** )(iVar5 * 8 + 0x9300bf8) = U_JUKELINUX1_TEXTO1;
          iVar5 := KLJ;
          // C: *(char ** )(iVar5 * 8 + 0x9300bfc) = U_JUKELINUX1_TEXTO2;
        end;
        TOTALLJ := KLJ;
        CloseFile(ARQTEXTO);
      end;
      NOMEARQ := PASTA + 'interfaceteclado.txt';
      local_620 := NOMEARQ;
      AssignFile(ARQTEXTO, local_620);
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '74');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '73');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '72');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '70');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '71');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '75');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '81');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '65');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '78');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '79');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '67');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 48);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '66');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 48);
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '-----------------');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Musica+');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Musica-');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'CD+');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'CD-');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Ritmo');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Tocar');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Cancelar');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Credito');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'C.Remoto+');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'C.Remoto-');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Menu');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'CreditoGratisVIP');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Credito2');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Karaoke');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        Sleep(500);
      end;
      if LETRASEXE = 'BRG' then begin
        local_624 := PASTACHAVE + 'interfaceteclado.txt';
        cVar3 := FileExists(local_624);
        if not cVar3 then begin
          ShowMessage('2');
          local_624 := PASTACHAVE + 'interfaceteclado.txt';
          // C: puVar6 = local_624;
          if False { C: local_624 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar6,&local_62c);
          // C: uVar2 = local_62c;
          local_638 := PASTA + 'interfaceteclado.txt';
          // C: puVar6 = local_638;
          if False { C: local_638 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar6,&local_634);
          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_634,uVar2,extraout_ECX_00 & 0xffffff00);
          Gravalog('Nao existia o arquivo no Pendrive, entao Gravou Automaticamente o Arquivo "interfaceteclado.txt" da HD para o Pendrive');
        end
        else begin
          ShowMessage('1');
          local_628 := PASTA + 'interfaceteclado.txt';
          // C: puVar6 = local_628;
          if False { C: local_628 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar6,&local_624);
          // C: puVar6 = local_624;
          local_630 := PASTACHAVE + 'interfaceteclado.txt';
          // C: puVar7 = local_630;
          if False { C: local_630 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar7,&local_62c);
          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_62c,puVar6,extraout_ECX & 0xffffff00);
          Gravalog('Restaurou Automaticamente o Arquivo "interfaceteclado.txt" do Pendrive para a HD');
        end;
      end;
      local_620 := NOMEARQ;
      AssignFile(ARQTEXTO, local_620);
      Reset(ARQTEXTO);
      while True do begin
        cVar3 := Eof(ARQTEXTO);
        if cVar3 then begin Break; end;
        local_100 := local_100 + 1;
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        iVar5 := local_100;
        // C: *(undefined4 * )(local_1e0 + iVar5 * 4 + 8) = U_JUKELINUX1_TEXTOTECLA;
      end;
      CloseFile(ARQTEXTO);
      if local_100 = 27 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Rewrite(ARQTEXTO);
        repeat
          local_100 := local_100 + 1;
          // C: fpc_write_text_ansistr (0,U_JUKELINUX1_ARQTEXTO,*(undefined4 * )(local_1e0 + local_100 * 4 + 8));
          Writeln(ARQTEXTO);
          if local_100 = 13 then begin
            Write(ARQTEXTO, 48);
            Writeln(ARQTEXTO);
          end;
        until not (local_100 < 27);
        Write(ARQTEXTO, 'Karaoke');
        Writeln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_620 := NOMEARQ;
        AssignFile(ARQTEXTO, local_620);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLAMUSICAMAIS := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLAMUSICAMENOS := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACDMAIS := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACDMENOS := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLARITMO := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLATOCAR := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACANCELAR := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACREDITO := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACRMAIS := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACRMENOS := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLAMENU := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACREDITOGRATISVIP := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLACREDITO2 := StrToIntDef(TEXTOTECLA, 0);
        Read(ARQTEXTO, TEXTOTECLA);
        Readln(ARQTEXTO);
        TECLAKARAOKE := StrToIntDef(TEXTOTECLA, 0);
        CloseFile(ARQTEXTO);
        local_63c := IntToStr(TECLAMUSICAMAIS);
        Form1.EditMusicaMais.Caption := local_63c;
        local_63c := IntToStr(TECLAMUSICAMENOS);
        Form1.EditMusicaMenos.Caption := local_63c;
        local_63c := IntToStr(TECLACDMAIS);
        Form1.EditCDMais.Caption := local_63c;
        local_63c := IntToStr(TECLACDMENOS);
        Form1.EditCDMenos.Caption := local_63c;
        local_63c := IntToStr(TECLARITMO);
        Form1.EditRitmo.Caption := local_63c;
        local_63c := IntToStr(TECLATOCAR);
        Form1.EditTocar.Caption := local_63c;
        local_63c := IntToStr(TECLACANCELAR);
        Form1.EditCancelar.Caption := local_63c;
        local_63c := IntToStr(TECLACREDITO);
        Form1.EditCredito.Caption := local_63c;
        local_63c := IntToStr(TECLACRMAIS);
        Form1.EditCRMais.Caption := local_63c;
        local_63c := IntToStr(TECLACRMENOS);
        Form1.EditCRMenos.Caption := local_63c;
        local_63c := IntToStr(TECLAMENU);
        Form1.EditMenuTecla.Caption := local_63c;
        local_63c := IntToStr(TECLACREDITOGRATISVIP);
        Form1.EditCreditoVIP.Caption := local_63c;
        local_63c := IntToStr(TECLACREDITO2);
        Form1.EditCredito2.Caption := local_63c;
        local_63c := IntToStr(TECLAKARAOKE);
        Form1.EditKaraoke.Caption := local_63c;
      end;
      local_634 := PASTA + 'tocando.txt';
      cVar3 := FileExists(local_634);
      if cVar3 then begin
        // C: fpc_pchar_to_ansistr("ocando.txt ÿÿÿÿ>   #########################ATENCAO##############################  ÿÿÿÿ6   Nao Encontrado o Arquivo ",&local_634);
        DeleteFile(local_634);
      end;
      NOMEARQ := PASTA + 'tocar.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        Gravalog('#########################ATENCAO##############################');
        Gravalog('Nao Encontrado o Arquivo Tocar.txt, recriado em branco');
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        if SEMPENDRIVE = 0 then begin
          local_634 := PASTACHAVE + 'tocar.txt';
          cVar3 := FileExists(local_634);
          if cVar3 then begin
            local_740 := PASTA + 'tocar.txt';
            // C: puVar6 = local_740;
            if False { C: local_740 == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar6,&local_634);
            // C: uVar2 = local_634;
            local_748 := PASTACHAVE + 'tocar.txt';
            // C: puVar6 = local_748;
            if False { C: local_748 == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar6,&local_744);
            // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_744,uVar2,extraout_ECX_01 & 0xffffff00);
            Gravalog('Restaurou o Arquivo Tocar do Pendrive, Nao existia o Arquivo na HD');
          end;
        end;
      end;
      NOMEARQ := PASTA + 'tocar.txt';
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTOCAR, local_73c);
        Reset(ARQTOCAR);
        while True do begin
          cVar3 := Eof(ARQTOCAR);
          if cVar3 then begin Break; end;
          Read(ARQTOCAR, TEXTO);
          Readln(ARQTOCAR);
          local_104 := local_104 + 1;
        end;
        CloseFile(ARQTOCAR);
      end;
      if SEMPENDRIVE = 0 then begin
        NOMEARQ := PASTACHAVE + 'tocar.txt';
        cVar3 := FileExists(NOMEARQ);
        if cVar3 then begin
          local_73c := NOMEARQ;
          AssignFile(ARQTOCAR, local_73c);
          Reset(ARQTOCAR);
          while True do begin
            cVar3 := Eof(ARQTOCAR);
            if cVar3 then begin Break; end;
            Read(ARQTOCAR, TEXTO);
            Readln(ARQTOCAR);
            local_108 := local_108 + 1;
          end;
          CloseFile(ARQTOCAR);
        end;
        if (0 < local_108) and (local_104 = 0) then begin
          local_74c := PASTA + 'tocar.txt';
          // C: puVar6 = local_74c;
          if False { C: local_74c == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar6,&local_744);
          // C: uVar2 = local_744;
          local_754 := PASTACHAVE + 'tocar.txt';
          // C: puVar6 = local_754;
          if False { C: local_754 == (undefined1 * )0x0 } then begin
          end;
          // C: fpc_pchar_to_ansistr(puVar6,&local_750);
          // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_750,uVar2,extraout_ECX_02 & 0xffffff00);
          Gravalog('Restaurou o Arquivo Tocar do Pendrive, Arquivo da Em Branco');
        end;
      end;
      NOMEARQ := PASTA + 'frases.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Seja Bem Vindo');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Escolha sua Musica Preferida');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Divirta-se');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'CDs e DVDs Selecionados pra Voce');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Varios Generos Musicais');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Coloque Credito e Escolha a sua Musica Preferida');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Obrigado pela Preferencia');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Confira os Lancamentos');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'DVDs Musicais Exclusivos pra Voce');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Aqui Voce faz a Festa');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        KFRASE := 0;
        while True do begin
          cVar3 := Eof(ARQTEXTO);
          if cVar3 then begin Break; end;
          KFRASE := KFRASE + 1;
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          // C: fpc_ansistr_concat(U_JUKELINUX1_KFRASE * 4 + 0x9301bfc,U_JUKELINUX1_TEXTO, "            ");
          iVar5 := KFRASE;
          // C: fpc_ansistr_incr_ref ( *(undefined4 * )(U_JUKELINUX1_ARQTOCARX + U_JUKELINUX1_KFRASE * 4 + 0x24c));
          iVar8 := KFRASE;
          // C: *(undefined4 * )(iVar8 * 4 + 0x9301ccc) = *(undefined4 * )(U_JUKELINUX1_ARQTOCARX + iVar5 * 4 + 0x24c);
        end;
        CloseFile(ARQTEXTO);
        TOTALFRASE := KFRASE;
        POSFRASE := 0;
      end;
      NOMEARQ := PASTA + 'velocidadedisplay.txt';
      TEXTO := '150';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '150');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      VELOCIDADEDISPLAY := StrToIntDef(TEXTO, 150);
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb9c) + 0xdc)) (Form1.TimerRodaDisplay,U_JUKELINUX1_VELOCIDADEDISPLAY);
      NOMEARQ := PASTA + 'aumentavolumecomumtoque.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Pressionando');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      AUMENTAVOLUMECOMUMTOQUE := TEXTO;
      // C: fpc_ansistr_copy(U_JUKELINUX1_AUMENTAVOLUMECOMUMTOQUE,1,1);
      if local_750 = 'S' then begin
        AUMENTAVOLUMECOMUMTOQUE := 'Um Toque';
      end;
      // C: fpc_ansistr_copy(U_JUKELINUX1_AUMENTAVOLUMECOMUMTOQUE,1,1);
      if local_750 = 'N' then begin
        AUMENTAVOLUMECOMUMTOQUE := 'Pressionando';
      end;
      Form1.ComboBox16.Caption := AUMENTAVOLUMECOMUMTOQUE;
      TOQUEVOLUMEMAIS := 0;
      TOQUEVOLUMEMENOS := 0;
      NOMEARQ := PASTA + 'tempovolumeumtoque.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '250');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      TEMPOVOLUMEUMTOQUE := StrToIntDef(TEXTO, 250);
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb4c) + 0xdc)) (Form1.TimerVolumeMais,U_JUKELINUX1_TEMPOVOLUMEUMTOQUE);
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbd4) + 0xdc)) (Form1.TimerVolumeMenos,U_JUKELINUX1_TEMPOVOLUMEUMTOQUE);
      NOMEARQ := PASTA + 'autoteste.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Sim');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      AUTOTESTE := TEXTO;
      Form1.ComboBox22.Caption := TEXTO;
      NOMEARQ := PASTA + 'volumepelopainel.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Desativado');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      VOLUMEPELOPAINEL := TEXTO;
      Form1.ComboBox23.Caption := TEXTO;
      NOMEARQ := PASTA + 'tocados.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        local_750 := DateToStr(Date);
        Write(ARQTEXTO, local_750);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      NOMEARQ := PASTA + 'volume.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '100');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        VOLUME := StrToIntDef(TEXTO, 100);
      end;
      if RELOGIOTOTALSTR = '0' then begin
        NOMEARQ := PASTA + 'relogiototal.txt';
        cVar3 := FileExists(NOMEARQ);
        if not cVar3 then begin
          local_73c := NOMEARQ;
          AssignFile(ARQTEXTO, local_73c);
          Rewrite(ARQTEXTO);
          RELOGIOTOTALSTR := '0';
          local_750 := Cripta(RELOGIOTOTALSTR);
          Write(ARQTEXTO, local_750);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
      end;
      NOMEARQ := PASTA + 'relogiototal.txt';
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_750 := Descripta(TEXTO);
        RELOGIOTOTALSTR := local_750;
        CloseFile(ARQTEXTO);
      end;
      RELOGIOTOTAL := StrToIntDef(RELOGIOTOTALSTR, 0);
      if RELOGIOTOTALSTR = '0' then begin
        NOMEARQ := PASTA + 'relogioparcial.txt';
        cVar3 := FileExists(NOMEARQ);
        if not cVar3 then begin
          local_73c := NOMEARQ;
          AssignFile(ARQTEXTO, local_73c);
          Rewrite(ARQTEXTO);
          RELOGIOPARCIALSTR := '0';
          local_750 := Cripta(RELOGIOPARCIALSTR);
          Write(ARQTEXTO, local_750);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end;
      end;
      NOMEARQ := PASTA + 'relogioparcial.txt';
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_750 := Descripta(TEXTO);
        RELOGIOPARCIALSTR := local_750;
        CloseFile(ARQTEXTO);
      end;
      RELOGIOPARCIAL := StrToIntDef(RELOGIOPARCIALSTR, 0);
      RELOGIOGRATISSTR := '0';
      NOMEARQ := PASTA + 'relogiogratis.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        local_750 := Cripta('0');
        Write(ARQTEXTO, local_750);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_750 := Descripta(TEXTO);
        RELOGIOGRATISSTR := local_750;
        CloseFile(ARQTEXTO);
      end;
      RELOGIOGRATIS := StrToIntDef(RELOGIOGRATISSTR, 0);
      RELOGIOGRATISVIPSTR := '0';
      NOMEARQ := PASTA + 'relogiogratisvip.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        local_750 := Cripta('0');
        Write(ARQTEXTO, local_750);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_750 := Descripta(TEXTO);
        RELOGIOGRATISVIPSTR := local_750;
      end;
      RELOGIOGRATISVIP := StrToIntDef(RELOGIOGRATISVIPSTR, 0);
      QTDCREDITOSGRATIS := 0;
      NOMEARQ := PASTA + 'qtdcreditosgratis.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        local_750 := Cripta('0');
        Write(ARQTEXTO, local_750);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_750 := Descripta(TEXTO);
        QTDCREDITOSGRATIS := StrToIntDef(local_750, 0);
        local_758 := IntToStr(QTDCREDITOSGRATIS);
        Form1.ComboBox18.Caption := local_758;
      end;
      QTDCREDITOSGRATISVIP := 0;
      NOMEARQ := PASTA + 'qtdcreditosgratisvip.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_73c := NOMEARQ;
        AssignFile(ARQTEXTO, local_73c);
        Rewrite(ARQTEXTO);
        local_750 := Cripta('0');
        Write(ARQTEXTO, local_750);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_750 := Descripta(TEXTO);
        QTDCREDITOSGRATISVIP := StrToIntDef(local_750, 0);
        local_758 := IntToStr(QTDCREDITOSGRATISVIP);
        Form1.ComboBox19.Caption := local_758;
      end;
      NOMEARQ := PASTA + 'reaisxmusicas.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '1x2');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, REAISXMUSICAS);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      Form1.ComboBox1.Caption := REAISXMUSICAS;
      NOMEARQ := PASTA + 'touchscreen.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Não');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TOUCHSCREEN);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      NOMEARQ := PASTA + 'formadepaginacao.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Dentro do Ritmo');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, FORMADEPAGINACAO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      Form1.ComboBox15.Caption := FORMADEPAGINACAO;
      NOMEARQ := PASTA + 'tempopropagandatv.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '15');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        TEMPOPROPAGANDASTR := TEXTO;
      end;
      iVar5 := StrToIntDef(TEMPOPROPAGANDASTR, 15);
      TEMPOPROPAGANDA := iVar5 * 1000;
      NOMEARQ := PASTA + 'propaganda.txt';
      PROPAGANDA := 'Sem Propaganda';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Sem Propaganda');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, '-----------------------');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Fotos PNG no Monitor');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Fotos para Bar no Monitor');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Fotos para Boate no Monitor');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Fotos para Bar na TV');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Fotos para Boate na TV');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Videos para Bar na TV/Monitor');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Videos para Boate na TV/Monitor');
        Writeln(ARQTEXTO);
        Write(ARQTEXTO, 'Propaganda Padrao Aprova');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        Form1.ComboBox5.Caption := TEXTO;
        PROPAGANDA := TEXTO;
      end;
      NOMEARQ := PASTA + 'tempoparapaginarsozinho.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '60');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        if TEXTO = 'Desligado' then begin
          TEMPOPARAPAGINARSOZINHO := 0;
        end
        else begin
          TEMPOPARAPAGINARSOZINHO := StrToIntDef(TEXTO, 60);
        end;
        DIRECAO := 'Frente';
        TEMPOEMSEGUNDOSPAGINARSOZINHO := 0;
        local_85c := IntToStr(TEMPOPARAPAGINARSOZINHO);
        TEMPOPARAPAGINARSOZINHOOPC := local_85c;
        if local_85c = '0' then begin
          TEMPOPARAPAGINARSOZINHOOPC := 'Desligado';
        end;
      end;
      NOMEARQ := PASTA + 'porcentagemdoponto.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, '30');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, PORCENTAGEMDOPONTOSTR);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      PORCENTAGEMDOPONTO := StrToIntDef(PORCENTAGEMDOPONTOSTR, 30);
      Form1.ComboBoxPorcento.Caption := PORCENTAGEMDOPONTOSTR;
      local_85c := PASTA + 'musicagratis.txt';
      cVar3 := FileExists(local_85c);
      if not cVar3 then begin
        local_85c := PASTA + 'musicagratis.txt';
        local_858 := local_85c;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        Write(ARQTEXTO, 'Sem Musica Gratis');
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      local_85c := PASTA + 'musicagratis.txt';
      cVar3 := FileExists(local_85c);
      if cVar3 then begin
        local_85c := PASTA + 'musicagratis.txt';
        local_858 := local_85c;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, MUSICAGRATIS);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      Form1.ComboBox4.Caption := MUSICAGRATIS;
      TOCANDOMUSICAGRATIS := 0;
      NOMEARQ := PASTA + 'creditos.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        local_85c := Cripta('0');
        Write(ARQTEXTO, local_85c);
        Writeln(ARQTEXTO);
        local_85c := Cripta(JC_SERIALPENDRIVE);
        Write(ARQTEXTO, local_85c);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      // C: U_JUKELINUX1_JC_SPC = (char * )0x0;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_85c := Descripta(TEXTO);
        CREDITOSSTR := local_85c;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_85c := Descripta(TEXTO);
        JC_SPC := local_85c;
        CloseFile(ARQTEXTO);
      end;
      if JC_SPC = JC_SERIALPENDRIVE then begin
        CREDITOS := StrToIntDef(CREDITOSSTR, 0);
      end
      else begin
        CREDITOS := -1;
        local_768 := 'Arquivo de Creditos com Problemas: jc_spc=';
        local_764 := JC_SPC;
        local_760 := ' <> jc_serialpendrive=';
        local_75c := JC_SERIALPENDRIVE;
        local_85c := local_768 + local_764 + local_760 + local_75c;
        Gravalog(local_85c);
      end;
      if SEMPENDRIVE <> 0 then begin
        CREDITOS := StrToIntDef(CREDITOSSTR, 0);
      end;
      if (CREDITOS = -1) or (CREDITOS = 0) then begin
        NOMEARQBACKUP := PASTACHAVE + 'creditos.txt';
        cVar3 := FileExists(NOMEARQBACKUP);
        if cVar3 then begin
          local_858 := NOMEARQBACKUP;
          AssignFile(ARQTEXTO, local_858);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          local_85c := Descripta(TEXTO);
          XCREDITOSSTR := local_85c;
          Read(ARQTEXTO, TEXTO);
          Readln(ARQTEXTO);
          local_85c := Descripta(TEXTO);
          XJC_SPC := local_85c;
          CloseFile(ARQTEXTO);
          if XJC_SPC = JC_SERIALPENDRIVE then begin
            iVar5 := StrToIntDef(XCREDITOSSTR, 0);
            iVar8 := StrToIntDef(CREDITOSSTR, 0);
            if iVar8 < iVar5 then begin
              local_860 := PASTA + 'creditos.txt';
              // C: puVar6 = local_860;
              if False { C: local_860 == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar6,&local_85c);
              // C: pcVar1 = local_85c;
              local_868 := PASTACHAVE + 'creditos.txt';
              // C: puVar6 = local_868;
              if False { C: local_868 == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar6,&local_864);
              // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_864,pcVar1,extraout_ECX_03 & 0xffffff00);
              local_864 := 'Restaurando os Creditos do Pendrive Chave, Créditos = ' + XCREDITOSSTR;
              Gravalog(local_864);
              // C: U_JUKELINUX1_JC_SPC = (char * )0x0;
              NOMEARQ := PASTA + 'creditos.txt';
              cVar3 := FileExists(NOMEARQ);
              if cVar3 then begin
                local_858 := NOMEARQ;
                AssignFile(ARQTEXTO, local_858);
                Reset(ARQTEXTO);
                Read(ARQTEXTO, TEXTO);
                Readln(ARQTEXTO);
                local_864 := Descripta(TEXTO);
                CREDITOSSTR := local_864;
                Read(ARQTEXTO, TEXTO);
                Readln(ARQTEXTO);
                local_864 := Descripta(TEXTO);
                JC_SPC := local_864;
                CloseFile(ARQTEXTO);
              end;
              if JC_SPC = JC_SERIALPENDRIVE then begin
                CREDITOS := StrToIntDef(CREDITOSSTR, 0);
              end
              else begin
                CREDITOS := 0;
              end;
              local_864 := 'Lendo o Arquivo Creditos.txt da HD, Créditos = ' + CREDITOSSTR;
              Gravalog(local_864);
            end;
          end
          else begin
            local_768 := 'Erro Restaurando Creditos.txt do Pendrive Chave: xjc_spc=';
            local_764 := XJC_SPC;
            local_760 := ' <> jc_serialpendrive=';
            local_75c := JC_SERIALPENDRIVE;
            local_864 := local_768 + local_764 + local_760 + local_75c;
            Gravalog(local_864);
          end;
        end;
      end;
      NOMEARQ := PASTA + 'creditosvip.txt';
      cVar3 := FileExists(NOMEARQ);
      if not cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Rewrite(ARQTEXTO);
        local_864 := Cripta('0');
        Write(ARQTEXTO, local_864);
        Writeln(ARQTEXTO);
        local_864 := Cripta(JC_SERIALPENDRIVE);
        Write(ARQTEXTO, local_864);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
      end;
      // C: U_JUKELINUX1_JC_SPC = (char * )0x0;
      cVar3 := FileExists(NOMEARQ);
      if cVar3 then begin
        local_858 := NOMEARQ;
        AssignFile(ARQTEXTO, local_858);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_864 := Descripta(TEXTO);
        CREDITOSSTRVIP := local_864;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_864 := Descripta(TEXTO);
        JC_SPC := local_864;
        CloseFile(ARQTEXTO);
      end;
      if JC_SPC = JC_SERIALPENDRIVE then begin
        CREDITOSVIP := StrToIntDef(CREDITOSSTRVIP, 0);
      end
      else begin
        CREDITOSVIP := 0;
      end;
      Gravalog('Fim da Rotina Create');
    end;
    ROTINA_DO_ACTIVATE := 1;
  end;
end;

{ JUKELINUX1_TFORM1_$__FORMKEYDOWN$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  local_3c: AnsiString;
  cVar1: Boolean;
  iVar3: LongInt;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  local_10 := Self;
  local_c := Key;
  local_8 := Sender;
  begin
    if False { C: *local_c == 0x1b } then begin
      local_10.Close;
    end;
    if ALTERANDOFRASES = 0 then begin
      if False { C: (( *local_c == U_JUKELINUX1_TECLACDMAIS) && (U_JUKELINUX1_MOSTRANDORITMOS == '\0')) && (U_JUKELINUX1_MOSTRANDOLETRAS == '\0') } then begin
        Presstecla;
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        if RODAVOLUME = 0 then begin
          if False { C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME == (char * )0x0 } then begin
            RODAVOLUME := 1;
            TECLAANTERIORRODAVOLUME := 'CD+';
          end
          else begin
            RODAVOLUME := 0;
            // C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char * )0x0;
          end;
        end;
        if RODAVOLUME = 3 then begin
          // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_TECLAANTERIORRODAVOLUME,"CD-");
          if iVar3 = 0 then begin
            RODAVOLUME := 4;
            TECLAANTERIORRODAVOLUME := 'CD+';
          end
          else begin
            RODAVOLUME := 0;
            // C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char * )0x0;
          end;
        end;
        // C: iVar3 = fpc_ansistr_compare_equal(U_JUKELINUX1_TECLAANTERIORRODAVOLUME,"CD-");
        if False { C: ((iVar3 == 0) && (U_JUKELINUX1_RODAVOLUME == 6)) && (iVar3 = fpc_ansistr_compare_equal(U_JUKELINUX1_VOLUMEPELOPAINEL,"Ativado"), iVar3 == 0) } then begin
          RODAVOLUME := 7;
          VOLUMEATIVADO := 1;
          Form1.TimerDesativaVolume.Enabled := False;
          Form1.TimerDesativaVolume.Enabled := True;
        end;
        if VOLUMEATIVADO = 0 then begin
          Form1.TimerPaginaMais.Enabled := True;
          SEGURANDOTECLA := SEGURANDOTECLA + 1;
        end
        else begin
          Rotina_Volumemais;
        end;
      end;
      if False { C: (( *local_c == U_JUKELINUX1_TECLACDMENOS) && (U_JUKELINUX1_MOSTRANDORITMOS == '\0')) && (U_JUKELINUX1_MOSTRANDOLETRAS == '\0') } then begin
        Presstecla;
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        if RODAVOLUME = 2 then begin
          // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_TECLAANTERIORRODAVOLUME,"Musica+");
          if iVar3 = 0 then begin
            RODAVOLUME := 3;
            TECLAANTERIORRODAVOLUME := 'CD-';
          end
          else begin
            RODAVOLUME := 0;
            // C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char * )0x0;
          end;
        end;
        if RODAVOLUME = 5 then begin
          // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_TECLAANTERIORRODAVOLUME,"Musica+");
          if iVar3 = 0 then begin
            RODAVOLUME := 6;
            TECLAANTERIORRODAVOLUME := 'CD-';
          end
          else begin
            RODAVOLUME := 0;
            // C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char * )0x0;
          end;
        end;
        if VOLUMEATIVADO = 0 then begin
          Form1.TimerPaginaMenos.Enabled := True;
          SEGURANDOTECLA := SEGURANDOTECLA + 1;
        end
        else begin
          Rotina_Volumemenos;
        end;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLAMUSICAMENOS } then begin
        Presstecla;
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        if False { C: U_JUKELINUX1_MUSICASELECIONADA < (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90] } then begin
          Desselecionamusica;
          MUSICASELECIONADA := MUSICASELECIONADA + 1;
          MUSICASELECIONADAPOSTELA := MUSICASELECIONADAPOSTELA + 1;
          if 12 < MUSICASELECIONADAPOSTELA then begin
            MUSICASELECIONADAPOSTELA := 12;
          end;
          Selecionamusica;
          if RODAVOLUME = 1 then begin
            // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_TECLAANTERIORRODAVOLUME,"CD+");
            if iVar3 = 0 then begin
              RODAVOLUME := 2;
              TECLAANTERIORRODAVOLUME := 'Musica+';
            end
            else begin
              RODAVOLUME := 0;
              // C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char * )0x0;
            end;
          end;
          if RODAVOLUME = 4 then begin
            // C: iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_TECLAANTERIORRODAVOLUME,"CD+");
            if iVar3 = 0 then begin
              RODAVOLUME := 5;
              TECLAANTERIORRODAVOLUME := 'Musica+';
            end
            else begin
              RODAVOLUME := 0;
              // C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char * )0x0;
            end;
          end;
          if VOLUMEATIVADO <> 0 then begin
            Desativa_Volume_Pelo_Painel;
          end;
        end
        else begin
          Desselecionamusica;
          MUSICASELECIONADA := 1;
          MUSICASELECIONADAPOSTELA := 1;
          Selecionamusica;
          Mostra_Musicas(KMAT + 5);
        end;
        if (ESTANOMENU <> 0) and (SENHAOK = 1) then begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelPress1,local_3c);
          if local_3c = 'Pressione o Botão MÚSICA para Carregar a Atualização/Upg' then begin
            cVar1 := DirectoryExists(NOMEPASTAUPGRADE);
            if not cVar1 then begin
              Form1.PanelMusRelogio.Left := 15;
              Form1.PanelMusRelogio.Top := 350;
              if RESOLUCAO = 1024 then begin
                Form1.PanelMusRelogio.Width := 410;
              end;
              if RESOLUCAO = 1366 then begin
                Form1.PanelMusRelogio.Width := 675;
              end;
              if RESOLUCAO = 1440 then begin
                Form1.PanelMusRelogio.Width := 675;
              end;
              Form1.PanelMusRelogio.Height := 335;
              iVar3 := Form1.PanelMusRelogio.Width - Form1.PanelMusR.Width;
              // C: CONTROLS_TCONTROL____SETLEFT_LONGINT (Form1.PanelMusR,(int)(iVar3 + (iVar3 >> 0x1f & 1U)) >> 1);
              Form1.PanelMusRelogio.Show;
              // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa24) + 0x2fc))(Form1.PanelMusRelogio);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Excluicdpelalista;
              Form1.LabelPress1.Caption := 'Ok, Apagado a Lista de Exclusao';
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              // C: JUKELINUX1_TFORM1____BUTTONMUSCARREGARCLICK_TOBJECT(local_10,U_JUKELINUX1_FORM1);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Sleep(3000);
              Form1.PanelMusRelogio.Hide;
              Form1.LabelPress1.Font.Color := 65280;
              Form1.LabelPress1.Caption := 'Ok, Atualização Carregada';
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
            end
            else begin
              Form1.PanelUpgrade1.Left := 15;
              Form1.PanelUpgrade1.Top := 350;
              if RESOLUCAO = 1024 then begin
                Form1.PanelUpgrade1.Width := 410;
              end;
              if RESOLUCAO = 1366 then begin
                Form1.PanelUpgrade1.Width := 675;
              end;
              if RESOLUCAO = 1440 then begin
                Form1.PanelUpgrade1.Width := 675;
              end;
              Form1.PanelUpgrade1.Height := 335;
              Form1.PanelUpgrade1.Show;
              // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x678) + 0x2fc))(Form1.PanelUpgrade1);
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Form1.LabelUpgrade1.Caption := 'Aguarde...';
              // C: JUKELINUX1_TFORM1____BUTTONUPGRADECLICK_TOBJECT(local_10,local_8);
              Sleep(3000);
              Form1.PanelUpgrade1.Hide;
              FORM1.Refresh;
              // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
              Form1.LabelPress1.Font.Color := 65280;
              Form1.LabelPress1.Caption := 'Ok, Upgrade Carregado, Desligue e Ligue a Jukebox';
            end;
          end;
        end;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLAMUSICAMAIS } then begin
        Presstecla;
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        RODAVOLUME := 0;
        // C: U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char * )0x0;
        if MUSICASELECIONADAPOSTELA < 1 then begin
          Mostra_Musicas(KMAT + 5);
          // C: U_JUKELINUX1_MUSICASELECIONADA = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
          MUSICASELECIONADAPOSTELA := MUSICASELECIONADA;
          if 12 < MUSICASELECIONADA then begin
            MUSICASELECIONADAPOSTELA := 12;
          end;
          Selecionamusica;
        end
        else begin
          Desselecionamusica;
          MUSICASELECIONADA := MUSICASELECIONADA + -1;
          MUSICASELECIONADAPOSTELA := MUSICASELECIONADAPOSTELA + -1;
          Selecionamusica;
        end;
        if VOLUMEATIVADO <> 0 then begin
          Desativa_Volume_Pelo_Painel;
        end;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLACRMAIS } then begin
        Presstecla;
        if AUMENTAVOLUMECOMUMTOQUE = 'Um Toque' then begin
          if TOQUEVOLUMEMENOS = 1 then begin
            TOQUEVOLUMEMENOS := 0;
            Form1.TimerVolumeMenos.Enabled := False;
            TOQUEVOLUMEMAIS := 1;
          end;
          if TOQUEVOLUMEMAIS = 1 then begin
            TOQUEVOLUMEMAIS := 2;
            Form1.TimerVolumeMais.Enabled := False;
            TOQUEVOLUMEMENOS := 0;
            Form1.TimerVolumeMenos.Enabled := False;
          end;
          if TOQUEVOLUMEMAIS = 0 then begin
            TOQUEVOLUMEMAIS := 1;
            Form1.TimerVolumeMais.Enabled := True;
          end;
          if TOQUEVOLUMEMAIS = 2 then begin
            TOQUEVOLUMEMAIS := 0;
          end;
        end
        else begin
          Rotina_Volumemais;
        end;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLACRMENOS } then begin
        Presstecla;
        if AUMENTAVOLUMECOMUMTOQUE = 'Um Toque' then begin
          if TOQUEVOLUMEMAIS = 1 then begin
            TOQUEVOLUMEMAIS := 0;
            Form1.TimerVolumeMais.Enabled := False;
            TOQUEVOLUMEMENOS := 1;
          end;
          if TOQUEVOLUMEMENOS = 1 then begin
            TOQUEVOLUMEMENOS := 2;
            Form1.TimerVolumeMenos.Enabled := False;
            TOQUEVOLUMEMAIS := 0;
            Form1.TimerVolumeMais.Enabled := False;
          end;
          if TOQUEVOLUMEMENOS = 0 then begin
            TOQUEVOLUMEMENOS := 1;
            Form1.TimerVolumeMenos.Enabled := True;
          end;
          if TOQUEVOLUMEMENOS = 2 then begin
            TOQUEVOLUMEMENOS := 0;
          end;
        end
        else begin
          Rotina_Volumemenos;
        end;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__FORMKEYUP$TOBJECT$WORD$TSHIFTSTATE }
procedure TForm1.FormKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  iVar1, iVar2, local_110, local_210: LongInt;
  local_10: TForm1;
  local_8: TObject;
  local_c: Word;
begin
  if ALTERANDOFRASES = 0 then begin
    local_10 := Self;
    local_c := Key;
    local_8 := Sender;
    if LENDOCODIGODOCARTAO = 0 then begin
      if Key = TECLACREDITOGRATISVIP then begin
        Rotina_Creditosvip;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLAMENU } then begin
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        Rotina_Menu;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLACRMAIS } then begin
        Destravamensagem;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLACRMENOS } then begin
        Destravamensagem;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLACANCELAR } then begin
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        Rotina_Cancelar;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLATOCAR } then begin
        Rotina_Tocar;
        if VOLUMEATIVADO <> 0 then begin
          Desativa_Volume_Pelo_Painel;
        end;
      end;
      if False { C: ( *local_c == U_JUKELINUX1_TECLACREDITO) || ( *local_c == U_JUKELINUX1_TECLACREDITO2) } then begin
        Presstecla;
        Rotina_Creditos('Normal');
        if VOLUMEATIVADO <> 0 then begin
          Desativa_Volume_Pelo_Painel;
        end;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLARITMO } then begin
        Presstecla;
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        RODAVOLUME := 0;
        TECLAANTERIORRODAVOLUME := '';
        Rotina_Ritmos;
        if VOLUMEATIVADO <> 0 then begin
          Desativa_Volume_Pelo_Painel;
        end;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLACDMAIS } then begin
        Presstecla;
        if (MOSTRANDORITMOS = 0) and (MOSTRANDOLETRAS = 0) then begin
          SEGURANDOTECLA := 0;
        end;
        if MOSTRANDORITMOS <> 0 then begin
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Anti-Horário");
          iVar2 := NUMRITMOSELECIONADO;
          NUMRITMOSELECIONADO := iVar2;
          if False { C: (iVar1 == 0) && (U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + -1, U_JUKELINUX1_NUMRITMOSELECIONADO < 1) } then begin
            NUMRITMOSELECIONADO := iVar2;
          end;
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Horário");
          iVar2 := NUMRITMOSELECIONADO;
          NUMRITMOSELECIONADO := iVar2;
          if iVar1 = 0 then begin
            NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + 1;
            if TOTALMMRITMO < NUMRITMOSELECIONADO then begin
              NUMRITMOSELECIONADO := iVar2;
            end;
          end;
          Mostra_Ritmos;
          Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
          Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
        end;
        if MOSTRANDOLETRAS <> 0 then begin
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Anti-Horário");
          iVar2 := NUMLETRASELECIONADA;
          NUMLETRASELECIONADA := iVar2;
          if False { C: (iVar1 == 0) && (U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + -1, U_JUKELINUX1_NUMLETRASELECIONADA < 1) } then begin
            NUMLETRASELECIONADA := iVar2;
          end;
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Horário");
          iVar2 := NUMLETRASELECIONADA;
          NUMLETRASELECIONADA := iVar2;
          if iVar1 = 0 then begin
            NUMLETRASELECIONADA := NUMLETRASELECIONADA + 1;
            if TOTALMMLETRA < NUMLETRASELECIONADA then begin
              NUMLETRASELECIONADA := iVar2;
            end;
          end;
          Mostra_Letras;
          Form1.TimerSelecionaLetraAutomatico.Enabled := False;
          Form1.TimerSelecionaLetraAutomatico.Enabled := True;
        end;
      end;
      if False { C: *local_c == U_JUKELINUX1_TECLACDMENOS } then begin
        Presstecla;
        if (MOSTRANDORITMOS = 0) and (MOSTRANDOLETRAS = 0) then begin
          SEGURANDOTECLA := 0;
        end;
        if MOSTRANDORITMOS <> 0 then begin
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Anti-Horário");
          iVar2 := NUMRITMOSELECIONADO;
          NUMRITMOSELECIONADO := iVar2;
          if False { C: (iVar1 == 0) && (U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + 1, U_JUKELINUX1_TOTALMMRITMO < U_JUKELINUX1_NUMRITMOSELECIONADO) } then begin
            NUMRITMOSELECIONADO := iVar2;
          end;
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Horário");
          iVar2 := NUMRITMOSELECIONADO;
          NUMRITMOSELECIONADO := iVar2;
          if iVar1 = 0 then begin
            NUMRITMOSELECIONADO := NUMRITMOSELECIONADO + -1;
            if NUMRITMOSELECIONADO < 1 then begin
              NUMRITMOSELECIONADO := iVar2;
            end;
          end;
          Mostra_Ritmos;
          Form1.TimerSelecionaRitmoAutomatico.Enabled := False;
          Form1.TimerSelecionaRitmoAutomatico.Enabled := True;
        end;
        if MOSTRANDOLETRAS <> 0 then begin
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Anti-Horário");
          iVar2 := NUMLETRASELECIONADA;
          NUMLETRASELECIONADA := iVar2;
          if False { C: (iVar1 == 0) && (U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + 1, U_JUKELINUX1_TOTALMMLETRA < U_JUKELINUX1_NUMLETRASELECIONADA) } then begin
            NUMLETRASELECIONADA := iVar2;
          end;
          // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Horário");
          iVar2 := NUMLETRASELECIONADA;
          NUMLETRASELECIONADA := iVar2;
          if iVar1 = 0 then begin
            NUMLETRASELECIONADA := NUMLETRASELECIONADA + -1;
            if NUMLETRASELECIONADA < 1 then begin
              NUMLETRASELECIONADA := iVar2;
            end;
          end;
          Mostra_Letras;
          Form1.TimerSelecionaLetraAutomatico.Enabled := False;
          Form1.TimerSelecionaLetraAutomatico.Enabled := True;
        end;
      end;
    end;
    if LENDOCODIGODOCARTAO = 1 then begin
      // C: local_210[0] = (ushort)(byte)*local_c << 8 | 1;
      // C: fpc_shortstr_concat(local_110,0xff,&U_JUKELINUX1_CODIGODOCARTAO,local_210);
      // C: FPC_SHORTSTR_TO_SHORTSTR(&U_JUKELINUX1_CODIGODOCARTAO,0x14,local_110);
    end;
    if LENDOCODIGODOCARTAO = 0 then begin
      // C: iVar2 = fpc_ansistr_compare_equal(U_JUKELINUX1_CARTAOJUKEBOX,"Desativado");
      if False { C: (iVar2 != 0) && ( *local_c == 0x30) } then begin
        CODIGODOCARTAO := Chr(Key);
        // C: DAT_09646eb1 = (byte)*local_c;
        LENDOCODIGODOCARTAO := 1;
        Presstecla;
      end;
    end;
    if False { C: (U_JUKELINUX1_LENDOCODIGODOCARTAO == 1) && ( *local_c == 0xd) } then begin
      if CARTAOJUKEBOX = 'Boate' then begin
        Cartaocodbar_Boate;
      end;
      if CARTAOJUKEBOX = 'Bar' then begin
        Cartaocodbar_Bar;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__IMAGETELA1MOUSEDOWN$TOBJECT$TMOUSEBUTTON$TSHIFTSTATE$LONGINT$LONGINT }
procedure TForm1.ImageTela1MouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_c: TMouseButton;
  local_8: TObject;
begin
  local_10 := Self;
  local_c := Button;
  local_8 := Sender;
  begin
    local_3c := Copy(TOUCHSCREEN, 1, 1);
    if local_3c = 'S' then begin
      TOUCHPRESSIONADO := 1;
      Le_Touchscreen_Inicial;
      // C: DEBUGSTART_JUKELINUX1();
      Form1.TimerTouchScreen.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__IMAGETELA1MOUSEUP$TOBJECT$TMOUSEBUTTON$TSHIFTSTATE$LONGINT$LONGINT }
procedure TForm1.ImageTela1MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  local_3c: AnsiString;
  local_10: TForm1;
  local_c: TMouseButton;
  local_8: TObject;
begin
  local_10 := Self;
  local_c := Button;
  local_8 := Sender;
  begin
    local_3c := Copy(TOUCHSCREEN, 1, 1);
    if local_3c = 'S' then begin
      TOUCHPRESSIONADO := 0;
      Le_Touchscreen_Final;
      // C: DEBUGSTART_JUKELINUX1();
      Form1.TimerTouchScreen.Enabled := False;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__LABEL1024CLICK$TOBJECT }
procedure TForm1.Label1024Click(Sender: TObject);
begin
  DIMINUERESOLUCAO := DIMINUERESOLUCAO + 1;
  if DIMINUERESOLUCAO = 1 then begin
    // C: DIALOGS_SHOWMESSAGE_ANSISTRING("Se deseja ajustar a resolução para 1024x768\rClique em OK e clique novamente em [1024x768]");
    // C: param_3 = extraout_ECX;
  end;
  if DIMINUERESOLUCAO = 2 then begin
    DIMINUERESOLUCAO := 0;
    ESTADIGITANDOSENHA := 2;
    // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.ComboBox7,"1024x768",param_3,Self,Sender);
    // C: JUKELINUX1_TFORM1____COMBOBOX7CHANGE_TOBJECT(Self,U_JUKELINUX1_FORM1);
  end;
end;

{ JUKELINUX1_TFORM1_$__LABELCLIENTECLICK$TOBJECT }
procedure TForm1.LabelClienteClick(Sender: TObject);
begin
  Self.Close;
end;

{ JUKELINUX1_TFORM1_$__LABELENTRARNOMENUCLICK$TOBJECT }
procedure TForm1.LabelEntrarNoMenuClick(Sender: TObject);
var
  local_38, local_44: AnsiString;
  local_c: TForm1;
  local_8: TObject;
  local_3c, local_40: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Form1.PanelMenu.Left := 0;
    Form1.PanelMenu.Top := 0;
    Form1.PanelMenu.Width := RESOLUCAO;
    Form1.PanelMenu.Height := RESOLUCAOALTURA;
    Form1.Labelversao.Caption := VERSAO;
    local_44 := LETRASEXE;
    local_40 := ' ';
    local_3c := JC_CODIGODAMAQUINA;
    local_38 := local_44 + local_40 + local_3c;
    Form1.LabelCliente.Caption := local_38;
    Voltamenu;
    Form1.EditSenha.Caption := '';
    SENHAOK := 1;
    if RESOLUCAO = 1024 then begin
      Form1.PanelSenha.Left := 230;
      Form1.PanelSenha.Top := 140;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.PanelSenha.Left := 450;
      Form1.PanelSenha.Top := 140;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.PanelSenha.Left := 450;
      Form1.PanelSenha.Top := 140;
    end;
    Form1.PanelSenha.Show;
    Form1.LabelMenuDSErro.Hide;
    Form1.PanelSenha.BringToFront;
    Form1.PanelMenu.Show;
    ESTADIGITANDOSENHA := 2;
  end;
end;

{ JUKELINUX1_TFORM1_$__LABELERRO1CLICK$TOBJECT }
procedure TForm1.LabelErro1Click(Sender: TObject);
begin
  Self.Close;
end;

{ JUKELINUX1_TFORM1_$__LABELERRO2CLICK$TOBJECT }
procedure TForm1.LabelErro2Click(Sender: TObject);
begin
  Self.Close;
end;

{ JUKELINUX1_TFORM1_$__LABELMENUSENHASAIRCLICK$TOBJECT }
procedure TForm1.LabelMenuSenhaSairClick(Sender: TObject);
begin
  ESTADIGITANDOSENHA := 2;
  Rotina_Menu;
end;

{ JUKELINUX1_TFORM1_$__LABELRITMO1CLICK$TOBJECT }
procedure TForm1.LabelRitmo1Click(Sender: TObject);
begin
  Rotina_Ritmos;
end;

{ JUKELINUX1_TFORM1_$__LABELSAIRDOMENU1CLICK$TOBJECT }
procedure TForm1.LabelSairDoMenu1Click(Sender: TObject);
begin
  ESTADIGITANDOSENHA := 2;
  Rotina_Menu;
end;

{ JUKELINUX1_TFORM1_$__LABELSAIRDOMENU2CLICK$TOBJECT }
procedure TForm1.LabelSairDoMenu2Click(Sender: TObject);
begin
  ESTADIGITANDOSENHA := 2;
  Rotina_Menu;
end;

{ JUKELINUX1_TFORM1_$__LABELSAIRDOMENU3CLICK$TOBJECT }
procedure TForm1.LabelSairDoMenu3Click(Sender: TObject);
begin
  ESTADIGITANDOSENHA := 2;
  Rotina_Menu;
end;

{ JUKELINUX1_TFORM1_$__LABELSAIRDOMENU4CLICK$TOBJECT }
procedure TForm1.LabelSairDoMenu4Click(Sender: TObject);
begin
  ESTADIGITANDOSENHA := 2;
  Rotina_Menu;
end;

{ JUKELINUX1_TFORM1_$__LABELSAIRDOMENU5CLICK$TOBJECT }
procedure TForm1.LabelSairDoMenu5Click(Sender: TObject);
begin
  ESTADIGITANDOSENHA := 2;
  Rotina_Menu;
end;

{ JUKELINUX1_TFORM1_$__LABELVERSAOCLICK$TOBJECT }
procedure TForm1.LabelversaoClick(Sender: TObject);
begin
  Self.Close;
end;

{ JUKELINUX1_TFORM1_$__LISTBOXRCDSCLICK$TOBJECT }
procedure TForm1.ListBoxRCdsClick(Sender: TObject);
var
  local_14, local_40, local_44: AnsiString;
  cVar1: Boolean;
  iVar3, iVar4, local_10, uVar5: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ListBoxRCds + 0x364) + 0x80)) (Form1.ListBoxRCds.Items);
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        // C: cVar1 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN (Form1.ListBoxRCds,local_10);
        if cVar1 then begin
          // C: piVar6 = &local_14;
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRCds + 0x364) + 0x78)) (Form1.ListBoxRCds.Items,local_10,local_40,piVar6);
          // C: uVar5 = 0;
          if local_40 <> '' then begin
            // C: uVar5 = *(undefined4 * )(local_40[0] + -4);
          end;
          local_40 := Form1.ListBoxRCds.Items[local_10];
          // C: fpc_ansistr_copy(local_40[0],10,uVar5,piVar6);
        end;
      until not (local_10 < iVar3 + -1);
    end;
    iVar3 := TOTALCDS;
    if local_14 <> '' then begin
      local_10 := 1;
      if 0 < TOTALCDS then begin
        repeat
          local_10 := local_10 + 1;
          // C: iVar4 = fpc_ansistr_compare_equal ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x1fc), local_14);
          if iVar4 = 0 then begin
            // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x204));
            if not cVar1 then begin
              CDSELEAPAGAR := '';
            end
            else begin
              // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageCapaMT.Picture, *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x204));
              Form1.ImageCapaMT.Show;
              Form1.CapaMT.Show;
              Form1.LabelCDMt.Show;
              Form1.ImgLanMT.Hide;
              if False { C: STREQ(local_10 * 0x240 + 0x8e9133e,"S") } then begin
                Form1.ImgLanMT.Show;
              end;
              // ?: BAIRROSTR + local_10 * 144 := local_40;
              local_44 := 'De: ' + local_40;
              Form1.LabelCDMt.Caption := local_44;
              iVar4 := local_10 * 576;
              // C: U_JUKELINUX1_CDSELEAPAGAR = *(undefined4 * )(U_JUKELINUX1_ARQLOG + iVar4 + 0x1f8);
              CDSELEAPAGARX := local_14;
            end;
          end;
        until not (local_10 < iVar3);
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__LISTBOXRGENEROSCLICK$TOBJECT }
procedure TForm1.ListBoxRGenerosClick(Sender: TObject);
var
  local_14, local_40, local_48, local_50, local_54, local_58: AnsiString;
  cVar1: Boolean;
  iVar3, iVar4, local_10: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_44, local_4c: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: iVar3 = ( **(code ** )( **(int ** )(Form1.ListBoxRGeneros + 0x364) + 0x80)) (Form1.ListBoxRGeneros.Items);
    if -1 < iVar3 + -1 then begin
      local_10 := -1;
      repeat
        local_10 := local_10 + 1;
        // C: cVar1 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN (Form1.ListBoxRGeneros,local_10);
        if cVar1 then begin
          // C: piVar5 = &local_14;
          // C: ( **(code ** )( **(int ** )(Form1.ListBoxRGeneros + 0x364) + 0x78)) (Form1.ListBoxRGeneros.Items,local_10,local_40,piVar5);
          // C: iVar4 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT(0x28,local_40[0]);
          local_40 := Form1.ListBoxRGeneros.Items[local_10];
          // C: fpc_ansistr_copy(local_40[0],1,iVar4 + -2,piVar5);
        end;
      until not (local_10 < iVar3 + -1);
    end;
    if local_14 <> '' then begin
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x858) + 0x480))(Form1.ListBoxRCds);
      iVar3 := TOTALCDS;
      local_10 := 1;
      if 0 < TOTALCDS then begin
        repeat
          local_10 := local_10 + 1;
          // C: fpc_shortstr_to_ansistr(local_10 * 0x240 + 0x8e91128,local_40);
          if local_40 = local_14 then begin
            iVar4 := Pos('50+TOCADOS', local_14);
            if iVar4 = 0 then begin
              local_50 := '(';
              // C: SYSUTILS_INTTOSTR_LONGINT__ANSISTRING ((&U_JUKELINUX1_SELOSSTR)[local_10 * 0x90],&local_58);
              local_54 := Strzero(local_58, 4);
              local_4c := local_54;
              local_48 := ') - ';
              // C: local_44 = *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x1fc);
              local_40 := local_50 + local_4c + local_48 + local_44;
              // C: ( **(code ** )( **(int ** )(Form1.ListBoxRCds + 0x364) + 0xa4)) (Form1.ListBoxRCds.Items,local_40[0]);
            end
            else begin
              // C: fpc_ansistr_concat(&local_58,"(----) - ", *(undefined4 * )(U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x1fc));
              // C: ( **(code ** )( **(int ** )(Form1.ListBoxRCds + 0x364) + 0xa4)) (Form1.ListBoxRCds.Items,local_58);
            end;
          end;
        until not (local_10 < iVar3);
      end;
    end;
    Form1.ImageCapaMT.Hide;
    Form1.ImgLanMT.Hide;
    Form1.CapaMT.Hide;
    Form1.LabelCDMt.Hide;
  end;
end;

{ JUKELINUX1_TFORM1_$__MEMOERROCLICK$TOBJECT }
procedure TForm1.MemoErroClick(Sender: TObject);
begin
  Self.Close;
end;

{ JUKELINUX1_TFORM1_$__MUSICA10CLICK$TOBJECT }
procedure TForm1.Musica10Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica10,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 10;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA11CLICK$TOBJECT }
procedure TForm1.Musica11Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica11,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 11;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA12CLICK$TOBJECT }
procedure TForm1.Musica12Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica12,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 12;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA1CLICK$TOBJECT }
procedure TForm1.Musica1Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica1,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADA := MUSICASELECIONADATS + 1;
    MUSICASELECIONADAPOSTELA := 1;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA2CLICK$TOBJECT }
procedure TForm1.Musica2Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica2,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 2;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA3CLICK$TOBJECT }
procedure TForm1.Musica3Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica3,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 3;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA4CLICK$TOBJECT }
procedure TForm1.Musica4Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica4,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 4;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA5CLICK$TOBJECT }
procedure TForm1.Musica5Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica5,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 5;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA6CLICK$TOBJECT }
procedure TForm1.Musica6Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica6,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 6;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA7CLICK$TOBJECT }
procedure TForm1.Musica7Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica7,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 7;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA8CLICK$TOBJECT }
procedure TForm1.Musica8Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica8,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 8;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__MUSICA9CLICK$TOBJECT }
procedure TForm1.Musica9Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Desselecionamusica;
    // C: iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    KTS := 1;
    if 0 < iVar1 then begin
      KTS := 0;
      repeat
        KTS := KTS + 1;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.Musica9,local_38);
        // C: iVar3 = fpc_ansistr_compare_equal ( *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_KTS * 4), local_38[0]);
        if iVar3 = 0 then begin
          MUSICASELECIONADA := KTS;
        end;
      until not (KTS < iVar1);
    end;
    local_38 := IntToStr(MUSICASELECIONADA);
    Form1.Label10.Caption := local_38;
    MUSICASELECIONADAPOSTELA := 9;
    Selecionamusica;
  end;
end;

{ JUKELINUX1_TFORM1_$__PANELABERTURACLICK$TOBJECT }
procedure TForm1.PanelaberturaClick(Sender: TObject);
begin
  Self.Close;
end;

{ JUKELINUX1_TFORM1_$__PANELBLOQUEIOCLICK$TOBJECT }
procedure TForm1.PanelBloqueioClick(Sender: TObject);
begin
  Rotina_Menu;
end;

{ JUKELINUX1_TFORM1_$__PANELCOTESTECLICK$TOBJECT }
procedure TForm1.PanelCOTesteClick(Sender: TObject);
begin
  Form1.PanelCadastro.Hide;
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbc8) + 0xd8)) (Form1.TimerCadastro,extraout_EDX & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xbc8), Self,Sender);
  ALTERANDOFRASES := 0;
  // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x430))(U_JUKELINUX1_FORM1);
end;

{ JUKELINUX1_TFORM1_$__PANELERROCLICK$TOBJECT }
procedure TForm1.PanelErroClick(Sender: TObject);
begin
  Self.Close;
end;

{ JUKELINUX1_TFORM1_$__PANELMENU1CLICK$TOBJECT }
procedure TForm1.PanelMenu1Click(Sender: TObject);
begin
  if SENHAOK = 2 then begin
    Voltamenu;
    Form1.PanelMenu1c.Show;
    Form1.PanelMenu1grande.Show;
    Form1.LabelSairDoMenu1.Show;
  end;
end;

{ JUKELINUX1_TFORM1_$__PANELMENU2CLICK$TOBJECT }
procedure TForm1.PanelMenu2Click(Sender: TObject);
var
  local_180, local_184, local_188, local_194, local_198, local_1a8, local_1ac, local_1b0, local_1b8, local_1bc, local_2b0, local_2b4, local_38, local_40, local_48, local_4c, local_58, local_60, local_64, local_70, local_78, local_7c, local_80, local_88, local_94, uVar4: AnsiString;
  cVar1: Boolean;
  iVar3, local_3c, local_6c: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_18c, local_190, local_19c, local_1a0, local_1a4, local_1b4, local_44, local_50, local_54, local_5c, local_74, local_84, local_8c, local_90: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    if SENHAOK = 1 then begin
      Form1.ButtonQR.Hide;
      Form1.ButtonZRP.Hide;
      Voltamenu;
      local_38 := IntToStr(MINUTOSLIGADA);
      MINUTOSLIGADASTR := local_38;
      local_3c := StrToIntDef(MINUTOSLIGADASTR, 0);
      // C: SYSUTILS_FLOATTOSTR_EXTENDED__ANSISTRING(local_38);
      MINUTOSLIGADASTR := local_38;
      // C: uVar4 = SUB42(local_38,0);
      // C: iVar3 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT (CONCAT31((int3)((uint)local_38 >> 8),0x2e),U_JUKELINUX1_MINUTOSLIGADASTR);
      uVar4 := Copy(MINUTOSLIGADASTR, 1, iVar3 + 2);
      MINUTOSLIGADASTR := local_38;
      local_4c := 'Relógio Total...: R$ ';
      local_38 := IntToStr(RELOGIOTOTAL);
      local_48 := local_38;
      local_44 := ',00';
      local_40 := local_4c + local_48 + local_44;
      Form1.LabelRT.Caption := local_40;
      local_60 := 'Relógio Parcial: R$ ';
      local_64 := IntToStr(RELOGIOPARCIAL);
      local_5c := local_64;
      // C: local_58 = ",00  [";
      local_54 := MINUTOSLIGADASTR;
      local_50 := 'hs Ligada]';
      local_40 := local_60 + local_5c + local_58 + local_54 + local_50;
      Form1.LabelRP.Caption := local_40;
      local_64 := IntToStr(PORCENTAGEMDOPONTO);
      local_40 := '% do  Ponto: ' + local_64;
      Form1.LabelPor.Caption := local_40;
      // ?: local_6c := (longlong) ROUND((float10)PORCENTAGEMDOPONTO * ((float10)RELOGIOPARCIAL div ''));
      // C: U_JUKELINUX1_VALORPONTO = (int)local_6c;
      local_4c := 'Valor do Ponto..: R$ ';
      local_64 := IntToStr(VALORPONTO);
      local_48 := local_64;
      local_44 := ',00';
      local_40 := local_4c + local_48 + local_44;
      Form1.LabelVP.Caption := local_40;
      local_7c := 'Valor da Empresa: R$ ';
      local_64 := IntToStr(RELOGIOPARCIAL - VALORPONTO);
      local_78 := local_64;
      local_74 := ',00';
      local_70 := local_7c + local_78 + local_74;
      Form1.LabelVE.Caption := local_70;
      local_80 := PASTA + 'ultimofechamento.txt';
      cVar1 := FileExists(local_80);
      if not cVar1 then begin
        Form1.LabelUF1.Caption := 'Não Existe o Arquivo de Último Fechamento:';
        Form1.LabelUF2.Caption := '';
      end
      else begin
        local_80 := PASTA + 'ultimofechamento.txt';
        local_180 := local_80;
        AssignFile(ARQTEXTO, local_180);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_7c := 'Relógio Parcial do Último Fechamento: R$ ';
        local_78 := TEXTO;
        local_74 := ',00';
        local_70 := local_7c + local_78 + local_74;
        Form1.LabelUF1.Caption := local_70;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_70 := TEXTO + ' - ';
        Form1.LabelUF2.Caption := local_70;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelUF2,&local_80);
        local_7c := local_80;
        local_78 := TEXTO;
        local_74 := ' - ';
        local_70 := local_7c + local_78 + local_74;
        Form1.LabelUF2.Caption := local_70;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelUF2,&local_80);
        local_8c := local_80;
        local_88 := TEXTO;
        local_84 := '% - ';
        local_184 := local_8c + local_88 + local_84;
        Form1.LabelUF2.Caption := local_184;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        // C: local_84 = (char * )SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT(U_JUKELINUX1_TEXTO,0);
        // C: SYSUTILS_FLOATTOSTR_EXTENDED__ANSISTRING(&local_80);
        TEXTO := local_80;
        // C: uVar4 = SUB42(&local_80,0);
        // C: iVar3 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT (CONCAT31((int3)((uint)&local_80 >> 8),0x2e),U_JUKELINUX1_TEXTO);
        uVar4 := Copy(TEXTO, 1, iVar3 + 2);
        TEXTO := local_80;
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelUF2,&local_80);
        local_8c := local_80;
        local_88 := TEXTO;
        local_84 := 'hs Ligada';
        local_184 := local_8c + local_88 + local_84;
        Form1.LabelUF2.Caption := local_184;
        CloseFile(ARQTEXTO);
      end;
      if RESOLUCAO = 1024 then begin
        // C: CONTROLS_TCONTROL____SETLEFT_LONGINT(Form1.ImageQrcode,0x1b8);
      end;
      if RESOLUCAO = 1366 then begin
        // C: CONTROLS_TCONTROL____SETLEFT_LONGINT(Form1.ImageQrcode,0x2ee);
      end;
      if RESOLUCAO = 1440 then begin
        // C: CONTROLS_TCONTROL____SETLEFT_LONGINT(Form1.ImageQrcode,0x2ee);
      end;
      // C: CONTROLS_TCONTROL____SETTOP_LONGINT(Form1.ImageQrcode,0x15e);
      Form1.PanelMenu2c.Show;
      Form1.PanelMenu2grande.Show;
      if RESOLUCAO = 1024 then begin
        Form1.LabelRT.Font.Size := 18;
        Form1.LabelRP.Font.Size := 18;
        Form1.LabelVE.Font.Size := 18;
        Form1.LabelVP.Font.Size := 34;
        Form1.LabelPress.Font.Size := 10;
        Form1.LabelPress1.Font.Size := 10;
        Form1.LabelPress2.Font.Size := 10;
        Form1.LabelPress3.Font.Size := 10;
        Form1.LabelUF1.Font.Size := 10;
        Form1.LabelUF2.Font.Size := 10;
        Form1.LabelPress2.Width := 390;
      end;
      if RESOLUCAO = 1366 then begin
        Form1.LabelRT.Font.Size := 24;
        Form1.LabelRP.Font.Size := 24;
        Form1.LabelVE.Font.Size := 24;
        Form1.LabelVP.Font.Size := 42;
        Form1.LabelPress.Font.Size := 14;
        Form1.LabelPress1.Font.Size := 14;
        Form1.LabelPress2.Font.Size := 14;
        Form1.LabelPress3.Font.Size := 14;
        Form1.LabelUF1.Font.Size := 14;
        Form1.LabelUF2.Font.Size := 14;
        Form1.LabelPress2.Width := 647;
      end;
      if RESOLUCAO = 1440 then begin
        Form1.LabelRT.Font.Size := 24;
        Form1.LabelRP.Font.Size := 24;
        Form1.LabelVE.Font.Size := 24;
        Form1.LabelVP.Font.Size := 42;
        Form1.LabelPress.Font.Size := 14;
        Form1.LabelPress1.Font.Size := 14;
        Form1.LabelPress2.Font.Size := 14;
        Form1.LabelPress3.Font.Size := 14;
        Form1.LabelUF1.Font.Size := 14;
        Form1.LabelUF2.Font.Size := 14;
        Form1.LabelPress2.Width := 647;
      end;
      if (0 < QTDCREDITOSGRATIS) and (0 < QTDCREDITOSGRATISVIP) then begin
        local_94 := 'Pressione o Botão GÊNERO para deixar ';
        local_80 := IntToStr(QTDCREDITOSGRATIS);
        local_90 := local_80;
        local_8c := ' Créditos Grátis + ';
        local_188 := IntToStr(QTDCREDITOSGRATISVIP);
        local_88 := local_188;
        local_84 := ' VIPs';
        local_184 := local_94 + local_90 + local_8c + local_88 + local_84;
        Form1.LabelPress2.Caption := local_184;
      end;
      if (0 < QTDCREDITOSGRATIS) and (QTDCREDITOSGRATISVIP = 0) then begin
        local_194 := 'Pressione o Botão GÊNERO para deixar ';
        local_188 := IntToStr(QTDCREDITOSGRATIS);
        local_190 := local_188;
        local_18c := ' Créditos Grátis';
        local_184 := local_194 + local_190 + local_18c;
        Form1.LabelPress2.Caption := local_184;
      end;
      if (QTDCREDITOSGRATIS = 0) and (0 < QTDCREDITOSGRATISVIP) then begin
        local_194 := 'Pressione o Botão GÊNERO para deixar ';
        local_188 := IntToStr(QTDCREDITOSGRATIS);
        local_190 := local_188;
        local_18c := ' Créditos Grátis VIP';
        local_184 := local_194 + local_190 + local_18c;
        Form1.LabelPress2.Caption := local_184;
      end;
      if (QTDCREDITOSGRATIS = 0) and (QTDCREDITOSGRATISVIP = 0) then begin
        Form1.LabelPress2.Caption := '';
      end;
      Form1.LabelEntrarNoMenu.Top := Form1.LabelSairDoMenu2.Top + 40;
      Form1.LabelEntrarNoMenu.Left := Form1.LabelSairDoMenu2.Left;
      Form1.LabelEntrarNoMenu.Width := Form1.LabelSairDoMenu2.Width;
      Form1.LabelEntrarNoMenu.Show;
      Form1.LabelPress.Caption := 'Pressione o Botão OK para Zerar Relógio Parcial';
      Form1.LabelPress.Show;
      Form1.LabelPress1.Show;
      Form1.LabelPress2.Show;
      Form1.ComboBoxPorcento.Hide;
      Form1.LabelSairDoMenu2.Show;
    end;
    if SENHAOK = 2 then begin
      Form1.ButtonQR.Hide;
      Form1.ButtonZRP.Hide;
      Voltamenu;
      local_188 := IntToStr(MINUTOSLIGADA);
      MINUTOSLIGADASTR := local_188;
      // C: local_18c = (undefined * ) SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT(U_JUKELINUX1_MINUTOSLIGADASTR,0);
      // C: SYSUTILS_FLOATTOSTR_EXTENDED__ANSISTRING(&local_188);
      MINUTOSLIGADASTR := local_188;
      // C: uVar4 = SUB42(&local_188,0);
      // C: iVar3 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT (CONCAT31((int3)((uint)&local_188 >> 8),0x2e),U_JUKELINUX1_MINUTOSLIGADASTR);
      uVar4 := Copy(MINUTOSLIGADASTR, 1, iVar3 + 2);
      MINUTOSLIGADASTR := local_188;
      local_194 := 'Relógio Total...: R$ ';
      local_188 := IntToStr(RELOGIOTOTAL);
      local_190 := local_188;
      local_18c := ',00';
      local_198 := local_194 + local_190 + local_18c;
      Form1.LabelRT.Caption := local_198;
      // C: local_1ac = CONCAT44(local_1ac._4_4_,"Relógio Parcial: R$ ");
      local_188 := IntToStr(RELOGIOPARCIAL);
      // C: local_1ac = CONCAT44(local_188,(int)local_1ac);
      // C: local_1a4 = ",00  [";
      local_1a0 := MINUTOSLIGADASTR;
      local_19c := 'hs Ligada]';
      local_198 := local_1ac + local_1a8 + local_1a4 + local_1a0 + local_19c;
      Form1.LabelRP.Caption := local_198;
      // ?: local_1ac := (longlong) ROUND((float10)PORCENTAGEMDOPONTO * ((float10)RELOGIOPARCIAL div ''));
      // C: U_JUKELINUX1_VALORPONTO = (int)local_1ac;
      local_1a4 := 'Valor do Ponto..: R$ ';
      local_1b0 := IntToStr(VALORPONTO);
      local_1a0 := local_1b0;
      local_19c := ',00';
      local_198 := local_1a4 + local_1a0 + local_19c;
      Form1.LabelVP.Caption := local_198;
      local_1a4 := 'Valor da Empresa: R$ ';
      local_1b0 := IntToStr(RELOGIOPARCIAL - VALORPONTO);
      local_1a0 := local_1b0;
      local_19c := ',00';
      local_198 := local_1a4 + local_1a0 + local_19c;
      Form1.LabelVE.Caption := local_198;
      local_1b0 := PASTA + 'ultimofechamento.txt';
      cVar1 := FileExists(local_1b0);
      if not cVar1 then begin
        Form1.LabelUF1.Caption := 'Não Existe o Arquivo de Último Fechamento:';
        Form1.LabelUF2.Caption := '';
      end
      else begin
        local_1b0 := PASTA + 'ultimofechamento.txt';
        local_2b0 := local_1b0;
        AssignFile(ARQTEXTO, local_2b0);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_1bc := 'Relógio Parcial do Último Fechamento: R$ ';
        local_1b8 := TEXTO;
        local_1b4 := ',00';
        local_198 := local_1bc + local_1b8 + local_1b4;
        Form1.LabelUF1.Caption := local_198;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        local_198 := TEXTO + ' - ';
        Form1.LabelUF2.Caption := local_198;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelUF2,&local_1b0);
        local_1bc := local_1b0;
        local_1b8 := TEXTO;
        local_1b4 := ' - ';
        local_198 := local_1bc + local_1b8 + local_1b4;
        Form1.LabelUF2.Caption := local_198;
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelUF2,&local_1b0);
        local_1bc := local_1b0;
        local_1b8 := TEXTO;
        local_1b4 := '%';
        local_2b4 := local_1bc + local_1b8 + local_1b4;
        Form1.LabelUF2.Caption := local_2b4;
        CloseFile(ARQTEXTO);
      end;
      Form1.PanelMenu2c.Show;
      Form1.PanelMenu2grande.Show;
      Form1.LabelEntrarNoMenu.Hide;
      Form1.LabelPress.Hide;
      Form1.LabelPress1.Hide;
      Form1.LabelPress2.Hide;
      Form1.LabelPress3.Hide;
      Form1.ComboBoxPorcento.Show;
      Form1.ComboBoxPorcento.Visible := True;
      Form1.LabelSairDoMenu2.Show;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__PANELMENU3CLICK$TOBJECT }
procedure TForm1.PanelMenu3Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  // C: iVar1 = fpc_setjmp();
  if (iVar1 = 0) and (SENHAOK = 2) then begin
    Voltamenu;
    Form1.PanelMenu3c.Show;
    Form1.PanelMenu3grande.Show;
    Form1.PanelCarregarMusica.Hide;
    Form1.PanelCarregarMusica.Left := 20;
    Form1.PanelCarregarMusica.Top := 60;
    Form1.PanelCarregarMusica.Width := Form1.PanelMenu3grande.Width + -40;
    Form1.PanelCarregarMusica.Height := Form1.PanelMenu3grande.Height + -80;
    Le_Tocados;
    KMATEXCLUI := 1;
    Mostra_Cd_Exclusao(KMATEXCLUI);
    local_38 := Copy(ORDEMDOSCDS, 1, 1);
    if local_38 = 'R' then begin
      Form1.ButtonEO3.Caption := 'Próximo Gênero';
    end
    else begin
      Form1.ButtonEO3.Caption := 'Próxima Letra';
    end;
    Form1.PanelExcluirMusica.Hide;
    Form1.PanelCarregarMusica.Hide;
    Form1.PanelEsconderRitmos.Hide;
    Form1.PanelEsconderRitmos1.Hide;
    Form1.LabelSairDoMenu3.Show;
    Form1.ShellTreeViewCC.Hide;
    Form1.EditCC.Hide;
  end;
  if iVar1 <> 0 then begin
  end;
end;

{ JUKELINUX1_TFORM1_$__PANELMENU4CLICK$TOBJECT }
procedure TForm1.PanelMenu4Click(Sender: TObject);
begin
  if SENHAOK = 2 then begin
    Voltamenu;
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb78) + 0xd8)) (Form1.TimerConfigInterface,1,**(int ** )(U_JUKELINUX1_FORM1 + 0xb78),Self,Sender);
    Form1.PanelMenu4c.Show;
    Form1.PanelMenu4grande.Show;
    Form1.LabelSairDoMenu4.Show;
    Form1.ButtonInterface.Caption := 'Salvar Letras da Interface';
    Form1.LabelIntInfo.Caption := 'Clique no Campo e Pressione a Tecla';
  end;
end;

{ JUKELINUX1_TFORM1_$__PANELMENU5CLICK$TOBJECT }
procedure TForm1.PanelMenu5Click(Sender: TObject);
var
  local_38: AnsiString;
  iVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  // C: iVar1 = fpc_setjmp();
  if (iVar1 = 0) and (SENHAOK = 2) then begin
    Voltamenu;
    // C: CONTROLS_TCONTROL____HIDE(Form1.PanelQrcodeCadastro1);
    Form1.ButtonZerarCreditos.Caption := 'Zerar Créditos';
    Form1.ButtonXML.Caption := 'Salvar XML no Pendrive';
    Form1.PanelMenu5c.Show;
    Form1.PanelMenu5grande.Show;
    Form1.LabelSairDoMenu5.Show;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(U_JUKELINUX1_MATFRASESORI,local_38);
    Form1.EditFrase1.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301cd4,local_38);
    Form1.EditFrase2.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301cd8,local_38);
    Form1.EditFrase3.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301cdc,local_38);
    Form1.EditFrase4.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301ce0,local_38);
    Form1.EditFrase5.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301ce4,local_38);
    Form1.EditFrase6.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301ce8,local_38);
    Form1.EditFrase7.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301cec,local_38);
    Form1.EditFrase8.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301cf0,local_38);
    Form1.EditFrase9.Caption := local_38;
    // C: SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(DAT_09301cf4,local_38);
    Form1.EditFrase10.Caption := local_38;
    Form1.EditFrase1.Visible := False;
    Form1.EditFrase2.Visible := False;
    Form1.EditFrase3.Visible := False;
    Form1.EditFrase4.Visible := False;
    Form1.EditFrase5.Visible := False;
    Form1.EditFrase6.Visible := False;
    Form1.EditFrase7.Visible := False;
    Form1.EditFrase8.Visible := False;
    Form1.EditFrase9.Visible := False;
    Form1.EditFrase10.Visible := False;
    if MENUMASTER = 0 then begin
      Form1.LabelCB18.Hide;
      Form1.ComboBox18.Hide;
      Form1.LabelCB19.Hide;
      Form1.ComboBox19.Hide;
    end
    else begin
      Form1.LabelCB18.Show;
      Form1.ComboBox18.Show;
      Form1.LabelCB19.Show;
      Form1.ComboBox19.Show;
    end;
  end;
  if iVar1 <> 0 then begin
  end;
end;

{ JUKELINUX1_TFORM1_$__SHELLTREEVIEWCCCHANGE$TOBJECT$TTREENODE }
procedure TForm1.ShellTreeViewCCChange(Sender: TObject; Node: TTreeNode);
var
  local_3c, local_40: AnsiString;
  local_10: TForm1;
  local_8: TObject;
  local_c: TTreeNode;
begin
  local_10 := Self;
  local_c := Node;
  local_8 := Sender;
  begin
    // C: SHELLCTRLS_TCUSTOMSHELLTREEVIEW____GETPATH__ANSISTRING (Form1.ShellTreeViewCC,&local_40);
    local_3c := local_40 + '/';
    Form1.EditCC.Caption := local_3c;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMER1MINUTOTIMER$TOBJECT }
procedure TForm1.Timer1MinutoTimer(Sender: TObject);
begin
  KTEMPOMG := KTEMPOMG + 1;
  if TEMPOTOCARMG = KTEMPOMG then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb40) + 0xd8)) (Form1.Timer1Minuto,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xb40), Self,Sender);
    if (TOCANDOMUSICA <> 0) and (TOCANDOMUSICAGRATIS <> 0) then begin
      Rotina_Cancelar;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMER1TIMER$TOBJECT }
procedure TForm1.Timer1Timer(Sender: TObject);
begin

end;

{ JUKELINUX1_TFORM1_$__TIMERABERTURATIMER$TOBJECT }
procedure TForm1.TimeraberturaTimer(Sender: TObject);
var
  local_38: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    TEMPOABERTURA := TEMPOABERTURA + -1;
    local_38 := IntToStr(TEMPOABERTURA);
    Form1.Labelaberturatempo.Caption := local_38;
    if TEMPOABERTURA = 0 then begin
      Form1.Timerabertura.Enabled := False;
      Form1.Panelabertura.Hide;
      Inicia_Tela;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERACIONAVOLUMETIMER$TOBJECT }
procedure TForm1.TimerAcionaVolumeTimer(Sender: TObject);
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb74) + 0xd8)) (Form1.TimerAcionaVolume,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xb74), Self,Sender);
  TEMPOPARAAUMENTARVOLUME := 0;
end;

{ JUKELINUX1_TFORM1_$__TIMERCADASTROTIMER$TOBJECT }
procedure TForm1.TimerCadastroTimer(Sender: TObject);
var
  local_158, local_1c, local_20, local_28, local_58, local_68: AnsiString;
  cVar1: Boolean;
  iVar3, local_10, local_14, local_2c: LongInt;
  local_c: TForm1;
  local_8: TObject;
  local_24, local_5c, local_60, local_64: Variant;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    local_58 := PASTACHAVE + 'jukebox.cadastro';
    cVar1 := FileExists(local_58);
    if cVar1 then begin
      local_58 := PASTACHAVE + 'jukebox.cadastro';
      local_158 := local_58;
      AssignFile(ARQTEXTO, local_158);
      Reset(ARQTEXTO);
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasuper2(TEXTO);
      local_24 := TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      JC_CODIGODAMAQUINA := local_28;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasimples(TEXTO);
      local_24 := local_24 + TEXTO;
      local_20 := local_28;
      Read(ARQTEXTO, TEXTO);
      Readln(ARQTEXTO);
      local_28 := Descriptasuper2(TEXTO);
      // C: local_1c[0] = local_28;
      CloseFile(ARQTEXTO);
      iVar3 := 0;
      if local_24 <> 0 then begin
        // C: iVar3 = *(int * )(local_24 + -4);
      end;
      local_14 := 1;
      if 0 < iVar3 then begin
        repeat
          local_14 := local_14 + 1;
          // C: local_10 = (uint)*(byte * )(local_24 + -1 + local_14) + local_10;
        until not (local_14 < iVar3);
      end;
      local_58 := IntToStr(local_10);
      local_24 := local_58;
      if local_58 = local_1c then begin
        if local_20 = 'novo' then begin
          local_2c := 1;
        end
        else begin
          local_2c := 0;
          if local_20 = 'zerado' then begin
            local_2c := 1;
          end;
        end;
        if local_2c = 0 then begin
          Le_Arquivo_De_Cadastro;
          Form1.TimerCadastro.Enabled := False;
        end
        else begin
          ALTERANDOFRASES := 1;
          Form1.TimerCadastro.Enabled := False;
          Form1.PanelCadastro.Align := alClient;
          Form1.PanelCadastro.BringToFront;
          Form1.PanelCadastro.Show;
          // C: CONTROLS_TCONTROL____HIDE(Form1.PanelQrcodeCadastro);
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9b4) + 0x430))(Form1.CodigodaMaquina);
          Form1.CodigodaMaquina.Visible := True;
          if JC_CODIGODAMAQUINA <> '0' then begin
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb04) + 0x430))(Form1.NomeDoPonto);
            Form1.CodigodaMaquina.Caption := JC_CODIGODAMAQUINA;
            Form1.CodigodaMaquina.Visible := False;
          end;
        end;
      end
      else begin
        local_68 := 'Serial do PenDrive Nao Confere com o Serial do Arquivo "jukebox.cadastro"'#13'';
        local_64 := local_24;
        local_60 := ' <> ';
        local_5c := local_1c;
        local_58 := local_68 + local_64 + local_60 + local_5c;
        Gravalog(local_58);
        Form1.TimerCadastro.Enabled := False;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERCEDULASTIMER$TOBJECT }
procedure TForm1.TimerCedulasTimer(Sender: TObject);
var
  local_134, local_138, local_13c, local_144, local_148: AnsiString;
  local_140, uVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Form1.TimerCedulas.Enabled := False;
    if CREDITOSCEDULAS = 1 then begin
      CREDITOSCEDULAS := 0;
    end;
    if CREDITOSCEDULAS = 2 then begin
      CREDITOS := CREDITOS + 1;
    end;
    if CREDITOSCEDULAS = 5 then begin
      CREDITOS := CREDITOS + 5;
    end;
    if CREDITOSCEDULAS = 10 then begin
      CREDITOS := CREDITOS + 10;
    end;
    if CREDITOSCEDULAS = 20 then begin
      CREDITOS := CREDITOS + 20;
    end;
    if CREDITOSCEDULAS = 50 then begin
      CREDITOS := CREDITOS + 50;
    end;
    if CREDITOSCEDULAS = 100 then begin
      CREDITOS := CREDITOS + 100;
    end;
    if CREDITOSCEDULAS <> 1 then begin
      CREDITOSCEDULAS := 0;
      NOMEARQ := PASTA + 'creditos.txt';
      local_134 := NOMEARQ;
      AssignFile(ARQTEXTO, local_134);
      Rewrite(ARQTEXTO);
      local_13c := IntToStr(CREDITOS);
      local_138 := Cripta(local_13c);
      Write(ARQTEXTO, local_138);
      Writeln(ARQTEXTO);
      local_13c := Cripta(JC_SERIALPENDRIVE);
      Write(ARQTEXTO, local_13c);
      Writeln(ARQTEXTO);
      Flush(ARQTEXTO);
      CloseFile(ARQTEXTO);
      if SEMPENDRIVE = 0 then begin
        local_138 := PASTACHAVE + 'creditos.txt';
        // C: puVar3 = local_138;
        if False { C: local_138 == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar3,&local_13c);
        // C: uVar1 = local_13c;
        local_144 := PASTA + 'creditos.txt';
        // C: puVar3 = local_144;
        if False { C: local_144 == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar3,&local_140);
        // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_140,uVar1,extraout_ECX & 0xffffff00);
      end;
      local_148 := IntToStr(CREDITOS);
      Form1.LabelCreditos.Caption := local_148;
      Form1.LabelCreditos.Font.Color := 65280;
      Form1.TimerPiscaCreditos.Enabled := False;
      Form1.TimerPiscaCreditos.Enabled := True;
      MOSTRANDOCREDITO := 1;
      Form1.TimerGravaPenDrive.Enabled := False;
      Form1.TimerGravaPenDrive.Enabled := True;
      JAGRAVOUNOPENDRIVE := 1;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERCONFIGINTERFACETIMER$TOBJECT }
procedure TForm1.TimerConfigInterfaceTimer(Sender: TObject);
var
  iVar1, uVar2: LongInt;
begin
  // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FUNCAOTECLA,"ritmo",param_3,Self,Sender);
  // C: uVar2 = extraout_ECX;
  if iVar1 = 0 then begin
    Form1.EditRitmo.Caption := TEMPTECLA;
    // C: uVar2 = extraout_ECX_00;
  end;
  // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FUNCAOTECLA,"musica+",uVar2,Self,Sender);
  // C: uVar2 = extraout_ECX_01;
  if iVar1 = 0 then begin
    Form1.EditMusicaMais.Caption := TEMPTECLA;
    // C: uVar2 = extraout_ECX_02;
  end;
  // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_FUNCAOTECLA,"musica-",uVar2,Self,Sender);
  if iVar1 = 0 then begin
    Form1.EditMusicaMenos.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'tocar' then begin
    Form1.EditTocar.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'cd-' then begin
    Form1.EditCDMenos.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'cd+' then begin
    Form1.EditCDMais.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'cancelar' then begin
    Form1.EditCancelar.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'credito' then begin
    Form1.EditCredito.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'cr+' then begin
    Form1.EditCRMais.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'cr-' then begin
    Form1.EditCRMenos.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'menu' then begin
    Form1.EditMenuTecla.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'VIP' then begin
    Form1.EditCreditoVIP.Caption := TEMPTECLA;
  end;
  if FUNCAOTECLA = 'credito2' then begin
    Form1.EditCredito2.Caption := TEMPTECLA;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERDESATIVAVOLUMETIMER$TOBJECT }
procedure TForm1.TimerDesativaVolumeTimer(Sender: TObject);
begin
  Desativa_Volume_Pelo_Painel;
end;

{ JUKELINUX1_TFORM1_$__TIMERESCONDEMSGTIMER$TOBJECT }
procedure TForm1.TimerEscondeMsgTimer(Sender: TObject);
begin
  // C: uVar1 = Sender;
  if MOSTRANDOSETABAIXO = -1 then begin
    Form1.SetaBaixo.Show;
    MOSTRANDOSETABAIXO := 1;
    // C: Sender = extraout_EDX;
  end;
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xba0) + 0xd8)) (Form1.TimerEscondeMsg,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xba0), Self,uVar1);
  Form1.Imagemsg.Hide;
  Form1.LabelMsg1.Hide;
  Form1.ImageSetaMsg.Hide;
  Form1.CDSelecionadoMsg.Hide;
  Form1.CapaSelecionadaMsg.Hide;
end;

{ JUKELINUX1_TFORM1_$__TIMERFRASESTIMER$TOBJECT }
procedure TForm1.TimerFrasesTimer(Sender: TObject);
var
  local_38: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    POSFRASE := POSFRASE + 1;
    if TOTALFRASE < POSFRASE then begin
      POSFRASE := 1;
    end;
    // C: fpc_ansistr_concat(local_38,"          ", *(undefined4 * )(U_JUKELINUX1_ARQTOCARX + U_JUKELINUX1_POSFRASE * 4 + 0x24c));
    Form1.LabelDisplay.Caption := local_38;
    Form1.TimerFrases.Enabled := False;
    Form1.TimerRodaDisplay.Enabled := True;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERGRAVAPENDRIVETIMER$TOBJECT }
procedure TForm1.TimerGravaPenDriveTimer(Sender: TObject);
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbb4) + 0xdc)) (Form1.TimerGravaPenDrive,3000,**(int ** )(U_JUKELINUX1_FORM1 + 0xbb4),Self,Sender);
  Grava_Pendrive_Contadores;
  Form1.TimerGravaPenDrive.Enabled := False;
end;

{ JUKELINUX1_TFORM1_$__TIMERMOSTRANOMEDEMUSICASTIMER$TOBJECT }
procedure TForm1.TimerMostraNomeDeMusicasTimer(Sender: TObject);
begin
  // C: uVar1 = Sender;
  if MOSTRANDOLETRANAPAGINACAO <> 0 then begin
    Mostra_Nome_Das_Musicas;
    Form1.ImageSetasPaginacao1.Hide;
    // C: uVar1 = Sender;
    Form1.ImageSetasPaginacao2.Hide;
    // C: Sender = extraout_EDX;
  end;
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbc0) + 0xd8)) (Form1.TimerMostraNomeDeMusicas,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xbc0), Self,uVar1);
end;

{ JUKELINUX1_TFORM1_$__TIMERMUSICAGRATISTIMER$TOBJECT }
procedure TForm1.TimerMusicaGratisTimer(Sender: TObject);
var
  local_138, local_13c, local_140, local_144, local_148, local_150, local_38: AnsiString;
  cVar2: Boolean;
  local_14c, uVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    if MUSICAGRATIS = 'Sem Musica Gratis' then begin
      Form1.TimerMusicaGratis.Enabled := False;
      MUSICAGRATISNUM := 0;
    end;
    TEMPOTOCARMG := 0;
    if MUSICAGRATIS = 'Continua' then begin
      MUSICAGRATISNUM := 1;
    end;
    if MUSICAGRATIS = '01 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 1;
    end;
    if MUSICAGRATIS = '02 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 2;
    end;
    if MUSICAGRATIS = '03 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 3;
    end;
    if MUSICAGRATIS = '04 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 3;
    end;
    if MUSICAGRATIS = '05 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 5;
    end;
    if MUSICAGRATIS = '10 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 10;
    end;
    if MUSICAGRATIS = '15 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 15;
    end;
    if MUSICAGRATIS = '20 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 20;
    end;
    if MUSICAGRATIS = '25 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 25;
    end;
    if MUSICAGRATIS = '30 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 30;
    end;
    if MUSICAGRATIS = '45 Minutos / Inteira' then begin
      MUSICAGRATISNUM := 45;
    end;
    if MUSICAGRATIS = '01 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 1;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '02 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 2;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '03 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 3;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '04 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 4;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '05 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 5;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '10 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 10;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '15 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 15;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '20 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 20;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '25 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 25;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '30 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 30;
      TEMPOTOCARMG := 60;
    end;
    if MUSICAGRATIS = '45 Minutos / 1 Minuto' then begin
      MUSICAGRATISNUM := 45;
      TEMPOTOCARMG := 60;
    end;
    if -1 < TEMPOEMSEGUNDOS then begin
      TEMPOEMSEGUNDOS := TEMPOEMSEGUNDOS + 1;
    end;
    if ((TEMPOEMSEGUNDOS <> -1) and (TOCANDOMUSICA = 0)) and (SELECIONADAS = 0) then begin
      if MUSICAGRATIS = 'Continua' then begin
        TEMPOEMSEGUNDOS := MUSICAGRATISNUM * 60;
      end;
    end;
    if 0 < SELECIONADAS then begin
      TEMPOEMSEGUNDOS := 0;
    end;
    if TOCANDOMUSICA <> 0 then begin
      TEMPOEMSEGUNDOS := 0;
    end;
    if TEMPOEMSEGUNDOS div 60 = MUSICAGRATISNUM then begin
      TEMPOEMSEGUNDOS := -1;
      if SELECAOMG = 'Aleatoria' then begin
        Randomize;
        CDGRATIS := Random(TOTALCDS + -1);
        if CDGRATIS = 0 then begin
          CDGRATIS := 1;
        end;
        Randomize;
        // C: U_JUKELINUX1_FAIXAGRATIS = SYSTEM_RANDOM_LONGINT__LONGINT ((&U_JUKELINUX1_NOMEDOCLIENTE)[U_JUKELINUX1_CDGRATIS * 0x90]);
        if FAIXAGRATIS = 0 then begin
          FAIXAGRATIS := 1;
        end;
        local_38 := PASTA + 'tocar.txt';
        cVar2 := FileExists(local_38);
        if cVar2 then begin
          // C: fpc_ansistr_concat(local_38,"Musica Gratis ", *(undefined4 * ) (U_JUKELINUX1_CDGRATIS * 0x240 + 0x8e91144 + U_JUKELINUX1_FAIXAGRATIS * 4));
          Gravalog(local_38);
          // C: cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * ) (U_JUKELINUX1_CDGRATIS * 0x240 + 0x8e91144 + U_JUKELINUX1_FAIXAGRATIS * 4));
          if cVar2 then begin
            local_38 := PASTA + 'tocar.txt';
            local_138 := local_38;
            AssignFile(ARQTOCAR, local_138);
            Append(ARQTOCAR);
            // C: fpc_ansistr_concat(local_38,"*", *(undefined4 * ) (U_JUKELINUX1_CDGRATIS * 0x240 + 0x8e91144 + U_JUKELINUX1_FAIXAGRATIS * 4));
            Write(ARQTOCAR, local_38);
            Writeln(ARQTOCAR);
            Flush(ARQTOCAR);
            CloseFile(ARQTOCAR);
            if SEMPENDRIVE = 0 then begin
              local_13c := PASTACHAVE + 'tocar.txt';
              // C: puVar5 = local_13c;
              if False { C: local_13c == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar5,local_38);
              // C: uVar1 = local_38[0];
              local_144 := PASTA + 'tocar.txt';
              // C: puVar5 = local_144;
              if False { C: local_144 == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar5,&local_140);
              // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_140,uVar1,extraout_ECX & 0xffffff00);
            end;
          end;
        end;
      end;
      if SELECAOMG = '50 Musicas +Tocadas' then begin
        POSMG := POSMG + 1;
        if TOTALMG < POSMG then begin
          POSMG := 1;
        end;
        local_140 := PASTA + 'inciarpela50maistocada.txt';
        local_138 := local_140;
        AssignFile(ARQTEXTO, local_138);
        Rewrite(ARQTEXTO);
        local_140 := IntToStr(POSMG);
        Write(ARQTEXTO, local_140);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_140 := PASTA + 'tocar.txt';
        cVar2 := FileExists(local_140);
        if cVar2 then begin
          // C: fpc_ansistr_concat(&local_140,"Musica Gratis ", *(undefined4 * )(&DAT_0964721c + U_JUKELINUX1_POSMG * 4));
          Gravalog(local_140);
          // C: cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ( *(undefined4 * )(&DAT_0964721c + U_JUKELINUX1_POSMG * 4));
          if cVar2 then begin
            local_140 := PASTA + 'tocar.txt';
            local_138 := local_140;
            AssignFile(ARQTOCAR, local_138);
            Append(ARQTOCAR);
            // C: fpc_ansistr_concat(&local_140,"*", *(undefined4 * )(&DAT_0964721c + U_JUKELINUX1_POSMG * 4));
            Write(ARQTOCAR, local_140);
            Writeln(ARQTOCAR);
            Flush(ARQTOCAR);
            CloseFile(ARQTOCAR);
            if SEMPENDRIVE = 0 then begin
              local_148 := PASTACHAVE + 'tocar.txt';
              // C: puVar5 = local_148;
              if False { C: local_148 == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar5,&local_140);
              // C: uVar1 = local_140;
              local_150 := PASTA + 'tocar.txt';
              // C: puVar5 = local_150;
              if False { C: local_150 == (undefined1 * )0x0 } then begin
              end;
              // C: fpc_pchar_to_ansistr(puVar5,&local_14c);
              // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_14c,uVar1,extraout_ECX_00 & 0xffffff00);
            end;
          end;
        end;
      end;
      if 0 < TEMPOTOCARMG then begin
        Form1.Timer1Minuto.Enabled := True;
        KTEMPOMG := 0;
      end;
      Mostra_Fila;
      TEMPOEMSEGUNDOS := 0;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERNOMEMUSICAGRANDETIMER$TOBJECT }
procedure TForm1.TimerNomeMusicaGrandeTimer(Sender: TObject);
var
  local_3c: AnsiString;
  iVar1, iVar2, local_38: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  // C: iVar1 = fpc_setjmp();
  if (iVar1 = 0) and (0 < MUSICASELECIONADA) then begin
    case MUSICASELECIONADAPOSTELA of
      1: begin
        iVar2 := 0;
        if NOMEMUSICAORIGINALGRANDE <> '' then begin
        // C: iVar2 = *(int * )(U_JUKELINUX1_NOMEMUSICAORIGINALGRANDE + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica1,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            Form1.Musica1.Caption := NOMEMUSICAORIGINALGRANDE;
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica1,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica1.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      2: begin
        iVar2 := 0;
        if False { C: DAT_09301dc4 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301dc4 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica2,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica2,DAT_09301dc4);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica2,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica2.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      3: begin
        iVar2 := 0;
        if False { C: DAT_09301dc8 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301dc8 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica3,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica3,DAT_09301dc8);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica3,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica3.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      4: begin
        iVar2 := 0;
        if False { C: DAT_09301dcc != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301dcc + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica4,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica4,DAT_09301dcc);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica4,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica4.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      5: begin
        iVar2 := 0;
        if False { C: DAT_09301dd0 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301dd0 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica5,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica5,DAT_09301dd0);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica5,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica5.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      6: begin
        iVar2 := 0;
        if False { C: DAT_09301dd4 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301dd4 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica6,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica6,DAT_09301dd4);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica6,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica6.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      7: begin
        iVar2 := 0;
        if False { C: DAT_09301dd8 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301dd8 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica7,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica7,DAT_09301dd8);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica7,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica7.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      8: begin
        iVar2 := 0;
        if False { C: DAT_09301ddc != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301ddc + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica8,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica8,DAT_09301ddc);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica8,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica8.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      9: begin
        iVar2 := 0;
        if False { C: DAT_09301de0 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301de0 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica9,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica9,DAT_09301de0);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica9,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica9.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      10: begin
        iVar2 := 0;
        if False { C: DAT_09301de4 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301de4 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica10,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica10,DAT_09301de4);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica10,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica10.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      11: begin
        iVar2 := 0;
        if False { C: DAT_09301de8 != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301de8 + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica11,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 11 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica11,DAT_09301de8);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica11,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica11.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
      12: begin
        iVar2 := 0;
        if False { C: DAT_09301dec != 0 } then begin
        // C: iVar2 = *(int * )(DAT_09301dec + -4);
        end;
        if TAMANHOMUSICAGRANDE < iVar2 then begin
        // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica12,local_38);
        iVar2 := 0;
        if local_38 <> 0 then begin
          // C: iVar2 = *(int * )(local_38[0] + -4);
        end;
        if iVar2 < 13 then begin
          if ALTEROUMUSICAGRANDE <> 0 then begin
            // C: CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING (Form1.Musica12,DAT_09301dec);
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,3000);
            SOMAMUSICAGRANDE := 0;
          end;
        end
        else begin
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.Musica12,&local_3c);
          TEXTOMUSICAGRANDE := local_3c;
          Delete(TEXTOMUSICAGRANDE, 1, 1);
          Form1.Musica12.Caption := TEXTOMUSICAGRANDE;
          SOMAMUSICAGRANDE := SOMAMUSICAGRANDE + 1;
          ALTEROUMUSICAGRANDE := 1;
          // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb94) + 0xdc)) (Form1.TimerNomeMusicaGrande,200);
        end;
        end;
      end;
    end;
  end;
  if iVar1 <> 0 then begin
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPAGINAMAISTIMER$TOBJECT }
procedure TForm1.TimerPaginaMaisTimer(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  iVar2, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Form1.TimerPaginaMais.Enabled := False;
    ENTROUROTINAPAGINACAO := 0;
    if SENTIDODAPAGINACAO = 'Anti-Horário' then begin
      KMAT := KMAT + -1;
      if KMAT = -5 then begin
        KMAT := -4;
        if FORMADEPAGINACAO = 'Continua' then begin
          KMAT := TOTALCDS + -5;
        end;
        Desselecionamusica;
        MUSICASELECIONADA := 0;
        MUSICASELECIONADAPOSTELA := 0;
        MUSICASELECIONADATS := 0;
        local_3c := IntToStr(MUSICASELECIONADATS);
        local_38 := 'MusicaSelecionadaTS=' + local_3c;
        Form1.Label7.Caption := local_38;
        if RESOLUCAO = 1366 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        if RESOLUCAO = 1024 then begin
          TAMANHOMUSICAGRANDE := 22;
        end;
        if RESOLUCAO = 1440 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        SOMAMUSICAGRANDE := 0;
        MOSTRANDORITMOS := 0;
        MOSTRANDOLETRAS := 0;
        Mostra_Cds(' ');
        Mostra_Nome_Das_Musicas;
        ENTROUROTINAPAGINACAO := 1;
      end;
      SETAVERMELHA := 'CD-';
      MOSTROUSETAVERMELHA := 0;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb44) + 0xdc))(Form1.TimerSetaVermelha,10);
      Form1.TimerSetaVermelha.Enabled := True;
    end;
    // C: iVar3 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Horário");
    iVar2 := KMAT;
    if iVar3 = 0 then begin
      KMAT := KMAT + 1;
      if TOTALCDS < iVar2 + 6 then begin
        KMAT := iVar2;
        if FORMADEPAGINACAO = 'Continua' then begin
          KMAT := -4;
        end;
        Desselecionamusica;
        MUSICASELECIONADA := 0;
        MUSICASELECIONADAPOSTELA := 0;
        MUSICASELECIONADATS := 0;
        if RESOLUCAO = 1366 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        if RESOLUCAO = 1024 then begin
          TAMANHOMUSICAGRANDE := 22;
        end;
        if RESOLUCAO = 1440 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        SOMAMUSICAGRANDE := 0;
        MOSTRANDORITMOS := 0;
        MOSTRANDOLETRAS := 0;
        Mostra_Cds('+');
        Mostra_Nome_Das_Musicas;
        ENTROUROTINAPAGINACAO := 1;
      end;
      SETAVERMELHA := 'CD+';
      MOSTROUSETAVERMELHA := 0;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb44) + 0xdc))(Form1.TimerSetaVermelha,10);
      Form1.TimerSetaVermelha.Enabled := True;
    end;
    ESTAPAGINANDOPARA := '+';
    if ENTROUROTINAPAGINACAO = 0 then begin
      Mostra_Cds('+');
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPAGINAMENOSTIMER$TOBJECT }
procedure TForm1.TimerPaginaMenosTimer(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  iVar2, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    Form1.TimerPaginaMenos.Enabled := False;
    ENTROUROTINAPAGINACAO := 0;
    // C: iVar2 = fpc_ansistr_compare_equal(U_JUKELINUX1_SENTIDODAPAGINACAO,"Anti-Horário");
    iVar3 := KMAT;
    if iVar2 = 0 then begin
      KMAT := KMAT + 1;
      if TOTALCDS < iVar3 + 6 then begin
        KMAT := iVar3;
        if FORMADEPAGINACAO = 'Continua' then begin
          KMAT := -4;
        end;
        Desselecionamusica;
        MUSICASELECIONADA := 0;
        MUSICASELECIONADAPOSTELA := 0;
        MUSICASELECIONADATS := 0;
        local_3c := IntToStr(MUSICASELECIONADATS);
        local_38 := 'MusicaSelecionadaTS=' + local_3c;
        Form1.Label7.Caption := local_38;
        if RESOLUCAO = 1366 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        if RESOLUCAO = 1024 then begin
          TAMANHOMUSICAGRANDE := 22;
        end;
        if RESOLUCAO = 1440 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        SOMAMUSICAGRANDE := 0;
        MOSTRANDORITMOS := 0;
        MOSTRANDOLETRAS := 0;
        Mostra_Cds(' ');
        Mostra_Nome_Das_Musicas;
        ENTROUROTINAPAGINACAO := 1;
      end;
      SETAVERMELHA := 'CD+';
      MOSTROUSETAVERMELHA := 0;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb44) + 0xdc))(Form1.TimerSetaVermelha,10);
      Form1.TimerSetaVermelha.Enabled := True;
    end;
    if SENTIDODAPAGINACAO = 'Horário' then begin
      KMAT := KMAT + -1;
      if KMAT = -5 then begin
        KMAT := -4;
        if FORMADEPAGINACAO = 'Continua' then begin
          KMAT := TOTALCDS + -5;
        end;
        Desselecionamusica;
        MUSICASELECIONADA := 0;
        MUSICASELECIONADAPOSTELA := 0;
        MUSICASELECIONADATS := 0;
        if RESOLUCAO = 1366 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        if RESOLUCAO = 1024 then begin
          TAMANHOMUSICAGRANDE := 22;
        end;
        if RESOLUCAO = 1440 then begin
          TAMANHOMUSICAGRANDE := 30;
        end;
        SOMAMUSICAGRANDE := 0;
        MOSTRANDORITMOS := 0;
        MOSTRANDOLETRAS := 0;
        Mostra_Cds(' ');
        Mostra_Nome_Das_Musicas;
        ENTROUROTINAPAGINACAO := 1;
      end;
      SETAVERMELHA := 'CD-';
      MOSTROUSETAVERMELHA := 0;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb44) + 0xdc))(Form1.TimerSetaVermelha,10);
      Form1.TimerSetaVermelha.Enabled := True;
    end;
    ESTAPAGINANDOPARA := '-';
    if ENTROUROTINAPAGINACAO = 0 then begin
      Mostra_Cds('-');
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPAGINASOZINHOTIMER$TOBJECT }
procedure TForm1.TimerPaginaSozinhoTimer(Sender: TObject);
var
  iVar1: LongInt;
begin
  TEMPOEMSEGUNDOSPAGINARSOZINHO := TEMPOEMSEGUNDOSPAGINARSOZINHO + 1;
  if TEMPOEMSEGUNDOSPAGINARSOZINHO = TEMPOPARAPAGINARSOZINHO then begin
    // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_DIRECAO,"Frente");
    if (iVar1 = 0) and (TOTALCDS <= KMAT + 4) then begin
      DIRECAO := 'Tras';
    end;
    // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_DIRECAO,"Tras");
    if (iVar1 = 0) and (KMAT = -3) then begin
      DIRECAO := 'Frente';
    end;
    if DIRECAO = 'Tras' then begin
      Form1.TimerPaginaMais.Enabled := True;
    end;
    if DIRECAO = 'Frente' then begin
      Form1.TimerPaginaMenos.Enabled := True;
    end;
    SEGURANDOTECLA := 0;
    // C: U_JUKELINUX1_TEMPOEMSEGUNDOSPAGINARSOZINHO = (int)(U_JUKELINUX1_TEMPOPARAPAGINARSOZINHO + (U_JUKELINUX1_TEMPOPARAPAGINARSOZINHO >> 0x1f & 3U)) >> 2;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPALHINHATIMER$TOBJECT }
procedure TForm1.TimerPalhinhaTimer(Sender: TObject);
label
  LAB_080e39d9, LAB_080e3a45;
var
  local_38, local_3c, local_40: AnsiString;
  cVar1: Boolean;
  iVar2, iVar3, iVar4: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  // C: iVar2 = fpc_setjmp();
  if iVar2 <> 0 then begin goto LAB_080e3a45; end;
  TEMCREDITO := 0;
  if REAISXMUSICAS = 'Livre' then begin
    TEMCREDITO := 1;
  end
  else if 0 < CREDITOS then begin
    TEMCREDITO := 1;
  end;
  TEMPOPALHINHA := TEMPOPALHINHA + 1;
  // C: if ((((U_JUKELINUX1_TEMPOPALHINHA != U_JUKELINUX1_TEMPOPARAINICIARAPALHINHA) || (U_JUKELINUX1_PALHINHASPORREAL < 1)) || (U_JUKELINUX1_ESTANOMENU != '\0')) || (((U_JUKELINUX1_TOCANDOMUSICA != '\0' || (U_JUKELINUX1_TEMCREDITO == '\0')) || ((U_JUKELINUX1_MUSICASELECIONADA < 1 || (iVar3 = fpc_ansistr_compare_equal (U_JUKELINUX1_MUSICAQUEJATOCOUAPALHINHA, *(undefined4 * ) ((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 + U_JUKELINUX1_MUSICASELECIONADA * 4)), iVar3 == 0)))))) goto LAB_080e3a45;
  Form1.TimerPalhinha.Enabled := False;
  iVar3 := MUSICASELECIONADA;
  iVar4 := (KMAT + 5) * 576;
  // C: U_JUKELINUX1_ORIGEMPALHINHA = *(undefined4 * )(iVar4 + 0x8e91144 + iVar3 * 4);
  // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
  if cVar1 then begin
    case MUSICASELECIONADAPOSTELA of
      1: begin
        Form1.ShapePalhinha.Left := Form1.Musica1.Left;
        Form1.ShapePalhinha.Top := Form1.Musica1.Top + 25;
      end;
      2: begin
        Form1.ShapePalhinha.Left := Form1.Musica2.Left;
        Form1.ShapePalhinha.Top := Form1.Musica2.Top + 25;
      end;
      3: begin
        Form1.ShapePalhinha.Left := Form1.Musica3.Left;
        Form1.ShapePalhinha.Top := Form1.Musica3.Top + 25;
      end;
      4: begin
        Form1.ShapePalhinha.Left := Form1.Musica4.Left;
        Form1.ShapePalhinha.Top := Form1.Musica4.Top + 25;
      end;
      5: begin
        Form1.ShapePalhinha.Left := Form1.Musica5.Left;
        Form1.ShapePalhinha.Top := Form1.Musica5.Top + 25;
      end;
      6: begin
        Form1.ShapePalhinha.Left := Form1.Musica6.Left;
        Form1.ShapePalhinha.Top := Form1.Musica6.Top + 25;
      end;
      7: begin
        Form1.ShapePalhinha.Left := Form1.Musica7.Left;
        Form1.ShapePalhinha.Top := Form1.Musica7.Top + 25;
      end;
      8: begin
        Form1.ShapePalhinha.Left := Form1.Musica8.Left;
        Form1.ShapePalhinha.Top := Form1.Musica8.Top + 25;
      end;
      9: begin
        Form1.ShapePalhinha.Left := Form1.Musica9.Left;
        Form1.ShapePalhinha.Top := Form1.Musica9.Top + 25;
      end;
      10: begin
        Form1.ShapePalhinha.Left := Form1.Musica10.Left;
        Form1.ShapePalhinha.Top := Form1.Musica10.Top + 25;
      end;
      11: begin
        Form1.ShapePalhinha.Left := Form1.Musica11.Left;
        Form1.ShapePalhinha.Top := Form1.Musica11.Top + 25;
      end;
      12: begin
        Form1.ShapePalhinha.Left := Form1.Musica12.Left;
        Form1.ShapePalhinha.Top := Form1.Musica12.Top + 25;
      end;
    end;
    Form1.ShapePalhinha.Width := 60;
    Form1.ShapePalhinha.Height := 0;
    Form1.ShapePalhinha.BringToFront;
    Form1.ShapePalhinha.Show;
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x67c) + 0x2fc))(Form1.ShapePalhinha);
    KSHAPE := 0;
    repeat
      KSHAPE := KSHAPE + 5;
      Form1.ShapePalhinha.Height := KSHAPE;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x67c) + 0x2fc))(Form1.ShapePalhinha);
    until not (KSHAPE <> 65);
    Form1.ImagePalhinha.Left := Form1.ShapePalhinha.Left + 10;
    Form1.ImagePalhinha.Top := Form1.ShapePalhinha.Top + 5;
    Form1.ImagePalhinha.BringToFront;
    Form1.ImagePalhinha.Show;
    local_38 := IntToStr(PALHINHASPORREAL);
    Form1.LabelQtdPalhinha.Caption := local_38;
    Form1.LabelQtdPalhinha.Left := Form1.ImagePalhinha.Left + 13;
    Form1.LabelQtdPalhinha.Top := Form1.ImagePalhinha.Top + 32;
    Form1.LabelTempoAindaTocandoAPalhinha.Left := Form1.ImagePalhinha.Left + -7;
    Form1.LabelTempoAindaTocandoAPalhinha.Top := Form1.ImagePalhinha.Top + 22;
    Form1.LabelTempoAindaTocandoAPalhinha.BringToFront;
    Form1.LabelTempoAindaTocandoAPalhinha.Show;
    local_38 := IntToStr(TEMPODEINTRODUCAOMUSICAL);
    Form1.LabelTempoAindaTocandoAPalhinha.Caption := local_38;
    Form1.LabelQtdPalhinha.BringToFront;
    Form1.LabelQtdPalhinha.Show;
    PALHINHASPORREAL := PALHINHASPORREAL + -1;
  end;
  // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
  Descriptografa(ORIGEMPALHINHA, 'PALHINHA');
  Form1.Play.Show;
  // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING (Form1.Play,U_JUKELINUX1_DESTINO);
  // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY(Form1.Play);
  // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + -1);
  // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + 1);
  Form1.Play.Hide;
  TOCANDOPALHINHA := 1;
  local_40 := ExtractFileExt(ORIGEMPALHINHA);
  local_3c := UpperCase(local_40);
  if local_3c = '.MPG' then begin
    LAB_080e39d9: ;
    Desativa_Propaganda;
    Form1.Play.Show;
    Form1.Play.BringToFront;
  end
  else begin
    local_3c := ExtractFileExt(ORIGEMPALHINHA);
    local_40 := UpperCase(local_3c);
    if local_40 = '.MKV' then begin goto LAB_080e39d9; end;
    local_3c := ExtractFileExt(ORIGEMPALHINHA);
    local_40 := UpperCase(local_3c);
    if local_40 = '.MP4' then begin goto LAB_080e39d9; end;
  end;
  MUSICAQUEJATOCOUAPALHINHA := ORIGEMPALHINHA;
  CONTADORTEMPOPALHINHA := 0;
  MUDOUDECDOUMUSICA := 0;
  Form1.TimerPalhinhaTocando.Enabled := True;
  LAB_080e3a45: ;
  if iVar2 <> 0 then begin
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPALHINHATOCANDOTIMER$TOBJECT }
procedure TForm1.TimerPalhinhaTocandoTimer(Sender: TObject);
label
  LAB_080e3caf, LAB_080e3d22;
var
  local_38, local_3c, local_40: AnsiString;
  iVar1, iVar2: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  // C: iVar1 = fpc_setjmp();
  if iVar1 <> 0 then begin goto LAB_080e3d22; end;
  Form1.TimerPalhinhaTocando.Enabled := False;
  if TOCANDOPALHINHA = 0 then begin goto LAB_080e3d22; end;
  CONTADORTEMPOPALHINHA := CONTADORTEMPOPALHINHA + 1;
  local_38 := IntToStr(TEMPODEINTRODUCAOMUSICAL - (CONTADORTEMPOPALHINHA div 2));
  Form1.LabelTempoAindaTocandoAPalhinha.Caption := local_38;
  // C: iVar2 = U_JUKELINUX1_CONTADORTEMPOPALHINHA + (U_JUKELINUX1_CONTADORTEMPOPALHINHA >> 0x1f & 1U);
  if False { C: (iVar2 >> 1 < U_JUKELINUX1_TEMPODEINTRODUCAOMUSICAL) && (U_JUKELINUX1_MUDOUDECDOUMUSICA == '\0') } then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb60) + 0xd8)) (Form1.TimerPalhinhaTocando,CONCAT31((int3)(iVar2 >> 9),1));
    goto LAB_080e3d22;
  end;
  // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.Play);
  Form1.Play.Hide;
  TOCANDOPALHINHA := 0;
  Form1.ShapePalhinha.Hide;
  Form1.ImagePalhinha.Hide;
  Form1.LabelQtdPalhinha.Hide;
  Form1.LabelTempoAindaTocandoAPalhinha.Hide;
  // C: ( **(code ** )( *U_JUKELINUX1_FORM1 + 0x2fc))(U_JUKELINUX1_FORM1);
  local_40 := ExtractFileExt(ORIGEMPALHINHA);
  local_3c := UpperCase(local_40);
  if local_3c = '.MPG' then begin
    LAB_080e3caf: ;
    Ativa_Propaganda;
  end
  else begin
    local_3c := ExtractFileExt(ORIGEMPALHINHA);
    local_40 := UpperCase(local_3c);
    if local_40 = '.MKV' then begin goto LAB_080e3caf; end;
    local_3c := ExtractFileExt(ORIGEMPALHINHA);
    local_40 := UpperCase(local_3c);
    if local_40 = '.MP4' then begin goto LAB_080e3caf; end;
  end;
  TOCANDOPALHINHA := 0;
  Form1.TimerPalhinhaTocando.Enabled := False;
  TEMPOPALHINHA := 0;
  MUDOUDECDOUMUSICA := 0;
  Form1.TimerPalhinha.Enabled := True;
  LAB_080e3d22: ;
  if iVar1 <> 0 then begin
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPISCACREDITOSTIMER$TOBJECT }
procedure TForm1.TimerPiscaCreditosTimer(Sender: TObject);
begin
  if 0 < MOSTRANDOCREDITO then begin
    if MOSTRANDOCREDITO = 1 then begin
      Form1.LabelCreditos.Show;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9e0) + 0x2fc))(Form1.LabelCreditos);
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 2 then begin
      Form1.LabelCreditos.Hide;
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 3 then begin
      Form1.LabelCreditos.Show;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9e0) + 0x2fc))(Form1.LabelCreditos);
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 4 then begin
      Form1.LabelCreditos.Hide;
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 5 then begin
      Form1.LabelCreditos.Show;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9e0) + 0x2fc))(Form1.LabelCreditos);
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 6 then begin
      Form1.LabelCreditos.Hide;
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 7 then begin
      Form1.LabelCreditos.Show;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9e0) + 0x2fc))(Form1.LabelCreditos);
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 8 then begin
      Form1.LabelCreditos.Hide;
      MOSTRANDOCREDITO := MOSTRANDOCREDITO + 1;
    end
    else if MOSTRANDOCREDITO = 9 then begin
      Form1.LabelCreditos.Show;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0x9e0) + 0x2fc))(Form1.LabelCreditos);
      Form1.LabelCreditos.Font.Color := 16777215;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 3000) + 0xd8)) (Form1.TimerPiscaCreditos,extraout_EDX & 0xffffff00, **(int ** )(U_JUKELINUX1_FORM1 + 3000),Self,Sender);
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPISCASETATIMER$TOBJECT }
procedure TForm1.TimerPiscaSetaTimer(Sender: TObject);
begin
  if 0 < MOSTRANDOSETABAIXO then begin
    if MOSTRANDOSETABAIXO = 1 then begin
      Form1.SetaBaixo.Show;
      MOSTRANDOSETABAIXO := 2;
    end
    else begin
      Form1.SetaBaixo.Hide;
      MOSTRANDOSETABAIXO := 1;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERPROPAGANDATIMER$TOBJECT }
procedure TForm1.TimerPropagandaTimer(Sender: TObject);
var
  cVar1: Boolean;
  iVar2: LongInt;
begin
  // C: iVar2 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT ("TV/Monitor",U_JUKELINUX1_PROPAGANDA,param_3,Self,Sender);
  if iVar2 < 1 then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xba8) + 0xdc)) (Form1.TimerPropaganda,U_JUKELINUX1_TEMPOPROPAGANDA);
    POSPRO := POSPRO + 1;
    if TOTALPRO < POSPRO then begin
      POSPRO := 1;
    end;
    // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN((&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
    if cVar1 then begin
      if PROPAGANDA = 'Fotos PNG no Monitor' then begin
        // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImagePNG.Picture, (&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
      end;
      if PROPAGANDA = 'Fotos para Bar no Monitor' then begin
        // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageJPG.Picture, (&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
      end;
      if PROPAGANDA = 'Fotos para Boate no Monitor' then begin
        // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageJPG.Picture, (&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
      end;
      if PROPAGANDA = 'Fotos para Bar na TV' then begin
        // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageTV.Picture, (&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
      end;
      if PROPAGANDA = 'Fotos para Boate na TV' then begin
        // C: GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING (Form1.ImageTV.Picture, (&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
      end;
    end;
  end
  else begin
    iVar2 := Pos('enquanto Toca CD', PROPAGANDA);
    if iVar2 = 0 then begin
      if TOCANDOVIDEOTV = 0 then begin
        Form1.playtv.Left := POSL;
        Form1.playtv.Top := POST;
        Form1.playtv.Width := POSW;
        Form1.playtv.Height := POSH;
        Form1.playtv.Show;
        // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa0c) + 0x2fc))(Form1.playtv);
        Form1.playtv.BringToFront;
        // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xba8) + 0xdc)) (Form1.TimerPropaganda,U_JUKELINUX1_TEMPOPROPAGANDA);
        POSPRO := POSPRO + 1;
        if TOTALPRO < POSPRO then begin
          POSPRO := 1;
        end;
        // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN ((&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
        if cVar1 then begin
          // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING (Form1.playtv,(&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
          // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY(Form1.playtv);
          // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT(Form1.playtv,1);
          // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT(Form1.playtv,0);
          TOCANDOVIDEOTV := 1;
          Form1.TimerTocandoTv.Enabled := True;
          Form1.TimerPropaganda.Enabled := False;
        end;
      end;
    end
    else if TOCANDOMUSICA = 0 then begin
      Form1.TimerTocandoTv.Enabled := False;
      // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.playtv);
      Form1.playtv.Hide;
      TOCANDOVIDEOTV := 0;
    end
    else if (TOCANDOMUSICADVD = 0) and (TOCANDOVIDEOTV = 0) then begin
      Form1.playtv.Left := POSL;
      Form1.playtv.Top := POST;
      Form1.playtv.Width := POSW;
      Form1.playtv.Height := POSH;
      Form1.playtv.Show;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa0c) + 0x2fc))(Form1.playtv);
      Form1.playtv.BringToFront;
      // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xba8) + 0xdc)) (Form1.TimerPropaganda,U_JUKELINUX1_TEMPOPROPAGANDA);
      POSPRO := POSPRO + 1;
      if TOTALPRO < POSPRO then begin
        POSPRO := 1;
      end;
      // C: cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN((&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
      if cVar1 then begin
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING (Form1.playtv,(&U_JUKELINUX1_TOTALPRO)[U_JUKELINUX1_POSPRO]);
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY(Form1.playtv);
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT(Form1.playtv,1);
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT(Form1.playtv,0);
        TOCANDOVIDEOTV := 1;
        Form1.TimerTocandoTv.Enabled := True;
        Form1.TimerPropaganda.Enabled := False;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERRODADISPLAYTIMER$TOBJECT }
procedure TForm1.TimerRodaDisplayTimer(Sender: TObject);
var
  local_38: AnsiString;
  iVar2: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(Form1.LabelDisplay,local_38);
    TEXTOX := local_38;
    // C: U_JUKELINUX1_TEXTOTEMPX._1_1_ = *local_38[0];
    Delete(TEXTOX, 1, 1);
    // C: fpc_char_to_ansistr(U_JUKELINUX1_TEXTOTEMPX._1_1_,local_38);
    iVar2 := 0;
    if False { C: U_JUKELINUX1_TEXTOX != (undefined1 * )0x0 } then begin
      // C: iVar2 = *(int * )(U_JUKELINUX1_TEXTOX + -4);
    end;
    Insert(local_38, TEXTOX, iVar2 + 1);
    Form1.LabelDisplay.Caption := TEXTOX;
    local_38 := Copy(TEXTOX, 1, 12);
    if local_38 = '            ' then begin
      Form1.TimerRodaDisplay.Enabled := False;
      Form1.TimerFrases.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERSELECIONALETRAAUTOMATICOTIMER$TOBJECT }
procedure TForm1.TimerSelecionaLetraAutomaticoTimer(Sender: TObject);
begin
  if MOSTRANDOLETRAS <> 0 then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbac) + 0xd8)) (Form1.TimerSelecionaLetraAutomatico,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xbac), Self,Sender);
    Destravamensagem;
    Rotina_Ritmos;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERSELECIONARITMOAUTOMATICOTIMER$TOBJECT }
procedure TForm1.TimerSelecionaRitmoAutomaticoTimer(Sender: TObject);
begin
  if MOSTRANDORITMOS <> 0 then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xbb0) + 0xd8)) (Form1.TimerSelecionaRitmoAutomatico,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xbb0), Self,Sender);
    Destravamensagem;
    Rotina_Ritmos;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERSENHAERRADATIMER$TOBJECT }
procedure TForm1.TimerSenhaErradaTimer(Sender: TObject);
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb84) + 0xd8)) (Form1.TimerSenhaErrada,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xb84), Self,Sender);
  Form1.LabelMenuDSErro.Hide;
end;

{ JUKELINUX1_TFORM1_$__TIMERSETAVERMELHATIMER$TOBJECT }
procedure TForm1.TimerSetaVermelhaTimer(Sender: TObject);
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb44) + 0xdc)) (Form1.TimerSetaVermelha,1000,**(int ** )(U_JUKELINUX1_FORM1 + 0xb44),Self,Sender);
  if MOSTROUSETAVERMELHA <> 0 then begin
    Form1.TimerSetaVermelha.Enabled := False;
    Form1.ImageSetabrgCima.Hide;
    Form1.ImageSetabrgBaixo.Hide;
    SETAVERMELHA := '';
  end;
  if SETAVERMELHA = 'CD-' then begin
    if RESOLUCAO = 1024 then begin
      Form1.ImageSetabrgCima.Left := 353;
      Form1.ImageSetabrgCima.Top := 44;
      Form1.ImageSetabrgBaixo.Left := 353;
      Form1.ImageSetabrgBaixo.Top := 622;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.ImageSetabrgCima.Left := 673;
      Form1.ImageSetabrgCima.Top := 44;
      Form1.ImageSetabrgBaixo.Left := 673;
      Form1.ImageSetabrgBaixo.Top := 622;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImageSetabrgCima.Left := 723;
      Form1.ImageSetabrgCima.Top := 44;
      Form1.ImageSetabrgBaixo.Left := 723;
      Form1.ImageSetabrgBaixo.Top := 752;
    end;
    Form1.ImageSetabrgCima.Show;
    Form1.ImageSetabrgBaixo.Show;
    MOSTROUSETAVERMELHA := 1;
  end;
  if SETAVERMELHA = 'CD+' then begin
    if RESOLUCAO = 1024 then begin
      Form1.ImageSetabrgBaixo.Left := 353;
      Form1.ImageSetabrgBaixo.Top := 44;
      Form1.ImageSetabrgCima.Left := 353;
      Form1.ImageSetabrgCima.Top := 622;
    end;
    if RESOLUCAO = 1366 then begin
      Form1.ImageSetabrgBaixo.Left := 673;
      Form1.ImageSetabrgBaixo.Top := 44;
      Form1.ImageSetabrgCima.Left := 673;
      Form1.ImageSetabrgCima.Top := 622;
    end;
    if RESOLUCAO = 1440 then begin
      Form1.ImageSetabrgBaixo.Left := 723;
      Form1.ImageSetabrgBaixo.Top := 44;
      Form1.ImageSetabrgCima.Left := 723;
      Form1.ImageSetabrgCima.Top := 752;
    end;
    Form1.ImageSetabrgCima.Show;
    Form1.ImageSetabrgBaixo.Show;
    MOSTROUSETAVERMELHA := 1;
  end;
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb44) + 0xdc))(Form1.TimerSetaVermelha,1000);
end;

{ JUKELINUX1_TFORM1_$__TIMERSORTEIOTIMER$TOBJECT }
procedure TForm1.TimerSorteioTimer(Sender: TObject);
var
  iVar1: LongInt;
begin
  // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb68) + 0xd8)) (Form1.TimerSorteio,Sender & 0xffffff00,**(int ** )(U_JUKELINUX1_FORM1 + 0xb68), Self,Sender);
  // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SORTEIODECREDITOS,"2 Reais");
  if (iVar1 = 0) and (1 < PULSOSPARASORTEIO) then begin
    PULSOSPARASORTEIO := PULSOSPARASORTEIO + -2;
    Mostra_Tela_De_Sorteio;
  end;
  // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SORTEIODECREDITOS,"5 Reais");
  if (iVar1 = 0) and (4 < PULSOSPARASORTEIO) then begin
    PULSOSPARASORTEIO := PULSOSPARASORTEIO + -5;
    Mostra_Tela_De_Sorteio;
  end;
  // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_SORTEIODECREDITOS,"10 Reais");
  if (iVar1 = 0) and (9 < PULSOSPARASORTEIO) then begin
    PULSOSPARASORTEIO := PULSOSPARASORTEIO + -10;
    Mostra_Tela_De_Sorteio;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERTELACHEIATIMER$TOBJECT }
procedure TForm1.TimerTelaCheiaTimer(Sender: TObject);
var
  iVar1: LongInt;
begin
  // C: iVar1 = fpc_ansistr_compare_equal (U_JUKELINUX1_TOCANDOTIPO,"DVD",param_3,Self,Sender);
  if ((iVar1 = 0) and (TOCANDOMUSICA <> 0)) and (Form1.Play.Left = POSL) then begin
    Desselecionamusica;
    MUSICASELECIONADA := 0;
    MUSICASELECIONADAPOSTELA := 0;
    MUSICASELECIONADATS := 0;
    Selecionamusica;
    Form1.Play.Left := 0;
    Form1.Play.Top := 0;
    Form1.Play.Width := RESOLUCAO;
    Form1.Play.Height := RESOLUCAOALTURA;
    Form1.Play.BringToFront;
    ESTAEMTELACHEIA := 1;
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc)) (Form1.TimerTelaCheia,500);
    Form1.TimerRodaDisplay.Enabled := False;
    Form1.TimerNomeMusicaGrande.Enabled := False;
    Form1.TimerPiscaSeta.Enabled := False;
    if TOCANDOMUSICA <> 0 then begin
      // C: iVar1 = fpc_ansistr_compare_equal(U_JUKELINUX1_LETRASEXE,"3MJ");
      if (iVar1 = 0) and (ESTANOMENU <> 0) then begin
        Form1.PanelMenu.Show;
        Form1.PanelMenu.BringToFront;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERTOCANDOPALHINHAESELETOCARTIMER$TOBJECT }
procedure TForm1.TimerTocandoPalhinhaESeleTocarTimer(Sender: TObject);
begin
  if MANDOUTOCARTOCANDOPALHINHA = 0 then begin
    Rotina_Tocar;
    Form1.TimerTocandoPalhinhaESeleTocar.Enabled := False;
  end;
  if MANDOUTOCARTOCANDOPALHINHA = 1 then begin
    Rotina_Cancelar;
    MANDOUTOCARTOCANDOPALHINHA := 0;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERTOCANDOTIMER$TOBJECT }
procedure TForm1.TimerTocandoTimer(Sender: TObject);
var
  local_38: AnsiString;
  cVar4: Boolean;
  iVar1, iVar2, iVar3: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    // C: cVar4 = MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____RUNNING__BOOLEAN(Form1.Play);
    if not cVar4 then begin
      Presstecla;
      Form1.TimerTocando.Enabled := False;
      // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.Play);
      Form1.Play.Hide;
      TOCANDOMUSICA := 0;
      TOCANDOMUSICADVD := 0;
      TOCANDOMUSICAGRATIS := 0;
      Form1.PanelCDTocando.Hide;
      Form1.Play.Hide;
      Ativa_Propaganda;
      local_38 := PASTA + 'tocando.txt';
      DeleteFile(local_38);
      iVar3 := TOTALFRASE;
      TOCANDOTIPO := '';
      KFRASE := 1;
      if 0 < TOTALFRASE then begin
        KFRASE := 0;
        repeat
          KFRASE := KFRASE + 1;
          iVar1 := KFRASE;
          iVar2 := KFRASE;
          // C: *(undefined4 * )(U_JUKELINUX1_ARQTOCARX + iVar2 * 4 + 0x24c) = *(undefined4 * )(iVar1 * 4 + 0x9301ccc);
        until not (KFRASE < iVar3);
      end;
      POSFRASE := 0;
      Form1.TimerTocar.Enabled := True;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERTOCANDOTVTIMER$TOBJECT }
procedure TForm1.TimerTocandoTvTimer(Sender: TObject);
var
  cVar1: Boolean;
begin
  // C: cVar1 = MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAYING__BOOLEAN(Form1.playtv);
  if not cVar1 then begin
    // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xb6c) + 0xd8)) (Form1.TimerTocandoTv,extraout_EDX & 0xffffff00, **(int ** )(U_JUKELINUX1_FORM1 + 0xb6c),Self,Sender);
    // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.playtv);
    Form1.playtv.Hide;
    Form1.TimerPropaganda.Enabled := True;
    TOCANDOVIDEOTV := 0;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERTOCARTIMER$TOBJECT }
procedure TForm1.TimerTocarTimer(Sender: TObject);
var
  local_134, local_138, local_13c, local_23c, local_240, local_244, local_248, local_24c, local_254, local_25c, local_260, local_264, local_268, local_368, local_36c: AnsiString;
  cVar2: Boolean;
  iVar1, iVar4, iVar6, iVar9, local_250, local_258, uVar7: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    OK_TOCA_MENU := 1;
    // C: iVar4 = fpc_ansistr_compare_equal(U_JUKELINUX1_LETRASEXE,"3MJ");
    if (iVar4 = 0) and (ESTANOMENU <> 0) then begin
      OK_TOCA_MENU := 1;
    end;
    if OK_TOCA_MENU <> 0 then begin
      Form1.TimerTocar.Enabled := False;
      if SELECIONADAS < 1 then begin
        Form1.TimerTocar.Enabled := True;
      end
      else if TOCANDOMUSICA = 0 then begin
        if TOCANDOPALHINHA = 0 then begin
          local_138 := PASTA + 'tocar.txt';
          local_134 := local_138;
          AssignFile(ARQTOCAR, local_134);
          Reset(ARQTOCAR);
          Read(ARQTOCAR, TEXTOTOCAR);
          Readln(ARQTOCAR);
          CloseFile(ARQTOCAR);
          TEXTOTOCAR2 := TEXTOTOCAR;
          // C: fpc_ansistr_copy(U_JUKELINUX1_TEXTOTOCAR,1,1);
          if local_138 = '*' then begin
            // C: uVar7 = 0;
            if TEXTOTOCAR <> '' then begin
              // C: uVar7 = *(undefined4 * )(U_JUKELINUX1_TEXTOTOCAR + -4);
            end;
            // C: fpc_ansistr_copy(U_JUKELINUX1_TEXTOTOCAR,2,uVar7);
            TEXTOTOCAR := local_138;
          end;
          TEXTOTOCANDO := TEXTOTOCAR;
          local_138 := PASTA + 'tocando.txt';
          local_134 := local_138;
          AssignFile(ARQTEXTO, local_134);
          Rewrite(ARQTEXTO);
          Write(ARQTEXTO, TEXTOTOCANDO);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
          local_138 := PASTA + 'tocando.txt';
          local_134 := local_138;
          AssignFile(ARQTEXTO, local_134);
          Reset(ARQTEXTO);
          Read(ARQTEXTO, TEXTOTOCANDO);
          Readln(ARQTEXTO);
          CloseFile(ARQTEXTO);
          // C: fpc_ansistr_copy(U_JUKELINUX1_TEXTOTOCAR2,1,1);
          if local_138 <> '*' then begin
            TEXTOTOCANDO := TEXTOTOCAR;
            local_138 := PASTA + 'tocados.txt';
            local_134 := local_138;
            AssignFile(ARQTEXTO, local_134);
            local_138 := PASTA + 'tocados.txt';
            cVar2 := FileExists(local_138);
            if not cVar2 then begin
              Rewrite(ARQTEXTO);
            end
            else begin
              Append(ARQTEXTO);
            end;
            Write(ARQTEXTO, TEXTOTOCANDO);
            Writeln(ARQTEXTO);
            Flush(ARQTEXTO);
            CloseFile(ARQTEXTO);
            TEXTOTOCANDO := TEXTOTOCAR;
            local_138 := PASTA + 'tocadosablf.txt';
            local_134 := local_138;
            AssignFile(ARQTEXTO, local_134);
            local_138 := PASTA + 'tocadosablf.txt';
            cVar2 := FileExists(local_138);
            if not cVar2 then begin
              Rewrite(ARQTEXTO);
            end
            else begin
              Append(ARQTEXTO);
            end;
            local_138 := DateToStr(Date);
            Write(ARQTEXTO, local_138);
            Writeln(ARQTEXTO);
            local_138 := TimeToStr(Time);
            Write(ARQTEXTO, local_138);
            Writeln(ARQTEXTO);
            iVar4 := 0;
            if PASTAMUSICAS <> '' then begin
              // C: iVar4 = *(int * )(U_JUKELINUX1_PASTAMUSICAS + -4);
            end;
            // C: uVar7 = 0;
            if TEXTOTOCANDO <> '' then begin
              // C: uVar7 = *(undefined4 * )(U_JUKELINUX1_TEXTOTOCANDO + -4);
            end;
            // C: fpc_ansistr_copy(U_JUKELINUX1_TEXTOTOCANDO,iVar4 + 1,uVar7);
            TEXTO := local_138;
            // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
            Writeln(ARQTEXTO);
            Flush(ARQTEXTO);
            CloseFile(ARQTEXTO);
            TEXTOTOCANDO := TEXTOTOCAR;
            local_138 := PASTA + 'tocadosaprova.txt';
            local_134 := local_138;
            AssignFile(ARQTEXTO, local_134);
            local_138 := PASTA + 'tocadosaprova.txt';
            cVar2 := FileExists(local_138);
            if not cVar2 then begin
              Rewrite(ARQTEXTO);
            end
            else begin
              Append(ARQTEXTO);
            end;
            local_138 := DateToStr(Date);
            Write(ARQTEXTO, local_138);
            Writeln(ARQTEXTO);
            local_138 := TimeToStr(Time);
            Write(ARQTEXTO, local_138);
            Writeln(ARQTEXTO);
            iVar4 := 0;
            if PASTAMUSICAS <> '' then begin
              // C: iVar4 = *(int * )(U_JUKELINUX1_PASTAMUSICAS + -4);
            end;
            // C: uVar7 = 0;
            if TEXTOTOCANDO <> '' then begin
              // C: uVar7 = *(undefined4 * )(U_JUKELINUX1_TEXTOTOCANDO + -4);
            end;
            // C: fpc_ansistr_copy(U_JUKELINUX1_TEXTOTOCANDO,iVar4 + 1,uVar7);
            TEXTO := local_138;
            // C: fpc_write_text_ansistr(0,U_JUKELINUX1_ARQTEXTO);
            Writeln(ARQTEXTO);
            Flush(ARQTEXTO);
            CloseFile(ARQTEXTO);
          end;
          local_13c := ExtractFileExt(TEXTOTOCAR);
          local_138 := UpperCase(local_13c);
          if local_138 = '.MP3' then begin
            DESTINO := PASTA + 'tocarcd.mp3';
            TOCANDOTIPO := 'CD';
          end;
          local_138 := ExtractFileExt(TEXTOTOCAR);
          local_13c := UpperCase(local_138);
          if local_13c = '.MPG' then begin
            DESTINO := PASTA + 'tocardvd.mpg';
            TOCANDOTIPO := 'DVD';
          end;
          local_138 := ExtractFileExt(TEXTOTOCAR);
          local_13c := UpperCase(local_138);
          if local_13c = '.WMA' then begin
            DESTINO := PASTA + 'tocarcd.wma';
            TOCANDOTIPO := 'CD';
          end;
          local_138 := ExtractFileExt(TEXTOTOCAR);
          local_13c := UpperCase(local_138);
          if local_13c = '.MKV' then begin
            DESTINO := PASTA + 'tocardvd.mkv';
            TOCANDOTIPO := 'DVD';
          end;
          local_138 := ExtractFileExt(TEXTOTOCAR);
          local_13c := UpperCase(local_138);
          if local_13c = '.MP4' then begin
            DESTINO := PASTA + 'tocardvd.mp4';
            TOCANDOTIPO := 'DVD';
          end;
          cVar2 := FileExists(TEXTOTOCAR);
          if cVar2 then begin
            Descriptografa(TEXTOTOCAR, 'NORMAL');
          end;
          local_13c := PASTA + 'tocarx.txt';
          local_23c := local_13c;
          AssignFile(ARQTOCARX, local_23c);
          Rewrite(ARQTOCARX);
          local_13c := PASTA + 'tocar.txt';
          local_23c := local_13c;
          AssignFile(ARQTOCAR, local_23c);
          Reset(ARQTOCAR);
          KTOCAR := 1;
          while True do begin
            cVar2 := Eof(ARQTOCAR);
            if cVar2 then begin Break; end;
            Read(ARQTOCAR, TEXTO);
            Readln(ARQTOCAR);
            if KTOCAR <> 1 then begin
              Write(ARQTOCARX, TEXTO);
              Writeln(ARQTOCARX);
            end;
            KTOCAR := KTOCAR + 1;
          end;
          CloseFile(ARQTOCAR);
          Flush(ARQTOCARX);
          CloseFile(ARQTOCARX);
          local_13c := PASTA + 'tocar.txt';
          DeleteFile(local_13c);
          local_13c := PASTA + 'tocar.txt';
          // C: puVar5 = local_13c;
          local_240 := PASTA + 'tocarx.txt';
          // C: SYSUTILS_RENAMEFILE_ANSISTRING_ANSISTRING__BOOLEAN(local_240,puVar5);
          if SEMPENDRIVE = 0 then begin
            local_13c := PASTACHAVE + 'tocar.txt';
            // C: puVar5 = local_13c;
            if False { C: local_13c == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar5,&local_240);
            // C: uVar7 = local_240;
            local_248 := PASTA + 'tocar.txt';
            // C: puVar5 = local_248;
            if False { C: local_248 == (undefined1 * )0x0 } then begin
            end;
            // C: fpc_pchar_to_ansistr(puVar5,&local_244);
            // C: FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN (local_244,uVar7,extraout_ECX & 0xffffff00);
          end;
          Mostra_Fila;
          if TOCANDOTIPO = 'CD' then begin
            Form1.Play.Show;
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING (Form1.Play,U_JUKELINUX1_DESTINO);
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY(Form1.Play);
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + -1);
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + 1);
            TOCANDOMUSICA := 1;
            TOCANDOMUSICADVD := 0;
            Form1.Play.Hide;
            Form1.TimerTocar.Enabled := False;
            Form1.TimerTocando.Enabled := True;
          end;
          if TOCANDOTIPO = 'DVD' then begin
            if TOCANDOVIDEOTV <> 0 then begin
              Form1.TimerTocandoTv.Enabled := False;
              // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP(Form1.playtv);
              Form1.playtv.Hide;
              TOCANDOVIDEOTV := 0;
            end;
            Form1.Play.Left := POSL;
            Form1.Play.Top := POST;
            Form1.Play.Width := POSW;
            Form1.Play.Height := POSH;
            Form1.Play.Show;
            // C: ( **(code ** )( **(int ** )(U_JUKELINUX1_FORM1 + 0xa84) + 0x2fc))(Form1.Play);
            Form1.Play.BringToFront;
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING (Form1.Play,U_JUKELINUX1_DESTINO);
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY(Form1.Play);
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + -1);
            // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + 1);
            TOCANDOMUSICA := 1;
            TOCANDOMUSICADVD := 1;
            Form1.TimerTocar.Enabled := False;
            Form1.TimerTocando.Enabled := True;
            if EXIBIRVIDEOSNO = 'MONITOR' then begin
              Form1.TimerTelaCheia.Enabled := True;
            end
            else begin
              Form1.TimerTelaCheia.Enabled := False;
            end;
          end;
          if TOCANDOTIPO = 'DVD' then begin
            Desativa_Propaganda;
          end;
          // C: iVar4 = fpc_ansistr_compare_equal(U_JUKELINUX1_TOCANDOTIPO,"CD");
          if False { C: (iVar4 == 0) && (iVar4 = fpc_ansistr_compare_equal(U_JUKELINUX1_EXIBIRVIDEOSNO,"MONITOR"), iVar4 == 0) } then begin
            Desativa_Propaganda;
          end;
          NOMECAPACDTOCANDO := '???????';
          NOMEDOCDTOCANDO := '???????';
          iVar4 := TOTALCDS;
          NOMEDAMUSICATOCANDO := '???????';
          KTOCAR := 1;
          if 0 < TOTALCDS then begin
            KTOCAR := 0;
            repeat
              KTOCAR := KTOCAR + 1;
              KTOCAR2 := 0;
              repeat
                KTOCAR2 := KTOCAR2 + 1;
                // C: iVar6 = fpc_ansistr_compare_equal (U_JUKELINUX1_TEXTOTOCAR, *(undefined4 * ) (U_JUKELINUX1_KTOCAR * 0x240 + 0x8e91144 + U_JUKELINUX1_KTOCAR2 * 4));
                if iVar6 = 0 then begin
                  iVar9 := KTOCAR * 576;
                  iVar1 := KTOCAR2;
                  iVar6 := KTOCAR;
                  // C: U_JUKELINUX1_NOMECAPACDTOCANDO = *(char ** )(U_JUKELINUX1_ARQLOG + iVar9 + 0x204);
                  // C: fpc_ansistr_incr_ref ((&U_JUKELINUX1_PASTACHAVE9) [U_JUKELINUX1_KTOCAR * 0x90 + U_JUKELINUX1_KTOCAR2]);
                  // C: U_JUKELINUX1_NOMEDAMUSICATOCANDO = (char * )(&U_JUKELINUX1_PASTACHAVE9)[iVar6 * 0x90 + iVar1];
                  iVar6 := 0;
                  if False { C: *(int * )(U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KTOCAR * 0x240 + 0x1fc) != 0 } then begin
                    // C: iVar6 = *(int * )( *(int * )(U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KTOCAR * 0x240 + 0x1fc) + -4);
                  end;
                  // C: fpc_ansistr_copy( *(undefined4 * ) (U_JUKELINUX1_ARQLOG + U_JUKELINUX1_KTOCAR * 0x240 + 0x1fc),1, iVar6 + -1);
                  NOMEDOCDTOCANDO := local_244;
                end;
              until not (KTOCAR2 < 40);
            until not (KTOCAR < iVar4);
          end;
          // C: fpc_ansistr_copy(U_JUKELINUX1_TEXTOTOCAR2,1,1);
          if local_244 = '*' then begin
            local_244 := PASTA + 'fundotocandogratis.jpg';
            Form1.ImageTocando.Picture.LoadFromFile(local_244);
            Form1.ImageTocando.Show;
            TOCANDOMUSICAGRATIS := 1;
          end
          else begin
            local_244 := PASTA + 'fundotocando.jpg';
            cVar2 := FileExists(local_244);
            if cVar2 then begin
              local_244 := PASTA + 'fundotocando.jpg';
              Form1.ImageTocando.Picture.LoadFromFile(local_244);
              TOCANDOMUSICAGRATIS := 0;
              Form1.ImageTocando.Show;
            end;
          end;
          Form1.ImageCDTocando.Show;
          Form1.ImageCDTocando.Picture.LoadFromFile(NOMECAPACDTOCANDO);
          Form1.LabelNomedaMusicaTocando.Caption := NOMEDAMUSICATOCANDO;
          // C: CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING (Form1.LabelNomedaMusicaTocando,&local_24c);
          Form1.LabelNomedaMusicaTocando1.Caption := local_24c;
          if TOCANDOTIPO = 'CD' then begin
            Form1.PanelCDTocando.Show;
          end
          else begin
            if EXIBIRVIDEOSNO = 'MONITOR' then begin
              Form1.PanelCDTocando.Hide;
            end
            else begin
              Form1.PanelCDTocando.Show;
            end;
          end;
          // C: fpc_ansistr_copy(U_JUKELINUX1_TEXTOTOCAR2,1,1);
          // C: iVar6 = fpc_ansistr_compare_equal(local_244,"*");
          iVar4 := TOTALFRASE;
          if iVar6 = 0 then begin
            KFRASE := 1;
            if 0 < TOTALFRASE then begin
              KFRASE := 0;
              repeat
                KFRASE := KFRASE + 1;
                local_268 := 'Voce Esta Ouvindo a MUSICA GRATIS: ';
                local_264 := NOMEDAMUSICATOCANDO;
                local_260 := '   do   ';
                local_25c := TOCANDOTIPO;
                // C: local_258 = "  >> ";
                local_254 := NOMEDOCDTOCANDO;
                // C: local_250 = " << MUSICA GRATIS            ";
                // C: fpc_ansistr_concat_multi(U_JUKELINUX1_KFRASE * 4 + 0x9301bfc,&local_268,6);
              until not (KFRASE < iVar4);
            end;
          end
          else begin
            KFRASE := 1;
            if 0 < TOTALFRASE then begin
              KFRASE := 0;
              repeat
                KFRASE := KFRASE + 1;
                local_268 := 'Voce Esta Ouvindo a Musica: ';
                local_264 := NOMEDAMUSICATOCANDO;
                local_260 := '   do   ';
                local_25c := TOCANDOTIPO;
                // C: local_258 = "  >> ";
                local_254 := NOMEDOCDTOCANDO;
                // C: local_250 = " <<            ";
                // C: fpc_ansistr_concat_multi(U_JUKELINUX1_KFRASE * 4 + 0x9301bfc,&local_268,6);
              until not (KFRASE < iVar4);
            end;
          end;
          POSFRASE := 0;
          // C: iVar4 = fpc_ansistr_compare_equal(U_JUKELINUX1_LETRASEXE,"3MJ");
          if (iVar4 = 0) and (ESTANOMENU <> 0) then begin
            Form1.PanelMenu.Show;
            Form1.PanelMenu.BringToFront;
          end;
          QUANTIDADESDEMUSICASTOCADAS := QUANTIDADESDEMUSICASTOCADAS + 1;
          local_244 := PASTA + 'jukelinux.txt';
          local_368 := local_244;
          AssignFile(ARQTEXTO, local_368);
          Rewrite(ARQTEXTO);
          local_244 := Criptasuper2(JC_SERIALPENDRIVECON);
          Write(ARQTEXTO, local_244);
          Writeln(ARQTEXTO);
          local_36c := IntToStr(QUANTIDADESDEMUSICASTOCADAS);
          local_244 := Criptasuper2(local_36c);
          Write(ARQTEXTO, local_244);
          Writeln(ARQTEXTO);
          Flush(ARQTEXTO);
          CloseFile(ARQTEXTO);
        end
        else begin
          Form1.TimerTocar.Enabled := True;
        end;
      end
      else begin
        Form1.TimerTocar.Enabled := True;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERTOUCHSCREENTIMER$TOBJECT }
procedure TForm1.TimerTouchScreenTimer(Sender: TObject);
var
  local_38, local_3c: AnsiString;
  iVar1: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    if (((4 < P_INICIAL_X) and (P_INICIAL_X < 1161)) and (564 < P_INICIAL_Y)) and (P_INICIAL_Y < 761) then begin
      Le_Touchscreen_Final;
      // C: DEBUGSTART_JUKELINUX1();
      if (0 < P_DESLOCAMENTO_X) and (P_DESLOCAMENTO_X < 100) then begin
        Presstecla;
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        Form1.TimerPaginaMais.Enabled := True;
        SEGURANDOTECLA := SEGURANDOTECLA + 1;
      end;
      if (P_DESLOCAMENTO_X < 0) and (P_DESLOCAMENTO_X < -100) then begin
        Presstecla;
        TEMPOPALHINHA := 0;
        MUDOUDECDOUMUSICA := 1;
        Form1.TimerPaginaMenos.Enabled := True;
        SEGURANDOTECLA := SEGURANDOTECLA + 1;
      end;
    end;
    if (((429 < P_INICIAL_X) and (P_INICIAL_X < 971)) and (204 < P_INICIAL_Y)) and (P_INICIAL_Y < 561) then begin
      Le_Touchscreen_Final;
      // C: DEBUGSTART_JUKELINUX1();
      if 0 < P_DESLOCAMENTO_Y then begin
        if P_DESLOCAMENTO_Y div 27 = 1 then begin
          if False { C: 0xc < (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90] } then begin
            local_3c := IntToStr(MUSICASELECIONADATS);
            local_38 := 'MusicaSelecionadaTS=' + local_3c;
            Form1.Label7.Caption := local_38;
            local_3c := IntToStr(MUSICASELECIONADA);
            local_38 := 'MusicaSelecionada=' + local_3c;
            Form1.Label8.Caption := local_38;
            local_3c := IntToStr(MUSICASELECIONADAPOSTELA);
            local_38 := 'MusicaSelecionadaPosTela=' + local_3c;
            Form1.Label9.Caption := local_38;
            if 0 < MUSICASELECIONADATS then begin
              MUSICASELECIONADATS := MUSICASELECIONADATS + -1;
              if 12 < MUSICASELECIONADA then begin
                MUSICASELECIONADA := MUSICASELECIONADA + -11;
              end;
              MUSICASELECIONADAPOSTELA := 0;
              MUSICASELECIONADA := MUSICASELECIONADA + -1;
              Selecionamusica;
              Desselecionamusica_Todas;
              Form1.Label6.Caption := '*Entrou';
              local_3c := IntToStr(MUSICASELECIONADATS);
              local_38 := '*MusicaSelecionadaTS=' + local_3c;
              Form1.Label7.Caption := local_38;
              local_3c := IntToStr(MUSICASELECIONADA);
              local_38 := '*MusicaSelecionada=' + local_3c;
              Form1.Label8.Caption := local_38;
              local_3c := IntToStr(MUSICASELECIONADAPOSTELA);
              local_38 := '*MusicaSelecionadaPosTela=' + local_3c;
              Form1.Label9.Caption := local_38;
            end;
            if MUSICASELECIONADATS < 0 then begin
              MUSICASELECIONADATS := 0;
            end;
          end;
          Le_Touchscreen_Inicial;
          // C: DEBUGSTART_JUKELINUX1();
        end;
      end;
      iVar1 := MUSICASELECIONADATS;
      if P_DESLOCAMENTO_Y < 0 then begin
        if P_DESLOCAMENTO_Y div 27 = -1 then begin
          if False { C: 0xc < (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90] } then begin
            MUSICASELECIONADATS := MUSICASELECIONADATS + 1;
            if MUSICASELECIONADA < 13 then begin
              MUSICASELECIONADA := 13;
            end
            else begin
              MUSICASELECIONADA := MUSICASELECIONADA + 1;
            end;
            if False { C: (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90] < U_JUKELINUX1_MUSICASELECIONADA } then begin
              MUSICASELECIONADA := MUSICASELECIONADA + -1;
              MUSICASELECIONADATS := iVar1;
            end;
            MUSICASELECIONADAPOSTELA := 12;
            Selecionamusica;
            Desselecionamusica_Todas;
            local_3c := IntToStr(MUSICASELECIONADATS);
            local_38 := 'MusicaSelecionadaTS=' + local_3c;
            Form1.Label7.Caption := local_38;
            local_3c := IntToStr(MUSICASELECIONADA);
            local_38 := 'MusicaSelecionada=' + local_3c;
            Form1.Label8.Caption := local_38;
            local_3c := IntToStr(MUSICASELECIONADAPOSTELA);
            local_38 := 'MusicaSelecionadaPosTela=' + local_3c;
            Form1.Label9.Caption := local_38;
            Form1.Label6.Caption := '';
          end;
          Le_Touchscreen_Inicial;
          // C: DEBUGSTART_JUKELINUX1();
        end;
      end;
    end;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERUMMILESEGUNDOTIMER$TOBJECT }
procedure TForm1.TimerUmMilesegundoTimer(Sender: TObject);
begin
  TEMPOEMMILLESEGUNDOS := TEMPOEMMILLESEGUNDOS + 1;
  if 30000 < TEMPOEMMILLESEGUNDOS then begin
    TEMPOEMMILLESEGUNDOS := 0;
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERUMMINUTOTIMER$TOBJECT }
procedure TForm1.TimerUmMinutoTimer(Sender: TObject);
var
  local_134, local_138: AnsiString;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  begin
    MINUTOSLIGADA := MINUTOSLIGADA + 1;
    local_138 := PASTA + 'minutosligada.txt';
    local_134 := local_138;
    AssignFile(ARQTEXTO, local_134);
    Rewrite(ARQTEXTO);
    local_138 := IntToStr(MINUTOSLIGADA);
    Write(ARQTEXTO, local_138);
    Writeln(ARQTEXTO);
    Flush(ARQTEXTO);
    CloseFile(ARQTEXTO);
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERVOLUME22HSTIMER$TOBJECT }
procedure TForm1.TimerVolume22hsTimer(Sender: TObject);
var
  local_13c, local_140, local_144, local_3c: AnsiString;
  iVar1, uVar2: LongInt;
  local_c: TForm1;
  local_8: TObject;
begin
  local_c := Self;
  local_8 := Sender;
  // C: iVar1 = fpc_setjmp();
  if (iVar1 = 0) and (0 < LIMITARVOLUME) then begin
    if LIMITARVOLUME < VOLUME then begin
      // C: puVar4 = local_38;
      local_3c := TimeToStr(Time);
      // C: fpc_ansistr_copy(local_3c,1,2,puVar4);
      // C: uVar2 = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT(local_38[0],0x14);
      if (uVar2 < 9) or (uVar2 - 22 < 2) then begin
        local_3c := PASTA + 'VolumeAntesdas22.Txt';
        local_13c := local_3c;
        AssignFile(ARQTEXTO, local_13c);
        Rewrite(ARQTEXTO);
        local_3c := IntToStr(VOLUME);
        Write(ARQTEXTO, local_3c);
        Writeln(ARQTEXTO);
        Flush(ARQTEXTO);
        CloseFile(ARQTEXTO);
        VOLUME := LIMITARVOLUME;
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_LIMITARVOLUME + -1);
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + 1);
        VOLUMELIMITADO := 1;
        if RESOLUCAO = 1366 then begin
          local_3c := IntToStr(LIMITARVOLUME);
          Mensagemjpg('mensagem1366-volumelimitado.jpg', 5, local_3c);
        end;
        if RESOLUCAO = 1440 then begin
          local_3c := IntToStr(LIMITARVOLUME);
          Mensagemjpg('mensagem1366-volumelimitado.jpg', 5, local_3c);
        end;
        if RESOLUCAO = 1024 then begin
          local_3c := IntToStr(LIMITARVOLUME);
          Mensagemjpg('mensagem1024-volumelimitado.jpg', 5, local_3c);
        end;
      end;
    end
    else if VOLUMELIMITADO <> 0 then begin
      // C: puVar4 = &local_3c;
      local_140 := TimeToStr(Time);
      // C: fpc_ansistr_copy(local_140,1,2,puVar4);
      // C: uVar2 = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT(local_3c,0x14);
      if (8 < uVar2) and (1 < uVar2 - 22) then begin
        local_140 := PASTA + 'VolumeAntesdas22.Txt';
        local_13c := local_140;
        AssignFile(ARQTEXTO, local_13c);
        Reset(ARQTEXTO);
        Read(ARQTEXTO, TEXTO);
        Readln(ARQTEXTO);
        CloseFile(ARQTEXTO);
        local_144 := PASTA + 'VolumeAntesdas22.Txt';
        // C: puVar3 = local_144;
        if False { C: local_144 == (undefined1 * )0x0 } then begin
        end;
        // C: fpc_pchar_to_ansistr(puVar3,&local_140);
        DeleteFile(local_140);
        VOLUME := StrToIntDef(TEXTO, 50);
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + -1);
        // C: MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT (Form1.Play,U_JUKELINUX1_VOLUME + 1);
        VOLUMELIMITADO := 0;
        if RESOLUCAO = 1366 then begin
          Mensagemjpg('mensagem1366-volumeliberado.jpg', 0, '');
        end;
        if RESOLUCAO = 1440 then begin
          Mensagemjpg('mensagem1366-volumeliberado.jpg', 0, '');
        end;
        if RESOLUCAO = 1024 then begin
          Mensagemjpg('mensagem1024-volumeliberado.jpg', 0, '');
        end;
      end;
    end;
  end;
  if iVar1 <> 0 then begin
  end;
end;

{ JUKELINUX1_TFORM1_$__TIMERVOLUMEMAISTIMER$TOBJECT }
procedure TForm1.TimerVolumeMaisTimer(Sender: TObject);
begin
  Rotina_Volumemais;
end;

{ JUKELINUX1_TFORM1_$__TIMERVOLUMEMENOSTIMER$TOBJECT }
procedure TForm1.TimerVolumeMenosTimer(Sender: TObject);
begin
  Rotina_Volumemenos;
end;
