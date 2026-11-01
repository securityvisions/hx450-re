

void __fastcall FUN_0042adb0(int param_1)

{
  int iVar1;
  char cVar2;
  undefined *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  DWORD DVar8;
  uint uVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  int local_2c4;
  uint local_2c0;
  undefined8 local_2bc;
  int local_2b4;
  byte local_2b0 [8];
  undefined1 local_2a8;
  undefined2 local_58 [34];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005520eb;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x784) == 0) {
    Sleep(10);
    memset(local_2b0 + 1,0,599);
    DVar8 = 3;
    local_2b0[0] = 4;
    local_2b0[1] = 0xf5;
    local_2a8 = 3;
    if (*(int *)(param_1 + 0x7ac) != 0) {
      local_2a8 = 9;
      DVar8 = 9;
    }
    pbVar11 = local_2b0;
    puVar3 = FUN_00413510();
    cVar2 = FUN_0044f280(puVar3,(undefined4 *)pbVar11,DVar8);
    if (cVar2 != '\0') {
      local_2b4 = 0;
      local_2bc = 0;
      MUI::KeyboardCtrl::GetKeyItems(*(KeyboardCtrl **)(param_1 + 0x398));
      local_8 = 0;
      uVar9 = 0;
      local_2c0 = local_2bc._4_4_ - (int)(void *)local_2bc >> 2;
      iVar7 = (int)(void *)local_2bc;
      if (local_2c0 != 0) {
        do {
          if ((uint)(local_2bc._4_4_ - iVar7 >> 2) <= uVar9) {
                    /* WARNING: Subroutine does not return */
            std::_Xout_of_range("invalid vector<T> subscript");
          }
          iVar1 = *(int *)(iVar7 + uVar9 * 4);
          if ((iVar1 != 0) && (*(int *)(param_1 + 0x828) != 0)) {
            piVar4 = FUN_0040c770((void *)(param_1 + 0x824),&local_2c4,(int *)(iVar1 + 4));
            iVar7 = *(int *)(*piVar4 + 0x14);
            if (*(int *)(param_1 + 0x7ac) == 0) {
              uVar5 = (int)((uint)local_2b0[iVar7] * 0xff) >> 8;
              uVar6 = uVar5 << 8 | uVar5;
            }
            else {
              uVar6 = (uint)CONCAT11(local_2b0[iVar7 * 4 + 3],local_2b0[iVar7 * 4 + 2]);
              uVar5 = (uint)local_2b0[iVar7 * 4 + 1];
            }
            *(uint *)(iVar1 + 0x30) = uVar6 << 8 | uVar5;
            iVar7 = (int)(void *)local_2bc;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < local_2c0);
      }
      memset(local_58,0,0x41);
      local_58[0] = 0x204;
      puVar10 = (undefined4 *)local_58;
      cVar2 = '\x01';
      uVar9 = 0x41;
      puVar3 = FUN_00413510();
      FUN_0044edb0(puVar3,puVar10,uVar9,cVar2);
      MUI::MControl::UpdateControl(*(MControl **)(param_1 + 0x398),1,0);
      if ((void *)local_2bc != (void *)0x0) {
        FUN_00405190((void *)local_2bc,local_2b4 - (int)(void *)local_2bc >> 2);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


