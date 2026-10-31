// JUKELINUX1_TFORM1_$__BUTTONQRCODECADASTROMENUCLICK$TOBJECT  @ 080cd3e0

void JUKELINUX1_TFORM1____BUTTONQRCODECADASTROMENUCLICK_TOBJECT(void)

{
  char cVar1;
  int *piVar2;
  longdouble lVar3;
  undefined8 local_178;
  undefined8 local_170;
  int iStack_168;
  
  iStack_168 = 0x80cd41a;
  fpc_pushexceptaddr();
  iStack_168 = 0x80cd41f;
  iStack_168 = fpc_setjmp();
  piVar2 = &iStack_168;
  if (iStack_168 == 0) {
    local_170 = (double)CONCAT44(0x80cd448,(undefined4)local_170);
    fpc_ansistr_decr_ref();
    local_170 = (double)CONCAT44(0x80cd454,(undefined4)local_170);
    lVar3 = (longdouble)SYSUTILS_DATE__TDATETIME();
    local_170 = (double)lVar3;
    local_178 = (double)CONCAT44(0x80cd462,(undefined4)local_178);
    SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
    local_178 = (double)CONCAT44(0x80cd478,(undefined4)local_178);
    fpc_ansistr_decr_ref();
    local_178 = (double)CONCAT44(0x80cd484,(undefined4)local_178);
    lVar3 = (longdouble)SYSUTILS_TIME__TDATETIME();
    local_178 = (double)lVar3;
    SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
    fpc_ansistr_concat_multi();
    fpc_ansistr_concat_multi();
    fpc_ansistr_concat_multi();
    fpc_ansistr_concat_multi();
    fpc_ansistr_concat_multi();
    fpc_ansistr_concat_multi();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    FPC_ANSISTR_TO_SHORTSTR();
    OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
    SYSTEM_REWRITE_TEXT();
    fpc_iocheck();
    fpc_write_text_ansistr();
    fpc_iocheck();
    fpc_writeln_end();
    fpc_iocheck();
    SYSTEM_FLUSH_TEXT();
    fpc_iocheck();
    OBJPAS_CLOSEFILE_TEXT();
    fpc_iocheck();
    U_JUKELINUX1_CMD =
         (int *)(*(code *)PTR_PROCESS_TPROCESS____CREATE_TCOMPONENT__TPROCESS_08dbcaa0)();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    PROCESS_TPROCESS____SETCOMMANDLINE_ANSISTRING();
    (**(code **)(*U_JUKELINUX1_CMD + 0xe0))();
    SYSTEM_TOBJECT____FREE();
    SYSUTILS_SLEEP_LONGWORD();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 != '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
    }
    CONTROLS_TCONTROL____SETLEFT_LONGINT();
    CONTROLS_TCONTROL____SETTOP_LONGINT();
    CONTROLS_TCONTROL____SHOW();
    piVar2 = (int *)&local_178;
  }
  piVar2[-1] = 0x80cd771;
  fpc_popaddrstack();
  piVar2[-1] = 0x80cd779;
  fpc_ansistr_decr_ref();
  piVar2[-1] = 0x80cd788;
  fpc_ansistr_decr_ref();
  piVar2[-1] = 0x80cd797;
  fpc_ansistr_decr_ref();
  if (*piVar2 != 0) {
    *piVar2 = 0x80cd7a8;
    fpc_reraise();
  }
  return;
}

