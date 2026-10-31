// JUKELINUX1_CRIPTASUPER$ANSISTRING$$ANSISTRING  @ 08094070

/* WARNING: Removing unreachable block (ram,0x08094117) */
/* WARNING: Removing unreachable block (ram,0x08094126) */
/* WARNING: Removing unreachable block (ram,0x0809412c) */

void JUKELINUX1_CRIPTASUPER_ANSISTRING__ANSISTRING(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int local_14;
  
  fpc_ansistr_incr_ref();
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    SYSTEM_RANDOMIZE();
    SYSTEM_RANDOM_LONGINT__LONGINT();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_decr_ref();
    JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    fpc_ansistr_decr_ref();
    iVar2 = 0;
    if (in_EAX != 0) {
      iVar2 = *(int *)(in_EAX + -4);
    }
    if (0 < iVar2) {
      local_14 = 0;
      do {
        local_14 = local_14 + 1;
        fpc_ansistr_decr_ref();
        fpc_char_to_ansistr();
        fpc_ansistr_concat();
      } while (local_14 < iVar2);
    }
    fpc_ansistr_concat();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

