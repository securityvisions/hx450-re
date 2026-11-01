

void FUN_0043f8b0(void *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  LPCWSTR pWVar3;
  LPCWSTR pWVar4;
  int local_28;
  undefined1 *local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_005534b8;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = 0;
  FUN_0040cbd0(&local_20,(short *)&PTR_005699cc);
  local_8._0_1_ = 1;
  local_1c = 0;
  FUN_0040cbd0(&local_1c,(short *)&PTR_005699cc);
  local_8._0_1_ = 2;
  local_18 = 0;
  FUN_0040cbd0(&local_18,(short *)&PTR_005699cc);
  local_8._0_1_ = 3;
  FUN_00405650(&local_1c,0x56aa54);
  FUN_0040e870(&local_28);
  local_8._0_1_ = 4;
  FUN_00405650(&local_18,0x56ceb4);
  local_8._0_1_ = 3;
  LOCK();
  piVar2 = (int *)(local_28 + -4);
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(**(int **)(local_28 + -0x10) + 4))();
  }
  piVar2 = FUN_00405020((int *)(local_18 + -0x10));
  pWVar4 = (LPCWSTR)(piVar2 + 4);
  local_24 = &stack0xffffffb0;
  local_8._0_1_ = 5;
  piVar2 = FUN_00405020((int *)(local_1c + -0x10));
  pWVar3 = (LPCWSTR)(piVar2 + 4);
  local_24 = &stack0xffffffac;
  local_8._0_1_ = 6;
  piVar2 = FUN_00405020((int *)(param_3 + -0x10));
  local_8._0_1_ = 3;
  FUN_0040e8f0(param_1,(LPCWSTR)(piVar2 + 4),pWVar3,pWVar4);
  local_8._0_1_ = 2;
  LOCK();
  piVar2 = (int *)(local_18 + -4);
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(**(int **)(local_18 + -0x10) + 4))();
  }
  local_8._0_1_ = 1;
  LOCK();
  piVar2 = (int *)(local_1c + -4);
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(**(int **)(local_1c + -0x10) + 4))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  LOCK();
  piVar2 = (int *)(local_20 + -4);
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(**(int **)(local_20 + -0x10) + 4))();
  }
  local_8 = 0xffffffff;
  LOCK();
  piVar2 = (int *)(param_3 + -4);
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(**(int **)(param_3 + -0x10) + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


