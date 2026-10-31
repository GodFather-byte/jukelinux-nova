// JUKELINUX1_ROTINA_CANCELAR  @ 080ac460

void JUKELINUX1_ROTINA_CANCELAR(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  fpc_pushexceptaddr();
  iVar5 = fpc_setjmp();
  if (iVar5 == 0) {
    U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
    cVar4 = MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAYING__BOOLEAN();
    if (cVar4 != '\0') {
      JUKELINUX1_PRESSTECLA();
      if (U_JUKELINUX1_TOCANDOMUSICAGRATIS == '\0') {
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        JUKELINUX1_GRAVALOG_ANSISTRING();
      }
      else {
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        JUKELINUX1_GRAVALOG_ANSISTRING();
      }
      (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb8c) + 0xd8))();
      MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
      CONTROLS_TCONTROL____HIDE();
      U_JUKELINUX1_TOCANDOMUSICA = 0;
      U_JUKELINUX1_TOCANDOMUSICADVD = 0;
      U_JUKELINUX1_TOCANDOMUSICAGRATIS = '\0';
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
      (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb90) + 0xd8))();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar5 != 0) {
    fpc_reraise();
  }
  return;
}

