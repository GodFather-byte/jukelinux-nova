// JUKELINUX1_DESCRIPTABUF  @ 08094cf0

void JUKELINUX1_DESCRIPTABUF(void)

{
  int iVar1;
  char acStack_808 [2048];
  int local_8;
  
  local_8 = 0;
  do {
    iVar1 = local_8 + 1;
    acStack_808[local_8] =
         (U_JUKELINUX1_TIMER1BUF[local_8] - (char)iVar1) - (char)U_JUKELINUX1_CHAVECRIPTOGRAFICA;
    local_8 = iVar1;
  } while (iVar1 < 0x800);
  local_8 = 0;
  do {
    iVar1 = local_8 + 1;
    U_JUKELINUX1_TIMER1BUF[local_8] = acStack_808[local_8];
    local_8 = iVar1;
  } while (iVar1 < 0x800);
  return;
}

