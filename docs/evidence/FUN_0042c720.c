

void __fastcall FUN_0042c720(void *param_1)

{
  int iVar1;
  wchar_t wVar2;
  ushort uVar3;
  long *plVar4;
  undefined *this;
  int iVar5;
  int *piVar6;
  wchar_t *pwVar7;
  uint uVar8;
  ushort *puVar9;
  long lVar10;
  uint uVar11;
  wchar_t *pwVar12;
  int extraout_ECX;
  ushort *puVar13;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  void *pvVar14;
  bool bVar15;
  int *piVar16;
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
  int local_38;
  int local_34;
  void *local_30;
  uint local_2c;
  undefined8 local_24;
  int local_1c;
  wchar_t *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00552220;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)param_1 + 0x870) = 0;
  local_30 = param_1;
  MUI::MListBox::DeleteAllItems(*(MListBox **)((int)param_1 + 0x55c));
  MUI::CRecordList::DeleteAllItems(*(CRecordList **)((int)param_1 + 0x5e8));
  FUN_0042c630((void *)((int)param_1 + 0x2c4),0);
  local_24 = 0;
  local_1c = 0;
  piVar16 = (int *)&local_24;
  local_8 = 0;
  this = FUN_0040f4c0();
  iVar5 = FUN_0040a9a0(this,piVar16);
  pvVar14 = (void *)local_24;
  if (0 < iVar5) {
    local_2c = 0;
    uVar11 = local_24._4_4_ - (int)(void *)local_24 >> 2;
    if (uVar11 != 0) {
      if (uVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      do {
        plVar4 = *(long **)((int)pvVar14 + local_2c * 4);
        if (plVar4 != (long *)0x0) {
          piVar16 = plVar4 + 1;
          piVar6 = FUN_00405020((int *)(plVar4[1] + -0x10));
          local_18 = (wchar_t *)(piVar6 + 4);
          local_8 = CONCAT31(local_8._1_3_,1);
          piVar6 = FUN_0040cac0(piVar16,&local_34,9);
          pwVar12 = L"New Macro";
          pwVar7 = (wchar_t *)*piVar6;
          do {
            wVar2 = *pwVar7;
            bVar15 = (ushort)wVar2 < (ushort)*pwVar12;
            if (wVar2 != *pwVar12) {
LAB_0042c846:
              uVar8 = -(uint)bVar15 | 1;
              goto LAB_0042c84b;
            }
            if (wVar2 == L'\0') break;
            wVar2 = pwVar7[1];
            bVar15 = (ushort)wVar2 < (ushort)pwVar12[1];
            if (wVar2 != pwVar12[1]) goto LAB_0042c846;
            pwVar7 = pwVar7 + 2;
            pwVar12 = pwVar12 + 2;
          } while (wVar2 != L'\0');
          uVar8 = 0;
LAB_0042c84b:
          LOCK();
          piVar6 = (int *)(local_34 + -4);
          iVar5 = *piVar6;
          *piVar6 = *piVar6 + -1;
          UNLOCK();
          if (iVar5 == 1 || iVar5 + -1 < 0) {
            (**(code **)(**(int **)(local_34 + -0x10) + 4))();
          }
          if (uVar8 == 0) {
            FUN_00413290(piVar16,&local_3c,*(int *)(*piVar16 + -0xc) + -9);
            local_8._0_1_ = 2;
            iVar5 = extraout_ECX;
            FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
            FUN_0043f8b0(&local_38,0x14b,iVar5);
            local_8._0_1_ = 3;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 2;
            LOCK();
            piVar6 = (int *)(local_38 + -4);
            iVar5 = *piVar6;
            *piVar6 = *piVar6 + -1;
            UNLOCK();
            if (iVar5 + -1 < 1) {
              (**(code **)(**(int **)(local_38 + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,1);
            iVar5 = local_3c;
LAB_0042cb44:
            LOCK();
            piVar6 = (int *)(iVar5 + -4);
            iVar1 = *piVar6;
            *piVar6 = *piVar6 + -1;
            UNLOCK();
            if (iVar1 == 1 || iVar1 + -1 < 0) {
              (**(code **)(**(int **)(iVar5 + -0x10) + 4))();
            }
          }
          else {
            piVar6 = FUN_0040cac0(piVar16,&local_40,4);
            puVar13 = &DAT_0056d144;
            puVar9 = (ushort *)*piVar6;
            do {
              uVar3 = *puVar9;
              bVar15 = uVar3 < *puVar13;
              if (uVar3 != *puVar13) {
LAB_0042c91e:
                uVar8 = -(uint)bVar15 | 1;
                goto LAB_0042c923;
              }
              if (uVar3 == 0) break;
              uVar3 = puVar9[1];
              bVar15 = uVar3 < puVar13[1];
              if (uVar3 != puVar13[1]) goto LAB_0042c91e;
              puVar9 = puVar9 + 2;
              puVar13 = puVar13 + 2;
            } while (uVar3 != 0);
            uVar8 = 0;
LAB_0042c923:
            LOCK();
            piVar6 = (int *)(local_40 + -4);
            iVar5 = *piVar6;
            *piVar6 = *piVar6 + -1;
            UNLOCK();
            if (iVar5 == 1 || iVar5 + -1 < 0) {
              (**(code **)(**(int **)(local_40 + -0x10) + 4))();
            }
            if (uVar8 == 0) {
              FUN_00413290(piVar16,&local_48,*(int *)(*piVar16 + -0xc) + -4);
              local_8._0_1_ = 4;
              iVar5 = extraout_ECX_00;
              FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
              FUN_0043f8b0(&local_44,0x14b,iVar5);
              local_8._0_1_ = 5;
              FUN_00405650(&local_18,0x56d138);
              local_8._0_1_ = 4;
              LOCK();
              piVar6 = (int *)(local_44 + -4);
              iVar5 = *piVar6;
              *piVar6 = *piVar6 + -1;
              UNLOCK();
              if (iVar5 + -1 < 1) {
                (**(code **)(**(int **)(local_44 + -0x10) + 4))();
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              iVar5 = local_48;
              goto LAB_0042cb44;
            }
            piVar6 = FUN_0040cac0(piVar16,&local_4c,3);
            puVar13 = &DAT_0056d150;
            puVar9 = (ushort *)*piVar6;
            do {
              uVar3 = *puVar9;
              bVar15 = uVar3 < *puVar13;
              if (uVar3 != *puVar13) {
LAB_0042c9f6:
                uVar8 = -(uint)bVar15 | 1;
                goto LAB_0042c9fb;
              }
              if (uVar3 == 0) break;
              uVar3 = puVar9[1];
              bVar15 = uVar3 < puVar13[1];
              if (uVar3 != puVar13[1]) goto LAB_0042c9f6;
              puVar9 = puVar9 + 2;
              puVar13 = puVar13 + 2;
            } while (uVar3 != 0);
            uVar8 = 0;
LAB_0042c9fb:
            LOCK();
            piVar6 = (int *)(local_4c + -4);
            iVar5 = *piVar6;
            *piVar6 = *piVar6 + -1;
            UNLOCK();
            if (iVar5 == 1 || iVar5 + -1 < 0) {
              (**(code **)(**(int **)(local_4c + -0x10) + 4))();
            }
            if (uVar8 == 0) {
              FUN_00413290(piVar16,&local_54,*(int *)(*piVar16 + -0xc) + -3);
              local_8._0_1_ = 6;
              iVar5 = extraout_ECX_01;
              FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
              FUN_0043f8b0(&local_50,0x14b,iVar5);
              local_8._0_1_ = 7;
              FUN_00405650(&local_18,0x56d138);
              local_8._0_1_ = 6;
              LOCK();
              piVar6 = (int *)(local_50 + -4);
              iVar5 = *piVar6;
              *piVar6 = *piVar6 + -1;
              UNLOCK();
              if (iVar5 + -1 < 1) {
                (**(code **)(**(int **)(local_50 + -0x10) + 4))();
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              iVar5 = local_54;
              goto LAB_0042cb44;
            }
            piVar6 = FUN_0040cac0(piVar16,&local_58,5);
            bVar15 = FUN_00413240(piVar6,(ushort *)&DAT_0056e494);
            LOCK();
            piVar6 = (int *)(local_58 + -4);
            iVar5 = *piVar6;
            *piVar6 = *piVar6 + -1;
            UNLOCK();
            if (iVar5 == 1 || iVar5 + -1 < 0) {
              (**(code **)(**(int **)(local_58 + -0x10) + 4))();
            }
            if (bVar15) {
              FUN_00413290(piVar16,&local_60,*(int *)(*piVar16 + -0xc) + -5);
              local_8._0_1_ = 8;
              iVar5 = extraout_ECX_02;
              FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
              FUN_0043f8b0(&local_5c,0x14b,iVar5);
              local_8._0_1_ = 9;
              FUN_00405650(&local_18,0x56d138);
              local_8._0_1_ = 8;
              LOCK();
              piVar6 = (int *)(local_5c + -4);
              iVar5 = *piVar6;
              *piVar6 = *piVar6 + -1;
              UNLOCK();
              if (iVar5 + -1 < 1) {
                (**(code **)(**(int **)(local_5c + -0x10) + 4))();
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              iVar5 = local_60;
              goto LAB_0042cb44;
            }
          }
          pwVar12 = local_18;
          MUI::MListBox::AddString(*(MListBox **)((int)local_30 + 0x55c),local_18,*plVar4,-1);
          local_8 = local_8 & 0xffffff00;
          LOCK();
          pwVar7 = pwVar12 + -2;
          iVar5 = *(int *)pwVar7;
          *(int *)pwVar7 = *(int *)pwVar7 + -1;
          UNLOCK();
          if (iVar5 + -1 < 1) {
            (**(code **)(**(int **)(pwVar12 + -8) + 4))();
          }
          iVar1 = *piVar16;
          LOCK();
          piVar16 = (int *)(iVar1 + -4);
          iVar5 = *piVar16;
          *piVar16 = *piVar16 + -1;
          UNLOCK();
          if (iVar5 == 1 || iVar5 + -1 < 0) {
            (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
          }
          FUN_004644e6(plVar4);
          pvVar14 = (void *)local_24;
        }
        local_2c = local_2c + 1;
        param_1 = local_30;
      } while (local_2c < uVar11);
    }
    local_24 = CONCAT44(pvVar14,(void *)local_24);
    MUI::MListBox::SetCurSel(*(MListBox **)((int)param_1 + 0x55c),0);
    lVar10 = MUI::MListBox::GetItemData(*(MListBox **)((int)param_1 + 0x55c),0);
    FUN_0042cc40(param_1,lVar10);
    FUN_0042c630((void *)((int)param_1 + 0x2c4),1);
  }
  if (pvVar14 != (void *)0x0) {
    FUN_00405190(pvVar14,local_1c - (int)pvVar14 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


