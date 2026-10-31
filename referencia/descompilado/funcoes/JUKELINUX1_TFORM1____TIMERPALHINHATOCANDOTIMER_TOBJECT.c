// JUKELINUX1_TFORM1_$__TIMERPALHINHATOCANDOTIMER$TOBJECT  @ 080e3a90

void JUKELINUX1_TFORM1____TIMERPALHINHATOCANDOTIMER_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 0;
  fpc_pushexceptaddr(0,0,0);
  iVar1 = fpc_setjmp();
  if (iVar1 != 0) goto LAB_080e3d22;
  (**(code **)(**(int **)(in_EAX + 0xb60) + 0xd8))();
  if (U_JUKELINUX1_TOCANDOPALHINHA == '\0') goto LAB_080e3d22;
  U_JUKELINUX1_CONTADORTEMPOPALHINHA = U_JUKELINUX1_CONTADORTEMPOPALHINHA + 1;
  fpc_ansistr_decr_ref();
  SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
  CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
  if (((int)(U_JUKELINUX1_CONTADORTEMPOPALHINHA + (U_JUKELINUX1_CONTADORTEMPOPALHINHA >> 0x1f & 1U))
       >> 1 < U_JUKELINUX1_TEMPODEINTRODUCAOMUSICAL) && (U_JUKELINUX1_MUDOUDECDOUMUSICA == '\0')) {
    (**(code **)(**(int **)(in_EAX + 0xb60) + 0xd8))();
    goto LAB_080e3d22;
  }
  MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
  CONTROLS_TCONTROL____HIDE();
  U_JUKELINUX1_TOCANDOPALHINHA = 0;
  CONTROLS_TCONTROL____HIDE();
  CONTROLS_TCONTROL____HIDE();
  CONTROLS_TCONTROL____HIDE();
  CONTROLS_TCONTROL____HIDE();
  (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
  fpc_ansistr_decr_ref();
  uVar4 = 0;
  fpc_ansistr_decr_ref(iVar1,uVar3,0);
  uVar3 = 0;
  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING(iVar1,0);
  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
LAB_080e3caf:
    JUKELINUX1_ATIVA_PROPAGANDA();
  }
  else {
    fpc_ansistr_decr_ref(iVar1,uVar3,uVar4);
    uVar3 = 0;
    fpc_ansistr_decr_ref(iVar1,0);
    SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING(iVar1,uVar3,0);
    SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) goto LAB_080e3caf;
    fpc_ansistr_decr_ref();
    uVar3 = 0;
    fpc_ansistr_decr_ref(iVar1,0);
    SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING(iVar1,uVar3,0);
    SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) goto LAB_080e3caf;
  }
  U_JUKELINUX1_TOCANDOPALHINHA = '\0';
  (**(code **)(**(int **)(in_EAX + 0xb60) + 0xd8))();
  U_JUKELINUX1_TEMPOPALHINHA = 0;
  U_JUKELINUX1_MUDOUDECDOUMUSICA = '\0';
  (**(code **)(**(int **)(in_EAX + 0xb64) + 0xd8))();
LAB_080e3d22:
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar3 = 0;
  fpc_ansistr_decr_ref(iVar1,0);
  uVar4 = 0;
  fpc_ansistr_decr_ref(iVar1,uVar3,0);
  if (iVar1 != 0) {
    fpc_reraise(uVar3,uVar4,0);
  }
  return;
}

