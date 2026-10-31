// JUKELINUX1_TFORM1_$__TIMERABERTURATIMER$TOBJECT  @ 080e3fb0

void JUKELINUX1_TFORM1____TIMERABERTURATIMER_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    U_JUKELINUX1_TEMPOABERTURA = U_JUKELINUX1_TEMPOABERTURA + -1;
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    if (U_JUKELINUX1_TEMPOABERTURA == 0) {
      (**(code **)(*Form1.Timerabertura + 0xd8))();
      CONTROLS_TCONTROL____HIDE();
      JUKELINUX1_INICIA_TELA();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

