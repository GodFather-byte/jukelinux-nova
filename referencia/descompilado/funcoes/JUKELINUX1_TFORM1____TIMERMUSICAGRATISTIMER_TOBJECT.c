// JUKELINUX1_TFORM1_$__TIMERMUSICAGRATISTIMER$TOBJECT  @ 080e1610

void JUKELINUX1_TFORM1____TIMERMUSICAGRATISTIMER_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      (**(code **)(**(int **)(in_EAX + 0xb80) + 0xd8))();
      U_JUKELINUX1_MUSICAGRATISNUM = 0;
    }
    U_JUKELINUX1_TEMPOTOCARMG = 0;
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 1;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 1;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 2;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 3;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 3;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 5;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 10;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0xf;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x14;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x19;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x1e;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x2d;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 1;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 2;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 3;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 4;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 5;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 10;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0xf;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x14;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x19;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x1e;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      U_JUKELINUX1_MUSICAGRATISNUM = 0x2d;
      U_JUKELINUX1_TEMPOTOCARMG = 0x3c;
    }
    if (-1 < U_JUKELINUX1_TEMPOEMSEGUNDOS) {
      U_JUKELINUX1_TEMPOEMSEGUNDOS = U_JUKELINUX1_TEMPOEMSEGUNDOS + 1;
    }
    if ((((U_JUKELINUX1_TEMPOEMSEGUNDOS != -1) && (U_JUKELINUX1_TOCANDOMUSICA == '\0')) &&
        (U_JUKELINUX1_SELECIONADAS == 0)) && (iVar3 = fpc_ansistr_compare_equal(), iVar3 == 0)) {
      U_JUKELINUX1_TEMPOEMSEGUNDOS = U_JUKELINUX1_MUSICAGRATISNUM * 0x3c;
    }
    if (0 < U_JUKELINUX1_SELECIONADAS) {
      U_JUKELINUX1_TEMPOEMSEGUNDOS = 0;
    }
    if (U_JUKELINUX1_TOCANDOMUSICA != '\0') {
      U_JUKELINUX1_TEMPOEMSEGUNDOS = 0;
    }
    if (U_JUKELINUX1_TEMPOEMSEGUNDOS / 0x3c == U_JUKELINUX1_MUSICAGRATISNUM) {
      U_JUKELINUX1_TEMPOEMSEGUNDOS = 0xffffffff;
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_CDGRATIS = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_CDGRATIS == 0) {
          U_JUKELINUX1_CDGRATIS = 1;
        }
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_FAIXAGRATIS = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_FAIXAGRATIS == 0) {
          U_JUKELINUX1_FAIXAGRATIS = 1;
        }
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            FPC_ANSISTR_TO_SHORTSTR();
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            SYSTEM_APPEND_TEXT();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
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
        }
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        U_JUKELINUX1_POSMG = U_JUKELINUX1_POSMG + 1;
        if (U_JUKELINUX1_TOTALMG < U_JUKELINUX1_POSMG) {
          U_JUKELINUX1_POSMG = 1;
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
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            FPC_ANSISTR_TO_SHORTSTR();
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            SYSTEM_APPEND_TEXT();
            fpc_iocheck();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
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
        }
      }
      if (0 < U_JUKELINUX1_TEMPOTOCARMG) {
        (**(code **)(**(int **)(in_EAX + 0xb40) + 0xd8))();
        U_JUKELINUX1_KTEMPOMG = 0;
      }
      JUKELINUX1_MOSTRA_FILA();
      U_JUKELINUX1_TEMPOEMSEGUNDOS = 0;
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

