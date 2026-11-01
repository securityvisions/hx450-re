

void __fastcall FUN_00423360(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined *this;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  void *pvVar10;
  undefined4 local_ac;
  undefined4 uStack_a8;
  int local_a0;
  int local_98;
  int local_94;
  int local_90;
  uint local_8c;
  undefined1 *local_88;
  int local_84;
  uint local_80;
  undefined4 *local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  undefined8 local_64;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined8 local_44;
  undefined4 local_3c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055169b;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_74 = param_1;
  iVar3 = MUI::LCDViewList::GetCurSel(*(LCDViewList **)(param_1 + 0x6b0));
  iVar4 = *(int *)(param_1 + 0x52c14);
  *(int *)(param_1 + 0x52c1c) = iVar3 + 1;
  this = FUN_0040f4c0();
  iVar4 = FUN_00407c20(this,iVar4);
  if (*(int *)(param_1 + 0x527c8) < iVar4) {
    iVar4 = *(int *)(param_1 + 0x527c8);
  }
  iVar4 = *(int *)(param_1 + 0x527c4) +
          *(int *)(param_1 + 0x527d4) * *(int *)(param_1 + 0x527d0) * iVar4 * 2;
  iVar3 = iVar4 / 0x1c;
  local_78 = iVar3 + 1;
  if (iVar4 == iVar3 * 0x1c) {
    local_78 = iVar3;
  }
  uVar8 = iVar4 + 0x1c;
  local_7c = (undefined4 *)FUN_00464a0c(uVar8);
  if (0 < (int)uVar8) {
    puVar9 = local_7c;
    for (uVar6 = uVar8 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar9 = 0xffffffff;
      puVar9 = puVar9 + 1;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar9 = 0xff;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
  }
  local_64 = 0;
  local_5c = 0;
  local_8 = 0;
  iVar4 = *(int *)ThreadLocalStoragePointer;
  local_90 = iVar4;
  if ((*(int *)(iVar4 + 4) < DAT_00595140) && (FUN_004646a0(&DAT_00595140), DAT_00595140 == -1)) {
    local_8._0_1_ = 1;
    memset(&DAT_005950d0,0,0x70);
    FUN_00401250();
    _atexit(thunk_FUN_00401370);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595140);
  }
  local_70 = FUN_004079d0(&DAT_005950d0,*(int *)(param_1 + 0x52c14),(int *)&local_64);
  if (0 < local_70) {
    FUN_00406a00(&local_ac);
    local_8._0_1_ = 2;
    if ((*(int *)(iVar4 + 4) < DAT_00595140) && (FUN_004646a0(&DAT_00595140), DAT_00595140 == -1)) {
      local_8._0_1_ = 3;
      memset(&DAT_005950d0,0,0x70);
      FUN_00401250();
      _atexit(thunk_FUN_00401370);
      local_8._0_1_ = 2;
      FUN_00464661(&DAT_00595140);
    }
    iVar4 = local_74;
    FUN_00407090(&DAT_005950d0,*(int *)(local_74 + 0x52c14),&local_ac);
    piVar5 = (int *)FUN_00405ab0();
    if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    local_68 = (**(code **)(*piVar5 + 0xc))();
    local_68 = local_68 + 0x10;
    local_8._0_1_ = 4;
    piVar5 = (int *)FUN_00405ab0();
    if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    iVar3 = (**(code **)(*piVar5 + 0xc))();
    iVar3 = iVar3 + 0x10;
    local_8._0_1_ = 5;
    local_6c = iVar3;
    FUN_0040b590((int *)&local_80);
    local_8._0_1_ = 6;
    FUN_00405650(&local_68,0x56e0f8);
    local_8 = CONCAT31(local_8._1_3_,5);
    LOCK();
    piVar5 = (int *)(local_80 - 4);
    iVar1 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      (**(code **)(**(int **)(local_80 - 0x10) + 4))();
    }
    iVar1 = local_68;
    local_84 = *(int *)(iVar4 + 0x527c4);
    iVar4 = *(int *)(iVar4 + 0x527c8);
    if (iVar4 < local_70) {
      local_70 = iVar4;
    }
    local_80 = 0;
    *(char *)local_7c = (char)local_70;
    if (0 < local_70) {
      local_8c = local_64._4_4_ - (int)(void *)local_64 >> 2;
      iVar4 = (int)(void *)local_64;
      do {
        if (local_8c <= local_80) goto LAB_004238db;
        local_88 = *(undefined1 **)(iVar4 + local_80 * 4);
        if (local_88 != (undefined1 *)0x0) {
          uVar7 = 1;
          if (1 < *(int *)(local_88 + 0xc) / 2) {
            uVar7 = (char)(*(int *)(local_88 + 0xc) / 2);
          }
          *(undefined1 *)(local_80 + 1 + (int)local_7c) = uVar7;
          FUN_00405650(&local_6c,0x56e144);
          iVar3 = local_6c;
          local_88 = &stack0xffffff3c;
          FUN_00405020((int *)(local_6c + -0x10));
          iVar4 = local_74;
          MUI::LCDViewList::GetImageRGB565Data(*(LCDViewList **)(local_74 + 0x6b0));
          local_84 = local_84 + *(int *)(iVar4 + 0x527d4) * *(int *)(iVar4 + 0x527d0) * 2;
          iVar4 = (int)(void *)local_64;
        }
        local_80 = local_80 + 1;
      } while ((int)local_80 < local_70);
    }
    local_8._0_1_ = 4;
    LOCK();
    piVar5 = (int *)(iVar3 + -4);
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar4 + -1 < 1) {
      (**(code **)(**(int **)(iVar3 + -0x10) + 4))();
    }
    local_8._0_1_ = 2;
    LOCK();
    piVar5 = (int *)(iVar1 + -4);
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar4 + -1 < 1) {
      (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    LOCK();
    piVar5 = (int *)(local_94 + -4);
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar4 + -1 < 1) {
      (**(code **)(**(int **)(local_94 + -0x10) + 4))();
    }
    LOCK();
    piVar5 = (int *)(local_98 + -4);
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar4 + -1 < 1) {
      (**(code **)(**(int **)(local_98 + -0x10) + 4))();
    }
    LOCK();
    piVar5 = (int *)(local_a0 + -4);
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar4 + -1 < 1) {
      (**(code **)(**(int **)(local_a0 + -0x10) + 4))();
    }
  }
  uVar6 = 0;
  uVar8 = local_64._4_4_ - (int)(void *)local_64 >> 2;
  pvVar10 = (void *)local_64;
  if (0 < (int)uVar8) {
    do {
      if (uVar8 <= uVar6) {
LAB_004238db:
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      pvVar10 = *(void **)((int)(void *)local_64 + uVar6 * 4);
      if (pvVar10 != (void *)0x0) {
        iVar3 = *(int *)((int)pvVar10 + 0x14);
        LOCK();
        piVar5 = (int *)(iVar3 + -4);
        iVar4 = *piVar5;
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (iVar4 + -1 < 1) {
          (**(code **)(**(int **)(iVar3 + -0x10) + 4))();
        }
        iVar3 = *(int *)((int)pvVar10 + 8);
        LOCK();
        piVar5 = (int *)(iVar3 + -4);
        iVar4 = *piVar5;
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (iVar4 == 1 || iVar4 + -1 < 0) {
          (**(code **)(**(int **)(iVar3 + -0x10) + 4))();
        }
        FUN_004644e6(pvVar10);
      }
      uVar6 = uVar6 + 1;
      pvVar10 = (void *)local_64;
    } while ((int)uVar6 < (int)uVar8);
  }
  local_64 = CONCAT44(pvVar10,(void *)local_64);
  memset(&local_58,0,0x41);
  iVar4 = local_74;
  local_58._1_2_ = 0x37f;
  local_54 = CONCAT13((char)((uint)local_78 >> 0x10),
                      CONCAT12((char)((uint)local_78 >> 8),
                               (short)CONCAT31((int3)local_78,*(undefined1 *)(local_74 + 0x52c1c))))
  ;
  local_58._3_1_ = 0;
  if ((*(int *)(local_90 + 4) < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1))
  {
    local_8._0_1_ = 7;
    memset(&DAT_00595144,0,0x34);
    FUN_0044e680();
    _atexit(thunk_FUN_0044e780);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595178);
  }
  FUN_0044f4d0(&DAT_00595144,&local_58,0x41);
  iVar3 = 0;
  if (0 < local_78) {
    local_70 = 0;
    puVar9 = local_7c;
    do {
      memset(&local_58,0,0x41);
      if (iVar3 < 0x10000) {
        bVar2 = 0x80;
      }
      else {
        bVar2 = (byte)((uint)iVar3 >> 0x10) | 0x80;
      }
      local_54 = *puVar9;
      uStack_50 = puVar9[1];
      uStack_4c = puVar9[2];
      uStack_48 = puVar9[3];
      local_58._3_1_ = (undefined1)((uint)iVar3 >> 8);
      local_3c = puVar9[6];
      local_44 = *(undefined8 *)(puVar9 + 4);
      local_58._1_2_ = CONCAT11((char)iVar3,bVar2);
      if ((*(int *)(local_90 + 4) < DAT_00595178) &&
         (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
        local_8._0_1_ = 8;
        memset(&DAT_00595144,0,0x34);
        FUN_0044e680();
        _atexit(thunk_FUN_0044e780);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00464661(&DAT_00595178);
      }
      FUN_0044f4d0(&DAT_00595144,&local_58,0x41);
      puVar9 = puVar9 + 7;
      Sleep(2);
      iVar4 = *(int *)(iVar4 + 0x52c34);
      if (iVar4 != 0) {
        local_8c = local_70 / local_78;
        FUN_00405650((void *)(iVar4 + 0x2b4),0x56fac8);
        if (*(MControlFont **)(iVar4 + 0x2b0) != (MControlFont *)0x0) {
          MUI::MControlFont::SetTitle
                    (*(MControlFont **)(iVar4 + 0x2b0),*(wchar_t **)(iVar4 + 0x2b4));
        }
        if (*(MProgress **)(iVar4 + 0x2b8) != (MProgress *)0x0) {
          MUI::MProgress::SetProgress(*(MProgress **)(iVar4 + 0x2b8),local_8c);
        }
      }
      local_70 = local_70 + 100;
      iVar3 = iVar3 + 1;
      iVar4 = local_74;
    } while (iVar3 < local_78);
    pvVar10 = (void *)local_64;
  }
  free(local_7c);
  iVar4 = *(int *)(iVar4 + 0x52c34);
  if (iVar4 != 0) {
    FUN_00405650((undefined4 *)(iVar4 + 0x2b4),0x56fac8);
    if (*(MControlFont **)(iVar4 + 0x2b0) != (MControlFont *)0x0) {
      MUI::MControlFont::SetTitle(*(MControlFont **)(iVar4 + 0x2b0),*(wchar_t **)(iVar4 + 0x2b4));
    }
    if (*(MProgress **)(iVar4 + 0x2b8) != (MProgress *)0x0) {
      MUI::MProgress::SetProgress(*(MProgress **)(iVar4 + 0x2b8),100);
    }
  }
  if (pvVar10 != (void *)0x0) {
    FUN_00405190(pvVar10,local_5c - (int)pvVar10 >> 2);
  }
  ExceptionList = local_10;
  uStack_a8 = 0x423a6e;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


