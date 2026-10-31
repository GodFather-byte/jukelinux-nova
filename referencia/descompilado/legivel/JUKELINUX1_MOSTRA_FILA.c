// JUKELINUX1_MOSTRA_FILA  @ 080ab860

void JUKELINUX1_MOSTRA_FILA(void)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  int aiStack_160 [3];
  undefined4 local_34 [11];
  char local_8;
  
  local_34[0] = 0;
  aiStack_160[2] = 0x80ab8cc;
  fpc_pushexceptaddr();
  aiStack_160[2] = 0x80ab8d1;
  aiStack_160[2] = fpc_setjmp();
  piVar3 = aiStack_160 + 2;
  if (aiStack_160[2] == 0) {
    fpc_ansistr_decr_ref();
    local_34[0] = 0;
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    piVar3 = aiStack_160 + 2;
    if (cVar1 != '\0') {
      U_JUKELINUX1_SELECIONADAS = 0;
      fpc_ansistr_decr_ref();
      local_34[0] = 0;
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_RESET_TEXT();
      fpc_iocheck();
      piVar3 = aiStack_160 + 2;
      local_8 = '\0';
      while( true ) {
        *(undefined4 *)((int)piVar3 + -4) = 0x80ab9fe;
        cVar1 = SYSTEM_EOF_TEXT__BOOLEAN();
        puVar2 = (undefined1 *)((int)piVar3 + -4);
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba05;
        fpc_iocheck();
        if (cVar1 != '\0') break;
        *(undefined4 *)((int)piVar3 + -4) = 0x80ab97e;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80ab98d;
        fpc_read_text_ansistr();
        *(undefined4 *)((int)piVar3 + -4) = 0x80ab992;
        fpc_iocheck();
        *(undefined4 *)((int)piVar3 + -4) = 0x80ab99c;
        fpc_readln_end();
        *(undefined4 *)((int)piVar3 + -4) = 0x80ab9a1;
        fpc_iocheck();
        *(undefined4 *)((int)piVar3 + -4) = 0x80ab9ab;
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 == '\0') {
          *(undefined4 *)((int)piVar3 + -4) = 0x80ab9b7;
          fpc_ansistr_decr_ref();
          local_34[0] = 0;
          *(undefined4 **)((int)piVar3 + -4) = local_34;
          *(undefined4 *)((int)piVar3 + -8) = 0x80ab9de;
          fpc_ansistr_copy();
          *(undefined4 *)((int)piVar3 + -8) = 0x80ab9e6;
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          piVar3 = (int *)((int)piVar3 + -4);
          if (cVar1 == '\0') {
            local_8 = '\x01';
            piVar3 = (int *)puVar2;
          }
        }
        U_JUKELINUX1_SELECIONADAS = U_JUKELINUX1_SELECIONADAS + 1;
      }
      *(undefined4 *)((int)piVar3 + -4) = 0x80aba17;
      OBJPAS_CLOSEFILE_TEXT();
      *(undefined4 *)((int)piVar3 + -4) = 0x80aba1c;
      fpc_iocheck();
      if (local_8 != '\0') {
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba2e;
        fpc_ansistr_decr_ref();
        local_34[0] = 0;
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba48;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba5b;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba6b;
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba75;
        SYSTEM_RESET_TEXT();
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba7a;
        fpc_iocheck();
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba82;
        fpc_ansistr_decr_ref();
        local_34[0] = 0;
        *(undefined4 *)((int)piVar3 + -4) = 0x80aba9c;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abaaf;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar3 + -4) = 0x80ababf;
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abac9;
        SYSTEM_REWRITE_TEXT();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abace;
        fpc_iocheck();
        while( true ) {
          *(undefined4 *)((int)piVar3 + -4) = 0x80abb44;
          cVar1 = SYSTEM_EOF_TEXT__BOOLEAN();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abb4b;
          fpc_iocheck();
          if (cVar1 != '\0') break;
          *(undefined4 *)((int)piVar3 + -4) = 0x80abada;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abae9;
          fpc_read_text_ansistr();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abaee;
          fpc_iocheck();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abaf8;
          fpc_readln_end();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abafd;
          fpc_iocheck();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abb07;
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            *(undefined4 *)((int)piVar3 + -4) = 0x80abb20;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)piVar3 + -4) = 0x80abb25;
            fpc_iocheck();
            *(undefined4 *)((int)piVar3 + -4) = 0x80abb2f;
            fpc_writeln_end();
            *(undefined4 *)((int)piVar3 + -4) = 0x80abb34;
            fpc_iocheck();
          }
          U_JUKELINUX1_SELECIONADAS = U_JUKELINUX1_SELECIONADAS + 1;
        }
        *(undefined4 *)((int)piVar3 + -4) = 0x80abb59;
        OBJPAS_CLOSEFILE_TEXT();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abb5e;
        fpc_iocheck();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abb68;
        OBJPAS_CLOSEFILE_TEXT();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abb6d;
        fpc_iocheck();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abb75;
        fpc_ansistr_decr_ref();
        local_34[0] = 0;
        *(undefined4 *)((int)piVar3 + -4) = 0x80abb87;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abba7;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abbbe;
        fpc_pchar_to_ansistr();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abbcc;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abbe1;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc01;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc1b;
        fpc_pchar_to_ansistr();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc2a;
        FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
        U_JUKELINUX1_SELECIONADAS = 0;
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc3f;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc5f;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc75;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc85;
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc8f;
        SYSTEM_RESET_TEXT();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abc94;
        fpc_iocheck();
        while( true ) {
          *(undefined4 *)((int)piVar3 + -4) = 0x80abcd5;
          cVar1 = SYSTEM_EOF_TEXT__BOOLEAN();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abcdc;
          fpc_iocheck();
          if (cVar1 != '\0') break;
          *(undefined4 *)((int)piVar3 + -4) = 0x80abca2;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abcb1;
          fpc_read_text_ansistr();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abcb6;
          fpc_iocheck();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abcc0;
          fpc_readln_end();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abcc5;
          fpc_iocheck();
          U_JUKELINUX1_SELECIONADAS = U_JUKELINUX1_SELECIONADAS + 1;
        }
        *(undefined4 *)((int)piVar3 + -4) = 0x80abcea;
        OBJPAS_CLOSEFILE_TEXT();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abcef;
        fpc_iocheck();
        if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
          *(undefined4 *)((int)piVar3 + -4) = 0x80abd07;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abd1c;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abd3c;
          fpc_ansistr_concat();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abd56;
          fpc_pchar_to_ansistr();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abd67;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abd7c;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abd9c;
          fpc_ansistr_concat();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abdb6;
          fpc_pchar_to_ansistr();
          *(undefined4 *)((int)piVar3 + -4) = 0x80abdc5;
          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
        }
      }
      if (U_JUKELINUX1_SELECIONADAS < 100) {
        *(undefined4 *)((int)piVar3 + -4) = 0x80abdde;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abdf3;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe08;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe22;
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe38;
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe4e;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe64;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
      else {
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe74;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe89;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abe9e;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abeb8;
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abece;
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abee4;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar3 + -4) = 0x80abefa;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
    }
  }
  piVar3[-1] = 0x80abeff;
  fpc_popaddrstack();
  piVar3[-1] = 0x80abf0a;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80abf1f;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80abf34;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80abf49;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80abf5e;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80abf73;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80abf88;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80abf9a;
  fpc_ansistr_decr_ref();
  local_34[0] = 0;
  if (*piVar3 != 0) {
    *piVar3 = 0x80abfab;
    fpc_reraise();
  }
  return;
}

