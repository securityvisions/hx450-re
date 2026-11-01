

void __fastcall FUN_00434840(void *param_1)

{
  if (*(int *)((int)param_1 + 0x784) == 0) {
    FUN_00418550(param_1,0);
    if (*(int *)((int)param_1 + 0x7b0) != 0) {
      FUN_00418550(param_1,1);
      return;
    }
  }
  else if (*(int *)((int)param_1 + 0x784) == 2) {
    Sleep(10);
    FUN_00418df0(param_1,0);
    if (*(int *)((int)param_1 + 0x7b0) != 0) {
      FUN_00418df0(param_1,1);
    }
  }
  return;
}


