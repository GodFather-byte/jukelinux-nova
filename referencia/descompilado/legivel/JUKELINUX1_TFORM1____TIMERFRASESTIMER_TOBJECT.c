// JUKELINUX1_TFORM1_$__TIMERFRASESTIMER$TOBJECT  @ 080e14e0

void JUKELINUX1_TFORM1____TIMERFRASESTIMER_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    U_JUKELINUX1_POSFRASE = U_JUKELINUX1_POSFRASE + 1;
    if (U_JUKELINUX1_TOTALFRASE < U_JUKELINUX1_POSFRASE) {
      U_JUKELINUX1_POSFRASE = 1;
    }
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    (**(code **)(*Form1.PanelMusRelogio + 0xd8))();
    (**(code **)(*Form1.LabelMusR + 0xd8))();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

