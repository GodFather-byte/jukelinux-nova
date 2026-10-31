// JUKELINUX1_TFORM1_$__BUTTON1CLICK$TOBJECT  @ 080cca10

void JUKELINUX1_TFORM1____BUTTON1CLICK_TOBJECT(void)

{
  int iVar1;
  int local_10;
  
  fpc_pushexceptaddr(0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    U_JUKELINUX1_FOTOPNG = U_JUKELINUX1_FOTOPNG + 1;
    if (U_JUKELINUX1_FOTOPNG == 5) {
      U_JUKELINUX1_FOTOPNG = 1;
    }
    if (U_JUKELINUX1_FOTOPNG == 1) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar1,0);
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
    }
    if (U_JUKELINUX1_FOTOPNG == 2) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar1,0);
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
    }
    if (U_JUKELINUX1_FOTOPNG == 3) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar1,0);
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
    }
    if (U_JUKELINUX1_FOTOPNG == 4) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat(iVar1,0);
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
    }
    CONTROLS_TCONTROL____BRINGTOFRONT();
    CONTROLS_TCONTROL____SETTOP_LONGINT();
    CONTROLS_TCONTROL____SETWIDTH_LONGINT();
    CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
    CONTROLS_TCONTROL____SETLEFT_LONGINT();
    CONTROLS_TCONTROL____SHOW();
    local_10 = 0;
    do {
      local_10 = local_10 + 1;
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
    } while (local_10 < 0x88);
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise(0);
  }
  return;
}

