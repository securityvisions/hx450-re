

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __fastcall FUN_00422ac0(int param_1)

{
  int iVar1;
  undefined *this;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  void *pvVar10;
  bool bVar11;
  undefined4 local_106c;
  undefined4 uStack_1068;
  int local_1060;
  int local_1058;
  int local_1054;
  uint local_1050;
  undefined1 *local_104c;
  int local_1048;
  uint local_1044;
  int local_1040;
  int local_103c;
  undefined4 *local_1038;
  int local_1034;
  uint local_1030;
  int local_102c;
  int local_1028;
  undefined8 local_1024;
  int local_101c;
  undefined2 local_1018;
  undefined1 local_1016;
  undefined1 local_1010;
  undefined1 local_100f;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055160f;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1034 = param_1;
  iVar1 = MUI::LCDViewList::GetCurSel(*(LCDViewList **)(param_1 + 0x6b0));
  iVar2 = *(int *)(param_1 + 0x52c14);
  *(int *)(param_1 + 0x52c1c) = iVar1 + 1;
  this = FUN_0040f4c0();
  iVar2 = FUN_00407c20(this,iVar2);
  if (*(int *)(param_1 + 0x527c8) < iVar2) {
    iVar2 = *(int *)(param_1 + 0x527c8);
  }
  uVar8 = *(int *)(param_1 + 0x527c4) +
          *(int *)(param_1 + 0x527d4) * *(int *)(param_1 + 0x527d0) * iVar2 * 2;
  uVar3 = (int)(uVar8 + ((int)uVar8 >> 0x1f & 0xfffU)) >> 0xc;
  uVar6 = uVar8 & 0x80000fff;
  bVar11 = uVar6 == 0;
  if ((int)uVar6 < 0) {
    bVar11 = (uVar6 - 1 | 0xfffff000) == 0xffffffff;
  }
  local_1044 = uVar3 + 1;
  if (bVar11) {
    local_1044 = uVar3;
  }
  uVar8 = uVar8 + 0x1000;
  local_1038 = (undefined4 *)FUN_00464a0c(uVar8);
  if (0 < (int)uVar8) {
    puVar9 = local_1038;
    for (uVar3 = uVar8 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar9 = 0xffffffff;
      puVar9 = puVar9 + 1;
    }
    for (uVar8 = uVar8 & 3; param_1 = local_1034, uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar9 = 0xff;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
  }
  local_1024 = 0;
  local_101c = 0;
  local_8 = 0;
  iVar2 = *(int *)ThreadLocalStoragePointer;
  local_1048 = iVar2;
  if ((*(int *)(iVar2 + 4) < DAT_00595140) && (FUN_004646a0(&DAT_00595140), DAT_00595140 == -1)) {
    local_8._0_1_ = 1;
    memset(&DAT_005950d0,0,0x70);
    FUN_00401250();
    _atexit(thunk_FUN_00401370);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595140);
  }
  local_1040 = FUN_004079d0(&DAT_005950d0,*(int *)(param_1 + 0x52c14),(int *)&local_1024);
  if (0 < local_1040) {
    FUN_00406a00(&local_106c);
    local_8._0_1_ = 2;
    if ((*(int *)(iVar2 + 4) < DAT_00595140) && (FUN_004646a0(&DAT_00595140), DAT_00595140 == -1)) {
      local_8._0_1_ = 3;
      memset(&DAT_005950d0,0,0x70);
      FUN_00401250();
      _atexit(thunk_FUN_00401370);
      local_8._0_1_ = 2;
      FUN_00464661(&DAT_00595140);
    }
    FUN_00407090(&DAT_005950d0,*(int *)(param_1 + 0x52c14),&local_106c);
    piVar4 = (int *)FUN_00405ab0();
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    local_1028 = (**(code **)(*piVar4 + 0xc))();
    local_1028 = local_1028 + 0x10;
    local_8._0_1_ = 4;
    piVar4 = (int *)FUN_00405ab0();
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    iVar2 = (**(code **)(*piVar4 + 0xc))();
    iVar2 = iVar2 + 0x10;
    local_8._0_1_ = 5;
    local_102c = iVar2;
    FUN_0040b590((int *)&local_1030);
    local_8._0_1_ = 6;
    FUN_00405650(&local_1028,0x56e0f8);
    local_8 = CONCAT31(local_8._1_3_,5);
    LOCK();
    piVar4 = (int *)(local_1030 - 4);
    iVar1 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      (**(code **)(**(int **)(local_1030 - 0x10) + 4))();
    }
    iVar1 = local_1028;
    local_103c = *(int *)(param_1 + 0x527c4);
    if (*(int *)(param_1 + 0x527c8) < local_1040) {
      local_1040 = *(int *)(param_1 + 0x527c8);
    }
    local_1030 = 0;
    *(char *)local_1038 = (char)local_1040;
    if (0 < local_1040) {
      local_1050 = local_1024._4_4_ - (int)(void *)local_1024 >> 2;
      iVar5 = (int)(void *)local_1024;
      do {
        if (local_1050 <= local_1030) goto LAB_00423346;
        local_104c = *(undefined1 **)(iVar5 + local_1030 * 4);
        if (local_104c != (undefined1 *)0x0) {
          uVar7 = 1;
          if (1 < *(int *)(local_104c + 0xc) / 2) {
            uVar7 = (char)(*(int *)(local_104c + 0xc) / 2);
          }
          *(undefined1 *)(local_1030 + 1 + (int)local_1038) = uVar7;
          FUN_00405650(&local_102c,0x56e144);
          iVar2 = local_102c;
          local_104c = &stack0xffffef7c;
          FUN_00405020((int *)(local_102c + -0x10));
          iVar5 = local_1034;
          MUI::LCDViewList::GetImageRGB565Data(*(LCDViewList **)(local_1034 + 0x6b0));
          local_103c = local_103c + *(int *)(iVar5 + 0x527d4) * *(int *)(iVar5 + 0x527d0) * 2;
          iVar5 = (int)(void *)local_1024;
        }
        local_1030 = local_1030 + 1;
      } while ((int)local_1030 < local_1040);
    }
    local_8._0_1_ = 4;
    LOCK();
    piVar4 = (int *)(iVar2 + -4);
    iVar5 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar5 + -1 < 1) {
      (**(code **)(**(int **)(iVar2 + -0x10) + 4))();
    }
    local_8._0_1_ = 2;
    LOCK();
    piVar4 = (int *)(iVar1 + -4);
    iVar2 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar2 + -1 < 1) {
      (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    LOCK();
    piVar4 = (int *)(local_1054 + -4);
    iVar2 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar2 + -1 < 1) {
      (**(code **)(**(int **)(local_1054 + -0x10) + 4))();
    }
    LOCK();
    piVar4 = (int *)(local_1058 + -4);
    iVar2 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar2 + -1 < 1) {
      (**(code **)(**(int **)(local_1058 + -0x10) + 4))();
    }
    LOCK();
    piVar4 = (int *)(local_1060 + -4);
    iVar2 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar2 + -1 < 1) {
      (**(code **)(**(int **)(local_1060 + -0x10) + 4))();
    }
  }
  uVar3 = 0;
  uVar8 = local_1024._4_4_ - (int)(void *)local_1024 >> 2;
  pvVar10 = (void *)local_1024;
  if (0 < (int)uVar8) {
    do {
      if (uVar8 <= uVar3) {
LAB_00423346:
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      pvVar10 = *(void **)((int)(void *)local_1024 + uVar3 * 4);
      if (pvVar10 != (void *)0x0) {
        iVar1 = *(int *)((int)pvVar10 + 0x14);
        LOCK();
        piVar4 = (int *)(iVar1 + -4);
        iVar2 = *piVar4;
        *piVar4 = *piVar4 + -1;
        UNLOCK();
        if (iVar2 + -1 < 1) {
          (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
        }
        iVar1 = *(int *)((int)pvVar10 + 8);
        LOCK();
        piVar4 = (int *)(iVar1 + -4);
        iVar2 = *piVar4;
        *piVar4 = *piVar4 + -1;
        UNLOCK();
        if (iVar2 == 1 || iVar2 + -1 < 0) {
          (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
        }
        FUN_004644e6(pvVar10);
      }
      uVar3 = uVar3 + 1;
      pvVar10 = (void *)local_1024;
    } while ((int)uVar3 < (int)uVar8);
  }
  local_1024 = CONCAT44(pvVar10,(void *)local_1024);
  memset((void *)((int)&local_1018 + 1),0,0x1000);
  iVar2 = local_1048;
  local_1018 = 0x1804;
  if ((*(int *)(local_1048 + 4) < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)
     ) {
    local_8._0_1_ = 7;
    memset(&DAT_00595144,0,0x34);
    FUN_0044e680();
    _atexit(thunk_FUN_0044e780);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595178);
  }
  FUN_0044edb0(&DAT_00595144,(undefined4 *)&local_1018,0x41,'\x01');
  iVar1 = local_1034;
  local_1018 = 0x7204;
  local_1016 = *(undefined1 *)(local_1034 + 0x52c1c);
  local_1010 = (undefined1)local_1044;
  local_100f = (undefined1)(local_1044 >> 8);
  if ((*(int *)(iVar2 + 4) < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
    local_8._0_1_ = 8;
    memset(&DAT_00595144,0,0x34);
    FUN_0044e680();
    _atexit(thunk_FUN_0044e780);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595178);
  }
  FUN_0044edb0(&DAT_00595144,(undefined4 *)&local_1018,0x41,'\x01');
  if (0 < (int)local_1044) {
    iVar2 = 0;
    local_1030 = local_1044;
    puVar9 = local_1038;
    do {
      memset(&local_1018,0,0x1001);
      memcpy(&local_1018,puVar9,0x1000);
      if ((*(int *)(local_1048 + 4) < DAT_00595178) &&
         (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
        local_8._0_1_ = 9;
        memset(&DAT_00595144,0,0x34);
        FUN_0044e680();
        _atexit(thunk_FUN_0044e780);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00464661(&DAT_00595178);
      }
      FUN_0044f1b0(&DAT_00595144,&local_1018);
      iVar1 = *(int *)(iVar1 + 0x52c34);
      if (iVar1 != 0) {
        local_1050 = iVar2 / (int)local_1044;
        FUN_00405650((void *)(iVar1 + 0x2b4),0x56fac8);
        if (*(MControlFont **)(iVar1 + 0x2b0) != (MControlFont *)0x0) {
          MUI::MControlFont::SetTitle
                    (*(MControlFont **)(iVar1 + 0x2b0),*(wchar_t **)(iVar1 + 0x2b4));
        }
        if (*(MProgress **)(iVar1 + 0x2b8) != (MProgress *)0x0) {
          MUI::MProgress::SetProgress(*(MProgress **)(iVar1 + 0x2b8),local_1050);
        }
      }
      puVar9 = puVar9 + 0x400;
      iVar2 = iVar2 + 100;
      local_1030 = local_1030 - 1;
      iVar1 = local_1034;
    } while (local_1030 != 0);
    local_1030 = 0;
    iVar2 = local_1048;
    pvVar10 = (void *)local_1024;
  }
  free(local_1038);
  memset(&local_1018,0,0x41);
  local_1018 = 0x204;
  if ((*(int *)(iVar2 + 4) < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
    local_8._0_1_ = 10;
    memset(&DAT_00595144,0,0x34);
    FUN_0044e680();
    _atexit(thunk_FUN_0044e780);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595178);
  }
  FUN_0044edb0(&DAT_00595144,(undefined4 *)&local_1018,0x41,'\x01');
  iVar2 = *(int *)(iVar1 + 0x52c34);
  if (iVar2 != 0) {
    FUN_00405650((undefined4 *)(iVar2 + 0x2b4),0x56fac8);
    if (*(MControlFont **)(iVar2 + 0x2b0) != (MControlFont *)0x0) {
      MUI::MControlFont::SetTitle(*(MControlFont **)(iVar2 + 0x2b0),*(wchar_t **)(iVar2 + 0x2b4));
    }
    if (*(MProgress **)(iVar2 + 0x2b8) != (MProgress *)0x0) {
      MUI::MProgress::SetProgress(*(MProgress **)(iVar2 + 0x2b8),100);
    }
  }
  if (pvVar10 != (void *)0x0) {
    FUN_00405190(pvVar10,local_101c - (int)pvVar10 >> 2);
  }
  ExceptionList = local_10;
  uStack_1068 = 0x423342;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


