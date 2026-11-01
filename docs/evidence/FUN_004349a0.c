

void __fastcall FUN_004349a0(void *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined *puVar6;
  int iVar7;
  int extraout_ECX;
  undefined1 **ppuVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 **ppuVar13;
  int *piVar14;
  undefined1 *local_74;
  undefined1 *local_70;
  undefined1 *local_6c;
  void *local_68;
  undefined1 **local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  int local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  _SYSTEMTIME local_48;
  int *local_38;
  int local_34;
  undefined8 local_30;
  int local_28;
  undefined8 local_24;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00552bdc;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_68 = param_1;
  GetLocalTime(&local_48);
  piVar4 = (int *)FUN_00405ab0();
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_00405810(0x80004005);
  }
  local_34 = (**(code **)(*piVar4 + 0xc))();
  local_34 = local_34 + 0x10;
  local_8 = 0;
  FUN_00405650(&local_34,0x56e060);
  iVar3 = local_34;
  local_74 = &stack0xffffff70;
  piVar4 = (int *)(local_34 + -0x10);
  piVar5 = FUN_00405020(piVar4);
  piVar5 = piVar5 + 4;
  local_8._0_1_ = 1;
  piVar14 = *(int **)((int)param_1 + 0x7f4);
  puVar6 = FUN_0040f4c0();
  local_8._0_1_ = 0;
  local_70 = (undefined1 *)FUN_00406bd0(puVar6,(int)piVar14,(int)piVar5);
  if (local_70 != (undefined1 *)0x0) {
    piVar5 = (int *)FUN_00405ab0();
    if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    iVar7 = (**(code **)(*piVar5 + 0xc))();
    local_38 = (int *)(iVar7 + 0x10);
    local_8._0_1_ = 2;
    piVar5 = (int *)FUN_00405ab0();
    if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    iVar7 = 0x434ab8;
    local_18 = (**(code **)(*piVar5 + 0xc))();
    local_18 = local_18 + 0x10;
    local_8._0_1_ = 3;
    FUN_0040b590((int *)&local_64);
    local_8._0_1_ = 4;
    FUN_00405650(&local_38,0x56e0bc);
    local_8._0_1_ = 3;
    LOCK();
    ppuVar13 = local_64 + -1;
    puVar12 = *ppuVar13;
    *ppuVar13 = *ppuVar13 + -1;
    UNLOCK();
    if (puVar12 == (undefined1 *)0x1 || (int)(puVar12 + -1) < 0) {
      (**(code **)(*(int *)local_64[-4] + 4))();
    }
    piVar2 = local_38;
    FUN_0040b6c0(local_38);
    local_74 = &stack0xffffff68;
    piVar5 = piVar2 + -4;
    FUN_00405020(piVar5);
    local_64 = (undefined1 **)&stack0xffffff64;
    local_8._0_1_ = 5;
    FUN_00405020((int *)(*(int *)((int)local_68 + 0x52c2c) + -0x10));
    local_8._0_1_ = 3;
    local_64 = (undefined1 **)
               MUI::LCDViewList::LoadGIFImageFile(*(LCDViewList **)((int)local_68 + 0x6b0));
    local_1c = 0;
    local_24 = 0;
    MUI::LCDViewList::GetDelayTimes(*(LCDViewList **)((int)local_68 + 0x6b0));
    local_8._0_1_ = 6;
    FUN_00405650(&local_18,0x56e990);
    iVar9 = local_18;
    local_74 = &stack0xffffff60;
    local_6c = &stack0xffffff60;
    FUN_00405020((int *)(local_18 + -0x10));
    local_6c = &stack0xffffff5c;
    local_8._0_1_ = 7;
    FUN_00405020(piVar4);
    local_8._0_1_ = 6;
    MUI::LCDViewList::AddString(*(LCDViewList **)((int)local_68 + 0x6b0));
    local_6c = &stack0xffffff68;
    iVar10 = extraout_ECX;
    FUN_0040cbd0(&stack0xffffff68,L"0.png");
    puVar12 = local_70;
    local_8._0_1_ = 8;
    puVar11 = local_70;
    puVar6 = FUN_0040f4c0();
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_00406e50(puVar6,(int)puVar11,iVar10);
    ppuVar13 = local_64;
    puVar6 = FUN_0040f4c0();
    FUN_00406d70(puVar6,(int)puVar12,(int)ppuVar13);
    if (local_64 == (undefined1 **)0x1) {
      if ((uint)(local_24._4_4_ - (int)(void *)local_24) < 4) {
        ppuVar13 = &local_74;
        local_74 = (undefined1 *)0xa;
        FUN_00423e90(&local_24,ppuVar13);
      }
    }
    puVar12 = local_70;
    local_30 = 0;
    local_28 = 0;
    iVar10 = 0;
    local_8._0_1_ = 9;
    if (0 < (int)local_64) {
      do {
        FUN_00405650(&local_18,0x56e114);
        FUN_00406b00(&local_60);
        local_8._0_1_ = 10;
        local_5c = puVar12;
        local_54 = *(undefined4 *)((int)(void *)local_24 + iVar10 * 4);
        local_50 = iVar10;
        FUN_00404cd0(&local_4c,&local_18);
        FUN_00404cd0(&local_58,&local_18);
        ppuVar13 = &local_60;
        FUN_00423c60(&local_30,ppuVar13);
        local_8._0_1_ = 9;
        ppuVar8 = (undefined1 **)(local_4c + -0x10);
        LOCK();
        piVar1 = (int *)(local_4c + -4);
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar9 == 1 || iVar9 + -1 < 0) {
          (**(code **)(*(int *)*ppuVar8 + 4))();
          ppuVar13 = ppuVar8;
        }
        ppuVar8 = (undefined1 **)(local_58 + -0x10);
        LOCK();
        piVar1 = (int *)(local_58 + -4);
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar9 == 1 || iVar9 + -1 < 0) {
          (**(code **)(*(int *)*ppuVar8 + 4))();
          ppuVar13 = ppuVar8;
        }
        iVar10 = iVar10 + 1;
        iVar9 = local_18;
      } while (iVar10 < (int)local_64);
    }
    local_6c = &stack0xffffff60;
    FUN_00423da0(&stack0xffffff60,(int *)&local_30);
    local_8._0_1_ = 0xb;
    if ((*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595140) &&
       (FUN_004646a0(&DAT_00595140), DAT_00595140 == -1)) {
      local_8._0_1_ = 0xc;
      memset(&DAT_005950d0,0,0x70);
      FUN_00401250();
      _atexit(thunk_FUN_00401370);
      local_8._0_1_ = 0xb;
      FUN_00464661(&DAT_00595140);
    }
    local_8 = CONCAT31(local_8._1_3_,9);
    FUN_00407600(&DAT_005950d0,(int *)ppuVar13,piVar14,iVar7);
    *(undefined1 **)((int)local_68 + 0x52c14) = local_70;
    FUN_00421990(local_68,(int)local_70);
    piVar14 = (int *)local_30;
    if ((int *)local_30 != (int *)0x0) {
      FUN_00407e20((int *)local_30,local_30._4_4_);
      FUN_004051f0(piVar14,(local_28 - (int)piVar14) / 0x18);
    }
    if ((void *)local_24 != (void *)0x0) {
      FUN_00405190((void *)local_24,local_1c - (int)(void *)local_24 >> 2);
      local_24 = 0;
      local_1c = 0;
    }
    local_8._0_1_ = 2;
    LOCK();
    piVar14 = (int *)(iVar9 + -4);
    iVar7 = *piVar14;
    *piVar14 = *piVar14 + -1;
    UNLOCK();
    if (iVar7 == 1 || iVar7 + -1 < 0) {
      (**(code **)(**(int **)(iVar9 + -0x10) + 4))();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    LOCK();
    piVar2 = piVar2 + -1;
    iVar7 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar7 == 1 || iVar7 + -1 < 0) {
      (**(code **)(*(int *)*piVar5 + 4))();
    }
  }
  local_8 = 0xffffffff;
  LOCK();
  piVar14 = (int *)(iVar3 + -4);
  iVar3 = *piVar14;
  *piVar14 = *piVar14 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(*(int *)*piVar4 + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


