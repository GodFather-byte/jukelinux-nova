// JUKELINUX1_MOSTRA_JPG_LETRA$ANSISTRING$$ANSISTRING  @ 08098a70

void JUKELINUX1_MOSTRA_JPG_LETRA_ANSISTRING__ANSISTRING(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  fpc_ansistr_incr_ref();
  fpc_pushexceptaddr();
  iVar3 = fpc_setjmp();
  if (iVar3 == 0) {
    fpc_ansistr_concat();
    iVar1 = U_JUKELINUX1_TOTALLJ;
    U_JUKELINUX1_KLJ = 1;
    if (0 < U_JUKELINUX1_TOTALLJ) {
      U_JUKELINUX1_KLJ = 0;
      do {
        U_JUKELINUX1_KLJ = U_JUKELINUX1_KLJ + 1;
        fpc_ansistr_decr_ref();
        SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 == 0) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat_multi();
          cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar2 != '\0') {
            fpc_ansistr_concat_multi();
          }
        }
      } while (U_JUKELINUX1_KLJ < iVar1);
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar3 != 0) {
    fpc_reraise();
  }
  return;
}

