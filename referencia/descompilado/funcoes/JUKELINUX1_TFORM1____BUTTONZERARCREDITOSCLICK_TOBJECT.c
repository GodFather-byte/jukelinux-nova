// JUKELINUX1_TFORM1_$__BUTTONZERARCREDITOSCLICK$TOBJECT  @ 080d6da0

void JUKELINUX1_TFORM1____BUTTONZERARCREDITOSCLICK_TOBJECT(void)

{
  int iVar1;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    U_JUKELINUX1_CREDITOS = 0;
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
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    JUKELINUX1_GRAVALOG_ANSISTRING();
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

