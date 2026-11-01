

undefined * FUN_00413510(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054fe3c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595178) {
    FUN_004646a0(&DAT_00595178);
    if (DAT_00595178 == -1) {
      local_8 = 0;
      memset(&DAT_00595144,0,0x34);
      FUN_0044e680();
      _atexit(thunk_FUN_0044e780);
      FUN_00464661(&DAT_00595178);
    }
  }
  ExceptionList = local_10;
  return &DAT_00595144;
}


