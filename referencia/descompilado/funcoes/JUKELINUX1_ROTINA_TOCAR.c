// JUKELINUX1_ROTINA_TOCAR  @ 080ac700

void JUKELINUX1_ROTINA_TOCAR(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_CREDITOS = 1;
    }
    if (U_JUKELINUX1_ESTANOMENU == '\0') {
      iVar3 = *(int *)((U_JUKELINUX1_KMAT + 5) * 0x240 + 0x8e91144 +
                      U_JUKELINUX1_MUSICASELECIONADA * 4);
      iVar4 = 0;
      if (iVar3 != 0) {
        iVar4 = *(int *)(iVar3 + -4);
      }
      if (iVar4 < 1) {
        JUKELINUX1_PRESSTECLA();
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
      }
      else {
        if ((U_JUKELINUX1_TOCANDOMUSICA != '\0') && (U_JUKELINUX1_TOCANDOMUSICAGRATIS != '\0')) {
          JUKELINUX1_ROTINA_CANCELAR();
        }
        if (U_JUKELINUX1_CREDITOS < 1) {
          if (U_JUKELINUX1_RESOLUCAO == 0x556) {
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x400) {
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
        }
        else if (0 < U_JUKELINUX1_MUSICASELECIONADA) {
          cVar1 = JUKELINUX1_TEM_2X_MUSICA_NA_FILA__BOOLEAN();
          if (cVar1 == '\0') {
            U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + -1;
            U_JUKELINUX1_PULSOSPARACARTAO = 0;
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            FPC_ANSISTR_TO_SHORTSTR();
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            SYSTEM_REWRITE_TEXT();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_CREDITOSSTR = 0;
            fpc_ansistr_decr_ref();
            JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_CREDITOSSTR = 0;
            fpc_write_text_ansistr();
            fpc_iocheck();
            fpc_writeln_end();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
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
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat();
              fpc_pchar_to_ansistr();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat();
              fpc_pchar_to_ansistr();
              FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
            }
            GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
            (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 3000) + 0xd8))();
            (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 3000) + 0xd8))();
            U_JUKELINUX1_MOSTRANDOCREDITO = 1;
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar1 != '\0') {
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat();
              FPC_ANSISTR_TO_SHORTSTR();
              OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
              SYSTEM_APPEND_TEXT();
              fpc_iocheck();
              fpc_write_text_ansistr();
              fpc_iocheck();
              fpc_writeln_end();
              fpc_iocheck();
              SYSTEM_FLUSH_TEXT();
              fpc_iocheck();
              OBJPAS_CLOSEFILE_TEXT();
              fpc_iocheck();
              if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
                fpc_ansistr_decr_ref();
                fpc_ansistr_decr_ref();
                fpc_ansistr_concat();
                fpc_pchar_to_ansistr();
                fpc_ansistr_decr_ref();
                fpc_ansistr_decr_ref();
                fpc_ansistr_concat();
                fpc_pchar_to_ansistr();
                FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
              }
            }
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            if (U_JUKELINUX1_RESOLUCAO == 0x556) {
              JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
              JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            if (U_JUKELINUX1_RESOLUCAO == 0x400) {
              JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            JUKELINUX1_MOSTRA_FILA();
          }
          else {
            if (U_JUKELINUX1_RESOLUCAO == 0x556) {
              JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
              JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            if (U_JUKELINUX1_RESOLUCAO == 0x400) {
              JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
          }
        }
      }
    }
    else if (U_JUKELINUX1_SENHAOK == 1) {
      U_JUKELINUX1_PRESS2XPARAZERAR = U_JUKELINUX1_PRESS2XPARAZERAR + 1;
      if (U_JUKELINUX1_PRESS2XPARAZERAR < 2) {
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
      if (1 < U_JUKELINUX1_PRESS2XPARAZERAR) {
        JUKELINUX1_TFORM1____BUTTONZRPCLICK_TOBJECT();
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
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

