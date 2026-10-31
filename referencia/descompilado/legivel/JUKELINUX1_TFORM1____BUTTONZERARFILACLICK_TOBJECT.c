// JUKELINUX1_TFORM1_$__BUTTONZERARFILACLICK$TOBJECT  @ 080d70f0

void JUKELINUX1_TFORM1____BUTTONZERARFILACLICK_TOBJECT(void)

{
  int iVar1;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_concat();
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
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
    JUKELINUX1_MOSTRA_FILA();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    JUKELINUX1_GRAVALOG_ANSISTRING();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

