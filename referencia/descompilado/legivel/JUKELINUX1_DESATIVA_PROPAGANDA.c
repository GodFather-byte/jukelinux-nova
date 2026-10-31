// JUKELINUX1_DESATIVA_PROPAGANDA  @ 080abfc0

void JUKELINUX1_DESATIVA_PROPAGANDA(void)

{
  int iVar1;
  
  (**(code **)(*Form1.ImageMusR + 0xd8))();
  iVar1 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
  if (0 < iVar1) {
    (**(code **)(*Form1.LabelUF1 + 0xd8))();
    MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
    CONTROLS_TCONTROL____HIDE();
    U_JUKELINUX1_TOCANDOVIDEOTV = 0;
  }
  iVar1 = fpc_ansistr_compare_equal();
  if (iVar1 == 0) {
    CONTROLS_TCONTROL____HIDE();
  }
  iVar1 = fpc_ansistr_compare_equal();
  if (iVar1 == 0) {
    CONTROLS_TCONTROL____HIDE();
  }
  iVar1 = fpc_ansistr_compare_equal();
  if (iVar1 == 0) {
    CONTROLS_TCONTROL____HIDE();
  }
  iVar1 = fpc_ansistr_compare_equal();
  if (iVar1 == 0) {
    CONTROLS_TCONTROL____HIDE();
  }
  iVar1 = fpc_ansistr_compare_equal();
  if (iVar1 == 0) {
    CONTROLS_TCONTROL____HIDE();
  }
  if ((U_JUKELINUX1_ESTANOMENU == '\0') && (U_JUKELINUX1_TOCANDOMUSICADVD == '\0')) {
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      U_JUKELINUX1_TOCANDOVIDEOTV = 0;
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*Form1.ImageMusR + 0xd8))();
    }
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      U_JUKELINUX1_TOCANDOVIDEOTV = 0;
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*Form1.ImageMusR + 0xd8))();
    }
  }
  return;
}

