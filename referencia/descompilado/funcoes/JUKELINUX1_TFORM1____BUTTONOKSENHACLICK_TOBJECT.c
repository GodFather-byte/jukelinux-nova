// JUKELINUX1_TFORM1_$__BUTTONOKSENHACLICK$TOBJECT  @ 080d4a10

void JUKELINUX1_TFORM1____BUTTONOKSENHACLICK_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  fpc_pushexceptaddr(0,0);
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    if (U_JUKELINUX1_CHAVEDEINSTALACAO != '\0') {
      cVar1 = (**(code **)(**(int **)(in_EAX + 0xa8c) + 0x450))();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 == '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FPC_ANSISTR_TO_SHORTSTR();
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          SYSTEM_REWRITE_TEXT();
          fpc_iocheck();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
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
          fpc_ansistr_decr_ref();
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_concat();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          DIALOGS_SHOWMESSAGE_ANSISTRING();
        }
      }
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          fpc_pchar_to_ansistr();
          SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
          U_JUKELINUX1_CHAVEDEINSTALACAO = '\0';
          DIALOGS_SHOWMESSAGE_ANSISTRING();
          U_JUKELINUX1_ESTADIGITANDOSENHA = 2;
          JUKELINUX1_ROTINA_MENU();
        }
      }
      cVar1 = (**(code **)(**(int **)(in_EAX + 0xa88) + 0x450))();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 == '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          FPC_ANSISTR_TO_SHORTSTR();
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          SYSTEM_REWRITE_TEXT();
          fpc_iocheck();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
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
          fpc_ansistr_decr_ref();
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_concat();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          DIALOGS_SHOWMESSAGE_ANSISTRING();
          JUKELINUX1_TFORM1____BS10CLICK_TOBJECT();
          (**(code **)(**(int **)(in_EAX + 0xa8c) + 0x454))();
        }
      }
    }
    if (U_JUKELINUX1_CHAVEDEINSTALACAO == '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 == '\0') {
        JUKELINUX1_GRAVALOG_ANSISTRING();
        DIALOGS_SHOWMESSAGE_ANSISTRING();
      }
      else {
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
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
        fpc_ansistr_incr_ref();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          U_JUKELINUX1_MENUMASTER = 0;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SENHAOK = 2;
          GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
          CONTROLS_TCONTROL____HIDE();
          JUKELINUX1_LIBERA_QUANTIDADESDEMUSICASTOCADAS();
        }
        else {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 == '\0') {
            JUKELINUX1_GRAVALOG_ANSISTRING();
            DIALOGS_SHOWMESSAGE_ANSISTRING();
          }
          else {
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
            OBJPAS_CLOSEFILE_TEXT();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
            iVar3 = fpc_ansistr_compare_equal();
            if (iVar3 == 0) {
              U_JUKELINUX1_MENUMASTER = 1;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              U_JUKELINUX1_SENHAOK = 2;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              CONTROLS_TCONTROL____HIDE();
              JUKELINUX1_LIBERA_QUANTIDADESDEMUSICASTOCADAS();
            }
            else {
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref(iVar2,uVar4,0);
              CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar2,0);
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              CONTROLS_TCONTROL____SHOW();
              (**(code **)(**(int **)(in_EAX + 0x948) + 0x2fc))();
              (**(code **)(**(int **)(in_EAX + 0xb84) + 0xd8))();
              (**(code **)(**(int **)(in_EAX + 0xb84) + 0xdc))();
              (**(code **)(**(int **)(in_EAX + 0xb84) + 0xd8))();
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            }
          }
        }
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar4 = 0;
  fpc_ansistr_decr_ref(iVar2,0);
  fpc_ansistr_decr_ref(iVar2,uVar4,0);
  fpc_ansistr_decr_ref();
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

