// JUKELINUX1_TFORM1_$__TIMERTOCARTIMER$TOBJECT  @ 080e5f20

/* WARNING: Removing unreachable block (ram,0x080e5fda) */

void JUKELINUX1_TFORM1____TIMERTOCARTIMER_TOBJECT(void)

{
  code *pcVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int **ppiVar6;
  undefined1 *puVar7;
  int *piVar8;
  int iVar9;
  longdouble lVar10;
  int *piStack_384;
  int *piStack_380;
  int iStack_37c;
  char *local_244;
  undefined4 local_240;
  undefined4 local_13c;
  int local_138 [75];
  int local_c;
  
  local_244 = (char *)0x0;
  local_240 = 0;
  local_13c = 0;
  local_138[0] = 0;
  iStack_37c = 0x80e5f97;
  fpc_pushexceptaddr();
  iStack_37c = 0x80e5f9c;
  iStack_37c = fpc_setjmp();
  piVar8 = &iStack_37c;
  if (iStack_37c == 0) {
    U_JUKELINUX1_OK_TOCA_MENU = '\x01';
    piStack_380 = (int *)0x80e5fbb;
    iVar4 = fpc_ansistr_compare_equal();
    piVar8 = &iStack_37c;
    if ((iVar4 == 0) && (U_JUKELINUX1_ESTANOMENU != '\0')) {
      U_JUKELINUX1_OK_TOCA_MENU = '\x01';
    }
    if (U_JUKELINUX1_OK_TOCA_MENU != '\0') {
      piStack_380 = (int *)0x80e600a;
      (**(code **)(**(int **)(local_c + 0xb90) + 0xd8))();
      if (U_JUKELINUX1_SELECIONADAS < 1) {
        piStack_380 = (int *)0x80e77e9;
        (**(code **)(**(int **)(local_c + 0xb90) + 0xd8))();
        piVar8 = &iStack_37c;
      }
      else if (U_JUKELINUX1_TOCANDOMUSICA == '\0') {
        if (U_JUKELINUX1_TOCANDOPALHINHA == '\0') {
          piStack_380 = (int *)0x80e603c;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          piStack_380 = (int *)0x80e605c;
          fpc_ansistr_concat();
          piStack_380 = (int *)0x80e6072;
          FPC_ANSISTR_TO_SHORTSTR();
          piStack_380 = (int *)0x80e6082;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          piStack_380 = (int *)0x80e608c;
          SYSTEM_RESET_TEXT();
          piStack_380 = (int *)0x80e6091;
          fpc_iocheck();
          piStack_380 = (int *)0x80e609b;
          fpc_ansistr_decr_ref();
          piStack_380 = (int *)0x80e60aa;
          fpc_read_text_ansistr();
          piStack_380 = (int *)0x80e60af;
          fpc_iocheck();
          piStack_380 = (int *)0x80e60b9;
          fpc_readln_end();
          piStack_380 = (int *)0x80e60be;
          fpc_iocheck();
          piStack_380 = (int *)0x80e60c8;
          OBJPAS_CLOSEFILE_TEXT();
          piStack_380 = (int *)0x80e60cd;
          fpc_iocheck();
          piStack_380 = (int *)0x80e60d7;
          fpc_ansistr_incr_ref();
          piStack_380 = (int *)0x80e60e1;
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOTOCAR2 = U_JUKELINUX1_TEXTOTOCAR;
          piStack_380 = (int *)0x80e60f6;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          piStack_380 = local_138;
          piStack_384 = (int *)0x80e611b;
          fpc_ansistr_copy();
          piStack_384 = (int *)0x80e612b;
          iVar4 = fpc_ansistr_compare_equal();
          ppiVar6 = &piStack_380;
          if (iVar4 == 0) {
            piStack_384 = (int *)0x80e613a;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            piStack_384 = local_138;
            fpc_ansistr_copy();
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            ppiVar6 = &piStack_384;
            U_JUKELINUX1_TEXTOTOCAR = local_138[0];
          }
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6191;
          fpc_ansistr_incr_ref();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e619b;
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOTOCANDO = U_JUKELINUX1_TEXTOTOCAR;
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e61b0;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e61d0;
          fpc_ansistr_concat();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e61e6;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e61f6;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6200;
          SYSTEM_REWRITE_TEXT();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6205;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e621a;
          fpc_write_text_ansistr();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e621f;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6229;
          fpc_writeln_end();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e622e;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6238;
          SYSTEM_FLUSH_TEXT();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e623d;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6247;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e624c;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6257;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e6277;
          fpc_ansistr_concat();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e628d;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e629d;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62a7;
          SYSTEM_RESET_TEXT();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62ac;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62b6;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62c5;
          fpc_read_text_ansistr();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62ca;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62d4;
          fpc_readln_end();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62d9;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62e3;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62e8;
          fpc_iocheck();
          *(undefined4 *)((int)ppiVar6 + -4) = 0x80e62f3;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(int **)((int)ppiVar6 + -4) = local_138;
          *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6318;
          fpc_ansistr_copy();
          *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6328;
          iVar4 = fpc_ansistr_compare_equal();
          puVar7 = (undefined1 *)((int)ppiVar6 + -4);
          if (iVar4 != 0) {
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e633a;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6344;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TEXTOTOCANDO = U_JUKELINUX1_TEXTOTOCAR;
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6359;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6379;
            fpc_ansistr_concat();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e638f;
            FPC_ANSISTR_TO_SHORTSTR();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e639f;
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e63aa;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e63ca;
            fpc_ansistr_concat();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e63d5;
            cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar3 == '\0') {
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e63e3;
              SYSTEM_REWRITE_TEXT();
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e63e8;
              fpc_iocheck();
            }
            else {
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e63f4;
              SYSTEM_APPEND_TEXT();
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e63f9;
              fpc_iocheck();
            }
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e640e;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6413;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e641d;
            fpc_writeln_end();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6422;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e642c;
            SYSTEM_FLUSH_TEXT();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6431;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e643b;
            OBJPAS_CLOSEFILE_TEXT();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6440;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e644a;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6454;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TEXTOTOCANDO = U_JUKELINUX1_TEXTOTOCAR;
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6469;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6489;
            fpc_ansistr_concat();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e649f;
            FPC_ANSISTR_TO_SHORTSTR();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e64af;
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e64ba;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e64da;
            fpc_ansistr_concat();
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e64e5;
            cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar3 == '\0') {
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e64f3;
              SYSTEM_REWRITE_TEXT();
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e64f8;
              fpc_iocheck();
            }
            else {
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6504;
              SYSTEM_APPEND_TEXT();
              *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6509;
              fpc_iocheck();
            }
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6514;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -8) = 0x80e6523;
            lVar10 = (longdouble)SYSUTILS_DATE__TDATETIME();
            *(double *)((int)ppiVar6 + -0xc) = (double)lVar10;
            *(undefined4 *)((int)ppiVar6 + -0x10) = 0x80e6534;
            SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
            *(undefined4 *)((int)ppiVar6 + -0x10) = 0x80e6549;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)ppiVar6 + -0x10) = 0x80e654e;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x10) = 0x80e6558;
            fpc_writeln_end();
            *(undefined4 *)((int)ppiVar6 + -0x10) = 0x80e655d;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x10) = 0x80e6568;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -0x10) = 0x80e6577;
            lVar10 = (longdouble)SYSUTILS_TIME__TDATETIME();
            *(double *)((int)ppiVar6 + -0x14) = (double)lVar10;
            *(undefined4 *)((int)ppiVar6 + -0x18) = 0x80e6588;
            SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
            *(undefined4 *)((int)ppiVar6 + -0x18) = 0x80e659d;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)ppiVar6 + -0x18) = 0x80e65a2;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x18) = 0x80e65ac;
            fpc_writeln_end();
            *(undefined4 *)((int)ppiVar6 + -0x18) = 0x80e65b1;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x18) = 0x80e65bc;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(int **)((int)ppiVar6 + -0x18) = local_138;
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e65f2;
            fpc_ansistr_copy();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e65fd;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6607;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TEXTO = local_138[0];
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6622;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6627;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6631;
            fpc_writeln_end();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6636;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6640;
            SYSTEM_FLUSH_TEXT();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6645;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e664f;
            OBJPAS_CLOSEFILE_TEXT();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6654;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e665e;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6668;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TEXTOTOCANDO = U_JUKELINUX1_TEXTOTOCAR;
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e667d;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e669d;
            fpc_ansistr_concat();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e66b3;
            FPC_ANSISTR_TO_SHORTSTR();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e66c3;
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e66ce;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e66ee;
            fpc_ansistr_concat();
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e66f9;
            cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar3 == '\0') {
              *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6707;
              SYSTEM_REWRITE_TEXT();
              *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e670c;
              fpc_iocheck();
            }
            else {
              *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6718;
              SYSTEM_APPEND_TEXT();
              *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e671d;
              fpc_iocheck();
            }
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6728;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -0x1c) = 0x80e6737;
            lVar10 = (longdouble)SYSUTILS_DATE__TDATETIME();
            *(double *)((int)ppiVar6 + -0x20) = (double)lVar10;
            *(undefined4 *)((int)ppiVar6 + -0x24) = 0x80e6748;
            SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
            *(undefined4 *)((int)ppiVar6 + -0x24) = 0x80e675d;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)ppiVar6 + -0x24) = 0x80e6762;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x24) = 0x80e676c;
            fpc_writeln_end();
            *(undefined4 *)((int)ppiVar6 + -0x24) = 0x80e6771;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x24) = 0x80e677c;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(undefined4 *)((int)ppiVar6 + -0x24) = 0x80e678b;
            lVar10 = (longdouble)SYSUTILS_TIME__TDATETIME();
            *(double *)((int)ppiVar6 + -0x28) = (double)lVar10;
            *(undefined4 *)((int)ppiVar6 + -0x2c) = 0x80e679c;
            SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
            *(undefined4 *)((int)ppiVar6 + -0x2c) = 0x80e67b1;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)ppiVar6 + -0x2c) = 0x80e67b6;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x2c) = 0x80e67c0;
            fpc_writeln_end();
            *(undefined4 *)((int)ppiVar6 + -0x2c) = 0x80e67c5;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x2c) = 0x80e67d0;
            fpc_ansistr_decr_ref();
            local_138[0] = 0;
            *(int **)((int)ppiVar6 + -0x2c) = local_138;
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6806;
            fpc_ansistr_copy();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6811;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e681b;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TEXTO = local_138[0];
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6836;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e683b;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6845;
            fpc_writeln_end();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e684a;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6854;
            SYSTEM_FLUSH_TEXT();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6859;
            fpc_iocheck();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6863;
            OBJPAS_CLOSEFILE_TEXT();
            *(undefined4 *)((int)ppiVar6 + -0x30) = 0x80e6868;
            fpc_iocheck();
            puVar7 = (undefined1 *)((int)ppiVar6 + -0x2c);
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6873;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6888;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e68a2;
          SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e68b3;
          SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e68c3;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e68dc;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -4) = 0x80e68eb;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TOCANDOTIPO = &__JUKELINUX1__Ld158;
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e68fc;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6911;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e692b;
          SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e693c;
          SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e694c;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e6965;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -4) = 0x80e6974;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TOCANDOTIPO = &__JUKELINUX1__Ld29;
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6985;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e699a;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e69b4;
          SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e69c5;
          SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e69d5;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e69ee;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -4) = 0x80e69fd;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TOCANDOTIPO = &__JUKELINUX1__Ld158;
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6a0e;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6a23;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6a3d;
          SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e6a4e;
          SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e6a5e;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e6a77;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -4) = 0x80e6a86;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TOCANDOTIPO = &__JUKELINUX1__Ld29;
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6a97;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6aac;
          fpc_ansistr_decr_ref();
          local_138[0] = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6ac6;
          SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e6ad7;
          SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e6ae7;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e6b00;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -4) = 0x80e6b0f;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TOCANDOTIPO = &__JUKELINUX1__Ld29;
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6b1f;
          cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar3 != '\0') {
            *(undefined4 *)(puVar7 + -4) = 0x80e6b32;
            JUKELINUX1_DESCRIPTOGRAFA_ANSISTRING_ANSISTRING();
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6b3d;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6b5d;
          fpc_ansistr_concat();
          *(undefined4 *)(puVar7 + -4) = 0x80e6b73;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)(puVar7 + -4) = 0x80e6b83;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e6b8d;
          SYSTEM_REWRITE_TEXT();
          *(undefined4 *)(puVar7 + -4) = 0x80e6b92;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -4) = 0x80e6b9d;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6bbd;
          fpc_ansistr_concat();
          *(undefined4 *)(puVar7 + -4) = 0x80e6bd3;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)(puVar7 + -4) = 0x80e6be3;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)(puVar7 + -4) = 0x80e6bed;
          SYSTEM_RESET_TEXT();
          *(undefined4 *)(puVar7 + -4) = 0x80e6bf2;
          fpc_iocheck();
          U_JUKELINUX1_KTOCAR = 1;
          while( true ) {
            *(undefined4 *)(puVar7 + -4) = 0x80e6c70;
            cVar3 = SYSTEM_EOF_TEXT__BOOLEAN();
            *(undefined4 *)(puVar7 + -4) = 0x80e6c77;
            fpc_iocheck();
            if (cVar3 != '\0') break;
            *(undefined4 *)(puVar7 + -4) = 0x80e6c0a;
            fpc_ansistr_decr_ref();
            *(undefined4 *)(puVar7 + -4) = 0x80e6c19;
            fpc_read_text_ansistr();
            *(undefined4 *)(puVar7 + -4) = 0x80e6c1e;
            fpc_iocheck();
            *(undefined4 *)(puVar7 + -4) = 0x80e6c28;
            fpc_readln_end();
            *(undefined4 *)(puVar7 + -4) = 0x80e6c2d;
            fpc_iocheck();
            if (U_JUKELINUX1_KTOCAR != 1) {
              *(undefined4 *)(puVar7 + -4) = 0x80e6c4c;
              fpc_write_text_ansistr();
              *(undefined4 *)(puVar7 + -4) = 0x80e6c51;
              fpc_iocheck();
              *(undefined4 *)(puVar7 + -4) = 0x80e6c5b;
              fpc_writeln_end();
              *(undefined4 *)(puVar7 + -4) = 0x80e6c60;
              fpc_iocheck();
            }
            U_JUKELINUX1_KTOCAR = U_JUKELINUX1_KTOCAR + 1;
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6c85;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)(puVar7 + -4) = 0x80e6c8a;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -4) = 0x80e6c94;
          SYSTEM_FLUSH_TEXT();
          *(undefined4 *)(puVar7 + -4) = 0x80e6c99;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -4) = 0x80e6ca3;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)(puVar7 + -4) = 0x80e6ca8;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -4) = 0x80e6cb3;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6cd3;
          fpc_ansistr_concat();
          *(undefined4 *)(puVar7 + -4) = 0x80e6cde;
          SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
          *(undefined4 *)(puVar7 + -4) = 0x80e6ce9;
          fpc_ansistr_decr_ref();
          local_13c = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6d09;
          fpc_ansistr_concat();
          *(undefined4 *)(puVar7 + -4) = 0x80e6d1a;
          fpc_ansistr_decr_ref();
          local_240 = 0;
          *(undefined4 *)(puVar7 + -4) = 0x80e6d3a;
          fpc_ansistr_concat();
          *(undefined4 *)(puVar7 + -4) = 0x80e6d47;
          SYSUTILS_RENAMEFILE_ANSISTRING_ANSISTRING__BOOLEAN();
          if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
            *(undefined4 *)(puVar7 + -4) = 0x80e6d5f;
            fpc_ansistr_decr_ref();
            local_240 = 0;
            *(undefined4 *)(puVar7 + -4) = 0x80e6d74;
            fpc_ansistr_decr_ref();
            local_13c = 0;
            *(undefined4 *)(puVar7 + -4) = 0x80e6d94;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -4) = 0x80e6dae;
            fpc_pchar_to_ansistr();
            *(undefined4 *)(puVar7 + -4) = 0x80e6dbf;
            fpc_ansistr_decr_ref();
            local_244 = (char *)0x0;
            *(undefined4 *)(puVar7 + -4) = 0x80e6dd4;
            fpc_ansistr_decr_ref();
            *(undefined4 *)(puVar7 + -4) = 0x80e6df4;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -4) = 0x80e6e0e;
            fpc_pchar_to_ansistr();
            *(undefined4 *)(puVar7 + -4) = 0x80e6e1d;
            FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6e22;
          JUKELINUX1_MOSTRA_FILA();
          *(undefined4 *)(puVar7 + -4) = 0x80e6e31;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e6e47;
            CONTROLS_TCONTROL____SHOW();
            *(undefined4 *)(puVar7 + -4) = 0x80e6e5b;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING();
            *(undefined4 *)(puVar7 + -4) = 0x80e6e69;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY();
            *(undefined4 *)(puVar7 + -4) = 0x80e6e7e;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
            *(undefined4 *)(puVar7 + -4) = 0x80e6e93;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
            U_JUKELINUX1_TOCANDOMUSICA = '\x01';
            U_JUKELINUX1_TOCANDOMUSICADVD = 0;
            *(undefined4 *)(puVar7 + -4) = 0x80e6eaf;
            CONTROLS_TCONTROL____HIDE();
            pcVar1 = *(code **)(**(int **)(local_c + 0xb90) + 0xd8);
            *(undefined4 *)(puVar7 + -4) = 0x80e6ecb;
            (*pcVar1)();
            pcVar1 = *(code **)(**(int **)(local_c + 0xb8c) + 0xd8);
            *(undefined4 *)(puVar7 + -4) = 0x80e6ee7;
            (*pcVar1)();
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e6ef6;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            if (U_JUKELINUX1_TOCANDOVIDEOTV != '\0') {
              pcVar1 = *(code **)(**(int **)(local_c + 0xb6c) + 0xd8);
              *(undefined4 *)(puVar7 + -4) = 0x80e6f23;
              (*pcVar1)();
              *(undefined4 *)(puVar7 + -4) = 0x80e6f31;
              MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
              *(undefined4 *)(puVar7 + -4) = 0x80e6f3f;
              CONTROLS_TCONTROL____HIDE();
              U_JUKELINUX1_TOCANDOVIDEOTV = '\0';
            }
            *(undefined4 *)(puVar7 + -4) = 0x80e6f5a;
            CONTROLS_TCONTROL____SETLEFT_LONGINT();
            *(undefined4 *)(puVar7 + -4) = 0x80e6f6e;
            CONTROLS_TCONTROL____SETTOP_LONGINT();
            *(undefined4 *)(puVar7 + -4) = 0x80e6f82;
            CONTROLS_TCONTROL____SETWIDTH_LONGINT();
            *(undefined4 *)(puVar7 + -4) = 0x80e6f96;
            CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
            *(undefined4 *)(puVar7 + -4) = 0x80e6fa4;
            CONTROLS_TCONTROL____SHOW();
            pcVar1 = *(code **)(**(int **)(local_c + 0xa84) + 0x2fc);
            *(undefined4 *)(puVar7 + -4) = 0x80e6fbe;
            (*pcVar1)();
            *(undefined4 *)(puVar7 + -4) = 0x80e6fcc;
            CONTROLS_TCONTROL____BRINGTOFRONT();
            *(undefined4 *)(puVar7 + -4) = 0x80e6fe0;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING();
            *(undefined4 *)(puVar7 + -4) = 0x80e6fee;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY();
            *(undefined4 *)(puVar7 + -4) = 0x80e7003;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
            *(undefined4 *)(puVar7 + -4) = 0x80e7018;
            MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
            U_JUKELINUX1_TOCANDOMUSICA = '\x01';
            U_JUKELINUX1_TOCANDOMUSICADVD = 1;
            pcVar1 = *(code **)(**(int **)(local_c + 0xb90) + 0xd8);
            *(undefined4 *)(puVar7 + -4) = 0x80e7042;
            (*pcVar1)();
            pcVar1 = *(code **)(**(int **)(local_c + 0xb8c) + 0xd8);
            *(undefined4 *)(puVar7 + -4) = 0x80e705e;
            (*pcVar1)();
            *(undefined4 *)(puVar7 + -4) = 0x80e706d;
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 == 0) {
              pcVar1 = *(code **)(**(int **)(local_c + 0xb88) + 0xd8);
              *(undefined4 *)(puVar7 + -4) = 0x80e708d;
              (*pcVar1)();
            }
            else {
              pcVar1 = *(code **)(**(int **)(local_c + 0xb88) + 0xd8);
              *(undefined4 *)(puVar7 + -4) = 0x80e70ab;
              (*pcVar1)();
            }
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e70ba;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e70c3;
            JUKELINUX1_DESATIVA_PROPAGANDA();
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e70d2;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -4) = 0x80e70e5;
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 == 0) {
              *(undefined4 *)(puVar7 + -4) = 0x80e70ee;
              JUKELINUX1_DESATIVA_PROPAGANDA();
            }
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e70fd;
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_NOMECAPACDTOCANDO = __JUKELINUX1__Ld1026;
          *(undefined4 *)(puVar7 + -4) = 0x80e7112;
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_NOMEDOCDTOCANDO = __JUKELINUX1__Ld1026;
          *(undefined4 *)(puVar7 + -4) = 0x80e7127;
          fpc_ansistr_decr_ref();
          iVar4 = U_JUKELINUX1_TOTALCDS;
          U_JUKELINUX1_NOMEDAMUSICATOCANDO = __JUKELINUX1__Ld1026;
          U_JUKELINUX1_KTOCAR = 1;
          if (0 < U_JUKELINUX1_TOTALCDS) {
            U_JUKELINUX1_KTOCAR = 0;
            do {
              U_JUKELINUX1_KTOCAR = U_JUKELINUX1_KTOCAR + 1;
              U_JUKELINUX1_KTOCAR2 = 0;
              do {
                U_JUKELINUX1_KTOCAR2 = U_JUKELINUX1_KTOCAR2 + 1;
                *(undefined4 *)(puVar7 + -4) = 0x80e7190;
                iVar5 = fpc_ansistr_compare_equal();
                if (iVar5 == 0) {
                  iVar9 = U_JUKELINUX1_KTOCAR * 0x240;
                  *(undefined4 *)(puVar7 + -4) = 0x80e71af;
                  fpc_ansistr_incr_ref();
                  *(undefined4 *)(puVar7 + -4) = 0x80e71b9;
                  fpc_ansistr_decr_ref();
                  iVar2 = U_JUKELINUX1_KTOCAR2;
                  iVar5 = U_JUKELINUX1_KTOCAR;
                  U_JUKELINUX1_NOMECAPACDTOCANDO = *(char **)(U_JUKELINUX1_ARQLOG + iVar9 + 0x204);
                  *(undefined4 *)(puVar7 + -4) = 0x80e71e2;
                  fpc_ansistr_incr_ref();
                  *(undefined4 *)(puVar7 + -4) = 0x80e71ec;
                  fpc_ansistr_decr_ref();
                  U_JUKELINUX1_NOMEDAMUSICATOCANDO =
                       (char *)(&U_JUKELINUX1_PASTACHAVE9)[iVar5 * 0x90 + iVar2];
                  *(undefined4 *)(puVar7 + -4) = 0x80e7203;
                  fpc_ansistr_decr_ref();
                  local_244 = (char *)0x0;
                  *(char ***)(puVar7 + -4) = &local_244;
                  *(undefined4 *)(puVar7 + -8) = 0x80e7248;
                  fpc_ansistr_copy();
                  *(undefined4 *)(puVar7 + -8) = 0x80e7253;
                  fpc_ansistr_incr_ref();
                  *(undefined4 *)(puVar7 + -8) = 0x80e725d;
                  fpc_ansistr_decr_ref();
                  puVar7 = puVar7 + -4;
                  U_JUKELINUX1_NOMEDOCDTOCANDO = local_244;
                }
              } while (U_JUKELINUX1_KTOCAR2 < 0x28);
            } while (U_JUKELINUX1_KTOCAR < iVar4);
          }
          *(undefined4 *)(puVar7 + -4) = 0x80e728c;
          fpc_ansistr_decr_ref();
          local_244 = (char *)0x0;
          *(char ***)(puVar7 + -4) = &local_244;
          *(undefined4 *)(puVar7 + -8) = 0x80e72b1;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar7 + -8) = 0x80e72c1;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -8) = 0x80e72d0;
            fpc_ansistr_decr_ref();
            local_244 = (char *)0x0;
            *(undefined4 *)(puVar7 + -8) = 0x80e72f0;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -8) = 0x80e730a;
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
            *(undefined4 *)(puVar7 + -8) = 0x80e7318;
            CONTROLS_TCONTROL____SHOW();
            U_JUKELINUX1_TOCANDOMUSICAGRATIS = 1;
          }
          else {
            *(undefined4 *)(puVar7 + -8) = 0x80e732f;
            fpc_ansistr_decr_ref();
            local_244 = (char *)0x0;
            *(undefined4 *)(puVar7 + -8) = 0x80e734f;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar7 + -8) = 0x80e735a;
            cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar3 != '\0') {
              *(undefined4 *)(puVar7 + -8) = 0x80e7369;
              fpc_ansistr_decr_ref();
              local_244 = (char *)0x0;
              *(undefined4 *)(puVar7 + -8) = 0x80e7389;
              fpc_ansistr_concat();
              *(undefined4 *)(puVar7 + -8) = 0x80e73a3;
              GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
              U_JUKELINUX1_TOCANDOMUSICAGRATIS = 0;
              *(undefined4 *)(puVar7 + -8) = 0x80e73b8;
              CONTROLS_TCONTROL____SHOW();
            }
          }
          *(undefined4 *)(puVar7 + -8) = 0x80e73c6;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)(puVar7 + -8) = 0x80e73e0;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          *(undefined4 *)(puVar7 + -8) = 0x80e73f4;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)(puVar7 + -8) = 0x80e73ff;
          fpc_ansistr_decr_ref();
          *(undefined4 *)(puVar7 + -8) = 0x80e741d;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          *(undefined4 *)(puVar7 + -8) = 0x80e7431;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)(puVar7 + -8) = 0x80e7440;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            *(undefined4 *)(puVar7 + -8) = 0x80e7452;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)(puVar7 + -8) = 0x80e7463;
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 == 0) {
              *(undefined4 *)(puVar7 + -8) = 0x80e7475;
              CONTROLS_TCONTROL____HIDE();
            }
            else {
              *(undefined4 *)(puVar7 + -8) = 0x80e7485;
              CONTROLS_TCONTROL____SHOW();
            }
          }
          *(undefined4 *)(puVar7 + -8) = 0x80e7490;
          fpc_ansistr_decr_ref();
          local_244 = (char *)0x0;
          *(char ***)(puVar7 + -8) = &local_244;
          *(undefined4 *)(puVar7 + -0xc) = 0x80e74b5;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e74c5;
          iVar5 = fpc_ansistr_compare_equal();
          iVar4 = U_JUKELINUX1_TOTALFRASE;
          piVar8 = (int *)(puVar7 + -8);
          if (iVar5 == 0) {
            U_JUKELINUX1_KFRASE = 1;
            if (0 < U_JUKELINUX1_TOTALFRASE) {
              U_JUKELINUX1_KFRASE = 0;
              do {
                U_JUKELINUX1_KFRASE = U_JUKELINUX1_KFRASE + 1;
                *(undefined4 *)(puVar7 + -0xc) = 0x80e75ff;
                fpc_ansistr_concat_multi();
              } while (U_JUKELINUX1_KFRASE < iVar4);
            }
          }
          else {
            U_JUKELINUX1_KFRASE = 1;
            if (0 < U_JUKELINUX1_TOTALFRASE) {
              U_JUKELINUX1_KFRASE = 0;
              do {
                U_JUKELINUX1_KFRASE = U_JUKELINUX1_KFRASE + 1;
                *(undefined4 *)(puVar7 + -0xc) = 0x80e755f;
                fpc_ansistr_concat_multi();
              } while (U_JUKELINUX1_KFRASE < iVar4);
            }
          }
          U_JUKELINUX1_POSFRASE = 0;
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7620;
          iVar4 = fpc_ansistr_compare_equal();
          if ((iVar4 == 0) && (U_JUKELINUX1_ESTANOMENU != '\0')) {
            *(undefined4 *)(puVar7 + -0xc) = 0x80e763b;
            CONTROLS_TCONTROL____SHOW();
            *(undefined4 *)(puVar7 + -0xc) = 0x80e7649;
            CONTROLS_TCONTROL____BRINGTOFRONT();
          }
          U_JUKELINUX1_QUANTIDADESDEMUSICASTOCADAS = U_JUKELINUX1_QUANTIDADESDEMUSICASTOCADAS + 1;
          *(undefined4 *)(puVar7 + -0xc) = 0x80e765a;
          fpc_ansistr_decr_ref();
          local_244 = (char *)0x0;
          *(undefined4 *)(puVar7 + -0xc) = 0x80e767a;
          fpc_ansistr_concat();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7690;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76a0;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76aa;
          SYSTEM_REWRITE_TEXT();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76af;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76ba;
          fpc_ansistr_decr_ref();
          local_244 = (char *)0x0;
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76d4;
          JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76e9;
          fpc_write_text_ansistr();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76ee;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76f8;
          fpc_writeln_end();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e76fd;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7708;
          fpc_ansistr_decr_ref();
          local_244 = (char *)0x0;
          *(undefined4 *)(puVar7 + -0xc) = 0x80e771d;
          fpc_ansistr_decr_ref();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7737;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7748;
          JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e775d;
          fpc_write_text_ansistr();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7762;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e776c;
          fpc_writeln_end();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7771;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e777b;
          SYSTEM_FLUSH_TEXT();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e7780;
          fpc_iocheck();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e778a;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)(puVar7 + -0xc) = 0x80e778f;
          fpc_iocheck();
        }
        else {
          piStack_380 = (int *)0x80e77ad;
          (**(code **)(**(int **)(local_c + 0xb90) + 0xd8))();
          piVar8 = &iStack_37c;
        }
      }
      else {
        piStack_380 = (int *)0x80e77cb;
        (**(code **)(**(int **)(local_c + 0xb90) + 0xd8))();
        piVar8 = &iStack_37c;
      }
    }
  }
  piVar8[-1] = 0x80e77ee;
  fpc_popaddrstack();
  piVar8[-1] = 0x80e77f9;
  fpc_ansistr_decr_ref();
  piVar8[-1] = 0x80e780e;
  fpc_ansistr_decr_ref();
  piVar8[-1] = 0x80e7823;
  fpc_ansistr_decr_ref();
  piVar8[-1] = 0x80e7838;
  fpc_ansistr_decr_ref();
  local_244 = (char *)0x0;
  piVar8[-1] = 0x80e784d;
  fpc_ansistr_decr_ref();
  local_240 = 0;
  piVar8[-1] = 0x80e7862;
  fpc_ansistr_decr_ref();
  local_13c = 0;
  piVar8[-1] = 0x80e7877;
  fpc_ansistr_decr_ref();
  local_138[0] = 0;
  if (*piVar8 != 0) {
    *piVar8 = 0x80e788b;
    fpc_reraise();
  }
  return;
}

