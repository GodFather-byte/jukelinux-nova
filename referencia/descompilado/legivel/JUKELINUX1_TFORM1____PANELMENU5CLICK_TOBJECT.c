// JUKELINUX1_TFORM1_$__PANELMENU5CLICK$TOBJECT  @ 080e0800

void JUKELINUX1_TFORM1____PANELMENU5CLICK_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if ((iVar1 == 0) && (U_JUKELINUX1_SENHAOK == 2)) {
    JUKELINUX1_VOLTAMENU();
    CONTROLS_TCONTROL____HIDE();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SHOW();
    CONTROLS_TCONTROL____SHOW();
    CONTROLS_TCONTROL____SHOW();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_TRIMRIGHT_ANSISTRING__ANSISTRING(iVar1,0);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    (**(code **)(*Form1.ImgLanMais3 + 0x220))();
    (**(code **)(*Form1.Img50Menos2 + 0x220))();
    (**(code **)(*Form1.Img50Menos3 + 0x220))();
    (**(code **)(*Form1.Img50Menos4 + 0x220))();
    (**(code **)(*Form1.Img50Menos5 + 0x220))();
    (**(code **)(*Form1.Img50Mais1 + 0x220))();
    (**(code **)(*Form1.Img50Mais2 + 0x220))();
    (**(code **)(*Form1.Img50Mais3 + 0x220))();
    (**(code **)(*Form1.Img50Mais4 + 0x220))();
    (**(code **)(*Form1.Img50Menos1 + 0x220))();
    if (U_JUKELINUX1_MENUMASTER == '\0') {
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

