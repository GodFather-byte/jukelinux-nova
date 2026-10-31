// JUKELINUX1_MOSTRA_SETAS$LONGINT  @ 080a30f0

void JUKELINUX1_MOSTRA_SETAS_LONGINT(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  fpc_pushexceptaddr(0,0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    if ((int)(&U_JUKELINUX1_NOMEDOCLIENTE)[in_EAX * 0x90] < 0xd) {
      CONTROLS_TCONTROL____HIDE();
      U_JUKELINUX1_MOSTRANDOSETABAIXO = 0;
      (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbbc) + 0xd8))();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      U_JUKELINUX1_MOSTRANDOSETABAIXO = 1;
      (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbbc) + 0xd8))();
    }
    fpc_ansistr_decr_ref();
    fpc_shortstr_to_ansistr(iVar1,uVar3,0);
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    else {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
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

