// JUKELINUX1_CARTAOCODBAR_BAR  @ 080b4080

void JUKELINUX1_CARTAOCODBAR_BAR(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined1 **ppuVar4;
  undefined1 **ppuVar5;
  int aiStack_378 [3];
  undefined1 *puStack_36c;
  int iStack_368;
  undefined1 local_248 [256];
  undefined1 local_148 [296];
  undefined1 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_8;
  
  iStack_368 = 0x80b40d7;
  fpc_pushexceptaddr();
  iStack_368 = 0x80b40dc;
  iStack_368 = fpc_setjmp();
  ppuVar5 = (undefined1 **)&iStack_368;
  if (iStack_368 == 0) {
    puStack_36c = local_148;
    fpc_shortstr_copy();
    FPC_SHORTSTR_TO_SHORTSTR();
    iVar3 = U_JUKELINUX1_TOTMMCARTAO;
    ppuVar5 = &puStack_36c;
    ppuVar4 = &puStack_36c;
    if (U_JUKELINUX1_CODIGODOCARTAO == '\b') {
      local_8 = '\0';
      local_c = 1;
      ppuVar5 = &puStack_36c;
      if (0 < U_JUKELINUX1_TOTMMCARTAO) {
        local_c = 0;
        do {
          local_c = local_c + 1;
          *(undefined1 **)((int)ppuVar4 + -4) = local_148;
          *(undefined4 *)((int)ppuVar4 + -8) = 0x80b415e;
          fpc_shortstr_copy();
          *(undefined1 **)((int)ppuVar4 + -8) = local_248;
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80b4186;
          fpc_shortstr_copy();
          *(undefined4 *)((int)ppuVar4 + -0xc) = 0x80b4193;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          ppuVar5 = (undefined1 **)((int)ppuVar4 + -8);
          ppuVar4 = (undefined1 **)((int)ppuVar4 + -8);
          if (iVar2 == 0) {
            local_1c = local_c;
            local_8 = '\x01';
          }
        } while (local_c < iVar3);
      }
      if (local_8 != '\0') {
        if (U_JUKELINUX1_ESTANOMENU == '\0') {
          if (U_JUKELINUX1_PULSOSPARACARTAO == 0) {
            *(undefined4 *)((int)ppuVar5 + -4) = 0x80b41d5;
            fpc_ansistr_decr_ref();
            *(undefined4 *)((int)ppuVar5 + -4) = 0x80b41f6;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4201;
            U_JUKELINUX1_CREDITOSCARTAO = JUKELINUX1_LECREDITODOCARTAO_ANSISTRING__LONGINT();
            if (U_JUKELINUX1_CREDITOSCARTAO < 1) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b46e9;
              CONTROLS_TCONTROL____SETLEFT_LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4704;
              CONTROLS_TCONTROL____SETTOP_LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b471f;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b472f;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b473f;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b474f;
              CONTROLS_TCONTROL____SHOW();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b475f;
              CONTROLS_TCONTROL____BRINGTOFRONT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b476f;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b478e;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4799;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b47b3;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b47c9;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b47d4;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b47f4;
              CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b480a;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              local_14 = 0;
              do {
                local_14 = local_14 + 1;
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4839;
                CONTROLS_TCONTROL____SETTOP_LONGINT();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4849;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4868;
                (*pcVar1)();
              } while (local_14 < 0x96);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b487c;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4896;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b48ac;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b48b7;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b48d7;
              CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b48ed;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4908;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4918;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.ImgLanMais2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4937;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4947;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.BS8 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4966;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4976;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4995;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b499f;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b49b2;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b49bc;
              SYSUTILS_SLEEP_LONGWORD();
              local_14 = 0;
              do {
                local_14 = local_14 + 1;
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b49ed;
                CONTROLS_TCONTROL____SETTOP_LONGINT();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b49fd;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4a1c;
                (*pcVar1)();
              } while (local_14 < 0x96);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4a35;
              CONTROLS_TCONTROL____HIDE();
            }
            else {
              pcVar1 = *(code **)(*(int *)Form1.LabelUpgrade1 + 0xd8);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b422f;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b423f;
              CONTROLS_TCONTROL____SHOW();
              pcVar1 = *(code **)(*(int *)Form1.PanelExcluirMusica + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b425e;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4279;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b42a0;
              CONTROLS_TCONTROL____SETLEFT_LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b42bb;
              CONTROLS_TCONTROL____SETTOP_LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b42d6;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b42e6;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b42f6;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4306;
              CONTROLS_TCONTROL____SHOW();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4316;
              CONTROLS_TCONTROL____BRINGTOFRONT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4326;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4345;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4350;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b436a;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4380;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b438b;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b43ab;
              CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b43c1;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              local_14 = 0;
              do {
                local_14 = local_14 + 1;
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b43f1;
                CONTROLS_TCONTROL____SETTOP_LONGINT();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4401;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4420;
                (*pcVar1)();
              } while (local_14 < 0x96);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4433;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4446;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4450;
              SYSUTILS_SLEEP_LONGWORD();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b445f;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSCARTAO = U_JUKELINUX1_CREDITOSCARTAO + -1;
                local_18 = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b447f;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSCARTAO = U_JUKELINUX1_CREDITOSCARTAO + -1;
                local_18 = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b449f;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSCARTAO = U_JUKELINUX1_CREDITOSCARTAO + -2;
                local_18 = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b44bc;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b44d6;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b44ec;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b44f7;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4517;
              CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b452d;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4548;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4558;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.ImgLanMais2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4577;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4587;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.BS8 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b45a6;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b45b0;
              JUKELINUX1_ROTINA_CREDITOS_ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b45c0;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b45e1;
              fpc_shortstr_to_ansistr();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b45ee;
              JUKELINUX1_GRAVACREDITONOCARTAO_ANSISTRING_LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b45fe;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b461d;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4627;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b463a;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4644;
              SYSUTILS_SLEEP_LONGWORD();
              local_14 = 0;
              do {
                local_14 = local_14 + 1;
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4675;
                CONTROLS_TCONTROL____SETTOP_LONGINT();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4685;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b46a4;
                (*pcVar1)();
              } while (local_14 < 0x96);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b46bd;
              CONTROLS_TCONTROL____HIDE();
            }
          }
          else if (U_JUKELINUX1_CREDITOS < 1) {
            U_JUKELINUX1_PULSOSPARACARTAO = 0;
          }
          else {
            local_20 = 0;
            if (U_JUKELINUX1_PULSOSPARACARTAO == 1) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4a68;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 1;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4a8f;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 2;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4ab6;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 2) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4aef;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 2;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4b16;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 4;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4b3d;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 1;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 3) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4b76;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 3;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4b9d;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 6;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4bc4;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 1;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 4) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4bfd;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 4;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4c24;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 8;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4c4b;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 2;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 5) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4c84;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 5;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4cab;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 10;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4cd2;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 2;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 6) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4d0b;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 6;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4d32;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0xc;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4d59;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 3;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 7) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4d92;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 6;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4db9;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0xe;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4de0;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 3;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 8) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4e19;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 8;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4e40;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x10;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4e67;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 4;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 9) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4ea0;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 9;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4ec7;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x12;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4eee;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 4;
                U_JUKELINUX1_CREDITOSBONUS = 0;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 10) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4f27;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 10;
                U_JUKELINUX1_CREDITOSBONUS = 2;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4f4e;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x14;
                U_JUKELINUX1_CREDITOSBONUS = 3;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4f75;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 5;
                U_JUKELINUX1_CREDITOSBONUS = 1;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 0x14) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4fae;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x14;
                U_JUKELINUX1_CREDITOSBONUS = 5;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4fd5;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x28;
                U_JUKELINUX1_CREDITOSBONUS = 10;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b4ffc;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 10;
                U_JUKELINUX1_CREDITOSBONUS = 2;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 0x32) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5035;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x32;
                U_JUKELINUX1_CREDITOSBONUS = 10;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b505c;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 100;
                U_JUKELINUX1_CREDITOSBONUS = 0x14;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5083;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x19;
                U_JUKELINUX1_CREDITOSBONUS = 5;
              }
              local_20 = 1;
            }
            if (U_JUKELINUX1_PULSOSPARACARTAO == 100) {
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b50bc;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 100;
                U_JUKELINUX1_CREDITOSBONUS = 0x14;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b50e3;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 200;
                U_JUKELINUX1_CREDITOSBONUS = 0x28;
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b510a;
              iVar3 = fpc_ansistr_compare_equal();
              if (iVar3 == 0) {
                U_JUKELINUX1_CREDITOSPARACARTAO = 0x32;
                U_JUKELINUX1_CREDITOSBONUS = 10;
              }
              local_20 = 1;
            }
            if (0 < U_JUKELINUX1_CREDITOSPARACARTAO) {
              pcVar1 = *(code **)(*(int *)Form1.LabelUpgrade1 + 0xd8);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5162;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5172;
              CONTROLS_TCONTROL____SHOW();
              pcVar1 = *(code **)(*(int *)Form1.PanelExcluirMusica + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5191;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b51ac;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b51b7;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b51d8;
              fpc_shortstr_to_ansistr();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b51e3;
              U_JUKELINUX1_CREDITOSCARTAO = JUKELINUX1_LECREDITODOCARTAO_ANSISTRING__LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b520f;
              CONTROLS_TCONTROL____SETLEFT_LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b522a;
              CONTROLS_TCONTROL____SETTOP_LONGINT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5245;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5255;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5265;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5275;
              CONTROLS_TCONTROL____SHOW();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5285;
              CONTROLS_TCONTROL____BRINGTOFRONT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5295;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b52b4;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b52bf;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b52d9;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b52ef;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b52fa;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b531a;
              CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5330;
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              local_14 = 0;
              do {
                local_14 = local_14 + 1;
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5361;
                CONTROLS_TCONTROL____SETTOP_LONGINT();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5371;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5390;
                (*pcVar1)();
              } while (local_14 < 0x96);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b53a3;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b53b6;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b53c0;
              SYSUTILS_SLEEP_LONGWORD();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b53d0;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b53e0;
              CONTROLS_TCONTROL____HIDE();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b53eb;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b540c;
              fpc_shortstr_to_ansistr();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5425;
              JUKELINUX1_GRAVACREDITONOCARTAO_ANSISTRING_LONGINT();
              iVar3 = U_JUKELINUX1_CREDITOSPARACARTAO;
              local_10 = 1;
              if (0 < U_JUKELINUX1_CREDITOSPARACARTAO) {
                local_10 = 0;
                do {
                  local_10 = local_10 + 1;
                  U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + -1;
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5454;
                  fpc_ansistr_decr_ref();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b546e;
                  SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5484;
                  CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b549f;
                  GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
                  U_JUKELINUX1_CREDITOSCARTAO = U_JUKELINUX1_CREDITOSCARTAO + 1;
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b54b0;
                  fpc_ansistr_decr_ref();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b54ca;
                  SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b54e0;
                  CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b54eb;
                  fpc_ansistr_decr_ref();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b550b;
                  CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5521;
                  CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b553c;
                  GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b554c;
                  CONTROLS_TCONTROL____REFRESH();
                  pcVar1 = *(code **)(*(int *)Form1.ImgLanMais2 + 0x2fc);
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b556b;
                  (*pcVar1)();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b557b;
                  CONTROLS_TCONTROL____REFRESH();
                  pcVar1 = *(code **)(*(int *)Form1.BS8 + 0x2fc);
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b559a;
                  (*pcVar1)();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b55a4;
                  CONTROLS_TCONTROL____REFRESH();
                  pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b55b7;
                  (*pcVar1)();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b55c1;
                  SYSUTILS_SLEEP_LONGWORD();
                  *(undefined4 *)((int)ppuVar5 + -4) = 0x80b55c6;
                  JUKELINUX1_PRESSTECLA();
                } while (local_10 < iVar3);
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b55ea;
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b55fa;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5619;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5623;
              CONTROLS_TCONTROL____REFRESH();
              pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5636;
              (*pcVar1)();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b564b;
              fpc_ansistr_concat();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5661;
              FPC_ANSISTR_TO_SHORTSTR();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5671;
              OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b567b;
              SYSTEM_REWRITE_TEXT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5680;
              fpc_iocheck();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b568b;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56a0;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56ba;
              SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56cb;
              JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56e0;
              fpc_write_text_ansistr();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56e5;
              fpc_iocheck();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56ef;
              fpc_writeln_end();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56f4;
              fpc_iocheck();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b56ff;
              fpc_ansistr_decr_ref();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5719;
              JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b572e;
              fpc_write_text_ansistr();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5733;
              fpc_iocheck();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b573d;
              fpc_writeln_end();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5742;
              fpc_iocheck();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b574c;
              SYSTEM_FLUSH_TEXT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5751;
              fpc_iocheck();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b575b;
              OBJPAS_CLOSEFILE_TEXT();
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5760;
              fpc_iocheck();
              if (U_JUKELINUX1_SEMPENDRIVE == '\0') {
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5778;
                fpc_ansistr_decr_ref();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b578d;
                fpc_ansistr_decr_ref();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b57ad;
                fpc_ansistr_concat();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b57c7;
                fpc_pchar_to_ansistr();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b57d8;
                fpc_ansistr_decr_ref();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b57ed;
                fpc_ansistr_decr_ref();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b580d;
                fpc_ansistr_concat();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5827;
                fpc_pchar_to_ansistr();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5836;
                FILEUTIL_COPYFILE_ANSISTRING_ANSISTRING_BOOLEAN__BOOLEAN();
              }
              if (0 < U_JUKELINUX1_CREDITOSBONUS) {
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b584d;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5860;
                (*pcVar1)();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b586a;
                SYSUTILS_SLEEP_LONGWORD();
                iVar3 = U_JUKELINUX1_CREDITOSBONUS;
                local_10 = 1;
                if (0 < U_JUKELINUX1_CREDITOSBONUS) {
                  local_10 = 0;
                  do {
                    local_10 = local_10 + 1;
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5897;
                    CONTROLS_TCONTROL____SHOW();
                    U_JUKELINUX1_CREDITOSCARTAO = U_JUKELINUX1_CREDITOSCARTAO + 1;
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b58a8;
                    fpc_ansistr_decr_ref();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b58c2;
                    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b58d8;
                    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b58e3;
                    fpc_ansistr_decr_ref();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5903;
                    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5919;
                    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5934;
                    GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5944;
                    CONTROLS_TCONTROL____REFRESH();
                    pcVar1 = *(code **)(*(int *)Form1.ImgLanMais2 + 0x2fc);
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5963;
                    (*pcVar1)();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5973;
                    CONTROLS_TCONTROL____REFRESH();
                    pcVar1 = *(code **)(*(int *)Form1.BS8 + 0x2fc);
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5992;
                    (*pcVar1)();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b599c;
                    CONTROLS_TCONTROL____REFRESH();
                    pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b59af;
                    (*pcVar1)();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b59b9;
                    SYSUTILS_SLEEP_LONGWORD();
                    *(undefined4 *)((int)ppuVar5 + -4) = 0x80b59be;
                    JUKELINUX1_PRESSTECLA();
                  } while (local_10 < iVar3);
                }
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b59d7;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b59f6;
                (*pcVar1)();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5a00;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5a13;
                (*pcVar1)();
              }
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5a1d;
              SYSUTILS_SLEEP_LONGWORD();
              local_14 = 0;
              do {
                local_14 = local_14 + 1;
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5a4d;
                CONTROLS_TCONTROL____SETTOP_LONGINT();
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5a5d;
                CONTROLS_TCONTROL____REFRESH();
                pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
                *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5a7c;
                (*pcVar1)();
              } while (local_14 < 0x96);
              *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5a95;
              CONTROLS_TCONTROL____HIDE();
              U_JUKELINUX1_CREDITOSPARACARTAO = 0;
              U_JUKELINUX1_CREDITOSBONUS = 0;
              U_JUKELINUX1_PULSOSPARACARTAO = 0;
            }
          }
        }
        else {
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5ad2;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5af3;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5afe;
          U_JUKELINUX1_CREDITOSCARTAO = JUKELINUX1_LECREDITODOCARTAO_ANSISTRING__LONGINT();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5b2a;
          CONTROLS_TCONTROL____SETLEFT_LONGINT();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5b45;
          CONTROLS_TCONTROL____SETTOP_LONGINT();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5b60;
          GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5b70;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5b80;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5b90;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5ba0;
          CONTROLS_TCONTROL____BRINGTOFRONT();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5bb0;
          CONTROLS_TCONTROL____REFRESH();
          pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5bcf;
          (*pcVar1)();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5bda;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5bf4;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5c0a;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5c15;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5c35;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5c4b;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          local_14 = 0;
          do {
            local_14 = local_14 + 1;
            *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5c7d;
            CONTROLS_TCONTROL____SETTOP_LONGINT();
            *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5c8d;
            CONTROLS_TCONTROL____REFRESH();
            pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
            *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5cac;
            (*pcVar1)();
          } while (local_14 < 0x96);
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5cbf;
          CONTROLS_TCONTROL____REFRESH();
          pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5cd2;
          (*pcVar1)();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5cdc;
          SYSUTILS_SLEEP_LONGWORD();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5cec;
          CONTROLS_TCONTROL____SHOW();
          U_JUKELINUX1_CREDITOSCARTAO = U_JUKELINUX1_CREDITOSCARTAO + 2;
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5cfe;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5d18;
          SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5d2e;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5d39;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5d59;
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5d6f;
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5d8a;
          GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5d9a;
          CONTROLS_TCONTROL____REFRESH();
          pcVar1 = *(code **)(*(int *)Form1.ImgLanMais2 + 0x2fc);
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5db9;
          (*pcVar1)();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5dc9;
          CONTROLS_TCONTROL____REFRESH();
          pcVar1 = *(code **)(*(int *)Form1.BS8 + 0x2fc);
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5de8;
          (*pcVar1)();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5df3;
          fpc_ansistr_decr_ref();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e14;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e24;
          JUKELINUX1_GRAVACREDITONOCARTAO_ANSISTRING_LONGINT();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e34;
          CONTROLS_TCONTROL____REFRESH();
          pcVar1 = *(code **)(*(int *)Form1.LabelE2 + 0x2fc);
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e53;
          (*pcVar1)();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e5d;
          CONTROLS_TCONTROL____REFRESH();
          pcVar1 = *(code **)(*U_JUKELINUX1_FORM1 + 0x2fc);
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e70;
          (*pcVar1)();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e7a;
          SYSUTILS_SLEEP_LONGWORD();
          *(undefined4 *)((int)ppuVar5 + -4) = 0x80b5e8a;
          CONTROLS_TCONTROL____HIDE();
          U_JUKELINUX1_PULSOSPARACARTAO = 0;
        }
      }
    }
    U_JUKELINUX1_CODIGODOCARTAO = '\0';
    U_JUKELINUX1_LENDOCODIGODOCARTAO = 0;
  }
  ppuVar5[-1] = (undefined1 *)0x80b5eaa;
  fpc_popaddrstack();
  ppuVar5[-1] = (undefined1 *)0x80b5eb5;
  fpc_ansistr_decr_ref();
  ppuVar5[-1] = (undefined1 *)0x80b5eca;
  fpc_ansistr_decr_ref();
  ppuVar5[-1] = (undefined1 *)0x80b5edf;
  fpc_ansistr_decr_ref();
  ppuVar5[-1] = (undefined1 *)0x80b5ef4;
  fpc_ansistr_decr_ref();
  ppuVar5[-1] = (undefined1 *)0x80b5f09;
  fpc_ansistr_decr_ref();
  if (*ppuVar5 != (undefined1 *)0x0) {
    *ppuVar5 = (undefined1 *)0x80b5f1d;
    fpc_reraise();
  }
  return;
}

