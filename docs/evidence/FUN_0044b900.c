

void __fastcall FUN_0044b900(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  long lVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  char cVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  undefined8 local_2bc;
  int local_2b4;
  undefined4 local_2b0;
  undefined2 local_1f2;
  undefined2 local_72;
  undefined4 local_58;
  undefined1 local_50;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_0055428b;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar17 = param_1;
  iVar5 = MUI::MListBox::GetCurSel(*(MListBox **)(param_1 + 0x43c));
  if (-1 < iVar5) {
    lVar6 = MUI::MListBox::GetItemData(*(MListBox **)(param_1 + 0x43c),iVar5);
    FUN_0044b7f0(param_1);
    memset((void *)((int)&local_58 + 1),0,0x40);
    local_58._0_2_ = 0x1804;
    puVar13 = &local_58;
    cVar15 = '\x01';
    uVar14 = 0x41;
    puVar7 = FUN_00413510();
    FUN_0044edb0(puVar7,puVar13,uVar14,cVar15);
    local_50 = 3;
    local_58._0_2_ = 0x2304;
    if (*(int *)(param_1 + 0x7ac) != 0) {
      local_50 = 9;
    }
    cVar15 = '\x01';
    puVar13 = &local_58;
    uVar14 = 0x41;
    puVar7 = FUN_00413510();
    FUN_0044edb0(puVar7,puVar13,uVar14,cVar15);
    memset(&local_2b0,0,600);
    local_2bc = 0;
    local_2b4 = 0;
    piVar16 = (int *)&local_2bc;
    local_8 = 0;
    puVar7 = FUN_0040f4c0();
    uVar14 = FUN_00409220(puVar7,lVar6,piVar16);
    uVar12 = 0;
    pvVar4 = (void *)local_2bc;
    if (0 < (int)uVar14) {
      do {
        if ((uint)(local_2bc._4_4_ - (int)(void *)local_2bc >> 2) <= uVar12) goto LAB_0044bbd5;
        iVar5 = *(int *)((int)(void *)local_2bc + uVar12 * 4);
        if ((iVar5 != 0) && (*(int *)(param_1 + 0x828) != 0)) {
          puVar13 = *(undefined4 **)(param_1 + 0x824);
          puVar11 = puVar13;
          if (*(char *)((int)puVar13[1] + 0xd) == '\0') {
            puVar8 = (undefined4 *)puVar13[1];
            do {
              if ((int)puVar8[4] < *(int *)(iVar5 + 0xc)) {
                puVar9 = (undefined4 *)puVar8[2];
              }
              else {
                puVar9 = (undefined4 *)*puVar8;
                puVar11 = puVar8;
              }
              puVar8 = puVar9;
              param_1 = iVar17;
            } while (*(char *)((int)puVar9 + 0xd) == '\0');
          }
          if ((puVar11 == puVar13) || (*(int *)(iVar5 + 0xc) < (int)puVar11[4])) {
            puVar11 = puVar13;
          }
          iVar2 = puVar11[5];
          if (0 < iVar2) {
            if (*(int *)(param_1 + 0x7ac) == 0) {
              if (0 < *(int *)(iVar5 + 0x10)) {
                *(undefined1 *)((int)&local_2b0 + iVar2) = 0xff;
              }
            }
            else {
              *(undefined1 *)((int)&local_2b0 + iVar2 * 4 + 1) = *(undefined1 *)(iVar5 + 0x10);
              *(undefined1 *)((int)&local_2b0 + iVar2 * 4 + 2) = *(undefined1 *)(iVar5 + 0x11);
              uVar1 = *(undefined1 *)(iVar5 + 0x12);
              *(char *)(&local_2b0 + iVar2) = (char)iVar2;
              *(undefined1 *)((int)&local_2b0 + iVar2 * 4 + 3) = uVar1;
            }
          }
        }
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < (int)uVar14);
    }
    uVar12 = 0;
    if (uVar14 != 0) {
      uVar10 = local_2bc._4_4_ - (int)(void *)local_2bc >> 2;
      uVar18 = uVar10;
      do {
        if (uVar10 <= uVar12) {
LAB_0044bbd5:
                    /* WARNING: Subroutine does not return */
          std::_Xout_of_range("invalid vector<T> subscript");
        }
        pvVar3 = *(void **)((int)pvVar4 + uVar12 * 4);
        if (pvVar3 != (void *)0x0) {
          uVar10 = uVar18;
          FUN_004644e6(pvVar3);
          uVar18 = uVar10;
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar14);
    }
    piVar16 = (int *)(*(int *)ThreadLocalStoragePointer + 4);
    if (*(int *)(param_1 + 0x7ac) == 0) {
      local_1f2 = 0x55aa;
      if ((*piVar16 < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
        local_8._0_1_ = 2;
        memset(&DAT_00595144,0,0x34);
        FUN_0044e680();
        _atexit(thunk_FUN_0044e780);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00464661(&DAT_00595178);
      }
      uVar14 = 0xc0;
    }
    else {
      local_72 = 0x55aa;
      if ((*piVar16 < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
        local_8._0_1_ = 1;
        memset(&DAT_00595144,0,0x34);
        FUN_0044e680();
        _atexit(thunk_FUN_0044e780);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00464661(&DAT_00595178);
      }
      uVar14 = 0x240;
    }
    FUN_0044edb0(&DAT_00595144,&local_2b0,uVar14,'\x01');
    memset(&local_58,0,0x41);
    local_58._0_2_ = 0x204;
    if ((*piVar16 < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
      local_8._0_1_ = 3;
      memset(&DAT_00595144,0,0x34);
      FUN_0044e680();
      _atexit(thunk_FUN_0044e780);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00464661(&DAT_00595178);
    }
    FUN_0044edb0(&DAT_00595144,&local_58,0x41,'\x01');
    local_58._0_2_ = 0xf004;
    if ((*piVar16 < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
      local_8._0_1_ = 4;
      memset(&DAT_00595144,0,0x34);
      FUN_0044e680();
      _atexit(thunk_FUN_0044e780);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00464661(&DAT_00595178);
    }
    FUN_0044edb0(&DAT_00595144,&local_58,0x41,'\x01');
    if (pvVar4 != (void *)0x0) {
      FUN_00405190(pvVar4,local_2b4 - (int)pvVar4 >> 2);
    }
  }
  ExceptionList = local_10;
  local_2bc = CONCAT44(local_2bc._4_4_,0x44bd66);
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


