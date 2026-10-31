// JUKELINUX1_TFORM1_$__COMBOBOX7CHANGE$TOBJECT  @ 080dbe00

void JUKELINUX1_TFORM1____COMBOBOX7CHANGE_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  undefined4 **ppuVar3;
  int *piVar4;
  undefined4 *puStack_25c;
  int iStack_258;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  char *local_48;
  undefined4 local_44;
  undefined *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_c;
  
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_3c = 0;
  local_38 = 0;
  iStack_258 = 0x80dbe5d;
  fpc_pushexceptaddr();
  iStack_258 = 0x80dbe62;
  iStack_258 = fpc_setjmp();
  piVar4 = &iStack_258;
  if (iStack_258 == 0) {
    U_JUKELINUX1_OKC = 0;
    puStack_25c = (undefined4 *)0x80dbe9b;
    iVar1 = (**(code **)(**(int **)(*(int *)(local_c + 0x6e8) + 0x36c) + 0x80))();
    ppuVar3 = (undefined4 **)&iStack_258;
    piVar4 = &iStack_258;
    U_JUKELINUX1_KKC = 0;
    if (-1 < iVar1 + -1) {
      U_JUKELINUX1_KKC = -1;
      do {
        U_JUKELINUX1_KKC = U_JUKELINUX1_KKC + 1;
        puStack_25c = (undefined4 *)0x80dbeca;
        fpc_ansistr_decr_ref();
        local_38 = 0;
        puStack_25c = (undefined4 *)0x80dbee2;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        puStack_25c = (undefined4 *)0x80dbeed;
        fpc_ansistr_decr_ref();
        local_3c = 0;
        puStack_25c = (undefined4 *)0x80dbf20;
        (**(code **)(**(int **)(*(int *)(local_c + 0x6e8) + 0x36c) + 0x78))();
        puStack_25c = (undefined4 *)0x80dbf2a;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_OKC = 1;
        }
      } while (U_JUKELINUX1_KKC < iVar1 + -1);
    }
    if (U_JUKELINUX1_OKC == 1) {
      puStack_25c = (undefined4 *)0x80dbf5a;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      puStack_25c = (undefined4 *)0x80dbf74;
      fpc_ansistr_concat();
      puStack_25c = (undefined4 *)0x80dbf87;
      FPC_ANSISTR_TO_SHORTSTR();
      puStack_25c = (undefined4 *)0x80dbf97;
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      puStack_25c = (undefined4 *)0x80dbfa1;
      SYSTEM_REWRITE_TEXT();
      puStack_25c = (undefined4 *)0x80dbfa6;
      fpc_iocheck();
      puStack_25c = (undefined4 *)0x80dbfae;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      puStack_25c = (undefined4 *)0x80dbfc6;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      puStack_25c = (undefined4 *)0x80dbfce;
      fpc_ansistr_incr_ref();
      puStack_25c = (undefined4 *)0x80dbfd8;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_RESOLUCAOOPC = local_3c;
      puStack_25c = (undefined4 *)0x80dbfeb;
      fpc_ansistr_decr_ref();
      local_140 = 0;
      puStack_25c = (undefined4 *)0x80dc009;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      puStack_25c = (undefined4 *)0x80dc019;
      iVar1 = fpc_ansistr_compare_equal();
      if (iVar1 == 0) {
        puStack_25c = (undefined4 *)0x80dc0a1;
        fpc_ansistr_decr_ref();
        local_144 = 0;
        puStack_25c = (undefined4 *)0x80dc0bf;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        puStack_25c = (undefined4 *)0x80dc0d4;
        fpc_write_text_ansistr();
        puStack_25c = (undefined4 *)0x80dc0d9;
        fpc_iocheck();
        puStack_25c = (undefined4 *)0x80dc0e3;
        fpc_writeln_end();
        puStack_25c = (undefined4 *)0x80dc0e8;
        fpc_iocheck();
      }
      else {
        puStack_25c = (undefined4 *)0x80dc025;
        fpc_ansistr_decr_ref();
        local_3c = 0;
        puStack_25c = &local_3c;
        fpc_ansistr_decr_ref();
        local_144 = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        fpc_ansistr_copy();
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        ppuVar3 = &puStack_25c;
      }
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dc0f2;
      SYSTEM_FLUSH_TEXT();
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dc0f7;
      fpc_iocheck();
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dc101;
      OBJPAS_CLOSEFILE_TEXT();
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dc106;
      fpc_iocheck();
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dc111;
      fpc_ansistr_decr_ref();
      local_144 = 0;
      local_48 = __JUKELINUX1__Ld955;
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dc12b;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      *(undefined4 **)((int)ppuVar3 + -4) = &local_3c;
      *(undefined4 *)((int)ppuVar3 + -8) = 0x80dc141;
      fpc_ansistr_decr_ref();
      local_148 = 0;
      *(undefined4 *)((int)ppuVar3 + -8) = 0x80dc15f;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppuVar3 + -8) = 0x80dc174;
      fpc_ansistr_copy();
      local_44 = local_3c;
      local_40 = &__JUKELINUX1__Ld197;
      *(undefined4 *)((int)ppuVar3 + -8) = 0x80dc195;
      fpc_ansistr_concat_multi();
      *(undefined4 *)((int)ppuVar3 + -8) = 0x80dc1a0;
      JUKELINUX1_GRAVALOG_ANSISTRING();
      *(undefined4 *)((int)ppuVar3 + -8) = 0x80dc1ab;
      fpc_ansistr_decr_ref();
      local_148 = 0;
      *(undefined4 **)((int)ppuVar3 + -8) = &local_148;
      *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc1c7;
      fpc_ansistr_decr_ref();
      local_144 = 0;
      *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc1e5;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc1fa;
      fpc_ansistr_copy();
      *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc20a;
      iVar1 = fpc_ansistr_compare_equal();
      if (iVar1 == 0) {
        *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc221;
        iVar1 = fpc_ansistr_compare_equal();
        if (iVar1 == 0) {
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc238;
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_PROPAGANDA = __JUKELINUX1__Ld91;
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc249;
          fpc_ansistr_decr_ref();
          local_148 = 0;
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc269;
          fpc_ansistr_concat();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc27f;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc28f;
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc299;
          SYSTEM_RESET_TEXT();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc29e;
          fpc_iocheck();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2a8;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2b7;
          fpc_read_text_ansistr();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2bc;
          fpc_iocheck();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2c6;
          fpc_readln_end();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2cb;
          fpc_iocheck();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2d5;
          OBJPAS_CLOSEFILE_TEXT();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2da;
          fpc_iocheck();
          *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2ee;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
      }
      *(undefined4 *)((int)ppuVar3 + -0xc) = 0x80dc2f8;
      DIALOGS_SHOWMESSAGE_ANSISTRING();
      piVar4 = (int *)((int)ppuVar3 + -8);
    }
    else {
      puStack_25c = (undefined4 *)0x80dc30e;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
  }
  piVar4[-1] = 0x80dc313;
  fpc_popaddrstack();
  piVar4[-1] = 0x80dc31e;
  fpc_ansistr_decr_ref();
  local_148 = 0;
  piVar4[-1] = 0x80dc333;
  fpc_ansistr_decr_ref();
  local_144 = 0;
  piVar4[-1] = 0x80dc348;
  fpc_ansistr_decr_ref();
  local_140 = 0;
  piVar4[-1] = 0x80dc35a;
  fpc_ansistr_decr_ref();
  local_3c = 0;
  piVar4[-1] = 0x80dc369;
  fpc_ansistr_decr_ref();
  local_38 = 0;
  if (*piVar4 != 0) {
    *piVar4 = 0x80dc37a;
    fpc_reraise();
  }
  return;
}

