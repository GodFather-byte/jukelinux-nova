// JUKELINUX1_MENSAGEMJPG$ANSISTRING$LONGINT$ANSISTRING  @ 08098be0

void JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
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
      U_JUKELINUX1_LIMPAMSG = '\x01';
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        U_JUKELINUX1_LIMPAMSG = '\0';
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        U_JUKELINUX1_LIMPAMSG = '\0';
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        U_JUKELINUX1_LIMPAMSG = '\0';
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        U_JUKELINUX1_LIMPAMSG = '\0';
      }
      if (in_EDX == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
      if (in_EDX == 1) {
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SHOW();
      }
      if (in_EDX == 2) {
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SHOW();
      }
      if (in_EDX == 3) {
        CONTROLS_TCONTROL____HIDE();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
        }
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        fpc_ansistr_decr_ref();
        JUKELINUX1_MOSTRA_JPG_RITMO_ANSISTRING__ANSISTRING(iVar2,0);
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____REFRESH();
        (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      }
      if (in_EDX == 4) {
        CONTROLS_TCONTROL____HIDE();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
        }
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        fpc_ansistr_decr_ref();
        JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING(iVar2,0);
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____REFRESH();
        (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      }
      if (in_EDX == 5) {
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          (**(code **)(**(int **)(U_JUKELINUX1_FORM1[0x265] + 0xe4) + 0xa4))();
        }
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SHOW();
      }
      if (U_JUKELINUX1_LIMPAMSG == '\0') {
        (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e8] + 0xdc))();
      }
      else {
        (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e8] + 0xdc))();
      }
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e8] + 0xd8))();
      (**(code **)(*(int *)U_JUKELINUX1_FORM1[0x2e8] + 0xd8))();
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

