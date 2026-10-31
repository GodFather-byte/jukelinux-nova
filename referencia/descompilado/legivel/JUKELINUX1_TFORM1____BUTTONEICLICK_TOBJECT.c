// JUKELINUX1_TFORM1_$__BUTTONEICLICK$TOBJECT  @ 080ce1d0

void JUKELINUX1_TFORM1____BUTTONEICLICK_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    iVar3 = (**(code **)(**(int **)(Form1.LabelE1 + 0x364) + 0x80))();
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      do {
        local_10 = local_10 + 1;
        cVar1 = STDCTRLS_TCUSTOMLISTBOX____GETSELECTED_LONGINT__BOOLEAN();
        if (cVar1 != '\0') {
          (**(code **)(**(int **)(Form1.LabelE1 + 0x364) + 0x8c))();
        }
      } while (local_10 < iVar3 + -1);
    }
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    if (-1 < iVar3 + -1) {
      local_10 = -1;
      do {
        local_10 = local_10 + 1;
        fpc_ansistr_decr_ref();
        (**(code **)(**(int **)(Form1.LabelE1 + 0x364) + 0x78))();
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 != 0) {
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.LabelE1 + 0x364) + 0x78))();
          fpc_write_text_ansistr();
          fpc_iocheck();
          fpc_writeln_end();
          fpc_iocheck();
        }
      } while (local_10 < iVar3 + -1);
    }
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
    U_JUKELINUX1_RELECDS = 1;
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

