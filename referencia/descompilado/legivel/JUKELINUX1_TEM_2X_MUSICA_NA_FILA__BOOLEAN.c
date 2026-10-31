// JUKELINUX1_TEM_2X_MUSICA_NA_FILA$$BOOLEAN  @ 080ab570

/* WARNING: Removing unreachable block (ram,0x080ab7be) */
/* WARNING: Removing unreachable block (ram,0x080ab7b0) */
/* WARNING: Removing unreachable block (ram,0x080ab7df) */
/* WARNING: Removing unreachable block (ram,0x080ab7b7) */
/* WARNING: Removing unreachable block (ram,0x080ab7c5) */
/* WARNING: Removing unreachable block (ram,0x080ab7d4) */
/* WARNING: Removing unreachable block (ram,0x080ab7e6) */
/* WARNING: Removing unreachable block (ram,0x080ab7f5) */

undefined1 JUKELINUX1_TEM_2X_MUSICA_NA_FILA__BOOLEAN(void)

{
  char cVar1;
  int iVar2;
  undefined1 local_8;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      fpc_ansistr_decr_ref();
    }
    else {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_RESET_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
    }
    fpc_ansistr_decr_ref();
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
      while( true ) {
        cVar1 = SYSTEM_EOF_TEXT__BOOLEAN();
        fpc_iocheck();
        if (cVar1 != '\0') break;
        fpc_ansistr_decr_ref();
        fpc_read_text_ansistr();
        fpc_iocheck();
        fpc_readln_end();
        fpc_iocheck();
      }
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
    }
    local_8 = 0;
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return local_8;
}

