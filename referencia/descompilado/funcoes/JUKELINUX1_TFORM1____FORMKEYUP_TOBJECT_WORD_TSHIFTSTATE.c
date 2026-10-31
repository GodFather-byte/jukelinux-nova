// JUKELINUX1_TFORM1_$__FORMKEYUP$TOBJECT$WORD$TSHIFTSTATE  @ 080c57e0

void JUKELINUX1_TFORM1____FORMKEYUP_TOBJECT_WORD_TSHIFTSTATE(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  ushort *in_ECX;
  ushort **ppuVar3;
  ushort *puStack_214;
  ushort local_210 [256];
  int local_10;
  ushort *local_c;
  
  if (U_JUKELINUX1_ALTERANDOFRASES == '\0') {
    local_c = in_ECX;
    if (U_JUKELINUX1_LENDOCODIGODOCARTAO == 0) {
      local_10 = in_EAX;
      if (*in_ECX == U_JUKELINUX1_TECLACREDITOGRATISVIP) {
        puStack_214 = (ushort *)0x80c581f;
        JUKELINUX1_ROTINA_CREDITOSVIP();
      }
      if (*local_c == U_JUKELINUX1_TECLAMENU) {
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        puStack_214 = (ushort *)0x80c5843;
        JUKELINUX1_ROTINA_MENU();
      }
      if (*local_c == U_JUKELINUX1_TECLACRMAIS) {
        puStack_214 = (ushort *)0x80c5856;
        JUKELINUX1_DESTRAVAMENSAGEM();
      }
      if (*local_c == U_JUKELINUX1_TECLACRMENOS) {
        puStack_214 = (ushort *)0x80c5869;
        JUKELINUX1_DESTRAVAMENSAGEM();
      }
      if (*local_c == U_JUKELINUX1_TECLACANCELAR) {
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        puStack_214 = (ushort *)0x80c588d;
        JUKELINUX1_ROTINA_CANCELAR();
      }
      if (*local_c == U_JUKELINUX1_TECLATOCAR) {
        puStack_214 = (ushort *)0x80c58a0;
        JUKELINUX1_ROTINA_TOCAR();
        if (U_JUKELINUX1_VOLUMEATIVADO != '\0') {
          puStack_214 = (ushort *)0x80c58ae;
          JUKELINUX1_DESATIVA_VOLUME_PELO_PAINEL();
        }
      }
      if ((*local_c == U_JUKELINUX1_TECLACREDITO) || (*local_c == U_JUKELINUX1_TECLACREDITO2)) {
        puStack_214 = (ushort *)0x80c58cf;
        JUKELINUX1_PRESSTECLA();
        puStack_214 = (ushort *)0x80c58d9;
        JUKELINUX1_ROTINA_CREDITOS_ANSISTRING();
        if (U_JUKELINUX1_VOLUMEATIVADO != '\0') {
          puStack_214 = (ushort *)0x80c58e7;
          JUKELINUX1_DESATIVA_VOLUME_PELO_PAINEL();
        }
      }
      if (*local_c == U_JUKELINUX1_TECLARITMO) {
        puStack_214 = (ushort *)0x80c58fa;
        JUKELINUX1_PRESSTECLA();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        U_JUKELINUX1_RODAVOLUME = 0;
        puStack_214 = (ushort *)0x80c591f;
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_TECLAANTERIORRODAVOLUME = 0;
        puStack_214 = (ushort *)0x80c592e;
        JUKELINUX1_ROTINA_RITMOS();
        if (U_JUKELINUX1_VOLUMEATIVADO != '\0') {
          puStack_214 = (ushort *)0x80c593c;
          JUKELINUX1_DESATIVA_VOLUME_PELO_PAINEL();
        }
      }
      if (*local_c == U_JUKELINUX1_TECLACDMAIS) {
        puStack_214 = (ushort *)0x80c5953;
        JUKELINUX1_PRESSTECLA();
        if ((U_JUKELINUX1_MOSTRANDORITMOS == '\0') && (U_JUKELINUX1_MOSTRANDOLETRAS == '\0')) {
          U_JUKELINUX1_SEGURANDOTECLA = 0;
        }
        if (U_JUKELINUX1_MOSTRANDORITMOS != '\0') {
          puStack_214 = (ushort *)0x80c598b;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMRITMOSELECIONADO;
          U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + -1,
             U_JUKELINUX1_NUMRITMOSELECIONADO < 1)) {
            U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          }
          puStack_214 = (ushort *)0x80c59b4;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMRITMOSELECIONADO;
          U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + 1,
             U_JUKELINUX1_TOTALMMRITMO < U_JUKELINUX1_NUMRITMOSELECIONADO)) {
            U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          }
          puStack_214 = (ushort *)0x80c59d6;
          JUKELINUX1_MOSTRA_RITMOS();
          puStack_214 = (ushort *)0x80c59f2;
          (**(code **)(**(int **)(local_10 + 0xbb0) + 0xd8))();
          puStack_214 = (ushort *)0x80c5a0e;
          (**(code **)(**(int **)(local_10 + 0xbb0) + 0xd8))();
        }
        if (U_JUKELINUX1_MOSTRANDOLETRAS != '\0') {
          puStack_214 = (ushort *)0x80c5a2a;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMLETRASELECIONADA;
          U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + -1,
             U_JUKELINUX1_NUMLETRASELECIONADA < 1)) {
            U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          }
          puStack_214 = (ushort *)0x80c5a53;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMLETRASELECIONADA;
          U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + 1,
             U_JUKELINUX1_TOTALMMLETRA < U_JUKELINUX1_NUMLETRASELECIONADA)) {
            U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          }
          puStack_214 = (ushort *)0x80c5a75;
          JUKELINUX1_MOSTRA_LETRAS();
          puStack_214 = (ushort *)0x80c5a91;
          (**(code **)(**(int **)(local_10 + 0xbac) + 0xd8))();
          puStack_214 = (ushort *)0x80c5aad;
          (**(code **)(**(int **)(local_10 + 0xbac) + 0xd8))();
        }
      }
      if (*local_c == U_JUKELINUX1_TECLACDMENOS) {
        puStack_214 = (ushort *)0x80c5ac4;
        JUKELINUX1_PRESSTECLA();
        if ((U_JUKELINUX1_MOSTRANDORITMOS == '\0') && (U_JUKELINUX1_MOSTRANDOLETRAS == '\0')) {
          U_JUKELINUX1_SEGURANDOTECLA = 0;
        }
        if (U_JUKELINUX1_MOSTRANDORITMOS != '\0') {
          puStack_214 = (ushort *)0x80c5afc;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMRITMOSELECIONADO;
          U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + 1,
             U_JUKELINUX1_TOTALMMRITMO < U_JUKELINUX1_NUMRITMOSELECIONADO)) {
            U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          }
          puStack_214 = (ushort *)0x80c5b28;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMRITMOSELECIONADO;
          U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + -1,
             U_JUKELINUX1_NUMRITMOSELECIONADO < 1)) {
            U_JUKELINUX1_NUMRITMOSELECIONADO = iVar2;
          }
          puStack_214 = (ushort *)0x80c5b47;
          JUKELINUX1_MOSTRA_RITMOS();
          puStack_214 = (ushort *)0x80c5b63;
          (**(code **)(**(int **)(local_10 + 0xbb0) + 0xd8))();
          puStack_214 = (ushort *)0x80c5b7f;
          (**(code **)(**(int **)(local_10 + 0xbb0) + 0xd8))();
        }
        if (U_JUKELINUX1_MOSTRANDOLETRAS != '\0') {
          puStack_214 = (ushort *)0x80c5b9b;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMLETRASELECIONADA;
          U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + 1,
             U_JUKELINUX1_TOTALMMLETRA < U_JUKELINUX1_NUMLETRASELECIONADA)) {
            U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          }
          puStack_214 = (ushort *)0x80c5bc7;
          iVar1 = fpc_ansistr_compare_equal();
          iVar2 = U_JUKELINUX1_NUMLETRASELECIONADA;
          U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          if ((iVar1 == 0) &&
             (U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + -1,
             U_JUKELINUX1_NUMLETRASELECIONADA < 1)) {
            U_JUKELINUX1_NUMLETRASELECIONADA = iVar2;
          }
          puStack_214 = (ushort *)0x80c5be6;
          JUKELINUX1_MOSTRA_LETRAS();
          puStack_214 = (ushort *)0x80c5c02;
          (**(code **)(**(int **)(local_10 + 0xbac) + 0xd8))();
          puStack_214 = (ushort *)0x80c5c1e;
          (**(code **)(**(int **)(local_10 + 0xbac) + 0xd8))();
        }
      }
    }
    ppuVar3 = (ushort **)local_210;
    if (U_JUKELINUX1_LENDOCODIGODOCARTAO == 1) {
      local_210[0] = (ushort)(byte)*local_c << 8 | 1;
      puStack_214 = local_210;
      fpc_shortstr_concat();
      FPC_SHORTSTR_TO_SHORTSTR();
      ppuVar3 = &puStack_214;
    }
    if (U_JUKELINUX1_LENDOCODIGODOCARTAO == 0) {
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80c5c84;
      iVar2 = fpc_ansistr_compare_equal();
      if ((iVar2 != 0) && (*local_c == 0x30)) {
        U_JUKELINUX1_CODIGODOCARTAO = 1;
        DAT_09646eb1 = (byte)*local_c;
        U_JUKELINUX1_LENDOCODIGODOCARTAO = 1;
        *(undefined4 *)((int)ppuVar3 + -4) = 0x80c5cb3;
        JUKELINUX1_PRESSTECLA();
      }
    }
    if ((U_JUKELINUX1_LENDOCODIGODOCARTAO == 1) && (*local_c == 0xd)) {
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80c5cd7;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppuVar3 + -4) = 0x80c5ce0;
        JUKELINUX1_CARTAOCODBAR_BOATE();
      }
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80c5cef;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppuVar3 + -4) = 0x80c5cf8;
        JUKELINUX1_CARTAOCODBAR_BAR();
      }
    }
  }
  return;
}

