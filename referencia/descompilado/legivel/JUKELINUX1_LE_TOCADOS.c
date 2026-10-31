// JUKELINUX1_LE_TOCADOS  @ 080b07b0

void JUKELINUX1_LE_TOCADOS(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  int local_8;
  
  fpc_pushexceptaddr();
  iVar3 = fpc_setjmp();
  if (iVar3 == 0) {
    CONTROLS_TCONTROL____SHOW();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    CONTROLS_TCONTROL____REFRESH();
    fpc_ansistr_decr_ref();
    fpc_ansistr_concat();
    cVar2 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar2 != '\0') {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      FPC_ANSISTR_TO_SHORTSTR();
      OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
      SYSTEM_RESET_TEXT();
      fpc_iocheck();
      while( true ) {
        cVar2 = SYSTEM_EOF_TEXT__BOOLEAN();
        fpc_iocheck();
        if (cVar2 != '\0') break;
        fpc_ansistr_decr_ref();
        fpc_read_text_ansistr();
        fpc_iocheck();
        fpc_readln_end();
        fpc_iocheck();
        iVar1 = U_JUKELINUX1_TOTALCDS;
        if (0 < U_JUKELINUX1_TOTALCDS) {
          local_8 = 0;
          do {
            local_8 = local_8 + 1;
            iVar5 = (&U_JUKELINUX1_NOMEDOCLIENTE)[local_8 * 0x90];
            if (0 < iVar5) {
              local_c = 0;
              do {
                local_c = local_c + 1;
                iVar4 = fpc_ansistr_compare_equal();
                if (iVar4 == 0) {
                  (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] =
                       (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90] + 1;
                }
              } while (local_c < iVar5);
            }
          } while (local_8 < iVar1);
        }
      }
      OBJPAS_CLOSEFILE_TEXT();
      fpc_iocheck();
    }
    (**(code **)(*(int *)Form1.LabelMDataHora + 0x480))();
    iVar1 = U_JUKELINUX1_TOTALMMRITMO;
    if (0 < U_JUKELINUX1_TOTALMMRITMO) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        *(undefined4 *)(&DAT_0930013c + local_10 * 4) = 0;
      } while (local_10 < iVar1);
    }
    iVar1 = U_JUKELINUX1_TOTALMMRITMO;
    if (0 < U_JUKELINUX1_TOTALMMRITMO) {
      local_10 = 0;
      do {
        iVar5 = U_JUKELINUX1_TOTALCDS;
        local_10 = local_10 + 1;
        if (0 < U_JUKELINUX1_TOTALCDS) {
          local_8 = 0;
          do {
            local_8 = local_8 + 1;
            fpc_ansistr_decr_ref();
            fpc_shortstr_to_ansistr();
            iVar4 = fpc_ansistr_compare_equal();
            if (iVar4 == 0) {
              *(int *)(&DAT_0930013c + local_10 * 4) =
                   *(int *)(&DAT_0930013c + local_10 * 4) + (&U_JUKELINUX1_SELOSSTR)[local_8 * 0x90]
              ;
            }
          } while (local_8 < iVar5);
        }
      } while (local_10 < iVar1);
    }
    iVar1 = U_JUKELINUX1_TOTALMMRITMO;
    if (0 < U_JUKELINUX1_TOTALMMRITMO) {
      local_10 = 0;
      do {
        local_10 = local_10 + 1;
        iVar5 = SYSTEM_POS_ANSISTRING_ANSISTRING__LONGINT();
        if (iVar5 == 0) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          fpc_ansistr_concat_multi();
          (**(code **)(**(int **)(Form1.LabelMDataHora + 0x364) + 0xa4))();
        }
        else {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          (**(code **)(**(int **)(Form1.LabelMDataHora + 0x364) + 0xa4))();
        }
      } while (local_10 < iVar1);
    }
    (**(code **)(*(int *)Form1.PanelMenu5grande + 0x480))();
    CONTROLS_TCONTROL____HIDE();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    CONTROLS_TCONTROL____REFRESH();
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar3 != 0) {
    fpc_reraise();
  }
  return;
}

