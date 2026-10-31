// JUKELINUX1_TFORM1_$__BUTTONGRAVAROSDADOSCLICK$TOBJECT  @ 080d3780

/* WARNING: Removing unreachable block (ram,0x080d3af3) */
/* WARNING: Removing unreachable block (ram,0x080d3a4f) */
/* WARNING: Removing unreachable block (ram,0x080d39ab) */
/* WARNING: Removing unreachable block (ram,0x080d3907) */
/* WARNING: Removing unreachable block (ram,0x080d3825) */
/* WARNING: Removing unreachable block (ram,0x080d38b5) */
/* WARNING: Removing unreachable block (ram,0x080d3959) */
/* WARNING: Removing unreachable block (ram,0x080d39fd) */
/* WARNING: Removing unreachable block (ram,0x080d3aa1) */
/* WARNING: Removing unreachable block (ram,0x080d3b45) */
/* WARNING: Removing unreachable block (ram,0x080d3b12) */
/* WARNING: Removing unreachable block (ram,0x080d3b4c) */
/* WARNING: Removing unreachable block (ram,0x080d3ac0) */
/* WARNING: Removing unreachable block (ram,0x080d3afa) */
/* WARNING: Removing unreachable block (ram,0x080d3a6e) */
/* WARNING: Removing unreachable block (ram,0x080d3aa8) */
/* WARNING: Removing unreachable block (ram,0x080d3a1c) */
/* WARNING: Removing unreachable block (ram,0x080d3a56) */
/* WARNING: Removing unreachable block (ram,0x080d39ca) */
/* WARNING: Removing unreachable block (ram,0x080d3a04) */
/* WARNING: Removing unreachable block (ram,0x080d3978) */
/* WARNING: Removing unreachable block (ram,0x080d39b2) */
/* WARNING: Removing unreachable block (ram,0x080d3926) */
/* WARNING: Removing unreachable block (ram,0x080d3960) */
/* WARNING: Removing unreachable block (ram,0x080d38d4) */
/* WARNING: Removing unreachable block (ram,0x080d390e) */
/* WARNING: Removing unreachable block (ram,0x080d3882) */
/* WARNING: Removing unreachable block (ram,0x080d38bc) */
/* WARNING: Removing unreachable block (ram,0x080d3b68) */
/* WARNING: Removing unreachable block (ram,0x080d4456) */
/* WARNING: Removing unreachable block (ram,0x080d4459) */
/* WARNING: Removing unreachable block (ram,0x080d4465) */
/* WARNING: Removing unreachable block (ram,0x080d4468) */
/* WARNING: Removing unreachable block (ram,0x080d4486) */
/* WARNING: Removing unreachable block (ram,0x080d4912) */
/* WARNING: Removing unreachable block (ram,0x080d4957) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffa00 : 0x080d49f9 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void JUKELINUX1_TFORM1____BUTTONGRAVAROSDADOSCLICK_TOBJECT(void)

{
  int iVar1;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_decr_ref();
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    DIALOGS_SHOWMESSAGE_ANSISTRING();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
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

