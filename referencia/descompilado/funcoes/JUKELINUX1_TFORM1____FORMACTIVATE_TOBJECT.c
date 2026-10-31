// JUKELINUX1_TFORM1_$__FORMACTIVATE$TOBJECT  @ 080c77e0

void JUKELINUX1_TFORM1____FORMACTIVATE_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int local_10;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    if (U_JUKELINUX1_ROTINA_DO_ACTIVATE == 1) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_concat();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      if (U_JUKELINUX1_ERROSERIALNUM == 0) {
        U_JUKELINUX1_ROTINA_DO_ACTIVATE = 2;
      }
      else {
        (**(code **)(**(int **)(in_EAX + 0xb0c) + 0x104))();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____SHOW();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        if (U_JUKELINUX1_ERROSERIALNUM == 9) {
          fpc_ansistr_decr_ref();
          U_JUKELINUX1_MUSICAGRATIS = __JUKELINUX1__Ld264;
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
          U_JUKELINUX1_ATIVACAO = __JUKELINUX1__Ld755;
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
      }
    }
    if (U_JUKELINUX1_ROTINA_DO_ACTIVATE == 2) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_concat();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      U_JUKELINUX1_OPC = 2;
      iVar3 = fpc_ansistr_compare_equal();
      if ((((iVar3 == 0) && (iVar3 = fpc_ansistr_compare_equal(), iVar3 == 0)) &&
          (iVar3 = fpc_ansistr_compare_equal(), iVar3 == 0)) &&
         (iVar3 = fpc_ansistr_compare_equal(), iVar3 == 0)) {
        U_JUKELINUX1_OPC = 1;
      }
      if (U_JUKELINUX1_OPC == 1) {
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
        JUKELINUX1_GRAVALOG_ANSISTRING();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
      }
      else {
        iVar3 = fpc_ansistr_compare_equal();
        U_JUKELINUX1_PENDRIVEZERADO = iVar3 == 0;
        if ((bool)U_JUKELINUX1_PENDRIVEZERADO) {
          JUKELINUX1_GRAVALOG_ANSISTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_concat();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_concat_multi();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_concat_multi();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_concat_multi();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          fpc_ansistr_decr_ref();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_decr_ref();
          JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
          fpc_ansistr_concat_multi();
          JUKELINUX1_GRAVALOG_ANSISTRING();
          JUKELINUX1_GRAVA_PENDRIVE_CONTADORES();
          JUKELINUX1_GRAVALOG_ANSISTRING();
        }
        else {
          iVar3 = fpc_ansistr_compare_equal();
          if (iVar3 == 0) {
            if (U_JUKELINUX1_JC_RELOGIOTOTAL < U_JUKELINUX1_RELOGIOTOTAL) {
              local_10 = 1;
            }
            if (U_JUKELINUX1_JC_RELOGIOGRATIS < U_JUKELINUX1_RELOGIOGRATIS) {
              local_10 = 1;
            }
            if (U_JUKELINUX1_JC_RELOGIOGRATISVIP < U_JUKELINUX1_RELOGIOGRATISVIP) {
              local_10 = 1;
            }
            if (U_JUKELINUX1_RELOGIOTOTAL < U_JUKELINUX1_JC_RELOGIOTOTAL) {
              local_10 = 2;
            }
            if (U_JUKELINUX1_RELOGIOPARCIAL < U_JUKELINUX1_JC_RELOGIOPARCIAL) {
              local_10 = 2;
            }
            if (U_JUKELINUX1_RELOGIOGRATIS < U_JUKELINUX1_JC_RELOGIOGRATIS) {
              local_10 = 2;
            }
            if (U_JUKELINUX1_RELOGIOGRATISVIP < U_JUKELINUX1_JC_RELOGIOGRATISVIP) {
              local_10 = 2;
            }
            if (local_10 == 1) {
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              JUKELINUX1_GRAVA_PENDRIVE_CONTADORES();
              JUKELINUX1_GRAVALOG_ANSISTRING();
            }
            if (local_10 == 2) {
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_incr_ref();
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_RELOGIOTOTALSTR = U_JUKELINUX1_JC_RELOGIOTOTALSTR;
              fpc_ansistr_incr_ref();
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_RELOGIOPARCIALSTR = U_JUKELINUX1_JC_RELOGIOPARCIALSTR;
              fpc_ansistr_incr_ref();
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_PORCENTAGEMDOPONTOSTR = U_JUKELINUX1_JC_PORCENTAGEMDOPONTOSTR;
              fpc_ansistr_incr_ref();
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_RELOGIOGRATISSTR = U_JUKELINUX1_JC_RELOGIOGRATISSTR;
              fpc_ansistr_incr_ref();
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_RELOGIOGRATISVIPSTR = U_JUKELINUX1_JC_RELOGIOGRATISVIPSTR;
              U_JUKELINUX1_RELOGIOTOTAL = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
              U_JUKELINUX1_RELOGIOPARCIAL = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
              U_JUKELINUX1_PORCENTAGEMDOPONTO = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
              U_JUKELINUX1_RELOGIOGRATIS = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
              U_JUKELINUX1_RELOGIOGRATISVIP = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
              JUKELINUX1_GRAVA_HD_RELOGIOS();
              JUKELINUX1_GRAVA_HD_PORCENTAGEM();
              JUKELINUX1_GRAVA_HD_RELOGIOGRATIS();
              JUKELINUX1_GRAVA_HD_RELOGIOGRATISVIP();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
              fpc_ansistr_decr_ref();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_decr_ref();
              JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
              fpc_ansistr_concat_multi();
              JUKELINUX1_GRAVALOG_ANSISTRING();
            }
          }
          else {
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_RELOGIOTOTALSTR = U_JUKELINUX1_JC_RELOGIOTOTALSTR;
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_RELOGIOPARCIALSTR = U_JUKELINUX1_JC_RELOGIOPARCIALSTR;
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_PORCENTAGEMDOPONTOSTR = U_JUKELINUX1_JC_PORCENTAGEMDOPONTOSTR;
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_RELOGIOGRATISSTR = U_JUKELINUX1_JC_RELOGIOGRATISSTR;
            fpc_ansistr_incr_ref();
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_RELOGIOGRATISVIPSTR = U_JUKELINUX1_JC_RELOGIOGRATISVIPSTR;
            U_JUKELINUX1_RELOGIOTOTAL = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
            U_JUKELINUX1_RELOGIOPARCIAL = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
            U_JUKELINUX1_PORCENTAGEMDOPONTO = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
            U_JUKELINUX1_RELOGIOGRATIS = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
            U_JUKELINUX1_RELOGIOGRATISVIP = SYSUTILS_STRTOINTDEF_ANSISTRING_LONGINT__LONGINT();
            JUKELINUX1_GRAVA_HD_RELOGIOS();
            JUKELINUX1_GRAVA_HD_PORCENTAGEM();
            JUKELINUX1_GRAVA_HD_RELOGIOGRATIS();
            JUKELINUX1_GRAVA_HD_RELOGIOGRATISVIP();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_decr_ref();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_decr_ref();
            JUKELINUX1_STRZERO_ANSISTRING_LONGINT__ANSISTRING();
            fpc_ansistr_concat_multi();
            JUKELINUX1_GRAVALOG_ANSISTRING();
            fpc_ansistr_concat();
            FPC_ANSISTR_TO_SHORTSTR();
            OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
            SYSTEM_REWRITE_TEXT();
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
            fpc_ansistr_decr_ref();
            fpc_ansistr_concat();
            JUKELINUX1_GRAVALOG_ANSISTRING();
          }
        }
      }
      U_JUKELINUX1_ROTINA_DO_ACTIVATE = 3;
    }
    if (U_JUKELINUX1_ROTINA_DO_ACTIVATE == 3) {
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_concat();
      JUKELINUX1_GRAVALOG_ANSISTRING();
      (**(code **)(**(int **)(in_EAX + 0xb14) + 0x21c))();
      CONTROLS_TCONTROL____BRINGTOFRONT();
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      CONTROLS_TCONTROL____SETWIDTH_LONGINT();
      CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      (**(code **)(**(int **)(in_EAX + 0xac4) + 0x10c))();
      (**(code **)(**(int **)(in_EAX + 0xac4) + 0x104))();
      CONTROLS_TCONTROL____SETWIDTH_LONGINT();
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      STDCTRLS_TCUSTOMLABEL____SETALIGNMENT_TALIGNMENT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      (**(code **)(**(int **)(in_EAX + 0xac8) + 0x10c))();
      (**(code **)(**(int **)(in_EAX + 0xac8) + 0x104))();
      CONTROLS_TCONTROL____SETWIDTH_LONGINT();
      CONTROLS_TCONTROL____SETLEFT_LONGINT();
      STDCTRLS_TCUSTOMLABEL____SETALIGNMENT_TALIGNMENT();
      CONTROLS_TCONTROL____SETTOP_LONGINT();
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      U_JUKELINUX1_TEMPOABERTURA = 5;
      fpc_ansistr_decr_ref();
      fpc_ansistr_concat();
      cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
      if (cVar1 != '\0') {
        U_JUKELINUX1_TEMPOABERTURA = 1;
      }
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      U_JUKELINUX1_TELAABERTURA = 1;
      CONTROLS_TCONTROL____SHOW();
      (**(code **)(**(int **)(in_EAX + 0xb14) + 0x2fc))();
      U_JUKELINUX1_PRESSIONADOTECLA = 0;
      U_JUKELINUX1_TOCANDOMUSICA = 0;
      U_JUKELINUX1_TOCANDOMUSICADVD = 0;
      U_JUKELINUX1_TOCANDOMUSICAGRATIS = 0;
      U_JUKELINUX1_ROTINA_DO_ACTIVATE = 4;
    }
    if (U_JUKELINUX1_ROTINA_DO_ACTIVATE == 4) {
      (**(code **)(**(int **)(in_EAX + 0xbc4) + 0xd8))();
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
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

