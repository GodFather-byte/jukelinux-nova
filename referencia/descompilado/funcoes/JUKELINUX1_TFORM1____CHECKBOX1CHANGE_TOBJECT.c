// JUKELINUX1_TFORM1_$__CHECKBOX1CHANGE$TOBJECT  @ 080d8250

void JUKELINUX1_TFORM1____CHECKBOX1CHANGE_TOBJECT(void)

{
  char cVar1;
  int in_EAX;
  
  cVar1 = (**(code **)(**(int **)(in_EAX + 0x5b0) + 0x450))();
  if (cVar1 != '\0') {
    CONTROLS_TCONTROL____SHOW();
    CONTROLS_TCONTROL____SHOW();
  }
  return;
}

