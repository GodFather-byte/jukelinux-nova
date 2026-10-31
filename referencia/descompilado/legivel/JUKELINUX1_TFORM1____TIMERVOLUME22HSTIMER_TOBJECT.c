// JUKELINUX1_TFORM1_$__TIMERVOLUME22HSTIMER$TOBJECT  @ 080e7fc0

void JUKELINUX1_TFORM1____TIMERVOLUME22HSTIMER_TOBJECT(void)

{
  uint uVar1;
  int *piVar2;
  longdouble lVar3;
  undefined8 local_154;
  undefined4 *puStack_14c;
  int aiStack_148 [67];
  undefined4 local_3c;
  undefined4 local_38 [13];
  
  aiStack_148[1] = 0;
  aiStack_148[2] = 0;
  local_3c = 0;
  local_38[0] = 0;
  aiStack_148[0] = 0x80e8001;
  fpc_pushexceptaddr();
  aiStack_148[0] = 0x80e8006;
  aiStack_148[0] = fpc_setjmp();
  piVar2 = aiStack_148;
  if ((aiStack_148[0] == 0) && (piVar2 = aiStack_148, 0 < U_JUKELINUX1_LIMITARVOLUME)) {
    if (U_JUKELINUX1_LIMITARVOLUME < U_JUKELINUX1_VOLUME) {
      puStack_14c = (undefined4 *)0x80e8035;
      fpc_ansistr_decr_ref();
      local_38[0] = 0;
      puStack_14c = local_38;
      local_154 = (double)CONCAT44(0x80e8048,(undefined4)local_154);
      fpc_ansistr_decr_ref();
      local_3c = 0;
      local_154 = (double)CONCAT44(0x80e8054,(undefined4)local_154);
      lVar3 = (longdouble)SYSUTILS_TIME__TDATETIME();
      local_154 = (double)lVar3;
      SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
      fpc_ansistr_copy();
      uVar1 = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
      piVar2 = (int *)&local_154;
      if (uVar1 < 9 || uVar1 - 0x16 < 2) {
        fpc_ansistr_decr_ref();
        local_3c = 0;
        fpc_ansistr_concat();
        FPC_ANSISTR_TO_SHORTSTR();
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        SYSTEM_REWRITE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        local_3c = 0;
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        SYSTEM_FLUSH_TEXT();
        fpc_iocheck();
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
        U_JUKELINUX1_VOLUME = U_JUKELINUX1_LIMITARVOLUME;
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
        MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
        U_JUKELINUX1_VOLUMELIMITADO = '\x01';
        if (U_JUKELINUX1_RESOLUCAO == 0x556) {
          fpc_ansistr_decr_ref();
          local_3c = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
          fpc_ansistr_decr_ref();
          local_3c = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
        }
        piVar2 = (int *)&local_154;
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          fpc_ansistr_decr_ref();
          local_3c = 0;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          piVar2 = (int *)&local_154;
        }
      }
    }
    else {
      piVar2 = aiStack_148;
      if (U_JUKELINUX1_VOLUMELIMITADO != '\0') {
        puStack_14c = (undefined4 *)0x80e8249;
        fpc_ansistr_decr_ref();
        local_3c = 0;
        puStack_14c = &local_3c;
        local_154 = (double)CONCAT44(0x80e825f,(undefined4)local_154);
        fpc_ansistr_decr_ref();
        aiStack_148[2] = 0;
        local_154 = (double)CONCAT44(0x80e826e,(undefined4)local_154);
        lVar3 = (longdouble)SYSUTILS_TIME__TDATETIME();
        local_154 = (double)lVar3;
        SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
        fpc_ansistr_copy();
        uVar1 = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
        piVar2 = (int *)&local_154;
        if (8 < uVar1 && 1 < uVar1 - 0x16) {
          fpc_ansistr_decr_ref();
          aiStack_148[2] = 0;
          fpc_ansistr_concat();
          FPC_ANSISTR_TO_SHORTSTR();
          OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
          SYSTEM_RESET_TEXT();
          fpc_iocheck();
          fpc_ansistr_decr_ref();
          fpc_read_text_ansistr();
          fpc_iocheck();
          fpc_readln_end();
          fpc_iocheck();
          OBJPAS_CLOSEFILE_TEXT();
          fpc_iocheck();
          fpc_ansistr_decr_ref();
          aiStack_148[2] = 0;
          fpc_ansistr_decr_ref();
          aiStack_148[1] = 0;
          fpc_ansistr_concat();
          fpc_pchar_to_ansistr();
          SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
          U_JUKELINUX1_VOLUME = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
          MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
          MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____SETVOLUME_LONGINT();
          U_JUKELINUX1_VOLUMELIMITADO = '\0';
          if (U_JUKELINUX1_RESOLUCAO == 0x556) {
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
          }
          piVar2 = (int *)&local_154;
          if (U_JUKELINUX1_RESOLUCAO == 0x400) {
            JUKELINUX1_MENSAGEMJPG_ANSISTRING_LONGINT_ANSISTRING();
            piVar2 = (int *)&local_154;
          }
        }
      }
    }
  }
  piVar2[-1] = 0x80e845d;
  fpc_popaddrstack();
  piVar2[-1] = 0x80e8468;
  fpc_ansistr_decr_ref();
  aiStack_148[1] = 0;
  piVar2[-1] = 0x80e847d;
  fpc_ansistr_decr_ref();
  aiStack_148[2] = 0;
  piVar2[-1] = 0x80e848f;
  fpc_ansistr_decr_ref();
  local_3c = 0;
  piVar2[-1] = 0x80e849e;
  fpc_ansistr_decr_ref();
  local_38[0] = 0;
  if (*piVar2 != 0) {
    *piVar2 = 0x80e84af;
    fpc_reraise();
  }
  return;
}

