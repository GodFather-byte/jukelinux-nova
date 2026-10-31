// JUKELINUX1_ROTINA_MENU  @ 080ae810

void JUKELINUX1_ROTINA_MENU(void)

{
  char cVar1;
  int *piVar2;
  longdouble lVar3;
  undefined8 local_178;
  undefined4 *puStack_170;
  undefined8 local_16c;
  int iStack_164;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_4c;
  undefined4 local_48;
  undefined *local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_58 = 0;
  local_54 = 0;
  local_34 = 0;
  local_30 = 0;
  iStack_164 = 0x80ae852;
  fpc_pushexceptaddr();
  iStack_164 = 0x80ae857;
  iStack_164 = fpc_setjmp();
  piVar2 = &iStack_164;
  if (iStack_164 == 0) {
    if (U_JUKELINUX1_ESTANOMENU == '\0') {
      local_16c = (double)CONCAT44(0x80ae872,(undefined4)local_16c);
      JUKELINUX1_PRESSTECLA();
      piVar2 = &iStack_164;
      if (U_JUKELINUX1_ESTADIGITANDOSENHA == 0) {
        U_JUKELINUX1_ZERA50 = 0;
        U_JUKELINUX1_ESTANOMENU = '\x01';
        local_16c = (double)CONCAT44(0x80ae895,(undefined4)local_16c);
        JUKELINUX1_DESATIVA_PROPAGANDA();
        U_JUKELINUX1_ALTEROUPRO = '\0';
        U_JUKELINUX1_RELECDS = '\0';
        U_JUKELINUX1_PRESS2XPARAZERAR = 0;
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          local_16c = (double)CONCAT44(0x80ae8c1,(undefined4)local_16c);
          fpc_ansistr_decr_ref();
          local_30 = 0;
          local_16c = (double)CONCAT44(0x80ae8db,(undefined4)local_16c);
          fpc_ansistr_concat();
          local_16c = (double)CONCAT44(0x80ae8e3,(undefined4)local_16c);
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            local_16c = (double)CONCAT44(0x80ae8ef,(undefined4)local_16c);
            fpc_ansistr_decr_ref();
            local_30 = 0;
            local_16c = (double)CONCAT44(0x80ae909,(undefined4)local_16c);
            fpc_ansistr_concat();
            local_16c = (double)CONCAT44(0x80ae922,(undefined4)local_16c);
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          local_16c = (double)CONCAT44(0x80ae936,(undefined4)local_16c);
          fpc_ansistr_decr_ref();
          local_30 = 0;
          local_16c = (double)CONCAT44(0x80ae950,(undefined4)local_16c);
          fpc_ansistr_concat();
          local_16c = (double)CONCAT44(0x80ae958,(undefined4)local_16c);
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            local_16c = (double)CONCAT44(0x80ae964,(undefined4)local_16c);
            fpc_ansistr_decr_ref();
            local_30 = 0;
            local_16c = (double)CONCAT44(0x80ae97e,(undefined4)local_16c);
            fpc_ansistr_concat();
            local_16c = (double)CONCAT44(0x80ae997,(undefined4)local_16c);
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          local_16c = (double)CONCAT44(0x80ae9ab,(undefined4)local_16c);
          fpc_ansistr_decr_ref();
          local_30 = 0;
          local_16c = (double)CONCAT44(0x80ae9c5,(undefined4)local_16c);
          fpc_ansistr_concat();
          local_16c = (double)CONCAT44(0x80ae9cd,(undefined4)local_16c);
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            local_16c = (double)CONCAT44(0x80ae9d9,(undefined4)local_16c);
            fpc_ansistr_decr_ref();
            local_30 = 0;
            local_16c = (double)CONCAT44(0x80ae9f3,(undefined4)local_16c);
            fpc_ansistr_concat();
            local_16c = (double)CONCAT44(0x80aea0c,(undefined4)local_16c);
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
        local_16c = (double)CONCAT44(0x80aea30,(undefined4)local_16c);
        (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x1fa] + 0x104))();
        local_16c = (double)CONCAT44(0x80aea45,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        local_16c = (double)CONCAT44(0x80aea5a,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        local_16c = (double)CONCAT44(0x80aea70,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        local_16c = (double)CONCAT44(0x80aea86,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        local_16c = (double)CONCAT44(0x80aea96,(undefined4)local_16c);
        CONTROLS_TCONTROL____HIDE();
        local_16c = (double)CONCAT44(0x80aeaa6,(undefined4)local_16c);
        CONTROLS_TCONTROL____HIDE();
        U_JUKELINUX1_CREDITOSTESTE = 0;
        local_16c = (double)CONCAT44(0x80aeac0,(undefined4)local_16c);
        CONTROLS_TCONTROL____HIDE();
        local_16c = (double)CONCAT44(0x80aead5,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        local_16c = (double)CONCAT44(0x80aeaea,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        local_16c = (double)CONCAT44(0x80aeafa,(undefined4)local_16c);
        CONTROLS_TCONTROL____SHOW();
        local_16c = (double)CONCAT44(0x80aeb10,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        local_16c = (double)CONCAT44(0x80aeb18,(undefined4)local_16c);
        fpc_ansistr_decr_ref();
        local_34 = 0;
        local_40 = U_JUKELINUX1_LETRASEXE;
        local_3c = &__JUKELINUX1__Ld10;
        local_38 = U_JUKELINUX1_JC_CODIGODAMAQUINA;
        local_16c = (double)CONCAT44(0x80aeb47,(undefined4)local_16c);
        fpc_ansistr_concat_multi();
        local_16c = (double)CONCAT44(0x80aeb5a,(undefined4)local_16c);
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        local_16c = (double)CONCAT44(0x80aeb62,(undefined4)local_16c);
        fpc_ansistr_decr_ref();
        local_34 = 0;
        local_16c = (double)CONCAT44(0x80aeb71,(undefined4)local_16c);
        fpc_ansistr_decr_ref();
        local_54 = 0;
        local_16c = (double)CONCAT44(0x80aeb7d,(undefined4)local_16c);
        lVar3 = (longdouble)SYSUTILS_DATE__TDATETIME();
        local_16c = (double)lVar3;
        puStack_170 = (undefined4 *)0x80aeb8b;
        SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
        local_50 = local_54;
        local_4c = &__JUKELINUX1__Ld236;
        puStack_170 = (undefined4 *)0x80aeba1;
        fpc_ansistr_decr_ref();
        local_58 = 0;
        puStack_170 = &local_58;
        local_178 = (double)CONCAT44(0x80aebb4,(undefined4)local_178);
        fpc_ansistr_decr_ref();
        local_178 = (double)CONCAT44(0x80aebc0,(undefined4)local_178);
        lVar3 = (longdouble)SYSUTILS_TIME__TDATETIME();
        local_178 = (double)lVar3;
        SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
        fpc_ansistr_copy();
        local_48 = local_58;
        local_44 = &__JUKELINUX1__Ld237;
        fpc_ansistr_concat_multi();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        JUKELINUX1_VOLTAMENU();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        U_JUKELINUX1_SENHAOK = 1;
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
          CONTROLS_TCONTROL____SETTOP_LONGINT();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
          CONTROLS_TCONTROL____SETTOP_LONGINT();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
          CONTROLS_TCONTROL____SETTOP_LONGINT();
        }
        if (U_JUKELINUX1_CHAVEDEINSTALACAO == '\0') {
          CONTROLS_TCONTROL____HIDE();
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          CONTROLS_TCONTROL____SHOW();
          CONTROLS_TCONTROL____SHOW();
        }
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____HIDE();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____SHOW();
        (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x1d5] + 0x430))();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        JUKELINUX1_TFORM1____PANELMENU2CLICK_TOBJECT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____HIDE();
        if (U_JUKELINUX1_SEMQRCODE == '\0') {
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
        else {
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
        CONTROLS_TCONTROL____REFRESH();
        (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
        JUKELINUX1_TFORM1____BUTTONQRCLICK_TOBJECT();
        U_JUKELINUX1_ESTADIGITANDOSENHA = 1;
        piVar2 = (int *)&local_178;
      }
    }
    else {
      if (U_JUKELINUX1_ESTADIGITANDOSENHA == 2) {
        U_JUKELINUX1_SENHAOK = 0;
        if (U_JUKELINUX1_RELECDS != '\0') {
          local_16c = (double)CONCAT44(0x80aef24,(undefined4)local_16c);
          JUKELINUX1_MOSTRA_TELA_CARREGANDO_CDS();
          local_16c = (double)CONCAT44(0x80aef39,(undefined4)local_16c);
          fpc_ansistr_concat();
          local_16c = (double)CONCAT44(0x80aef43,(undefined4)local_16c);
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 == '\0') {
            local_16c = (double)CONCAT44(0x80aef5d,(undefined4)local_16c);
            FPC_ANSISTR_TO_SHORTSTR();
            local_16c = (double)CONCAT44(0x80aef6d,(undefined4)local_16c);
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            local_16c = (double)CONCAT44(0x80aef77,(undefined4)local_16c);
            SYSTEM_REWRITE_TEXT();
            local_16c = (double)CONCAT44(0x80aef7c,(undefined4)local_16c);
            fpc_iocheck();
            local_16c = (double)CONCAT44(0x80aef86,(undefined4)local_16c);
            SYSTEM_FLUSH_TEXT();
            local_16c = (double)CONCAT44(0x80aef8b,(undefined4)local_16c);
            fpc_iocheck();
            local_16c = (double)CONCAT44(0x80aef95,(undefined4)local_16c);
            OBJPAS_CLOSEFILE_TEXT();
            local_16c = (double)CONCAT44(0x80aef9a,(undefined4)local_16c);
            fpc_iocheck();
          }
          local_16c = (double)CONCAT44(0x80aefa4,(undefined4)local_16c);
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            local_16c = (double)CONCAT44(0x80aefd7,(undefined4)local_16c);
            (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x27e] + 0x364) + 0xb8))();
            local_16c = (double)CONCAT44(0x80aefed,(undefined4)local_16c);
            FPC_ANSISTR_TO_SHORTSTR();
            local_16c = (double)CONCAT44(0x80aeffd,(undefined4)local_16c);
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            local_16c = (double)CONCAT44(0x80af007,(undefined4)local_16c);
            SYSTEM_RESET_TEXT();
            local_16c = (double)CONCAT44(0x80af00c,(undefined4)local_16c);
            fpc_iocheck();
            while( true ) {
              local_16c = (double)CONCAT44(0x80af078,(undefined4)local_16c);
              cVar1 = SYSTEM_EOF_TEXT__BOOLEAN();
              local_16c = (double)CONCAT44(0x80af07f,(undefined4)local_16c);
              fpc_iocheck();
              if (cVar1 != '\0') break;
              local_16c = (double)CONCAT44(0x80af01a,(undefined4)local_16c);
              fpc_ansistr_decr_ref();
              local_16c = (double)CONCAT44(0x80af029,(undefined4)local_16c);
              fpc_read_text_ansistr();
              local_16c = (double)CONCAT44(0x80af02e,(undefined4)local_16c);
              fpc_iocheck();
              local_16c = (double)CONCAT44(0x80af038,(undefined4)local_16c);
              fpc_readln_end();
              local_16c = (double)CONCAT44(0x80af03d,(undefined4)local_16c);
              fpc_iocheck();
              local_16c = (double)CONCAT44(0x80af06e,(undefined4)local_16c);
              (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x27e] + 0x364) + 0xa4))();
            }
            local_16c = (double)CONCAT44(0x80af08d,(undefined4)local_16c);
            OBJPAS_CLOSEFILE_TEXT();
            local_16c = (double)CONCAT44(0x80af092,(undefined4)local_16c);
            fpc_iocheck();
          }
          local_16c = (double)CONCAT44(0x80af0b3,(undefined4)local_16c);
          (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x272] + 0x220))();
          local_16c = (double)CONCAT44(0x80af0b8,(undefined4)local_16c);
          JUKELINUX1_CARREGANDO_CDS();
          local_16c = (double)CONCAT44(0x80af0d9,(undefined4)local_16c);
          (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x272] + 0x220))();
          local_16c = (double)CONCAT44(0x80af0e9,(undefined4)local_16c);
          CONTROLS_TCONTROL____HIDE();
          U_JUKELINUX1_KMAT = 0xfffffffc;
          U_JUKELINUX1_MUSICASELECIONADA = 0;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
          U_JUKELINUX1_MUSICASELECIONADATS = 0;
          if (U_JUKELINUX1_RESOLUCAO == 0x556) {
            U_JUKELINUX1_TAMANHOMUSICAGRANDE = 0x1e;
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x400) {
            U_JUKELINUX1_TAMANHOMUSICAGRANDE = 0x16;
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
            U_JUKELINUX1_TAMANHOMUSICAGRANDE = 0x1e;
          }
          U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          U_JUKELINUX1_MOSTRANDORITMOS = 0;
          U_JUKELINUX1_MOSTRANDOLETRAS = 0;
          local_16c = (double)CONCAT44(0x80af175,(undefined4)local_16c);
          JUKELINUX1_MOSTRA_CDS_ANSISTRING();
          local_16c = (double)CONCAT44(0x80af17a,(undefined4)local_16c);
          JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS();
          local_16c = (double)CONCAT44(0x80af17f,(undefined4)local_16c);
          JUKELINUX1_MOSTRA_FILA();
          local_16c = (double)CONCAT44(0x80af1a0,(undefined4)local_16c);
          (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e5] + 0xd8))();
        }
        local_16c = (double)CONCAT44(0x80af1c1,(undefined4)local_16c);
        (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2de] + 0xd8))();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_ESTANOMENU = '\0';
        U_JUKELINUX1_ESTADIGITANDOSENHA = 0;
        local_16c = (double)CONCAT44(0x80af1ec,(undefined4)local_16c);
        CONTROLS_TCONTROL____HIDE();
        if (U_JUKELINUX1_ALTEROUPRO != '\0') {
          local_16c = (double)CONCAT44(0x80af1fa,(undefined4)local_16c);
          JUKELINUX1_CARREGANDO_PROPAGANDAS();
        }
        local_16c = (double)CONCAT44(0x80af1ff,(undefined4)local_16c);
        JUKELINUX1_ATIVA_PROPAGANDA();
      }
      piVar2 = &iStack_164;
      if (U_JUKELINUX1_ESTADIGITANDOSENHA == 1) {
        local_16c = (double)CONCAT44(0x80af219,(undefined4)local_16c);
        JUKELINUX1_TFORM1____LABELENTRARNOMENUCLICK_TOBJECT();
        piVar2 = &iStack_164;
      }
    }
  }
  piVar2[-1] = 0x80af21e;
  fpc_popaddrstack();
  piVar2[-1] = 0x80af226;
  fpc_ansistr_decr_ref();
  piVar2[-1] = 0x80af235;
  fpc_ansistr_decr_ref();
  local_58 = 0;
  piVar2[-1] = 0x80af244;
  fpc_ansistr_decr_ref();
  local_54 = 0;
  piVar2[-1] = 0x80af253;
  fpc_ansistr_decr_ref();
  local_34 = 0;
  piVar2[-1] = 0x80af262;
  fpc_ansistr_decr_ref();
  local_30 = 0;
  if (*piVar2 != 0) {
    *piVar2 = 0x80af273;
    fpc_reraise();
  }
  return;
}

