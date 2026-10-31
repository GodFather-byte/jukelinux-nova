// JUKELINUX1_TFORM1_$__LISTBOXRGENEROSCLICK$TOBJECT  @ 080c6580

void JUKELINUX1_TFORM1____LISTBOXRGENEROSCLICK_TOBJECT(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int aiStack_70 [3];
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  aiStack_70[2] = 0x80c65c1;
  fpc_pushexceptaddr();
  aiStack_70[2] = 0x80c65c6;
  aiStack_70[2] = fpc_setjmp();
  piVar5 = aiStack_70 + 2;
  if (aiStack_70[2] == 0) {
    fpc_ansistr_decr_ref();
    local_14 = 0;
    iVar3 = (**(code **)(**(int **)(*(int *)(local_c + 0x854) + 0x364) + 0x80))();
    piVar5 = aiStack_70 + 2;
    local_10 = 0;
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      piVar5 = aiStack_70 + 2;
      do {
        local_10 = local_10 + 1;
        *(undefined4 *)((int)piVar5 + -4) = 0x80c6630;
        cVar2 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN();
        if (cVar2 != '\0') {
          *(int **)((int)piVar5 + -4) = &local_14;
          *(undefined4 *)((int)piVar5 + -8) = 0x80c6644;
          fpc_ansistr_decr_ref();
          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x854) + 0x364) + 0x78);
          *(undefined4 *)((int)piVar5 + -8) = 0x80c6674;
          (*pcVar1)();
          *(undefined4 *)((int)piVar5 + -8) = 0x80c667e;
          SYSTEM_POS_CHAR_ANSISTRING__LONGINT();
          *(undefined4 *)((int)piVar5 + -8) = 0x80c668b;
          fpc_ansistr_decr_ref();
          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x854) + 0x364) + 0x78);
          *(undefined4 *)((int)piVar5 + -8) = 0x80c66bb;
          (*pcVar1)();
          *(undefined4 *)((int)piVar5 + -8) = 0x80c66ca;
          fpc_ansistr_copy();
          piVar5 = (int *)((int)piVar5 + -4);
        }
      } while (local_10 < iVar3 + -1);
    }
    if (local_14 != 0) {
      pcVar1 = *(code **)(**(int **)(local_c + 0x858) + 0x480);
      *(undefined4 *)((int)piVar5 + -4) = 0x80c66f8;
      (*pcVar1)();
      iVar3 = U_JUKELINUX1_TOTALCDS;
      local_10 = 1;
      if (0 < U_JUKELINUX1_TOTALCDS) {
        local_10 = 0;
        do {
          local_10 = local_10 + 1;
          *(undefined4 *)((int)piVar5 + -4) = 0x80c671f;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar5 + -4) = 0x80c673d;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)piVar5 + -4) = 0x80c6748;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)((int)piVar5 + -4) = 0x80c675d;
            iVar4 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
            if (iVar4 == 0) {
              *(undefined4 *)((int)piVar5 + -4) = 0x80c676d;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -4) = 0x80c6784;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -4) = 0x80c6793;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -4) = 0x80c67b1;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              *(undefined4 *)((int)piVar5 + -4) = 0x80c67c1;
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              *(undefined4 *)((int)piVar5 + -4) = 0x80c67f1;
              fpc_ansistr_concat_multi();
              pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x858) + 0x364) + 0xa4);
              *(undefined4 *)((int)piVar5 + -4) = 0x80c681a;
              (*pcVar1)();
            }
            else {
              *(undefined4 *)((int)piVar5 + -4) = 0x80c6824;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -4) = 0x80c6847;
              fpc_ansistr_concat();
              pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x858) + 0x364) + 0xa4);
              *(undefined4 *)((int)piVar5 + -4) = 0x80c6870;
              (*pcVar1)();
            }
          }
        } while (local_10 < iVar3);
      }
    }
    *(undefined4 *)((int)piVar5 + -4) = 0x80c6887;
    CONTROLS_TCONTROL____HIDE();
    *(undefined4 *)((int)piVar5 + -4) = 0x80c6895;
    CONTROLS_TCONTROL____HIDE();
    *(undefined4 *)((int)piVar5 + -4) = 0x80c68a3;
    CONTROLS_TCONTROL____HIDE();
    *(undefined4 *)((int)piVar5 + -4) = 0x80c68b1;
    CONTROLS_TCONTROL____HIDE();
  }
  piVar5[-1] = 0x80c68b6;
  fpc_popaddrstack();
  piVar5[-1] = 0x80c68be;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80c68cd;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80c68dc;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80c68eb;
  fpc_ansistr_decr_ref();
  local_14 = 0;
  if (*piVar5 != 0) {
    *piVar5 = 0x80c68fc;
    fpc_reraise();
  }
  return;
}

