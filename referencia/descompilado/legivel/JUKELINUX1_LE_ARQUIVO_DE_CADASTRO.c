// JUKELINUX1_LE_ARQUIVO_DE_CADASTRO  @ 08095ca0

void JUKELINUX1_LE_ARQUIVO_DE_CADASTRO(void)

{
  char cVar1;
  int iVar2;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 != '\0') {
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
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_JC_CODIGODAMAQUINA = 0;
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_CODIGODAMAQUINASTR = U_JUKELINUX1_JC_CODIGODAMAQUINA;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_NOMEDOPONTOSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_CLIENTESTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_RGSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_CPFSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_TELEFONESSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_ENDERECOSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_BAIRROSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_CIDADESTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_DATADAINSTALACAOSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_SELOSSTR = 0;
      fpc_ansistr_decr_ref();
      fpc_read_text_ansistr();
      fpc_iocheck();
      fpc_readln_end();
      fpc_iocheck();
      JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

