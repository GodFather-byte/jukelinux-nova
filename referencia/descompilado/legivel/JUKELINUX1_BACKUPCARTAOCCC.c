// JUKELINUX1_BACKUPCARTAOCCC  @ 080b3770

void JUKELINUX1_BACKUPCARTAOCCC(void)

{
  char cVar1;
  int iVar2;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
      SYSUTILS_SLEEP_LONGWORD();
    }
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    fpc_ansistr_concat_multi();
    fpc_ansistr_decr_ref();
    fpc_pchar_to_ansistr();
    fpc_ansistr_decr_ref();
    fpc_pchar_to_ansistr();
    FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
    SYSUTILS_SLEEP_LONGWORD();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

