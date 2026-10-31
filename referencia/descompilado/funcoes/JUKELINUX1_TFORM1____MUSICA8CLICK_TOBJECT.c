// JUKELINUX1_TFORM1_$__MUSICA8CLICK$TOBJECT  @ 080c7520

void JUKELINUX1_TFORM1____MUSICA8CLICK_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    JUKELINUX1_DESSELECIONAMUSICA();
    iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
    U_JUKELINUX1_KTS = 1;
    if (0 < iVar1) {
      U_JUKELINUX1_KTS = 0;
      do {
        U_JUKELINUX1_KTS = U_JUKELINUX1_KTS + 1;
        fpc_ansistr_decr_ref();
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          U_JUKELINUX1_MUSICASELECIONADA = U_JUKELINUX1_KTS;
        }
      } while (U_JUKELINUX1_KTS < iVar1);
    }
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 8;
    JUKELINUX1_SELECIONAMUSICA();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

