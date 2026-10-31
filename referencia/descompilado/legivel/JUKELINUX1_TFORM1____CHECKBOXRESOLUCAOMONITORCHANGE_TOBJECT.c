// JUKELINUX1_TFORM1_$__CHECKBOXRESOLUCAOMONITORCHANGE$TOBJECT  @ 080d82a0

void JUKELINUX1_TFORM1____CHECKBOXRESOLUCAOMONITORCHANGE_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  
  fpc_pushexceptaddr(0);
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    cVar1 = (**(code **)(*Form1.LabelRitmo + 0x450))();
    if (cVar1 != '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar2,0);
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      fpc_write_text_char();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
    }
    cVar1 = (**(code **)(*Form1.LabelRitmo + 0x450))();
    if (cVar1 == '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar2,0);
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      fpc_write_text_char();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise(0);
  }
  return;
}

