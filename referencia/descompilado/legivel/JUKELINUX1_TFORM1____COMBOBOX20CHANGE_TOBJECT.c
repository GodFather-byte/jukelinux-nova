// JUKELINUX1_TFORM1_$__COMBOBOX20CHANGE$TOBJECT  @ 080da5d0

void JUKELINUX1_TFORM1____COMBOBOX20CHANGE_TOBJECT(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 0;
  fpc_pushexceptaddr(0,0,0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    uVar3 = 0;
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar1,uVar2,0,uVar3);
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar1,0);
    fpc_ansistr_concat_multi();
    JUKELINUX1_GRAVALOG_ANSISTRING();
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar1,0);
    U_JUKELINUX1_RESOLUCAOTVX = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar1,0);
    U_JUKELINUX1_RESOLUCAOTVY = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
    JUKELINUX1_DEFINE_EXIBIRVIDEOS();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar2 = 0;
  fpc_ansistr_decr_ref(iVar1,0);
  uVar3 = 0;
  fpc_ansistr_decr_ref(iVar1,uVar2,0);
  if (iVar1 != 0) {
    fpc_reraise(uVar2,uVar3,0);
  }
  return;
}

