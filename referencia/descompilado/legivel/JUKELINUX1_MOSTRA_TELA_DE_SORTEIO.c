// JUKELINUX1_MOSTRA_TELA_DE_SORTEIO  @ 08097160

void JUKELINUX1_MOSTRA_TELA_DE_SORTEIO(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int aiStack_3c [5];
  int local_28 [4];
  undefined *local_18;
  int local_14;
  int local_c;
  int local_8;
  
  local_18 = (undefined *)0x0;
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    if (U_JUKELINUX1_TOCANDOPALHINHA != '\0') {
      CONTROLS_TCONTROL____HIDE();
    }
    if (U_JUKELINUX1_TOCANDOMUSICADVD != '\0') {
      CONTROLS_TCONTROL____HIDE();
    }
    if (U_JUKELINUX1_TOCANDOVIDEOTV != '\0') {
      CONTROLS_TCONTROL____HIDE();
    }
    (**(code **)(*(int *)Form1.LabelUpgrade1 + 0xd8))();
    CONTROLS_TCONTROL____SHOW();
    (**(code **)(*(int *)Form1.PanelExcluirMusica + 0x2fc))();
    GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
    fpc_ansistr_decr_ref();
    local_18 = &__JUKELINUX1__Ld48;
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          fpc_ansistr_decr_ref();
          local_18 = &__JUKELINUX1__Ld51;
        }
      }
      if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          fpc_ansistr_decr_ref();
          local_18 = &__JUKELINUX1__Ld51;
        }
      }
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          fpc_ansistr_decr_ref();
          local_18 = &__JUKELINUX1__Ld51;
        }
      }
      if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          fpc_ansistr_decr_ref();
          local_18 = &__JUKELINUX1__Ld51;
        }
      }
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          fpc_ansistr_decr_ref();
          local_18 = &__JUKELINUX1__Ld51;
        }
      }
      if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          fpc_ansistr_decr_ref();
          local_18 = &__JUKELINUX1__Ld51;
        }
      }
    }
    if (U_JUKELINUX1_RESOLUCAO == 0x400) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        local_18 = &__JUKELINUX1__Ld51;
      }
    }
    if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        local_18 = &__JUKELINUX1__Ld51;
      }
    }
    iVar3 = fpc_ansistr_compare_equal();
    if (iVar3 == 0) {
      (**(code **)(*(int *)Form1.CapaMenos2 + 0x104))();
      CONTROLS_TCONTROL____BRINGTOFRONT();
      if (U_JUKELINUX1_RESOLUCAO == 0x556) {
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETWIDTH_LONGINT();
        CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
      }
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____HIDE();
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      CONTROLS_TCONTROL____REFRESH();
      SYSUTILS_SLEEP_LONGWORD();
      if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
      CONTROLS_TCONTROL____SENDTOBACK();
      if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
      }
      if (U_JUKELINUX1_RESOLUCAO == 0x400) {
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
        CONTROLS_TCONTROL____SETLEFT_LONGINT();
        CONTROLS_TCONTROL____SETTOP_LONGINT();
      }
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      }
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      CONTROLS_TCONTROL____REFRESH();
      SYSUTILS_SLEEP_LONGWORD();
      SYSTEM_RANDOMIZE();
      local_c = SYSTEM_RANDOM_LONGINT__LONGINT();
      if (local_c == 0) {
        local_c = 1;
      }
      local_28[0] = SYSTEM_RANDOM_LONGINT__LONGINT();
      local_28[1] = SYSTEM_RANDOM_LONGINT__LONGINT();
      local_28[2] = SYSTEM_RANDOM_LONGINT__LONGINT();
      local_28[3] = SYSTEM_RANDOM_LONGINT__LONGINT();
      if (U_JUKELINUX1_PREMIOU == '\0') {
        U_JUKELINUX1_PREMIOU = '\x01';
        local_28[2] = local_28[0];
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          local_28[1] = local_28[0];
        }
      }
      else {
        U_JUKELINUX1_PREMIOU = '\0';
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        local_28[1] = local_28[0];
        local_28[2] = local_28[0];
        local_28[3] = local_28[0];
      }
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*(int *)Form1.PanelCadastro + 0x2fc))();
      SYSUTILS_SLEEP_LONGWORD();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*(int *)Form1.CadastroObrigatorio + 0x2fc))();
      SYSUTILS_SLEEP_LONGWORD();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*(int *)Form1.CodigodaMaquina + 0x2fc))();
      SYSUTILS_SLEEP_LONGWORD();
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(*(int *)Form1.NomeDoPonto + 0x2fc))();
      (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      CONTROLS_TCONTROL____REFRESH();
      SYSUTILS_SLEEP_LONGWORD();
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        aiStack_3c[local_8] = 0;
      } while (local_8 < 4);
      local_8 = 0;
      do {
        iVar3 = local_8 + 1;
        if (aiStack_3c[local_8 + 5] == 0) {
          aiStack_3c[1] = aiStack_3c[1] + 1;
        }
        if (aiStack_3c[local_8 + 5] == 1) {
          aiStack_3c[2] = aiStack_3c[2] + 1;
        }
        if (aiStack_3c[local_8 + 5] == 2) {
          aiStack_3c[3] = aiStack_3c[3] + 1;
        }
        if (aiStack_3c[local_8 + 5] == 3) {
          aiStack_3c[4] = aiStack_3c[4] + 1;
        }
        local_8 = iVar3;
      } while (iVar3 < 4);
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        if (aiStack_3c[local_8] == 1) {
          aiStack_3c[local_8] = 0;
        }
      } while (local_8 < 4);
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        local_14 = 0;
      } while (local_8 < 4);
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        if (aiStack_3c[local_8] == 3) {
          local_14 = 1;
        }
      } while (local_8 < 4);
      local_8 = 0;
      do {
        local_8 = local_8 + 1;
        if (aiStack_3c[local_8] == 4) {
          local_14 = 2;
        }
      } while (local_8 < 4);
      if (local_14 == 1) {
        if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
      }
      if (local_14 == 2) {
        if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
      }
      if (local_14 == 0) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
        if (cVar1 != '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
        }
        if ((U_JUKELINUX1_RESOLUCAO == 0x556) || (U_JUKELINUX1_RESOLUCAO == 0x5a0)) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
        if (U_JUKELINUX1_RESOLUCAO == 0x400) {
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
          if (cVar1 != '\0') {
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          }
        }
      }
      (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
      CONTROLS_TCONTROL____REFRESH();
      if (0 < local_14) {
        U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + local_14;
        fpc_ansistr_concat();
        FPC_ANSISTR_TO_SHORTSTR();
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        SYSTEM_REWRITE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        SYSTEM_FLUSH_TEXT();
        fpc_iocheck();
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
        if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          fpc_pchar_to_ansistr();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          fpc_pchar_to_ansistr();
          FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
        }
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        (**(code **)(*(int *)Form1.LabelUpgrade1 + 0xd8))();
        (**(code **)(*(int *)Form1.LabelUpgrade1 + 0xd8))();
        U_JUKELINUX1_MOSTRANDOCREDITO = 1;
      }
      SYSUTILS_SLEEP_LONGWORD();
      CONTROLS_TCONTROL____HIDE();
      if (U_JUKELINUX1_TOCANDOPALHINHA != '\0') {
        CONTROLS_TCONTROL____SHOW();
      }
      if (U_JUKELINUX1_TOCANDOMUSICADVD != '\0') {
        CONTROLS_TCONTROL____SHOW();
      }
      if (U_JUKELINUX1_TOCANDOVIDEOTV != '\0') {
        CONTROLS_TCONTROL____SHOW();
      }
      if (0 < U_JUKELINUX1_PULSOSPARASORTEIO) {
        (**(code **)(*(int *)Form1.LabelVE + 0xd8))();
      }
    }
    else {
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        JUKELINUX1_GRAVALOG_ANSISTRING();
      }
      iVar3 = fpc_ansistr_compare_equal();
      if (iVar3 == 0) {
        JUKELINUX1_GRAVALOG_ANSISTRING();
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
  local_18 = (undefined *)0x0;
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

