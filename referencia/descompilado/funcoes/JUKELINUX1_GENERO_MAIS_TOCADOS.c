// JUKELINUX1_GENERO_MAIS_TOCADOS  @ 080b0c40

void JUKELINUX1_GENERO_MAIS_TOCADOS(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  int local_8;
  
  fpc_pushexceptaddr();
  iVar4 = fpc_setjmp();
  if (iVar4 == 0) {
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar3 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    iVar2 = U_JUKELINUX1_TOTALCDS;
    if (cVar3 != '\0') {
      if (0 < U_JUKELINUX1_TOTALCDS) {
        local_8 = 0;
        do {
          local_8 = local_8 + 1;
          (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] = 0;
        } while (local_8 < iVar2);
      }
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_RESET_TEXT();
      fpc_iocheck();
      while( true ) {
        cVar3 = SYSTEM_EOF_TEXT__BOOLEAN();
        fpc_iocheck();
        if (cVar3 != '\0') break;
        fpc_ansistr_decr_ref();
        fpc_read_text_ansistr();
        fpc_iocheck();
        fpc_readln_end();
        fpc_iocheck();
        iVar2 = U_JUKELINUX1_TOTALCDS;
        if (0 < U_JUKELINUX1_TOTALCDS) {
          local_8 = 0;
          do {
            local_8 = local_8 + 1;
            iVar1 = (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90];
            if (0 < iVar1) {
              local_c = 0;
              do {
                local_c = local_c + 1;
                iVar5 = fpc_ansistr_compare_equal();
                if (iVar5 == 0) {
                  (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] =
                       (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] + 1;
                }
              } while (local_c < iVar1);
            }
          } while (local_8 < iVar2);
        }
      }
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
    }
    (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0x854) + 0x480))();
    iVar2 = U_JUKELINUX1_TOTALMMRITMO;
    if (0 < U_JUKELINUX1_TOTALMMRITMO) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        *(undefined4 *)(&DAT_0930013c + local_10 * 4) = 0;
      } while (local_10 < iVar2);
    }
    iVar2 = U_JUKELINUX1_TOTALMMRITMO;
    if (0 < U_JUKELINUX1_TOTALMMRITMO) {
      local_10 = 0;
      do {
        iVar1 = U_JUKELINUX1_TOTALCDS;
        local_10 = local_10 + 1;
        if (0 < U_JUKELINUX1_TOTALCDS) {
          local_8 = 0;
          do {
            local_8 = local_8 + 1;
            fpc_ansistr_decr_ref();
            fpc_shortstr_to_ansistr();
            iVar5 = fpc_ansistr_compare_equal();
            if (iVar5 == 0) {
              *(int *)(&DAT_0930013c + local_10 * 4) =
                   *(int *)(&DAT_0930013c + local_10 * 4) + (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90]
              ;
            }
          } while (local_8 < iVar1);
        }
      } while (local_10 < iVar2);
    }
    iVar2 = U_JUKELINUX1_TOTALMMRITMO;
    if (0 < U_JUKELINUX1_TOTALMMRITMO) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        (**(code **)(**(int **)(*(int *)(U_JUKELINUX1_FORM1 + 0x854) + 0x364) + 0xa4))();
      } while (local_10 < iVar2);
    }
    (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0x858) + 0x480))();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar4 != 0) {
    fpc_reraise();
  }
  return;
}

