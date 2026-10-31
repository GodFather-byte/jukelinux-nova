// JUKELINUX1_CARREGANDO_CDS  @ 0809ab60

/* WARNING: Removing unreachable block (ram,0x0809c537) */
/* WARNING: Removing unreachable block (ram,0x0809c53f) */
/* WARNING: Removing unreachable block (ram,0x0809c5be) */
/* WARNING: Removing unreachable block (ram,0x0809c5c6) */

void JUKELINUX1_CARREGANDO_CDS(void)

{
  code *pcVar1;
  bool bVar2;
  undefined1 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int *piVar11;
  undefined1 *puVar12;
  longdouble lVar13;
  int aiStack_4790c0 [4];
  undefined4 uStack_478f9c;
  undefined4 auStack_478f98 [65];
  undefined4 uStack_478e94;
  undefined4 auStack_478e90 [59];
  undefined *puStack_478da4;
  undefined4 uStack_478da0;
  char *pcStack_478d9c;
  undefined4 uStack_478d98;
  undefined8 uStack_478d94;
  int iStack_478d8c;
  undefined4 auStack_478d88 [65];
  undefined4 uStack_478c84;
  undefined4 uStack_478c80;
  int iStack_478c7c;
  int iStack_478c78;
  int iStack_478c74;
  int aiStack_478c70 [66];
  int iStack_478b68;
  undefined4 uStack_478b64;
  int iStack_478b60;
  undefined *puStack_478b5c;
  int aiStack_478b58 [11];
  char cStack_478b2c;
  int iStack_478b28;
  int iStack_478b24;
  undefined4 uStack_478b20;
  int aiStack_478b1c [2000];
  int aiStack_476bdc [2001];
  int iStack_474c98;
  int iStack_474c94;
  int iStack_474c90;
  int aiStack_474c8c [8000];
  int aiStack_46cf8c [7871];
  int aiStack_465490 [81];
  int aiStack_46534c [4];
  int aiStack_46533c [45];
  int iStack_465288;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  aiStack_4790c0[3] = 0x809aba0;
  fpc_initialize();
  aiStack_4790c0[3] = 0x809abb0;
  fpc_initialize();
  aiStack_4790c0[3] = 0x809abc0;
  fpc_initialize();
  aiStack_474c8c[0] = 0;
  aiStack_4790c0[3] = 0x809abda;
  fpc_initialize();
  uStack_478b20 = 0;
  iStack_478b24 = 0;
  uStack_478f9c = 0;
  auStack_478f98[0] = 0;
  uStack_478e94 = 0;
  auStack_478e90[0] = 0;
  iStack_478d8c = 0;
  auStack_478d88[0] = 0;
  uStack_478c84 = 0;
  uStack_478c80 = 0;
  iStack_478c7c = 0;
  iStack_478c78 = 0;
  iStack_478c74 = 0;
  aiStack_478c70[0] = 0;
  aiStack_478c70[1] = 0;
  iStack_478b68 = 0;
  aiStack_478b58[0] = 0;
  aiStack_4790c0[3] = 0x809ac9a;
  fpc_pushexceptaddr();
  aiStack_4790c0[3] = 0x809ac9f;
  aiStack_4790c0[3] = fpc_setjmp();
  piVar11 = aiStack_4790c0 + 3;
  if (aiStack_4790c0[3] == 0) {
    CONTROLS_TCONTROL____REFRESH();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
    piVar11 = aiStack_4790c0 + 3;
    local_8 = 0;
    do {
      local_8 = local_8 + 1;
      U_JUKELINUX1_ARQLOG[local_8 * 0x240 + 0x1f0] = 0;
      fpc_ansistr_decr_ref();
      *(undefined4 *)(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1f8) = 0;
      fpc_ansistr_decr_ref();
      *(undefined4 *)(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x1fc) = 0;
      fpc_ansistr_decr_ref();
      *(undefined4 *)(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x200) = 0;
      fpc_ansistr_decr_ref();
      *(undefined4 *)(U_JUKELINUX1_ARQLOG + local_8 * 0x240 + 0x204) = 0;
      U_JUKELINUX1_ARQLOG[local_8 * 0x240 + 0x208] = 0;
      local_c = 0;
      do {
        local_c = local_c + 1;
        fpc_ansistr_decr_ref();
        *(undefined4 *)(local_8 * 0x240 + 0x8e91144 + local_c * 4) = 0;
      } while (local_c < 0x28);
      local_c = 0;
      do {
        local_c = local_c + 1;
        fpc_ansistr_decr_ref();
        (&U_JUKELINUX1_PASTACHAVE9)[local_8 * 0x90 + local_c] = 0;
      } while (local_c < 0x28);
      (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] = 0;
      *(undefined1 *)(&U_JUKELINUX1_SERIAL + local_8 * 0x90) = 0;
      *(undefined1 *)(&U_JUKELINUX1_TECLAMUSICAMAIS + local_8 * 0x90) = 0;
      local_c = 0;
      do {
        local_c = local_c + 1;
        (&U_JUKELINUX1_TECLACDMENOS)[local_8 * 0x90 + local_c] = 0;
      } while (local_c < 0x28);
      *(undefined1 *)(&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x90) = 0;
      *(undefined1 *)((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) = 0;
      *(undefined1 *)(&U_JUKELINUX1_BAIRROSTR + local_8 * 0x90) = 0;
      (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] = 0;
    } while (local_8 < 8000);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    (**(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc))();
    CONTROLS_TCONTROL____REFRESH();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    cVar4 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar4 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
    U_JUKELINUX1_KMAT = 0;
    iVar5 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    if (-1 < iVar5 + -1) {
      local_8 = -1;
      piVar11 = aiStack_4790c0 + 3;
      do {
        local_8 = local_8 + 1;
        *(undefined4 *)((int)piVar11 + -4) = 0x809af66;
        fpc_ansistr_decr_ref();
        aiStack_478b58[0] = 0;
        pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
        *(undefined4 *)((int)piVar11 + -4) = 0x809afa1;
        (*pcVar1)();
        *(undefined4 *)((int)piVar11 + -4) = 0x809afb1;
        iVar6 = fpc_ansistr_compare_equal();
        if (iVar6 != 0) {
          *(undefined4 *)((int)piVar11 + -4) = 0x809afc4;
          fpc_ansistr_decr_ref();
          aiStack_478b58[0] = 0;
          pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
          *(undefined4 *)((int)piVar11 + -4) = 0x809afff;
          (*pcVar1)();
          *(undefined4 *)((int)piVar11 + -4) = 0x809b00f;
          iVar6 = fpc_ansistr_compare_equal();
          if (iVar6 != 0) {
            U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + 1;
            uStack_478b64 = U_JUKELINUX1_PASTAMUSICAS;
            *(undefined4 *)((int)piVar11 + -4) = 0x809b033;
            fpc_ansistr_decr_ref();
            aiStack_478b58[0] = 0;
            *(int **)((int)piVar11 + -4) = aiStack_478b58;
            *(undefined4 *)((int)piVar11 + -8) = 0x809b04f;
            fpc_ansistr_decr_ref();
            iStack_478b68 = 0;
            pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
            *(undefined4 *)((int)piVar11 + -8) = 0x809b08a;
            (*pcVar1)();
            *(undefined4 *)((int)piVar11 + -8) = 0x809b0a5;
            fpc_ansistr_decr_ref();
            iStack_478b68 = 0;
            pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
            *(undefined4 *)((int)piVar11 + -8) = 0x809b0e0;
            (*pcVar1)();
            *(undefined4 *)((int)piVar11 + -8) = 0x809b0f2;
            fpc_ansistr_copy();
            iStack_478b60 = aiStack_478b58[0];
            puStack_478b5c = &__JUKELINUX1__Ld115;
            *(undefined4 *)((int)piVar11 + -8) = 0x809b12a;
            fpc_ansistr_concat_multi();
            *(undefined4 *)((int)piVar11 + -8) = 0x809b135;
            fpc_ansistr_decr_ref();
            iStack_478b68 = 0;
            *(int **)((int)piVar11 + -8) = &iStack_478b68;
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b151;
            fpc_ansistr_decr_ref();
            aiStack_478b58[0] = 0;
            pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b18c;
            (*pcVar1)();
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b1a7;
            fpc_ansistr_decr_ref();
            aiStack_478b58[0] = 0;
            pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b1e2;
            (*pcVar1)();
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b1f4;
            fpc_ansistr_copy();
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b215;
            fpc_ansistr_concat();
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b220;
            fpc_ansistr_decr_ref();
            iStack_478b68 = 0;
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b246;
            SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b251;
            fpc_ansistr_incr_ref();
            iVar6 = U_JUKELINUX1_KMAT * 0x240;
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b268;
            fpc_ansistr_decr_ref();
            *(int *)(U_JUKELINUX1_ARQLOG + iVar6 + 0x1fc) = iStack_478b68;
            *(undefined4 *)((int)piVar11 + -0xc) = 0x809b28c;
            iVar6 = SYSTEM_POS_CHAR_ANSISTRING__LONGINT();
            puVar9 = (undefined1 *)((int)piVar11 + -8);
            piVar11 = (int *)((int)piVar11 + -8);
            if (0 < iVar6) {
              U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + -1;
              piVar11 = (int *)puVar9;
            }
          }
        }
      } while (local_8 < iVar5 + -1);
    }
    U_JUKELINUX1_TOTALCDS = U_JUKELINUX1_KMAT;
    *(undefined4 *)((int)piVar11 + -4) = 0x809b2be;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    pcVar1 = *(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809b2dd;
    (*pcVar1)();
    *(undefined4 *)((int)piVar11 + -4) = 0x809b2e7;
    CONTROLS_TCONTROL____REFRESH();
    pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809b2fa;
    (*pcVar1)();
    iVar5 = U_JUKELINUX1_TOTALCDS;
    if (0 < U_JUKELINUX1_TOTALCDS) {
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        *(undefined4 *)((int)piVar11 + -4) = 0x809b32e;
        fpc_ansistr_decr_ref();
        iStack_478b68 = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809b34e;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b364;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b374;
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b37e;
        SYSTEM_REWRITE_TEXT();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b383;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3a1;
        fpc_write_text_ansistr();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3a6;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3b0;
        fpc_writeln_end();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3b5;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3bf;
        SYSTEM_FLUSH_TEXT();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3c4;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3ce;
        OBJPAS_CLOSEFILE_TEXT();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3d3;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809b3e7;
        cVar4 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
        if (cVar4 != '\0') {
          *(undefined4 *)((int)piVar11 + -4) = 0x809b40e;
          FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
          U_JUKELINUX1_KMATMUSICA = 0;
          *(undefined4 *)((int)piVar11 + -4) = 0x809b428;
          iVar6 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
          if (-1 < iVar6 + -1) {
            local_c = -1;
            puVar10 = (undefined1 *)piVar11;
            do {
              local_c = local_c + 1;
              *(undefined4 *)(puVar10 + -4) = 0x809b44e;
              fpc_ansistr_decr_ref();
              iStack_478b68 = 0;
              pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
              *(undefined4 *)(puVar10 + -4) = 0x809b489;
              (*pcVar1)();
              *(undefined4 *)(puVar10 + -4) = 0x809b499;
              iVar7 = fpc_ansistr_compare_equal();
              piVar11 = (int *)puVar10;
              if (iVar7 != 0) {
                *(undefined4 *)(puVar10 + -4) = 0x809b4ac;
                fpc_ansistr_decr_ref();
                iStack_478b68 = 0;
                pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                *(undefined4 *)(puVar10 + -4) = 0x809b4e7;
                (*pcVar1)();
                *(undefined4 *)(puVar10 + -4) = 0x809b4f7;
                iVar7 = fpc_ansistr_compare_equal();
                if (iVar7 != 0) {
                  *(undefined4 *)(puVar10 + -4) = 0x809b50a;
                  fpc_ansistr_decr_ref();
                  iStack_478b68 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809b51f;
                  fpc_ansistr_decr_ref();
                  aiStack_478c70[1] = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809b534;
                  fpc_ansistr_decr_ref();
                  aiStack_478c70[0] = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809b56f;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809b580;
                  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809b591;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809b5a1;
                  iVar7 = fpc_ansistr_compare_equal();
                  if ((iVar7 == 0) && (U_JUKELINUX1_KMATMUSICA + 1 < 0x29)) {
                    U_JUKELINUX1_KMATMUSICA = U_JUKELINUX1_KMATMUSICA + 1;
                    *(undefined4 *)(puVar10 + -4) = 0x809b5c9;
                    fpc_ansistr_decr_ref();
                    aiStack_478c70[0] = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809b604;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809b638;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809b643;
                    fpc_ansistr_decr_ref();
                    aiStack_478c70[0] = 0;
                    *(int **)(puVar10 + -4) = aiStack_478c70;
                    *(undefined4 *)(puVar10 + -8) = 0x809b65f;
                    fpc_ansistr_decr_ref();
                    aiStack_478c70[1] = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809b69a;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809b6b7;
                    fpc_ansistr_decr_ref();
                    aiStack_478c70[1] = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809b6f2;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809b704;
                    fpc_ansistr_copy();
                    *(undefined4 *)(puVar10 + -8) = 0x809b70f;
                    fpc_ansistr_incr_ref();
                    iVar7 = U_JUKELINUX1_KMATMUSICA;
                    *(undefined4 *)(puVar10 + -8) = 0x809b72a;
                    fpc_ansistr_decr_ref();
                    (&U_JUKELINUX1_PASTACHAVE9)[local_8 * 0x90 + iVar7] = aiStack_478c70[0];
                    *(undefined4 *)(puVar10 + -8) = 0x809b755;
                    FPC_SHORTSTR_TO_SHORTSTR();
                    puVar10 = puVar10 + -4;
                  }
                  *(undefined4 *)(puVar10 + -4) = 0x809b760;
                  fpc_ansistr_decr_ref();
                  aiStack_478c70[0] = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809b775;
                  fpc_ansistr_decr_ref();
                  aiStack_478c70[1] = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809b78a;
                  fpc_ansistr_decr_ref();
                  iStack_478c74 = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809b7c5;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809b7d6;
                  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809b7e7;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809b7f7;
                  iVar7 = fpc_ansistr_compare_equal();
                  if ((iVar7 == 0) && (U_JUKELINUX1_KMATMUSICA + 1 < 0x29)) {
                    U_JUKELINUX1_KMATMUSICA = U_JUKELINUX1_KMATMUSICA + 1;
                    *(undefined4 *)(puVar10 + -4) = 0x809b81f;
                    fpc_ansistr_decr_ref();
                    iStack_478c74 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809b85a;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809b88e;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809b899;
                    fpc_ansistr_decr_ref();
                    iStack_478c74 = 0;
                    *(int **)(puVar10 + -4) = &iStack_478c74;
                    *(undefined4 *)(puVar10 + -8) = 0x809b8b5;
                    fpc_ansistr_decr_ref();
                    aiStack_478c70[0] = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809b8f0;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809b90d;
                    fpc_ansistr_decr_ref();
                    aiStack_478c70[0] = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809b948;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809b95a;
                    fpc_ansistr_copy();
                    *(undefined4 *)(puVar10 + -8) = 0x809b965;
                    fpc_ansistr_incr_ref();
                    iVar7 = U_JUKELINUX1_KMATMUSICA;
                    *(undefined4 *)(puVar10 + -8) = 0x809b980;
                    fpc_ansistr_decr_ref();
                    (&U_JUKELINUX1_PASTACHAVE9)[local_8 * 0x90 + iVar7] = iStack_478c74;
                    *(undefined4 *)(puVar10 + -8) = 0x809b9ab;
                    FPC_SHORTSTR_TO_SHORTSTR();
                    puVar10 = puVar10 + -4;
                  }
                  *(undefined4 *)(puVar10 + -4) = 0x809b9b6;
                  fpc_ansistr_decr_ref();
                  iStack_478c74 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809b9cb;
                  fpc_ansistr_decr_ref();
                  aiStack_478c70[0] = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809b9e0;
                  fpc_ansistr_decr_ref();
                  iStack_478c78 = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809ba1b;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809ba2c;
                  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809ba3d;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809ba4d;
                  iVar7 = fpc_ansistr_compare_equal();
                  if ((iVar7 == 0) && (U_JUKELINUX1_KMATMUSICA + 1 < 0x29)) {
                    U_JUKELINUX1_KMATMUSICA = U_JUKELINUX1_KMATMUSICA + 1;
                    *(undefined4 *)(puVar10 + -4) = 0x809ba75;
                    fpc_ansistr_decr_ref();
                    iStack_478c78 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809bab0;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809bae4;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809baef;
                    fpc_ansistr_decr_ref();
                    iStack_478c78 = 0;
                    *(int **)(puVar10 + -4) = &iStack_478c78;
                    *(undefined4 *)(puVar10 + -8) = 0x809bb0b;
                    fpc_ansistr_decr_ref();
                    iStack_478c74 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809bb46;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809bb63;
                    fpc_ansistr_decr_ref();
                    iStack_478c74 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809bb9e;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809bbb0;
                    fpc_ansistr_copy();
                    *(undefined4 *)(puVar10 + -8) = 0x809bbbb;
                    fpc_ansistr_incr_ref();
                    iVar7 = U_JUKELINUX1_KMATMUSICA;
                    *(undefined4 *)(puVar10 + -8) = 0x809bbd6;
                    fpc_ansistr_decr_ref();
                    (&U_JUKELINUX1_PASTACHAVE9)[local_8 * 0x90 + iVar7] = iStack_478c78;
                    *(undefined4 *)(puVar10 + -8) = 0x809bc01;
                    FPC_SHORTSTR_TO_SHORTSTR();
                    puVar10 = puVar10 + -4;
                  }
                  *(undefined4 *)(puVar10 + -4) = 0x809bc0c;
                  fpc_ansistr_decr_ref();
                  iStack_478c78 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809bc21;
                  fpc_ansistr_decr_ref();
                  iStack_478c74 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809bc36;
                  fpc_ansistr_decr_ref();
                  iStack_478c7c = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809bc71;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809bc82;
                  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809bc93;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809bca3;
                  iVar7 = fpc_ansistr_compare_equal();
                  if ((iVar7 == 0) && (U_JUKELINUX1_KMATMUSICA + 1 < 0x29)) {
                    U_JUKELINUX1_KMATMUSICA = U_JUKELINUX1_KMATMUSICA + 1;
                    *(undefined4 *)(puVar10 + -4) = 0x809bccb;
                    fpc_ansistr_decr_ref();
                    iStack_478c7c = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809bd06;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809bd3a;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809bd45;
                    fpc_ansistr_decr_ref();
                    iStack_478c7c = 0;
                    *(int **)(puVar10 + -4) = &iStack_478c7c;
                    *(undefined4 *)(puVar10 + -8) = 0x809bd61;
                    fpc_ansistr_decr_ref();
                    iStack_478c78 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809bd9c;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809bdb9;
                    fpc_ansistr_decr_ref();
                    iStack_478c78 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809bdf4;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809be06;
                    fpc_ansistr_copy();
                    *(undefined4 *)(puVar10 + -8) = 0x809be11;
                    fpc_ansistr_incr_ref();
                    iVar7 = U_JUKELINUX1_KMATMUSICA;
                    *(undefined4 *)(puVar10 + -8) = 0x809be2c;
                    fpc_ansistr_decr_ref();
                    (&U_JUKELINUX1_PASTACHAVE9)[local_8 * 0x90 + iVar7] = iStack_478c7c;
                    *(undefined4 *)(puVar10 + -8) = 0x809be57;
                    FPC_SHORTSTR_TO_SHORTSTR();
                    puVar10 = puVar10 + -4;
                  }
                  *(undefined4 *)(puVar10 + -4) = 0x809be62;
                  fpc_ansistr_decr_ref();
                  iStack_478c7c = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809be77;
                  fpc_ansistr_decr_ref();
                  iStack_478c78 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809be8c;
                  fpc_ansistr_decr_ref();
                  uStack_478c80 = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809bec7;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809bed8;
                  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809bee9;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809bef9;
                  iVar7 = fpc_ansistr_compare_equal();
                  if ((iVar7 == 0) && (U_JUKELINUX1_KMATMUSICA + 1 < 0x29)) {
                    U_JUKELINUX1_KMATMUSICA = U_JUKELINUX1_KMATMUSICA + 1;
                    *(undefined4 *)(puVar10 + -4) = 0x809bf21;
                    fpc_ansistr_decr_ref();
                    uStack_478c80 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809bf5c;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809bf90;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809bf9b;
                    fpc_ansistr_decr_ref();
                    uStack_478c80 = 0;
                    *(undefined4 **)(puVar10 + -4) = &uStack_478c80;
                    *(undefined4 *)(puVar10 + -8) = 0x809bfb7;
                    fpc_ansistr_decr_ref();
                    iStack_478c7c = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809bff2;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809c00f;
                    fpc_ansistr_decr_ref();
                    iStack_478c7c = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -8) = 0x809c04a;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -8) = 0x809c05c;
                    fpc_ansistr_copy();
                    *(undefined4 *)(puVar10 + -8) = 0x809c067;
                    fpc_ansistr_incr_ref();
                    iVar7 = U_JUKELINUX1_KMATMUSICA;
                    *(undefined4 *)(puVar10 + -8) = 0x809c082;
                    fpc_ansistr_decr_ref();
                    (&U_JUKELINUX1_PASTACHAVE9)[local_8 * 0x90 + iVar7] = uStack_478c80;
                    *(undefined4 *)(puVar10 + -8) = 0x809c0ad;
                    FPC_SHORTSTR_TO_SHORTSTR();
                    puVar10 = puVar10 + -4;
                  }
                  *(undefined4 *)(puVar10 + -4) = 0x809c0b8;
                  fpc_ansistr_decr_ref();
                  uStack_478c80 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809c0cd;
                  fpc_ansistr_decr_ref();
                  iStack_478c7c = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809c0e2;
                  fpc_ansistr_decr_ref();
                  uStack_478c84 = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809c11d;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809c12e;
                  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809c13f;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809c14f;
                  iVar7 = fpc_ansistr_compare_equal();
                  if (iVar7 == 0) {
                    *(undefined4 *)(puVar10 + -4) = 0x809c162;
                    fpc_ansistr_decr_ref();
                    uStack_478c84 = 0;
                    *(undefined4 *)(puVar10 + -4) = 0x809c177;
                    fpc_ansistr_decr_ref();
                    uStack_478c80 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809c1b2;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809c1c3;
                    SYSUTILS_EXTRACTFILENAME_ANSISTRING__ANSISTRING();
                    *(undefined4 *)(puVar10 + -4) = 0x809c1d3;
                    iVar7 = fpc_ansistr_compare_equal();
                    if (iVar7 == 0) {
                      *(undefined4 *)(puVar10 + -4) = 0x809c253;
                      fpc_ansistr_decr_ref();
                      uStack_478c84 = 0;
                      pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                      *(undefined4 *)(puVar10 + -4) = 0x809c28e;
                      (*pcVar1)();
                      *(undefined4 *)(puVar10 + -4) = 0x809c2b7;
                      fpc_ansistr_concat();
                    }
                    else {
                      *(undefined4 *)(puVar10 + -4) = 0x809c1e2;
                      fpc_ansistr_decr_ref();
                      uStack_478c84 = 0;
                      pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                      *(undefined4 *)(puVar10 + -4) = 0x809c21d;
                      (*pcVar1)();
                      *(undefined4 *)(puVar10 + -4) = 0x809c246;
                      fpc_ansistr_concat();
                    }
                  }
                  *(undefined4 *)(puVar10 + -4) = 0x809c2c2;
                  fpc_ansistr_decr_ref();
                  uStack_478c84 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809c2d7;
                  fpc_ansistr_decr_ref();
                  uStack_478c80 = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809c312;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809c323;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809c333;
                  iVar7 = fpc_ansistr_compare_equal();
                  if (iVar7 == 0) {
                    *(undefined4 *)(puVar10 + -4) = 0x809c346;
                    fpc_ansistr_decr_ref();
                    uStack_478c84 = 0;
                    *(undefined4 *)(puVar10 + -4) = 0x809c35b;
                    fpc_ansistr_decr_ref();
                    uStack_478c80 = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809c396;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809c3ba;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809c3c5;
                    cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
                    if (cVar4 != '\0') {
                      *(undefined4 *)(puVar10 + -4) = 0x809c3d5;
                      fpc_ansistr_decr_ref();
                      *(undefined4 *)(puVar10 + -4) = 0x809c3e7;
                      fpc_ansistr_decr_ref();
                      uStack_478c84 = 0;
                      *(undefined4 *)(puVar10 + -4) = 0x809c3fc;
                      fpc_ansistr_decr_ref();
                      uStack_478c80 = 0;
                      pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                      *(undefined4 *)(puVar10 + -4) = 0x809c437;
                      (*pcVar1)();
                      *(undefined4 *)(puVar10 + -4) = 0x809c45b;
                      fpc_ansistr_concat();
                      *(undefined4 *)(puVar10 + -4) = 0x809c471;
                      FPC_ANSISTR_TO_SHORTSTR();
                      *(undefined4 *)(puVar10 + -4) = 0x809c481;
                      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
                      *(undefined4 *)(puVar10 + -4) = 0x809c48b;
                      SYSTEM_RESET_TEXT();
                      *(undefined4 *)(puVar10 + -4) = 0x809c490;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c498;
                      fpc_ansistr_decr_ref();
                      *(undefined4 *)(puVar10 + -4) = 0x809c4a5;
                      fpc_read_text_ansistr();
                      *(undefined4 *)(puVar10 + -4) = 0x809c4aa;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c4b4;
                      fpc_readln_end();
                      *(undefined4 *)(puVar10 + -4) = 0x809c4b9;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c4c3;
                      OBJPAS_CLOSEFILE_TEXT();
                      *(undefined4 *)(puVar10 + -4) = 0x809c4c8;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c4d3;
                      fpc_ansistr_decr_ref();
                      uStack_478c84 = 0;
                      *(undefined4 **)(puVar10 + -4) = &uStack_478c84;
                      *(undefined4 *)(puVar10 + -8) = 0x809c4ef;
                      fpc_ansistr_decr_ref();
                      uStack_478c80 = 0;
                      *(undefined4 *)(puVar10 + -8) = 0x809c507;
                      SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                      *(undefined4 *)(puVar10 + -8) = 0x809c51c;
                      fpc_ansistr_copy();
                      *(undefined4 *)(puVar10 + -8) = 0x809c52c;
                      fpc_ansistr_compare_equal();
                      *(undefined4 *)(puVar10 + -8) = 0x809c55a;
                      fpc_ansistr_decr_ref();
                      uStack_478c84 = 0;
                      *(undefined4 **)(puVar10 + -8) = &uStack_478c84;
                      *(undefined4 *)(puVar10 + -0xc) = 0x809c576;
                      fpc_ansistr_decr_ref();
                      auStack_478d88[0] = 0;
                      *(undefined4 *)(puVar10 + -0xc) = 0x809c58e;
                      SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                      *(undefined4 *)(puVar10 + -0xc) = 0x809c5a3;
                      fpc_ansistr_copy();
                      *(undefined4 *)(puVar10 + -0xc) = 0x809c5b3;
                      fpc_ansistr_compare_equal();
                      *(undefined4 *)(puVar10 + -0xc) = 0x809c5e5;
                      iVar7 = fpc_ansistr_compare_equal();
                      puVar3 = puVar10 + -8;
                      if (iVar7 != 0) {
                        *(undefined4 *)(puVar10 + -0xc) = 0x809c5f4;
                        fpc_ansistr_decr_ref();
                        auStack_478d88[0] = 0;
                        *(undefined4 **)(puVar10 + -0xc) = auStack_478d88;
                        *(undefined4 *)(puVar10 + -0x10) = 0x809c610;
                        fpc_ansistr_decr_ref();
                        uStack_478c84 = 0;
                        *(undefined4 *)(puVar10 + -0x10) = 0x809c628;
                        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                        *(undefined4 *)(puVar10 + -0x10) = 0x809c63d;
                        fpc_ansistr_copy();
                        *(undefined4 *)(puVar10 + -0x10) = 0x809c64d;
                        iVar7 = fpc_ansistr_compare_equal();
                        puVar3 = puVar10 + -0xc;
                        if (iVar7 == 0) {
                          *(undefined4 *)(puVar10 + -0x10) = 0x809c65e;
                          fpc_ansistr_decr_ref();
                          puVar3 = puVar10 + -0xc;
                        }
                      }
                      puVar10 = puVar3;
                      *(undefined4 *)(puVar10 + -4) = 0x809c66c;
                      fpc_ansistr_decr_ref();
                      auStack_478d88[0] = 0;
                      *(undefined4 *)(puVar10 + -4) = 0x809c690;
                      fpc_shortstr_to_ansistr();
                      *(undefined4 *)(puVar10 + -4) = 0x809c6a0;
                      iVar7 = fpc_ansistr_compare_equal();
                      if (iVar7 != 0) {
                        *(undefined4 *)(puVar10 + -4) = 0x809c6af;
                        fpc_ansistr_decr_ref();
                        auStack_478d88[0] = 0;
                        *(undefined4 *)(puVar10 + -4) = 0x809c6c7;
                        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                        *(undefined4 *)(puVar10 + -4) = 0x809c6e6;
                        FPC_ANSISTR_TO_SHORTSTR();
                      }
                    }
                  }
                  *(undefined4 *)(puVar10 + -4) = 0x809c6f1;
                  fpc_ansistr_decr_ref();
                  auStack_478d88[0] = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809c706;
                  fpc_ansistr_decr_ref();
                  uStack_478c84 = 0;
                  *(undefined4 *)(puVar10 + -4) = 0x809c71b;
                  fpc_ansistr_decr_ref();
                  iStack_478d8c = 0;
                  pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                  *(undefined4 *)(puVar10 + -4) = 0x809c756;
                  (*pcVar1)();
                  *(undefined4 *)(puVar10 + -4) = 0x809c767;
                  SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809c778;
                  SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                  *(undefined4 *)(puVar10 + -4) = 0x809c788;
                  iVar7 = fpc_ansistr_compare_equal();
                  piVar11 = (int *)puVar10;
                  if (iVar7 == 0) {
                    *(undefined4 *)(puVar10 + -4) = 0x809c79b;
                    fpc_ansistr_decr_ref();
                    iStack_478d8c = 0;
                    *(undefined4 *)(puVar10 + -4) = 0x809c7bb;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809c7c6;
                    cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
                    if (cVar4 != '\0') {
                      *(undefined4 *)(puVar10 + -4) = 0x809c7d9;
                      fpc_ansistr_decr_ref();
                      iStack_478d8c = 0;
                      *(undefined4 *)(puVar10 + -4) = 0x809c7ee;
                      fpc_ansistr_decr_ref();
                      auStack_478d88[0] = 0;
                      pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                      *(undefined4 *)(puVar10 + -4) = 0x809c829;
                      (*pcVar1)();
                      *(undefined4 *)(puVar10 + -4) = 0x809c84d;
                      fpc_ansistr_concat();
                      *(undefined4 *)(puVar10 + -4) = 0x809c858;
                      SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
                    }
                    *(undefined4 *)(puVar10 + -4) = 0x809c863;
                    fpc_ansistr_decr_ref();
                    iStack_478d8c = 0;
                    *(undefined4 *)(puVar10 + -4) = 0x809c878;
                    fpc_ansistr_decr_ref();
                    auStack_478d88[0] = 0;
                    pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                    *(undefined4 *)(puVar10 + -4) = 0x809c8b3;
                    (*pcVar1)();
                    *(undefined4 *)(puVar10 + -4) = 0x809c8d7;
                    fpc_ansistr_concat();
                    *(undefined4 *)(puVar10 + -4) = 0x809c8e2;
                    cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
                    if (cVar4 != '\0') {
                      *(undefined4 *)(puVar10 + -4) = 0x809c8f5;
                      fpc_ansistr_decr_ref();
                      iStack_478d8c = 0;
                      *(undefined4 *)(puVar10 + -4) = 0x809c90a;
                      fpc_ansistr_decr_ref();
                      auStack_478d88[0] = 0;
                      pcVar1 = *(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78);
                      *(undefined4 *)(puVar10 + -4) = 0x809c945;
                      (*pcVar1)();
                      *(undefined4 *)(puVar10 + -4) = 0x809c969;
                      fpc_ansistr_concat();
                      *(undefined4 *)(puVar10 + -4) = 0x809c97f;
                      FPC_ANSISTR_TO_SHORTSTR();
                      *(undefined4 *)(puVar10 + -4) = 0x809c98f;
                      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
                      *(undefined4 *)(puVar10 + -4) = 0x809c999;
                      SYSTEM_RESET_TEXT();
                      *(undefined4 *)(puVar10 + -4) = 0x809c99e;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9a9;
                      fpc_ansistr_decr_ref();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9b9;
                      fpc_read_text_ansistr();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9be;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9c8;
                      fpc_readln_end();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9cd;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9d8;
                      fpc_ansistr_decr_ref();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9e8;
                      fpc_read_text_ansistr();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9ed;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9f7;
                      fpc_readln_end();
                      *(undefined4 *)(puVar10 + -4) = 0x809c9fc;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809ca06;
                      OBJPAS_CLOSEFILE_TEXT();
                      *(undefined4 *)(puVar10 + -4) = 0x809ca0b;
                      fpc_iocheck();
                      *(undefined4 *)(puVar10 + -4) = 0x809ca2a;
                      FPC_ANSISTR_TO_SHORTSTR();
                      *(undefined4 *)(puVar10 + -4) = 0x809ca3a;
                      iStack_478b28 = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
                      *(undefined4 *)(puVar10 + -4) = 0x809ca4b;
                      fpc_ansistr_decr_ref();
                      iStack_478d8c = 0;
                      *(undefined4 *)(puVar10 + -4) = 0x809ca60;
                      fpc_ansistr_incr_ref();
                      *(undefined4 *)(puVar10 + -4) = 0x809ca6b;
                      fpc_ansistr_decr_ref();
                      iStack_478d8c = iStack_478b24;
                      *(undefined4 *)(puVar10 + -4) = 0;
                      *(undefined4 *)(puVar10 + -8) = 0x809ca97;
                      lVar13 = (longdouble)
                               SYSUTILS_STRTODATE_PCHAR_LONGINT_ANSISTRING_CHAR__TDATETIME();
                      uStack_478d94 = (double)lVar13;
                      *(double *)(puVar10 + -0xc) = uStack_478d94;
                      *(undefined4 *)(puVar10 + -0x10) = 0x809cad0;
                      lVar13 = (longdouble)SYSUTILS_DATE__TDATETIME();
                      *(double *)(puVar10 + -0x14) = (double)lVar13;
                      *(undefined4 *)(puVar10 + -0x18) = 0x809cadb;
                      iVar7 = DATEUTILS_DAYSBETWEEN_TDATETIME_TDATETIME__LONGINT();
                      piVar11 = (int *)(puVar10 + -0x14);
                      if (iVar7 < iStack_478b28) {
                        *(undefined4 *)(puVar10 + -0x18) = 0x809caf2;
                        fpc_ansistr_decr_ref();
                        iStack_478d8c = 0;
                        *(undefined4 *)(puVar10 + -0x18) = 0x809cb16;
                        fpc_shortstr_to_ansistr();
                        if (iStack_478d8c == 0) {
                          *(undefined2 *)((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) =
                               0x5301;
                          *(undefined4 *)(puVar10 + -0x18) = 0x809cb3d;
                          fpc_ansistr_decr_ref();
                          iStack_478d8c = 0;
                          *(undefined4 *)(puVar10 + -0x18) = 0x809cb57;
                          SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                          *(undefined4 *)(puVar10 + -0x18) = 0x809cb76;
                          FPC_ANSISTR_TO_SHORTSTR();
                          piVar11 = (int *)(puVar10 + -0x14);
                        }
                        else {
                          cStack_478b2c = '\0';
                          pcVar1 = *(code **)(**(int **)(Form1.LabelE1 + 0x364) + 0x80);
                          *(undefined4 *)(puVar10 + -0x18) = 0x809cbad;
                          iVar7 = (*pcVar1)();
                          if (-1 < iVar7 + -1) {
                            local_10 = -1;
                            do {
                              local_10 = local_10 + 1;
                              *(undefined4 *)(puVar10 + -0x18) = 0x809cbd2;
                              fpc_ansistr_decr_ref();
                              iStack_478d8c = 0;
                              pcVar1 = *(code **)(**(int **)(Form1.LabelE1 + 0x364) +
                                                 0x78);
                              *(undefined4 *)(puVar10 + -0x18) = 0x809cc0d;
                              (*pcVar1)();
                              *(undefined4 *)(puVar10 + -0x18) = 0x809cc1e;
                              fpc_ansistr_decr_ref();
                              auStack_478e90[0] = 0;
                              *(undefined4 *)(puVar10 + -0x18) = 0x809cc42;
                              fpc_shortstr_to_ansistr();
                              *(undefined4 *)(puVar10 + -0x18) = 0x809cc4f;
                              iVar8 = fpc_ansistr_compare_equal();
                              if (iVar8 == 0) {
                                cStack_478b2c = '\x01';
                              }
                            } while (local_10 < iVar7 + -1);
                          }
                          piVar11 = (int *)(puVar10 + -0x14);
                          if (cStack_478b2c == '\0') {
                            *(undefined2 *)((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) =
                                 0x5301;
                            *(undefined4 *)(puVar10 + -0x18) = 0x809cc8a;
                            fpc_ansistr_decr_ref();
                            auStack_478e90[0] = 0;
                            *(undefined4 *)(puVar10 + -0x18) = 0x809cca4;
                            SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                            *(undefined4 *)(puVar10 + -0x18) = 0x809ccc3;
                            FPC_ANSISTR_TO_SHORTSTR();
                            piVar11 = (int *)(puVar10 + -0x14);
                          }
                        }
                      }
                      else {
                        *(undefined2 *)((int)&U_JUKELINUX1_ENDERECOSTR + local_8 * 0x240 + 2) =
                             0x4e01;
                      }
                    }
                  }
                }
              }
              puVar10 = (undefined1 *)piVar11;
            } while (local_c < iVar6 + -1);
          }
          (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] = U_JUKELINUX1_KMATMUSICA;
          *(undefined4 *)((int)piVar11 + -4) = 0x809cd09;
          cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar4 != '\0') {
            *(undefined4 *)((int)piVar11 + -4) = 0x809cd21;
            cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
            if (cVar4 != '\0') goto LAB_0809cd38;
          }
          (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] = 0;
        }
LAB_0809cd38:
      } while (local_8 < iVar5);
    }
    iVar5 = U_JUKELINUX1_TOTALCDS;
    iStack_465288 = 0;
    if (0 < U_JUKELINUX1_TOTALCDS) {
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        cStack_478b2c = '\0';
        pcVar1 = *(code **)(**(int **)(Form1.LabelE1 + 0x364) + 0x80);
        *(undefined4 *)((int)piVar11 + -4) = 0x809cda5;
        iVar6 = (*pcVar1)();
        if (-1 < iVar6 + -1) {
          local_c = -1;
          do {
            local_c = local_c + 1;
            *(undefined4 *)((int)piVar11 + -4) = 0x809cdca;
            fpc_ansistr_decr_ref();
            auStack_478e90[0] = 0;
            pcVar1 = *(code **)(**(int **)(Form1.LabelE1 + 0x364) + 0x78);
            *(undefined4 *)((int)piVar11 + -4) = 0x809ce05;
            (*pcVar1)();
            *(undefined4 *)((int)piVar11 + -4) = 0x809ce16;
            fpc_ansistr_decr_ref();
            iStack_478d8c = 0;
            *(undefined4 *)((int)piVar11 + -4) = 0x809ce3a;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)((int)piVar11 + -4) = 0x809ce47;
            iVar7 = fpc_ansistr_compare_equal();
            if (iVar7 == 0) {
              cStack_478b2c = '\x01';
            }
          } while (local_c < iVar6 + -1);
        }
        if ((&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90] == 0) {
          cStack_478b2c = '\x01';
        }
        if (cStack_478b2c == '\0') {
          iStack_465288 = iStack_465288 + 1;
          *(undefined4 *)((int)piVar11 + -4) = 0x809ceb1;
          fpc_copy_proc();
        }
      } while (local_8 < iVar5);
    }
    iVar5 = iStack_465288;
    U_JUKELINUX1_TOTALCDS = iStack_465288;
    if (0 < iStack_465288) {
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        *(undefined4 *)((int)piVar11 + -4) = 0x809cf04;
        fpc_copy_proc();
      } while (local_8 < iVar5);
    }
    *(undefined4 *)((int)piVar11 + -4) = 0x809cf1e;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    pcVar1 = *(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809cf3d;
    (*pcVar1)();
    *(undefined4 *)((int)piVar11 + -4) = 0x809cf47;
    CONTROLS_TCONTROL____REFRESH();
    pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809cf5a;
    (*pcVar1)();
    local_20 = U_JUKELINUX1_TOTALCDS;
    do {
      bVar2 = false;
      if (0 < local_20 + -1) {
        local_8 = 0;
        puVar10 = (undefined1 *)piVar11;
        do {
          local_8 = local_8 + 1;
          *(undefined4 *)(puVar10 + -4) = 0x809cf92;
          fpc_ansistr_decr_ref();
          auStack_478e90[0] = 0;
          *(undefined4 **)(puVar10 + -4) = auStack_478e90;
          *(undefined4 *)(puVar10 + -8) = 0x809cfb7;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar10 + -8) = 0x809cfc7;
          iVar5 = fpc_ansistr_compare_equal();
          if (iVar5 == 0) {
            *(undefined4 *)(puVar10 + -8) = 0x809cfda;
            fpc_ansistr_decr_ref();
            auStack_478e90[0] = 0;
            *(undefined4 *)(puVar10 + -8) = 0x809cffe;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)(puVar10 + -8) = 0x809d01b;
            fpc_ansistr_concat();
            *(undefined4 *)(puVar10 + -8) = 0x809d026;
            fpc_ansistr_decr_ref();
            auStack_478e90[0] = 0;
            *(undefined4 *)(puVar10 + -8) = 0x809d04b;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)(puVar10 + -8) = 0x809d06d;
            fpc_ansistr_concat();
          }
          *(undefined4 *)(puVar10 + -8) = 0x809d078;
          fpc_ansistr_decr_ref();
          auStack_478e90[0] = 0;
          *(undefined4 **)(puVar10 + -8) = auStack_478e90;
          *(undefined4 *)(puVar10 + -0xc) = 0x809d09d;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar10 + -0xc) = 0x809d0ad;
          iVar5 = fpc_ansistr_compare_equal();
          if (iVar5 == 0) {
            *(undefined4 *)(puVar10 + -0xc) = 0x809d0c5;
            fpc_ansistr_incr_ref();
            *(undefined4 *)(puVar10 + -0xc) = 0x809d0cd;
            fpc_ansistr_decr_ref();
            *(undefined4 *)(puVar10 + -0xc) = 0x809d0eb;
            fpc_ansistr_incr_ref();
            *(undefined4 *)(puVar10 + -0xc) = 0x809d0f3;
            fpc_ansistr_decr_ref();
          }
          *(undefined4 *)(puVar10 + -0xc) = 0x809d107;
          iVar5 = fpc_ansistr_compare();
          if (0 < iVar5) {
            *(undefined4 *)(puVar10 + -0xc) = 0x809d12a;
            fpc_copy_proc();
            *(undefined4 *)(puVar10 + -0xc) = 0x809d153;
            fpc_copy_proc();
            *(undefined4 *)(puVar10 + -0xc) = 0x809d177;
            fpc_copy_proc();
            bVar2 = true;
          }
          piVar11 = (int *)(puVar10 + -8);
          puVar10 = puVar10 + -8;
        } while (local_8 < local_20 + -1);
      }
      local_20 = local_20 + -1;
    } while (bVar2);
    *(undefined4 *)((int)piVar11 + -4) = 0x809d19c;
    fpc_ansistr_decr_ref();
    auStack_478e90[0] = 0;
    *(undefined4 *)((int)piVar11 + -4) = 0x809d1bc;
    fpc_ansistr_concat();
    *(undefined4 *)((int)piVar11 + -4) = 0x809d1c7;
    cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    iVar5 = U_JUKELINUX1_TOTALCDS;
    if (cVar4 != '\0') {
      if (0 < U_JUKELINUX1_TOTALCDS) {
        local_18 = 0;
        do {
          local_18 = local_18 + 1;
          (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90] = 0;
        } while (local_18 < iVar5);
      }
      local_24 = 0;
      *(undefined4 *)((int)piVar11 + -4) = 0x809d211;
      fpc_ansistr_decr_ref();
      auStack_478e90[0] = 0;
      *(undefined4 *)((int)piVar11 + -4) = 0x809d231;
      fpc_ansistr_concat();
      *(undefined4 *)((int)piVar11 + -4) = 0x809d247;
      FPC_ANSISTR_TO_SHORTSTR();
      *(undefined4 *)((int)piVar11 + -4) = 0x809d257;
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      *(undefined4 *)((int)piVar11 + -4) = 0x809d261;
      SYSTEM_RESET_TEXT();
      *(undefined4 *)((int)piVar11 + -4) = 0x809d266;
      fpc_iocheck();
      while( true ) {
        *(undefined4 *)((int)piVar11 + -4) = 0x809d337;
        cVar4 = SYSTEM_EOF_TEXT__BOOLEAN();
        *(undefined4 *)((int)piVar11 + -4) = 0x809d33e;
        fpc_iocheck();
        if (cVar4 != '\0') break;
        *(undefined4 *)((int)piVar11 + -4) = 0x809d276;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar11 + -4) = 0x809d285;
        fpc_read_text_ansistr();
        *(undefined4 *)((int)piVar11 + -4) = 0x809d28a;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809d294;
        fpc_readln_end();
        *(undefined4 *)((int)piVar11 + -4) = 0x809d299;
        fpc_iocheck();
        iVar5 = U_JUKELINUX1_TOTALCDS;
        local_24 = local_24 + 1;
        if (0 < U_JUKELINUX1_TOTALCDS) {
          local_18 = 0;
          do {
            local_18 = local_18 + 1;
            iVar6 = (&U_JUKELINUX1_NOMEDOCLIENTE)[local_18 * 0x90];
            if (0 < iVar6) {
              local_1c = 0;
              do {
                local_1c = local_1c + 1;
                *(undefined4 *)((int)piVar11 + -4) = 0x809d2fd;
                iVar7 = fpc_ansistr_compare_equal();
                if (iVar7 == 0) {
                  (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90] =
                       (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90] + 1;
                  (&U_JUKELINUX1_TECLACDMENOS)[local_18 * 0x90 + local_1c] =
                       (&U_JUKELINUX1_TECLACDMENOS)[local_18 * 0x90 + local_1c] + 1;
                }
              } while (local_1c < iVar6);
            }
          } while (local_18 < iVar5);
        }
      }
      *(undefined4 *)((int)piVar11 + -4) = 0x809d350;
      OBJPAS_CLOSEFILE_TEXT();
      *(undefined4 *)((int)piVar11 + -4) = 0x809d355;
      fpc_iocheck();
      iVar5 = U_JUKELINUX1_TOTALCDS;
      if (0 < local_24) {
        if (0 < U_JUKELINUX1_TOTALCDS) {
          local_18 = 0;
          do {
            local_18 = local_18 + 1;
            *(undefined4 *)((int)piVar11 + -4) = 0x809d38f;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)piVar11 + -4) = 0x809d39e;
            fpc_ansistr_decr_ref();
            aiStack_46cf8c[local_18] = *(int *)(U_JUKELINUX1_ARQLOG + local_18 * 0x240 + 0x1f8);
            aiStack_474c8c[local_18] = (&U_JUKELINUX1_SELOSSTR)[local_18 * 0x90];
          } while (local_18 < iVar5);
        }
        local_20 = U_JUKELINUX1_TOTALCDS;
        do {
          bVar2 = false;
          if (0 < local_20 + -1) {
            local_8 = 0;
            do {
              iVar5 = local_8 + 1;
              iStack_474c90 = aiStack_474c8c[iVar5];
              iStack_474c94 = aiStack_474c8c[local_8 + 2];
              if (iStack_474c90 < iStack_474c94) {
                *(undefined4 *)((int)piVar11 + -4) = 0x809d42f;
                fpc_ansistr_incr_ref();
                *(undefined4 *)((int)piVar11 + -4) = 0x809d43a;
                fpc_ansistr_decr_ref();
                aiStack_474c8c[0] = aiStack_46cf8c[iVar5];
                iStack_474c98 = aiStack_474c8c[iVar5];
                *(undefined4 *)((int)piVar11 + -4) = 0x809d467;
                fpc_ansistr_incr_ref();
                *(undefined4 *)((int)piVar11 + -4) = 0x809d476;
                fpc_ansistr_decr_ref();
                aiStack_46cf8c[iVar5] = aiStack_46cf8c[local_8 + 2];
                aiStack_474c8c[iVar5] = aiStack_474c8c[local_8 + 2];
                *(undefined4 *)((int)piVar11 + -4) = 0x809d4a4;
                fpc_ansistr_incr_ref();
                *(undefined4 *)((int)piVar11 + -4) = 0x809d4b4;
                fpc_ansistr_decr_ref();
                aiStack_46cf8c[local_8 + 2] = aiStack_474c8c[0];
                aiStack_474c8c[local_8 + 2] = iStack_474c98;
                bVar2 = true;
              }
              local_8 = iVar5;
            } while (iVar5 < local_20 + -1);
          }
          local_20 = local_20 + -1;
        } while (bVar2);
        local_10 = U_JUKELINUX1_TOTALCDS;
        local_24 = 0;
        local_c = 0;
        do {
          iVar5 = U_JUKELINUX1_TOTALCDS;
          local_c = local_c + 1;
          if ((0 < aiStack_474c8c[local_c]) && (0 < U_JUKELINUX1_TOTALCDS)) {
            local_8 = 0;
            do {
              local_8 = local_8 + 1;
              if (local_24 < 0x33) {
                *(undefined4 *)((int)piVar11 + -4) = 0x809d571;
                iVar6 = fpc_ansistr_compare_equal();
                if (iVar6 == 0) {
                  *(undefined4 *)((int)piVar11 + -4) = 0x809d5a5;
                  fpc_copy_proc();
                  local_10 = local_10 + 1;
                  *(undefined4 *)((int)piVar11 + -4) = 0x809d5d0;
                  fpc_copy_proc();
                  *(undefined4 *)((int)piVar11 + -4) = 0x809d5ee;
                  FPC_SHORTSTR_TO_SHORTSTR();
                  *(undefined4 *)((int)piVar11 + -4) = 0x809d5f9;
                  fpc_ansistr_decr_ref();
                  auStack_478e90[0] = 0;
                  *(undefined4 **)((int)piVar11 + -4) = auStack_478e90;
                  *(undefined4 *)((int)piVar11 + -8) = 0x809d61e;
                  fpc_ansistr_copy();
                  *(undefined4 *)((int)piVar11 + -8) = 0x809d62e;
                  iVar6 = fpc_ansistr_compare_equal();
                  if (iVar6 == 0) {
                    puStack_478da4 = &__JUKELINUX1__Ld10;
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d64c;
                    fpc_ansistr_decr_ref();
                    auStack_478e90[0] = 0;
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d664;
                    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                    uStack_478da0 = auStack_478e90[0];
                    pcStack_478d9c = __JUKELINUX1__Ld137;
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d686;
                    fpc_ansistr_decr_ref();
                    uStack_478e94 = 0;
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d6a5;
                    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                    uStack_478d98 = uStack_478e94;
                    uStack_478d94 =
                         (double)CONCAT44(*(undefined4 *)
                                           (U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x1fc),
                                          &__JUKELINUX1__Ld138);
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d6f0;
                    fpc_ansistr_concat_multi();
                  }
                  else {
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d700;
                    fpc_ansistr_decr_ref();
                    uStack_478e94 = 0;
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d718;
                    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                    uStack_478da0 = uStack_478e94;
                    pcStack_478d9c = __JUKELINUX1__Ld137;
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d73a;
                    fpc_ansistr_decr_ref();
                    auStack_478e90[0] = 0;
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d759;
                    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                    uStack_478d98 = auStack_478e90[0];
                    uStack_478d94 =
                         (double)CONCAT44(*(undefined4 *)
                                           (U_JUKELINUX1_ARQLOG + local_10 * 0x240 + 0x1fc),
                                          &__JUKELINUX1__Ld138);
                    *(undefined4 *)((int)piVar11 + -8) = 0x809d7a4;
                    fpc_ansistr_concat_multi();
                  }
                  piVar11 = (int *)((int)piVar11 + -4);
                  local_24 = local_24 + 1;
                }
              }
            } while (local_8 < iVar5);
          }
        } while (local_c < 0x32);
        U_JUKELINUX1_TOTALCDS = local_10;
        aiStack_478b1c[0] = 0;
        local_18 = 0;
        do {
          local_18 = local_18 + 1;
          if ((0 < aiStack_474c8c[local_18]) && (iVar5 = aiStack_46534c[local_18 * 0x90], 0 < iVar5)
             ) {
            local_1c = 0;
            do {
              local_1c = local_1c + 1;
              if (0 < aiStack_46533c[local_18 * 0x90 + local_1c]) {
                aiStack_478b1c[0] = aiStack_478b1c[0] + 1;
                *(undefined4 *)((int)piVar11 + -4) = 0x809d85a;
                fpc_ansistr_incr_ref();
                iVar6 = aiStack_478b1c[0];
                *(undefined4 *)((int)piVar11 + -4) = 0x809d86c;
                fpc_ansistr_decr_ref();
                aiStack_476bdc[iVar6] = aiStack_465490[local_18 * 0x90 + local_1c];
                aiStack_478b1c[aiStack_478b1c[0]] = aiStack_46533c[local_18 * 0x90 + local_1c];
              }
            } while (local_1c < iVar5);
          }
        } while (local_18 < 0x32);
        local_20 = 0x32;
        do {
          bVar2 = false;
          if (0 < local_20 + -1) {
            local_8 = 0;
            do {
              iVar5 = local_8 + 1;
              iStack_474c90 = aiStack_478b1c[iVar5];
              iStack_474c94 = aiStack_478b1c[local_8 + 2];
              if (iStack_474c90 < iStack_474c94) {
                *(undefined4 *)((int)piVar11 + -4) = 0x809d917;
                fpc_ansistr_incr_ref();
                *(undefined4 *)((int)piVar11 + -4) = 0x809d922;
                fpc_ansistr_decr_ref();
                aiStack_474c8c[0] = aiStack_476bdc[iVar5];
                iStack_474c98 = aiStack_478b1c[iVar5];
                *(undefined4 *)((int)piVar11 + -4) = 0x809d94f;
                fpc_ansistr_incr_ref();
                *(undefined4 *)((int)piVar11 + -4) = 0x809d95e;
                fpc_ansistr_decr_ref();
                aiStack_476bdc[iVar5] = aiStack_476bdc[local_8 + 2];
                aiStack_478b1c[iVar5] = aiStack_478b1c[local_8 + 2];
                *(undefined4 *)((int)piVar11 + -4) = 0x809d98c;
                fpc_ansistr_incr_ref();
                *(undefined4 *)((int)piVar11 + -4) = 0x809d99c;
                fpc_ansistr_decr_ref();
                aiStack_476bdc[local_8 + 2] = aiStack_474c8c[0];
                aiStack_478b1c[local_8 + 2] = iStack_474c98;
                bVar2 = true;
              }
              local_8 = iVar5;
            } while (iVar5 < local_20 + -1);
          }
          local_20 = local_20 + -1;
        } while (bVar2);
        U_JUKELINUX1_TOTALMG = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809d9e9;
        fpc_ansistr_decr_ref();
        uStack_478e94 = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809da09;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar11 + -4) = 0x809da1f;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar11 + -4) = 0x809da2f;
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        *(undefined4 *)((int)piVar11 + -4) = 0x809da39;
        SYSTEM_REWRITE_TEXT();
        *(undefined4 *)((int)piVar11 + -4) = 0x809da3e;
        fpc_iocheck();
        local_8 = 0;
        do {
          local_8 = local_8 + 1;
          if (0 < aiStack_478b1c[local_8]) {
            *(undefined4 *)((int)piVar11 + -4) = 0x809da6c;
            fpc_ansistr_incr_ref();
            *(undefined4 *)((int)piVar11 + -4) = 0x809da7b;
            fpc_ansistr_decr_ref();
            *(int *)(&DAT_0964721c + local_8 * 4) = aiStack_476bdc[local_8];
            U_JUKELINUX1_TOTALMG = U_JUKELINUX1_TOTALMG + 1;
            *(undefined4 *)((int)piVar11 + -4) = 0x809daa8;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)piVar11 + -4) = 0x809daad;
            fpc_iocheck();
            *(undefined4 *)((int)piVar11 + -4) = 0x809dab7;
            fpc_writeln_end();
            *(undefined4 *)((int)piVar11 + -4) = 0x809dabc;
            fpc_iocheck();
            *(undefined4 *)((int)piVar11 + -4) = 0x809dac7;
            fpc_ansistr_decr_ref();
            uStack_478e94 = 0;
            *(undefined4 *)((int)piVar11 + -4) = 0x809dae6;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            *(undefined4 *)((int)piVar11 + -4) = 0x809dafb;
            fpc_write_text_ansistr();
            *(undefined4 *)((int)piVar11 + -4) = 0x809db00;
            fpc_iocheck();
            *(undefined4 *)((int)piVar11 + -4) = 0x809db0a;
            fpc_writeln_end();
            *(undefined4 *)((int)piVar11 + -4) = 0x809db0f;
            fpc_iocheck();
          }
        } while (local_8 < 0x32);
        *(undefined4 *)((int)piVar11 + -4) = 0x809db23;
        SYSTEM_FLUSH_TEXT();
        *(undefined4 *)((int)piVar11 + -4) = 0x809db28;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809db32;
        OBJPAS_CLOSEFILE_TEXT();
        *(undefined4 *)((int)piVar11 + -4) = 0x809db37;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809db42;
        fpc_ansistr_decr_ref();
        uStack_478e94 = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809db62;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar11 + -4) = 0x809db6d;
        cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar4 == '\0') {
          *(undefined4 *)((int)piVar11 + -4) = 0x809db80;
          fpc_ansistr_decr_ref();
          uStack_478e94 = 0;
          *(undefined4 *)((int)piVar11 + -4) = 0x809dba0;
          fpc_ansistr_concat();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dbb6;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dbc6;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dbd0;
          SYSTEM_REWRITE_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dbd5;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dbe4;
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTO = &__JUKELINUX1__Ld141;
          *(undefined4 *)((int)piVar11 + -4) = 0x809dbff;
          fpc_write_text_ansistr();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc04;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc0e;
          fpc_writeln_end();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc13;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc1d;
          SYSTEM_FLUSH_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc22;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc2c;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc31;
          fpc_iocheck();
        }
        *(undefined4 *)((int)piVar11 + -4) = 0x809dc3c;
        fpc_ansistr_decr_ref();
        uStack_478e94 = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809dc5c;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar11 + -4) = 0x809dc67;
        cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar4 != '\0') {
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc7a;
          fpc_ansistr_decr_ref();
          uStack_478e94 = 0;
          *(undefined4 *)((int)piVar11 + -4) = 0x809dc9a;
          fpc_ansistr_concat();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dcb0;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dcc0;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dcca;
          SYSTEM_RESET_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dccf;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dcd9;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dce8;
          fpc_read_text_ansistr();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dced;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dcf7;
          fpc_readln_end();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dcfc;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dd06;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dd0b;
          fpc_iocheck();
        }
        *(undefined4 *)((int)piVar11 + -4) = 0x809dd1a;
        U_JUKELINUX1_LIMITEARQ = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
        if (U_JUKELINUX1_LIMITEARQ < U_JUKELINUX1_TOTALMG) {
          U_JUKELINUX1_TOTALMG = U_JUKELINUX1_LIMITEARQ;
        }
        *(undefined4 *)((int)piVar11 + -4) = 0x809dd3c;
        fpc_ansistr_decr_ref();
        uStack_478e94 = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809dd5c;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar11 + -4) = 0x809dd67;
        cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar4 == '\0') {
          *(undefined4 *)((int)piVar11 + -4) = 0x809dd7a;
          fpc_ansistr_decr_ref();
          uStack_478e94 = 0;
          *(undefined4 *)((int)piVar11 + -4) = 0x809dd9a;
          fpc_ansistr_concat();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ddb0;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ddc0;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ddca;
          SYSTEM_REWRITE_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ddcf;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dde0;
          fpc_write_text_char();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dde5;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ddef;
          fpc_writeln_end();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ddf4;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ddfe;
          SYSTEM_FLUSH_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809de03;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809de0d;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809de12;
          fpc_iocheck();
        }
        *(undefined4 *)((int)piVar11 + -4) = 0x809de1d;
        fpc_ansistr_decr_ref();
        uStack_478e94 = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809de3d;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar11 + -4) = 0x809de48;
        cVar4 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar4 != '\0') {
          *(undefined4 *)((int)piVar11 + -4) = 0x809de5b;
          fpc_ansistr_decr_ref();
          uStack_478e94 = 0;
          *(undefined4 *)((int)piVar11 + -4) = 0x809de7b;
          fpc_ansistr_concat();
          *(undefined4 *)((int)piVar11 + -4) = 0x809de91;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dea1;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)piVar11 + -4) = 0x809deab;
          SYSTEM_RESET_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809deb0;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809deba;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dec9;
          fpc_read_text_ansistr();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dece;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809ded8;
          fpc_readln_end();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dedd;
          fpc_iocheck();
          *(undefined4 *)((int)piVar11 + -4) = 0x809dee7;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)piVar11 + -4) = 0x809deec;
          fpc_iocheck();
        }
        U_JUKELINUX1_POSMG = 0;
        *(undefined4 *)((int)piVar11 + -4) = 0x809df05;
        U_JUKELINUX1_POSMG = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
        if (U_JUKELINUX1_TOTALMG < U_JUKELINUX1_POSMG) {
          U_JUKELINUX1_POSMG = 0;
        }
      }
    }
    *(undefined4 *)((int)piVar11 + -4) = 0x809df31;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    pcVar1 = *(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809df50;
    (*pcVar1)();
    *(undefined4 *)((int)piVar11 + -4) = 0x809df5a;
    CONTROLS_TCONTROL____REFRESH();
    pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809df6d;
    (*pcVar1)();
    local_20 = U_JUKELINUX1_TOTALCDS;
    do {
      bVar2 = false;
      if (0 < local_20 + -1) {
        local_8 = 0;
        puVar10 = (undefined1 *)piVar11;
        do {
          local_8 = local_8 + 1;
          *(undefined4 *)(puVar10 + -4) = 0x809dfa6;
          fpc_ansistr_decr_ref();
          uStack_478e94 = 0;
          *(undefined4 **)(puVar10 + -4) = &uStack_478e94;
          *(undefined4 *)(puVar10 + -8) = 0x809dfcb;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar10 + -8) = 0x809dfdb;
          iVar5 = fpc_ansistr_compare_equal();
          if (iVar5 == 0) {
            *(undefined4 *)(puVar10 + -8) = 0x809dfee;
            fpc_ansistr_decr_ref();
            uStack_478e94 = 0;
            *(undefined4 *)(puVar10 + -8) = 0x809e012;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)(puVar10 + -8) = 0x809e01d;
            fpc_ansistr_incr_ref();
            *(undefined4 *)(puVar10 + -8) = 0x809e025;
            fpc_ansistr_decr_ref();
            *(undefined4 *)(puVar10 + -8) = 0x809e039;
            fpc_ansistr_decr_ref();
            uStack_478e94 = 0;
            *(undefined4 *)(puVar10 + -8) = 0x809e05e;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)(puVar10 + -8) = 0x809e069;
            fpc_ansistr_incr_ref();
            *(undefined4 *)(puVar10 + -8) = 0x809e071;
            fpc_ansistr_decr_ref();
          }
          *(undefined4 *)(puVar10 + -8) = 0x809e085;
          fpc_ansistr_decr_ref();
          uStack_478e94 = 0;
          *(undefined4 **)(puVar10 + -8) = &uStack_478e94;
          *(undefined4 *)(puVar10 + -0xc) = 0x809e0aa;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar10 + -0xc) = 0x809e0ba;
          iVar5 = fpc_ansistr_compare_equal();
          if (iVar5 == 0) {
            *(undefined4 *)(puVar10 + -0xc) = 0x809e0d2;
            fpc_ansistr_incr_ref();
            *(undefined4 *)(puVar10 + -0xc) = 0x809e0da;
            fpc_ansistr_decr_ref();
            *(undefined4 *)(puVar10 + -0xc) = 0x809e0f8;
            fpc_ansistr_incr_ref();
            *(undefined4 *)(puVar10 + -0xc) = 0x809e100;
            fpc_ansistr_decr_ref();
          }
          *(undefined4 *)(puVar10 + -0xc) = 0x809e114;
          iVar5 = fpc_ansistr_compare();
          if (0 < iVar5) {
            *(undefined4 *)(puVar10 + -0xc) = 0x809e137;
            fpc_copy_proc();
            *(undefined4 *)(puVar10 + -0xc) = 0x809e160;
            fpc_copy_proc();
            *(undefined4 *)(puVar10 + -0xc) = 0x809e184;
            fpc_copy_proc();
            bVar2 = true;
          }
          piVar11 = (int *)(puVar10 + -8);
          puVar10 = puVar10 + -8;
        } while (local_8 < local_20 + -1);
      }
      local_20 = local_20 + -1;
    } while (bVar2);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e1b3;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    pcVar1 = *(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e1d2;
    (*pcVar1)();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e1dc;
    CONTROLS_TCONTROL____REFRESH();
    pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e1ef;
    (*pcVar1)();
    U_JUKELINUX1_KL = 0;
    do {
      U_JUKELINUX1_KL = U_JUKELINUX1_KL + 1;
      iVar5 = U_JUKELINUX1_KL;
      *(undefined4 *)((int)piVar11 + -4) = 0x809e218;
      fpc_ansistr_decr_ref();
      (&U_JUKELINUX1_CDSELEAPAGARX)[iVar5] = 0;
      iVar5 = U_JUKELINUX1_TOTALCDS;
    } while (U_JUKELINUX1_KL < 100);
    U_JUKELINUX1_TOTALMMLETRA = 0;
    if (0 < U_JUKELINUX1_TOTALCDS) {
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        bVar2 = false;
        local_c = 0;
        puVar10 = (undefined1 *)piVar11;
        do {
          puVar12 = puVar10;
          local_c = local_c + 1;
          *(undefined4 *)(puVar12 + -4) = 0x809e272;
          fpc_ansistr_decr_ref();
          uStack_478e94 = 0;
          *(undefined4 *)(puVar12 + -4) = 0x809e291;
          SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar12 + -4) = 0x809e2a2;
          fpc_ansistr_decr_ref();
          auStack_478f98[0] = 0;
          *(undefined4 *)(puVar12 + -4) = 0x809e2b7;
          fpc_ansistr_decr_ref();
          uStack_478f9c = 0;
          *(undefined4 **)(puVar12 + -4) = &uStack_478f9c;
          *(undefined4 *)(puVar12 + -8) = 0x809e2e6;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar12 + -8) = 0x809e2f7;
          SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar12 + -8) = 0x809e304;
          iVar6 = fpc_ansistr_compare_equal();
          if (iVar6 == 0) {
            bVar2 = true;
          }
          puVar10 = puVar12 + -4;
        } while (local_c < 100);
        piVar11 = (int *)(puVar12 + -4);
        if ((!bVar2) && (piVar11 = (int *)(puVar12 + -4), U_JUKELINUX1_TOTALMMLETRA < 0x65)) {
          U_JUKELINUX1_TOTALMMLETRA = U_JUKELINUX1_TOTALMMLETRA + 1;
          *(undefined4 *)(puVar12 + -8) = 0x809e340;
          fpc_ansistr_decr_ref();
          uStack_478f9c = 0;
          *(undefined4 *)(puVar12 + -8) = 0x809e355;
          fpc_ansistr_decr_ref();
          auStack_478f98[0] = 0;
          *(undefined4 **)(puVar12 + -8) = auStack_478f98;
          *(undefined4 *)(puVar12 + -0xc) = 0x809e384;
          fpc_ansistr_copy();
          *(undefined4 *)(puVar12 + -0xc) = 0x809e395;
          SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)(puVar12 + -0xc) = 0x809e3a0;
          fpc_ansistr_incr_ref();
          iVar6 = U_JUKELINUX1_TOTALMMLETRA;
          *(undefined4 *)(puVar12 + -0xc) = 0x809e3b2;
          fpc_ansistr_decr_ref();
          piVar11 = (int *)(puVar12 + -8);
          (&U_JUKELINUX1_CDSELEAPAGARX)[iVar6] = uStack_478f9c;
        }
      } while (local_8 < iVar5);
    }
    *(undefined4 *)((int)piVar11 + -4) = 0x809e3d3;
    fpc_ansistr_decr_ref();
    uStack_478f9c = 0;
    *(undefined4 *)((int)piVar11 + -4) = 0x809e3f3;
    fpc_ansistr_concat();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e409;
    FPC_ANSISTR_TO_SHORTSTR();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e419;
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e423;
    SYSTEM_REWRITE_TEXT();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e428;
    fpc_iocheck();
    iVar5 = U_JUKELINUX1_TOTALMMLETRA;
    if (0 < U_JUKELINUX1_TOTALMMLETRA) {
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        *(undefined4 *)((int)piVar11 + -4) = 0x809e45c;
        fpc_write_text_ansistr();
        *(undefined4 *)((int)piVar11 + -4) = 0x809e461;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809e46b;
        fpc_writeln_end();
        *(undefined4 *)((int)piVar11 + -4) = 0x809e470;
        fpc_iocheck();
      } while (local_8 < iVar5);
    }
    *(undefined4 *)((int)piVar11 + -4) = 0x809e47f;
    SYSTEM_FLUSH_TEXT();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e484;
    fpc_iocheck();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e48e;
    OBJPAS_CLOSEFILE_TEXT();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e493;
    fpc_iocheck();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e4a8;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    pcVar1 = *(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e4c7;
    (*pcVar1)();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e4d1;
    CONTROLS_TCONTROL____REFRESH();
    pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e4e4;
    (*pcVar1)();
    U_JUKELINUX1_KR = 0;
    do {
      U_JUKELINUX1_KR = U_JUKELINUX1_KR + 1;
      iVar5 = U_JUKELINUX1_KR;
      *(undefined4 *)((int)piVar11 + -4) = 0x809e50c;
      fpc_ansistr_decr_ref();
      *(undefined4 *)(&DAT_092fffac + iVar5 * 4) = 0;
      iVar5 = U_JUKELINUX1_TOTALCDS;
    } while (U_JUKELINUX1_KR < 100);
    U_JUKELINUX1_TOTALMMRITMO = 0;
    if (0 < U_JUKELINUX1_TOTALCDS) {
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        bVar2 = false;
        local_c = 0;
        do {
          local_c = local_c + 1;
          *(undefined4 *)((int)piVar11 + -4) = 0x809e566;
          fpc_ansistr_decr_ref();
          uStack_478f9c = 0;
          *(undefined4 *)((int)piVar11 + -4) = 0x809e58a;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)piVar11 + -4) = 0x809e59f;
          iVar6 = fpc_ansistr_compare_equal();
          if (iVar6 == 0) {
            bVar2 = true;
          }
        } while (local_c < 100);
        if ((!bVar2) && (U_JUKELINUX1_TOTALMMRITMO < 0x65)) {
          U_JUKELINUX1_TOTALMMRITMO = U_JUKELINUX1_TOTALMMRITMO + 1;
          *(undefined4 *)((int)piVar11 + -4) = 0x809e5cf;
          fpc_ansistr_decr_ref();
          uStack_478f9c = 0;
          *(undefined4 *)((int)piVar11 + -4) = 0x809e5f3;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)piVar11 + -4) = 0x809e5fe;
          fpc_ansistr_incr_ref();
          iVar6 = U_JUKELINUX1_TOTALMMRITMO;
          *(undefined4 *)((int)piVar11 + -4) = 0x809e610;
          fpc_ansistr_decr_ref();
          *(undefined4 *)(&DAT_092fffac + iVar6 * 4) = uStack_478f9c;
        }
      } while (local_8 < iVar5);
    }
    pcVar1 = *(code **)(**(int **)(Form1.ButtonEO3 + 0x364) + 0xb8);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e651;
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(Form1.DataDaInstalacao + 0x36c) + 0xb8);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e67c;
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(Form1.ButtonGravarOsDados + 0x36c) + 0xb8);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e6a7;
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(Form1.CPF + 0x36c) + 0xb8);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e6d2;
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(Form1.Telefones + 0x36c) + 0xb8);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e6fd;
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(Form1.Bairro + 0x36c) + 0xb8);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e728;
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(Form1.Cidade + 0x36c) + 0xb8);
    *(undefined4 *)((int)piVar11 + -4) = 0x809e753;
    (*pcVar1)();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e75e;
    fpc_ansistr_decr_ref();
    uStack_478f9c = 0;
    *(undefined4 *)((int)piVar11 + -4) = 0x809e77e;
    fpc_ansistr_concat();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e794;
    FPC_ANSISTR_TO_SHORTSTR();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e7a4;
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e7ae;
    SYSTEM_REWRITE_TEXT();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e7b3;
    fpc_iocheck();
    iVar5 = U_JUKELINUX1_TOTALMMRITMO;
    if (0 < U_JUKELINUX1_TOTALMMRITMO) {
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        pcVar1 = *(code **)(**(int **)(Form1.ButtonEO3 + 0x364) + 0xa4);
        *(undefined4 *)((int)piVar11 + -4) = 0x809e804;
        (*pcVar1)();
        pcVar1 = *(code **)(**(int **)(Form1.DataDaInstalacao + 0x36c) + 0xa4);
        *(undefined4 *)((int)piVar11 + -4) = 0x809e839;
        (*pcVar1)();
        pcVar1 = *(code **)(**(int **)(Form1.ButtonGravarOsDados + 0x36c) + 0xa4);
        *(undefined4 *)((int)piVar11 + -4) = 0x809e86e;
        (*pcVar1)();
        pcVar1 = *(code **)(**(int **)(Form1.CPF + 0x36c) + 0xa4);
        *(undefined4 *)((int)piVar11 + -4) = 0x809e8a3;
        (*pcVar1)();
        pcVar1 = *(code **)(**(int **)(Form1.Telefones + 0x36c) + 0xa4);
        *(undefined4 *)((int)piVar11 + -4) = 0x809e8d8;
        (*pcVar1)();
        pcVar1 = *(code **)(**(int **)(Form1.Bairro + 0x36c) + 0xa4);
        *(undefined4 *)((int)piVar11 + -4) = 0x809e90d;
        (*pcVar1)();
        pcVar1 = *(code **)(**(int **)(Form1.Cidade + 0x36c) + 0xa4);
        *(undefined4 *)((int)piVar11 + -4) = 0x809e942;
        (*pcVar1)();
        *(undefined4 *)((int)piVar11 + -4) = 0x809e95b;
        fpc_write_text_ansistr();
        *(undefined4 *)((int)piVar11 + -4) = 0x809e960;
        fpc_iocheck();
        *(undefined4 *)((int)piVar11 + -4) = 0x809e96a;
        fpc_writeln_end();
        *(undefined4 *)((int)piVar11 + -4) = 0x809e96f;
        fpc_iocheck();
      } while (local_8 < iVar5);
    }
    *(undefined4 *)((int)piVar11 + -4) = 0x809e982;
    SYSTEM_FLUSH_TEXT();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e987;
    fpc_iocheck();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e991;
    OBJPAS_CLOSEFILE_TEXT();
    *(undefined4 *)((int)piVar11 + -4) = 0x809e996;
    fpc_iocheck();
  }
  piVar11[-1] = 0x809e99b;
  fpc_popaddrstack();
  piVar11[-1] = 0x809e9a6;
  fpc_ansistr_decr_ref();
  uStack_478f9c = 0;
  piVar11[-1] = 0x809e9bb;
  fpc_ansistr_decr_ref();
  auStack_478f98[0] = 0;
  piVar11[-1] = 0x809e9d0;
  fpc_ansistr_decr_ref();
  uStack_478e94 = 0;
  piVar11[-1] = 0x809e9e5;
  fpc_ansistr_decr_ref();
  auStack_478e90[0] = 0;
  piVar11[-1] = 0x809e9fa;
  fpc_ansistr_decr_ref();
  iStack_478d8c = 0;
  piVar11[-1] = 0x809ea0f;
  fpc_ansistr_decr_ref();
  auStack_478d88[0] = 0;
  piVar11[-1] = 0x809ea24;
  fpc_ansistr_decr_ref();
  uStack_478c84 = 0;
  piVar11[-1] = 0x809ea39;
  fpc_ansistr_decr_ref();
  uStack_478c80 = 0;
  piVar11[-1] = 0x809ea4e;
  fpc_ansistr_decr_ref();
  iStack_478c7c = 0;
  piVar11[-1] = 0x809ea63;
  fpc_ansistr_decr_ref();
  iStack_478c78 = 0;
  piVar11[-1] = 0x809ea78;
  fpc_ansistr_decr_ref();
  iStack_478c74 = 0;
  piVar11[-1] = 0x809ea8d;
  fpc_ansistr_decr_ref();
  aiStack_478c70[0] = 0;
  piVar11[-1] = 0x809eaa2;
  fpc_ansistr_decr_ref();
  aiStack_478c70[1] = 0;
  piVar11[-1] = 0x809eab7;
  fpc_ansistr_decr_ref();
  iStack_478b68 = 0;
  piVar11[-1] = 0x809eacc;
  fpc_ansistr_decr_ref();
  aiStack_478b58[0] = 0;
  piVar11[-1] = 0x809eade;
  fpc_ansistr_decr_ref();
  piVar11[-1] = 0x809eaed;
  fpc_ansistr_decr_ref();
  piVar11[-1] = 0x809eafc;
  fpc_ansistr_decr_ref();
  piVar11[-1] = 0x809eb13;
  FPC_FINALIZE();
  piVar11[-1] = 0x809eb23;
  FPC_FINALIZE();
  piVar11[-1] = 0x809eb33;
  FPC_FINALIZE();
  piVar11[-1] = 0x809eb3e;
  fpc_ansistr_decr_ref();
  aiStack_474c8c[0] = 0;
  piVar11[-1] = 0x809eb58;
  FPC_FINALIZE();
  piVar11[-1] = 0x809eb63;
  fpc_ansistr_decr_ref();
  uStack_478b20 = 0;
  piVar11[-1] = 0x809eb78;
  fpc_ansistr_decr_ref();
  iStack_478b24 = 0;
  if (*piVar11 != 0) {
    *piVar11 = 0x809eb8c;
    fpc_reraise();
  }
  return;
}

