// JUKELINUX1_TFORM1_$__BUTTONXMLCLICK$TOBJECT  @ 080d68e0

void JUKELINUX1_TFORM1____BUTTONXMLCLICK_TOBJECT(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  fpc_pushexceptaddr();
  iVar3 = fpc_setjmp();
  if (iVar3 == 0) {
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    else {
      cVar1 = '\0';
      fpc_ansistr_concat_multi();
      cVar2 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
      if (cVar2 == '\0') {
        SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
        SYSUTILS_SLEEP_LONGWORD();
      }
      cVar2 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
      if (cVar2 != '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
        else {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
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
        }
        cVar1 = cVar1 == '\0';
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar2 == '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
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
          cVar1 = cVar1 + '\x01';
        }
        else {
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
      }
      if (cVar1 == '\x02') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat_multi();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar3 != 0) {
    fpc_reraise();
  }
  return;
}

