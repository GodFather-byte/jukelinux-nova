// JUKELINUX1_TFORM1_$__BUTTONSALVARFRASESCLICK$TOBJECT  @ 080d5480

void JUKELINUX1_TFORM1____BUTTONSALVARFRASESCLICK_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  
  fpc_pushexceptaddr();
  iVar4 = fpc_setjmp();
  if (iVar4 == 0) {
    if (U_JUKELINUX1_ALTERANDOFRASES == '\0') {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      U_JUKELINUX1_ALTERANDOFRASES = '\x01';
      (**(code **)(**(int **)(in_EAX + 0x700) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x724) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x728) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x72c) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x730) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x734) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x738) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x73c) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x740) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x720) + 0x220))();
    }
    else {
      U_JUKELINUX1_ALTERANDOFRASES = '\0';
      (**(code **)(**(int **)(in_EAX + 0x700) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x724) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x728) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x72c) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x730) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x734) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x738) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x73c) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x740) + 0x220))();
      (**(code **)(**(int **)(in_EAX + 0x720) + 0x220))();
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
      cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar3 != '\0') {
        FPC_ANSISTR_TO_SHORTSTR();
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        SYSTEM_RESET_TEXT();
        fpc_iocheck();
        U_JUKELINUX1_KFRASE = 0;
        while( true ) {
          cVar3 = SYSTEM_EOF_TEXT__BOOLEAN();
          fpc_iocheck();
          if (cVar3 != '\0') break;
          U_JUKELINUX1_KFRASE = U_JUKELINUX1_KFRASE + 1;
          fpc_ansistr_decr_ref();
          fpc_read_text_ansistr();
          fpc_iocheck();
          fpc_readln_end();
          fpc_iocheck();
          fpc_ansistr_concat();
          iVar1 = U_JUKELINUX1_KFRASE;
          fpc_ansistr_incr_ref();
          iVar2 = U_JUKELINUX1_KFRASE;
          fpc_ansistr_decr_ref();
          *(undefined4 *)(iVar2 * 4 + 0x9301ccc) =
               *(undefined4 *)(U_JUKELINUX1_ARQTOCARX + iVar1 * 4 + 0x24c);
        }
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
        U_JUKELINUX1_TOTALFRASE = U_JUKELINUX1_KFRASE;
        U_JUKELINUX1_POSFRASE = 0;
      }
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar4 != 0) {
    fpc_reraise();
  }
  return;
}

