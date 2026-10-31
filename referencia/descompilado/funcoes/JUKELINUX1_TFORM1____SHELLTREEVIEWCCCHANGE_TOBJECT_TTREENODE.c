// JUKELINUX1_TFORM1_$__SHELLTREEVIEWCCCHANGE$TOBJECT$TTREENODE  @ 080e0c20

void JUKELINUX1_TFORM1____SHELLTREEVIEWCCCHANGE_TOBJECT_TTREENODE(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fpc_pushexceptaddr(0,0);
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_decr_ref(iVar1,uVar2,0);
    SHELLCTRLS_TCUSTOMSHELLTREEVIEW____GETPATH__ANSISTRING(iVar1,0);
    fpc_ansistr_concat();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar2 = 0;
  fpc_ansistr_decr_ref(iVar1,0);
  if (iVar1 != 0) {
    fpc_reraise(uVar2,0);
  }
  return;
}

