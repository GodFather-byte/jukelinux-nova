// JUKELINUX1_TFORM1_$__COMBOBOX6CHANGE$TOBJECT  @ 080dba90

void JUKELINUX1_TFORM1____COMBOBOX6CHANGE_TOBJECT(void)

{
  int iVar1;
  int iVar2;
  undefined4 **ppuVar3;
  int iStack_158;
  undefined4 *apuStack_154 [2];
  int iStack_14c;
  undefined4 local_3c;
  undefined4 local_38;
  int local_c;
  
  local_3c = 0;
  local_38 = 0;
  iStack_14c = 0x80dbacf;
  fpc_pushexceptaddr();
  iStack_14c = 0x80dbad4;
  iStack_14c = fpc_setjmp();
  ppuVar3 = (undefined4 **)&iStack_14c;
  if (iStack_14c == 0) {
    U_JUKELINUX1_OKC = 0;
    apuStack_154[1] = (undefined4 *)0x80dbb0d;
    iVar1 = (**(code **)(**(int **)(*(int *)(local_c + 0x6e4) + 0x36c) + 0x80))();
    ppuVar3 = (undefined4 **)&iStack_14c;
    U_JUKELINUX1_KKC = 0;
    if (-1 < iVar1 + -1) {
      U_JUKELINUX1_KKC = -1;
      do {
        U_JUKELINUX1_KKC = U_JUKELINUX1_KKC + 1;
        apuStack_154[1] = (undefined4 *)0x80dbb3a;
        fpc_ansistr_decr_ref();
        local_38 = 0;
        apuStack_154[1] = (undefined4 *)0x80dbb52;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        apuStack_154[1] = (undefined4 *)0x80dbb5d;
        fpc_ansistr_decr_ref();
        local_3c = 0;
        apuStack_154[1] = (undefined4 *)0x80dbb90;
        (**(code **)(**(int **)(*(int *)(local_c + 0x6e4) + 0x36c) + 0x78))();
        apuStack_154[1] = (undefined4 *)0x80dbb9a;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_OKC = 1;
        }
      } while (U_JUKELINUX1_KKC < iVar1 + -1);
    }
    if (U_JUKELINUX1_OKC == 1) {
      apuStack_154[1] = (undefined4 *)0x80dbbca;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      apuStack_154[1] = (undefined4 *)0x80dbbe4;
      fpc_ansistr_concat();
      apuStack_154[1] = (undefined4 *)0x80dbbf7;
      FPC_ANSISTR_TO_SHORTSTR();
      apuStack_154[1] = (undefined4 *)0x80dbc07;
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      apuStack_154[1] = (undefined4 *)0x80dbc11;
      SYSTEM_REWRITE_TEXT();
      apuStack_154[1] = (undefined4 *)0x80dbc16;
      fpc_iocheck();
      apuStack_154[1] = (undefined4 *)0x80dbc1e;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      apuStack_154[1] = (undefined4 *)0x80dbc36;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      apuStack_154[1] = (undefined4 *)0x80dbc3e;
      fpc_ansistr_incr_ref();
      apuStack_154[1] = (undefined4 *)0x80dbc48;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_LIMITARVOLUMEOPC = local_3c;
      apuStack_154[1] = (undefined4 *)0x80dbc58;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      apuStack_154[1] = (undefined4 *)0x80dbc70;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      apuStack_154[1] = (undefined4 *)0x80dbc82;
      fpc_write_text_ansistr();
      apuStack_154[1] = (undefined4 *)0x80dbc87;
      fpc_iocheck();
      apuStack_154[1] = (undefined4 *)0x80dbc91;
      fpc_writeln_end();
      apuStack_154[1] = (undefined4 *)0x80dbc96;
      fpc_iocheck();
      apuStack_154[1] = (undefined4 *)0x80dbca0;
      SYSTEM_FLUSH_TEXT();
      apuStack_154[1] = (undefined4 *)0x80dbca5;
      fpc_iocheck();
      apuStack_154[1] = (undefined4 *)0x80dbcaf;
      OBJPAS_CLOSEFILE_TEXT();
      apuStack_154[1] = (undefined4 *)0x80dbcb4;
      fpc_iocheck();
      apuStack_154[1] = (undefined4 *)0x80dbcbc;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      apuStack_154[1] = &local_3c;
      apuStack_154[0] = (undefined4 *)0x80dbcdb;
      fpc_ansistr_copy();
      apuStack_154[0] = (undefined4 *)0x80dbce8;
      iVar1 = fpc_ansistr_compare_equal();
      ppuVar3 = apuStack_154 + 1;
      if (iVar1 == 0) {
        U_JUKELINUX1_LIMITARVOLUMESTR._0_2_ = 0x3001;
      }
      else {
        apuStack_154[0] = (undefined4 *)0x80dbcff;
        fpc_ansistr_decr_ref();
        local_3c = 0;
        apuStack_154[0] = &local_3c;
        fpc_ansistr_copy();
        FPC_ANSISTR_TO_SHORTSTR();
        ppuVar3 = apuStack_154;
      }
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dbd38;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dbd4c;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dbd59;
      U_JUKELINUX1_LIMITARVOLUME = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dbd66;
      fpc_ansistr_decr_ref();
      local_3c = 0;
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dbd95;
      fpc_ansistr_concat_multi();
      *(undefined4 *)((int)ppuVar3 + -4) = 0x80dbd9d;
      JUKELINUX1_GRAVALOG_ANSISTRING();
    }
    else {
      apuStack_154[1] = (undefined4 *)0x80dbdb3;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    }
  }
  ppuVar3[-1] = (undefined4 *)0x80dbdb8;
  fpc_popaddrstack();
  ppuVar3[-1] = (undefined4 *)0x80dbdc0;
  fpc_ansistr_decr_ref();
  local_3c = 0;
  ppuVar3[-1] = (undefined4 *)0x80dbdcf;
  fpc_ansistr_decr_ref();
  local_38 = 0;
  if (*ppuVar3 != (undefined4 *)0x0) {
    *ppuVar3 = (undefined4 *)0x80dbde0;
    fpc_reraise();
  }
  return;
}

