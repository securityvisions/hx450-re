

void __fastcall FUN_004277d0(void *param_1)

{
  wchar_t wVar1;
  ushort uVar2;
  long *plVar3;
  void *this;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  wchar_t *pwVar9;
  uint uVar10;
  ushort *puVar11;
  long lVar12;
  int extraout_ECX;
  wchar_t *pwVar13;
  int extraout_ECX_00;
  ushort *puVar14;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  void *pvVar15;
  undefined1 *puVar16;
  bool bVar17;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  long *local_38;
  void *local_34;
  undefined1 *local_2c;
  int local_28;
  undefined8 local_24;
  int local_1c;
  wchar_t *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00551e38;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = param_1;
  MUI::MListBox::DeleteAllItems(*(MListBox **)((int)param_1 + 0x4cc));
  local_24 = 0;
  local_1c = 0;
  piVar6 = (int *)&local_24;
  local_8 = 0;
  iVar5 = *(int *)((int)param_1 + 0x7f4);
  puVar4 = FUN_0040f4c0();
  iVar5 = FUN_004097f0(puVar4,iVar5,piVar6);
  if (iVar5 < 1) {
    piVar6 = (int *)FUN_00405ab0();
    if (piVar6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    iVar5 = (**(code **)(*piVar6 + 0xc))();
    local_18 = (wchar_t *)(iVar5 + 0x10);
    local_8._0_1_ = 1;
    MUI::MListBox::GetItemCount(*(MListBox **)((int)param_1 + 0x4cc));
    iVar5 = extraout_ECX;
    FUN_0040cbd0(&stack0xffffff84,L"KB.DIALOG");
    FUN_0043f8b0(&local_28,0x171,iVar5);
    local_8._0_1_ = 2;
    FUN_00405650(&local_18,0x56d818);
    local_8._0_1_ = 1;
    LOCK();
    piVar6 = (int *)(local_28 + -4);
    iVar5 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
    if (iVar5 == 1 || iVar5 + -1 < 0) {
      (**(code **)(**(int **)(local_28 + -0x10) + 4))();
    }
    pwVar9 = local_18;
    local_2c = &stack0xffffff88;
    local_38 = (long *)&stack0xffffff88;
    pwVar13 = local_18 + -8;
    piVar6 = FUN_00405020((int *)pwVar13);
    piVar6 = piVar6 + 4;
    local_8._0_1_ = 3;
    iVar5 = *(int *)((int)param_1 + 0x7f4);
    puVar4 = FUN_0040f4c0();
    local_8._0_1_ = 1;
    FUN_004093d0(puVar4,iVar5,(int)piVar6);
    piVar6 = (int *)&local_24;
    iVar5 = *(int *)((int)param_1 + 0x7f4);
    puVar4 = FUN_0040f4c0();
    iVar7 = FUN_004097f0(puVar4,iVar5,piVar6);
    local_8 = (uint)local_8._1_3_ << 8;
    LOCK();
    pwVar9 = pwVar9 + -2;
    iVar5 = *(int *)pwVar9;
    *(int *)pwVar9 = *(int *)pwVar9 + -1;
    UNLOCK();
    if (iVar5 == 1 || iVar5 + -1 < 0) {
      (**(code **)(**(int **)pwVar13 + 4))();
    }
    if (iVar7 < 1) {
      pvVar15 = (void *)local_24;
      goto LAB_00427d86;
    }
  }
  puVar16 = (undefined1 *)0x0;
  local_2c = (undefined1 *)(local_24._4_4_ - (int)(void *)local_24 >> 2);
  pvVar15 = (void *)local_24;
  if (local_2c != (undefined1 *)0x0) {
    if (local_2c == (undefined1 *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xout_of_range("invalid vector<T> subscript");
    }
    do {
      local_38 = *(long **)((int)pvVar15 + (int)puVar16 * 4);
      if (local_38 != (long *)0x0) {
        piVar6 = local_38 + 2;
        piVar8 = FUN_00405020((int *)(local_38[2] + -0x10));
        local_18 = (wchar_t *)(piVar8 + 4);
        local_8 = CONCAT31(local_8._1_3_,4);
        piVar8 = FUN_0040cac0(piVar6,&local_28,0x12);
        pwVar13 = L"Real-time Lighting";
        pwVar9 = (wchar_t *)*piVar8;
        do {
          wVar1 = *pwVar9;
          bVar17 = (ushort)wVar1 < (ushort)*pwVar13;
          if (wVar1 != *pwVar13) {
LAB_004279ca:
            uVar10 = -(uint)bVar17 | 1;
            goto LAB_004279cf;
          }
          if (wVar1 == L'\0') break;
          wVar1 = pwVar9[1];
          bVar17 = (ushort)wVar1 < (ushort)pwVar13[1];
          if (wVar1 != pwVar13[1]) goto LAB_004279ca;
          pwVar9 = pwVar9 + 2;
          pwVar13 = pwVar13 + 2;
        } while (wVar1 != L'\0');
        uVar10 = 0;
LAB_004279cf:
        LOCK();
        piVar8 = (int *)(local_28 + -4);
        iVar5 = *piVar8;
        *piVar8 = *piVar8 + -1;
        UNLOCK();
        if (iVar5 == 1 || iVar5 + -1 < 0) {
          (**(code **)(**(int **)(local_28 + -0x10) + 4))();
        }
        if (uVar10 == 0) {
          FUN_00413290(piVar6,&local_40,*(int *)(*piVar6 + -0xc) + -0x12);
          local_8._0_1_ = 5;
          iVar5 = extraout_ECX_00;
          FUN_0040cbd0(&stack0xffffff84,L"KB.DIALOG");
          FUN_0043f8b0(&local_3c,0x171,iVar5);
          local_8._0_1_ = 6;
          FUN_00405650(&local_18,0x56d138);
          local_8._0_1_ = 5;
          LOCK();
          piVar8 = (int *)(local_3c + -4);
          iVar5 = *piVar8;
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if (iVar5 + -1 < 1) {
            (**(code **)(**(int **)(local_3c + -0x10) + 4))();
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          iVar5 = local_40;
LAB_00427ccc:
          LOCK();
          piVar8 = (int *)(iVar5 + -4);
          iVar7 = *piVar8;
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if (iVar7 == 1 || iVar7 + -1 < 0) {
            (**(code **)(**(int **)(iVar5 + -0x10) + 4))();
          }
        }
        else {
          piVar8 = FUN_0040cac0(piVar6,&local_44,4);
          puVar14 = &DAT_0056e2e0;
          puVar11 = (ushort *)*piVar8;
          do {
            uVar2 = *puVar11;
            bVar17 = uVar2 < *puVar14;
            if (uVar2 != *puVar14) {
LAB_00427aa6:
              uVar10 = -(uint)bVar17 | 1;
              goto LAB_00427aab;
            }
            if (uVar2 == 0) break;
            uVar2 = puVar11[1];
            bVar17 = uVar2 < puVar14[1];
            if (uVar2 != puVar14[1]) goto LAB_00427aa6;
            puVar11 = puVar11 + 2;
            puVar14 = puVar14 + 2;
          } while (uVar2 != 0);
          uVar10 = 0;
LAB_00427aab:
          LOCK();
          piVar8 = (int *)(local_44 + -4);
          iVar5 = *piVar8;
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if (iVar5 == 1 || iVar5 + -1 < 0) {
            (**(code **)(**(int **)(local_44 + -0x10) + 4))();
          }
          if (uVar10 == 0) {
            FUN_00413290(piVar6,&local_4c,*(int *)(*piVar6 + -0xc) + -4);
            local_8._0_1_ = 7;
            iVar5 = extraout_ECX_01;
            FUN_0040cbd0(&stack0xffffff84,L"KB.DIALOG");
            FUN_0043f8b0(&local_48,0x171,iVar5);
            local_8._0_1_ = 8;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 7;
            LOCK();
            piVar8 = (int *)(local_48 + -4);
            iVar5 = *piVar8;
            *piVar8 = *piVar8 + -1;
            UNLOCK();
            if (iVar5 + -1 < 1) {
              (**(code **)(**(int **)(local_48 + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,4);
            iVar5 = local_4c;
            goto LAB_00427ccc;
          }
          piVar8 = FUN_0040cac0(piVar6,&local_50,4);
          puVar14 = &DAT_0056e2d4;
          puVar11 = (ushort *)*piVar8;
          do {
            uVar2 = *puVar11;
            bVar17 = uVar2 < *puVar14;
            if (uVar2 != *puVar14) {
LAB_00427b7e:
              uVar10 = -(uint)bVar17 | 1;
              goto LAB_00427b83;
            }
            if (uVar2 == 0) break;
            uVar2 = puVar11[1];
            bVar17 = uVar2 < puVar14[1];
            if (uVar2 != puVar14[1]) goto LAB_00427b7e;
            puVar11 = puVar11 + 2;
            puVar14 = puVar14 + 2;
          } while (uVar2 != 0);
          uVar10 = 0;
LAB_00427b83:
          LOCK();
          piVar8 = (int *)(local_50 + -4);
          iVar5 = *piVar8;
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if (iVar5 == 1 || iVar5 + -1 < 0) {
            (**(code **)(**(int **)(local_50 + -0x10) + 4))();
          }
          if (uVar10 == 0) {
            FUN_00413290(piVar6,&local_58,*(int *)(*piVar6 + -0xc) + -4);
            local_8._0_1_ = 9;
            iVar5 = extraout_ECX_02;
            FUN_0040cbd0(&stack0xffffff84,L"KB.DIALOG");
            FUN_0043f8b0(&local_54,0x171,iVar5);
            local_8._0_1_ = 10;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 9;
            LOCK();
            piVar8 = (int *)(local_54 + -4);
            iVar5 = *piVar8;
            *piVar8 = *piVar8 + -1;
            UNLOCK();
            if (iVar5 + -1 < 1) {
              (**(code **)(**(int **)(local_54 + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,4);
            iVar5 = local_58;
            goto LAB_00427ccc;
          }
          piVar8 = FUN_0040cac0(piVar6,&local_5c,6);
          bVar17 = FUN_00413240(piVar8,&DAT_0056e314);
          LOCK();
          piVar8 = (int *)(local_5c + -4);
          iVar5 = *piVar8;
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if (iVar5 == 1 || iVar5 + -1 < 0) {
            (**(code **)(**(int **)(local_5c + -0x10) + 4))();
          }
          if (bVar17) {
            FUN_00413290(piVar6,&local_64,*(int *)(*piVar6 + -0xc) + -6);
            local_8._0_1_ = 0xb;
            iVar5 = extraout_ECX_03;
            FUN_0040cbd0(&stack0xffffff84,L"KB.DIALOG");
            FUN_0043f8b0(&local_60,0x171,iVar5);
            local_8._0_1_ = 0xc;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 0xb;
            LOCK();
            piVar8 = (int *)(local_60 + -4);
            iVar5 = *piVar8;
            *piVar8 = *piVar8 + -1;
            UNLOCK();
            if (iVar5 + -1 < 1) {
              (**(code **)(**(int **)(local_60 + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,4);
            iVar5 = local_64;
            goto LAB_00427ccc;
          }
        }
        plVar3 = local_38;
        MUI::MListBox::AddString(*(MListBox **)((int)local_34 + 0x4cc),local_18,*local_38,-1);
        iVar7 = *piVar6;
        LOCK();
        piVar6 = (int *)(iVar7 + -4);
        iVar5 = *piVar6;
        *piVar6 = *piVar6 + -1;
        UNLOCK();
        if (iVar5 == 1 || iVar5 + -1 < 0) {
          (**(code **)(**(int **)(iVar7 + -0x10) + 4))();
        }
        FUN_004644e6(plVar3);
        local_8 = local_8 & 0xffffff00;
        LOCK();
        pwVar9 = local_18 + -2;
        iVar5 = *(int *)pwVar9;
        *(int *)pwVar9 = *(int *)pwVar9 + -1;
        UNLOCK();
        if (iVar5 == 1 || iVar5 + -1 < 0) {
          (**(code **)(**(int **)(local_18 + -8) + 4))();
        }
        pvVar15 = (void *)local_24;
      }
      puVar16 = puVar16 + 1;
    } while (puVar16 < local_2c);
  }
  this = local_34;
  local_24 = CONCAT44(pvVar15,(void *)local_24);
  MUI::MListBox::SetCurSel(*(MListBox **)((int)local_34 + 0x4cc),0);
  MUI::MListBox::SetCurSel(*(MListBox **)((int)this + 0x4d8),0);
  lVar12 = MUI::MListBox::GetItemData(*(MListBox **)((int)this + 0x4cc),0);
  FUN_00427dd0(this,lVar12);
LAB_00427d86:
  if (pvVar15 != (void *)0x0) {
    FUN_00405190(pvVar15,local_1c - (int)pvVar15 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


