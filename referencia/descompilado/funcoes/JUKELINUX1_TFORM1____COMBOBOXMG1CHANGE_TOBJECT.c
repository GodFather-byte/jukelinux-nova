// JUKELINUX1_TFORM1_$__COMBOBOXMG1CHANGE$TOBJECT  @ 080dca90

void JUKELINUX1_TFORM1____COMBOBOXMG1CHANGE_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
    iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      do {
        local_10 = local_10 + 1;
        fpc_ansistr_decr_ref();
        (**(code **)(**(int **)(*(int *)(in_EAX + 0x9c8) + 0x364) + 0x78))();
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 != 0) {
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x9c8) + 0x364) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 != 0) {
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(*(int *)(in_EAX + 0x9c8) + 0x364) + 0x78))();
            SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 == 0) {
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              (**(code **)(**(int **)(*(int *)(in_EAX + 0x9c8) + 0x364) + 0x78))();
              fpc_ansistr_concat();
              cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
              if (cVar1 != '\0') {
                fpc_ansistr_decr_ref();
                fpc_ansistr_decr_ref();
                (**(code **)(**(int **)(*(int *)(in_EAX + 0x9c8) + 0x364) + 0x78))();
                fpc_ansistr_concat();
                SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
              }
            }
          }
        }
      } while (local_10 < iVar3 + -1);
    }
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
    U_JUKELINUX1_RELECDS = 1;
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

