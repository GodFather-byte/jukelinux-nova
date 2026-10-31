// JUKELINUX1_MENSAGEMTRAVADAJPG$ANSISTRING$LONGINT$ANSISTRING  @ 08099830

void JUKELINUX1_MENSAGEMTRAVADAJPG_ANSISTRING_LONGINT_ANSISTRING(void)

{
  char cVar1;
  int iVar2;
  int in_EDX;
  
  fpc_ansistr_incr_ref();
  fpc_ansistr_incr_ref();
  fpc_pushexceptaddr(0);
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat(iVar2,0);
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 != '\0') {
      if (0 < U_JUKELINUX1_MOSTRANDOSETABAIXO) {
        CONTROLS_TCONTROL____HIDE();
        U_JUKELINUX1_MOSTRANDOSETABAIXO = -1;
      }
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar2,0);
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SETWIDTH_LONGINT();
      CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
      CONTROLS_TCONTROL____SHOW();
      if (in_EDX == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
      if (in_EDX == 3) {
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          (**(code **)(**(int **)(*(int *)(U_JUKELINUX1_FORM1 + 0x994) + 0xe4) + 0xa4))();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          (**(code **)(**(int **)(*(int *)(U_JUKELINUX1_FORM1 + 0x994) + 0xe4) + 0xa4))();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          (**(code **)(**(int **)(*(int *)(U_JUKELINUX1_FORM1 + 0x994) + 0xe4) + 0xa4))();
        }
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SHOW();
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref(iVar2,0);
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

