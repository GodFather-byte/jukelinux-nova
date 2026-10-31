// JUKELINUX1_CARREGANDO_KARAOKES  @ 0809a850

/* WARNING: Removing unreachable block (ram,0x0809aaa8) */

void JUKELINUX1_CARREGANDO_KARAOKES(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int aiStack_50 [3];
  undefined4 local_34 [11];
  int local_8;
  
  local_34[0] = 0;
  aiStack_50[2] = 0x809a87d;
  fpc_pushexceptaddr();
  aiStack_50[2] = 0x809a882;
  aiStack_50[2] = fpc_setjmp();
  piVar5 = aiStack_50 + 2;
  if (aiStack_50[2] == 0) {
    CONTROLS_TCONTROL____REFRESH();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    (**(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc))();
    CONTROLS_TCONTROL____REFRESH();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    cVar2 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar2 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
    piVar5 = aiStack_50 + 2;
    local_8 = 0;
    do {
      iVar3 = local_8 + 1;
      local_8 = iVar3;
      fpc_ansistr_decr_ref();
      *(undefined4 *)(&DAT_092f635c + iVar3 * 4) = 0;
    } while (local_8 < 8000);
    U_JUKELINUX1_KMATKARAOKE = 0;
    iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    local_8 = 0;
    if (-1 < iVar3 + -1) {
      local_8 = -1;
      piVar5 = aiStack_50 + 2;
      do {
        local_8 = local_8 + 1;
        *(undefined4 *)((int)piVar5 + -4) = 0x809a9af;
        fpc_ansistr_decr_ref();
        local_34[0] = 0;
        pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
        *(undefined4 *)((int)piVar5 + -4) = 0x809a9e4;
        (*pcVar1)();
        *(undefined4 *)((int)piVar5 + -4) = 0x809a9f1;
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 != 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x809aa01;
          fpc_ansistr_decr_ref();
          local_34[0] = 0;
          pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
          *(undefined4 *)((int)piVar5 + -4) = 0x809aa36;
          (*pcVar1)();
          *(undefined4 *)((int)piVar5 + -4) = 0x809aa43;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 != 0) {
            U_JUKELINUX1_KMATKARAOKE = U_JUKELINUX1_KMATKARAOKE + 1;
            *(undefined4 *)((int)piVar5 + -4) = 0x809aa59;
            fpc_ansistr_decr_ref();
            local_34[0] = 0;
            *(undefined4 **)((int)piVar5 + -4) = local_34;
            *(undefined4 *)((int)piVar5 + -8) = 0x809aa6c;
            fpc_ansistr_decr_ref();
            pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
            *(undefined4 *)((int)piVar5 + -8) = 0x809aaa1;
            (*pcVar1)();
            *(undefined4 *)((int)piVar5 + -8) = 0x809aab5;
            fpc_ansistr_decr_ref();
            pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
            *(undefined4 *)((int)piVar5 + -8) = 0x809aaea;
            (*pcVar1)();
            *(undefined4 *)((int)piVar5 + -8) = 0x809aaf9;
            fpc_ansistr_copy();
            *(undefined4 *)((int)piVar5 + -8) = 0x809ab13;
            fpc_ansistr_concat();
            piVar5 = (int *)((int)piVar5 + -4);
          }
        }
      } while (local_8 < iVar3 + -1);
    }
    U_JUKELINUX1_TOTALKARAOKES = U_JUKELINUX1_KMATKARAOKE;
  }
  piVar5[-1] = 0x809ab2b;
  fpc_popaddrstack();
  piVar5[-1] = 0x809ab33;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x809ab42;
  fpc_ansistr_decr_ref();
  local_34[0] = 0;
  if (*piVar5 != 0) {
    *piVar5 = 0x809ab53;
    fpc_reraise();
  }
  return;
}

