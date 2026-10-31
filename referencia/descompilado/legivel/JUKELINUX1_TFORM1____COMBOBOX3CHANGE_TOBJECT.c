// JUKELINUX1_TFORM1_$__COMBOBOX3CHANGE$TOBJECT  @ 080db1a0

void JUKELINUX1_TFORM1____COMBOBOX3CHANGE_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    U_JUKELINUX1_OKC = 0;
    iVar2 = (**(code **)(**(int **)(Form1.LabelNomedaMusicaTocando1 + 0x36c) + 0x80))();
    U_JUKELINUX1_KKC = 0;
    if (-1 < iVar2 + -1) {
      U_JUKELINUX1_KKC = -1;
      do {
        U_JUKELINUX1_KKC = U_JUKELINUX1_KKC + 1;
        fpc_ansistr_decr_ref();
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        fpc_ansistr_decr_ref();
        (**(code **)(**(int **)(Form1.LabelNomedaMusicaTocando1 + 0x36c) + 0x78))();
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          U_JUKELINUX1_OKC = 1;
        }
      } while (U_JUKELINUX1_KKC < iVar2 + -1);
    }
    if (U_JUKELINUX1_OKC == 1) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_ORDEMDOSCDS = 0;
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat_multi();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      JUKELINUX1_DESSELECIONAMUSICA();
      U_JUKELINUX1_MUSICASELECIONADA = 0;
      U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
      U_JUKELINUX1_MUSICASELECIONADATS = 0;
      JUKELINUX1_SELECIONAMUSICA();
      JUKELINUX1_CARREGANDO_CDS();
      U_JUKELINUX1_KMAT = 0xfffffffc;
      U_JUKELINUX1_MUSICASELECIONADA = 0;
      U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
      U_JUKELINUX1_MUSICASELECIONADATS = 0;
      if (U_JUKELINUX1_RESOLUCAO == 0x556) {
        U_JUKELINUX1_TAMANHOMUSICAGRANDE = 0x1e;
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        U_JUKELINUX1_TAMANHOMUSICAGRANDE = 0x16;
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
        U_JUKELINUX1_TAMANHOMUSICAGRANDE = 0x1e;
      }
      U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
      U_JUKELINUX1_MOSTRANDORITMOS = 0;
      U_JUKELINUX1_MOSTRANDOLETRAS = 0;
      JUKELINUX1_MOSTRA_CDS_ANSISTRING();
      JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS();
      JUKELINUX1_MOSTRA_FILA();
    }
    else {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

