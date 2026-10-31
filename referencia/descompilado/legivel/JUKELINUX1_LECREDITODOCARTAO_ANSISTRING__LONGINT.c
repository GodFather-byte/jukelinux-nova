// JUKELINUX1_LECREDITODOCARTAO$ANSISTRING$$LONGINT  @ 080b3930

undefined4 JUKELINUX1_LECREDITODOCARTAO_ANSISTRING__LONGINT(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int aiStack_160 [4];
  int local_14;
  undefined4 local_c;
  
  aiStack_160[3] = 0x80b3947;
  fpc_ansistr_incr_ref();
  aiStack_160[3] = 0x80b3976;
  fpc_pushexceptaddr();
  aiStack_160[3] = 0x80b397b;
  aiStack_160[3] = fpc_setjmp();
  piVar3 = aiStack_160 + 3;
  if (aiStack_160[3] == 0) {
    local_c = 0;
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      piVar3 = aiStack_160 + 3;
    }
    else {
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TYPEDFILE_SHORTSTRING();
      fpc_reset_typed();
      fpc_iocheck();
      piVar3 = aiStack_160 + 3;
      local_14 = 0;
      while( true ) {
        *(undefined4 *)((int)piVar3 + -4) = 0x80b3abb;
        cVar1 = SYSTEM_EOF_file__BOOLEAN();
        *(undefined4 *)((int)piVar3 + -4) = 0x80b3ac2;
        fpc_iocheck();
        if (cVar1 != '\0') break;
        *(int *)((int)piVar3 + -4) = local_14 >> 0x1f;
        *(int *)((int)piVar3 + -8) = local_14;
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a08;
        SYSTEM_SEEK_file_INT64();
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a0d;
        fpc_iocheck();
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a21;
        FPC_TYPED_READ();
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a26;
        fpc_iocheck();
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a31;
        fpc_ansistr_decr_ref();
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a4b;
        fpc_shortstr_to_ansistr();
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a59;
        JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
        *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a64;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a73;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a8d;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3a9b;
          JUKELINUX1_DESCRIPTA_ANSISTRING__ANSISTRING();
          *(undefined4 *)((int)piVar3 + -0xc) = 0x80b3aa8;
          local_c = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
        }
        piVar3 = (int *)((int)piVar3 + -8);
        local_14 = local_14 + 1;
      }
      *(undefined4 *)((int)piVar3 + -4) = 0x80b3ad4;
      OBJPAS_CLOSEFILE_file();
      *(undefined4 *)((int)piVar3 + -4) = 0x80b3ad9;
      fpc_iocheck();
    }
  }
  piVar3[-1] = 0x80b3b13;
  fpc_popaddrstack();
  piVar3[-1] = 0x80b3b1e;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80b3b30;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80b3b3f;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80b3b4e;
  fpc_ansistr_decr_ref();
  piVar3[-1] = 0x80b3b5d;
  fpc_ansistr_decr_ref();
  if (*piVar3 != 0) {
    *piVar3 = 0x80b3b67;
    fpc_reraise();
  }
  return local_c;
}

