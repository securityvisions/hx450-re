

void __fastcall FUN_00414410(int param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 *puVar6;
  uint uVar7;
  wchar_t **ppwVar8;
  wchar_t *local_5c;
  undefined1 local_58 [5];
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4c;
  undefined2 local_46;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00550010;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  memset(local_58,0,0x41);
  local_58._1_4_ = 0x1007;
  local_53 = 1;
  iVar2 = MUI::CCheckButton::GetCheck(*(CCheckButton **)(param_1 + 0x678));
  iVar3 = MUI::CCheckButton::GetCheck(*(CCheckButton **)(param_1 + 0x67c));
  iVar4 = MUI::CCheckButton::GetCheck(*(CCheckButton **)(param_1 + 0x680));
  local_5c = (wchar_t *)0x0;
  if (iVar2 != 0) {
    local_52 = 1;
  }
  if (iVar3 != 0) {
    local_51 = 1;
  }
  if (iVar4 != 0) {
    local_50 = 1;
  }
  FUN_0040cbd0(&local_5c,(short *)&PTR_005699cc);
  ppwVar8 = &local_5c;
  local_8 = 0;
  iVar3 = extraout_ECX;
  FUN_0040cbd0(&stack0xffffff84,L"fn_switch");
  local_8._0_1_ = 1;
  iVar2 = *(int *)(param_1 + 0x7f4);
  puVar5 = FUN_0040f4c0();
  local_8._0_1_ = 0;
  FUN_00401940(puVar5,iVar2,iVar3,ppwVar8);
  iVar2 = _wtoi(local_5c);
  local_4f = (undefined1)iVar2;
  ppwVar8 = &local_5c;
  iVar3 = extraout_ECX_00;
  FUN_0040cbd0(&stack0xffffff84,L"sleep_time");
  local_8._0_1_ = 2;
  iVar2 = *(int *)(param_1 + 0x7f4);
  puVar5 = FUN_0040f4c0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00401940(puVar5,iVar2,iVar3,ppwVar8);
  if (*(int *)(local_5c + -6) == 0) {
    FUN_004050e0(&local_5c,&DAT_0056d42c,1);
  }
  iVar2 = _wtoi(local_5c);
  local_4e = (undefined1)iVar2;
  ppwVar8 = &local_5c;
  iVar3 = extraout_ECX_01;
  FUN_0040cbd0(&stack0xffffff84,L"key_respondtime");
  local_8._0_1_ = 3;
  iVar2 = *(int *)(param_1 + 0x7f4);
  puVar5 = FUN_0040f4c0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00401940(puVar5,iVar2,iVar3,ppwVar8);
  if (*(int *)(local_5c + -6) == 0) {
    FUN_004050e0(&local_5c,&DAT_0056d42c,1);
  }
  iVar2 = _wtoi(local_5c);
  local_4c = (undefined1)iVar2;
  puVar6 = (undefined4 *)local_58;
  uVar7 = 0x41;
  local_46 = 0x55aa;
  puVar5 = FUN_00413510();
  FUN_0044f4d0(puVar5,puVar6,uVar7);
  local_8 = 0xffffffff;
  LOCK();
  pwVar1 = local_5c + -2;
  iVar2 = *(int *)pwVar1;
  *(int *)pwVar1 = *(int *)pwVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(**(int **)(local_5c + -8) + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


