// JUKELINUX1_EXCLUICDPELALISTA  @ 080b2a40

void JUKELINUX1_EXCLUICDPELALISTA(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_fb4;
  int local_fb0;
  int local_7dc;
  int local_7d8 [501];
  
  fpc_initialize();
  fpc_initialize();
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 != '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_RESET_TEXT();
      fpc_iocheck();
      local_7dc = 0;
      while( true ) {
        cVar1 = SYSTEM_EOF_TEXT__BOOLEAN();
        fpc_iocheck();
        if (cVar1 != '\0') break;
        fpc_ansistr_decr_ref();
        fpc_read_text_ansistr();
        fpc_iocheck();
        fpc_readln_end();
        fpc_iocheck();
        local_7dc = local_7dc + 1;
        fpc_ansistr_incr_ref();
        fpc_ansistr_decr_ref();
        local_7d8[local_7dc] = U_JUKELINUX1_TEXTO;
      }
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x22f] + 0x2fc))();
      local_7d8[0] = 1;
      if (0 < local_7dc) {
        local_7d8[0] = 0;
        do {
          local_7d8[0] = local_7d8[0] + 1;
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat_multi();
          cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat_multi();
            cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar1 != '\0') {
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat_multi();
              GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
            }
            (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x1e4] + 0x2fc))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x230] + 0x2fc))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x241] + 0x2fc))();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat_multi();
            cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar1 != '\0') {
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat_multi();
              GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
            }
            (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x1e5] + 0x2fc))();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat_multi();
            FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
            local_fb0 = 0;
            iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
            if (-1 < iVar3 + -1) {
              local_fb4 = -1;
              do {
                local_fb4 = local_fb4 + 1;
                fpc_ansistr_decr_ref();
                (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x272] + 0x364) + 0x78))();
                iVar4 = fpc_ansistr_compare_equal();
                if (iVar4 != 0) {
                  fpc_ansistr_decr_ref();
                  (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x272] + 0x364) + 0x78))();
                  iVar4 = fpc_ansistr_compare_equal();
                  if (iVar4 != 0) {
                    fpc_ansistr_decr_ref();
                    fpc_ansistr_decr_ref();
                    (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x272] + 0x364) + 0x78))();
                    fpc_ansistr_concat_multi();
                    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
                    if (cVar1 != '\0') {
                      local_fb0 = local_fb0 + 1;
                      fpc_ansistr_decr_ref();
                      (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x272] + 0x364) + 0x78))();
                      fpc_ansistr_concat_multi();
                    }
                  }
                }
              } while (local_fb4 < iVar3 + -1);
            }
            if (0 < local_fb0) {
              local_fb4 = 0;
              do {
                local_fb4 = local_fb4 + 1;
                SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
                fpc_ansistr_decr_ref();
                fpc_ansistr_concat();
                CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x231] + 0x2fc))();
                (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
              } while (local_fb4 < local_fb0);
            }
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x241] + 0x2fc))();
            (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
            SYSUTILS_SLEEP_LONGWORD();
            U_JUKELINUX1_RELECDS = 1;
          }
        } while (local_7d8[0] < local_7dc);
      }
    }
    fpc_ansistr_decr_ref();
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_concat_multi();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____REFRESH();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    SYSUTILS_SLEEP_LONGWORD();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  FPC_FINALIZE();
  FPC_FINALIZE();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

