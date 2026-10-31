// JUKELINUX1_TFORM1_$__CAPAMENOS1CLICK$TOBJECT  @ 080d7ed0

void JUKELINUX1_TFORM1____CAPAMENOS1CLICK_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  
  if (U_JUKELINUX1_MOSTRANDORITMOS == '\0') {
    if (-5 < U_JUKELINUX1_KMAT + -1) {
      U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + -1;
      JUKELINUX1_MOSTRA_CDS_ANSISTRING();
    }
  }
  else {
    iVar1 = fpc_ansistr_compare_equal();
    if ((iVar1 == 0) && (U_JUKELINUX1_NUMRITMOSELECIONADO + -1 <= U_JUKELINUX1_TOTALMMRITMO)) {
      U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + -1;
      JUKELINUX1_MOSTRA_RITMOS();
      (**(code **)(**(int **)(in_EAX + 0xbb0) + 0xd8))();
      (**(code **)(**(int **)(in_EAX + 0xbb0) + 0xd8))();
    }
  }
  return;
}

