// JUKELINUX1_MOSTRA_CDS$ANSISTRING  @ 080a4f80

/* WARNING: Removing unreachable block (ram,0x080a9160) */
/* WARNING: Removing unreachable block (ram,0x080a9171) */
/* WARNING: Removing unreachable block (ram,0x080a9184) */
/* WARNING: Removing unreachable block (ram,0x080a918a) */
/* WARNING: Removing unreachable block (ram,0x080a919d) */
/* WARNING: Removing unreachable block (ram,0x080a91a3) */
/* WARNING: Removing unreachable block (ram,0x080a91b4) */
/* WARNING: Removing unreachable block (ram,0x080a91c7) */
/* WARNING: Removing unreachable block (ram,0x080a91cd) */
/* WARNING: Removing unreachable block (ram,0x080a91e0) */

void JUKELINUX1_MOSTRA_CDS_ANSISTRING(void)

{
  code *pcVar1;
  int iVar2;
  int **ppiVar3;
  int **ppiVar4;
  int *piVar5;
  int *piStack_4c;
  int *piStack_48;
  int *piStack_44;
  int *piStack_40;
  int aiStack_3c [14];
  
  aiStack_3c[0] = 0x80a4f8e;
  fpc_ansistr_incr_ref();
  aiStack_3c[1] = 0;
  aiStack_3c[2] = 0;
  aiStack_3c[0] = 0x80a4fac;
  fpc_pushexceptaddr();
  aiStack_3c[0] = 0x80a4fb1;
  aiStack_3c[0] = fpc_setjmp();
  piVar5 = aiStack_3c;
  if (aiStack_3c[0] != 0) goto LAB_080a91e6;
  piStack_40 = (int *)0x80a4fc2;
  fpc_ansistr_decr_ref();
  aiStack_3c[2] = 0;
  piStack_40 = aiStack_3c + 2;
  piStack_44 = (int *)0x80a4fe1;
  fpc_ansistr_copy();
  piStack_44 = (int *)0x80a4fee;
  iVar2 = fpc_ansistr_compare_equal();
  ppiVar4 = &piStack_40;
  if (iVar2 == 0) {
    if (U_JUKELINUX1_TRAVADODENTRODORITMO == 0) {
      piStack_44 = (int *)0x80a500b;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_44 = (int *)0x80a502e;
      fpc_shortstr_to_ansistr();
      piStack_44 = (int *)0x80a5036;
      fpc_ansistr_incr_ref();
      piStack_44 = (int *)0x80a5040;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_TRAVADODENTRODORITMO = aiStack_3c[2];
      piStack_44 = (int *)0x80a5050;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_44 = (int *)0x80a5073;
      fpc_shortstr_to_ansistr();
      piStack_44 = (int *)0x80a507b;
      fpc_ansistr_incr_ref();
      piStack_44 = (int *)0x80a5085;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_RITMODOCD = aiStack_3c[2];
    }
    piStack_44 = (int *)0x80a509a;
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      piStack_44 = (int *)0x80a50aa;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_44 = (int *)0x80a50cd;
      fpc_shortstr_to_ansistr();
      piStack_44 = (int *)0x80a50d5;
      fpc_ansistr_incr_ref();
      piStack_44 = (int *)0x80a50df;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_TRAVADODENTRODORITMO = aiStack_3c[2];
      piStack_44 = (int *)0x80a50ef;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_44 = (int *)0x80a5112;
      fpc_shortstr_to_ansistr();
      piStack_44 = (int *)0x80a511a;
      fpc_ansistr_incr_ref();
      piStack_44 = (int *)0x80a5124;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_RITMODOCD = aiStack_3c[2];
    }
    piStack_44 = (int *)0x80a5134;
    fpc_ansistr_decr_ref();
    aiStack_3c[2] = 0;
    piStack_44 = (int *)0x80a5157;
    fpc_shortstr_to_ansistr();
    piStack_44 = (int *)0x80a515f;
    fpc_ansistr_incr_ref();
    piStack_44 = (int *)0x80a5169;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_RITMODOCD = aiStack_3c[2];
    U_JUKELINUX1_MMCCDDSS = '\0';
    piStack_44 = (int *)0x80a5188;
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      U_JUKELINUX1_MMCCDDSS = '\x01';
    }
    piStack_44 = (int *)0x80a51a2;
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      U_JUKELINUX1_MMCCDDSS = '\x01';
      piStack_44 = (int *)0x80a51b9;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_44 = (int *)0x80a51dc;
      fpc_shortstr_to_ansistr();
      piStack_44 = (int *)0x80a51e4;
      fpc_ansistr_incr_ref();
      piStack_44 = (int *)0x80a51ee;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_TRAVADODENTRODORITMO = aiStack_3c[2];
      piStack_44 = (int *)0x80a51fe;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_44 = (int *)0x80a5221;
      fpc_shortstr_to_ansistr();
      piStack_44 = (int *)0x80a5229;
      fpc_ansistr_incr_ref();
      piStack_44 = (int *)0x80a5233;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_RITMODOCD = aiStack_3c[2];
    }
    if (U_JUKELINUX1_MMCCDDSS == '\0') {
      piStack_44 = (int *)0x80a72c3;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        piStack_44 = (int *)0x80a72d6;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + 1;
        }
        piStack_44 = (int *)0x80a72ef;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + -1;
        }
      }
      piStack_44 = (int *)0x80a7306;
      iVar2 = fpc_ansistr_compare_equal();
      ppiVar4 = &piStack_40;
      if (iVar2 == 0) {
        piStack_44 = (int *)0x80a7319;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + -1;
        }
        piStack_44 = (int *)0x80a7332;
        iVar2 = fpc_ansistr_compare_equal();
        ppiVar4 = &piStack_40;
        if (iVar2 == 0) {
          U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + 1;
          ppiVar4 = &piStack_40;
        }
      }
    }
    else {
      if (U_JUKELINUX1_SEGURANDOTECLA < 8) {
        U_JUKELINUX1_MOSTRAPAGINANDOCDS = '\x01';
      }
      else if (0xe < U_JUKELINUX1_SEGURANDOTECLA) {
        piStack_44 = (int *)0x80a5274;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_MOSTRAPAGINANDOCDS = '\0';
        }
        else {
          U_JUKELINUX1_MOSTRAPAGINANDOCDS = '\x01';
        }
      }
      if (U_JUKELINUX1_MOSTRAPAGINANDOCDS != '\0') {
        if (U_JUKELINUX1_KMAT < 1) {
LAB_080a5430:
          piStack_44 = (int *)0x80a5440;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a5450;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a5460;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          piStack_44 = (int *)0x80a52aa;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a52ca;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a52d8;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a5430;
          piStack_44 = (int *)0x80a52f2;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          piStack_44 = (int *)0x80a531a;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          piStack_44 = (int *)0x80a532a;
          CONTROLS_TCONTROL____SHOW();
          piStack_44 = (int *)0x80a5345;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a5359;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a536b;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a5373;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a5393;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a53a0;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a53b4;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a53c6;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a53ce;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a53ee;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a53fb;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a541a;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              piStack_44 = (int *)0x80a542e;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (U_JUKELINUX1_KMAT + 1 < 1) {
LAB_080a5602:
          piStack_44 = (int *)0x80a5612;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a5622;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a5632;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          piStack_44 = (int *)0x80a5476;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a5497;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a54a5;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a5602;
          piStack_44 = (int *)0x80a54bf;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          piStack_44 = (int *)0x80a54e8;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          piStack_44 = (int *)0x80a54f8;
          CONTROLS_TCONTROL____SHOW();
          piStack_44 = (int *)0x80a5514;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a5528;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a553a;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a5542;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a5563;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a5570;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a5584;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a5596;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a559e;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a55bf;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a55cc;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a55ec;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              piStack_44 = (int *)0x80a5600;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (U_JUKELINUX1_KMAT + 2 < 1) {
LAB_080a57e2:
          piStack_44 = (int *)0x80a57f2;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a5802;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a5812;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          piStack_44 = (int *)0x80a564a;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a566d;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a567b;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a57e2;
          piStack_44 = (int *)0x80a5695;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          piStack_44 = (int *)0x80a56c0;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          piStack_44 = (int *)0x80a56d0;
          CONTROLS_TCONTROL____SHOW();
          piStack_44 = (int *)0x80a56ee;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a5702;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a5714;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a571c;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a573f;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a574c;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a5760;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a5772;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a577a;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a579d;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a57aa;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a57cc;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              piStack_44 = (int *)0x80a57e0;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (U_JUKELINUX1_KMAT + 3 < 1) {
LAB_080a59c2:
          piStack_44 = (int *)0x80a59d2;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a59e2;
          CONTROLS_TCONTROL____HIDE();
          piStack_44 = (int *)0x80a59f2;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          piStack_44 = (int *)0x80a582a;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a584d;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a585b;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a59c2;
          piStack_44 = (int *)0x80a5875;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          piStack_44 = (int *)0x80a58a0;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          piStack_44 = (int *)0x80a58b0;
          CONTROLS_TCONTROL____SHOW();
          piStack_44 = (int *)0x80a58ce;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a58e2;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a58f4;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a58fc;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a591f;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a592c;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a5940;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            piStack_44 = (int *)0x80a5952;
            CONTROLS_TCONTROL____HIDE();
          }
          piStack_44 = (int *)0x80a595a;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a597d;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a598a;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a59ac;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              piStack_44 = (int *)0x80a59c0;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (0 < U_JUKELINUX1_KMAT + 4) {
          piStack_44 = (int *)0x80a5a0a;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          piStack_44 = (int *)0x80a5a2d;
          fpc_shortstr_to_ansistr();
          piStack_44 = (int *)0x80a5a3b;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            piStack_44 = (int *)0x80a5a55;
            EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
            piStack_44 = (int *)0x80a5a80;
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
            piStack_44 = (int *)0x80a5a90;
            CONTROLS_TCONTROL____SHOW();
            piStack_44 = (int *)0x80a5aae;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              piStack_44 = (int *)0x80a5ac2;
              CONTROLS_TCONTROL____SHOW();
            }
            else {
              piStack_44 = (int *)0x80a5ad4;
              CONTROLS_TCONTROL____HIDE();
            }
            piStack_44 = (int *)0x80a5adc;
            fpc_ansistr_decr_ref();
            aiStack_3c[2] = 0;
            piStack_44 = (int *)0x80a5aff;
            fpc_shortstr_to_ansistr();
            piStack_44 = (int *)0x80a5b0c;
            iVar2 = fpc_ansistr_compare_equal();
            if (iVar2 == 0) {
              piStack_44 = (int *)0x80a5b20;
              CONTROLS_TCONTROL____SHOW();
            }
            else {
              piStack_44 = (int *)0x80a5b32;
              CONTROLS_TCONTROL____HIDE();
            }
            piStack_44 = (int *)0x80a5b3a;
            fpc_ansistr_decr_ref();
            aiStack_3c[2] = 0;
            piStack_44 = (int *)0x80a5b5d;
            fpc_shortstr_to_ansistr();
            piStack_44 = (int *)0x80a5b6a;
            iVar2 = fpc_ansistr_compare_equal();
            if (iVar2 == 0) {
              piStack_44 = (int *)0x80a5b8c;
              iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
              if (iVar2 == 0) {
                piStack_44 = (int *)0x80a5ba0;
                CONTROLS_TCONTROL____HIDE();
              }
            }
            goto LAB_080a5bd2;
          }
        }
        piStack_44 = (int *)0x80a5bb2;
        CONTROLS_TCONTROL____HIDE();
        piStack_44 = (int *)0x80a5bc2;
        CONTROLS_TCONTROL____HIDE();
        piStack_44 = (int *)0x80a5bd2;
        CONTROLS_TCONTROL____HIDE();
      }
LAB_080a5bd2:
      piStack_44 = (int *)0x80a5bfd;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      piStack_44 = (int *)0x80a5c05;
      fpc_ansistr_decr_ref();
      aiStack_3c[1] = 0;
      piStack_44 = (int *)0x80a5c1c;
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      piStack_44 = (int *)0x80a5c2f;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      piStack_44 = (int *)0x80a5c37;
      fpc_ansistr_decr_ref();
      aiStack_3c[1] = 0;
      piStack_44 = aiStack_3c + 1;
      piStack_48 = (int *)0x80a5c7c;
      fpc_ansistr_copy();
      piStack_48 = (int *)0x80a5c8f;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      piStack_48 = (int *)0x80a5c97;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_48 = (int *)0x80a5cba;
      fpc_shortstr_to_ansistr();
      piStack_48 = (int *)0x80a5cc2;
      fpc_ansistr_incr_ref();
      piStack_48 = (int *)0x80a5ccc;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_RITMODOCD = aiStack_3c[2];
      piStack_48 = (int *)0x80a5cdc;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_48 = aiStack_3c + 2;
      piStack_4c = (int *)0x80a5d0a;
      fpc_ansistr_copy();
      piStack_4c = (int *)0x80a5d12;
      fpc_ansistr_incr_ref();
      piStack_4c = (int *)0x80a5d1c;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_LETRADOCD = aiStack_3c[2];
      piStack_4c = (int *)0x80a5d2c;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_4c = (int *)0x80a5d4f;
      fpc_shortstr_to_ansistr();
      piStack_4c = (int *)0x80a5d5c;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        piStack_4c = (int *)0x80a5d75;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a5d90;
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        piStack_4c = (int *)0x80a5da0;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        piStack_4c = (int *)0x80a5db7;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a5dd2;
        GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
        piStack_4c = (int *)0x80a5de2;
        CONTROLS_TCONTROL____HIDE();
      }
      piStack_4c = (int *)0x80a5dea;
      fpc_ansistr_decr_ref();
      aiStack_3c[1] = 0;
      piStack_4c = (int *)0x80a5e04;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      piStack_4c = (int *)0x80a5e17;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      piStack_4c = (int *)0x80a5e1f;
      fpc_ansistr_decr_ref();
      aiStack_3c[1] = 0;
      piStack_4c = (int *)0x80a5e42;
      fpc_shortstr_to_ansistr();
      piStack_4c = (int *)0x80a5e55;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      piStack_4c = (int *)0x80a5e5d;
      fpc_ansistr_decr_ref();
      aiStack_3c[1] = 0;
      piStack_4c = (int *)0x80a5e77;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      piStack_4c = (int *)0x80a5e8a;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      piStack_4c = (int *)0x80a5ea8;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        piStack_4c = (int *)0x80a5ebc;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        piStack_4c = (int *)0x80a5ece;
        CONTROLS_TCONTROL____HIDE();
      }
      piStack_4c = (int *)0x80a5ed6;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_4c = (int *)0x80a5ef9;
      fpc_shortstr_to_ansistr();
      piStack_4c = (int *)0x80a5f06;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        piStack_4c = (int *)0x80a5f1a;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        piStack_4c = (int *)0x80a5f2c;
        CONTROLS_TCONTROL____HIDE();
      }
      piStack_4c = (int *)0x80a5f34;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      piStack_4c = (int *)0x80a5f57;
      fpc_shortstr_to_ansistr();
      piStack_4c = (int *)0x80a5f64;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        piStack_4c = (int *)0x80a5f86;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          piStack_4c = (int *)0x80a5f9a;
          CONTROLS_TCONTROL____HIDE();
        }
      }
      if (U_JUKELINUX1_SEGURANDOTECLA < 8) {
        piStack_4c = (int *)0x80a5fb8;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a5fc8;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a5fec;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6010;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6034;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6058;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a607c;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a60a0;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a60c4;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a60e8;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a610c;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6130;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6154;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6178;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6180;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a619a;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a61a2;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a61ac;
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_NOMEMUSICAORIGINALGRANDE = aiStack_3c[2];
        piStack_4c = (int *)0x80a61bc;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a61d6;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a61de;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a61e8;
        fpc_ansistr_decr_ref();
        DAT_09301dc4 = aiStack_3c[2];
        piStack_4c = (int *)0x80a61f8;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a6212;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a621a;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a6224;
        fpc_ansistr_decr_ref();
        DAT_09301dc8 = aiStack_3c[2];
        piStack_4c = (int *)0x80a6234;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a624e;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6256;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a6260;
        fpc_ansistr_decr_ref();
        DAT_09301dcc = aiStack_3c[2];
        piStack_4c = (int *)0x80a6270;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a628a;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6292;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a629c;
        fpc_ansistr_decr_ref();
        DAT_09301dd0 = aiStack_3c[2];
        piStack_4c = (int *)0x80a62ac;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a62c6;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a62ce;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a62d8;
        fpc_ansistr_decr_ref();
        DAT_09301dd4 = aiStack_3c[2];
        piStack_4c = (int *)0x80a62e8;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a6302;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a630a;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a6314;
        fpc_ansistr_decr_ref();
        DAT_09301dd8 = aiStack_3c[2];
        piStack_4c = (int *)0x80a6324;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a633e;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6346;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a6350;
        fpc_ansistr_decr_ref();
        DAT_09301ddc = aiStack_3c[2];
        piStack_4c = (int *)0x80a6360;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a637a;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6382;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a638c;
        fpc_ansistr_decr_ref();
        DAT_09301de0 = aiStack_3c[2];
        piStack_4c = (int *)0x80a639c;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a63b6;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a63be;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a63c8;
        fpc_ansistr_decr_ref();
        DAT_09301de4 = aiStack_3c[2];
        piStack_4c = (int *)0x80a63d8;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a63f2;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a63fa;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a6404;
        fpc_ansistr_decr_ref();
        DAT_09301de8 = aiStack_3c[2];
        piStack_4c = (int *)0x80a6414;
        fpc_ansistr_decr_ref();
        aiStack_3c[2] = 0;
        piStack_4c = (int *)0x80a642e;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6436;
        fpc_ansistr_incr_ref();
        piStack_4c = (int *)0x80a6440;
        fpc_ansistr_decr_ref();
        DAT_09301dec = aiStack_3c[2];
        piStack_4c = (int *)0x80a6458;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6468;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6478;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6488;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6498;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a64a8;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a64b8;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a64c8;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a64d8;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a64e8;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a64f8;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6508;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6518;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a6528;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a6538;
        CONTROLS_TCONTROL____HIDE();
        U_JUKELINUX1_MOSTRANDOLETRANAPAGINACAO = 0;
        iVar2 = 0;
        if ((&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] != 0) {
          iVar2 = *(int *)((&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] + -4
                          );
        }
        if (0 < iVar2) {
          piStack_4c = (int *)0x80a656e;
          CONTROLS_TCONTROL____SHOW();
          U_JUKELINUX1_MOSTRANDOSETABAIXO = 1;
        }
        piStack_4c = (int *)0x80a6588;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6595;
        JUKELINUX1_MOSTRA_MUSICAS_LONGINT();
        ppiVar3 = &piStack_48;
      }
      else {
        piStack_4c = (int *)0x80a65aa;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a65ba;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a65ca;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a65da;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a65ea;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a65fa;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a660a;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a661a;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a662a;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a663a;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a664a;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a665a;
        CONTROLS_TCONTROL____HIDE();
        piStack_4c = (int *)0x80a6670;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        piStack_4c = (int *)0x80a6680;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a6690;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a66a0;
        CONTROLS_TCONTROL____SHOW();
        piStack_4c = (int *)0x80a66af;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          piStack_4c = (int *)0x80a66bb;
          fpc_ansistr_decr_ref();
          aiStack_3c[1] = 0;
          piStack_4c = aiStack_3c + 1;
          fpc_ansistr_copy();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
        else {
          piStack_4c = (int *)0x80a6706;
          fpc_ansistr_decr_ref();
          aiStack_3c[1] = 0;
          piStack_4c = aiStack_3c + 1;
          fpc_ansistr_copy();
          CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        }
        fpc_ansistr_decr_ref();
        aiStack_3c[1] = 0;
        CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
        CONTROLS_TCONTROL____HIDE();
        U_JUKELINUX1_MOSTRANDOSETABAIXO = 0;
        CONTROLS_TCONTROL____HIDE();
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            CONTROLS_TCONTROL____HIDE();
            CONTROLS_TCONTROL____SHOW();
          }
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            CONTROLS_TCONTROL____SHOW();
            CONTROLS_TCONTROL____HIDE();
          }
        }
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            CONTROLS_TCONTROL____SHOW();
            CONTROLS_TCONTROL____HIDE();
          }
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            CONTROLS_TCONTROL____HIDE();
            CONTROLS_TCONTROL____SHOW();
          }
        }
        CONTROLS_TCONTROL____BRINGTOFRONT();
        CONTROLS_TCONTROL____BRINGTOFRONT();
        U_JUKELINUX1_MOSTRANDOLETRANAPAGINACAO = 1;
        (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbc0) + 0xdc))();
        (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbc0) + 0xd8))();
        (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbc0) + 0xd8))();
        ppiVar3 = &piStack_4c;
      }
      ppiVar4 = ppiVar3;
      if (U_JUKELINUX1_MOSTRAPAGINANDOCDS != '\0') {
        if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 6) {
LAB_080a6ae6:
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6af6;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6b06;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6b16;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a694e;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6971;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a697f;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a6ae6;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6999;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a69c4;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a69d4;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a69f2;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a06;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a18;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a20;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a43;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a50;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a64;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a76;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6a7e;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6aa1;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6aae;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6ad0;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6ae4;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 7) {
LAB_080a6cca:
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6cda;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6cea;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6cfa;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6b32;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6b55;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6b63;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a6cca;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6b7d;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6ba8;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6bb8;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6bd6;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6bea;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6bfc;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c04;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c27;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c34;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c48;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c5a;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c62;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c85;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6c92;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6cb4;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6cc8;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 8) {
LAB_080a6eae:
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6ebe;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6ece;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6ede;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6d16;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6d39;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6d47;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a6eae;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6d61;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6d8c;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6d9c;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6dba;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6dce;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6de0;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6de8;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e0b;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e18;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e2c;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e3e;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e46;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e69;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e76;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6e98;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6eac;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 9) {
LAB_080a7092:
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a70a2;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a70b2;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a70c2;
          CONTROLS_TCONTROL____HIDE();
        }
        else {
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6efa;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6f1d;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6f2b;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 != 0) goto LAB_080a7092;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6f45;
          EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6f70;
          GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6f80;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6f9e;
          iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6fb2;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6fc4;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6fcc;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6fef;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a6ffc;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7010;
            CONTROLS_TCONTROL____SHOW();
          }
          else {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7022;
            CONTROLS_TCONTROL____HIDE();
          }
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a702a;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a704d;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a705a;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a707c;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7090;
              CONTROLS_TCONTROL____HIDE();
            }
          }
        }
        if (U_JUKELINUX1_KMAT + 10 <= U_JUKELINUX1_TOTALCDS) {
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a70de;
          fpc_ansistr_decr_ref();
          aiStack_3c[2] = 0;
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7101;
          fpc_shortstr_to_ansistr();
          *(undefined4 *)((int)ppiVar3 + -4) = 0x80a710f;
          iVar2 = fpc_ansistr_compare_equal();
          if (iVar2 == 0) {
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7129;
            EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7154;
            GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7164;
            CONTROLS_TCONTROL____SHOW();
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7182;
            iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
            if (iVar2 == 0) {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7196;
              CONTROLS_TCONTROL____SHOW();
            }
            else {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a71a8;
              CONTROLS_TCONTROL____HIDE();
            }
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a71b0;
            fpc_ansistr_decr_ref();
            aiStack_3c[2] = 0;
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a71d3;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a71e0;
            iVar2 = fpc_ansistr_compare_equal();
            if (iVar2 == 0) {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a71f4;
              CONTROLS_TCONTROL____SHOW();
            }
            else {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7206;
              CONTROLS_TCONTROL____HIDE();
            }
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a720e;
            fpc_ansistr_decr_ref();
            aiStack_3c[2] = 0;
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7231;
            fpc_shortstr_to_ansistr();
            *(undefined4 *)((int)ppiVar3 + -4) = 0x80a723e;
            iVar2 = fpc_ansistr_compare_equal();
            if (iVar2 == 0) {
              *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7264;
              iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
              if (iVar2 == 0) {
                *(undefined4 *)((int)ppiVar3 + -4) = 0x80a727c;
                CONTROLS_TCONTROL____HIDE();
              }
            }
            goto LAB_080a733c;
          }
        }
        *(undefined4 *)((int)ppiVar3 + -4) = 0x80a7291;
        CONTROLS_TCONTROL____HIDE();
        *(undefined4 *)((int)ppiVar3 + -4) = 0x80a72a1;
        CONTROLS_TCONTROL____HIDE();
        *(undefined4 *)((int)ppiVar3 + -4) = 0x80a72b1;
        CONTROLS_TCONTROL____HIDE();
      }
    }
  }
