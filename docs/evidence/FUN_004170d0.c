

void __fastcall FUN_004170d0(void *param_1)

{
  int iVar1;
  wchar_t wVar2;
  ushort uVar3;
  long *plVar4;
  void *pvVar5;
  undefined *puVar6;
  int *piVar7;
  wchar_t *pwVar8;
  ushort *puVar9;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  wchar_t *pwVar10;
  int extraout_ECX_02;
  ushort *puVar11;
  int extraout_ECX_03;
  int extraout_ECX_04;
  int extraout_ECX_05;
  int iVar12;
  uint uVar13;
  long lVar14;
  bool bVar15;
  int *piVar16;
  undefined4 *puVar17;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  int local_34;
  undefined8 local_30;
  undefined4 local_28;
  undefined8 local_24;
  int local_1c;
  wchar_t *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055058c;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  MUI::MListBox::DeleteAllItems(*(MListBox **)((int)param_1 + 0x364));
  local_24 = 0;
  local_1c = 0;
  piVar16 = (int *)&local_24;
  local_8 = 0;
  puVar6 = FUN_0040f4c0();
  local_48 = FUN_00402b10(puVar6,piVar16);
  if (local_48 < 1) {
    FUN_004010f0(&local_38);
    local_8._0_1_ = 1;
    iVar12 = extraout_ECX;
    FUN_0040cbd0(&stack0xffffff68,L"KB.DIALOG");
    FUN_0043f8b0(&local_3c,0x41,iVar12);
    local_8._0_1_ = 2;
    FUN_00405650(&local_34,0x56d66c);
    local_8._0_1_ = 1;
    LOCK();
    piVar16 = (int *)(local_3c - 4);
    iVar12 = *piVar16;
    *piVar16 = *piVar16 + -1;
    UNLOCK();
    if (iVar12 == 1 || iVar12 + -1 < 0) {
      (**(code **)(**(int **)(local_3c - 0x10) + 4))();
    }
    puVar17 = &local_38;
    puVar6 = FUN_0040f4c0();
    FUN_00402650(puVar6,(int)puVar17);
    puVar6 = FUN_0040f4c0();
    FUN_00401ad0(puVar6);
    iVar12 = extraout_ECX_00;
    FUN_0040cbd0(&stack0xffffff68,L"KB.DIALOG");
    FUN_0043f8b0(&local_3c,0x41,iVar12);
    local_8._0_1_ = 3;
    FUN_00405650(&local_34,0x56d678);
    local_8._0_1_ = 1;
    LOCK();
    piVar16 = (int *)(local_3c - 4);
    iVar12 = *piVar16;
    *piVar16 = *piVar16 + -1;
    UNLOCK();
    if (iVar12 == 1 || iVar12 + -1 < 0) {
      (**(code **)(**(int **)(local_3c - 0x10) + 4))();
    }
    puVar17 = &local_38;
    puVar6 = FUN_0040f4c0();
    FUN_00402650(puVar6,(int)puVar17);
    iVar12 = extraout_ECX_01;
    FUN_0040cbd0(&stack0xffffff68,L"KB.DIALOG");
    FUN_0043f8b0(&local_3c,0x41,iVar12);
    local_8._0_1_ = 4;
    FUN_00405650(&local_34,0x56d684);
    local_8._0_1_ = 1;
    LOCK();
    piVar16 = (int *)(local_3c - 4);
    iVar12 = *piVar16;
    *piVar16 = *piVar16 + -1;
    UNLOCK();
    if (iVar12 == 1 || iVar12 + -1 < 0) {
      (**(code **)(**(int **)(local_3c - 0x10) + 4))();
    }
    puVar17 = &local_38;
    puVar6 = FUN_0040f4c0();
    FUN_00402650(puVar6,(int)puVar17);
    puVar6 = FUN_0040f4c0();
    FUN_00402db0(puVar6);
    piVar16 = (int *)&local_24;
    puVar6 = FUN_0040f4c0();
    local_48 = FUN_00402b10(puVar6,piVar16);
    local_8 = (uint)local_8._1_3_ << 8;
    LOCK();
    piVar16 = (int *)((int)local_30 + -4);
    iVar12 = *piVar16;
    *piVar16 = *piVar16 + -1;
    UNLOCK();
    if (iVar12 + -1 < 1) {
      (**(code **)(**(int **)((int)local_30 + -0x10) + 4))();
    }
    LOCK();
    piVar16 = (int *)(local_34 + -4);
    iVar12 = *piVar16;
    *piVar16 = *piVar16 + -1;
    UNLOCK();
    if (iVar12 == 1 || iVar12 + -1 < 0) {
      (**(code **)(**(int **)(local_34 + -0x10) + 4))();
    }
  }
  local_3c = 0;
  if (0 < local_48) {
    uVar13 = local_24._4_4_ - (int)(void *)local_24 >> 2;
    iVar12 = (int)(void *)local_24;
    local_40 = uVar13;
    do {
      if (uVar13 <= local_3c) {
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      plVar4 = *(long **)(iVar12 + local_3c * 4);
      if (plVar4 != (long *)0x0) {
        piVar16 = plVar4 + 1;
        piVar7 = FUN_00405020((int *)(plVar4[1] + -0x10));
        local_18 = (wchar_t *)(piVar7 + 4);
        local_8 = CONCAT31(local_8._1_3_,5);
        piVar7 = FUN_0040cac0(piVar16,&local_4c,0x13);
        pwVar10 = L"My Exclusive Config";
        pwVar8 = (wchar_t *)*piVar7;
        do {
          wVar2 = *pwVar8;
          bVar15 = (ushort)wVar2 < (ushort)*pwVar10;
          if (wVar2 != *pwVar10) {
LAB_00417368:
            uVar13 = -(uint)bVar15 | 1;
            goto LAB_0041736d;
          }
          if (wVar2 == L'\0') break;
          wVar2 = pwVar8[1];
          bVar15 = (ushort)wVar2 < (ushort)pwVar10[1];
          if (wVar2 != pwVar10[1]) goto LAB_00417368;
          pwVar8 = pwVar8 + 2;
          pwVar10 = pwVar10 + 2;
        } while (wVar2 != L'\0');
        uVar13 = 0;
LAB_0041736d:
        LOCK();
        piVar7 = (int *)(local_4c + -4);
        iVar12 = *piVar7;
        *piVar7 = *piVar7 + -1;
        UNLOCK();
        if (iVar12 == 1 || iVar12 + -1 < 0) {
          (**(code **)(**(int **)(local_4c + -0x10) + 4))();
        }
        if (uVar13 == 0) {
          FUN_00413290(piVar16,&local_54,*(int *)(*piVar16 + -0xc) + -0x13);
          local_8._0_1_ = 6;
          iVar12 = extraout_ECX_02;
          FUN_0040cbd0(&stack0xffffff64,L"KB.DIALOG");
          FUN_0043f8b0(&local_50,0x41,iVar12);
          local_8._0_1_ = 7;
          FUN_00405650(&local_18,0x56d138);
          local_8._0_1_ = 6;
          LOCK();
          piVar7 = (int *)(local_50 + -4);
          iVar12 = *piVar7;
          *piVar7 = *piVar7 + -1;
          UNLOCK();
          if (iVar12 + -1 < 1) {
            (**(code **)(**(int **)(local_50 + -0x10) + 4))();
          }
          local_8 = CONCAT31(local_8._1_3_,5);
          iVar12 = local_54;
LAB_00417687:
          LOCK();
          piVar7 = (int *)(iVar12 + -4);
          iVar1 = *piVar7;
          *piVar7 = *piVar7 + -1;
          UNLOCK();
          if (iVar1 == 1 || iVar1 + -1 < 0) {
            (**(code **)(**(int **)(iVar12 + -0x10) + 4))();
          }
        }
        else {
          piVar7 = FUN_0040cac0(piVar16,&local_58,6);
          puVar11 = &DAT_0056d6b8;
          puVar9 = (ushort *)*piVar7;
          do {
            uVar3 = *puVar9;
            bVar15 = uVar3 < *puVar11;
            if (uVar3 != *puVar11) {
LAB_0041743d:
              uVar13 = -(uint)bVar15 | 1;
              goto LAB_00417442;
            }
            if (uVar3 == 0) break;
            uVar3 = puVar9[1];
            bVar15 = uVar3 < puVar11[1];
            if (uVar3 != puVar11[1]) goto LAB_0041743d;
            puVar9 = puVar9 + 2;
            puVar11 = puVar11 + 2;
          } while (uVar3 != 0);
          uVar13 = 0;
LAB_00417442:
          LOCK();
          piVar7 = (int *)(local_58 + -4);
          iVar12 = *piVar7;
          *piVar7 = *piVar7 + -1;
          UNLOCK();
          if (iVar12 == 1 || iVar12 + -1 < 0) {
            (**(code **)(**(int **)(local_58 + -0x10) + 4))();
          }
          if (uVar13 == 0) {
            FUN_00413290(piVar16,&local_60,*(int *)(*piVar16 + -0xc) + -6);
            local_8._0_1_ = 8;
            iVar12 = extraout_ECX_03;
            FUN_0040cbd0(&stack0xffffff64,L"KB.DIALOG");
            FUN_0043f8b0(&local_5c,0x41,iVar12);
            local_8._0_1_ = 9;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 8;
            LOCK();
            piVar7 = (int *)(local_5c + -4);
            iVar12 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar12 + -1 < 1) {
              (**(code **)(**(int **)(local_5c + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,5);
            iVar12 = local_60;
            goto LAB_00417687;
          }
          piVar7 = FUN_0040cac0(piVar16,&local_64,6);
          puVar11 = &DAT_0056d6c8;
          puVar9 = (ushort *)*piVar7;
          do {
            uVar3 = *puVar9;
            bVar15 = uVar3 < *puVar11;
            if (uVar3 != *puVar11) {
LAB_00417516:
              uVar13 = -(uint)bVar15 | 1;
              goto LAB_0041751b;
            }
            if (uVar3 == 0) break;
            uVar3 = puVar9[1];
            bVar15 = uVar3 < puVar11[1];
            if (uVar3 != puVar11[1]) goto LAB_00417516;
            puVar9 = puVar9 + 2;
            puVar11 = puVar11 + 2;
          } while (uVar3 != 0);
          uVar13 = 0;
LAB_0041751b:
          LOCK();
          piVar7 = (int *)(local_64 + -4);
          iVar12 = *piVar7;
          *piVar7 = *piVar7 + -1;
          UNLOCK();
          if (iVar12 == 1 || iVar12 + -1 < 0) {
            (**(code **)(**(int **)(local_64 + -0x10) + 4))();
          }
          if (uVar13 == 0) {
            FUN_00413290(piVar16,&local_6c,*(int *)(*piVar16 + -0xc) + -6);
            local_8._0_1_ = 10;
            iVar12 = extraout_ECX_04;
            FUN_0040cbd0(&stack0xffffff64,L"KB.DIALOG");
            FUN_0043f8b0(&local_68,0x41,iVar12);
            local_8._0_1_ = 0xb;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 10;
            LOCK();
            piVar7 = (int *)(local_68 + -4);
            iVar12 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar12 + -1 < 1) {
              (**(code **)(**(int **)(local_68 + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,5);
            iVar12 = local_6c;
            goto LAB_00417687;
          }
          piVar7 = FUN_0040cac0(piVar16,&local_70,3);
          puVar11 = &DAT_0056d6d8;
          puVar9 = (ushort *)*piVar7;
          do {
            uVar3 = *puVar9;
            bVar15 = uVar3 < *puVar11;
            if (uVar3 != *puVar11) {
LAB_004175eb:
              uVar13 = -(uint)bVar15 | 1;
              goto LAB_004175f0;
            }
            if (uVar3 == 0) break;
            uVar3 = puVar9[1];
            bVar15 = uVar3 < puVar11[1];
            if (uVar3 != puVar11[1]) goto LAB_004175eb;
            puVar9 = puVar9 + 2;
            puVar11 = puVar11 + 2;
          } while (uVar3 != 0);
          uVar13 = 0;
LAB_004175f0:
          LOCK();
          piVar7 = (int *)(local_70 + -4);
          iVar12 = *piVar7;
          *piVar7 = *piVar7 + -1;
          UNLOCK();
          if (iVar12 == 1 || iVar12 + -1 < 0) {
            (**(code **)(**(int **)(local_70 + -0x10) + 4))();
          }
          if (uVar13 == 0) {
            FUN_00413290(piVar16,&local_78,*(int *)(*piVar16 + -0xc) + -3);
            local_8._0_1_ = 0xc;
            iVar12 = extraout_ECX_05;
            FUN_0040cbd0(&stack0xffffff64,L"KB.DIALOG");
            FUN_0043f8b0(&local_74,0x41,iVar12);
            local_8._0_1_ = 0xd;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 0xc;
            LOCK();
            piVar7 = (int *)(local_74 + -4);
            iVar12 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar12 + -1 < 1) {
              (**(code **)(**(int **)(local_74 + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,5);
            iVar12 = local_78;
            goto LAB_00417687;
          }
        }
        pwVar10 = local_18;
        MUI::MListBox::AddString(*(MListBox **)((int)param_1 + 0x364),local_18,*plVar4,-1);
        local_8 = local_8 & 0xffffff00;
        LOCK();
        pwVar8 = pwVar10 + -2;
        iVar12 = *(int *)pwVar8;
        *(int *)pwVar8 = *(int *)pwVar8 + -1;
        UNLOCK();
        if (iVar12 + -1 < 1) {
          (**(code **)(**(int **)(pwVar10 + -8) + 4))();
        }
        iVar1 = plVar4[2];
        LOCK();
        piVar7 = (int *)(iVar1 + -4);
        iVar12 = *piVar7;
        *piVar7 = *piVar7 + -1;
        UNLOCK();
        if (iVar12 + -1 < 1) {
          (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
        }
        iVar1 = *piVar16;
        LOCK();
        piVar16 = (int *)(iVar1 + -4);
        iVar12 = *piVar16;
        *piVar16 = *piVar16 + -1;
        UNLOCK();
        if (iVar12 == 1 || iVar12 + -1 < 0) {
          (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
        }
        FUN_004644e6(plVar4);
        iVar12 = (int)(void *)local_24;
        uVar13 = local_40;
      }
      local_3c = local_3c + 1;
    } while ((int)local_3c < local_48);
  }
  pvVar5 = (void *)local_24;
  local_24 = CONCAT44((void *)local_24,(void *)local_24);
  if (*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595140) {
    FUN_004646a0(&DAT_00595140);
    if (DAT_00595140 == -1) {
      local_8 = CONCAT31(local_8._1_3_,0xe);
      memset(&DAT_005950d0,0,0x70);
      FUN_00401250();
      _atexit(thunk_FUN_00401370);
      FUN_00464661(&DAT_00595140);
    }
  }
  local_44 = &DAT_005950d8;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005950d8);
  local_8._0_1_ = 0xf;
  lVar14 = 0;
  local_30 = 0;
  local_28 = 0;
  FUN_00463fd0((undefined4 *)&local_30);
  local_8 = CONCAT31(local_8._1_3_,0x10);
  FUN_00464430(&DAT_005950d0,(int)&local_30,
               (byte *)"SELECT profile FROM t_profile_data WHERE status = ?",(byte *)0xffffffff);
  FUN_004641d0(&local_30,1,1);
  uVar13 = FUN_00464320((int)&local_30);
  if (uVar13 == 100) {
    lVar14 = FUN_004642b0(&local_30,0);
  }
  FUN_00464070((undefined4 *)&local_30);
  local_8 = local_8 & 0xffffff00;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005950d8);
  *(long *)((int)param_1 + 0x7f8) = lVar14;
  MUI::MListBox::SetCurData(*(MListBox **)((int)param_1 + 0x364),lVar14);
  *(undefined4 *)((int)param_1 + 0x7fc) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x378) + 0xa0))();
  (**(code **)(**(int **)((int)param_1 + 0x37c) + 0xa0))(L"img_btn_layer_n.png",4);
  MUI::KeyLayerButton::SetCheck(*(KeyLayerButton **)((int)param_1 + 0x380),1);
  FUN_004178b0(param_1,*(int *)((int)param_1 + 0x7f8));
  if (pvVar5 != (void *)0x0) {
    FUN_00405190(pvVar5,local_1c - (int)pvVar5 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


