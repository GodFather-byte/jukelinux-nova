// JUKELINUX1_MOSTRA_TELA_CARREGANDO_CDS  @ 080ae1c0

void JUKELINUX1_MOSTRA_TELA_CARREGANDO_CDS(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  longdouble lVar4;
  undefined8 local_c0;
  int *piStack_b8;
  undefined8 local_b4;
  undefined8 local_ac;
  undefined4 *puStack_a4;
  undefined8 local_a0;
  int aiStack_98 [4];
  undefined *local_88;
  undefined4 local_84;
  char *local_80;
  undefined4 local_7c;
  undefined *local_78;
  undefined4 local_74;
  char *local_70;
  undefined4 local_6c;
  undefined *local_68;
  undefined4 local_64;
  undefined *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_4c;
  undefined4 local_48;
  char *local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined4 local_30;
  
  aiStack_98[1] = 0;
  aiStack_98[2] = 0;
  aiStack_98[3] = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_30 = 0;
  aiStack_98[0] = 0x80ae21a;
  fpc_pushexceptaddr();
  aiStack_98[0] = 0x80ae21f;
  aiStack_98[0] = fpc_setjmp();
  piVar3 = aiStack_98;
  if (aiStack_98[0] != 0) goto LAB_080ae769;
  local_a0 = (double)CONCAT44(0x80ae24c,(undefined4)local_a0);
  (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xa94) + 0x104))();
  local_a0 = (double)CONCAT44(0x80ae25b,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
LAB_080ae298:
    local_a0 = (double)CONCAT44(0x80ae2b9,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  else {
    local_a0 = (double)CONCAT44(0x80ae26e,(undefined4)local_a0);
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) goto LAB_080ae298;
    local_a0 = (double)CONCAT44(0x80ae281,(undefined4)local_a0);
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) goto LAB_080ae298;
    local_a0 = (double)CONCAT44(0x80ae294,(undefined4)local_a0);
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) goto LAB_080ae298;
  }
  local_a0 = (double)CONCAT44(0x80ae2c8,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
    local_a0 = (double)CONCAT44(0x80ae2ed,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  local_a0 = (double)CONCAT44(0x80ae2fc,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
    local_a0 = (double)CONCAT44(0x80ae321,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  local_a0 = (double)CONCAT44(0x80ae330,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
    local_a0 = (double)CONCAT44(0x80ae355,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  local_a0 = (double)CONCAT44(0x80ae364,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
    local_a0 = (double)CONCAT44(0x80ae389,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  local_a0 = (double)CONCAT44(0x80ae398,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
    local_a0 = (double)CONCAT44(0x80ae3bd,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  local_a0 = (double)CONCAT44(0x80ae3cc,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
    local_a0 = (double)CONCAT44(0x80ae3f1,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  local_a0 = (double)CONCAT44(0x80ae400,(undefined4)local_a0);
  iVar2 = fpc_ansistr_compare_equal();
  if (iVar2 == 0) {
LAB_080ae417:
    local_a0 = (double)CONCAT44(0x80ae438,(undefined4)local_a0);
    EXTCTRLS_TCUSTOMIMAGE____SETPICTURE_TPICTURE();
  }
  else {
    local_a0 = (double)CONCAT44(0x80ae413,(undefined4)local_a0);
    iVar2 = fpc_ansistr_compare_equal();
    if (iVar2 == 0) goto LAB_080ae417;
  }
  local_a0 = (double)CONCAT44(0x80ae44d,(undefined4)local_a0);
  CONTROLS_TCONTROL____SETLEFT_LONGINT();
  local_a0 = (double)CONCAT44(0x80ae462,(undefined4)local_a0);
  CONTROLS_TCONTROL____SETTOP_LONGINT();
  local_a0 = (double)CONCAT44(0x80ae478,(undefined4)local_a0);
  CONTROLS_TCONTROL____SETWIDTH_LONGINT();
  local_a0 = (double)CONCAT44(0x80ae48e,(undefined4)local_a0);
  CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
  local_a0 = (double)CONCAT44(0x80ae49e,(undefined4)local_a0);
  CONTROLS_TCONTROL____SHOW();
  local_a0 = (double)CONCAT44(0x80ae4ae,(undefined4)local_a0);
  CONTROLS_TCONTROL____BRINGTOFRONT();
  local_a0 = (double)CONCAT44(0x80ae4cd,(undefined4)local_a0);
  (**(code **)(**(int **)(U_JUKELINUX1_FORM1 + 0xb10) + 0x2fc))();
  local_a0 = (double)CONCAT44(0x80ae4e2,(undefined4)local_a0);
  CONTROLS_TCONTROL____SETLEFT_LONGINT();
  local_a0 = (double)CONCAT44(0x80ae4f7,(undefined4)local_a0);
  CONTROLS_TCONTROL____SETTOP_LONGINT();
  local_a0 = (double)CONCAT44(0x80ae50d,(undefined4)local_a0);
  CONTROLS_TCONTROL____SETWIDTH_LONGINT();
  local_a0 = (double)CONCAT44(0x80ae515,(undefined4)local_a0);
  fpc_ansistr_decr_ref();
  local_30 = 0;
  local_4c = &__JUKELINUX1__Ld10;
  local_48 = U_JUKELINUX1_VERSAO;
  local_44 = __JUKELINUX1__Ld235;
  local_a0 = (double)CONCAT44(0x80ae53c,(undefined4)local_a0);
  fpc_ansistr_decr_ref();
  local_50 = 0;
  local_a0 = (double)CONCAT44(0x80ae548,(undefined4)local_a0);
  lVar4 = (longdouble)SYSUTILS_DATE__TDATETIME();
  local_a0 = (double)lVar4;
  puStack_a4 = (undefined4 *)0x80ae556;
  SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
  local_40 = local_50;
  local_3c = &__JUKELINUX1__Ld236;
  puStack_a4 = (undefined4 *)0x80ae56c;
  fpc_ansistr_decr_ref();
  local_54 = 0;
  puStack_a4 = &local_54;
  local_ac = (double)CONCAT44(0x80ae57f,(undefined4)local_ac);
  fpc_ansistr_decr_ref();
  local_58 = 0;
  local_ac = (double)CONCAT44(0x80ae58b,(undefined4)local_ac);
  lVar4 = (longdouble)SYSUTILS_TIME__TDATETIME();
  local_ac = (double)lVar4;
  local_b4 = (double)CONCAT44(0x80ae599,(undefined4)local_b4);
  SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
  local_b4 = (double)CONCAT44(0x80ae5ab,(undefined4)local_b4);
  fpc_ansistr_copy();
  local_38 = local_54;
  local_34 = &__JUKELINUX1__Ld237;
  local_b4 = (double)CONCAT44(0x80ae5c9,(undefined4)local_b4);
  fpc_ansistr_concat_multi();
  local_b4 = (double)CONCAT44(0x80ae5dc,(undefined4)local_b4);
  CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
  local_b4 = (double)CONCAT44(0x80ae5e4,(undefined4)local_b4);
  fpc_ansistr_decr_ref();
  local_58 = 0;
  local_b4 = (double)CONCAT44(0x80ae5fe,(undefined4)local_b4);
  fpc_ansistr_concat();
  local_b4 = (double)CONCAT44(0x80ae606,(undefined4)local_b4);
  cVar1 = SYSUTILS_FILEEXISTS_ANSISTRING__BOOLEAN();
  piVar3 = (int *)&local_ac;
  if ((cVar1 == '\0') && (piVar3 = (int *)&local_ac, -1 < U_JUKELINUX1_BLOQUEARQUANDOTOCAR)) {
    local_b4 = (double)CONCAT44(0x80ae624,(undefined4)local_b4);
    fpc_ansistr_decr_ref();
    local_5c = 0;
    local_88 = &__JUKELINUX1__Ld10;
    local_84 = U_JUKELINUX1_VERSAO;
    local_80 = __JUKELINUX1__Ld239;
    local_b4 = (double)CONCAT44(0x80ae64e,(undefined4)local_b4);
    fpc_ansistr_decr_ref();
    local_58 = 0;
    local_b4 = (double)CONCAT44(0x80ae662,(undefined4)local_b4);
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    local_7c = local_58;
    local_78 = &__JUKELINUX1__Ld115;
    local_b4 = (double)CONCAT44(0x80ae678,(undefined4)local_b4);
    fpc_ansistr_decr_ref();
    local_54 = 0;
    local_b4 = (double)CONCAT44(0x80ae68c,(undefined4)local_b4);
    SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
    local_74 = local_54;
    local_70 = __JUKELINUX1__Ld240;
    local_b4 = (double)CONCAT44(0x80ae6a5,(undefined4)local_b4);
    fpc_ansistr_decr_ref();
    aiStack_98[3] = 0;
    local_b4 = (double)CONCAT44(0x80ae6b4,(undefined4)local_b4);
    lVar4 = (longdouble)SYSUTILS_DATE__TDATETIME();
    local_b4 = (double)lVar4;
    piStack_b8 = (int *)0x80ae6c5;
    SYSUTILS_DATETOSTR_TDATETIME__ANSISTRING();
    local_6c = aiStack_98[3];
    local_68 = &__JUKELINUX1__Ld236;
    piStack_b8 = (int *)0x80ae6e1;
    fpc_ansistr_decr_ref();
    aiStack_98[2] = 0;
    piStack_b8 = aiStack_98 + 2;
    local_c0 = (double)CONCAT44(0x80ae6fd,(undefined4)local_c0);
    fpc_ansistr_decr_ref();
    aiStack_98[1] = 0;
    local_c0 = (double)CONCAT44(0x80ae70c,(undefined4)local_c0);
    lVar4 = (longdouble)SYSUTILS_TIME__TDATETIME();
    local_c0 = (double)lVar4;
    SYSUTILS_TIMETOSTR_TDATETIME__ANSISTRING();
    fpc_ansistr_copy();
    local_64 = aiStack_98[2];
    local_60 = &__JUKELINUX1__Ld237;
    fpc_ansistr_concat_multi();
    CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
    piVar3 = (int *)&local_c0;
  }
LAB_080ae769:
  piVar3[-1] = 0x80ae76e;
  fpc_popaddrstack();
  piVar3[-1] = 0x80ae779;
  fpc_ansistr_decr_ref();
  aiStack_98[1] = 0;
  piVar3[-1] = 0x80ae78e;
  fpc_ansistr_decr_ref();
  aiStack_98[2] = 0;
  piVar3[-1] = 0x80ae7a3;
  fpc_ansistr_decr_ref();
  aiStack_98[3] = 0;
  piVar3[-1] = 0x80ae7b5;
  fpc_ansistr_decr_ref();
  local_5c = 0;
  piVar3[-1] = 0x80ae7c4;
  fpc_ansistr_decr_ref();
  local_58 = 0;
  piVar3[-1] = 0x80ae7d3;
  fpc_ansistr_decr_ref();
  local_54 = 0;
  piVar3[-1] = 0x80ae7e2;
  fpc_ansistr_decr_ref();
  local_50 = 0;
  piVar3[-1] = 0x80ae7f1;
  fpc_ansistr_decr_ref();
  local_30 = 0;
  if (*piVar3 != 0) {
    *piVar3 = 0x80ae802;
    fpc_reraise();
  }
  return;
}

