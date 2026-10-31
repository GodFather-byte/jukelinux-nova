// JUKELINUX1_TFORM1_$__LISTBOXRCDSCLICK$TOBJECT  @ 080c6250

/* WARNING: Removing unreachable block (ram,0x080c6343) */

void JUKELINUX1_TFORM1____LISTBOXRCDSCLICK_TOBJECT(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int aiStack_5c [3];
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  aiStack_5c[2] = 0x80c628a;
  fpc_pushexceptaddr();
  aiStack_5c[2] = 0x80c628f;
  aiStack_5c[2] = fpc_setjmp();
  piVar5 = aiStack_5c + 2;
  if (aiStack_5c[2] == 0) {
    fpc_ansistr_decr_ref();
    local_14 = 0;
    iVar3 = (**(code **)(**(int **)(*(int *)(local_c + 0x858) + 0x364) + 0x80))();
    piVar5 = aiStack_5c + 2;
    local_10 = 0;
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      piVar5 = aiStack_5c + 2;
      do {
        local_10 = local_10 + 1;
        *(undefined4 *)((int)piVar5 + -4) = 0x80c62f8;
        cVar2 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN();
        if (cVar2 != '\0') {
          *(int **)((int)piVar5 + -4) = &local_14;
          *(undefined4 *)((int)piVar5 + -8) = 0x80c630c;
          fpc_ansistr_decr_ref();
          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x858) + 0x364) + 0x78);
          *(undefined4 *)((int)piVar5 + -8) = 0x80c633c;
          (*pcVar1)();
          *(undefined4 *)((int)piVar5 + -8) = 0x80c634e;
          fpc_ansistr_decr_ref();
          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x858) + 0x364) + 0x78);
          *(undefined4 *)((int)piVar5 + -8) = 0x80c637e;
          (*pcVar1)();
          *(undefined4 *)((int)piVar5 + -8) = 0x80c638d;
          fpc_ansistr_copy();
          piVar5 = (int *)((int)piVar5 + -4);
        }
      } while (local_10 < iVar3 + -1);
    }
    iVar3 = U_JUKELINUX1_TOTALCDS;
    if ((local_14 != 0) && (local_10 = 1, 0 < U_JUKELINUX1_TOTALCDS)) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        *(undefined4 *)((int)piVar5 + -4) = 0x80c63d6;
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 == 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x80c63f2;
          cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar2 == '\0') {
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6525;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_CDSELEAPAGAR = 0;
          }
          else {
            *(undefined4 *)((int)piVar5 + -4) = 0x80c641d;
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c642b;
            CONTROLS_TCONTROL____SHOW();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6439;
            CONTROLS_TCONTROL____SHOW();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6447;
            CONTROLS_TCONTROL____SHOW();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6455;
            CONTROLS_TCONTROL____HIDE();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c646e;
            iVar4 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar4 == 0) {
              *(undefined4 *)((int)piVar5 + -4) = 0x80c6480;
              CONTROLS_TCONTROL____SHOW();
            }
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6488;
            fpc_ansistr_decr_ref();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6497;
            fpc_ansistr_decr_ref();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c64b5;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c64c5;
            fpc_ansistr_concat();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c64d6;
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            iVar4 = local_10 * 0x240;
            *(undefined4 *)((int)piVar5 + -4) = 0x80c64ea;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c64f4;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_CDSELEAPAGAR = *(undefined4 *)(U_JUKELINUX1_ARQLOG + iVar4 + 0x1f8);
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6507;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)piVar5 + -4) = 0x80c6511;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_CDSELEAPAGARX = local_14;
          }
        }
      } while (local_10 < iVar3);
    }
  }
  piVar5[-1] = 0x80c653d;
  fpc_popaddrstack();
  piVar5[-1] = 0x80c6545;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80c6554;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80c6563;
  fpc_ansistr_decr_ref();
  local_14 = 0;
  if (*piVar5 != 0) {
    *piVar5 = 0x80c6574;
    fpc_reraise();
  }
  return;
}

