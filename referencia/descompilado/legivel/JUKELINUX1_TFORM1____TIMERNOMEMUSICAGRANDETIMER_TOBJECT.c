// JUKELINUX1_TFORM1_$__TIMERNOMEMUSICAGRANDETIMER$TOBJECT  @ 080e2130

void JUKELINUX1_TFORM1____TIMERNOMEMUSICAGRANDETIMER_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  fpc_pushexceptaddr(0,0);
  iVar1 = fpc_setjmp();
  if ((iVar1 == 0) && (0 < U_JUKELINUX1_MUSICASELECIONADA)) {
    switch(U_JUKELINUX1_MUSICASELECIONADAPOSTELA) {
    case 1:
      iVar2 = 0;
      if (U_JUKELINUX1_NOMEMUSICAORIGINALGRANDE != 0) {
        iVar2 = *(int *)(U_JUKELINUX1_NOMEMUSICAORIGINALGRANDE + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 2:
      iVar2 = 0;
      if (DAT_09301dc4 != 0) {
        iVar2 = *(int *)(DAT_09301dc4 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 3:
      iVar2 = 0;
      if (DAT_09301dc8 != 0) {
        iVar2 = *(int *)(DAT_09301dc8 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 4:
      iVar2 = 0;
      if (DAT_09301dcc != 0) {
        iVar2 = *(int *)(DAT_09301dcc + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 5:
      iVar2 = 0;
      if (DAT_09301dd0 != 0) {
        iVar2 = *(int *)(DAT_09301dd0 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 6:
      iVar2 = 0;
      if (DAT_09301dd4 != 0) {
        iVar2 = *(int *)(DAT_09301dd4 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 7:
      iVar2 = 0;
      if (DAT_09301dd8 != 0) {
        iVar2 = *(int *)(DAT_09301dd8 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 8:
      iVar2 = 0;
      if (DAT_09301ddc != 0) {
        iVar2 = *(int *)(DAT_09301ddc + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 9:
      iVar2 = 0;
      if (DAT_09301de0 != 0) {
        iVar2 = *(int *)(DAT_09301de0 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 10:
      iVar2 = 0;
      if (DAT_09301de4 != 0) {
        iVar2 = *(int *)(DAT_09301de4 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 0xb:
      iVar2 = 0;
      if (DAT_09301de8 != 0) {
        iVar2 = *(int *)(DAT_09301de8 + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xb) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
      break;
    case 0xc:
      iVar2 = 0;
      if (DAT_09301dec != 0) {
        iVar2 = *(int *)(DAT_09301dec + -4);
      }
      if (U_JUKELINUX1_TAMANHOMUSICAGRANDE < iVar2) {
        fpc_ansistr_decr_ref();
        iVar4 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = *(int *)(iVar4 + -4);
        }
        if (iVar2 < 0xd) {
          if (U_JUKELINUX1_ALTEROUMUSICAGRANDE != '\0') {
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
            U_JUKELINUX1_SOMAMUSICAGRANDE = 0;
          }
        }
        else {
          fpc_ansistr_decr_ref();
          uVar3 = 0;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          fpc_ansistr_incr_ref();
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_TEXTOMUSICAGRANDE = uVar3;
          SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          U_JUKELINUX1_SOMAMUSICAGRANDE = U_JUKELINUX1_SOMAMUSICAGRANDE + 1;
          U_JUKELINUX1_ALTEROUMUSICAGRANDE = '\x01';
          (**(code **)(*Form1.LabelSairDoMenu2 + 0xdc))();
        }
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar3 = 0;
  fpc_ansistr_decr_ref(iVar1,0);
  if (iVar1 != 0) {
    fpc_reraise(uVar3,0);
  }
  return;
}

