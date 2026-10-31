// JUKELINUX1_DESCRIPTOGRAFA$ANSISTRING$ANSISTRING  @ 08094d60

void JUKELINUX1_DESCRIPTOGRAFA_ANSISTRING_ANSISTRING(void)

{
  undefined1 *puVar1;
  int **ppiVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int **ppiVar7;
  int aiStack_158 [3];
  int *piStack_14c;
  undefined4 *puStack_148;
  int iStack_144;
  int local_3c [13];
  int local_8;
  
  iStack_144 = 0x8094d7d;
  fpc_ansistr_incr_ref();
  iStack_144 = 0x8094d85;
  fpc_ansistr_incr_ref();
  local_3c[0] = 0;
  local_3c[1] = 0;
  iStack_144 = 0x8094da3;
  fpc_pushexceptaddr();
  iStack_144 = 0x8094da8;
  iStack_144 = fpc_setjmp();
  ppiVar7 = (int **)&iStack_144;
  if (iStack_144 == 0) {
    puStack_148 = (undefined4 *)0x8094db9;
    fpc_ansistr_incr_ref();
    puStack_148 = (undefined4 *)0x8094dc3;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_ORIGEM = local_8;
    puStack_148 = (undefined4 *)0x8094dd5;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_DESTINO = 0;
    puStack_148 = (undefined4 *)0x8094dec;
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      iVar3 = 0;
      if (U_JUKELINUX1_ORIGEM != 0) {
        iVar3 = *(int *)(U_JUKELINUX1_ORIGEM + -4);
      }
      if (0 < iVar3) {
        puStack_148 = (undefined4 *)0x8094e10;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8094e1f;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8094e33;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094e3e;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094e4b;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x8094e64;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x8094e6c;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8094e7b;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8094e8f;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094e9a;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094ea7;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x8094ec0;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x8094ec8;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8094ed7;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8094eeb;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094ef6;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094f03;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x8094f1c;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x8094f24;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8094f33;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8094f47;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094f52;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094f5f;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x8094f78;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x8094f80;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8094f8f;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8094fa3;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094fae;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8094fbb;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x8094fd4;
          fpc_ansistr_concat();
        }
      }
    }
    puStack_148 = (undefined4 *)0x8094fe1;
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      iVar3 = 0;
      if (U_JUKELINUX1_ORIGEM != 0) {
        iVar3 = *(int *)(U_JUKELINUX1_ORIGEM + -4);
      }
      if (0 < iVar3) {
        puStack_148 = (undefined4 *)0x8095005;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8095014;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8095028;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8095033;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8095040;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x8095059;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x8095061;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8095070;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8095084;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x809508f;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x809509c;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x80950b5;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x80950bd;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x80950cc;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x80950e0;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x80950eb;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x80950f8;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x8095111;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x8095119;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8095128;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x809513c;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8095147;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8095154;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x809516d;
          fpc_ansistr_concat();
        }
        puStack_148 = (undefined4 *)0x8095175;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x8095184;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        puStack_148 = (undefined4 *)0x8095198;
        SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x80951a3;
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x80951b0;
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          puStack_148 = (undefined4 *)0x80951c9;
          fpc_ansistr_concat();
        }
      }
    }
    ppiVar7 = (int **)&iStack_144;
    iVar3 = 0;
    if (U_JUKELINUX1_DESTINO != 0) {
      iVar3 = *(int *)(U_JUKELINUX1_DESTINO + -4);
    }
    if (0 < iVar3) {
      if (U_JUKELINUX1_CHAVECRIPTOGRAFICA == 0) {
        U_JUKELINUX1_ESTADESCRIPTOGRAFANDO = 1;
        puStack_148 = (undefined4 *)0x8095594;
        FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
        ppiVar7 = (int **)&iStack_144;
        U_JUKELINUX1_ESTADESCRIPTOGRAFANDO = 0;
      }
      else {
        U_JUKELINUX1_ESTADESCRIPTOGRAFANDO = 1;
        U_JUKELINUX1_ERROTOCAR = 0;
        puStack_148 = (undefined4 *)0x8095205;
        fpc_ansistr_incr_ref();
        puStack_148 = (undefined4 *)0x809520f;
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_TIMER1ORIGEM = U_JUKELINUX1_ORIGEM;
        puStack_148 = (undefined4 *)0x8095221;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        puStack_148 = (undefined4 *)0x809523a;
        SYSUTILS_CHANGEFILEEXT_ANSISTRING_ANSISTRING__ANSISTRING();
        puStack_148 = (undefined4 *)0x8095242;
        fpc_ansistr_incr_ref();
        puStack_148 = (undefined4 *)0x809524c;
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_TIMER1DESTINOINF = local_3c[0];
        puStack_148 = (undefined4 *)0x809525e;
        fpc_ansistr_incr_ref();
        puStack_148 = (undefined4 *)0x8095268;
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_TIMER1DESTINOMP3 = U_JUKELINUX1_DESTINO;
        puStack_148 = (undefined4 *)0x8095288;
        FPC_ANSISTR_TO_SHORTSTR();
        puStack_148 = (undefined4 *)0x8095298;
        OBJPAS_ASSIGNFILE_file_SHORTSTRING();
        puStack_148 = (undefined4 *)0x80952a7;
        SYSTEM_RESET_file_LONGINT();
        puStack_148 = (undefined4 *)0x80952ac;
        fpc_iocheck();
        puStack_148 = (undefined4 *)0x80952c2;
        FPC_ANSISTR_TO_SHORTSTR();
        puStack_148 = (undefined4 *)0x80952d2;
        OBJPAS_ASSIGNFILE_file_SHORTSTRING();
        puStack_148 = (undefined4 *)0x80952e1;
        SYSTEM_REWRITE_file_LONGINT();
        puStack_148 = (undefined4 *)0x80952e6;
        fpc_iocheck();
        puStack_148 = (undefined4 *)0x80952fc;
        FPC_ANSISTR_TO_SHORTSTR();
        puStack_148 = (undefined4 *)0x809530c;
        OBJPAS_ASSIGNFILE_file_SHORTSTRING();
        puStack_148 = (undefined4 *)0x809531b;
        SYSTEM_REWRITE_file_LONGINT();
        puStack_148 = (undefined4 *)0x8095320;
        fpc_iocheck();
        puStack_148 = &U_JUKELINUX1_TIMER1NUMREAD;
        piStack_14c = (int *)0x8095339;
        SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT();
        piStack_14c = (int *)0x809533e;
        fpc_iocheck();
        piStack_14c = (int *)0x8095346;
        fpc_ansistr_decr_ref();
        local_3c[0] = 0;
        piStack_14c = (int *)0x8095355;
        fpc_ansistr_decr_ref();
        local_3c[1] = 0;
        piStack_14c = local_3c + 1;
        fpc_chararray_to_ansistr();
        SYSUTILS_TRIM_ANSISTRING__ANSISTRING();
        U_JUKELINUX1_TIMER1TAMINT = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
        ppiVar7 = &piStack_14c;
        if (0 < U_JUKELINUX1_TIMER1TAMINT) {
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TIMER1GRAVADORA = 0;
          U_JUKELINUX1_TIMER1K = 0;
          ppiVar2 = &piStack_14c;
          do {
            puVar4 = (undefined1 *)ppiVar2;
            U_JUKELINUX1_TIMER1K = U_JUKELINUX1_TIMER1K + 1;
            *(int **)(puVar4 + -4) = &U_JUKELINUX1_TIMER1NUMREAD;
            *(undefined4 *)(puVar4 + -8) = 0x80953db;
            SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT();
            *(undefined4 *)(puVar4 + -8) = 0x80953e0;
            fpc_iocheck();
            *(undefined4 *)(puVar4 + -8) = 0x80953e8;
            fpc_ansistr_decr_ref();
            local_3c[0] = 0;
            *(int **)(puVar4 + -8) = local_3c;
            *(undefined4 *)(puVar4 + -0xc) = 0x8095404;
            fpc_chararray_to_ansistr();
            *(undefined4 *)(puVar4 + -0xc) = 0x8095417;
            fpc_ansistr_concat();
            ppiVar2 = (int **)(puVar4 + -8);
          } while (U_JUKELINUX1_TIMER1K < 0x1e);
          *(undefined4 *)(puVar4 + -0xc) = 0x8095428;
          fpc_ansistr_decr_ref();
          local_3c[0] = 0;
          *(undefined4 *)(puVar4 + -0xc) = 0x809543c;
          JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar4 + -0xc) = 0x8095444;
          fpc_ansistr_incr_ref();
          *(undefined4 *)(puVar4 + -0xc) = 0x809544e;
          fpc_ansistr_decr_ref();
          iVar3 = U_JUKELINUX1_TIMER1TAMINT;
          U_JUKELINUX1_TIMER1GRAVADORA = local_3c[0];
          U_JUKELINUX1_TIMER1K = 1;
          puVar1 = puVar4 + -8;
          if (0 < U_JUKELINUX1_TIMER1TAMINT) {
            U_JUKELINUX1_TIMER1K = 0;
            puVar5 = puVar4;
            do {
              U_JUKELINUX1_TIMER1K = U_JUKELINUX1_TIMER1K + 1;
              *(int **)(puVar5 + -0xc) = &U_JUKELINUX1_TIMER1NUMREAD;
              *(undefined4 *)(puVar5 + -0x10) = 0x8095493;
              SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT();
              *(undefined4 *)(puVar5 + -0x10) = 0x8095498;
              fpc_iocheck();
              *(int **)(puVar5 + -0x10) = &U_JUKELINUX1_TIMER1NUMWRITTEN;
              *(undefined4 *)(puVar5 + -0x14) = 0x80954b2;
              SYSTEM_BLOCKWRITE_file_formal_LONGINT_LONGINT();
              *(undefined4 *)(puVar5 + -0x14) = 0x80954b7;
              fpc_iocheck();
              puVar1 = puVar5 + -0x10;
              puVar5 = puVar5 + -8;
            } while (U_JUKELINUX1_TIMER1K < iVar3);
          }
          do {
            puVar6 = puVar1;
            *(int **)(puVar6 + -4) = &U_JUKELINUX1_TIMER1NUMREAD;
            *(undefined4 *)(puVar6 + -8) = 0x80954d9;
            SYSTEM_BLOCKREAD_file_formal_LONGINT_LONGINT();
            *(undefined4 *)(puVar6 + -8) = 0x80954de;
            fpc_iocheck();
            *(undefined4 *)(puVar6 + -8) = 0x80954e3;
            JUKELINUX1_DESCRIPTABUF();
            *(int **)(puVar6 + -8) = &U_JUKELINUX1_TIMER1NUMWRITTEN;
            *(undefined4 *)(puVar6 + -0xc) = 0x80954fd;
            SYSTEM_BLOCKWRITE_file_formal_LONGINT_LONGINT();
            *(undefined4 *)(puVar6 + -0xc) = 0x8095502;
            fpc_iocheck();
            if (U_JUKELINUX1_TIMER1NUMREAD == 0) break;
            puVar1 = puVar6 + -8;
          } while (U_JUKELINUX1_TIMER1NUMWRITTEN == U_JUKELINUX1_TIMER1NUMREAD);
          *(undefined4 *)(puVar6 + -0xc) = 0x8095522;
          OBJPAS_CLOSEFILE_file();
          *(undefined4 *)(puVar6 + -0xc) = 0x8095527;
          fpc_iocheck();
          *(undefined4 *)(puVar6 + -0xc) = 0x8095531;
          OBJPAS_CLOSEFILE_file();
          *(undefined4 *)(puVar6 + -0xc) = 0x8095536;
          fpc_iocheck();
          *(undefined4 *)(puVar6 + -0xc) = 0x8095540;
          OBJPAS_CLOSEFILE_file();
          *(undefined4 *)(puVar6 + -0xc) = 0x8095545;
          fpc_iocheck();
          *(undefined4 *)(puVar6 + -0xc) = 0x809554d;
          fpc_ansistr_decr_ref();
          local_3c[0] = 0;
          *(undefined4 *)(puVar6 + -0xc) = 0x809556a;
          fpc_pchar_to_ansistr();
          *(undefined4 *)(puVar6 + -0xc) = 0x8095572;
          SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
          ppiVar7 = (int **)(puVar6 + -8);
        }
        U_JUKELINUX1_ESTADESCRIPTOGRAFANDO = 0;
      }
    }
  }
  ppiVar7[-1] = (int *)0x80955a0;
  fpc_popaddrstack();
  ppiVar7[-1] = (int *)0x80955a8;
  fpc_ansistr_decr_ref();
  local_3c[0] = 0;
  ppiVar7[-1] = (int *)0x80955b7;
  fpc_ansistr_decr_ref();
  local_3c[1] = 0;
  ppiVar7[-1] = (int *)0x80955c6;
  fpc_ansistr_decr_ref();
  ppiVar7[-1] = (int *)0x80955ce;
  fpc_ansistr_decr_ref();
  if (*ppiVar7 != (int *)0x0) {
    *ppiVar7 = (int *)0x80955d8;
    fpc_reraise();
  }
  return;
}

