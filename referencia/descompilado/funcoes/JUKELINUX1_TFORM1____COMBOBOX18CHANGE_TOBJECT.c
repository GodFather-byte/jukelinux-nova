// JUKELINUX1_TFORM1_$__COMBOBOX18CHANGE$TOBJECT  @ 080d99b0

void JUKELINUX1_TFORM1____COMBOBOX18CHANGE_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  fpc_pushexceptaddr(0,0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    iVar2 = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
    if (iVar2 < 0) {
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar1,0);
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    else {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar1,uVar3,0);
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
      fpc_ansistr_decr_ref(iVar1,uVar3,0);
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      fpc_ansistr_concat_multi();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      fpc_ansistr_decr_ref();
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar1,uVar3,0);
      U_JUKELINUX1_QTDCREDITOSGRATIS = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar3 = 0;
  fpc_ansistr_decr_ref(iVar1,0);
  fpc_ansistr_decr_ref(iVar1,uVar3,0);
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

