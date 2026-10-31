// JUKELINUX1_APAGA_CD$LONGINT$LONGINT  @ 080b2650

void JUKELINUX1_APAGA_CD_LONGINT_LONGINT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1a4;
  int local_10;
  
  fpc_initialize();
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
    local_1a4 = 0;
    iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      do {
        local_10 = local_10 + 1;
        fpc_ansistr_decr_ref();
        (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 != 0) {
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 != 0) {
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
            fpc_ansistr_concat();
            cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar1 != '\0') {
              local_1a4 = local_1a4 + 1;
              fpc_ansistr_decr_ref();
              (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
              fpc_ansistr_concat();
            }
          }
        }
      } while (local_10 < iVar3 + -1);
    }
    if (0 < local_1a4) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
      } while (local_10 < local_1a4);
    }
    SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    U_JUKELINUX1_RELECDS = 1;
    if (in_EAX == 1) {
      CONTROLS_TCONTROL____HIDE();
    }
    if (in_EAX == 2) {
      CONTROLS_TCONTROL____HIDE();
    }
    if (in_EAX == 3) {
      CONTROLS_TCONTROL____HIDE();
    }
    if (in_EAX == 4) {
      CONTROLS_TCONTROL____HIDE();
    }
    if (in_EAX == 5) {
      CONTROLS_TCONTROL____HIDE();
    }
    if (in_EAX == 6) {
      CONTROLS_TCONTROL____HIDE();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  FPC_FINALIZE();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

