// JUKELINUX1_DESCRIPTASIMPLES$ANSISTRING$$ANSISTRING  @ 08094980

void JUKELINUX1_DESCRIPTASIMPLES_ANSISTRING__ANSISTRING(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *in_EDX;
  int iVar2;
  int local_10;
  
  fpc_ansistr_incr_ref();
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_decr_ref();
    iVar2 = 0;
    if (in_EAX != 0) {
      iVar2 = *(int *)(in_EAX + -4);
    }
    if (0 < iVar2) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        fpc_ansistr_decr_ref();
        fpc_char_to_ansistr();
        fpc_ansistr_concat();
      } while (local_10 < iVar2);
    }
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    *in_EDX = 0;
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

