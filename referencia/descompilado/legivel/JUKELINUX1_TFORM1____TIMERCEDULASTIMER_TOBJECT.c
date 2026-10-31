// JUKELINUX1_TFORM1_$__TIMERCEDULASTIMER$TOBJECT  @ 080e0d80

void JUKELINUX1_TFORM1____TIMERCEDULASTIMER_TOBJECT(void)

{
  int in_EAX;
  int iVar1;
  
  fpc_pushexceptaddr();
  iVar1 = fpc_setjmp();
  if (iVar1 == 0) {
    (**(code **)(*Form1.LabelKaraoke + 0xd8))();
    if (U_JUKELINUX1_CREDITOSCEDULAS == 1) {
      U_JUKELINUX1_CREDITOSCEDULAS = 0;
    }
    if (U_JUKELINUX1_CREDITOSCEDULAS == 2) {
      U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 1;
    }
    if (U_JUKELINUX1_CREDITOSCEDULAS == 5) {
      U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 5;
    }
    if (U_JUKELINUX1_CREDITOSCEDULAS == 10) {
      U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 10;
    }
    if (U_JUKELINUX1_CREDITOSCEDULAS == 0x14) {
      U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 0x14;
    }
    if (U_JUKELINUX1_CREDITOSCEDULAS == 0x32) {
      U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 0x32;
    }
    if (U_JUKELINUX1_CREDITOSCEDULAS == 100) {
      U_JUKELINUX1_CREDITOS = U_JUKELINUX1_CREDITOS + 100;
    }
    if (U_JUKELINUX1_CREDITOSCEDULAS != 1) {
      U_JUKELINUX1_CREDITOSCEDULAS = 0;
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
      (**(code **)(*Form1.PanelUpgrade1 + 0xd8))();
      (**(code **)(*Form1.PanelUpgrade1 + 0xd8))();
      U_JUKELINUX1_JAGRAVOUNOPENDRIVE = 1;
    }
  }
  fpc_popaddrstack();
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

