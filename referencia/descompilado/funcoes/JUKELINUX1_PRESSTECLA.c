// JUKELINUX1_PRESSTECLA  @ 080955e0

void JUKELINUX1_PRESSTECLA(void)

{
  int iVar1;
  
  U_JUKELINUX1_TEMPOEMSEGUNDOS = 0;
  U_JUKELINUX1_TEMPOEMSEGUNDOSPAGINARSOZINHO = 0;
  if (U_JUKELINUX1_LIMPAMSG != '\0') {
    (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xba0) + 0xdc))();
  }
  if (U_JUKELINUX1_LIMPAMSG == '\0') {
    (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xba0) + 0xdc))();
  }
  if (U_JUKELINUX1_TOCANDOMUSICA != '\0') {
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      iVar1 = fpc_ansistr_compare_equal();
      if (iVar1 == 0) {
        if (*(int *)(*(int *)(U_JUKELINUX1_FORM1 + 0xa84) + 0x128) == 0) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
          CONTROLS_TCONTROL____SETTOP_LONGINT();
          CONTROLS_TCONTROL____SETWIDTH_LONGINT();
          CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xa84) + 0x10c))();
          CONTROLS_TCONTROL____SHOW();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb9c) + 0xd8))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb94) + 0xd8))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbbc) + 0xd8))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb88) + 0xd8))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb88) + 0xd8))();
          U_JUKELINUX1_ESTAEMTELACHEIA = 0;
        }
        else {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb88) + 0xd8))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb88) + 0xdc))();
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb88) + 0xd8))();
        }
      }
    }
  }
  return;
}

