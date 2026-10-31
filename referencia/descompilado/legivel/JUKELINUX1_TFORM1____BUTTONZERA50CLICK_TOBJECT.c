// JUKELINUX1_TFORM1_$__BUTTONZERA50CLICK$TOBJECT  @ 080cd7b0

void JUKELINUX1_TFORM1____BUTTONZERA50CLICK_TOBJECT(void)

{
  int *piVar1;
  longdouble lVar2;
  undefined8 local_144;
  int aiStack_13c [65];
  undefined4 local_38;
  
  local_38 = 0;
  aiStack_13c[0] = 0x80cd7d6;
  fpc_pushexceptaddr();
  aiStack_13c[0] = 0x80cd7db;
  aiStack_13c[0] = fpc_setjmp();
  piVar1 = aiStack_13c;
  if (aiStack_13c[0] == 0) {
    piVar1 = aiStack_13c;
    if (U_JUKELINUX1_ZERA50 == 2) {
      local_144 = (double)CONCAT44(0x80cd7fa,(undefined4)local_144);
      fpc_ansistr_decr_ref();
      local_38 = 0;
      local_144 = (double)CONCAT44(0x80cd814,(undefined4)local_144);
      fpc_ansistr_concat();
      local_144 = (double)CONCAT44(0x80cd81c,(undefined4)local_144);
      SYSUTILS_DELETEFILE_ANSISTRING__BOOLEAN();
      local_144 = (double)CONCAT44(0x80cd831,(undefined4)local_144);
      fpc_ansistr_concat();
      local_144 = (double)CONCAT44(0x80cd847,(undefined4)local_144);
      FPC_ANSISTR_TO_SHORTSTR();
      local_144 = (double)CONCAT44(0x80cd857,(undefined4)local_144);
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      local_144 = (double)CONCAT44(0x80cd861,(undefined4)local_144);
      SYSTEM_REWRITE_TEXT();
      local_144 = (double)CONCAT44(0x80cd866,(undefined4)local_144);
      fpc_iocheck();
      local_144 = (double)CONCAT44(0x80cd86e,(undefined4)local_144);
      fpc_ansistr_decr_ref();
      local_38 = 0;
      local_144 = (double)CONCAT44(0x80cd87a,(undefined4)local_144);
      lVar2 = (longdouble)SYSUTILS_DATE__TDATETIME();
      local_144 = (double)lVar2;
      SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      piVar1 = (int *)&local_144;
      U_JUKELINUX1_ZERA50 = 3;
    }
    if (U_JUKELINUX1_ZERA50 == 1) {
      *(undefined4 *)((int)piVar1 + -4) = 0x80cd906;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)piVar1 + -4) = 0x80cd910;
      DIALOGS_SHOWMESSAGE_ANSISTRING();
      U_JUKELINUX1_ZERA50 = 2;
    }
    if (U_JUKELINUX1_ZERA50 == 0) {
      *(undefined4 *)((int)piVar1 + -4) = 0x80cd936;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)piVar1 + -4) = 0x80cd940;
      DIALOGS_SHOWMESSAGE_ANSISTRING();
      U_JUKELINUX1_ZERA50 = 1;
    }
  }
  piVar1[-1] = 0x80cd94f;
  fpc_popaddrstack();
  piVar1[-1] = 0x80cd957;
  fpc_ansistr_decr_ref();
  local_38 = 0;
  if (*piVar1 != 0) {
    *piVar1 = 0x80cd968;
    fpc_reraise();
  }
  return;
}

