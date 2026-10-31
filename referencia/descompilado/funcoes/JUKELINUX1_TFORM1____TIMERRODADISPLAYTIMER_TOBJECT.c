// JUKELINUX1_TFORM1_$__TIMERRODADISPLAYTIMER$TOBJECT  @ 080e54c0

void JUKELINUX1_TFORM1____TIMERRODADISPLAYTIMER_TOBJECT(void)

{
  int iVar1;
  undefined1 ***pppuVar2;
  undefined1 **ppuStack_40;
  int iStack_3c;
  undefined1 *local_38 [11];
  int local_c;
  
  local_38[0] = (undefined1 *)0x0;
  iStack_3c = 0x80e54e3;
  fpc_pushexceptaddr();
  iStack_3c = 0x80e54e8;
  iStack_3c = fpc_setjmp();
  pppuVar2 = (undefined1 ***)&iStack_3c;
  if (iStack_3c == 0) {
    ppuStack_40 = (undefined1 **)0x80e54f9;
    fpc_ansistr_decr_ref();
    local_38[0] = (undefined1 *)0x0;
    ppuStack_40 = (undefined1 **)0x80e5511;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    ppuStack_40 = (undefined1 **)0x80e5519;
    fpc_ansistr_incr_ref();
    ppuStack_40 = (undefined1 **)0x80e5523;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_TEXTOX = local_38[0];
    U_JUKELINUX1_TEXTOTEMPX._1_1_ = *local_38[0];
    ppuStack_40 = (undefined1 **)0x80e5546;
    SYSTEM_DELETE_ANSISTRING_LONGINT_LONGINT();
    ppuStack_40 = (undefined1 **)0x80e554e;
    fpc_ansistr_decr_ref();
    local_38[0] = (undefined1 *)0x0;
    ppuStack_40 = (undefined1 **)0x80e5562;
    fpc_char_to_ansistr();
    ppuStack_40 = (undefined1 **)0x80e557d;
    SYSTEM_INSERT_ANSISTRING_ANSISTRING_LONGINT();
    ppuStack_40 = (undefined1 **)0x80e5591;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    ppuStack_40 = (undefined1 **)0x80e5599;
    fpc_ansistr_decr_ref();
    local_38[0] = (undefined1 *)0x0;
    ppuStack_40 = local_38;
    fpc_ansistr_copy();
    iVar1 = fpc_ansistr_compare_equal();
    pppuVar2 = &ppuStack_40;
    if (iVar1 == 0) {
      (**(code **)(**(int **)(local_c + 0xb9c) + 0xd8))();
      (**(code **)(**(int **)(local_c + 0xb98) + 0xd8))();
      pppuVar2 = &ppuStack_40;
    }
  }
  pppuVar2[-1] = (undefined1 **)0x80e5606;
  fpc_popaddrstack();
  pppuVar2[-1] = (undefined1 **)0x80e560e;
  fpc_ansistr_decr_ref();
  local_38[0] = (undefined1 *)0x0;
  if (*pppuVar2 != (undefined1 **)0x0) {
    *pppuVar2 = (undefined1 **)0x80e561f;
    fpc_reraise();
  }
  return;
}

