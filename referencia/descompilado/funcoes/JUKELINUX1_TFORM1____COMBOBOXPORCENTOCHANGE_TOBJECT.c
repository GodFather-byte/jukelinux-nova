// JUKELINUX1_TFORM1_$__COMBOBOXPORCENTOCHANGE$TOBJECT  @ 080ddfe0

void JUKELINUX1_TFORM1____COMBOBOXPORCENTOCHANGE_TOBJECT(void)

{
  int iVar1;
  undefined4 uVar2;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat(iVar1,0);
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_PORCENTAGEMDOPONTOSTR = uVar2;
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat_multi(iVar1,0);
    JUKELINUX1_GRAVALOG_ANSISTRING();
    U_JUKELINUX1_PORCENTAGEMDOPONTO = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

