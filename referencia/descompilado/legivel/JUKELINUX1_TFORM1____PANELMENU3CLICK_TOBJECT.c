// JUKELINUX1_TFORM1_$__PANELMENU3CLICK$TOBJECT  @ 080e05a0

void JUKELINUX1_TFORM1____PANELMENU3CLICK_TOBJECT(void)

{
  int iVar1;
  int **ppiVar2;
  int *piStack_40;
  int aiStack_3c [14];
  
  aiStack_3c[1] = 0;
  aiStack_3c[0] = 0x80e05c3;
  fpc_pushexceptaddr();
  aiStack_3c[0] = 0x80e05c8;
  aiStack_3c[0] = fpc_setjmp();
  ppiVar2 = (int **)aiStack_3c;
  if ((aiStack_3c[0] == 0) && (ppiVar2 = (int **)aiStack_3c, U_JUKELINUX1_SENHAOK == 2)) {
    piStack_40 = (int *)0x80e05e4;
    JUKELINUX1_VOLTAMENU();
    piStack_40 = (int *)0x80e05f2;
    CONTROLS_TCONTROL____SHOW();
    piStack_40 = (int *)0x80e0600;
    CONTROLS_TCONTROL____SHOW();
    piStack_40 = (int *)0x80e060e;
    CONTROLS_TCONTROL____HIDE();
    piStack_40 = (int *)0x80e0621;
    CONTROLS_TCONTROL____SETLEFT_LONGINT();
    piStack_40 = (int *)0x80e0634;
    CONTROLS_TCONTROL____SETTOP_LONGINT();
    piStack_40 = (int *)0x80e0654;
    CONTROLS_TCONTROL____SETWIDTH_LONGINT();
    piStack_40 = (int *)0x80e0674;
    CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
    piStack_40 = (int *)0x80e0679;
    JUKELINUX1_LE_TOCADOS();
    U_JUKELINUX1_KMATEXCLUI = 1;
    piStack_40 = (int *)0x80e0688;
    JUKELINUX1_MOSTRA_CD_EXCLUSAO_LONGINT();
    piStack_40 = (int *)0x80e0690;
    fpc_ansistr_decr_ref();
    aiStack_3c[1] = 0;
    piStack_40 = aiStack_3c + 1;
    fpc_ansistr_copy();
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    else {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    CONTROLS_TCONTROL____HIDE();
    CONTROLS_TCONTROL____HIDE();
    CONTROLS_TCONTROL____HIDE();
    CONTROLS_TCONTROL____HIDE();
    CONTROLS_TCONTROL____SHOW();
    CONTROLS_TCONTROL____HIDE();
    CONTROLS_TCONTROL____HIDE();
    ppiVar2 = &piStack_40;
  }
  ppiVar2[-1] = (int *)0x80e074f;
  fpc_popaddrstack();
  ppiVar2[-1] = (int *)0x80e0757;
  fpc_ansistr_decr_ref();
  aiStack_3c[1] = 0;
  if (*ppiVar2 != (int *)0x0) {
    *ppiVar2 = (int *)0x80e0768;
    fpc_reraise();
  }
  return;
}

