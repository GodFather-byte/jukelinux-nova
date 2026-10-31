// JUKELINUX1_TFORM1_$__TIMERTELACHEIATIMER$TOBJECT  @ 080e5ae0

void JUKELINUX1_TFORM1____TIMERTELACHEIATIMER_TOBJECT(void)

{
  int iVar1;
  
  iVar1 = fpc_ansistr_compare_equal();
  if (((iVar1 == 0) && (U_JUKELINUX1_TOCANDOMUSICA != '\0')) &&
     (*(int *)(Form1.PanelCarregarMusica + 0x128) == U_JUKELINUX1_POSL)) {
    JUKELINUX1_DESSELECIONAMUSICA();
    U_JUKELINUX1_MUSICASELECIONADA = 0;
    U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
    U_JUKELINUX1_MUSICASELECIONADATS = 0;
    JUKELINUX1_SELECIONAMUSICA();
    CONTROLS_TCONTROL____SETLEFT_LONGINT();
    CONTROLS_TCONTROL____SETTOP_LONGINT();
    CONTROLS_TCONTROL____SETWIDTH_LONGINT();
    CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
    CONTROLS_TCONTROL____BRINGTOFRONT();
    U_JUKELINUX1_ESTAEMTELACHEIA = 1;
    (**(code **)(*Form1.LabelPress1 + 0xdc))();
    (**(code **)(*Form1.LabelMusR + 0xd8))();
    (**(code **)(*Form1.LabelSairDoMenu2 + 0xd8))();
    (**(code **)(*Form1.LabelUpgradetit + 0xd8))();
    if (U_JUKELINUX1_TOCANDOMUSICA != '\0') {
      iVar1 = fpc_ansistr_compare_equal();
      if ((iVar1 == 0) && (U_JUKELINUX1_ESTANOMENU != '\0')) {
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
      }
    }
  }
  return;
}

