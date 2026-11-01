

void __fastcall FUN_0044bd70(int param_1)

{
  undefined1 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  undefined8 local_2bc;
  int local_2b4;
  undefined4 local_2b0;
  undefined2 local_1f2;
  undefined2 local_72;
  undefined4 local_58;
  undefined1 uStack_54;
  undefined2 uStack_53;
  undefined1 uStack_51;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined8 local_44;
  undefined4 local_3c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_005542e3;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = MUI::MListBox::GetCurSel(*(MListBox **)(param_1 + 0x43c));
  if (-1 < iVar4) {
    lVar5 = MUI::MListBox::GetItemData(*(MListBox **)(param_1 + 0x43c),iVar4);
    memset(&local_58,0,0x41);
    puVar11 = &local_58;
    local_58._1_1_ = 5;
    local_58._2_1_ = 0x10;
    local_58._3_1_ = 0;
    uStack_54 = 0x80;
    uStack_53 = 0;
    uVar13 = 0x41;
    uStack_51 = 0;
    iStack_4c = (uint)*(byte *)(param_1 + 0x814) << 8;
    uStack_48 = CONCAT22(0x55aa,(undefined2)uStack_48);
    puVar6 = FUN_00413510();
    FUN_0044f4d0(puVar6,puVar11,uVar13);
    memset(&local_2b0,0,600);
    local_2bc = 0;
    local_2b4 = 0;
    piVar14 = (int *)&local_2bc;
    local_8 = 0;
    puVar6 = FUN_0040f4c0();
    uVar13 = FUN_00409220(puVar6,lVar5,piVar14);
    uVar12 = 0;
    if (0 < (int)uVar13) {
      do {
        if ((uint)(local_2bc._4_4_ - (int)(void *)local_2bc >> 2) <= uVar12) goto LAB_0044c0b6;
        iVar4 = *(int *)((int)(void *)local_2bc + uVar12 * 4);
        if ((iVar4 != 0) && (*(int *)(param_1 + 0x828) != 0)) {
          puVar11 = *(undefined4 **)(param_1 + 0x824);
          puVar9 = puVar11;
          if (*(char *)((int)puVar11[1] + 0xd) == '\0') {
            puVar7 = (undefined4 *)puVar11[1];
            do {
              if ((int)puVar7[4] < *(int *)(iVar4 + 0xc)) {
                puVar8 = (undefined4 *)puVar7[2];
              }
              else {
                puVar8 = (undefined4 *)*puVar7;
                puVar9 = puVar7;
              }
              puVar7 = puVar8;
            } while (*(char *)((int)puVar8 + 0xd) == '\0');
          }
          if ((puVar9 == puVar11) || (*(int *)(iVar4 + 0xc) < (int)puVar9[4])) {
            puVar9 = puVar11;
          }
          iVar10 = puVar9[5];
          if (0 < iVar10) {
            if (*(int *)(param_1 + 0x7ac) == 0) {
              if (0 < *(int *)(iVar4 + 0x10)) {
                *(undefined1 *)((int)&local_2b0 + iVar10) = 0xff;
              }
            }
            else {
              *(undefined1 *)((int)&local_2b0 + iVar10 * 4 + 1) = *(undefined1 *)(iVar4 + 0x10);
              *(undefined1 *)((int)&local_2b0 + iVar10 * 4 + 2) = *(undefined1 *)(iVar4 + 0x11);
              uVar1 = *(undefined1 *)(iVar4 + 0x12);
              *(char *)(&local_2b0 + iVar10) = (char)iVar10;
              *(undefined1 *)((int)&local_2b0 + iVar10 * 4 + 3) = uVar1;
            }
          }
        }
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < (int)uVar13);
    }
    uVar12 = 0;
    if (uVar13 != 0) {
      iVar4 = local_2bc._4_4_ - (int)(void *)local_2bc;
      do {
        if ((uint)(iVar4 >> 2) <= uVar12) {
LAB_0044c0b6:
                    /* WARNING: Subroutine does not return */
          std::_Xout_of_range("invalid vector<T> subscript");
        }
        pvVar2 = *(void **)((int)(void *)local_2bc + uVar12 * 4);
        if (pvVar2 != (void *)0x0) {
          FUN_004644e6(pvVar2);
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar13);
    }
    puVar11 = &local_2b0;
    iVar4 = *(int *)ThreadLocalStoragePointer;
    if (*(int *)(param_1 + 0x7ac) == 0) {
      local_1f2 = 0x55aa;
      iVar10 = 0;
      do {
        memset(&local_58,0,0x41);
        uVar3 = *puVar11;
        local_58._1_1_ = 0x14;
        local_58._3_1_ = (char)iVar10;
        local_58._2_1_ = 0x1c;
        if (iVar10 == 6) {
          local_58._2_1_ = 0x18;
        }
        uStack_54 = (undefined1)uVar3;
        uStack_53 = (undefined2)((uint)uVar3 >> 8);
        uStack_51 = (undefined1)((uint)uVar3 >> 0x18);
        uStack_50 = puVar11[1];
        iStack_4c = puVar11[2];
        uStack_48 = puVar11[3];
        local_3c = puVar11[6];
        local_44 = *(undefined8 *)(puVar11 + 4);
        if ((*(int *)(iVar4 + 4) < DAT_00595178) &&
           (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
          local_8._0_1_ = 2;
          memset(&DAT_00595144,0,0x34);
          FUN_0044e680();
          _atexit(thunk_FUN_0044e780);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00464661(&DAT_00595178);
        }
        FUN_0044f4d0(&DAT_00595144,&local_58,0x41);
        puVar11 = puVar11 + 7;
        Sleep(2);
        iVar10 = iVar10 + 1;
      } while (iVar10 < 7);
    }
    else {
      local_72 = 0x55aa;
      iVar10 = 0;
      do {
        memset(&local_58,0,0x41);
        uVar3 = *puVar11;
        local_58._1_1_ = 0x14;
        local_58._3_1_ = (char)iVar10;
        local_58._2_1_ = 0x1c;
        if (iVar10 == 0x14) {
          local_58._2_1_ = 0x10;
        }
        uStack_54 = (undefined1)uVar3;
        uStack_53 = (undefined2)((uint)uVar3 >> 8);
        uStack_51 = (undefined1)((uint)uVar3 >> 0x18);
        uStack_50 = puVar11[1];
        iStack_4c = puVar11[2];
        uStack_48 = puVar11[3];
        local_3c = puVar11[6];
        local_44 = *(undefined8 *)(puVar11 + 4);
        if ((*(int *)(iVar4 + 4) < DAT_00595178) &&
           (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
          local_8._0_1_ = 1;
          memset(&DAT_00595144,0,0x34);
          FUN_0044e680();
          _atexit(thunk_FUN_0044e780);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00464661(&DAT_00595178);
        }
        FUN_0044f4d0(&DAT_00595144,&local_58,0x41);
        puVar11 = puVar11 + 7;
        Sleep(2);
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0x15);
    }
    if ((void *)local_2bc != (void *)0x0) {
      FUN_00405190((void *)local_2bc,local_2b4 - (int)(void *)local_2bc >> 2);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


