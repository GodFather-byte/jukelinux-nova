// JUKELINUX1_TFORM1_$__COMBOBOX1CHANGE$TOBJECT  @ 080d9ed0

void JUKELINUX1_TFORM1____COMBOBOX1CHANGE_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    U_JUKELINUX1_OKC = 0;
    iVar2 = (**(code **)(**(int **)(*(int *)(in_EAX + 0x6a4) + 0x36c) + 0x80))();
    U_JUKELINUX1_KKC = 0;
    if (-1 < iVar2 + -1) {
      U_JUKELINUX1_KKC = -1;
      do {
        U_JUKELINUX1_KKC = U_JUKELINUX1_KKC + 1;
        fpc_ansistr_decr_ref();
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        fpc_ansistr_decr_ref();
        (**(code **)(**(int **)(*(int *)(in_EAX + 0x6a4) + 0x36c) + 0x78))();
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          U_JUKELINUX1_OKC = 1;
        }
      } while (U_JUKELINUX1_KKC < iVar2 + -1);
    }
    if (U_JUKELINUX1_OKC == 1) {
      fpc_ansistr_decr_ref();
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_KR1 = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_KR1 < 0x14) {
          U_JUKELINUX1_KR1 = U_JUKELINUX1_KR1 + 0x14;
        }
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_KR2 = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_KR2 < 0x14) {
          U_JUKELINUX1_KR2 = U_JUKELINUX1_KR2 + 0x24;
        }
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_KR3 = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_KR3 < 0x14) {
          U_JUKELINUX1_KR3 = U_JUKELINUX1_KR3 + 0x16;
        }
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_KR4 = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_KR4 < 0x14) {
          U_JUKELINUX1_KR4 = U_JUKELINUX1_KR4 + 0x13;
        }
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_KR5 = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_KR5 < 0x14) {
          U_JUKELINUX1_KR5 = U_JUKELINUX1_KR5 + 0x27;
        }
        SYSTEM_RANDOMIZE();
        U_JUKELINUX1_KR6 = SYSTEM_RANDOM_LONGINT__LONGINT();
        if (U_JUKELINUX1_KR6 < 0x14) {
          U_JUKELINUX1_KR6 = U_JUKELINUX1_KR6 + 0x17;
        }
        if (U_JUKELINUX1_KR1 == U_JUKELINUX1_KR2) {
          U_JUKELINUX1_KR2 = U_JUKELINUX1_KR2 + 0xd;
        }
        if (100 < U_JUKELINUX1_KR2) {
          U_JUKELINUX1_KR2 = U_JUKELINUX1_KR2 + -0x19;
        }
        if (100 < U_JUKELINUX1_KR2) {
          U_JUKELINUX1_KR2 = 0x14;
        }
        if (U_JUKELINUX1_KR3 == U_JUKELINUX1_KR4) {
          U_JUKELINUX1_KR3 = U_JUKELINUX1_KR3 + 0x13;
        }
        if (100 < U_JUKELINUX1_KR4) {
          U_JUKELINUX1_KR4 = U_JUKELINUX1_KR4 + -0x1c;
        }
        if (100 < U_JUKELINUX1_KR4) {
          U_JUKELINUX1_KR4 = 0x1e;
        }
        if (U_JUKELINUX1_KR5 == U_JUKELINUX1_KR6) {
          U_JUKELINUX1_KR5 = U_JUKELINUX1_KR5 + 0xd;
        }
        if (100 < U_JUKELINUX1_KR6) {
          U_JUKELINUX1_KR6 = U_JUKELINUX1_KR6 + -0x1d;
        }
        if (100 < U_JUKELINUX1_KR6) {
          U_JUKELINUX1_KR2 = 0x28;
        }
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_ATIVACAO = __JUKELINUX1__Ld793;
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____HIDE();
        (**(code **)(**(int **)(in_EAX + 0xb18) + 0x104))();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        (**(code **)(**(int **)(in_EAX + 0x9c0) + 0x430))();
      }
      else {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        FPC_ANSISTR_TO_SHORTSTR();
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        SYSTEM_REWRITE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        fpc_ansistr_incr_ref();
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_REAISXMUSICAS = 0;
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        SYSTEM_FLUSH_TEXT();
        fpc_iocheck();
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
      }
    }
    else {
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
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
  if (iVar1 != 0) {
    fpc_reraise();
  }
  return;
}

