

void __fastcall FUN_00433e20(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar5;
  void *unaff_EDI;
  wchar_t *pwVar6;
  int local_1c;
  wchar_t *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00552b04;
  local_10 = ExceptionList;
  uVar3 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  MUI::MComboBox::DelAllItems(*(MComboBox **)(param_1 + 0x394));
  iVar5 = 0x295;
  pwVar6 = (wchar_t *)0xa;
  iVar4 = extraout_ECX;
  do {
    FUN_0040cbd0(&stack0xffffffbc,L"KB.DIALOG");
    FUN_0043f8b0(&local_1c,iVar5,iVar4);
    local_8 = 0;
    MUI::MComboBox::AddItem(*(MComboBox **)(param_1 + 0x394));
    local_8 = 0xffffffff;
    LOCK();
    piVar1 = (int *)(local_1c + -4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    iVar4 = extraout_ECX_00;
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      (**(code **)(**(int **)(local_1c + -0x10) + 4))();
      iVar4 = extraout_ECX_01;
    }
    iVar5 = iVar5 + 1;
    pwVar6 = (wchar_t *)((int)pwVar6 + -1);
  } while (pwVar6 != (wchar_t *)0x0);
  local_18 = pwVar6;
  FUN_0040cbd0(&local_18,(short *)&PTR_005699cc);
  local_8 = 1;
  FUN_0040cbd0(&stack0xffffffc4,L"lightmode");
  local_8._0_1_ = 2;
  if (*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595140) {
    FUN_004646a0(&DAT_00595140);
    if (DAT_00595140 == -1) {
      local_8._0_1_ = 3;
      memset(&DAT_005950d0,0,0x70);
      FUN_00401250();
      _atexit(thunk_FUN_00401370);
      local_8._0_1_ = 2;
      FUN_00464661(&DAT_00595140);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00401940(&DAT_005950d0,*(int *)(param_1 + 0x7f4),uVar3,unaff_EDI);
  iVar4 = _wtoi(local_18);
  *(int *)(param_1 + 0x808) = iVar4 + 0x1f;
  MUI::MComboBox::SelectData(*(MComboBox **)(param_1 + 0x394),iVar4 + 0x1f);
  local_8 = 0xffffffff;
  LOCK();
  pwVar6 = local_18 + -2;
  iVar4 = *(int *)pwVar6;
  *(int *)pwVar6 = *(int *)pwVar6 + -1;
  UNLOCK();
  if (iVar4 == 1 || iVar4 + -1 < 0) {
    (**(code **)(**(int **)(local_18 + -8) + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


