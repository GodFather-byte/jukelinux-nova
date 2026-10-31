// JUKELINUX1_TFORM1_$__FORMKEYDOWN$TOBJECT$WORD$TSHIFTSTATE  @ 080c4cd0

/* WARNING: Removing unreachable block (ram,0x080c5145) */

void JUKELINUX1_TFORM1____FORMKEYDOWN_TOBJECT_WORD_TSHIFTSTATE(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  ushort *in_ECX;
  
  fpc_pushexceptaddr();
  iVar2 = fpc_setjmp();
  if (iVar2 == 0) {
    if (*in_ECX == 0x1b) {
      FORMS_TCUSTOMFORM____CLOSE();
    }
    if (U_JUKELINUX1_ALTERANDOFRASES == '\0') {
      if (((*in_ECX == U_JUKELINUX1_TECLACDMAIS) && (U_JUKELINUX1_MOSTRANDORITMOS == '\0')) &&
         (U_JUKELINUX1_MOSTRANDOLETRAS == '\0')) {
        JUKELINUX1_PRESSTECLA();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        if (U_JUKELINUX1_RODAVOLUME == 0) {
          if (U_JUKELINUX1_TECLAANTERIORRODAVOLUME == (char *)0x0) {
            U_JUKELINUX1_RODAVOLUME = 1;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = &__JUKELINUX1__Ld737;
          }
          else {
            U_JUKELINUX1_RODAVOLUME = 0;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char *)0x0;
          }
        }
        if (U_JUKELINUX1_RODAVOLUME == 3) {
          iVar3 = fpc_ansistr_compare_equal();
          if (iVar3 == 0) {
            U_JUKELINUX1_RODAVOLUME = 4;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = &__JUKELINUX1__Ld737;
          }
          else {
            U_JUKELINUX1_RODAVOLUME = 0;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char *)0x0;
          }
        }
        iVar3 = fpc_ansistr_compare_equal();
        if (((iVar3 == 0) && (U_JUKELINUX1_RODAVOLUME == 6)) &&
           (iVar3 = fpc_ansistr_compare_equal(), iVar3 == 0)) {
          U_JUKELINUX1_RODAVOLUME = 7;
          U_JUKELINUX1_VOLUMEATIVADO = '\x01';
          (**(code **)(*Form1.PanelMenu2grande + 0xd8))();
          (**(code **)(*Form1.PanelMenu2grande + 0xd8))();
        }
        if (U_JUKELINUX1_VOLUMEATIVADO == '\0') {
          (**(code **)(*Form1.TimerPaginaMenos + 0xd8))();
          U_JUKELINUX1_SEGURANDOTECLA = U_JUKELINUX1_SEGURANDOTECLA + 1;
        }
        else {
          JUKELINUX1_ROTINA_VOLUMEMAIS();
        }
      }
      if (((*in_ECX == U_JUKELINUX1_TECLACDMENOS) && (U_JUKELINUX1_MOSTRANDORITMOS == '\0')) &&
         (U_JUKELINUX1_MOSTRANDOLETRAS == '\0')) {
        JUKELINUX1_PRESSTECLA();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        if (U_JUKELINUX1_RODAVOLUME == 2) {
          iVar3 = fpc_ansistr_compare_equal();
          if (iVar3 == 0) {
            U_JUKELINUX1_RODAVOLUME = 3;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = &__JUKELINUX1__Ld738;
          }
          else {
            U_JUKELINUX1_RODAVOLUME = 0;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char *)0x0;
          }
        }
        if (U_JUKELINUX1_RODAVOLUME == 5) {
          iVar3 = fpc_ansistr_compare_equal();
          if (iVar3 == 0) {
            U_JUKELINUX1_RODAVOLUME = 6;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = &__JUKELINUX1__Ld738;
          }
          else {
            U_JUKELINUX1_RODAVOLUME = 0;
            fpc_ansistr_decr_ref();
            U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char *)0x0;
          }
        }
        if (U_JUKELINUX1_VOLUMEATIVADO == '\0') {
          (**(code **)(*Form1.TimerPaginaMais + 0xd8))();
          U_JUKELINUX1_SEGURANDOTECLA = U_JUKELINUX1_SEGURANDOTECLA + 1;
        }
        else {
          JUKELINUX1_ROTINA_VOLUMEMENOS();
        }
      }
      if (*in_ECX == U_JUKELINUX1_TECLAMUSICAMENOS) {
        JUKELINUX1_PRESSTECLA();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        if (U_JUKELINUX1_MUSICASELECIONADA <
            (int)(&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90]) {
          JUKELINUX1_DESSELECIONAMUSICA();
          U_JUKELINUX1_MUSICASELECIONADA = U_JUKELINUX1_MUSICASELECIONADA + 1;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = U_JUKELINUX1_MUSICASELECIONADAPOSTELA + 1;
          if (0xc < U_JUKELINUX1_MUSICASELECIONADAPOSTELA) {
            U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0xc;
          }
          JUKELINUX1_SELECIONAMUSICA();
          if (U_JUKELINUX1_RODAVOLUME == 1) {
            iVar3 = fpc_ansistr_compare_equal();
            if (iVar3 == 0) {
              U_JUKELINUX1_RODAVOLUME = 2;
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_TECLAANTERIORRODAVOLUME = __JUKELINUX1__Ld740;
            }
            else {
              U_JUKELINUX1_RODAVOLUME = 0;
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char *)0x0;
            }
          }
          if (U_JUKELINUX1_RODAVOLUME == 4) {
            iVar3 = fpc_ansistr_compare_equal();
            if (iVar3 == 0) {
              U_JUKELINUX1_RODAVOLUME = 5;
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_TECLAANTERIORRODAVOLUME = __JUKELINUX1__Ld740;
            }
            else {
              U_JUKELINUX1_RODAVOLUME = 0;
              fpc_ansistr_decr_ref();
              U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char *)0x0;
            }
          }
          if (U_JUKELINUX1_VOLUMEATIVADO != '\0') {
            JUKELINUX1_DESATIVA_VOLUME_PELO_PAINEL();
          }
        }
        else {
          JUKELINUX1_DESSELECIONAMUSICA();
          U_JUKELINUX1_MUSICASELECIONADA = 1;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 1;
          JUKELINUX1_SELECIONAMUSICA();
          JUKELINUX1_MOSTRA_MUSICAS_LONGINT();
        }
        if ((U_JUKELINUX1_ESTANOMENU != '\0') && (U_JUKELINUX1_SENHAOK == 1)) {
          fpc_ansistr_decr_ref();
          CONTROLS_TCONTROL____GETTEXT__TTRANSLATESTRING();
          iVar3 = fpc_ansistr_compare_equal();
          if (iVar3 == 0) {
            cVar1 = SYSUTILS_DIRECTORYEXISTS_ANSISTRING__BOOLEAN();
            if (cVar1 == '\0') {
              CONTROLS_TCONTROL____SETLEFT_LONGINT();
              CONTROLS_TCONTROL____SETTOP_LONGINT();
              if (U_JUKELINUX1_RESOLUCAO == 0x400) {
                CONTROLS_TCONTROL____SETWIDTH_LONGINT();
              }
              if (U_JUKELINUX1_RESOLUCAO == 0x556) {
                CONTROLS_TCONTROL____SETWIDTH_LONGINT();
              }
              if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
                CONTROLS_TCONTROL____SETWIDTH_LONGINT();
              }
              CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
              CONTROLS_TCONTROL____SETLEFT_LONGINT();
              CONTROLS_TCONTROL____SHOW();
              (**(code **)(*Form1.CapaE1 + 0x2fc))();
              CONTROLS_TCONTROL____REFRESH();
              (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
              JUKELINUX1_EXCLUICDPELALISTA();
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              CONTROLS_TCONTROL____REFRESH();
              (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
              JUKELINUX1_TFORM1____BUTTONMUSCARREGARCLICK_TOBJECT();
              CONTROLS_TCONTROL____REFRESH();
              (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
              SYSUTILS_SLEEP_LONGWORD();
              CONTROLS_TCONTROL____HIDE();
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              CONTROLS_TCONTROL____REFRESH();
              (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
            }
            else {
              CONTROLS_TCONTROL____SETLEFT_LONGINT();
              CONTROLS_TCONTROL____SETTOP_LONGINT();
              if (U_JUKELINUX1_RESOLUCAO == 0x400) {
                CONTROLS_TCONTROL____SETWIDTH_LONGINT();
              }
              if (U_JUKELINUX1_RESOLUCAO == 0x556) {
                CONTROLS_TCONTROL____SETWIDTH_LONGINT();
              }
              if (U_JUKELINUX1_RESOLUCAO == 0x5a0) {
                CONTROLS_TCONTROL____SETWIDTH_LONGINT();
              }
              CONTROLS_TCONTROL____SETHEIGHT_LONGINT();
              CONTROLS_TCONTROL____SHOW();
              (**(code **)(*Form1.Musica12 + 0x2fc))();
              CONTROLS_TCONTROL____REFRESH();
              (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
              JUKELINUX1_TFORM1____BUTTONUPGRADECLICK_TOBJECT();
              SYSUTILS_SLEEP_LONGWORD();
              CONTROLS_TCONTROL____HIDE();
              CONTROLS_TCONTROL____REFRESH();
              (**(code **)(*U_JUKELINUX1_FORM1 + 0x2fc))();
              GRAPHICS_TFONT____SETCOLOR_TGRAPHICSCOLOR();
              CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
            }
          }
        }
      }
      if (*in_ECX == U_JUKELINUX1_TECLAMUSICAMAIS) {
        JUKELINUX1_PRESSTECLA();
        U_JUKELINUX1_TEMPOPALHINHA = 0;
        U_JUKELINUX1_MUDOUDECDOUMUSICA = 1;
        U_JUKELINUX1_RODAVOLUME = 0;
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_TECLAANTERIORRODAVOLUME = (char *)0x0;
        if (U_JUKELINUX1_MUSICASELECIONADAPOSTELA < 1) {
          JUKELINUX1_MOSTRA_MUSICAS_LONGINT();
          U_JUKELINUX1_MUSICASELECIONADA =
               (&U_JUKELINUX1_NOMEDOCLIENTE)[(U_JUKELINUX1_KMAT + 5) * 0x90];
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = U_JUKELINUX1_MUSICASELECIONADA;
          if (0xc < U_JUKELINUX1_MUSICASELECIONADA) {
            U_JUKELINUX1_MUSICASELECIONADAPOSTELA = 0xc;
          }
          JUKELINUX1_SELECIONAMUSICA();
        }
        else {
          JUKELINUX1_DESSELECIONAMUSICA();
          U_JUKELINUX1_MUSICASELECIONADA = U_JUKELINUX1_MUSICASELECIONADA + -1;
          U_JUKELINUX1_MUSICASELECIONADAPOSTELA = U_JUKELINUX1_MUSICASELECIONADAPOSTELA + -1;
          JUKELINUX1_SELECIONAMUSICA();
        }
        if (U_JUKELINUX1_VOLUMEATIVADO != '\0') {
          JUKELINUX1_DESATIVA_VOLUME_PELO_PAINEL();
        }
      }
      if (*in_ECX == U_JUKELINUX1_TECLACRMAIS) {
        JUKELINUX1_PRESSTECLA();
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          if (U_JUKELINUX1_TOQUEVOLUMEMENOS == 1) {
            U_JUKELINUX1_TOQUEVOLUMEMENOS = 0;
            (**(code **)(*Form1.TimerMostraNomeDeMusicas + 0xd8))();
            U_JUKELINUX1_TOQUEVOLUMEMAIS = 1;
          }
          if (U_JUKELINUX1_TOQUEVOLUMEMAIS == 1) {
            U_JUKELINUX1_TOQUEVOLUMEMAIS = 2;
            (**(code **)(*Form1.EditKaraoke + 0xd8))();
            U_JUKELINUX1_TOQUEVOLUMEMENOS = 0;
            (**(code **)(*Form1.TimerMostraNomeDeMusicas + 0xd8))();
          }
          if (U_JUKELINUX1_TOQUEVOLUMEMAIS == 0) {
            U_JUKELINUX1_TOQUEVOLUMEMAIS = 1;
            (**(code **)(*Form1.EditKaraoke + 0xd8))();
          }
          if (U_JUKELINUX1_TOQUEVOLUMEMAIS == 2) {
            U_JUKELINUX1_TOQUEVOLUMEMAIS = 0;
          }
        }
        else {
          JUKELINUX1_ROTINA_VOLUMEMAIS();
        }
      }
      if (*in_ECX == U_JUKELINUX1_TECLACRMENOS) {
        JUKELINUX1_PRESSTECLA();
        iVar3 = fpc_ansistr_compare_equal();
        if (iVar3 == 0) {
          if (U_JUKELINUX1_TOQUEVOLUMEMAIS == 1) {
            U_JUKELINUX1_TOQUEVOLUMEMAIS = 0;
            (**(code **)(*Form1.EditKaraoke + 0xd8))();
            U_JUKELINUX1_TOQUEVOLUMEMENOS = 1;
          }
          if (U_JUKELINUX1_TOQUEVOLUMEMENOS == 1) {
            U_JUKELINUX1_TOQUEVOLUMEMENOS = 2;
            (**(code **)(*Form1.TimerMostraNomeDeMusicas + 0xd8))();
            U_JUKELINUX1_TOQUEVOLUMEMAIS = 0;
            (**(code **)(*Form1.EditKaraoke + 0xd8))();
          }
          if (U_JUKELINUX1_TOQUEVOLUMEMENOS == 0) {
            U_JUKELINUX1_TOQUEVOLUMEMENOS = 1;
            (**(code **)(*Form1.TimerMostraNomeDeMusicas + 0xd8))();
          }
          if (U_JUKELINUX1_TOQUEVOLUMEMENOS == 2) {
            U_JUKELINUX1_TOQUEVOLUMEMENOS = 0;
          }
        }
        else {
          JUKELINUX1_ROTINA_VOLUMEMENOS();
        }
      }
    }
  }
  fpc_popaddrstack();
  fpc_ansistr_decr_ref();
  if (iVar2 != 0) {
    fpc_reraise();
  }
  return;
}

