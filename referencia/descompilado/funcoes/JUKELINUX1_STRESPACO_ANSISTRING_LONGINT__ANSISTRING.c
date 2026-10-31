// JUKELINUX1_STRESPACO$ANSISTRING$LONGINT$$ANSISTRING  @ 08093f80

void JUKELINUX1_STRESPACO_ANSISTRING_LONGINT__ANSISTRING(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *in_ECX;
  int in_EDX;
  int local_14;
  
  fpc_ansistr_incr_ref();
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    iVar2 = 0;
    if (in_EAX != 0) {
      iVar2 = *(int *)(in_EAX + -4);
    }
    fpc_ansistr_decr_ref();
    if (0 < in_EDX - iVar2) {
      local_14 = 0;
      do {
        local_14 = local_14 + 1;
        fpc_ansistr_concat();
      } while (local_14 < in_EDX - iVar2);
    }
    fpc_ansistr_concat();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    *in_ECX = in_EAX;
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

