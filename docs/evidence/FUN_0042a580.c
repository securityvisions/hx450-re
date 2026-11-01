

void __fastcall FUN_0042a580(int param_1)

{
  void *pvVar1;
  void *pvVar2;
  undefined *this;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int local_2c;
  int local_28;
  int local_24;
  undefined8 local_20;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055203c;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = param_1;
  FUN_0042b280(param_1);
  MUI::MListBox::DeleteAllItems(*(MListBox **)(param_1 + 0x38c));
  local_20 = 0;
  local_18 = 0;
  piVar9 = (int *)&local_20;
  local_8 = 0;
  iVar3 = *(int *)(param_1 + 0x7f4);
  this = FUN_0040f4c0();
  iVar3 = FUN_004086e0(this,iVar3,piVar9);
  pvVar2 = (void *)local_20;
  uVar8 = 0;
  local_24 = iVar3;
  if (0 < iVar3) {
    iVar4 = local_20._4_4_ - (int)(void *)local_20;
    do {
      if ((uint)(iVar4 >> 2) <= uVar8) {
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      pvVar1 = *(void **)((int)pvVar2 + uVar8 * 4);
      if (pvVar1 != (void *)0x0) {
        iVar10 = -1;
        lVar7 = *(long *)((int)pvVar1 + 0xc);
        FUN_0040cbd0(&stack0xffffffb0,L"KB.DIALOG");
        iVar5 = _wtoi(*(wchar_t **)((int)pvVar1 + 8));
        puVar6 = (undefined4 *)FUN_0043f8b0(&local_2c,iVar5,iVar3);
        local_8._0_1_ = 1;
        MUI::MListBox::AddString(*(MListBox **)(local_28 + 0x38c),(wchar_t *)*puVar6,lVar7,iVar10);
        local_8 = (uint)local_8._1_3_ << 8;
        LOCK();
        piVar9 = (int *)(local_2c + -4);
        iVar3 = *piVar9;
        *piVar9 = *piVar9 + -1;
        UNLOCK();
        if (iVar3 + -1 < 1) {
          (**(code **)(**(int **)(local_2c + -0x10) + 4))();
        }
        iVar5 = *(int *)((int)pvVar1 + 8);
        LOCK();
        piVar9 = (int *)(iVar5 + -4);
        iVar3 = *piVar9;
        *piVar9 = *piVar9 + -1;
        UNLOCK();
        if (iVar3 == 1 || iVar3 + -1 < 0) {
          (**(code **)(**(int **)(iVar5 + -0x10) + 4))();
        }
        FUN_004644e6(pvVar1);
        iVar3 = local_24;
      }
      uVar8 = uVar8 + 1;
      param_1 = local_28;
    } while ((int)uVar8 < iVar3);
  }
  local_20 = CONCAT44(pvVar2,(void *)local_20);
  if ((*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595140) &&
     (FUN_004646a0(&DAT_00595140), DAT_00595140 == -1)) {
    local_8._0_1_ = 2;
    memset(&DAT_005950d0,0,0x70);
    FUN_00401250();
    _atexit(thunk_FUN_00401370);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595140);
  }
  lVar7 = FUN_00408440(&DAT_005950d0,*(int *)(param_1 + 0x7f4));
  *(long *)(param_1 + 0x804) = lVar7;
  MUI::MListBox::SetCurData(*(MListBox **)(param_1 + 0x38c),lVar7);
  FUN_0042aa10(param_1);
  if (pvVar2 != (void *)0x0) {
    FUN_00405190(pvVar2,local_18 - (int)pvVar2 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


