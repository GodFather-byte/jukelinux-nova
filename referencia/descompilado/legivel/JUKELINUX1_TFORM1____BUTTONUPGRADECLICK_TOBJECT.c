// JUKELINUX1_TFORM1_$__BUTTONUPGRADECLICK$TOBJECT  @ 080d5c20

void JUKELINUX1_TFORM1____BUTTONUPGRADECLICK_TOBJECT(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1a8;
  int local_1a4;
  int local_1a0 [101];
  int local_c;
  
  fpc_initialize();
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    else {
      FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
      local_1a4 = 0;
      iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
      if (-1 < iVar3 + -1) {
        local_1a0[0] = -1;
        do {
          local_1a0[0] = local_1a0[0] + 1;
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 != 0) {
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 != 0) {
              iVar4 = local_1a4 + 1;
              fpc_ansistr_decr_ref();
              (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
              iVar5 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT();
              if ((iVar5 == 0) && (local_1a4 = iVar4, iVar4 < 0x65)) {
                fpc_ansistr_decr_ref();
                (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
                fpc_ansistr_incr_ref();
                fpc_ansistr_decr_ref();
                local_1a0[iVar4] = 0;
              }
            }
          }
        } while (local_1a0[0] < iVar3 + -1);
      }
      local_1a0[0] = 1;
      if (0 < local_1a4) {
        local_1a0[0] = 0;
        do {
          local_1a0[0] = local_1a0[0] + 1;
          fpc_ansistr_concat();
          fpc_ansistr_concat();
          fpc_ansistr_decr_ref();
          fpc_pchar_to_ansistr();
          fpc_ansistr_decr_ref();
          fpc_pchar_to_ansistr();
          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          CONTROLS_TCONTROL____REFRESH();
          (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
          SYSUTILS_SLEEP_LONGWORD();
        } while (local_1a0[0] < local_1a4);
      }
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      fpc_ansistr_decr_ref();
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      SYSUTILS_SLEEP_LONGWORD();
      CONTROLS_TCONTROL____REFRESH();
      (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      local_1a8 = 0;
      do {
        local_1a8 = local_1a8 + 1;
        if (local_1a8 == 1) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 2) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 3) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 4) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 5) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 6) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 7) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 8) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 9) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 10) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 0xb) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 0xc) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 0xd) {
          fpc_ansistr_decr_ref();
        }
        if (local_1a8 == 0xe) {
          fpc_ansistr_decr_ref();
        }
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
        local_1a4 = 0;
        iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
        if (-1 < iVar3 + -1) {
          local_1a0[0] = -1;
          do {
            local_1a0[0] = local_1a0[0] + 1;
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 != 0) {
              fpc_ansistr_decr_ref();
              (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
              iVar4 = fpc_ansistr_compare_equal();
              if (iVar4 != 0) {
                local_1a4 = local_1a4 + 1;
                fpc_ansistr_decr_ref();
                (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
                iVar4 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT();
                if ((iVar4 == 0) && (local_1a4 < 0x65)) {
                  fpc_ansistr_decr_ref();
                  (**(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78))();
                  fpc_ansistr_incr_ref();
                  fpc_ansistr_decr_ref();
                  local_1a0[local_1a4] = 0;
                }
              }
            }
          } while (local_1a0[0] < iVar3 + -1);
        }
        local_1a0[0] = 1;
        if (0 < local_1a4) {
          local_1a0[0] = 0;
          do {
            local_1a0[0] = local_1a0[0] + 1;
            fpc_ansistr_concat_multi();
            fpc_ansistr_concat_multi();
            fpc_ansistr_decr_ref();
            fpc_pchar_to_ansistr();
            fpc_ansistr_decr_ref();
            fpc_pchar_to_ansistr();
            FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            SYSUTILS_SLEEP_LONGWORD();
            CONTROLS_TCONTROL____REFRESH();
            (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
          } while (local_1a0[0] < local_1a4);
        }
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        fpc_ansistr_decr_ref();
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        SYSUTILS_SLEEP_LONGWORD();
        CONTROLS_TCONTROL____REFRESH();
        (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      } while (local_1a8 < 0xe);
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  FPC_FINALIZE();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

