// JUKELINUX1_GRAVA_HD_RELOGIOS  @ 08096ad0

void JUKELINUX1_GRAVA_HD_RELOGIOS(void)

{
  int iVar1;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_RELOGIOTOTALSTR = 0;
    JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat(iVar1,0);
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_RELOGIOPARCIALSTR = 0;
    JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat(iVar1,0);
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref(iVar1,0);
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

