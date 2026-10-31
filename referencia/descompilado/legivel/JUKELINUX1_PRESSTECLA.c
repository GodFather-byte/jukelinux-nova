// JUKELINUX1_PRESSTECLA  @ 080955e0

void JUKELINUX1_PRESSTECLA(void)

{
  int iVar1;
  
  U_JUKELINUX1_TEMPOEMSEGUNDOS = 0;
  U_JUKELINUX1_TEMPOEMSEGUNDOSPAGINARSOZINHO = 0;
  if (U_JUKELINUX1_LIMPAMSG != '\0') {
    (**(code **)(*Form1.LabelMusTot + 0xdc))();
  }
  if (U_JUKELINUX1_LIMPAMSG == '\0') {
    (**(code **)(*Form1.LabelMusTot + 0xdc))();
  }
  if (U_JUKELINUX1_TOCANDOMUSICA != '\0') {
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      iVar1 = fpc_ansistr_compare_equal();
      if (iVar1 == 0) {
        if (*(int *)(Form1.PanelCarregarMusica + 0x128) == 0) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
          CONTROLS_TCONTROL____SETTOP_LONGINT();
          CONTROLS_TCONTROL____SETWIDTH_LONGINT();
          CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
          (**(code **)(*Form1.PanelCarregarMusica + 0x10c))();
          CONTROLS_TCONTROL____SHOW();
          (**(code **)(*Form1.LabelMusR + 0xd8))();
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xd8))();
          (**(code **)(*Form1.LabelUpgradetit + 0xd8))();
          (**(code **)(*Form1.LabelPress1 + 0xdc))();
          (**(code **)(*Form1.LabelPress1 + 0xd8))();
          (**(code **)(*Form1.LabelPress1 + 0xdc))();
          (**(code **)(*Form1.LabelPress1 + 0xd8))();
          U_JUKELINUX1_ESTAEMTELACHEIA = 0;
        }
        else {
          (**(code **)(*Form1.LabelPress1 + 0xd8))();
          (**(code **)(*Form1.LabelPress1 + 0xdc))();
          (**(code **)(*Form1.LabelPress1 + 0xd8))();
        }
      }
    }
  }
  return;
}

