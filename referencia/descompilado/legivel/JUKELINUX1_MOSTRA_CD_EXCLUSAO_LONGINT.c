// JUKELINUX1_MOSTRA_CD_EXCLUSAO$LONGINT  @ 080b1030

void JUKELINUX1_MOSTRA_CD_EXCLUSAO_LONGINT(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_c;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    fpc_ansistr_decr_ref();
    fpc_ansistr_decr_ref();
    fpc_shortstr_to_ansistr();
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_decr_ref();
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    fpc_ansistr_concat_multi();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      iVar3 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar3 = (**(code **)(**(int **)(Form1.DataDaInstalacao + 0x36c) + 0x80))();
      if (-1 < iVar3 + -1) {
        local_c = -1;
        do {
          local_c = local_c + 1;
          fpc_ansistr_decr_ref();
          fpc_shortstr_to_ansistr();
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.DataDaInstalacao + 0x36c) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.DataDaInstalacao + 0x36c) + 0x78))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          }
        } while (local_c < iVar3 + -1);
      }
    }
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      iVar3 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar3 = (**(code **)(**(int **)(Form1.ButtonGravarOsDados + 0x36c) + 0x80))();
      if (-1 < iVar3 + -1) {
        local_c = -1;
        do {
          local_c = local_c + 1;
          fpc_ansistr_decr_ref();
          fpc_shortstr_to_ansistr();
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.ButtonGravarOsDados + 0x36c) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.ButtonGravarOsDados + 0x36c) + 0x78))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          }
        } while (local_c < iVar3 + -1);
      }
    }
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      iVar3 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar3 = (**(code **)(**(int **)(Form1.CPF + 0x36c) + 0x80))();
      if (-1 < iVar3 + -1) {
        local_c = -1;
        do {
          local_c = local_c + 1;
          fpc_ansistr_decr_ref();
          fpc_shortstr_to_ansistr();
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.CPF + 0x36c) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.CPF + 0x36c) + 0x78))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          }
        } while (local_c < iVar3 + -1);
      }
    }
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      iVar3 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar3 = (**(code **)(**(int **)(Form1.Telefones + 0x36c) + 0x80))();
      if (-1 < iVar3 + -1) {
        local_c = -1;
        do {
          local_c = local_c + 1;
          fpc_ansistr_decr_ref();
          fpc_shortstr_to_ansistr();
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.Telefones + 0x36c) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.Telefones + 0x36c) + 0x78))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          }
        } while (local_c < iVar3 + -1);
      }
    }
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      iVar3 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar3 = (**(code **)(**(int **)(Form1.Bairro + 0x36c) + 0x80))();
      if (-1 < iVar3 + -1) {
        local_c = -1;
        do {
          local_c = local_c + 1;
          fpc_ansistr_decr_ref();
          fpc_shortstr_to_ansistr();
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.Bairro + 0x36c) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.Bairro + 0x36c) + 0x78))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          }
        } while (local_c < iVar3 + -1);
      }
    }
    cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_decr_ref();
      fpc_shortstr_to_ansistr();
      fpc_ansistr_concat_multi();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      iVar3 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar3 = (**(code **)(**(int **)(Form1.Cidade + 0x36c) + 0x80))();
      if (-1 < iVar3 + -1) {
        local_c = -1;
        do {
          local_c = local_c + 1;
          fpc_ansistr_decr_ref();
          fpc_shortstr_to_ansistr();
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.Cidade + 0x36c) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 == 0) {
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.Cidade + 0x36c) + 0x78))();
            CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          }
        } while (local_c < iVar3 + -1);
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

