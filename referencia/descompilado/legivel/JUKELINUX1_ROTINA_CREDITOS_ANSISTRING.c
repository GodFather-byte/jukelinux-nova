// JUKELINUX1_ROTINA_CREDITOS$ANSISTRING  @ 080aab80

void JUKELINUX1_ROTINA_CREDITOS_ANSISTRING(void)

{
  int iVar1;
  int iVar2;
  
  fpc_ansistr_incr_ref();
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    if (U_JUKELINUX1_SENHAOK == 0) {
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
        }
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
        }
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
        }
        iVar2 = fpc_ansistr_compare_equal();
        if ((iVar2 == 0) &&
           (U_JUKELINUX1_CREDITOSTEMP = U_JUKELINUX1_CREDITOSTEMP + 1,
           U_JUKELINUX1_CREDITOSTEMP == 2)) {
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
          U_JUKELINUX1_CREDITOSTEMP = 0;
        }
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
        }
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 2;
        }
        iVar2 = fpc_ansistr_compare_equal();
        if (iVar2 == 0) {
          U_JUKELINUX1_CREDITOSCEDULAS = U_JUKELINUX1_CREDITOSCEDULAS + 1;
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
          (**(code **)(*Form1.LabelKaraoke + 0xd8))();
          (**(code **)(*Form1.LabelPress1 + 0xdc))();
          (**(code **)(*Form1.LabelKaraoke + 0xd8))();
        }
        iVar2 = fpc_ansistr_compare_equal();
        if ((iVar2 == 0) &&
           (U_JUKELINUX1_CREDITOSTEMP = U_JUKELINUX1_CREDITOSTEMP + 1,
           U_JUKELINUX1_CREDITOSTEMP == 2)) {
          U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
          U_JUKELINUX1_CREDITOSTEMP = 0;
        }
      }
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
      (**(code **)(*Form1.LabelUpgrade1 + 0xd8))();
      (**(code **)(*Form1.LabelUpgrade1 + 0xd8))();
      U_JUKELINUX1_MOSTRANDOCREDITO = 1;
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        U_JUKELINUX1_RELOGIOTOTAL = U_JUKELINUX1_RELOGIOTOTAL + 1;
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        FPC_ANSISTR_TO_SHORTSTR();
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        SYSTEM_REWRITE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_incr_ref();
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_RELOGIOTOTALSTR = 0;
        fpc_ansistr_decr_ref();
        JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
        fpc_ansistr_incr_ref();
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_RELOGIOTOTALSTR = 0;
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        SYSTEM_FLUSH_TEXT();
        fpc_iocheck();
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
        U_JUKELINUX1_RELOGIOPARCIAL = U_JUKELINUX1_RELOGIOPARCIAL + 1;
        fpc_ansistr_decr_ref();
        fpc_ansistr_concat();
        FPC_ANSISTR_TO_SHORTSTR();
        OBJPAS_ASSIGNFILE_TEXT_SHORTSTRING();
        SYSTEM_REWRITE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_incr_ref();
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_RELOGIOPARCIALSTR = 0;
        fpc_ansistr_decr_ref();
        JUKELINUX1_CRIPTA_ANSISTRING__ANSISTRING();
        fpc_ansistr_incr_ref();
        fpc_ansistr_decr_ref();
        U_JUKELINUX1_RELOGIOPARCIALSTR = 0;
        fpc_write_text_ansistr();
        fpc_iocheck();
        fpc_writeln_end();
        fpc_iocheck();
        SYSTEM_FLUSH_TEXT();
        fpc_iocheck();
        OBJPAS_CLOSEFILE_TEXT();
        fpc_iocheck();
        fpc_ansistr_decr_ref();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_decr_ref();
        SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
        fpc_ansistr_concat_multi();
        JUKELINUX1_GRAVALOG_ANSISTRING();
      }
      iVar2 = fpc_ansistr_compare_equal();
      if (iVar2 == 0) {
        U_JUKELINUX1_PALHINHASPORREAL =
             U_JUKELINUX1_PALHINHASPORREAL + U_JUKELINUX1_PALHINHASPORREALCONFIG;
        U_JUKELINUX1_PULSOSPARACARTAO = U_JUKELINUX1_PULSOSPARACARTAO + 1;
        U_JUKELINUX1_PULSOSPARASORTEIO = U_JUKELINUX1_PULSOSPARASORTEIO + 1;
        (**(code **)(*Form1.LabelVE + 0xd8))();
        (**(code **)(*Form1.LabelVE + 0xd8))();
      }
      (**(code **)(*Form1.PanelUpgrade1 + 0xd8))();
      (**(code **)(*Form1.PanelUpgrade1 + 0xd8))();
      U_JUKELINUX1_JAGRAVOUNOPENDRIVE = 1;
    }
    else {
      U_JUKELINUX1_CREDITOSTESTE = U_JUKELINUX1_CREDITOSTESTE + 1;
      fpc_ansistr_decr_ref();
      fpc_ansistr_decr_ref();
      SYSUTILS_INTTOSTR_LONGINT__ANSISTRING();
      fpc_ansistr_concat();
      CONTROLS_TCONTROL____SETTEXT_TTRANSLATESTRING();
      (**(code **)(*Form1.ComboBox19 + 0x2fc))();
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

