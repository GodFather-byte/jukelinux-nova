// JUKELINUX1_DESCRIPTASUPER$ANSISTRING$$ANSISTRING  @ 08094240

void JUKELINUX1_DESCRIPTASUPER_ANSISTRING__ANSISTRING(void)

{
  undefined4 *in_EDX;
  int iVar1;
  int **ppiVar2;
  int *piStack_4c;
  int iStack_48;
  int local_40 [11];
  undefined4 local_14;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  iStack_48 = 0x8094257;
  local_c = in_EDX;
  fpc_ansistr_incr_ref();
  local_14 = 0;
  local_40[0] = 0;
  iStack_48 = 0x8094275;
  fpc_pushexceptaddr();
  iStack_48 = 0x809427a;
  iStack_48 = fpc_setjmp();
  ppiVar2 = (int **)&iStack_48;
  if (iStack_48 == 0) {
    piStack_4c = (int *)0x809428b;
    fpc_ansistr_decr_ref();
    local_40[0] = 0;
    piStack_4c = local_40;
    fpc_ansistr_copy();
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    local_8 = local_40[0];
    fpc_ansistr_decr_ref();
    ppiVar2 = &piStack_4c;
    local_14 = 0;
    iVar1 = 0;
    if (local_8 != 0) {
      iVar1 = *(int *)(local_8 + -4);
    }
    local_10 = 1;
    if (0 < iVar1) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        fpc_ansistr_decr_ref();
        local_40[0] = 0;
        fpc_char_to_ansistr();
        fpc_ansistr_concat();
      } while (local_10 < iVar1);
    }
    fpc_ansistr_incr_ref();
    fpc_ansistr_decr_ref();
    *local_c = local_14;
  }
  ppiVar2[-1] = (int *)0x8094348;
  fpc_popaddrstack();
  ppiVar2[-1] = (int *)0x8094350;
  fpc_ansistr_decr_ref();
  local_40[0] = 0;
  ppiVar2[-1] = (int *)0x809435f;
  fpc_ansistr_decr_ref();
  local_14 = 0;
  ppiVar2[-1] = (int *)0x809436e;
  fpc_ansistr_decr_ref();
  if (*ppiVar2 != (int *)0x0) {
    *ppiVar2 = (int *)0x8094378;
    fpc_reraise();
  }
  return;
}

