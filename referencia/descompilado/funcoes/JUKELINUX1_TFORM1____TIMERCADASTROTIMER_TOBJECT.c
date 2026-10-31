// JUKELINUX1_TFORM1_$__TIMERCADASTROTIMER$TOBJECT  @ 080e4070

void JUKELINUX1_TFORM1____TIMERCADASTROTIMER_TOBJECT(void)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int local_14;
  
  fpc_pushexceptaddr();
  iVar4 = fpc_setjmp();
  if (iVar4 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar3 != '\0') {
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
      JUKELINUX1_DESCRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      iVar2 = U_JUKELINUX1_TEXTO;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_JC_CODIGODAMAQUINA = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      iVar5 = 0;
      if (iVar2 != 0) {
        iVar5 = *(int *)(iVar2 + -4);
      }
      if (0 < iVar5) {
        local_14 = 0;
        do {
          local_14 = local_14 + 1;
        } while (local_14 < iVar5);
      }
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      iVar5 = fpc_ansistr_compare_equal();
      if (iVar5 == 0) {
        iVar5 = fpc_ansistr_compare_equal();
        if (iVar5 == 0) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
          iVar5 = fpc_ansistr_compare_equal();
          if (iVar5 == 0) {
            bVar1 = true;
          }
        }
        if (bVar1) {
          U_JUKELINUX1_ALTERANDOFRASES = 1;
          (**(code **)(**(int **)(in_EAX + 0xbc8) + 0xd8))();
          (**(code **)(**(int **)(in_EAX + 0xb08) + 0x104))();
          CONTROLS_TCONTROL____BRINGTOFRONT();
          CONTROLS_TCONTROL____SHOW();
          CONTROLS_TCONTROL____HIDE();
          (**(code **)(**(int **)(in_EAX + 0x9b4) + 0x430))();
          (**(code **)(**(int **)(in_EAX + 0x9b4) + 0x220))();
          iVar5 = fpc_ansistr_compare_equal();
          if (iVar5 != 0) {
            (**(code **)(**(int **)(in_EAX + 0xb04) + 0x430))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(**(int **)(in_EAX + 0x9b4) + 0x220))();
          }
        }
        else {
          JUKELINUX1_LE_ARQUIVO_DE_CADASTRO();
          (**(code **)(**(int **)(in_EAX + 0xbc8) + 0xd8))();
        }
      }
      else {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
        (**(code **)(**(int **)(in_EAX + 0xbc8) + 0xd8))();
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar4 != 0) {
    fpc_reraise();
  }
  return;
}

