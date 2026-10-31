// JUKELINUX1_CARREGANDO_CARTOES  @ 080ad730

void JUKELINUX1_CARREGANDO_CARTOES(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  longdouble lVar6;
  int aiStack_280 [6];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  aiStack_280[5] = 0x80ad7a0;
  fpc_pushexceptaddr();
  aiStack_280[5] = 0x80ad7a5;
  aiStack_280[5] = fpc_setjmp();
  piVar5 = aiStack_280 + 5;
  if (aiStack_280[5] == 0) {
    local_c = 0;
    do {
      local_c = local_c + 1;
      (&DAT_0930303a)[local_c * 0x26] = 0;
      *(undefined1 *)((int)&U_JUKELINUX1_VOLUMEPELOPAINEL + local_c * 0x26 + 1) = 0;
      (&DAT_0930305e)[local_c * 0x26] = 0;
    } while (local_c < 90000);
    U_JUKELINUX1_KMMCARTAO = 0;
    FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
    iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    piVar5 = aiStack_280 + 5;
    if (-1 < iVar3 + -1) {
      local_8 = -1;
      piVar5 = aiStack_280 + 5;
      do {
        local_8 = local_8 + 1;
        *(undefined4 *)((int)piVar5 + -4) = 0x80ad843;
        fpc_ansistr_decr_ref();
        pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
        *(undefined4 *)((int)piVar5 + -4) = 0x80ad878;
        (*pcVar1)();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ad885;
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 != 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x80ad895;
          fpc_ansistr_decr_ref();
          pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
          *(undefined4 *)((int)piVar5 + -4) = 0x80ad8ca;
          (*pcVar1)();
          *(undefined4 *)((int)piVar5 + -4) = 0x80ad8d7;
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 != 0) {
            *(undefined4 *)((int)piVar5 + -4) = 0x80ad8e7;
            fpc_ansistr_decr_ref();
            *(undefined4 *)((int)piVar5 + -4) = 0x80ad8f6;
            fpc_ansistr_decr_ref();
            *(undefined4 *)((int)piVar5 + -4) = 0x80ad905;
            fpc_ansistr_decr_ref();
            pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
            *(undefined4 *)((int)piVar5 + -4) = 0x80ad93a;
            (*pcVar1)();
            *(undefined4 *)((int)piVar5 + -4) = 0x80ad945;
            SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
            *(undefined4 *)((int)piVar5 + -4) = 0x80ad950;
            SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
            *(undefined4 *)((int)piVar5 + -4) = 0x80ad95d;
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 == 0) {
              *(undefined4 *)((int)piVar5 + -4) = 0x80ad96d;
              fpc_ansistr_decr_ref();
              pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
              *(undefined4 *)((int)piVar5 + -4) = 0x80ad9a2;
              (*pcVar1)();
              *(undefined4 *)((int)piVar5 + -4) = 0x80ad9b5;
              fpc_ansistr_concat();
              *(undefined4 *)((int)piVar5 + -4) = 0x80ad9bf;
              cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
              if (cVar2 != '\0') {
                *(undefined4 *)((int)piVar5 + -4) = 0x80ad9dd;
                FPC_ANSISTR_TO_SHORTSTR();
                *(undefined4 *)((int)piVar5 + -4) = 0x80ad9ed;
                OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING();
                *(undefined4 *)((int)piVar5 + -4) = 0x80ad9fc;
                fpc_reset_typed();
                *(undefined4 *)((int)piVar5 + -4) = 0x80ada01;
                fpc_iocheck();
                *(undefined4 *)((int)piVar5 + -4) = 0;
                *(undefined4 *)((int)piVar5 + -8) = 0;
                *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada0f;
                SYSTEM_SEEK_file_INT64();
                *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada14;
                fpc_iocheck();
                *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada28;
                FPC_TYPED_READ();
                *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada2d;
                fpc_iocheck();
                piVar5 = (int *)((int)piVar5 + -8);
                local_10 = 0;
                while( true ) {
                  *(undefined4 *)((int)piVar5 + -4) = 0x80adad2;
                  cVar2 = SYSTEM_EOF_file__BOOLEAN();
                  *(undefined4 *)((int)piVar5 + -4) = 0x80adad9;
                  fpc_iocheck();
                  if (cVar2 != '\0') break;
                  local_10 = local_10 + 1;
                  *(int *)((int)piVar5 + -4) = local_10 >> 0x1f;
                  *(int *)((int)piVar5 + -8) = local_10;
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada53;
                  SYSTEM_SEEK_file_INT64();
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada58;
                  fpc_iocheck();
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada6c;
                  FPC_TYPED_READ();
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada71;
                  fpc_iocheck();
                  U_JUKELINUX1_KMMCARTAO = U_JUKELINUX1_KMMCARTAO + 1;
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada7f;
                  fpc_ansistr_decr_ref();
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80ada8e;
                  fpc_ansistr_decr_ref();
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80adaa2;
                  fpc_shortstr_to_ansistr();
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80adaad;
                  JUKELINUX1_DESCRIPTASUPER_ANSISTRING__ANSISTRING();
                  *(undefined4 *)((int)piVar5 + -0xc) = 0x80adac8;
                  FPC_ANSISTR_TO_SHORTSTR();
                  piVar5 = (int *)((int)piVar5 + -8);
                }
                *(undefined4 *)((int)piVar5 + -4) = 0x80adaeb;
                OBJPAS_CLOSEFILE_file();
                *(undefined4 *)((int)piVar5 + -4) = 0x80adaf0;
                fpc_iocheck();
              }
            }
          }
        }
      } while (local_8 < iVar3 + -1);
    }
    U_JUKELINUX1_TOTMMCARTAO = U_JUKELINUX1_KMMCARTAO;
    *(undefined4 *)((int)piVar5 + -4) = 0x80adb18;
    fpc_ansistr_concat();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adb22;
    cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar2 == '\0') {
      *(undefined4 *)((int)piVar5 + -4) = 0x80adb40;
      FPC_ANSISTR_TO_SHORTSTR();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adb50;
      OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adb5f;
      FPC_REWRITE_TYPED();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adb64;
      fpc_iocheck();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adb6c;
      fpc_ansistr_decr_ref();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adb7e;
      fpc_ansistr_decr_ref();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adb8d;
      lVar6 = (longdouble)SYSUTILS_DATE__TDATETIME();
      *(double *)((int)piVar5 + -8) = (double)lVar6;
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adb9e;
      SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adbac;
      JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adbbe;
      FPC_ANSISTR_TO_SHORTSTR();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adbc9;
      fpc_ansistr_decr_ref();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adbe3;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adbf1;
      JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
      U_JUKELINUX1_ACARM[0x1f] = 0;
      U_JUKELINUX1_ACARM[0x24] = 0;
      *(undefined4 *)((int)piVar5 + -0xc) = 0;
      *(undefined4 *)((int)piVar5 + -0x10) = 0;
      *(undefined4 *)((int)piVar5 + -0x14) = 0x80adc0d;
      SYSTEM_SEEK_file_INT64();
      *(undefined4 *)((int)piVar5 + -0x14) = 0x80adc12;
      fpc_iocheck();
      *(undefined4 *)((int)piVar5 + -0x14) = 0x80adc26;
      FPC_TYPED_WRITE();
      *(undefined4 *)((int)piVar5 + -0x14) = 0x80adc2b;
      fpc_iocheck();
      *(undefined4 *)((int)piVar5 + -0x14) = 0x80adc35;
      OBJPAS_CLOSEFILE_file();
      *(undefined4 *)((int)piVar5 + -0x14) = 0x80adc3a;
      fpc_iocheck();
      piVar5 = (int *)((int)piVar5 + -0x10);
    }
    *(undefined4 *)((int)piVar5 + -4) = 0x80adc44;
    cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar2 != '\0') {
      *(undefined4 *)((int)piVar5 + -4) = 0x80adc62;
      FPC_ANSISTR_TO_SHORTSTR();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adc72;
      OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adc81;
      fpc_reset_typed();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adc86;
      fpc_iocheck();
      local_10 = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0;
      *(undefined4 *)((int)piVar5 + -8) = 0;
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adc9f;
      SYSTEM_SEEK_file_INT64();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adca4;
      fpc_iocheck();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adcb8;
      FPC_TYPED_READ();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adcbd;
      fpc_iocheck();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adcc8;
      fpc_ansistr_decr_ref();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adce2;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -0xc) = 0x80adcf0;
      JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
      piVar5 = (int *)((int)piVar5 + -8);
      while( true ) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80adf11;
        cVar2 = SYSTEM_EOF_file__BOOLEAN();
        *(undefined4 *)((int)piVar5 + -4) = 0x80adf18;
        fpc_iocheck();
        if (cVar2 != '\0') break;
        local_10 = local_10 + 1;
        *(int *)((int)piVar5 + -4) = local_10 >> 0x1f;
        *(int *)((int)piVar5 + -8) = local_10;
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80add0f;
        SYSTEM_SEEK_file_INT64();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80add14;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80add28;
        FPC_TYPED_READ();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80add2d;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80add38;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80add52;
        fpc_shortstr_to_ansistr();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80add60;
        JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
        iVar3 = U_JUKELINUX1_TOTMMCARTAO;
        if (0 < U_JUKELINUX1_TOTMMCARTAO) {
          local_14 = 0;
          do {
            local_14 = local_14 + 1;
            *(undefined4 *)((int)piVar5 + -0xc) = 0x80add8a;
            fpc_ansistr_decr_ref();
            *(undefined4 *)((int)piVar5 + -0xc) = 0x80addab;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)((int)piVar5 + -0xc) = 0x80addb9;
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 == 0) {
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80addcc;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80adde1;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80addfb;
              fpc_shortstr_to_ansistr();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80ade0c;
              JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80ade28;
              FPC_ANSISTR_TO_SHORTSTR();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80ade33;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80ade48;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80ade62;
              fpc_shortstr_to_ansistr();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80ade73;
              JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
              *(undefined4 *)((int)piVar5 + -0xc) = 0x80ade8f;
              FPC_ANSISTR_TO_SHORTSTR();
            }
          } while (local_14 < iVar3);
        }
        U_JUKELINUX1_KMMCARTAO = U_JUKELINUX1_KMMCARTAO + 1;
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80adea9;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80adebe;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80aded8;
        fpc_shortstr_to_ansistr();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80adee9;
        JUKELINUX1_DESCRIPTASUPER_ANSISTRING__ANSISTRING();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80adf07;
        FPC_ANSISTR_TO_SHORTSTR();
        piVar5 = (int *)((int)piVar5 + -8);
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80adf2a;
      OBJPAS_CLOSEFILE_file();
      *(undefined4 *)((int)piVar5 + -4) = 0x80adf2f;
      fpc_iocheck();
    }
    *(undefined4 *)((int)piVar5 + -4) = 0x80adf3a;
    fpc_ansistr_decr_ref();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adf5a;
    fpc_ansistr_concat();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adf70;
    FPC_ANSISTR_TO_SHORTSTR();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adf80;
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adf8a;
    SYSTEM_REWRITE_TEXT();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adf8f;
    fpc_iocheck();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adfa1;
    fpc_write_text_ansistr();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adfa6;
    fpc_iocheck();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adfb0;
    fpc_writeln_end();
    *(undefined4 *)((int)piVar5 + -4) = 0x80adfb5;
    fpc_iocheck();
    iVar3 = U_JUKELINUX1_TOTMMCARTAO;
    if (0 < U_JUKELINUX1_TOTMMCARTAO) {
      local_14 = 0;
      do {
        local_14 = local_14 + 1;
        *(undefined4 *)((int)piVar5 + -4) = 0x80adfde;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80adff3;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae014;
        fpc_shortstr_to_ansistr();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae036;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae057;
        fpc_shortstr_to_ansistr();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae079;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae09a;
        fpc_shortstr_to_ansistr();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae0bc;
        fpc_ansistr_concat_multi();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae0d1;
        fpc_write_text_ansistr();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae0d6;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae0e0;
        fpc_writeln_end();
        *(undefined4 *)((int)piVar5 + -4) = 0x80ae0e5;
        fpc_iocheck();
      } while (local_14 < iVar3);
    }
    *(undefined4 *)((int)piVar5 + -4) = 0x80ae0f8;
    OBJPAS_CLOSEFILE_TEXT();
    *(undefined4 *)((int)piVar5 + -4) = 0x80ae0fd;
    fpc_iocheck();
  }
  piVar5[-1] = 0x80ae102;
  fpc_popaddrstack();
  piVar5[-1] = 0x80ae10d;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae122;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae137;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae14c;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae15e;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae16d;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae17c;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae18b;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80ae19a;
  fpc_ansistr_decr_ref();
  if (*piVar5 != 0) {
    *piVar5 = 0x80ae1ab;
    fpc_reraise();
  }
  return;
}