LAB_080a733c:
  *(undefined4 *)((int)ppiVar4 + -4) = 0x80a7344;
  fpc_ansistr_decr_ref();
  aiStack_3c[2] = 0;
  *(int **)((int)ppiVar4 + -4) = aiStack_3c + 2;
  *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7363;
  fpc_ansistr_copy();
  *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7370;
  iVar2 = fpc_ansistr_compare_equal();
  piVar5 = (int *)((int)ppiVar4 + -4);
  if (iVar2 == 0) {
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7380;
    fpc_ansistr_decr_ref();
    aiStack_3c[2] = 0;
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a73a3;
    fpc_shortstr_to_ansistr();
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a73ab;
    fpc_ansistr_incr_ref();
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a73b5;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_RITMODOCD = aiStack_3c[2];
    U_JUKELINUX1_MMCCDDSS = '\x01';
    if (U_JUKELINUX1_KMAT < 1) {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a753e;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a754e;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a755e;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a73f0;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7418;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7428;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7443;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7457;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7469;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7471;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7491;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a749e;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a74b2;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a74c4;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a74cc;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a74ec;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a74f9;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7518;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -8) = 0x80a752c;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_KMAT + 1 < 1) {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a76d1;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a76e1;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a76f1;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a757e;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a75a7;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a75b7;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a75d3;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a75e7;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a75f9;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7601;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7622;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a762f;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7643;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7655;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a765d;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a767e;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a768b;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a76ab;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -8) = 0x80a76bf;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_KMAT + 2 < 1) {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7870;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7880;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7890;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7713;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a773e;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a774e;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a776c;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7780;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7792;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a779a;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a77bd;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a77ca;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a77de;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a77f0;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a77f8;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a781b;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7828;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a784a;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -8) = 0x80a785e;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_KMAT + 3 < 1) {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7a0f;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7a1f;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7a2f;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a78b2;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a78dd;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a78ed;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a790b;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a791f;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7931;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7939;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a795c;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7969;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a797d;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a798f;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7997;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a79ba;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a79c7;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a79e9;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -8) = 0x80a79fd;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_KMAT + 4 < 1) {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7bae;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7bbe;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7bce;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7a51;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7a7c;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7a8c;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7aaa;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7abe;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7ad0;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7ad8;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7afb;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b08;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b1c;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b2e;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b36;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b59;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b66;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b88;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7b9c;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7bf9;
    GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7c01;
    fpc_ansistr_decr_ref();
    aiStack_3c[1] = 0;
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7c18;
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7c2b;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    *(undefined4 *)((int)ppiVar4 + -8) = 0x80a7c33;
    fpc_ansistr_decr_ref();
    aiStack_3c[1] = 0;
    *(int **)((int)ppiVar4 + -8) = aiStack_3c + 1;
    *(undefined4 *)((int)ppiVar4 + -0xc) = 0x80a7c78;
    fpc_ansistr_copy();
    *(undefined4 *)((int)ppiVar4 + -0xc) = 0x80a7c8b;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    *(undefined4 *)((int)ppiVar4 + -0xc) = 0x80a7c93;
    fpc_ansistr_decr_ref();
    aiStack_3c[2] = 0;
    *(undefined4 *)((int)ppiVar4 + -0xc) = 0x80a7cb6;
    fpc_shortstr_to_ansistr();
    *(undefined4 *)((int)ppiVar4 + -0xc) = 0x80a7cbe;
    fpc_ansistr_incr_ref();
    *(undefined4 *)((int)ppiVar4 + -0xc) = 0x80a7cc8;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_RITMODOCD = aiStack_3c[2];
    *(undefined4 *)((int)ppiVar4 + -0xc) = 0x80a7cd8;
    fpc_ansistr_decr_ref();
    aiStack_3c[2] = 0;
    *(int **)((int)ppiVar4 + -0xc) = aiStack_3c + 2;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d06;
    fpc_ansistr_copy();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d0e;
    fpc_ansistr_incr_ref();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d18;
    fpc_ansistr_decr_ref();
    U_JUKELINUX1_LETRADOCD = aiStack_3c[2];
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d28;
    fpc_ansistr_decr_ref();
    aiStack_3c[2] = 0;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d4b;
    fpc_shortstr_to_ansistr();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d58;
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d71;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d8c;
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7d9c;
      CONTROLS_TCONTROL____SHOW();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7db3;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7dce;
      GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7dde;
      CONTROLS_TCONTROL____HIDE();
    }
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7de6;
    fpc_ansistr_decr_ref();
    aiStack_3c[1] = 0;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e00;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e13;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e1b;
    fpc_ansistr_decr_ref();
    aiStack_3c[1] = 0;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e3e;
    fpc_shortstr_to_ansistr();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e51;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e59;
    fpc_ansistr_decr_ref();
    aiStack_3c[1] = 0;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e73;
    CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7e86;
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7ea4;
    iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
    if (iVar2 == 0) {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7eb8;
      CONTROLS_TCONTROL____SHOW();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7eca;
      CONTROLS_TCONTROL____HIDE();
    }
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7ed2;
    fpc_ansistr_decr_ref();
    aiStack_3c[2] = 0;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7ef5;
    fpc_shortstr_to_ansistr();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f02;
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f16;
      CONTROLS_TCONTROL____SHOW();
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f28;
      CONTROLS_TCONTROL____HIDE();
    }
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f30;
    fpc_ansistr_decr_ref();
    aiStack_3c[2] = 0;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f53;
    fpc_shortstr_to_ansistr();
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f60;
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f82;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7f96;
        CONTROLS_TCONTROL____HIDE();
      }
    }
    if (U_JUKELINUX1_SEGURANDOTECLA < 4) {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7fb4;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7fc4;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a7fe8;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a800c;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8030;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8054;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8078;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a809c;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a80c0;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a80e4;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8108;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a812c;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8150;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8174;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a817c;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8196;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a819e;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a81a8;
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_NOMEMUSICAORIGINALGRANDE = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a81b8;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a81d2;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a81da;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a81e4;
      fpc_ansistr_decr_ref();
      DAT_09301dc4 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a81f4;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a820e;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8216;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8220;
      fpc_ansistr_decr_ref();
      DAT_09301dc8 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8230;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a824a;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8252;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a825c;
      fpc_ansistr_decr_ref();
      DAT_09301dcc = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a826c;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8286;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a828e;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8298;
      fpc_ansistr_decr_ref();
      DAT_09301dd0 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a82a8;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a82c2;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a82ca;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a82d4;
      fpc_ansistr_decr_ref();
      DAT_09301dd4 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a82e4;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a82fe;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8306;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8310;
      fpc_ansistr_decr_ref();
      DAT_09301dd8 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8320;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a833a;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8342;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a834c;
      fpc_ansistr_decr_ref();
      DAT_09301ddc = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a835c;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8376;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a837e;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8388;
      fpc_ansistr_decr_ref();
      DAT_09301de0 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8398;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a83b2;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a83ba;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a83c4;
      fpc_ansistr_decr_ref();
      DAT_09301de4 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a83d4;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a83ee;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a83f6;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8400;
      fpc_ansistr_decr_ref();
      DAT_09301de8 = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8410;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a842a;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8432;
      fpc_ansistr_incr_ref();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a843c;
      fpc_ansistr_decr_ref();
      DAT_09301dec = aiStack_3c[2];
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8454;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8464;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8474;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8484;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8494;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a84a4;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a84b4;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a84c4;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a84d4;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a84e4;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a84f4;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8504;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8514;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8524;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8534;
      CONTROLS_TCONTROL____HIDE();
      U_JUKELINUX1_MOSTRANDOLETRANAPAGINACAO = 0;
      iVar2 = 0;
      if ((&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] != 0) {
        iVar2 = *(int *)((&U_JUKELINUX1_JC_SERIALPENDRIVECON)[(U_JUKELINUX1_KMAT + 5) * 0x90] + -4);
      }
      if (0 < iVar2) {
        *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a856a;
        CONTROLS_TCONTROL____SHOW();
        U_JUKELINUX1_MOSTRANDOSETABAIXO = 1;
      }
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8584;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8591;
      JUKELINUX1_MOSTRA_MUSICAS_LONGINT();
      piVar5 = (int *)((int)ppiVar4 + -0xc);
    }
    else {
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a85a6;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a85b6;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a85c6;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a85d6;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a85e6;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a85f6;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8606;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8616;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8626;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8636;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8646;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8656;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a866c;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a867c;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a868c;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a869c;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a86ab;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a86b7;
        fpc_ansistr_decr_ref();
        aiStack_3c[1] = 0;
        *(int **)((int)ppiVar4 + -0x10) = aiStack_3c + 1;
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a86e5;
        fpc_ansistr_copy();
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a86f8;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
      else {
        *(undefined4 *)((int)ppiVar4 + -0x10) = 0x80a8702;
        fpc_ansistr_decr_ref();
        aiStack_3c[1] = 0;
        *(int **)((int)ppiVar4 + -0x10) = aiStack_3c + 1;
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8730;
        fpc_ansistr_copy();
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8743;
        CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      }
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a874b;
      fpc_ansistr_decr_ref();
      aiStack_3c[1] = 0;
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8765;
      CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8778;
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8788;
      CONTROLS_TCONTROL____HIDE();
      U_JUKELINUX1_MOSTRANDOSETABAIXO = 0;
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a87a2;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a87b1;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a87c4;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a87d8;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a87e8;
          CONTROLS_TCONTROL____SHOW();
        }
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a87f7;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a880b;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a881b;
          CONTROLS_TCONTROL____HIDE();
        }
      }
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a882a;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a883d;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8851;
          CONTROLS_TCONTROL____SHOW();
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8861;
          CONTROLS_TCONTROL____HIDE();
        }
        *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8870;
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8884;
          CONTROLS_TCONTROL____HIDE();
          *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8894;
          CONTROLS_TCONTROL____SHOW();
        }
      }
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a88a4;
      CONTROLS_TCONTROL____BRINGTOFRONT();
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a88b4;
      CONTROLS_TCONTROL____BRINGTOFRONT();
      U_JUKELINUX1_MOSTRANDOLETRANAPAGINACAO = 1;
      pcVar1 = *(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbc0) + 0xdc);
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a88df;
      (*pcVar1)();
      pcVar1 = *(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbc0) + 0xd8);
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8900;
      (*pcVar1)();
      pcVar1 = *(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xbc0) + 0xd8);
      *(undefined4 *)((int)ppiVar4 + -0x14) = 0x80a8921;
      (*pcVar1)();
      piVar5 = (int *)((int)ppiVar4 + -0x10);
    }
    if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 6) {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8aa4;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8ab4;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8ac4;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8947;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8972;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8982;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a89a0;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a89b4;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a89c6;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a89ce;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a89f1;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a89fe;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8a12;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8a24;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8a2c;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8a4f;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8a5c;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8a7e;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x80a8a92;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 7) {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8c47;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8c57;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8c67;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8aea;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8b15;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8b25;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8b43;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8b57;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8b69;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8b71;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8b94;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8ba1;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8bb5;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8bc7;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8bcf;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8bf2;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8bff;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8c21;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x80a8c35;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 8) {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8dea;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8dfa;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8e0a;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8c8d;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8cb8;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8cc8;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8ce6;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8cfa;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8d0c;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8d14;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8d37;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8d44;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8d58;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8d6a;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8d72;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8d95;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8da2;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8dc4;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x80a8dd8;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 9) {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8f8d;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8f9d;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8fad;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8e30;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8e5b;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8e6b;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8e89;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8e9d;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8eaf;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8eb7;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8eda;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8ee7;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8efb;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8f0d;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8f15;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8f38;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8f45;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a8f67;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x80a8f7b;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
    if (U_JUKELINUX1_TOTALCDS < U_JUKELINUX1_KMAT + 10) {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a913b;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a914b;
      CONTROLS_TCONTROL____HIDE();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a915b;
      CONTROLS_TCONTROL____HIDE();
    }
    else {
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8fd3;
      EXTCTRLS_TCUSTOMIMAGE____SETSTRETCH_BOOLEAN();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a8ffe;
      GRAPHICS_TPICTURE____LOADFROMFILE_ANSISTRING();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a900e;
      CONTROLS_TCONTROL____SHOW();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a902c;
      iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a9040;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a9052;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a905a;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a907d;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a908a;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a909e;
        CONTROLS_TCONTROL____SHOW();
      }
      else {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a90b0;
        CONTROLS_TCONTROL____HIDE();
      }
      *(undefined4 *)((int)piVar5 + -4) = 0x80a90b8;
      fpc_ansistr_decr_ref();
      aiStack_3c[2] = 0;
      *(undefined4 *)((int)piVar5 + -4) = 0x80a90db;
      fpc_shortstr_to_ansistr();
      *(undefined4 *)((int)piVar5 + -4) = 0x80a90e8;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        *(undefined4 *)((int)piVar5 + -4) = 0x80a910e;
        iVar2 = FPC_SHORTSTR_COMPARE_EQUAL();
        if (iVar2 == 0) {
          *(undefined4 *)((int)piVar5 + -4) = 0x80a9126;
          CONTROLS_TCONTROL____HIDE();
        }
      }
    }
  }
LAB_080a91e6:
  piVar5[-1] = 0x80a91eb;
  fpc_popaddrstack();
  piVar5[-1] = 0x80a91f3;
  fpc_ansistr_decr_ref();
  aiStack_3c[1] = 0;
  piVar5[-1] = 0x80a9202;
  fpc_ansistr_decr_ref();
  aiStack_3c[2] = 0;
  piVar5[-1] = 0x80a9211;
  fpc_ansistr_decr_ref();
  if (*piVar5 != 0) {
    *piVar5 = 0x80a921b;
    fpc_reraise();
  }
  return;
}

