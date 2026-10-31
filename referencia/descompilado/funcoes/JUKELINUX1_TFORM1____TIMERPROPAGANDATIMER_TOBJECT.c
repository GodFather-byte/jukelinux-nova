// JUKELINUX1_TFORM1_$__TIMERPROPAGANDATIMER$TOBJECT  @ 080e4fd0

void JUKELINUX1_TFORM1____TIMERPROPAGANDATIMER_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  
  iVar2 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
  if (iVar2 < 1) {
    (**(code **)(**(int **)(in_EAX + 0xba8) + 0xdc))();
    U_JUKELINUX1_POSPRO = U_JUKELINUX1_POSPRO + 1;
    if (U_JUKELINUX1_TOTALPRO < U_JUKELINUX1_POSPRO) {
      U_JUKELINUX1_POSPRO = 1;
    }
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 != '\0') {
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
    }
  }
  else {
    iVar2 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
    if (iVar2 == 0) {
      if (U_JUKELINUX1_TOCANDOVIDEOTV == '\0') {
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
        CONTROLS_TCONTROL____SHOW();
        (**(code **)(**(int **)(in_EAX + 0xa0c) + 0x2fc))();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        (**(code **)(**(int **)(in_EAX + 0xba8) + 0xdc))();
        U_JUKELINUX1_POSPRO = U_JUKELINUX1_POSPRO + 1;
        if (U_JUKELINUX1_TOTALPRO < U_JUKELINUX1_POSPRO) {
          U_JUKELINUX1_POSPRO = 1;
        }
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING();
          MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY();
          MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
          MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
          U_JUKELINUX1_TOCANDOVIDEOTV = '\x01';
          (**(code **)(**(int **)(in_EAX + 0xb6c) + 0xd8))();
          (**(code **)(**(int **)(in_EAX + 0xba8) + 0xd8))();
        }
      }
    }
    else if (U_JUKELINUX1_TOCANDOMUSICA == '\0') {
      (**(code **)(**(int **)(in_EAX + 0xb6c) + 0xd8))();
      MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
      CONTROLS_TCONTROL____HIDE();
      U_JUKELINUX1_TOCANDOVIDEOTV = '\0';
    }
    else if ((U_JUKELINUX1_TOCANDOMUSICADVD == '\0') && (U_JUKELINUX1_TOCANDOVIDEOTV == '\0')) {
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SETWIDTH_LONGINT();
      CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(**(int **)(in_EAX + 0xa0c) + 0x2fc))();
      CONTROLS_TCONTROL____BRINGTOFRONT();
      (**(code **)(**(int **)(in_EAX + 0xba8) + 0xdc))();
      U_JUKELINUX1_POSPRO = U_JUKELINUX1_POSPRO + 1;
      if (U_JUKELINUX1_TOTALPRO < U_JUKELINUX1_POSPRO) {
        U_JUKELINUX1_POSPRO = 1;
      }
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETFILENAME_ANSISTRING();
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAY();
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
        U_JUKELINUX1_TOCANDOVIDEOTV = '\x01';
        (**(code **)(**(int **)(in_EAX + 0xb6c) + 0xd8))();
        (**(code **)(**(int **)(in_EAX + 0xba8) + 0xd8))();
      }
    }
  }
  return;
}

