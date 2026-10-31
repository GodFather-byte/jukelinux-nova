// JUKELINUX1_TFORM1_$__TIMERPAGINAMAISTIMER$TOBJECT  @ 080e48b0

void JUKELINUX1_TFORM1____TIMERPAGINAMAISTIMER_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    (**(code **)(*Form1.TimerPaginaMenos + 0xd8))();
    U_JUKELINUX1_ENTROUROTINAPAGINACAO = '\0';
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + -1;
      if (U_JUKELINUX1_KMAT == -5) {
        U_JUKELINUX1_KMAT = -4;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_KMAT = U_JUKELINUX1_TOTALCDS + -5;
        }
        JUKELINUX1_DESSELECIONAMUSICA();
        U_JUKELINUX1_MUSICASELECIONADA = 0;
        U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
        U_JUKELINUX1_MUSICASELECIONADATS = 0;
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_concat();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
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
        U_JUKELINUX1_ENTROUROTINAPAGINACAO = '\x01';
      }
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_SETAVERMELHA = &__JUKELINUX1__Ld738;
      U_JUKELINUX1_MOSTROUSETAVERMELHA = 0;
      (**(code **)(*Form1.EditCredito2 + 0xdc))();
      (**(code **)(*Form1.EditCredito2 + 0xd8))();
    }
    iVar3 = fpc_ansistr_compare_equal();
    iVar2 = U_JUKELINUX1_KMAT;
    if (iVar3 == 0) {
      U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + 1;
      if (U_JUKELINUX1_TOTALCDS < iVar2 + 6) {
        U_JUKELINUX1_KMAT = iVar2;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_KMAT = -4;
        }
        JUKELINUX1_DESSELECIONAMUSICA();
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
        U_JUKELINUX1_ENTROUROTINAPAGINACAO = '\x01';
      }
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_SETAVERMELHA = &__JUKELINUX1__Ld737;
      U_JUKELINUX1_MOSTROUSETAVERMELHA = 0;
      (**(code **)(*Form1.EditCredito2 + 0xdc))();
      (**(code **)(*Form1.EditCredito2 + 0xd8))();
    }
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_ESTAPAGINANDOPARA = &__JUKELINUX1__Ld167;
    if (U_JUKELINUX1_ENTROUROTINAPAGINACAO == '\0') {
      JUKELINUX1_MOSTRA_CDS_ANSISTRING();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

