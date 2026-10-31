// JUKELINUX1_TFORM1_$__BUTTONEA1CLICK$TOBJECT  @ 080cdb40

void JUKELINUX1_TFORM1____BUTTONEA1CLICK_TOBJECT(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int aiStack_1ec [3];
  undefined4 local_1d4;
  undefined4 local_1d0;
  int local_1a4;
  int local_10;
  
  aiStack_1ec[2] = 0x80cdb71;
  fpc_initialize();
  local_1d4 = 0;
  local_1d0 = 0;
  aiStack_1ec[2] = 0x80cdb9b;
  fpc_pushexceptaddr();
  aiStack_1ec[2] = 0x80cdba0;
  aiStack_1ec[2] = fpc_setjmp();
  piVar6 = aiStack_1ec + 2;
  if (aiStack_1ec[2] == 0) {
    FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
    local_1a4 = 0;
    iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    piVar6 = aiStack_1ec + 2;
    piVar5 = aiStack_1ec + 2;
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      do {
        local_10 = local_10 + 1;
        fpc_ansistr_decr_ref();
        local_1d0 = 0;
        (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 != 0) {
          fpc_ansistr_decr_ref();
          local_1d0 = 0;
          (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 != 0) {
            fpc_ansistr_decr_ref();
            local_1d0 = 0;
            fpc_ansistr_decr_ref();
            local_1d4 = 0;
            (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
            fpc_ansistr_concat();
            cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar2 != '\0') {
              local_1a4 = local_1a4 + 1;
              fpc_ansistr_decr_ref();
              local_1d4 = 0;
              (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
              fpc_ansistr_concat();
            }
          }
        }
      } while (local_10 < iVar3 + -1);
    }
    iVar3 = local_1a4;
    local_10 = 1;
    if (0 < local_1a4) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
      } while (local_10 < iVar3);
    }
    SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN();
    fpc_ansistr_decr_ref();
    local_1d4 = 0;
    fpc_ansistr_concat();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    U_JUKELINUX1_RELECDS = 1;
    iVar3 = (**(code **)(**(int **)(Form1.PanelMenu5grande + 0x364) + 0x80))();
    local_10 = 0;
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      do {
        local_10 = local_10 + 1;
        *(undefined4 *)((int)piVar5 + -4) = 0x80cde66;
        fpc_ansistr_decr_ref();
        local_1d4 = 0;
        *(undefined4 **)((int)piVar5 + -4) = &local_1d4;
        *(undefined4 *)((int)piVar5 + -8) = 0x80cde82;
        fpc_ansistr_decr_ref();
        local_1d0 = 0;
        pcVar1 = *(code **)(**(int **)(Form1.PanelMenu5grande + 0x364) + 0x78);
        *(undefined4 *)((int)piVar5 + -8) = 0x80cdebd;
        (*pcVar1)();
        *(undefined4 *)((int)piVar5 + -8) = 0x80cded5;
        fpc_ansistr_decr_ref();
        local_1d0 = 0;
        pcVar1 = *(code **)(**(int **)(Form1.PanelMenu5grande + 0x364) + 0x78);
        *(undefined4 *)((int)piVar5 + -8) = 0x80cdf10;
        (*pcVar1)();
        *(undefined4 *)((int)piVar5 + -8) = 0x80cdf22;
        fpc_ansistr_copy();
        *(undefined4 *)((int)piVar5 + -8) = 0x80cdf33;
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 == 0) {
          pcVar1 = *(code **)(**(int **)(Form1.PanelMenu5grande + 0x364) + 0x8c);
          *(undefined4 *)((int)piVar5 + -8) = 0x80cdf6a;
          (*pcVar1)();
        }
        piVar6 = (int *)((int)piVar5 + -4);
        piVar5 = (int *)((int)piVar5 + -4);
      } while (local_10 < iVar3 + -1);
    }
  }
  piVar6[-1] = 0x80cdf78;
  fpc_popaddrstack();
  piVar6[-1] = 0x80cdf83;
  fpc_ansistr_decr_ref();
  local_1d4 = 0;
  piVar6[-1] = 0x80cdf98;
  fpc_ansistr_decr_ref();
  local_1d0 = 0;
  piVar6[-1] = 0x80cdfb2;
  FPC_FINALIZE();
  if (*piVar6 != 0) {
    *piVar6 = 0x80cdfbc;
    fpc_reraise();
  }
  return;
}

