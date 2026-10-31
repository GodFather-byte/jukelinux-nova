// JUKELINUX1_TFORM1_$__IMAGETELA1MOUSEDOWN$TOBJECT$TMOUSEBUTTON$TSHIFTSTATE$LONGINT$LONGINT  @ 080c5d00

void JUKELINUX1_TFORM1____IMAGETELA1MOUSEDOWN_TOBJECT_TMOUSEBUTTON_TSHIFTSTATE_LONGINT_LONGINT(void)

{
  int iVar1;
  int **ppiVar2;
  int *piStack_44;
  int aiStack_40 [12];
  int local_10;
  
  aiStack_40[1] = 0;
  aiStack_40[0] = 0x80c5d26;
  fpc_pushexceptaddr();
  aiStack_40[0] = 0x80c5d2b;
  aiStack_40[0] = fpc_setjmp();
  ppiVar2 = (int **)aiStack_40;
  if (aiStack_40[0] == 0) {
    piStack_44 = (int *)0x80c5d38;
    fpc_ansistr_decr_ref();
    aiStack_40[1] = 0;
    piStack_44 = aiStack_40 + 1;
    fpc_ansistr_copy();
    iVar1 = fpc_ansistr_compare_equal();
    ppiVar2 = &piStack_44;
    if (iVar1 == 0) {
      U_JUKELINUX1_TOUCHPRESSIONADO = 1;
      JUKELINUX1_LE_TOUCHSCREEN_INICIAL();
      DEBUGSTART_JUKELINUX1();
      (**(code **)(**(int **)(local_10 + 0xb5c) + 0xd8))();
      ppiVar2 = &piStack_44;
    }
  }
  ppiVar2[-1] = (int *)0x80c5d9a;
  fpc_popaddrstack();
  ppiVar2[-1] = (int *)0x80c5da2;
  fpc_ansistr_decr_ref();
  aiStack_40[1] = 0;
  if (*ppiVar2 != (int *)0x0) {
    *ppiVar2 = (int *)0x80c5db3;
    fpc_reraise();
  }
  return;
}

