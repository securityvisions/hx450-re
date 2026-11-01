

void __fastcall FUN_004141a0(int param_1)

{
  wchar_t *pwVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 *puVar6;
  uint uVar7;
  char cVar8;
  wchar_t **ppwVar9;
  wchar_t *local_5c;
  undefined2 local_58;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_50;
  undefined2 local_1a;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00550010;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  memset((void *)((int)&local_58 + 1),0,0x40);
  local_58 = 0x1804;
  puVar6 = (undefined4 *)&local_58;
  cVar8 = '\x01';
  uVar7 = 0x41;
  puVar2 = FUN_00413510();
  FUN_0044edb0(puVar2,puVar6,uVar7,cVar8);
  cVar8 = '\x01';
  puVar6 = (undefined4 *)&local_58;
  local_58 = 0x1704;
  uVar7 = 0x41;
  local_56 = 1;
  local_50 = 1;
  puVar2 = FUN_00413510();
  FUN_0044edb0(puVar2,puVar6,uVar7,cVar8);
  memset(&local_58,0,0x41);
  local_58 = 0x100;
  iVar3 = MUI::CCheckButton::GetCheck(*(CCheckButton **)(param_1 + 0x678));
  iVar4 = MUI::CCheckButton::GetCheck(*(CCheckButton **)(param_1 + 0x67c));
  iVar5 = MUI::CCheckButton::GetCheck(*(CCheckButton **)(param_1 + 0x680));
  local_5c = (wchar_t *)0x0;
  if (iVar3 != 0) {
    local_56 = 1;
  }
  if (iVar4 != 0) {
    local_55 = 1;
  }
  if (iVar5 != 0) {
    local_54 = 1;
  }
  FUN_0040cbd0(&local_5c,(short *)&PTR_005699cc);
  ppwVar9 = &local_5c;
  local_8 = 0;
  iVar4 = extraout_ECX;
  FUN_0040cbd0(&stack0xffffff84,L"fn_switch");
  local_8._0_1_ = 1;
  iVar3 = *(int *)(param_1 + 0x7f4);
  puVar2 = FUN_0040f4c0();
  local_8._0_1_ = 0;
  FUN_00401940(puVar2,iVar3,iVar4,ppwVar9);
  iVar3 = _wtoi(local_5c);
  local_53 = (undefined1)iVar3;
  ppwVar9 = &local_5c;
  iVar4 = extraout_ECX_00;
  FUN_0040cbd0(&stack0xffffff84,L"sleep_time");
  local_8._0_1_ = 2;
  iVar3 = *(int *)(param_1 + 0x7f4);
  puVar2 = FUN_0040f4c0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00401940(puVar2,iVar3,iVar4,ppwVar9);
  if (*(int *)(local_5c + -6) == 0) {
    FUN_004050e0(&local_5c,&DAT_0056d42c,1);
  }
  iVar3 = _wtoi(local_5c);
  local_52 = (undefined1)iVar3;
  ppwVar9 = &local_5c;
  iVar4 = extraout_ECX_01;
  FUN_0040cbd0(&stack0xffffff84,L"key_respondtime");
  local_8._0_1_ = 3;
  iVar3 = *(int *)(param_1 + 0x7f4);
  puVar2 = FUN_0040f4c0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00401940(puVar2,iVar3,iVar4,ppwVar9);
  if (*(int *)(local_5c + -6) == 0) {
    FUN_004050e0(&local_5c,&DAT_0056d42c,1);
  }
  iVar3 = _wtoi(local_5c);
  local_50 = (undefined1)iVar3;
  puVar6 = (undefined4 *)&local_58;
  local_1a = 0x55aa;
  cVar8 = '\0';
  uVar7 = 0x41;
  puVar2 = FUN_00413510();
  FUN_0044edb0(puVar2,puVar6,uVar7,cVar8);
  memset(&local_58,0,0x41);
  local_58 = 0x204;
  puVar6 = (undefined4 *)&local_58;
  cVar8 = '\x01';
  uVar7 = 0x41;
  puVar2 = FUN_00413510();
  FUN_0044edb0(puVar2,puVar6,uVar7,cVar8);
  local_8 = 0xffffffff;
  LOCK();
  pwVar1 = local_5c + -2;
  iVar3 = *(int *)pwVar1;
  *(int *)pwVar1 = *(int *)pwVar1 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)(local_5c + -8) + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


