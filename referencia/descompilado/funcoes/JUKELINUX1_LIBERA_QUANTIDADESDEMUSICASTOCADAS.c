// JUKELINUX1_LIBERA_QUANTIDADESDEMUSICASTOCADAS  @ 080b35e0

void JUKELINUX1_LIBERA_QUANTIDADESDEMUSICASTOCADAS(void)

{
  int iVar1;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    U_JUKELINUX1_QUANTIDADESDEMUSICASTOCADAS = 0;
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat(iVar1,0);
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING(iVar1,0);
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING(iVar1,0);
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
    CONTROLS_TCONTROL____HIDE();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

