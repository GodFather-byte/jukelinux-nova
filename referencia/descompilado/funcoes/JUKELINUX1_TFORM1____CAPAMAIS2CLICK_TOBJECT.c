// JUKELINUX1_TFORM1_$__CAPAMAIS2CLICK$TOBJECT  @ 080d7c10

void JUKELINUX1_TFORM1____CAPAMAIS2CLICK_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  
  if (U_JUKELINUX1_MOSTRANDORITMOS == '\0') {
    if (U_JUKELINUX1_KMAT + 6 < U_JUKELINUX1_TOTALCDS) {
      U_JUKELINUX1_KMAT = U_JUKELINUX1_KMAT + 2;
      JUKELINUX1_MOSTRA_CDS_ANSISTRING();
    }
  }
  else {
    iVar1 = fpc_ansistr_compare_equal();
    if ((iVar1 == 0) && (U_JUKELINUX1_NUMRITMOSELECIONADO + 2 <= U_JUKELINUX1_TOTALMMRITMO)) {
      U_JUKELINUX1_NUMRITMOSELECIONADO = U_JUKELINUX1_NUMRITMOSELECIONADO + 2;
      JUKELINUX1_MOSTRA_RITMOS();
      (**(code **)(**(int **)(in_EAX + 0xbb0) + 0xd8))();
      (**(code **)(**(int **)(in_EAX + 0xbb0) + 0xd8))();
    }
  }
  return;
}

