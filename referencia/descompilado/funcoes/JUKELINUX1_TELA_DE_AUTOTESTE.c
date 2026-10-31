// JUKELINUX1_TELA_DE_AUTOTESTE  @ 0809eba0

void JUKELINUX1_TELA_DE_AUTOTESTE(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_65c;
  int local_4c8;
  int local_c;
  int local_8;
  
  fpc_initialize();
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    CONTROLS_TCONTROL____SETWIDTH_LONGINT();
    CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
    CONTROLS_TCONTROL____SETLEFT_LONGINT();
    CONTROLS_TCONTROL____SETTOP_LONGINT();
    CONTROLS_TCONTROL____SHOW();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2ac] + 0x2fc))();
      CONTROLS_TCONTROL____REFRESH();
      (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      iVar3 = U_JUKELINUX1_TOTALCDS;
      if (0 < U_JUKELINUX1_TOTALCDS) {
        local_8 = 0;
        do {
          local_8 = local_8 + 1;
          fpc_ansistr_decr_ref();
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          fpc_write_text_ansistr();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
          fpc_write_text_ansistr();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
          fpc_write_text_char();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
        } while (local_8 < iVar3);
      }
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      iVar3 = U_JUKELINUX1_TOTALCDS;
      if (0 < U_JUKELINUX1_TOTALCDS) {
        local_8 = 0;
        do {
          local_8 = local_8 + 1;
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FPC_ANSISTR_TO_SHORTSTR();
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          SYSTEM_APPEND_TEXT();
          fpc_iocheck();
          fpc_ansistr_decr_ref();
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          fpc_write_text_ansistr();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
          fpc_write_text_ansistr();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          FPC_WRITE_TEXT_SHORTSTR();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
          SYSTEM_FLUSH_TEXT();
          fpc_iocheck();
          OBJPAS_CLOSEFILE_TEXT();
          fpc_iocheck();
        } while (local_8 < iVar3);
      }
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      fpc_pchar_to_ansistr();
      SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      fpc_pchar_to_ansistr();
      SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FPC_ANSISTR_TO_SHORTSTR();
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          SYSTEM_RESET_TEXT();
          fpc_iocheck();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FPC_ANSISTR_TO_SHORTSTR();
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          SYSTEM_RESET_TEXT();
          fpc_iocheck();
          local_c = 0;
          while( true ) {
            cVar1 = SYSTEM_EOF_TEXT__BOOLEAN();
            fpc_iocheck();
            if (cVar1 != '\0') break;
            fpc_ansistr_decr_ref();
            fpc_read_text_ansistr();
            fpc_iocheck();
            fpc_readln_end();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            fpc_read_text_ansistr();
            fpc_iocheck();
            fpc_readln_end();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            fpc_read_text_ansistr();
            fpc_iocheck();
            fpc_readln_end();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            fpc_read_text_ansistr();
            fpc_iocheck();
            fpc_readln_end();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            fpc_read_text_ansistr();
            fpc_iocheck();
            fpc_readln_end();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            fpc_read_text_ansistr();
            fpc_iocheck();
            fpc_readln_end();
            fpc_iocheck();
            local_c = local_c + 1;
          }
          OBJPAS_CLOSEFILE_TEXT();
          fpc_iocheck();
          OBJPAS_CLOSEFILE_TEXT();
          fpc_iocheck();
          if (local_c < U_JUKELINUX1_TOTALCDS) {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x219] + 0x2fc))();
            FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
            local_65c = 0;
            iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
            if (-1 < iVar3 + -1) {
              local_4c8 = -1;
              do {
                local_4c8 = local_4c8 + 1;
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
                    fpc_ansistr_concat();
                    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
                    if (cVar1 != '\0') {
                      local_65c = local_65c + 1;
                      fpc_ansistr_decr_ref();
                      (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x272] + 0x364) + 0x78))();
                      fpc_ansistr_concat();
                    }
                  }
                }
              } while (local_4c8 < iVar3 + -1);
            }
            if (0 < local_65c) {
              local_4c8 = 0;
              do {
                local_4c8 = local_4c8 + 1;
                SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
              } while (local_4c8 < local_65c);
            }
            SYSUTILS_REMOVEDIR_ANSISTRING__BOOLEAN();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            fpc_pchar_to_ansistr();
            SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            fpc_pchar_to_ansistr();
            SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
            JUKELINUX1_CARREGANDO_CDS();
            CONTROLS_TCONTROL____HIDE();
          }
        }
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  FPC_FINALIZE();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

