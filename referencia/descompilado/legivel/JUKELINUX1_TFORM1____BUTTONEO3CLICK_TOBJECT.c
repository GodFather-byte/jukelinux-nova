// JUKELINUX1_TFORM1_$__BUTTONEO3CLICK$TOBJECT  @ 080ce4c0

void JUKELINUX1_TFORM1____BUTTONEO3CLICK_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 **ppuVar4;
  int aiStack_58 [2];
  undefined4 *puStack_50;
  undefined4 *puStack_4c;
  undefined4 *puStack_48;
  int iStack_44;
  undefined4 local_3c;
  undefined4 local_38 [13];
  
  local_3c = 0;
  local_38[0] = 0;
  iStack_44 = 0x80ce4ed;
  fpc_pushexceptaddr();
  iStack_44 = 0x80ce4f2;
  iStack_44 = fpc_setjmp();
  ppuVar4 = (undefined4 **)&iStack_44;
  if (iStack_44 == 0) {
    puStack_48 = (undefined4 *)0x80ce503;
    fpc_ansistr_decr_ref();
    local_38[0] = 0;
    puStack_48 = local_38;
    puStack_4c = (undefined4 *)0x80ce522;
    fpc_ansistr_copy();
    puStack_4c = (undefined4 *)0x80ce52f;
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      puStack_4c = (undefined4 *)0x80ce53f;
      fpc_ansistr_decr_ref();
      local_38[0] = 0;
      puStack_4c = (undefined4 *)0x80ce55f;
      fpc_shortstr_to_ansistr();
      puStack_4c = (undefined4 *)0x80ce567;
      fpc_ansistr_incr_ref();
      puStack_4c = (undefined4 *)0x80ce571;
      fpc_ansistr_decr_ref();
      iVar1 = U_JUKELINUX1_TOTALMMRITMO;
      U_JUKELINUX1_RITMOSELECIONADO = local_38[0];
      U_JUKELINUX1_NUMRITMOSELECIONADO = 0;
      U_JUKELINUX1_KR = 1;
      if (0 < U_JUKELINUX1_TOTALMMRITMO) {
        U_JUKELINUX1_KR = 0;
        do {
          U_JUKELINUX1_KR = U_JUKELINUX1_KR + 1;
          puStack_4c = (undefined4 *)0x80ce5c0;
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
      iVar2 = U_JUKELINUX1_NUMRITMOSELECIONADO;
      puStack_4c = (undefined4 *)0x80ce605;
      fpc_ansistr_incr_ref();
      puStack_4c = (undefined4 *)0x80ce60f;
      fpc_ansistr_decr_ref();
      iVar1 = U_JUKELINUX1_TOTALCDS;
      U_JUKELINUX1_RITMOESCOLHIDO = *(undefined4 *)(&DAT_092fffac + iVar2 * 4);
      U_JUKELINUX1_POSICAORITMO = 0;
      U_JUKELINUX1_KKRITMO = 1;
      if (0 < U_JUKELINUX1_TOTALCDS) {
        U_JUKELINUX1_KKRITMO = 0;
        do {
          U_JUKELINUX1_KKRITMO = U_JUKELINUX1_KKRITMO + 1;
          puStack_4c = (undefined4 *)0x80ce652;
          fpc_ansistr_decr_ref();
          local_38[0] = 0;
          puStack_4c = (undefined4 *)0x80ce672;
          fpc_shortstr_to_ansistr();
          puStack_4c = (undefined4 *)0x80ce680;
          iVar2 = fpc_ansistr_compare_equal();
          if ((iVar2 == 0) && (U_JUKELINUX1_POSICAORITMO == 0)) {
            U_JUKELINUX1_POSICAORITMO = U_JUKELINUX1_KKRITMO;
          }
        } while (U_JUKELINUX1_KKRITMO < iVar1);
      }
      if (U_JUKELINUX1_POSICAORITMO == 0) {
        U_JUKELINUX1_KMATEXCLUI = 1;
      }
      else {
        U_JUKELINUX1_KMATEXCLUI = U_JUKELINUX1_POSICAORITMO;
      }
      puStack_4c = (undefined4 *)0x80ce6c8;
      JUKELINUX1_MOSTRA_CD_EXCLUSAO_LONGINT();
    }
    puStack_4c = (undefined4 *)0x80ce6d0;
    fpc_ansistr_decr_ref();
    local_38[0] = 0;
    puStack_4c = local_38;
    puStack_50 = (undefined4 *)0x80ce6ef;
    fpc_ansistr_copy();
    puStack_50 = (undefined4 *)0x80ce6fc;
    iVar1 = fpc_ansistr_compare_equal();
    ppuVar4 = &puStack_4c;
    if (iVar1 == 0) {
      puStack_50 = (undefined4 *)0x80ce70c;
      fpc_ansistr_decr_ref();
      local_38[0] = 0;
      puStack_50 = (undefined4 *)0x80ce71b;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      puStack_50 = &local_3c;
      fpc_ansistr_copy();
      SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      iVar1 = U_JUKELINUX1_TOTALMMLETRA;
      ppuVar4 = &puStack_50;
      ppuVar3 = &puStack_50;
      U_JUKELINUX1_LETRASELECIONADA = local_38[0];
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
      U_JUKELINUX1_NUMLETRASELECIONADA = U_JUKELINUX1_NUMLETRASELECIONADA + 1;
      if (U_JUKELINUX1_TOTALMMLETRA < U_JUKELINUX1_NUMLETRASELECIONADA) {
        U_JUKELINUX1_NUMLETRASELECIONADA = 1;
      }
      fpc_ansistr_decr_ref();
      local_3c = 0;
      SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      iVar1 = U_JUKELINUX1_TOTALCDS;
      U_JUKELINUX1_LETRAESCOLHIDA = local_3c;
      U_JUKELINUX1_POSICAOLETRA = 0;
      U_JUKELINUX1_KKLETRA = 1;
      if (0 < U_JUKELINUX1_TOTALCDS) {
        U_JUKELINUX1_KKLETRA = 0;
        do {
          U_JUKELINUX1_KKLETRA = U_JUKELINUX1_KKLETRA + 1;
          *(undefined4 *)((int)ppuVar3 + -4) = 0x80ce85a;
          fpc_ansistr_decr_ref();
          local_3c = 0;
          *(undefined4 *)((int)ppuVar3 + -4) = 0x80ce869;
          fpc_ansistr_decr_ref();
          local_38[0] = 0;
          *(undefined4 **)((int)ppuVar3 + -4) = local_38;
          *(undefined4 *)((int)ppuVar3 + -8) = 0x80ce894;
          fpc_ansistr_copy();
          *(undefined4 *)((int)ppuVar3 + -8) = 0x80ce89f;
          SYSUTILS_LOWERCASE_ANSISTRING__ANSISTRING();
          *(undefined4 *)((int)ppuVar3 + -8) = 0x80ce8ad;
          iVar2 = fpc_ansistr_compare_equal();
          ppuVar4 = (undefined4 **)((int)ppuVar3 + -4);
          ppuVar3 = (undefined4 **)((int)ppuVar3 + -4);
          if ((iVar2 == 0) && (U_JUKELINUX1_POSICAOLETRA == 0)) {
            U_JUKELINUX1_POSICAOLETRA = U_JUKELINUX1_KKLETRA;
          }
        } while (U_JUKELINUX1_KKLETRA < iVar1);
      }
      if (U_JUKELINUX1_POSICAOLETRA == 0) {
        U_JUKELINUX1_KMATEXCLUI = 1;
      }
      else {
        U_JUKELINUX1_KMATEXCLUI = U_JUKELINUX1_POSICAOLETRA;
      }
      *(undefined4 *)((int)ppuVar4 + -4) = 0x80ce8f9;
      JUKELINUX1_MOSTRA_CD_EXCLUSAO_LONGINT();
    }
  }
  ppuVar4[-1] = (undefined4 *)0x80ce8fe;
  fpc_popaddrstack();
  ppuVar4[-1] = (undefined4 *)0x80ce906;
  fpc_ansistr_decr_ref();
  local_3c = 0;
  ppuVar4[-1] = (undefined4 *)0x80ce915;
  fpc_ansistr_decr_ref();
  local_38[0] = 0;
  if (*ppuVar4 != (undefined4 *)0x0) {
    *ppuVar4 = (undefined4 *)0x80ce926;
    fpc_reraise();
  }
  return;
}

