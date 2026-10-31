// JUKELINUX1_TFORM1_$__EDITMUSICAMENOSKEYDOWN$TOBJECT$WORD$TSHIFTSTATE  @ 080de910

void JUKELINUX1_TFORM1____EDITMUSICAMENOSKEYDOWN_TOBJECT_WORD_TSHIFTSTATE(void)

{
  int in_EAX;
  int iVar1;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_TEMPTECLA = 0;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_FUNCAOTECLA = __JUKELINUX1__Ld971;
    (**(code **)(**(int **)(in_EAX + 0xb78) + 0xd8))();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

