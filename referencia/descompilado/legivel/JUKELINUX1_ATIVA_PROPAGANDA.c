// JUKELINUX1_ATIVA_PROPAGANDA  @ 080ac1b0

void JUKELINUX1_ATIVA_PROPAGANDA(void)

{
  int iVar1;
  int iVar2;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    if (U_JUKELINUX1_TOCANDOMUSICA == '\0') {
      iVar2 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
      if (0 < iVar2) {
        U_JUKELINUX1_TOCANDOVIDEOTV = 0;
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
    }
    else {
      iVar2 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
      if (0 < iVar2) {
        (**(code **)(*Form1.LabelUF1 + 0xd8))();
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
        CONTROLS_TCONTROL____HIDE();
        U_JUKELINUX1_TOCANDOVIDEOTV = 0;
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
    }
    (**(code **)(*Form1.ImageMusR + 0xd8))();
    if (U_JUKELINUX1_TOTALPRO == 0) {
      (**(code **)(*Form1.ImageMusR + 0xd8))();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar1,0);
      JUKELINUX1_GRAVALOG_ANSISTRING();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

