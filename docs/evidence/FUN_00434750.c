

void __fastcall FUN_00434750(void *param_1)

{
  if ((*(byte *)((int)param_1 + 0x7a4) & 2) != 0) {
    FUN_0042c720(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 1) != 0) {
    FUN_004170d0(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 4) != 0) {
    FUN_0042a580((int)param_1);
  }
  if ((*(uint *)((int)param_1 + 0x7a4) & 0x100) != 0) {
    FUN_00433e20((int)param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 0x10) != 0) {
    FUN_00449370(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 8) != 0) {
    FUN_004277d0(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 0x20) != 0) {
    FUN_00432cd0(param_1);
  }
  if (*(int *)((int)param_1 + 0x784) == 0) {
    if ((*(byte *)((int)param_1 + 0x7a4) & 0x80) == 0) goto LAB_00434830;
LAB_004347ee:
    FUN_00420c90(param_1);
  }
  else if ((*(int *)((int)param_1 + 0x784) == 2) && (*(int *)((int)param_1 + 0x7a8) != 0))
  goto LAB_004347ee;
  if (((*(byte *)((int)param_1 + 0x7a4) & 0x80) != 0) && (*(char *)((int)param_1 + 0x527c0) != '\0')
     ) {
    if (*(int *)((int)param_1 + 0x784) == 0) {
      FUN_00423a80((int)param_1);
      FUN_00413880((int)param_1);
      return;
    }
    if (*(int *)((int)param_1 + 0x784) == 2) {
      FUN_00423bb0((int)param_1);
    }
  }
LAB_00434830:
  FUN_00413880((int)param_1);
  return;
}


