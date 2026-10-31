// JUKELINUX1_ROTINA_VOLUMEMAIS  @ 080afb20

void JUKELINUX1_ROTINA_VOLUMEMAIS(void)

{
  int iVar1;
  int iVar2;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    (**(code **)(*Form1.PanelMenu2grande + 0xd8))();
    (**(code **)(*Form1.PanelMenu2grande + 0xd8))();
    if (U_JUKELINUX1_TEMPOPARAAUMENTARVOLUME == 0) {
      U_JUKELINUX1_TEMPOPARAAUMENTARVOLUME = 1;
      (**(code **)(*Form1.ComboBoxPorcento + 0xd8))();
      (**(code **)(*Form1.ComboBoxPorcento + 0xd8))();
      U_JUKELINUX1_VOLUMELIMITADONAOAUMENTA = '\0';
      if ((U_JUKELINUX1_VOLUMELIMITADO != '\0') &&
         (U_JUKELINUX1_LIMITARVOLUME < U_JUKELINUX1_VOLUME + 1)) {
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_TOQUEVOLUMEMAIS = 0;
          (**(code **)(*Form1.EditKaraoke + 0xd8))();
        }
        U_JUKELINUX1_VOLUMELIMITADONAOAUMENTA = '\x01';
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          fpc_ansistr_decr_ref();
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          fpc_ansistr_decr_ref();
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          fpc_ansistr_decr_ref();
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
      }
      if (U_JUKELINUX1_VOLUMELIMITADONAOAUMENTA == '\0') {
        U_JUKELINUX1_VOLUME = U_JUKELINUX1_VOLUME + U_JUKELINUX1_INTERVALOVOLUME;
        if (100 < U_JUKELINUX1_VOLUME) {
          U_JUKELINUX1_VOLUME = 100;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            U_JUKELINUX1_TOQUEVOLUMEMAIS = 0;
            (**(code **)(*Form1.EditKaraoke + 0xd8))();
          }
        }
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
        if (U_JUKELINUX1_ESTAEMTELACHEIA == '\0') {
          if (U_JUKELINUX1_RESOLUCAO == 0x556) {
            fpc_ansistr_decr_ref();
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
            fpc_ansistr_decr_ref();
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x400) {
            fpc_ansistr_decr_ref();
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
        }
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        FPC_ANSISTR_TO_SHORTSTR();
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        SYSTEM_REWRITE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        SYSTEM_FLUSH_TEXT();
        fpc_iocheck();
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

