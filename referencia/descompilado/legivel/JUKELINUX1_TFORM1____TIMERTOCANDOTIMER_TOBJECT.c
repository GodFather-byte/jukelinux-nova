// JUKELINUX1_TFORM1_$__TIMERTOCANDOTIMER$TOBJECT  @ 080e5cf0

void JUKELINUX1_TFORM1____TIMERTOCANDOTIMER_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int in_EAX;
  int iVar5;
  
  fpc_pushexceptaddr();
  iVar5 = fpc_setjmp();
  if (iVar5 == 0) {
    cVar4 = MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____RUNNING__BOOLEAN();
    if (cVar4 == '\0') {
      JUKELINUX1_PRESSTECLA();
      (**(code **)(*Form1.LabelPress2 + 0xd8))();
      MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
      CONTROLS_TCONTROL____HIDE();
      U_JUKELINUX1_TOCANDOMUSICA = 0;
      U_JUKELINUX1_TOCANDOMUSICADVD = 0;
      U_JUKELINUX1_TOCANDOMUSICAGRATIS = 0;
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      JUKELINUX1_ATIVA_PROPAGANDA();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
      fpc_ansistr_decr_ref();
      iVar3 = U_JUKELINUX1_TOTALFRASE;
      U_JUKELINUX1_TOCANDOTIPO = 0;
      U_JUKELINUX1_KFRASE = 1;
      if (0 < U_JUKELINUX1_TOTALFRASE) {
        U_JUKELINUX1_KFRASE = 0;
        do {
          U_JUKELINUX1_KFRASE = U_JUKELINUX1_KFRASE + 1;
          iVar1 = U_JUKELINUX1_KFRASE;
          fpc_ansistr_incr_ref();
          iVar2 = U_JUKELINUX1_KFRASE;
          fpc_ansistr_decr_ref();
          *(undefined4 *)(U_JUKELINUX1_ARQTOCARX + iVar2 * 4 + 0x24c) =
               *(undefined4 *)(iVar1 * 4 + 0x9301ccc);
        } while (U_JUKELINUX1_KFRASE < iVar3);
      }
      U_JUKELINUX1_POSFRASE = 0;
      (**(code **)(*Form1.LabelNaoQR + 0xd8))();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar5 != 0) {
    fpc_reraise();
  }
  return;
}

