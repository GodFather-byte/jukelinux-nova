// JUKELINUX1_TFORM1_$__BUTTONMUSCARREGARCLICK$TOBJECT  @ 080d04c0

void JUKELINUX1_TFORM1____BUTTONMUSCARREGARCLICK_TOBJECT(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined1 *puVar7;
  longdouble lVar8;
  int aiStack_1158 [3];
  char *local_1134;
  char *local_1130;
  char *local_112c;
  undefined *local_1128;
  char *local_1124;
  char *local_1120;
  char *local_102c;
  int local_1028;
  undefined *local_1024;
  char *local_1020;
  undefined4 local_101c;
  int local_1018;
  char *local_1014;
  int local_1010;
  undefined *local_100c;
  int local_1008;
  char *local_1004;
  int local_1000;
  undefined *local_ffc;
  int local_ff8;
  int local_ff4;
  int local_ff0;
  char local_fc4 [2000];
  int aiStack_7f4 [501];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  aiStack_1158[2] = 0x80d04f1;
  fpc_initialize();
  aiStack_1158[2] = 0x80d0501;
  fpc_initialize();
  local_1134 = (char *)0x0;
  local_101c = 0;
  local_1018 = 0;
  local_ff8 = 0;
  local_ff4 = 0;
  local_ff0 = 0;
  aiStack_1158[2] = 0x80d055d;
  fpc_pushexceptaddr();
  aiStack_1158[2] = 0x80d0562;
  aiStack_1158[2] = fpc_setjmp();
  piVar6 = aiStack_1158 + 2;
  if (aiStack_1158[2] == 0) {
    fpc_ansistr_decr_ref();
    local_ff0 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    iVar3 = 0;
    if (local_ff0 != 0) {
      iVar3 = *(int *)(local_ff0 + -4);
    }
    if (0 < iVar3) {
      fpc_ansistr_decr_ref();
      local_ff0 = 0;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      fpc_ansistr_concat();
    }
    local_10 = 0;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    iVar3 = 0;
    if (U_JUKELINUX1_PERIODOSTR != 0) {
      iVar3 = *(int *)(U_JUKELINUX1_PERIODOSTR + -4);
    }
    if (iVar3 < 1) {
      if (U_JUKELINUX1_SENHAOK == 1) {
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piVar6 = aiStack_1158 + 2;
      }
      else {
        DIALOGS_SHOWMESSAGE_ANSISTRING();
        piVar6 = aiStack_1158 + 2;
      }
    }
    else {
      cVar2 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
      if (cVar2 == '\0') {
        if (U_JUKELINUX1_SENHAOK == 1) {
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          fpc_ansistr_decr_ref();
          local_101c = 0;
          local_1130 = __JUKELINUX1__Ld859;
          local_112c = U_JUKELINUX1_NOMEPASTACDNOVO;
          local_1128 = &__JUKELINUX1__Ld860;
          fpc_ansistr_concat_multi();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          piVar6 = aiStack_1158 + 2;
        }
        else {
          fpc_ansistr_decr_ref();
          local_1130 = __JUKELINUX1__Ld859;
          local_112c = U_JUKELINUX1_NOMEPASTACDNOVO;
          local_1128 = &__JUKELINUX1__Ld861;
          fpc_ansistr_concat_multi();
          DIALOGS_SHOWMESSAGE_ANSISTRING();
          piVar6 = aiStack_1158 + 2;
        }
      }
      else {
        (**(code **)(**(int **)(local_c + 0x4f4) + 0x220))();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____REFRESH();
        (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
        local_1c = 0;
        FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
        iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
        piVar6 = aiStack_1158 + 2;
        if (-1 < iVar3 + -1) {
          local_18 = -1;
          piVar6 = aiStack_1158 + 2;
          do {
            local_18 = local_18 + 1;
            *(undefined4 *)((int)piVar6 + -4) = 0x80d06d2;
            fpc_ansistr_decr_ref();
            local_ff4 = 0;
            pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
            *(undefined4 *)((int)piVar6 + -4) = 0x80d0708;
            (*pcVar1)();
            *(undefined4 *)((int)piVar6 + -4) = 0x80d0718;
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 != 0) {
              *(undefined4 *)((int)piVar6 + -4) = 0x80d072b;
              fpc_ansistr_decr_ref();
              local_ff4 = 0;
              pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
              *(undefined4 *)((int)piVar6 + -4) = 0x80d0761;
              (*pcVar1)();
              *(undefined4 *)((int)piVar6 + -4) = 0x80d0771;
              iVar4 = fpc_ansistr_compare_equal();
              if (iVar4 != 0) {
                local_1c = local_1c + 1;
                *(undefined4 *)((int)piVar6 + -4) = 0x80d0787;
                fpc_ansistr_decr_ref();
                local_ff4 = 0;
                *(int **)((int)piVar6 + -4) = &local_ff4;
                *(undefined4 *)((int)piVar6 + -8) = 0x80d07a3;
                fpc_ansistr_decr_ref();
                local_ff8 = 0;
                pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                *(undefined4 *)((int)piVar6 + -8) = 0x80d07d9;
                (*pcVar1)();
                *(undefined4 *)((int)piVar6 + -8) = 0x80d07f6;
                fpc_ansistr_decr_ref();
                local_ff8 = 0;
                pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                *(undefined4 *)((int)piVar6 + -8) = 0x80d082c;
                (*pcVar1)();
                *(undefined4 *)((int)piVar6 + -8) = 0x80d083e;
                fpc_ansistr_copy();
                *(undefined4 *)((int)piVar6 + -8) = 0x80d0849;
                fpc_ansistr_incr_ref();
                iVar4 = local_1c;
                *(undefined4 *)((int)piVar6 + -8) = 0x80d0858;
                fpc_ansistr_decr_ref();
                piVar6 = (int *)((int)piVar6 + -4);
                aiStack_7f4[iVar4] = local_ff4;
              }
            }
          } while (local_18 < iVar3 + -1);
        }
        iVar3 = local_1c;
        local_20 = local_1c;
        if (0 < local_1c) {
          local_18 = 0;
          do {
            local_18 = local_18 + 1;
            *(undefined4 *)((int)piVar6 + -4) = 0x80d08a2;
            fpc_ansistr_decr_ref();
            local_ff8 = 0;
            local_1004 = U_JUKELINUX1_NOMEPASTACDNOVO;
            local_1000 = aiStack_7f4[local_18];
            local_ffc = &__JUKELINUX1__Ld115;
            *(undefined4 *)((int)piVar6 + -4) = 0x80d08e8;
            fpc_ansistr_concat_multi();
            *(undefined4 *)((int)piVar6 + -4) = 0x80d08fc;
            FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
            *(undefined4 *)((int)piVar6 + -4) = 0x80d090a;
            iVar4 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
            local_14 = 0;
            if (-1 < iVar4 + -1) {
              local_14 = -1;
              puVar7 = (undefined1 *)piVar6;
              do {
                local_14 = local_14 + 1;
                *(undefined4 *)(puVar7 + -4) = 0x80d092e;
                fpc_ansistr_decr_ref();
                local_ff8 = 0;
                pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                *(undefined4 *)(puVar7 + -4) = 0x80d0964;
                (*pcVar1)();
                *(undefined4 *)(puVar7 + -4) = 0x80d0974;
                iVar5 = fpc_ansistr_compare_equal();
                piVar6 = (int *)puVar7;
                if (iVar5 != 0) {
                  *(undefined4 *)(puVar7 + -4) = 0x80d0987;
                  fpc_ansistr_decr_ref();
                  local_ff8 = 0;
                  pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                  *(undefined4 *)(puVar7 + -4) = 0x80d09bd;
                  (*pcVar1)();
                  *(undefined4 *)(puVar7 + -4) = 0x80d09cd;
                  iVar5 = fpc_ansistr_compare_equal();
                  if (iVar5 != 0) {
                    local_1014 = U_JUKELINUX1_NOMEPASTACDNOVO;
                    local_1010 = aiStack_7f4[local_18];
                    local_100c = &__JUKELINUX1__Ld115;
                    *(undefined4 *)(puVar7 + -4) = 0x80d0a06;
                    fpc_ansistr_decr_ref();
                    local_ff8 = 0;
                    *(int **)(puVar7 + -4) = &local_ff8;
                    *(undefined4 *)(puVar7 + -8) = 0x80d0a22;
                    fpc_ansistr_decr_ref();
                    local_1018 = 0;
                    pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                    *(undefined4 *)(puVar7 + -8) = 0x80d0a58;
                    (*pcVar1)();
                    *(undefined4 *)(puVar7 + -8) = 0x80d0a72;
                    fpc_ansistr_decr_ref();
                    local_1018 = 0;
                    pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                    *(undefined4 *)(puVar7 + -8) = 0x80d0aa8;
                    (*pcVar1)();
                    *(undefined4 *)(puVar7 + -8) = 0x80d0aba;
                    fpc_ansistr_copy();
                    local_1008 = local_ff8;
                    *(undefined4 *)(puVar7 + -8) = 0x80d0adb;
                    fpc_ansistr_concat_multi();
                    if (U_JUKELINUX1_SENHAOK == 1) {
                      *(undefined4 *)(puVar7 + -8) = 0x80d0af4;
                      fpc_ansistr_decr_ref();
                      local_1018 = 0;
                      *(undefined4 *)(puVar7 + -8) = 0x80d0b09;
                      fpc_ansistr_decr_ref();
                      local_ff8 = 0;
                      *(undefined4 *)(puVar7 + -8) = 0x80d0b23;
                      SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                      *(undefined4 *)(puVar7 + -8) = 0x80d0b34;
                      SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                      *(undefined4 *)(puVar7 + -8) = 0x80d0b44;
                      iVar5 = fpc_ansistr_compare_equal();
                      if (iVar5 == 0) {
                        *(undefined4 *)(puVar7 + -8) = 0x80d0b57;
                        fpc_ansistr_decr_ref();
                        local_1018 = 0;
                        *(undefined4 *)(puVar7 + -8) = 0x80d0b6c;
                        fpc_ansistr_decr_ref();
                        local_ff8 = 0;
                        *(undefined4 *)(puVar7 + -8) = 0x80d0b86;
                        SYSUTILS_EXTRACTFILENAME_ANSISTRING__ANSISTRING();
                        *(undefined4 *)(puVar7 + -8) = 0x80d0b97;
                        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                        *(undefined4 *)(puVar7 + -8) = 0x80d0ba7;
                        iVar5 = fpc_ansistr_compare_equal();
                        if (iVar5 == 0) {
                          *(undefined4 *)(puVar7 + -8) = 0x80d0bb5;
                          fpc_ansistr_incr_ref();
                          iVar5 = local_18;
                          *(undefined4 *)(puVar7 + -8) = 0x80d0bc4;
                          fpc_ansistr_decr_ref();
                          *(undefined4 *)(local_fc4 + iVar5 * 4) = U_JUKELINUX1_ORIGEM;
                        }
                      }
                    }
                    piVar6 = (int *)(puVar7 + -4);
                    if (U_JUKELINUX1_SENHAOK == 2) {
                      *(undefined4 *)(puVar7 + -8) = 0x80d0be9;
                      fpc_ansistr_decr_ref();
                      local_1018 = 0;
                      *(undefined4 *)(puVar7 + -8) = 0x80d0bfe;
                      fpc_ansistr_decr_ref();
                      local_ff8 = 0;
                      *(undefined4 *)(puVar7 + -8) = 0x80d0c18;
                      SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
                      *(undefined4 *)(puVar7 + -8) = 0x80d0c29;
                      SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                      *(undefined4 *)(puVar7 + -8) = 0x80d0c39;
                      iVar5 = fpc_ansistr_compare_equal();
                      piVar6 = (int *)(puVar7 + -4);
                      if (iVar5 == 0) {
                        *(undefined4 *)(puVar7 + -8) = 0x80d0c4c;
                        fpc_ansistr_decr_ref();
                        local_1018 = 0;
                        *(undefined4 *)(puVar7 + -8) = 0x80d0c61;
                        fpc_ansistr_decr_ref();
                        local_ff8 = 0;
                        *(undefined4 *)(puVar7 + -8) = 0x80d0c7b;
                        SYSUTILS_EXTRACTFILENAME_ANSISTRING__ANSISTRING();
                        *(undefined4 *)(puVar7 + -8) = 0x80d0c8c;
                        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
                        *(undefined4 *)(puVar7 + -8) = 0x80d0c9c;
                        iVar5 = fpc_ansistr_compare_equal();
                        piVar6 = (int *)(puVar7 + -4);
                        if (iVar5 == 0) {
                          *(undefined4 *)(puVar7 + -8) = 0x80d0caa;
                          fpc_ansistr_incr_ref();
                          iVar5 = local_18;
                          *(undefined4 *)(puVar7 + -8) = 0x80d0cb9;
                          fpc_ansistr_decr_ref();
                          piVar6 = (int *)(puVar7 + -4);
                          *(undefined4 *)(local_fc4 + iVar5 * 4) = U_JUKELINUX1_ORIGEM;
                        }
                      }
                    }
                  }
                }
                puVar7 = (undefined1 *)piVar6;
              } while (local_14 < iVar4 + -1);
            }
          } while (local_18 < iVar3);
        }
        iVar3 = local_20;
        local_18 = 1;
        if (0 < local_20) {
          local_18 = 0;
          puVar7 = (undefined1 *)piVar6;
          do {
            local_18 = local_18 + 1;
            local_fc4[0] = '\x01';
            pcVar1 = *(code **)(**(int **)(local_c + 0x6a0) + 0x450);
            *(undefined4 *)(puVar7 + -4) = 0x80d0d24;
            cVar2 = (*pcVar1)();
            if (cVar2 == '\0') {
              *(undefined4 *)(puVar7 + -4) = 0x80d0d33;
              fpc_ansistr_decr_ref();
              local_1018 = 0;
              *(undefined4 *)(puVar7 + -4) = 0x80d0d58;
              fpc_ansistr_concat();
              *(undefined4 *)(puVar7 + -4) = 0x80d0d63;
              cVar2 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
              if (cVar2 != '\0') {
                local_fc4[0] = '\0';
              }
            }
            piVar6 = (int *)puVar7;
            if (local_fc4[0] != '\0') {
              *(undefined4 *)(puVar7 + -4) = 0x80d0d86;
              fpc_ansistr_decr_ref();
              local_1018 = 0;
              *(undefined4 *)(puVar7 + -4) = 0x80d0dab;
              fpc_ansistr_concat();
              *(undefined4 *)(puVar7 + -4) = 0x80d0db6;
              cVar2 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
              if (cVar2 == '\0') {
                *(undefined4 *)(puVar7 + -4) = 0x80d0dc5;
                fpc_ansistr_decr_ref();
                local_1018 = 0;
                *(undefined4 *)(puVar7 + -4) = 0x80d0dea;
                fpc_ansistr_concat();
                *(undefined4 *)(puVar7 + -4) = 0x80d0df5;
                SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
                *(undefined4 *)(puVar7 + -4) = 0x80d0dff;
                SYSUTILS_SLEEP_LONGWORD();
              }
              *(undefined4 *)(puVar7 + -4) = 0x80d0e0a;
              fpc_ansistr_decr_ref();
              local_1018 = 0;
              *(undefined4 *)(puVar7 + -4) = 0x80d0e2f;
              fpc_ansistr_concat();
              *(undefined4 *)(puVar7 + -4) = 0x80d0e3a;
              cVar2 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
              if (cVar2 != '\0') {
                *(undefined4 *)(puVar7 + -4) = 0x80d0e4d;
                fpc_ansistr_decr_ref();
                local_101c = 0;
                local_1014 = __JUKELINUX1__Ld850;
                *(undefined4 *)(puVar7 + -4) = 0x80d0e6d;
                fpc_ansistr_decr_ref();
                local_1018 = 0;
                *(undefined4 *)(puVar7 + -4) = 0x80d0e85;
                SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                local_1010 = local_1018;
                local_100c = &__JUKELINUX1__Ld115;
                *(undefined4 *)(puVar7 + -4) = 0x80d0ea7;
                fpc_ansistr_decr_ref();
                local_ff8 = 0;
                *(undefined4 *)(puVar7 + -4) = 0x80d0ebf;
                SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                local_1008 = local_ff8;
                *(undefined4 *)(puVar7 + -4) = 0x80d0ee1;
                fpc_ansistr_concat_multi();
                *(undefined4 *)(puVar7 + -4) = 0x80d0ef5;
                CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                pcVar1 = *(code **)(**(int **)(local_c + 0x904) + 0x2fc);
                *(undefined4 *)(puVar7 + -4) = 0x80d0f0f;
                (*pcVar1)();
                *(undefined4 *)(puVar7 + -4) = 0x80d0f1a;
                fpc_ansistr_decr_ref();
                local_101c = 0;
                local_1014 = __JUKELINUX1__Ld850;
                *(undefined4 *)(puVar7 + -4) = 0x80d0f3a;
                fpc_ansistr_decr_ref();
                local_1018 = 0;
                *(undefined4 *)(puVar7 + -4) = 0x80d0f52;
                SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                local_1010 = local_1018;
                local_100c = &__JUKELINUX1__Ld115;
                *(undefined4 *)(puVar7 + -4) = 0x80d0f74;
                fpc_ansistr_decr_ref();
                local_ff8 = 0;
                *(undefined4 *)(puVar7 + -4) = 0x80d0f8c;
                SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                local_1008 = local_ff8;
                *(undefined4 *)(puVar7 + -4) = 0x80d0fae;
                fpc_ansistr_concat_multi();
                *(undefined4 *)(puVar7 + -4) = 0x80d0fc2;
                CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                pcVar1 = *(code **)(**(int **)(local_c + 0x8bc) + 0x2fc);
                *(undefined4 *)(puVar7 + -4) = 0x80d0fdc;
                (*pcVar1)();
                *(undefined4 *)(puVar7 + -4) = 0x80d0ffa;
                GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
                *(undefined4 *)(puVar7 + -4) = 0x80d1018;
                GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
                *(undefined4 *)(puVar7 + -4) = 0x80d1022;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
                *(undefined4 *)(puVar7 + -4) = 0x80d1035;
                (*pcVar1)();
                local_1c = 0;
                *(undefined4 *)(puVar7 + -4) = 0x80d1047;
                fpc_ansistr_decr_ref();
                local_1018 = 0;
                local_1004 = U_JUKELINUX1_NOMEPASTACDNOVO;
                local_1000 = aiStack_7f4[local_18];
                local_ffc = &__JUKELINUX1__Ld115;
                *(undefined4 *)(puVar7 + -4) = 0x80d108d;
                fpc_ansistr_concat_multi();
                *(undefined4 *)(puVar7 + -4) = 0x80d10a1;
                FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
                *(undefined4 *)(puVar7 + -4) = 0x80d10ac;
                fpc_ansistr_decr_ref();
                local_1018 = 0;
                local_1130 = U_JUKELINUX1_PASTAMUSICAS;
                local_112c = &__JUKELINUX1__Ld115;
                local_1128 = (undefined *)aiStack_7f4[local_18];
                local_1124 = &__JUKELINUX1__Ld115;
                local_1120 = __JUKELINUX1__Ld851;
                *(undefined4 *)(puVar7 + -4) = 0x80d1108;
                fpc_ansistr_concat_multi();
                *(undefined4 *)(puVar7 + -4) = 0x80d111e;
                FPC_ANSISTR_TO_SHORTSTR();
                *(undefined4 *)(puVar7 + -4) = 0x80d112e;
                OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
                *(undefined4 *)(puVar7 + -4) = 0x80d1138;
                SYSTEM_REWRITE_TEXT();
                *(undefined4 *)(puVar7 + -4) = 0x80d113d;
                fpc_iocheck();
                *(undefined4 *)(puVar7 + -4) = 0x80d1152;
                fpc_write_text_ansistr();
                *(undefined4 *)(puVar7 + -4) = 0x80d1157;
                fpc_iocheck();
                *(undefined4 *)(puVar7 + -4) = 0x80d1161;
                fpc_writeln_end();
                *(undefined4 *)(puVar7 + -4) = 0x80d1166;
                fpc_iocheck();
                *(undefined4 *)(puVar7 + -4) = 0x80d1171;
                fpc_ansistr_decr_ref();
                local_1018 = 0;
                *(undefined4 *)(puVar7 + -4) = 0x80d1180;
                lVar8 = (longdouble)SYSUTILS_DATE__TDATETIME();
                *(double *)(puVar7 + -8) = (double)lVar8;
                *(undefined4 *)(puVar7 + -0xc) = 0x80d1191;
                SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11a6;
                fpc_write_text_ansistr();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11ab;
                fpc_iocheck();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11b5;
                fpc_writeln_end();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11ba;
                fpc_iocheck();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11c4;
                SYSTEM_FLUSH_TEXT();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11c9;
                fpc_iocheck();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11d3;
                OBJPAS_CLOSEFILE_TEXT();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11d8;
                fpc_iocheck();
                *(undefined4 *)(puVar7 + -0xc) = 0x80d11e6;
                iVar4 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
                piVar6 = (int *)(puVar7 + -8);
                local_14 = 0;
                if (-1 < iVar4 + -1) {
                  local_14 = -1;
                  puVar7 = puVar7 + -8;
                  do {
                    local_14 = local_14 + 1;
                    *(undefined4 *)(puVar7 + -4) = 0x80d120a;
                    fpc_ansistr_decr_ref();
                    local_1018 = 0;
                    pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                    *(undefined4 *)(puVar7 + -4) = 0x80d1240;
                    (*pcVar1)();
                    *(undefined4 *)(puVar7 + -4) = 0x80d1250;
                    iVar5 = fpc_ansistr_compare_equal();
                    piVar6 = (int *)puVar7;
                    if (iVar5 != 0) {
                      *(undefined4 *)(puVar7 + -4) = 0x80d1263;
                      fpc_ansistr_decr_ref();
                      local_1018 = 0;
                      pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                      *(undefined4 *)(puVar7 + -4) = 0x80d1299;
                      (*pcVar1)();
                      *(undefined4 *)(puVar7 + -4) = 0x80d12a9;
                      iVar5 = fpc_ansistr_compare_equal();
                      if (iVar5 != 0) {
                        *(undefined4 *)(puVar7 + -4) = 0x80d12bc;
                        fpc_ansistr_decr_ref();
                        local_1018 = 0;
                        *(int **)(puVar7 + -4) = &local_1018;
                        *(undefined4 *)(puVar7 + -8) = 0x80d12d8;
                        fpc_ansistr_decr_ref();
                        local_1134 = (char *)0x0;
                        pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                        *(undefined4 *)(puVar7 + -8) = 0x80d130e;
                        (*pcVar1)();
                        *(undefined4 *)(puVar7 + -8) = 0x80d1328;
                        fpc_ansistr_decr_ref();
                        local_1134 = (char *)0x0;
                        pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                        *(undefined4 *)(puVar7 + -8) = 0x80d135e;
                        (*pcVar1)();
                        *(undefined4 *)(puVar7 + -8) = 0x80d1370;
                        fpc_ansistr_copy();
                        *(undefined4 *)(puVar7 + -8) = 0x80d1380;
                        iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
                        piVar6 = (int *)(puVar7 + -4);
                        if (iVar5 == 0) {
                          local_102c = U_JUKELINUX1_NOMEPASTACDNOVO;
                          local_1028 = aiStack_7f4[local_18];
                          local_1024 = &__JUKELINUX1__Ld115;
                          *(undefined4 *)(puVar7 + -8) = 0x80d13b9;
                          fpc_ansistr_decr_ref();
                          local_1134 = (char *)0x0;
                          *(char ***)(puVar7 + -8) = &local_1134;
                          *(undefined4 *)(puVar7 + -0xc) = 0x80d13d5;
                          fpc_ansistr_decr_ref();
                          local_1018 = 0;
                          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                          *(undefined4 *)(puVar7 + -0xc) = 0x80d140b;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0xc) = 0x80d1425;
                          fpc_ansistr_decr_ref();
                          local_1018 = 0;
                          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                          *(undefined4 *)(puVar7 + -0xc) = 0x80d145b;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0xc) = 0x80d146d;
                          fpc_ansistr_copy();
                          local_1020 = local_1134;
                          *(undefined4 *)(puVar7 + -0xc) = 0x80d148e;
                          fpc_ansistr_concat_multi();
                          local_102c = U_JUKELINUX1_PASTAMUSICAS;
                          local_1028 = aiStack_7f4[local_18];
                          local_1024 = &__JUKELINUX1__Ld115;
                          *(undefined4 *)(puVar7 + -0xc) = 0x80d14bf;
                          fpc_ansistr_decr_ref();
                          local_1134 = (char *)0x0;
                          *(char ***)(puVar7 + -0xc) = &local_1134;
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d14db;
                          fpc_ansistr_decr_ref();
                          local_1018 = 0;
                          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d1511;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d152b;
                          fpc_ansistr_decr_ref();
                          local_1018 = 0;
                          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d1561;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d1573;
                          fpc_ansistr_copy();
                          local_1020 = local_1134;
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d1594;
                          fpc_ansistr_concat_multi();
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d159f;
                          fpc_ansistr_decr_ref();
                          local_101c = 0;
                          local_1130 = __JUKELINUX1__Ld852;
                          local_112c = (char *)aiStack_7f4[local_18];
                          local_1128 = &__JUKELINUX1__Ld285;
                          local_1124 = __JUKELINUX1__Ld853;
                          *(undefined4 *)(puVar7 + -0x10) = 0x80d15e5;
                          fpc_ansistr_decr_ref();
                          local_1134 = (char *)0x0;
                          *(char ***)(puVar7 + -0x10) = &local_1134;
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1601;
                          fpc_ansistr_decr_ref();
                          local_1018 = 0;
                          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1637;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1651;
                          fpc_ansistr_decr_ref();
                          local_1018 = 0;
                          pcVar1 = *(code **)(**(int **)(*(int *)(local_c + 0x9c8) + 0x364) + 0x78);
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1687;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1699;
                          fpc_ansistr_copy();
                          local_1120 = local_1134;
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d16bb;
                          fpc_ansistr_concat_multi();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d16cf;
                          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                          pcVar1 = *(code **)(**(int **)(local_c + 0x8c4) + 0x2fc);
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d16e9;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d16f4;
                          fpc_ansistr_decr_ref();
                          local_101c = 0;
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1712;
                          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1726;
                          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                          pcVar1 = *(code **)(**(int **)(local_c + 0x8c0) + 0x2fc);
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1740;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d174a;
                          CONTROLS_TCONTROL____REFRESH();
                          pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d175d;
                          (*pcVar1)();
                          pcVar1 = *(code **)(**(int **)(local_c + 0xa2c) + 0x2fc);
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1777;
                          (*pcVar1)();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d1782;
                          fpc_ansistr_decr_ref();
                          local_1134 = (char *)0x0;
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d17a5;
                          fpc_pchar_to_ansistr();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d17b6;
                          fpc_ansistr_decr_ref();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d17d9;
                          fpc_pchar_to_ansistr();
                          *(undefined4 *)(puVar7 + -0x14) = 0x80d17e8;
                          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
                          piVar6 = (int *)(puVar7 + -0x10);
                          local_10 = local_10 + 1;
                        }
                      }
                    }
                    puVar7 = (undefined1 *)piVar6;
                  } while (local_14 < iVar4 + -1);
                }
              }
            }
            puVar7 = (undefined1 *)piVar6;
          } while (local_18 < iVar3);
        }
        if (0 < local_10) {
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1819;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1839;
          fpc_ansistr_concat();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d184f;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d185f;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1869;
          SYSTEM_REWRITE_TEXT();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d186e;
          fpc_iocheck();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1879;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1888;
          lVar8 = (longdouble)SYSUTILS_DATE__TDATETIME();
          *(double *)((int)piVar6 + -8) = (double)lVar8;
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d1899;
          SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18ae;
          fpc_write_text_ansistr();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18b3;
          fpc_iocheck();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18bd;
          fpc_writeln_end();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18c2;
          fpc_iocheck();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18cd;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18e5;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18fa;
          fpc_write_text_ansistr();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d18ff;
          fpc_iocheck();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d1909;
          fpc_writeln_end();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d190e;
          fpc_iocheck();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d1918;
          SYSTEM_FLUSH_TEXT();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d191d;
          fpc_iocheck();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d1927;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)piVar6 + -0xc) = 0x80d192c;
          fpc_iocheck();
          piVar6 = (int *)((int)piVar6 + -8);
        }
        if (local_10 < 1) {
          U_JUKELINUX1_RELECDS = 1;
          *(undefined4 *)((int)piVar6 + -4) = 0x80d19be;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d19d1;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d19e4;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d19f7;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1a0a;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1a18;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          U_JUKELINUX1_RELECDS = 1;
          *(undefined4 *)((int)piVar6 + -4) = 0x80d194d;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1960;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1973;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1986;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d1994;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)piVar6 + -4) = 0x80d19a2;
          CONTROLS_TCONTROL____HIDE();
        }
        *(undefined4 *)((int)piVar6 + -4) = 0x80d1a23;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar6 + -4) = 0x80d1a38;
        fpc_ansistr_decr_ref();
        local_101c = 0;
        *(undefined4 *)((int)piVar6 + -4) = 0x80d1a56;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        *(undefined4 *)((int)piVar6 + -4) = 0x80d1a6c;
        fpc_ansistr_concat();
        *(undefined4 *)((int)piVar6 + -4) = 0x80d1a77;
        JUKELINUX1_GRAVALOG_ANSISTRING();
      }
    }
  }
  piVar6[-1] = 0x80d1b98;
  fpc_popaddrstack();
  piVar6[-1] = 0x80d1ba3;
  fpc_ansistr_decr_ref();
  piVar6[-1] = 0x80d1bb8;
  fpc_ansistr_decr_ref();
  local_1134 = (char *)0x0;
  piVar6[-1] = 0x80d1bcd;
  fpc_ansistr_decr_ref();
  local_101c = 0;
  piVar6[-1] = 0x80d1be2;
  fpc_ansistr_decr_ref();
  local_1018 = 0;
  piVar6[-1] = 0x80d1bf7;
  fpc_ansistr_decr_ref();
  local_ff8 = 0;
  piVar6[-1] = 0x80d1c0c;
  fpc_ansistr_decr_ref();
  local_ff4 = 0;
  piVar6[-1] = 0x80d1c21;
  fpc_ansistr_decr_ref();
  local_ff0 = 0;
  piVar6[-1] = 0x80d1c3b;
  FPC_FINALIZE();
  piVar6[-1] = 0x80d1c4b;
  FPC_FINALIZE();
  if (*piVar6 != 0) {
    *piVar6 = 0x80d1c55;
    fpc_reraise();
  }
  return;
}

