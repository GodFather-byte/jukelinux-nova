// JUKELINUX1_TFORM1_$__TIMERTOCANDOTVTIMER$TOBJECT  @ 080e5ea0

void JUKELINUX1_TFORM1____TIMERTOCANDOTVTIMER_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  
  cVar1 = MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____PLAYING__BOOLEAN();
  if (cVar1 == '\0') {
    (**(code **)(**(int **)(in_EAX + 0xb6c) + 0xd8))();
    MPLAYERCTRL_TCUSTOMMPLAYERCONTROL____STOP();
    CONTROLS_TCONTROL____HIDE();
    (**(code **)(**(int **)(in_EAX + 0xba8) + 0xd8))();
    U_JUKELINUX1_TOCANDOVIDEOTV = 0;
  }
  return;
}

