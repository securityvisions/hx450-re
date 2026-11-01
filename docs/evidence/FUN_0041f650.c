

void __fastcall FUN_0041f650(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  undefined8 *puVar9;
  int iVar10;
  int local_24;
  undefined8 local_20;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00550fec;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined1 *)(param_1 + 0x775) = 0;
  piVar2 = (int *)FUN_00413510();
  piVar2[9] = 0;
  FUN_0044e910(piVar2);
  FUN_0044f950(piVar2);
  *piVar2 = 1;
  piVar2[1] = 0;
  iVar3 = FUN_00420130();
  puVar4 = FUN_00413510();
  *(undefined4 *)(puVar4 + 0x20) = 0;
  *(undefined4 *)(puVar4 + 0x24) = 0;
  local_20 = 0;
  local_18 = 0;
  puVar9 = &local_20;
  local_8 = 0;
  puVar4 = FUN_00413510();
  FUN_0044eac0(puVar4,puVar9);
  MUI::CDeviceList::SetAllDeviceState(*(CDeviceList **)(param_1 + 0x340),0);
  uVar7 = 0;
  uVar6 = local_20._4_4_ - (int)(void *)local_20 >> 2;
  if (uVar6 != 0) {
    do {
      if (uVar6 <= uVar7) goto LAB_0041f8da;
      iVar1 = *(int *)((int)(void *)local_20 + uVar7 * 4);
      if (iVar1 != 0) {
        MUI::CDeviceList::SetDeviceState
                  (*(CDeviceList **)(param_1 + 0x340),*(int *)(iVar1 + 0x41c),1);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar6);
  }
  MUI::CDeviceList::SetSelectDevice(*(CDeviceList **)(param_1 + 0x340),iVar3);
  uVar7 = 0;
  iVar3 = (*(int *)(param_1 + 0x79c) - *(int *)(param_1 + 0x798)) / 0x34;
  if (0 < iVar3) {
    local_24 = 0;
    do {
      iVar1 = *(int *)(param_1 + 0x798);
      if ((uint)((*(int *)(param_1 + 0x79c) - iVar1) / 0x34) <= uVar7) {
LAB_0041f8da:
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      iVar10 = *(int *)(local_24 + 0xc + iVar1);
      piVar2 = FUN_00405020((int *)(*(int *)(local_24 + iVar1) + -0x10));
      pcVar8 = (code *)(piVar2 + 4);
      local_8._0_1_ = 1;
      if (*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595178) {
        FUN_004646a0(&DAT_00595178);
        if (DAT_00595178 == -1) {
          local_8._0_1_ = 2;
          memset(&DAT_00595144,0,0x34);
          FUN_0044e680();
          pcVar8 = thunk_FUN_0044e780;
          _atexit(thunk_FUN_0044e780);
          local_8._0_1_ = 1;
          FUN_00464661(&DAT_00595178);
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      uVar5 = FUN_0044ec80(&DAT_00595144,*(uint *)(local_24 + 0x10 + iVar1),
                           *(uint *)(local_24 + 0x14 + iVar1),(ushort *)pcVar8,iVar10);
      *(uint *)(local_24 + 0x2c + iVar1) = (uint)(uVar5 < 0x80000000);
      if (0 < (int)uVar5) {
        *(undefined1 *)(param_1 + 0x775) = 1;
      }
      uVar7 = uVar7 + 1;
      local_24 = local_24 + 0x34;
    } while ((int)uVar7 < iVar3);
  }
  MUI::CDeviceList::GetSelectDevice(*(CDeviceList **)(param_1 + 0x340));
  FUN_004202b0();
  *(bool *)(param_1 + 0x774) = uVar6 != 0;
  if ((void *)local_20 != (void *)0x0) {
    FUN_00405190((void *)local_20,local_18 - (int)(void *)local_20 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


