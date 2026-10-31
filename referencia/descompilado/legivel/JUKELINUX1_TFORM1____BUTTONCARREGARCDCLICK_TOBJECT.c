// JUKELINUX1_TFORM1_$__BUTTONCARREGARCDCLICK$TOBJECT  @ 080cd970

void JUKELINUX1_TFORM1____BUTTONCARREGARCDCLICK_TOBJECT(void)

{
  int *piVar1;
  longdouble lVar2;
  undefined8 local_1fbc;
  int iStack_1fb4;
  undefined4 local_1fb0;
  char *local_1fac;
  undefined4 local_1fa8;
  undefined *local_1fa4;
  undefined4 local_1fa0;
  int local_c;
  
  local_1fb0 = 0;
  local_1fa0 = 0;
  iStack_1fb4 = 0x80cd9a9;
  fpc_pushexceptaddr();
  iStack_1fb4 = 0x80cd9ae;
  iStack_1fb4 = fpc_setjmp();
  piVar1 = &iStack_1fb4;
  if (iStack_1fb4 == 0) {
    local_1fbc = (double)CONCAT44(0x80cd9ca,(undefined4)local_1fbc);
    CONTROLS_TCONTROL____SETLEFT_LONGINT();
    local_1fbc = (double)CONCAT44(0x80cd9dd,(undefined4)local_1fbc);
    CONTROLS_TCONTROL____SETTOP_LONGINT();
    local_1fbc = (double)CONCAT44(0x80cd9f0,(undefined4)local_1fbc);
    CONTROLS_TCONTROL____SETWIDTH_LONGINT();
    local_1fbc = (double)CONCAT44(0x80cda03,(undefined4)local_1fbc);
    CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
    local_1fbc = (double)CONCAT44(0x80cda11,(undefined4)local_1fbc);
    CONTROLS_TCONTROL____SHOW();
    local_1fbc = (double)CONCAT44(0x80cda1f,(undefined4)local_1fbc);
    CONTROLS_TCONTROL____BRINGTOFRONT();
    local_1fbc = (double)CONCAT44(0x80cda3b,(undefined4)local_1fbc);
    (**(code **)(**(int **)(local_c + 0x4f4) + 0x220))();
    local_1fbc = (double)CONCAT44(0x80cda4e,(undefined4)local_1fbc);
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    local_1fbc = (double)CONCAT44(0x80cda59,(undefined4)local_1fbc);
    fpc_ansistr_decr_ref();
    local_1fa0 = 0;
    local_1fac = __JUKELINUX1__Ld830;
    local_1fbc = (double)CONCAT44(0x80cda79,(undefined4)local_1fbc);
    fpc_ansistr_decr_ref();
    local_1fb0 = 0;
    local_1fbc = (double)CONCAT44(0x80cda88,(undefined4)local_1fbc);
    lVar2 = (longdouble)SYSUTILS_DATE__TDATETIME();
    local_1fbc = (double)lVar2;
    SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
    local_1fa8 = local_1fb0;
    local_1fa4 = &__JUKELINUX1__Ld831;
    fpc_ansistr_concat_multi();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____HIDE();
    CONTROLS_TCONTROL____HIDE();
    piVar1 = (int *)&local_1fbc;
  }
  piVar1[-1] = 0x80cdafb;
  fpc_popaddrstack();
  piVar1[-1] = 0x80cdb06;
  fpc_ansistr_decr_ref();
  local_1fb0 = 0;
  piVar1[-1] = 0x80cdb1b;
  fpc_ansistr_decr_ref();
  local_1fa0 = 0;
  if (*piVar1 != 0) {
    *piVar1 = 0x80cdb2f;
    fpc_reraise();
  }
  return;
}

