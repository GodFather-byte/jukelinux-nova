// JUKELINUX1_TFORM1_$__BUTTONEACLICK$TOBJECT  @ 080cdfd0

void JUKELINUX1_TFORM1____BUTTONEACLICK_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int local_10;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    iVar3 = (**(code **)(**(int **)(Form1.ButtonEO3 + 0x364) + 0x80))();
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      do {
        local_10 = local_10 + 1;
        cVar1 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FPC_ANSISTR_TO_SHORTSTR();
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          SYSTEM_APPEND_TEXT();
          fpc_iocheck();
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.ButtonEO3 + 0x364) + 0x78))();
          fpc_write_text_ansistr();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
          SYSTEM_FLUSH_TEXT();
          fpc_iocheck();
          OBJPAS_CLOSEFILE_TEXT();
          fpc_iocheck();
          (**(code **)(**(int **)(Form1.ButtonEO3 + 0x364) + 0x8c))();
          U_JUKELINUX1_RELECDS = 1;
        }
      } while (local_10 < iVar3 + -1);
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

