// JUKELINUX1_TFORM1_$__TIMERPAGINASOZINHOTIMER$TOBJECT  @ 080e30b0

void JUKELINUX1_TFORM1____TIMERPAGINASOZINHOTIMER_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  
  U_JUKELINUX1_TEMPOEMSEGUNDOSPAGINARSOZINHO = U_JUKELINUX1_TEMPOEMSEGUNDOSPAGINARSOZINHO + 1;
  if (U_JUKELINUX1_TEMPOEMSEGUNDOSPAGINARSOZINHO == U_JUKELINUX1_TEMPOPARAPAGINARSOZINHO) {
    iVar1 = fpc_ansistr_compare_equal();
    if ((iVar1 == 0) && (U_JUKELINUX1_TOTALCDS <= U_JUKELINUX1_KMAT + 4)) {
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_DIRECAO = &__JUKELINUX1__Ld1020;
    }
    iVar1 = fpc_ansistr_compare_equal();
    if ((iVar1 == 0) && (U_JUKELINUX1_KMAT == -3)) {
      fpc_ansistr_decr_ref();
      U_JUKELINUX1_DIRECAO = __JUKELINUX1__Ld727;
    }
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      (**(code **)(**(int **)(in_EAX + 0xbcc) + 0xd8))();
    }
    iVar1 = fpc_ansistr_compare_equal();
    if (iVar1 == 0) {
      (**(code **)(**(int **)(in_EAX + 0xbd0) + 0xd8))();
    }
    U_JUKELINUX1_SEGURANDOTECLA = 0;
    U_JUKELINUX1_TEMPOEMSEGUNDOSPAGINARSOZINHO =
         (int)(U_JUKELINUX1_TEMPOPARAPAGINARSOZINHO +
              (U_JUKELINUX1_TEMPOPARAPAGINARSOZINHO >> 0x1f & 3U)) >> 2;
  }
  return;
}

