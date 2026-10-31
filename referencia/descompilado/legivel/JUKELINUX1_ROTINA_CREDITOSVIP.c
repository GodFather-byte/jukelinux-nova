// JUKELINUX1_ROTINA_CREDITOSVIP  @ 080b0250

void JUKELINUX1_ROTINA_CREDITOSVIP(void)

{
  int iVar1;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    if (U_JUKELINUX1_CREDITOSVIP < 1) {
      if (U_JUKELINUX1_RESOLUCAO == 0x556) {
        JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
        JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
      }
    }
    else {
      JUKELINUX1_PRESSTECLA();
      U_JUKELINUX1_CREDITOSVIP = U_JUKELINUX1_CREDITOSVIP + -1;
      if (U_JUKELINUX1_RESOLUCAO == 0x556) {
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
      }
      U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        fpc_pchar_to_ansistr();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        fpc_pchar_to_ansistr();
        FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
      }
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

