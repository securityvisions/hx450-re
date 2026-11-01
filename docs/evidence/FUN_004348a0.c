

void __fastcall FUN_004348a0(void *param_1)

{
  if (*(int *)((int)param_1 + 0x784) == 0) {
    if (*(int *)((int)param_1 + 0x7fc) == 0) {
      FUN_00418550(param_1,0);
      return;
    }
    if ((*(int *)((int)param_1 + 0x7fc) == 1) && (*(int *)((int)param_1 + 0x7b0) != 0)) {
      FUN_00418550(param_1,1);
      return;
    }
  }
  else if (*(int *)((int)param_1 + 0x784) == 2) {
    if (*(int *)((int)param_1 + 0x7fc) == 0) {
      FUN_00419130(param_1,0);
      return;
    }
    if (*(int *)((int)param_1 + 0x7fc) == 1) {
      FUN_00419130(param_1,1);
    }
  }
  return;
}


