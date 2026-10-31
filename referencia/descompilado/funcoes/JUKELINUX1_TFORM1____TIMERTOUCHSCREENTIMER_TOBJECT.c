// JUKELINUX1_TFORM1_$__TIMERTOUCHSCREENTIMER$TOBJECT  @ 080e78a0

void JUKELINUX1_TFORM1____TIMERTOUCHSCREENTIMER_TOBJECT(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  fpc_pushexceptaddr(0,0);
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    if ((((4 < U_JUKELINUX1_P_INICIAL_X) && (U_JUKELINUX1_P_INICIAL_X < 0x489)) &&
        (0x234 < U_JUKELINUX1_P_INICIAL_Y)) && (U_JUKELINUX1_P_INICIAL_Y < 0x2f9)) {
      JUKELINUX1_LE_TOUCHSCREEN_FINAL();
      DEBUGSTART_JUKELINUX1();
      if ((0 < U_JUKELINUX1_P_DESLOCAMENTO_X) && (U_JUKELINUX1_P_DESLOCAMENTO_X < 100)) {
        JUKELINUX1_PRESSTECLA();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        (**(code **)(**(int **)(in_EAX + 0xbcc) + 0xd8))();
        U_JUKELINUX1_SEGURANDOTECLA = U_JUKELINUX1_SEGURANDOTECLA + 1;
      }
      if ((U_JUKELINUX1_P_DESLOCAMENTO_X < 0) && (U_JUKELINUX1_P_DESLOCAMENTO_X < -100)) {
        JUKELINUX1_PRESSTECLA();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        (**(code **)(**(int **)(in_EAX + 0xbd0) + 0xd8))();
        U_JUKELINUX1_SEGURANDOTECLA = U_JUKELINUX1_SEGURANDOTECLA + 1;
      }
    }
    if ((((0x1ad < U_JUKELINUX1_P_INICIAL_X) && (U_JUKELINUX1_P_INICIAL_X < 0x3cb)) &&
        (0xcc < U_JUKELINUX1_P_INICIAL_Y)) && (U_JUKELINUX1_P_INICIAL_Y < 0x231)) {
      JUKELINUX1_LE_TOUCHSCREEN_FINAL();
      DEBUGSTART_JUKELINUX1();
      if ((0 < U_JUKELINUX1_P_DESLOCAMENTO_Y) && (U_JUKELINUX1_P_DESLOCAMENTO_Y / 0x1b == 1)) {
        if (0xc < (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90]) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref(iVar2,uVar3,0);
          uVar3 = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
          fpc_ansistr_concat();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref(iVar2,uVar3,0);
          uVar3 = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
          fpc_ansistr_concat();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref(iVar2,uVar3,0);
          uVar3 = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
          fpc_ansistr_concat();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          if (0 < U_JUKELINUX1_MUSICASELECIONADATS) {
            U_JUKELINUX1_MUSICASELECIONADATS = U_JUKELINUX1_MUSICASELECIONADATS + -1;
            if (0xc < U_JUKELINUX1_MUSICASELECIONADA) {
              U_JUKELINUX1_MUSICASELECIONADA = U_JUKELINUX1_MUSICASELECIONADA + -0xb;
            }
            U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0;
            U_JUKELINUX1_MUSICASELECIONADA = U_JUKELINUX1_MUSICASELECIONADA + -1;
            JUKELINUX1_SELECIONAMUSICA();
            JUKELINUX1_DESSELECIONAMUSICA_TODAS();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref(iVar2,uVar3,0);
            uVar3 = 0;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
            fpc_ansistr_concat();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref(iVar2,uVar3,0);
            uVar3 = 0;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
            fpc_ansistr_concat();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref(iVar2,uVar3,0);
            uVar3 = 0;
            SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
            fpc_ansistr_concat();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          }
          if (U_JUKELINUX1_MUSICASELECIONADATS < 0) {
            U_JUKELINUX1_MUSICASELECIONADATS = 0;
          }
        }
        JUKELINUX1_LE_TOUCHSCREEN_INICIAL();
        DEBUGSTART_JUKELINUX1();
      }
      iVar1 = U_JUKELINUX1_MUSICASELECIONADATS;
      if ((U_JUKELINUX1_P_DESLOCAMENTO_Y < 0) && (U_JUKELINUX1_P_DESLOCAMENTO_Y / 0x1b == -1)) {
        if (0xc < (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90]) {
          U_JUKELINUX1_MUSICASELECIONADATS = U_JUKELINUX1_MUSICASELECIONADATS + 1;
          if (U_JUKELINUX1_MUSICASELECIONADA < 0xd) {
            U_JUKELINUX1_MUSICASELECIONADA = 0xd;
          }
          else {
            U_JUKELINUX1_MUSICASELECIONADA = U_JUKELINUX1_MUSICASELECIONADA + 1;
          }
          if ((int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90] <
              U_JUKELINUX1_MUSICASELECIONADA) {
            U_JUKELINUX1_MUSICASELECIONADA = U_JUKELINUX1_MUSICASELECIONADA + -1;
            U_JUKELINUX1_MUSICASELECIONADATS = iVar1;
          }
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0xc;
          JUKELINUX1_SELECIONAMUSICA();
          JUKELINUX1_DESSELECIONAMUSICA_TODAS();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref(iVar2,uVar3,0);
          uVar3 = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
          fpc_ansistr_concat();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref(iVar2,uVar3,0);
          uVar3 = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
          fpc_ansistr_concat();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref(iVar2,uVar3,0);
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
          fpc_ansistr_concat();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
        JUKELINUX1_LE_TOUCHSCREEN_INICIAL();
        DEBUGSTART_JUKELINUX1();
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar3 = 0;
  fpc_ansistr_decr_ref(iVar2,0);
  if (iVar2 != 0) {
    fpc_reraise(uVar3,0);
  }
  return;
}

