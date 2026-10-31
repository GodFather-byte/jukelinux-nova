// JUKELINUX1_ROTINA_RITMOS  @ 080a94f0

void JUKELINUX1_ROTINA_RITMOS(void)

{
  int iVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 **ppuVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 **ppuVar7;
  int aiStack_17c [2];
  undefined4 *puStack_174;
  undefined4 *puStack_170;
  int iStack_16c;
  undefined4 local_34;
  undefined4 local_30 [11];
  
  local_34 = 0;
  local_30[0] = 0;
  iStack_16c = 0x80a955d;
  fpc_pushexceptaddr();
  iStack_16c = 0x80a9562;
  iStack_16c = fpc_setjmp();
  ppuVar7 = (undefined4 **)&iStack_16c;
  if (iStack_16c == 0) {
    if (U_JUKELINUX1_ESTANOMENU == '\0') {
      puStack_170 = (undefined4 *)0x80a9587;
      iVar1 = fpc_ansistr_compare_equal();
      ppuVar4 = (undefined4 **)&iStack_16c;
      if (iVar1 == 0) {
        puStack_170 = (undefined4 *)0x80a959f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a95af;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a95bf;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a95cf;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a95df;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a95ef;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a95ff;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a960f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a961f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a962f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a963f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a964f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a965f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a966f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a967f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a968f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a969f;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a96af;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a96bf;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a96cf;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a96df;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a96ef;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a96ff;
        CONTROLS_TCONTROL____HIDE();
        puStack_170 = (undefined4 *)0x80a9707;
        fpc_ansistr_decr_ref();
        local_30[0] = 0;
        puStack_170 = local_30;
        puStack_174 = (undefined4 *)0x80a9726;
        fpc_ansistr_copy();
        puStack_174 = (undefined4 *)0x80a9733;
        iVar1 = fpc_ansistr_compare_equal();
        if (iVar1 == 0) {
          if (U_JUKELINUX1_MOSTRANDORITMOS == '\0') {
            puStack_174 = (undefined4 *)0x80a974d;
            JUKELINUX1_DESSELECIONAMUSICA();
            U_JUKELINUX1_MUSICASELECIONADA = 0;
            U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
            U_JUKELINUX1_MUSICASELECIONADATS = 0;
            puStack_174 = (undefined4 *)0x80a9770;
            JUKELINUX1_SELECIONAMUSICA();
            puStack_174 = (undefined4 *)0x80a977a;
            fpc_ansistr_incr_ref();
            puStack_174 = (undefined4 *)0x80a9784;
            fpc_ansistr_decr_ref();
            iVar1 = U_JUKELINUX1_TOTALMMRITMO;
            U_JUKELINUX1_RITMOSELECIONADO = U_JUKELINUX1_RITMODOCD;
            U_JUKELINUX1_NUMRITMOSELECIONADO = 0;
            U_JUKELINUX1_KR = 1;
            if (0 < U_JUKELINUX1_TOTALMMRITMO) {
              U_JUKELINUX1_KR = 0;
              do {
                U_JUKELINUX1_KR = U_JUKELINUX1_KR + 1;
                puStack_174 = (undefined4 *)0x80a97d4;
                iVar2 = fpc_ansistr_compare_equal();
                if (iVar2 == 0) {
                  U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_KR;
                }
              } while (U_JUKELINUX1_KR < iVar1);
            }
            puStack_174 = (undefined4 *)0x80a97ef;
            JUKELINUX1_MOSTRA_RITMOS();
            U_JUKELINUX1_MOSTRANDORITMOS = '\x01';
            puStack_174 = (undefined4 *)0x80a9817;
            (**(code **)(*Form1.LabelEntrarNoMenu + 0xd8))();
            if (U_JUKELINUX1_RESOLUCAO == 0x556) {
              puStack_174 = (undefined4 *)0x80a9837;
              JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
              puStack_174 = (undefined4 *)0x80a9857;
              JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            if (U_JUKELINUX1_RESOLUCAO == 0x400) {
              puStack_174 = (undefined4 *)0x80a987b;
              JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
          }
          else {
            puStack_174 = (undefined4 *)0x80a98a1;
            (**(code **)(*Form1.LabelEntrarNoMenu + 0xd8))();
            iVar2 = U_JUKELINUX1_NUMRITMOSELECIONADO;
            puStack_174 = (undefined4 *)0x80a98b3;
            fpc_ansistr_incr_ref();
            puStack_174 = (undefined4 *)0x80a98bd;
            fpc_ansistr_decr_ref();
            iVar1 = U_JUKELINUX1_TOTALCDS;
            U_JUKELINUX1_RITMOESCOLHIDO = *(undefined4 *)(&DAT_092fffac + iVar2 * 4);
            U_JUKELINUX1_POSICAORITMO = 0;
            U_JUKELINUX1_KKRITMO = 1;
            if (0 < U_JUKELINUX1_TOTALCDS) {
              U_JUKELINUX1_KKRITMO = 0;
              do {
                U_JUKELINUX1_KKRITMO = U_JUKELINUX1_KKRITMO + 1;
                puStack_174 = (undefined4 *)0x80a9902;
                fpc_ansistr_decr_ref();
                local_30[0] = 0;
                puStack_174 = (undefined4 *)0x80a9922;
                fpc_shortstr_to_ansistr();
                puStack_174 = (undefined4 *)0x80a9930;
                iVar2 = fpc_ansistr_compare_equal();
                if ((iVar2 == 0) && (U_JUKELINUX1_POSICAORITMO == 0)) {
                  U_JUKELINUX1_POSICAORITMO = U_JUKELINUX1_KKRITMO;
                }
              } while (U_JUKELINUX1_KKRITMO < iVar1);
            }
            if (U_JUKELINUX1_POSICAORITMO == 0) {
              U_JUKELINUX1_KMAT = 1;
            }
            else {
              U_JUKELINUX1_KMAT = U_JUKELINUX1_POSICAORITMO + -5;
            }
            U_JUKELINUX1_MUSICASELECIONADA = 0;
            U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
            U_JUKELINUX1_MUSICASELECIONADATS = 0;
            U_JUKELINUX1_MOSTRANDORITMOS = '\0';
            U_JUKELINUX1_MOSTRANDOLETRAS = '\0';
            puStack_174 = (undefined4 *)0x80a99ae;
            JUKELINUX1_MOSTRA_CDS_ANSISTRING();
            puStack_174 = (undefined4 *)0x80a99b3;
            JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS();
            puStack_174 = (undefined4 *)0x80a99b8;
            JUKELINUX1_DESTRAVAMENSAGEM();
          }
        }
        puStack_174 = (undefined4 *)0x80a99c0;
        fpc_ansistr_decr_ref();
        local_30[0] = 0;
        puStack_174 = local_30;
        fpc_ansistr_copy();
        iVar1 = fpc_ansistr_compare_equal();
        ppuVar4 = &puStack_174;
        if (iVar1 == 0) {
          if (U_JUKELINUX1_MOSTRANDOLETRAS == '\0') {
            JUKELINUX1_DESSELECIONAMUSICA();
            U_JUKELINUX1_MUSICASELECIONADA = 0;
            U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
            U_JUKELINUX1_MUSICASELECIONADATS = 0;
            JUKELINUX1_SELECIONAMUSICA();
            fpc_ansistr_decr_ref();
            local_30[0] = 0;
            SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            iVar1 = U_JUKELINUX1_TOTALMMLETRA;
            U_JUKELINUX1_LETRASELECIONADA = local_30[0];
            U_JUKELINUX1_NUMLETRASELECIONADA = 0;
            U_JUKELINUX1_KL = 1;
            if (0 < U_JUKELINUX1_TOTALMMLETRA) {
              U_JUKELINUX1_KL = 0;
              do {
                U_JUKELINUX1_KL = U_JUKELINUX1_KL + 1;
                iVar2 = fpc_ansistr_compare_equal();
                if (iVar2 == 0) {
                  U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_KL;
                }
              } while (U_JUKELINUX1_KL < iVar1);
            }
            JUKELINUX1_MOSTRA_LETRAS();
            U_JUKELINUX1_MOSTRANDOLETRAS = '\x01';
            (**(code **)(*Form1.LabelPress3 + 0xd8))();
            if (U_JUKELINUX1_RESOLUCAO == 0x556) {
              JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
              JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
            }
            ppuVar4 = &puStack_174;
            if (U_JUKELINUX1_RESOLUCAO == 0x400) {
              JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING();
              ppuVar4 = &puStack_174;
            }
          }
          else {
            (**(code **)(*Form1.LabelPress3 + 0xd8))();
            fpc_ansistr_decr_ref();
            local_30[0] = 0;
            SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            iVar1 = U_JUKELINUX1_TOTALCDS;
            ppuVar4 = &puStack_174;
            ppuVar3 = &puStack_174;
            U_JUKELINUX1_LETRAESCOLHIDA = local_30[0];
            U_JUKELINUX1_POSICAOLETRA = 0;
            U_JUKELINUX1_KKLETRA = 1;
            if (0 < U_JUKELINUX1_TOTALCDS) {
              U_JUKELINUX1_KKLETRA = 0;
              do {
                U_JUKELINUX1_KKLETRA = U_JUKELINUX1_KKLETRA + 1;
                *(undefined4 *)((int)ppuVar3 + -4) = 0x80a9bea;
                fpc_ansistr_decr_ref();
                local_30[0] = 0;
                *(undefined4 *)((int)ppuVar3 + -4) = 0x80a9bf9;
                fpc_ansistr_decr_ref();
                local_34 = 0;
                *(undefined4 **)((int)ppuVar3 + -4) = &local_34;
                *(undefined4 *)((int)ppuVar3 + -8) = 0x80a9c24;
                fpc_ansistr_copy();
                *(undefined4 *)((int)ppuVar3 + -8) = 0x80a9c2f;
                SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
                *(undefined4 *)((int)ppuVar3 + -8) = 0x80a9c3d;
                iVar2 = fpc_ansistr_compare_equal();
                ppuVar4 = (undefined4 **)((int)ppuVar3 + -4);
                ppuVar3 = (undefined4 **)((int)ppuVar3 + -4);
                if ((iVar2 == 0) && (U_JUKELINUX1_POSICAOLETRA == 0)) {
                  U_JUKELINUX1_POSICAOLETRA = U_JUKELINUX1_KKLETRA;
                }
              } while (U_JUKELINUX1_KKLETRA < iVar1);
            }
            if (U_JUKELINUX1_POSICAOLETRA == 0) {
              U_JUKELINUX1_KMAT = 1;
            }
            else {
              U_JUKELINUX1_KMAT = U_JUKELINUX1_POSICAOLETRA + -5;
            }
            U_JUKELINUX1_MUSICASELECIONADA = 0;
            U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
            U_JUKELINUX1_MUSICASELECIONADATS = 0;
            U_JUKELINUX1_MOSTRANDORITMOS = '\0';
            U_JUKELINUX1_MOSTRANDOLETRAS = '\0';
            *(undefined4 *)((int)ppuVar4 + -4) = 0x80a9cbf;
            JUKELINUX1_MOSTRA_CDS_ANSISTRING();
            *(undefined4 *)((int)ppuVar4 + -4) = 0x80a9cc4;
            JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS();
            *(undefined4 *)((int)ppuVar4 + -4) = 0x80a9cc9;
            JUKELINUX1_DESTRAVAMENSAGEM();
          }
        }
      }
      *(undefined4 *)((int)ppuVar4 + -4) = 0x80a9cd8;
      iVar1 = fpc_ansistr_compare_equal();
      ppuVar7 = ppuVar4;
      if (iVar1 == 0) {
        *(undefined4 *)((int)ppuVar4 + -4) = 0x80a9ce8;
        fpc_ansistr_decr_ref();
        local_34 = 0;
        *(undefined4 **)((int)ppuVar4 + -4) = &local_34;
        *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9d07;
        fpc_ansistr_copy();
        *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9d14;
        iVar1 = fpc_ansistr_compare_equal();
        if (iVar1 == 0) {
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9d21;
          JUKELINUX1_DESSELECIONAMUSICA();
          U_JUKELINUX1_MUSICASELECIONADA = 0;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
          U_JUKELINUX1_MUSICASELECIONADATS = 0;
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9d44;
          JUKELINUX1_SELECIONAMUSICA();
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9d4e;
          fpc_ansistr_incr_ref();
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9d58;
          fpc_ansistr_decr_ref();
          iVar1 = U_JUKELINUX1_TOTALMMRITMO;
          U_JUKELINUX1_RITMOSELECIONADO = U_JUKELINUX1_RITMODOCD;
          U_JUKELINUX1_NUMRITMOSELECIONADO = 0;
          U_JUKELINUX1_KR = 1;
          if (0 < U_JUKELINUX1_TOTALMMRITMO) {
            U_JUKELINUX1_KR = 0;
            do {
              U_JUKELINUX1_KR = U_JUKELINUX1_KR + 1;
              *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9da8;
              iVar2 = fpc_ansistr_compare_equal();
              if (iVar2 == 0) {
                U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_KR;
              }
            } while (U_JUKELINUX1_KR < iVar1);
          }
          U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + 1;
          if (U_JUKELINUX1_TOTALMMRITMO < U_JUKELINUX1_NUMRITMOSELECIONADO) {
            U_JUKELINUX1_NUMRITMOSELECIONADO = 1;
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x556) {
            *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9e02;
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
            *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9e29;
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x400) {
            *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9e50;
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          iVar2 = U_JUKELINUX1_NUMRITMOSELECIONADO;
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9e62;
          fpc_ansistr_incr_ref();
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9e6c;
          fpc_ansistr_decr_ref();
          iVar1 = U_JUKELINUX1_TOTALCDS;
          U_JUKELINUX1_RITMOESCOLHIDO = *(undefined4 *)(&DAT_092fffac + iVar2 * 4);
          U_JUKELINUX1_POSICAORITMO = 0;
          U_JUKELINUX1_KKRITMO = 1;
          if (0 < U_JUKELINUX1_TOTALCDS) {
            U_JUKELINUX1_KKRITMO = 0;
            do {
              U_JUKELINUX1_KKRITMO = U_JUKELINUX1_KKRITMO + 1;
              *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9eae;
              fpc_ansistr_decr_ref();
              local_34 = 0;
              *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9ece;
              fpc_shortstr_to_ansistr();
              *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9edc;
              iVar2 = fpc_ansistr_compare_equal();
              if ((iVar2 == 0) && (U_JUKELINUX1_POSICAORITMO == 0)) {
                U_JUKELINUX1_POSICAORITMO = U_JUKELINUX1_KKRITMO;
              }
            } while (U_JUKELINUX1_KKRITMO < iVar1);
          }
          if (U_JUKELINUX1_POSICAORITMO == 0) {
            U_JUKELINUX1_KMAT = 1;
          }
          else {
            U_JUKELINUX1_KMAT = U_JUKELINUX1_POSICAORITMO + -5;
          }
          U_JUKELINUX1_MUSICASELECIONADA = 0;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
          U_JUKELINUX1_MUSICASELECIONADATS = 0;
          U_JUKELINUX1_MOSTRANDORITMOS = '\0';
          U_JUKELINUX1_MOSTRANDOLETRAS = '\0';
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9f53;
          JUKELINUX1_MOSTRA_CDS_ANSISTRING();
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9f58;
          JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS();
        }
        *(undefined4 *)((int)ppuVar4 + -8) = 0x80a9f60;
        fpc_ansistr_decr_ref();
        local_34 = 0;
        *(undefined4 **)((int)ppuVar4 + -8) = &local_34;
        *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9f7f;
        fpc_ansistr_copy();
        *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9f8c;
        iVar1 = fpc_ansistr_compare_equal();
        ppuVar7 = (undefined4 **)((int)ppuVar4 + -8);
        if (iVar1 == 0) {
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9f99;
          JUKELINUX1_DESSELECIONAMUSICA();
          U_JUKELINUX1_MUSICASELECIONADA = 0;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
          U_JUKELINUX1_MUSICASELECIONADATS = 0;
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9fbc;
          JUKELINUX1_SELECIONAMUSICA();
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9fc4;
          fpc_ansistr_decr_ref();
          local_34 = 0;
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9fd8;
          SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9fe0;
          fpc_ansistr_incr_ref();
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80a9fea;
          fpc_ansistr_decr_ref();
          iVar1 = U_JUKELINUX1_TOTALMMLETRA;
          puVar6 = (undefined1 *)((int)ppuVar4 + -8);
          puVar5 = (undefined1 *)((int)ppuVar4 + -8);
          U_JUKELINUX1_LETRASELECIONADA = local_34;
          U_JUKELINUX1_NUMLETRASELECIONADA = 0;
          U_JUKELINUX1_KL = 1;
          if (0 < U_JUKELINUX1_TOTALMMLETRA) {
            U_JUKELINUX1_KL = 0;
            do {
              U_JUKELINUX1_KL = U_JUKELINUX1_KL + 1;
              *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa038;
              iVar2 = fpc_ansistr_compare_equal();
              if (iVar2 == 0) {
                U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_KL;
              }
            } while (U_JUKELINUX1_KL < iVar1);
          }
          U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + 1;
          if (U_JUKELINUX1_TOTALMMLETRA < U_JUKELINUX1_NUMLETRASELECIONADA) {
            U_JUKELINUX1_NUMLETRASELECIONADA = 1;
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x556) {
            *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa092;
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
            *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa0b9;
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x400) {
            *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa0e0;
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa0e8;
          fpc_ansistr_decr_ref();
          local_34 = 0;
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa103;
          SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa10b;
          fpc_ansistr_incr_ref();
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80aa115;
          fpc_ansistr_decr_ref();
          iVar1 = U_JUKELINUX1_TOTALCDS;
          U_JUKELINUX1_LETRAESCOLHIDA = local_34;
          U_JUKELINUX1_POSICAOLETRA = 0;
          U_JUKELINUX1_KKLETRA = 1;
          if (0 < U_JUKELINUX1_TOTALCDS) {
            U_JUKELINUX1_KKLETRA = 0;
            do {
              U_JUKELINUX1_KKLETRA = U_JUKELINUX1_KKLETRA + 1;
              *(undefined4 *)(puVar5 + -4) = 0x80aa15a;
              fpc_ansistr_decr_ref();
              local_34 = 0;
              *(undefined4 *)(puVar5 + -4) = 0x80aa169;
              fpc_ansistr_decr_ref();
              local_30[0] = 0;
              *(undefined4 **)(puVar5 + -4) = local_30;
              *(undefined4 *)(puVar5 + -8) = 0x80aa194;
              fpc_ansistr_copy();
              *(undefined4 *)(puVar5 + -8) = 0x80aa19f;
              SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
              *(undefined4 *)(puVar5 + -8) = 0x80aa1ad;
              iVar2 = fpc_ansistr_compare_equal();
              puVar6 = puVar5 + -4;
              puVar5 = puVar5 + -4;
              if ((iVar2 == 0) && (U_JUKELINUX1_POSICAOLETRA == 0)) {
                U_JUKELINUX1_POSICAOLETRA = U_JUKELINUX1_KKLETRA;
              }
            } while (U_JUKELINUX1_KKLETRA < iVar1);
          }
          if (U_JUKELINUX1_POSICAOLETRA == 0) {
            U_JUKELINUX1_KMAT = 1;
          }
          else {
            U_JUKELINUX1_KMAT = U_JUKELINUX1_POSICAOLETRA + -5;
          }
          U_JUKELINUX1_MUSICASELECIONADA = 0;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
          U_JUKELINUX1_MUSICASELECIONADATS = 0;
          U_JUKELINUX1_MOSTRANDORITMOS = '\0';
          U_JUKELINUX1_MOSTRANDOLETRAS = '\0';
          *(undefined4 *)(puVar6 + -4) = 0x80aa228;
          JUKELINUX1_MOSTRA_CDS_ANSISTRING();
          *(undefined4 *)(puVar6 + -4) = 0x80aa22d;
          JUKELINUX1_MOSTRA_NOME_DAS_MUSICAS();
          ppuVar7 = (undefined4 **)puVar6;
        }
      }
    }
    else {
      ppuVar7 = (undefined4 **)&iStack_16c;
      if (U_JUKELINUX1_SENHAOK == 1) {
        if ((U_JUKELINUX1_QTDCREDITOSGRATIS == 0) && (U_JUKELINUX1_QTDCREDITOSGRATISVIP == 0)) {
          puStack_170 = (undefined4 *)0x80aa267;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          ppuVar7 = (undefined4 **)&iStack_16c;
        }
        else {
          puStack_170 = (undefined4 *)0x80aa274;
          fpc_ansistr_decr_ref();
          local_34 = 0;
          puStack_170 = &local_34;
          puStack_174 = (undefined4 *)0x80aa287;
          fpc_ansistr_decr_ref();
          local_30[0] = 0;
          puStack_174 = (undefined4 *)0x80aa2a1;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          puStack_174 = (undefined4 *)0x80aa2b3;
          fpc_ansistr_copy();
          puStack_174 = (undefined4 *)0x80aa2c0;
          iVar1 = fpc_ansistr_compare_equal();
          ppuVar7 = &puStack_170;
          if (iVar1 == 0) {
            puStack_174 = (undefined4 *)0x80aa2e3;
            GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
            if ((0 < U_JUKELINUX1_QTDCREDITOSGRATIS) && (0 < U_JUKELINUX1_QTDCREDITOSGRATISVIP)) {
              puStack_174 = (undefined4 *)0x80aa305;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa31c;
              fpc_ansistr_decr_ref();
              local_34 = 0;
              puStack_174 = (undefined4 *)0x80aa330;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              puStack_174 = (undefined4 *)0x80aa346;
              fpc_ansistr_decr_ref();
              local_30[0] = 0;
              puStack_174 = (undefined4 *)0x80aa35a;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              puStack_174 = (undefined4 *)0x80aa378;
              fpc_ansistr_concat_multi();
              puStack_174 = (undefined4 *)0x80aa38b;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            }
            if ((0 < U_JUKELINUX1_QTDCREDITOSGRATIS) && (U_JUKELINUX1_QTDCREDITOSGRATISVIP == 0)) {
              puStack_174 = (undefined4 *)0x80aa3a5;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa3bc;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa3d0;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              puStack_174 = (undefined4 *)0x80aa3ee;
              fpc_ansistr_concat_multi();
              puStack_174 = (undefined4 *)0x80aa401;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            }
            if ((U_JUKELINUX1_QTDCREDITOSGRATIS == 0) && (0 < U_JUKELINUX1_QTDCREDITOSGRATISVIP)) {
              puStack_174 = (undefined4 *)0x80aa41b;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa432;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa446;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              puStack_174 = (undefined4 *)0x80aa464;
              fpc_ansistr_concat_multi();
              puStack_174 = (undefined4 *)0x80aa477;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            }
            U_JUKELINUX1_RELOGIOGRATIS = U_JUKELINUX1_RELOGIOGRATIS + U_JUKELINUX1_QTDCREDITOSGRATIS
            ;
            puStack_174 = (undefined4 *)0x80aa48a;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa49e;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa4a6;
            fpc_ansistr_incr_ref();
            puStack_174 = (undefined4 *)0x80aa4b0;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_RELOGIOGRATISSTR = 0;
            puStack_174 = (undefined4 *)0x80aa4c0;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa4da;
            fpc_ansistr_concat();
            puStack_174 = (undefined4 *)0x80aa4ed;
            FPC_ANSISTR_TO_SHORTSTR();
            puStack_174 = (undefined4 *)0x80aa4fd;
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            puStack_174 = (undefined4 *)0x80aa507;
            SYSTEM_REWRITE_TEXT();
            puStack_174 = (undefined4 *)0x80aa50c;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa514;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa528;
            JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa53a;
            fpc_write_text_ansistr();
            puStack_174 = (undefined4 *)0x80aa53f;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa549;
            fpc_writeln_end();
            puStack_174 = (undefined4 *)0x80aa54e;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa558;
            SYSTEM_FLUSH_TEXT();
            puStack_174 = (undefined4 *)0x80aa55d;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa567;
            OBJPAS_CLOSEFILE_TEXT();
            puStack_174 = (undefined4 *)0x80aa56c;
            fpc_iocheck();
            U_JUKELINUX1_RELOGIOGRATISVIP =
                 U_JUKELINUX1_RELOGIOGRATISVIP + U_JUKELINUX1_QTDCREDITOSGRATISVIP;
            puStack_174 = (undefined4 *)0x80aa57f;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa593;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa59b;
            fpc_ansistr_incr_ref();
            puStack_174 = (undefined4 *)0x80aa5a5;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_RELOGIOGRATISVIPSTR = 0;
            puStack_174 = (undefined4 *)0x80aa5b5;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa5cf;
            fpc_ansistr_concat();
            puStack_174 = (undefined4 *)0x80aa5e2;
            FPC_ANSISTR_TO_SHORTSTR();
            puStack_174 = (undefined4 *)0x80aa5f2;
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            puStack_174 = (undefined4 *)0x80aa5fc;
            SYSTEM_REWRITE_TEXT();
            puStack_174 = (undefined4 *)0x80aa601;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa609;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa61d;
            JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa62f;
            fpc_write_text_ansistr();
            puStack_174 = (undefined4 *)0x80aa634;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa63e;
            fpc_writeln_end();
            puStack_174 = (undefined4 *)0x80aa643;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa64d;
            SYSTEM_FLUSH_TEXT();
            puStack_174 = (undefined4 *)0x80aa652;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa65c;
            OBJPAS_CLOSEFILE_TEXT();
            puStack_174 = (undefined4 *)0x80aa661;
            fpc_iocheck();
            U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + U_JUKELINUX1_QTDCREDITOSGRATIS;
            puStack_174 = (undefined4 *)0x80aa681;
            fpc_ansistr_concat();
            puStack_174 = (undefined4 *)0x80aa697;
            FPC_ANSISTR_TO_SHORTSTR();
            puStack_174 = (undefined4 *)0x80aa6a7;
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            puStack_174 = (undefined4 *)0x80aa6b1;
            SYSTEM_REWRITE_TEXT();
            puStack_174 = (undefined4 *)0x80aa6b6;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa6be;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa6d0;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa6ea;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa6f8;
            JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa70a;
            fpc_write_text_ansistr();
            puStack_174 = (undefined4 *)0x80aa70f;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa719;
            fpc_writeln_end();
            puStack_174 = (undefined4 *)0x80aa71e;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa729;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa743;
            JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa758;
            fpc_write_text_ansistr();
            puStack_174 = (undefined4 *)0x80aa75d;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa767;
            fpc_writeln_end();
            puStack_174 = (undefined4 *)0x80aa76c;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa776;
            SYSTEM_FLUSH_TEXT();
            puStack_174 = (undefined4 *)0x80aa77b;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa785;
            OBJPAS_CLOSEFILE_TEXT();
            puStack_174 = (undefined4 *)0x80aa78a;
            fpc_iocheck();
            if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
              puStack_174 = (undefined4 *)0x80aa7a2;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa7b4;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa7ce;
              fpc_ansistr_concat();
              puStack_174 = (undefined4 *)0x80aa7e5;
              fpc_pchar_to_ansistr();
              puStack_174 = (undefined4 *)0x80aa7f6;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa80b;
              fpc_ansistr_decr_ref();
              puStack_174 = (undefined4 *)0x80aa82b;
              fpc_ansistr_concat();
              puStack_174 = (undefined4 *)0x80aa845;
              fpc_pchar_to_ansistr();
              puStack_174 = (undefined4 *)0x80aa854;
              FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
            }
            U_JUKELINUX1_CREDITOSVIP = U_JUKELINUX1_CREDITOSVIP + U_JUKELINUX1_QTDCREDITOSGRATISVIP;
            puStack_174 = (undefined4 *)0x80aa874;
            fpc_ansistr_concat();
            puStack_174 = (undefined4 *)0x80aa88a;
            FPC_ANSISTR_TO_SHORTSTR();
            puStack_174 = (undefined4 *)0x80aa89a;
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            puStack_174 = (undefined4 *)0x80aa8a4;
            SYSTEM_REWRITE_TEXT();
            puStack_174 = (undefined4 *)0x80aa8a9;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa8b4;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa8c9;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa8e3;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa8f4;
            JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa909;
            fpc_write_text_ansistr();
            puStack_174 = (undefined4 *)0x80aa90e;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa918;
            fpc_writeln_end();
            puStack_174 = (undefined4 *)0x80aa91d;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa928;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa942;
            JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa957;
            fpc_write_text_ansistr();
            puStack_174 = (undefined4 *)0x80aa95c;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa966;
            fpc_writeln_end();
            puStack_174 = (undefined4 *)0x80aa96b;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa975;
            SYSTEM_FLUSH_TEXT();
            puStack_174 = (undefined4 *)0x80aa97a;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa984;
            OBJPAS_CLOSEFILE_TEXT();
            puStack_174 = (undefined4 *)0x80aa989;
            fpc_iocheck();
            puStack_174 = (undefined4 *)0x80aa994;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa9ae;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aa9c4;
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            puStack_174 = (undefined4 *)0x80aa9cf;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aa9ec;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aaa06;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aaa22;
            fpc_ansistr_decr_ref();
            puStack_174 = (undefined4 *)0x80aaa3c;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
            puStack_174 = (undefined4 *)0x80aaa60;
            fpc_ansistr_concat_multi();
            puStack_174 = (undefined4 *)0x80aaa6b;
            JUKELINUX1_GRAVALOG_ANSISTRING();
            puStack_174 = (undefined4 *)0x80aaa8c;
            (**(code **)(*Form1.PanelUpgrade1 + 0xd8))();
            puStack_174 = (undefined4 *)0x80aaaad;
            (**(code **)(*Form1.PanelUpgrade1 + 0xd8))();
            ppuVar7 = &puStack_170;
            U_JUKELINUX1_JAGRAVOUNOPENDRIVE = 1;
          }
        }
      }
    }
  }
  ppuVar7[-1] = (undefined4 *)0x80aaabc;
  fpc_popaddrstack();
  ppuVar7[-1] = (undefined4 *)0x80aaac7;
  fpc_ansistr_decr_ref();
  ppuVar7[-1] = (undefined4 *)0x80aaadc;
  fpc_ansistr_decr_ref();
  ppuVar7[-1] = (undefined4 *)0x80aaaf1;
  fpc_ansistr_decr_ref();
  ppuVar7[-1] = (undefined4 *)0x80aab06;
  fpc_ansistr_decr_ref();
  ppuVar7[-1] = (undefined4 *)0x80aab1b;
  fpc_ansistr_decr_ref();
  ppuVar7[-1] = (undefined4 *)0x80aab2d;
  fpc_ansistr_decr_ref();
  ppuVar7[-1] = (undefined4 *)0x80aab3c;
  fpc_ansistr_decr_ref();
  ppuVar7[-1] = (undefined4 *)0x80aab4b;
  fpc_ansistr_decr_ref();
  local_34 = 0;
  ppuVar7[-1] = (undefined4 *)0x80aab5a;
  fpc_ansistr_decr_ref();
  local_30[0] = 0;
  if (*ppuVar7 != (undefined4 *)0x0) {
    *ppuVar7 = (undefined4 *)0x80aab6b;
    fpc_reraise();
  }
  return;
}

