// JUKELINUX1_GRAVA_PENDRIVE_CONTADORES  @ 080961c0

/* WARNING: Removing unreachable block (ram,0x08096755) */
/* WARNING: Removing unreachable block (ram,0x08096764) */
/* WARNING: Removing unreachable block (ram,0x08096768) */

void JUKELINUX1_GRAVA_PENDRIVE_CONTADORES(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar3 = 0;
  fpc_pushexceptaddr(0,0,0,0,0);
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
        DIALOGS_SHOWMESSAGE_ANSISTRING();
      }
      U_JUKELINUX1_JAGRAVOUNOPENDRIVE = 0;
    }
    else {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_REWRITE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      JUKELINUX1_CRIPTASUPER2_ANSISTRING__ANSISTRING();
      fpc_write_text_ansistr();
      fpc_iocheck();
      fpc_writeln_end();
      fpc_iocheck();
      SYSTEM_FLUSH_TEXT();
      fpc_iocheck();
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,uVar3,0);
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING(iVar2,0);
      fpc_ansistr_concat_multi();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      U_JUKELINUX1_JAGRAVOUNOPENDRIVE = 0;
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  uVar3 = 0;
  fpc_ansistr_decr_ref(iVar2,0);
  uVar4 = 0;
  fpc_ansistr_decr_ref(iVar2,uVar3,0);
  uVar5 = 0;
  fpc_ansistr_decr_ref();
  uVar6 = 0;
  fpc_ansistr_decr_ref();
  uVar7 = 0;
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise(uVar3,uVar4,uVar5,uVar6,uVar7);
  }
  return;
}

