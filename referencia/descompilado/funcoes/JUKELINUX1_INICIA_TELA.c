// JUKELINUX1_INICIA_TELA  @ 080af500

void JUKELINUX1_INICIA_TELA(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  fpc_pushexceptaddr(0);
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_DEFINE_EXIBIRVIDEOS();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_CARREGANDO_CARTOES();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_MOSTRA_TELA_CARREGANDO_CDS();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_CARREGANDO_CDS();
    CONTROLS_TCONTROL____SETTOP_LONGINT();
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x272] + 0x220))();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x272] + 0x220))();
    JUKELINUX1_CARREGANDO_KARAOKES();
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x272] + 0x220))();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      JUKELINUX1_TELA_DE_AUTOTESTE();
    }
    JUKELINUX1_GRAVALOG_ANSISTRING();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 != '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      fpc_pchar_to_ansistr();
      SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      DIALOGS_SHOWMESSAGE_ANSISTRING();
      FORMS_TCUSTOMFORM____CLOSE();
    }
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2f2] + 0xd8))();
    JUKELINUX1_TELA1();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    JUKELINUX1_CARREGANDO_PROPAGANDAS();
    JUKELINUX1_ATIVA_PROPAGANDA();
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
    JUKELINUX1_MOSTRA_CDS_ANSISTRING();
    JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS();
    JUKELINUX1_MOSTRA_FILA();
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e5] + 0xd8))();
    iVar3 = FPC_SHORTSTR_COMPARE_EQUAL();
    if (iVar3 != 0) {
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2df] + 0xd8))();
    }
    if (0 < U_JUKELINUX1_TOTALFRASE) {
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e6] + 0xd8))();
    }
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e4] + 0xd8))();
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e4] + 0xd8))();
    if (U_JUKELINUX1_TEMPOPARAPAGINARSOZINHO == 0) {
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e9] + 0xd8))();
    }
    else {
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e9] + 0xd8))();
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e0] + 0xd8))();
    }
    else {
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e0] + 0xd8))();
    }
    (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2dc] + 0xd8))();
    if ((U_JUKELINUX1_BLOQUEARQUANDOTOCAR != -1) &&
       (U_JUKELINUX1_BLOQUEARQUANDOTOCAR <= U_JUKELINUX1_QUANTIDADESDEMUSICASTOCADAS)) {
      if ((U_JUKELINUX1_QUANTIDADESDEMUSICASTOCADAS == 0) && (U_JUKELINUX1_BLOQUEARQUANDOTOCAR == 0)
         ) {
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
      else {
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref(iVar2,uVar4,__JUKELINUX1__Ld266);
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SETWIDTH_LONGINT();
      CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____BRINGTOFRONT();
      fpc_ansistr_decr_ref();
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar2,0);
      JUKELINUX1_GRAVALOG_ANSISTRING();
    }
    JUKELINUX1_GRAVALOG_ANSISTRING();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x430))();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref(iVar2,0);
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

