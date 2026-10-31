// JUKELINUX1_SELECIONAMUSICA  @ 080a3280

void JUKELINUX1_SELECIONAMUSICA(void)

{
  int iVar1;
  undefined4 uVar2;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
      U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
      switch(U_JUKELINUX1_MUSICASELECIONADAANT) {
      case 1:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 2:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 3:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 4:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 5:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 6:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 7:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 8:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 9:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 10:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 0xb:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        break;
      case 0xc:
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
    }
    switch(U_JUKELINUX1_MUSICASELECIONADAPOSTELA) {
    case 0:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 1:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 2:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 3:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 4:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 5:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 6:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 7:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 8:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 9:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 10:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 0xb:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      break;
    case 0xc:
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
    }
    if ((U_JUKELINUX1_MUSICASELECIONADAPOSTELA == 0xc) && (0xc < U_JUKELINUX1_MUSICASELECIONADA)) {
      U_JUKELINUX1_POSTELAFAIXA = U_JUKELINUX1_MUSICASELECIONADA + -0xc;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    if ((U_JUKELINUX1_MUSICASELECIONADAPOSTELA == 0) && (0 < U_JUKELINUX1_MUSICASELECIONADA)) {
      U_JUKELINUX1_POSTELAFAIXA = U_JUKELINUX1_POSTELAFAIXA + -1;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      if (U_JUKELINUX1_MUSICASELECIONADAPOSTELA == 0) {
        U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 1;
      }
    }
    if (U_JUKELINUX1_MUSICASELECIONADA == 0) {
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
    }
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_NOMEMUSICAORIGINALGRANDE = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301dc4 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301dc8 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301dcc = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301dd0 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301dd4 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301dd8 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301ddc = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301de0 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301de4 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301de8 = uVar2;
    fpc_ansistr_decr_ref();
    uVar2 = 0;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    DAT_09301dec = uVar2;
    (**(code **)(*Form1.LabelSairDoMenu2 + 0xd8))();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

