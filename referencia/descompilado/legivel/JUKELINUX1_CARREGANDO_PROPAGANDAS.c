// JUKELINUX1_CARREGANDO_PROPAGANDAS  @ 08099be0

void JUKELINUX1_CARREGANDO_PROPAGANDAS(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    U_JUKELINUX1_KPRO = 0;
    do {
      U_JUKELINUX1_KPRO = U_JUKELINUX1_KPRO + 1;
      iVar3 = U_JUKELINUX1_KPRO;
      fpc_ansistr_decr_ref();
      (&U_JUKELINUX1_TOTALPRO)[iVar3] = 0;
    } while (U_JUKELINUX1_KPRO < 500);
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    fpc_ansistr_concat();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    if (U_JUKELINUX1_RESOLUCAO == 0x400) {
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_PROPAGANDA = __JUKELINUX1__Ld91;
        CONTROLS_TCONTROL____HIDE();
      }
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_incr_ref();
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_PASTAPROPAGANDA = U_JUKELINUX1_PASTA;
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    if (U_JUKELINUX1_RESOLUCAO == 0x556) {
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_concat();
        fpc_ansistr_decr_ref();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_concat();
        fpc_ansistr_decr_ref();
      }
    }
    if (U_JUKELINUX1_RESOLUCAO == 0x400) {
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_concat();
        fpc_ansistr_decr_ref();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_concat();
        fpc_ansistr_decr_ref();
      }
    }
    if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_concat();
        fpc_ansistr_decr_ref();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_concat();
        fpc_ansistr_decr_ref();
      }
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      fpc_ansistr_concat();
      fpc_ansistr_decr_ref();
    }
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    (**(code **)(*(int *)Form1.LabelMusUltima2 + 0x2fc))();
    CONTROLS_TCONTROL____REFRESH();
    (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
    cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
    if (cVar1 == '\0') {
      SYSUTILS_CREATEDIR_ANSISTRING__BOOLEAN();
    }
    FILECTRL_TCUSTOMFILELISTBOX____SETDIRECTORY_ANSISTRING();
    U_JUKELINUX1_KPRO = 0;
    U_JUKELINUX1_TOTALPRO = 0;
    iVar3 = STDCTRLS_TCUSTOMLISTBOX____GETCOUNT__LONGINT();
    if (-1 < iVar3 + -1) {
      local_8 = -1;
      do {
        local_8 = local_8 + 1;
        fpc_ansistr_decr_ref();
        (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
        iVar4 = fpc_ansistr_compare_equal();
        if (iVar4 != 0) {
          fpc_ansistr_decr_ref();
          (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
          iVar4 = fpc_ansistr_compare_equal();
          if (iVar4 != 0) {
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
            SYSUTILS_EXTRACTFILEEXT_ANSISTRING__ANSISTRING();
            SYSUTILS_UPPERCASE_ANSISTRING__ANSISTRING();
            iVar4 = fpc_ansistr_compare_equal();
            if ((iVar4 == 0) &&
               (U_JUKELINUX1_KPRO = U_JUKELINUX1_KPRO + 1, U_JUKELINUX1_KPRO < 0x1f5)) {
              fpc_ansistr_decr_ref();
              (**(code **)(**(int **)(Form1.ListBoxRCds + 0x364) + 0x78))();
              fpc_ansistr_concat();
            }
          }
        }
      } while (local_8 < iVar3 + -1);
    }
    U_JUKELINUX1_TOTALPRO = U_JUKELINUX1_KPRO;
    (**(code **)(*(int *)Form1.ImageMusR + 0xdc))();
    U_JUKELINUX1_POSPRO = 0;
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      (**(code **)(*(int *)Form1.ImageMusR + 0xd8))();
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          CONTROLS_TCONTROL____SHOW();
        }
      }
      else {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          CONTROLS_TCONTROL____SHOW();
        }
      }
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
        CONTROLS_TCONTROL____SHOW();
      }
    }
    else {
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____SHOW();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        CONTROLS_TCONTROL____HIDE();
      }
    }
    if (U_JUKELINUX1_TOTALPRO == 0) {
      (**(code **)(*(int *)Form1.ImageMusR + 0xd8))();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      JUKELINUX1_GRAVALOG_ANSISTRING();
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

