// JUKELINUX1_GRAVACREDITONOCARTAO$ANSISTRING$LONGINT  @ 080b3b80

void JUKELINUX1_GRAVACREDITONOCARTAO_ANSISTRING_LONGINT(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  int iStack_264;
  int local_14;
  
  iStack_264 = 0x80b3b9d;
  fpc_ansistr_incr_ref();
  iStack_264 = 0x80b3be0;
  fpc_pushexceptaddr();
  iStack_264 = 0x80b3be5;
  iStack_264 = fpc_setjmp();
  piVar5 = &iStack_264;
  if (iStack_264 == 0) {
    bVar1 = false;
    fpc_ansistr_concat();
    cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar2 == '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_concat_multi();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      piVar5 = &iStack_264;
    }
    else {
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING();
      fpc_reset_typed();
      fpc_iocheck();
      local_14 = 0;
      piVar5 = &iStack_264;
      while( true ) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3df3;
        cVar2 = SYSTEM_EOF_file__BOOLEAN();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3dfa;
        fpc_iocheck();
        if (cVar2 != '\0') break;
        *(int *)((int)piVar5 + -4) = local_14 >> 0x1f;
        *(int *)((int)piVar5 + -8) = local_14;
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3c6c;
        SYSTEM_SEEK_file_INT64();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3c71;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3c85;
        FPC_TYPED_READ();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3c8a;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3c95;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3caf;
        fpc_shortstr_to_ansistr();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3cbd;
        JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3cc8;
        iVar3 = fpc_ansistr_compare_equal();
        puVar4 = (undefined1 *)((int)piVar5 + -8);
        if (iVar3 == 0) {
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3cdb;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3cf5;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d03;
          JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d10;
          SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d1e;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d33;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d50;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d61;
          JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d76;
          FPC_ANSISTR_TO_SHORTSTR();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d81;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3d9b;
          JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
          *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3db0;
          FPC_ANSISTR_TO_SHORTSTR();
          *(int *)((int)piVar5 + -0xc) = local_14 >> 0x1f;
          *(int *)((int)piVar5 + -0x10) = local_14;
          *(undefined4 *)((int)piVar5 + -0x14) = 0x80b3dc4;
          SYSTEM_SEEK_file_INT64();
          *(undefined4 *)((int)piVar5 + -0x14) = 0x80b3dc9;
          fpc_iocheck();
          *(undefined4 *)((int)piVar5 + -0x14) = 0x80b3ddd;
          FPC_TYPED_WRITE();
          *(undefined4 *)((int)piVar5 + -0x14) = 0x80b3de2;
          fpc_iocheck();
          puVar4 = (undefined1 *)((int)piVar5 + -0x10);
          bVar1 = true;
        }
        local_14 = local_14 + 1;
        piVar5 = (int *)puVar4;
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80b3e0c;
      OBJPAS_CLOSEFILE_file();
      *(undefined4 *)((int)piVar5 + -4) = 0x80b3e11;
      fpc_iocheck();
      if (!bVar1) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e2f;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e3f;
        OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e4e;
        fpc_reset_typed();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e53;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e5e;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e76;
        JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e8b;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3e96;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3eab;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3ec3;
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3ed4;
        JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3ee9;
        FPC_ANSISTR_TO_SHORTSTR();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3ef4;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3f0e;
        JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
        *(undefined4 *)((int)piVar5 + -4) = 0x80b3f23;
        FPC_ANSISTR_TO_SHORTSTR();
        *(int *)((int)piVar5 + -4) = local_14 + 1 >> 0x1f;
        *(int *)((int)piVar5 + -8) = local_14 + 1;
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3f38;
        SYSTEM_SEEK_file_INT64();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3f3d;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3f51;
        FPC_TYPED_WRITE();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3f56;
        fpc_iocheck();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3f60;
        OBJPAS_CLOSEFILE_file();
        *(undefined4 *)((int)piVar5 + -0xc) = 0x80b3f65;
        fpc_iocheck();
        piVar5 = (int *)((int)piVar5 + -8);
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80b3f6a;
      JUKELINUX1_BACKUPCARTAOCCC();
    }
  }
  piVar5[-1] = 0x80b3ff8;
  fpc_popaddrstack();
  piVar5[-1] = 0x80b4003;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80b4018;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80b402d;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80b403f;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80b404e;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80b405d;
  fpc_ansistr_decr_ref();
  piVar5[-1] = 0x80b406c;
  fpc_ansistr_decr_ref();
  if (*piVar5 != 0) {
    *piVar5 = 0x80b4076;
    fpc_reraise();
  }
  return;
}

