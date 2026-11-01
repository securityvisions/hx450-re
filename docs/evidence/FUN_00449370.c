

void __fastcall FUN_00449370(void *param_1)

{
  int iVar1;
  wchar_t wVar2;
  ushort uVar3;
  long *plVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  wchar_t *pwVar8;
  uint uVar9;
  ushort *puVar10;
  long lVar11;
  undefined4 extraout_ECX;
  uint uVar12;
  wchar_t *pwVar13;
  int extraout_ECX_00;
  ushort *puVar14;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  void *pvVar15;
  bool bVar16;
  undefined4 uVar17;
  int *piVar18;
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
  int local_30;
  uint local_2c;
  undefined8 local_24;
  int local_1c;
  wchar_t *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554070;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  MUI::MListBox::DeleteAllItems(*(MListBox **)((int)param_1 + 0x43c));
  puVar5 = FUN_0040f4c0();
  iVar6 = FUN_00408940(puVar5);
  if (iVar6 < 1) {
    FUN_00449290((void *)((int)param_1 + 0x2c4),0);
    MUI::CCheckButton::SetCheck(*(CCheckButton **)((int)param_1 + 0x4a4),0);
    MUI::CCheckButton::SetCheck(*(CCheckButton **)((int)param_1 + 0x4a8),0);
    MUI::CCheckButton::SetCheck(*(CCheckButton **)((int)param_1 + 0x4ac),0);
    MUI::KeyboardCtrl::ResetAllItemCheck(*(KeyboardCtrl **)((int)param_1 + 0x444),0);
    MUI::MControl::UpdateControl(*(MControl **)((int)param_1 + 0x444),1,0);
  }
  else {
    local_24 = 0;
    local_1c = 0;
    piVar18 = (int *)&local_24;
    local_8 = 0;
    uVar17 = extraout_ECX;
    puVar5 = FUN_0040f4c0();
    iVar6 = FUN_00408d50(puVar5,uVar17,piVar18);
    if (iVar6 < 1) {
      FUN_00449290((void *)((int)param_1 + 0x2c4),0);
      pvVar15 = (void *)local_24;
    }
    else {
      FUN_00449290((void *)((int)param_1 + 0x2c4),1);
      uVar12 = local_24._4_4_ - (int)(void *)local_24 >> 2;
      local_2c = 0;
      pvVar15 = (void *)local_24;
      if (uVar12 != 0) {
        if (uVar12 == 0) {
                    /* WARNING: Subroutine does not return */
          std::_Xout_of_range("invalid vector<T> subscript");
        }
        do {
          plVar4 = *(long **)((int)pvVar15 + local_2c * 4);
          if (plVar4 != (long *)0x0) {
            piVar18 = plVar4 + 2;
            piVar7 = FUN_00405020((int *)(plVar4[2] + -0x10));
            local_18 = (wchar_t *)(piVar7 + 4);
            local_8 = CONCAT31(local_8._1_3_,1);
            piVar7 = FUN_0040cac0(piVar18,&local_30,0xc);
            pwVar13 = L"Custom Light";
            pwVar8 = (wchar_t *)*piVar7;
            do {
              wVar2 = *pwVar8;
              bVar16 = (ushort)wVar2 < (ushort)*pwVar13;
              if (wVar2 != *pwVar13) {
LAB_004494e6:
                uVar9 = -(uint)bVar16 | 1;
                goto LAB_004494eb;
              }
              if (wVar2 == L'\0') break;
              wVar2 = pwVar8[1];
              bVar16 = (ushort)wVar2 < (ushort)pwVar13[1];
              if (wVar2 != pwVar13[1]) goto LAB_004494e6;
              pwVar8 = pwVar8 + 2;
              pwVar13 = pwVar13 + 2;
            } while (wVar2 != L'\0');
            uVar9 = 0;
LAB_004494eb:
            LOCK();
            piVar7 = (int *)(local_30 + -4);
            iVar6 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar6 == 1 || iVar6 + -1 < 0) {
              (**(code **)(**(int **)(local_30 + -0x10) + 4))();
            }
            if (uVar9 == 0) {
              FUN_00413290(piVar18,&local_38,*(int *)(*piVar18 + -0xc) + -0xc);
              local_8._0_1_ = 2;
              iVar6 = extraout_ECX_00;
              FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
              FUN_0043f8b0(&local_34,0x4e,iVar6);
              local_8._0_1_ = 3;
              FUN_00405650(&local_18,0x56d138);
              local_8._0_1_ = 2;
              LOCK();
              piVar7 = (int *)(local_34 + -4);
              iVar6 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar6 + -1 < 1) {
                (**(code **)(**(int **)(local_34 + -0x10) + 4))();
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              iVar6 = local_38;
LAB_00449703:
              LOCK();
              piVar7 = (int *)(iVar6 + -4);
              iVar1 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar1 == 1 || iVar1 + -1 < 0) {
                (**(code **)(**(int **)(iVar6 + -0x10) + 4))();
              }
            }
            else {
              piVar7 = FUN_0040cac0(piVar18,&local_3c,5);
              puVar14 = &DAT_0056f860;
              puVar10 = (ushort *)*piVar7;
              do {
                uVar3 = *puVar10;
                bVar16 = uVar3 < *puVar14;
                if (uVar3 != *puVar14) {
LAB_004495bb:
                  uVar9 = -(uint)bVar16 | 1;
                  goto LAB_004495c0;
                }
                if (uVar3 == 0) break;
                uVar3 = puVar10[1];
                bVar16 = uVar3 < puVar14[1];
                if (uVar3 != puVar14[1]) goto LAB_004495bb;
                puVar10 = puVar10 + 2;
                puVar14 = puVar14 + 2;
              } while (uVar3 != 0);
              uVar9 = 0;
LAB_004495c0:
              LOCK();
              piVar7 = (int *)(local_3c + -4);
              iVar6 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar6 == 1 || iVar6 + -1 < 0) {
                (**(code **)(**(int **)(local_3c + -0x10) + 4))();
              }
              if (uVar9 == 0) {
                FUN_00413290(piVar18,&local_44,*(int *)(*piVar18 + -0xc) + -5);
                local_8._0_1_ = 4;
                iVar6 = extraout_ECX_01;
                FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
                FUN_0043f8b0(&local_40,0x4e,iVar6);
                local_8._0_1_ = 5;
                FUN_00405650(&local_18,0x56d138);
                local_8._0_1_ = 4;
                LOCK();
                piVar7 = (int *)(local_40 + -4);
                iVar6 = *piVar7;
                *piVar7 = *piVar7 + -1;
                UNLOCK();
                if (iVar6 + -1 < 1) {
                  (**(code **)(**(int **)(local_40 + -0x10) + 4))();
                }
                local_8 = CONCAT31(local_8._1_3_,1);
                iVar6 = local_44;
                goto LAB_00449703;
              }
              piVar7 = FUN_0040cac0(piVar18,&local_48,5);
              bVar16 = FUN_00413240(piVar7,&DAT_0056f86c);
              LOCK();
              piVar7 = (int *)(local_48 + -4);
              iVar6 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar6 == 1 || iVar6 + -1 < 0) {
                (**(code **)(**(int **)(local_48 + -0x10) + 4))();
              }
              if (bVar16) {
                FUN_00413290(piVar18,&local_50,*(int *)(*piVar18 + -0xc) + -5);
                local_8._0_1_ = 6;
                iVar6 = extraout_ECX_02;
                FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
                FUN_0043f8b0(&local_4c,0x4e,iVar6);
                local_8._0_1_ = 7;
                FUN_00405650(&local_18,0x56d138);
                local_8._0_1_ = 6;
                LOCK();
                piVar7 = (int *)(local_4c + -4);
                iVar6 = *piVar7;
                *piVar7 = *piVar7 + -1;
                UNLOCK();
                if (iVar6 + -1 < 1) {
                  (**(code **)(**(int **)(local_4c + -0x10) + 4))();
                }
                local_8 = CONCAT31(local_8._1_3_,1);
                iVar6 = local_50;
                goto LAB_00449703;
              }
              piVar7 = FUN_0040cac0(piVar18,&local_54,7);
              bVar16 = FUN_00413240(piVar7,&DAT_0056f850);
              LOCK();
              piVar7 = (int *)(local_54 + -4);
              iVar6 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar6 == 1 || iVar6 + -1 < 0) {
                (**(code **)(**(int **)(local_54 + -0x10) + 4))();
              }
              if (bVar16) {
                FUN_00413290(piVar18,&local_5c,*(int *)(*piVar18 + -0xc) + -7);
                local_8._0_1_ = 8;
                iVar6 = extraout_ECX_03;
                FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
                FUN_0043f8b0(&local_58,0x4e,iVar6);
                local_8._0_1_ = 9;
                FUN_00405650(&local_18,0x56d138);
                FUN_00404800(&local_58);
                local_8 = CONCAT31(local_8._1_3_,1);
                FUN_00404800(&local_5c);
              }
            }
            pwVar13 = local_18;
            MUI::MListBox::AddString(*(MListBox **)((int)param_1 + 0x43c),local_18,*plVar4,-1);
            local_8 = local_8 & 0xffffff00;
            LOCK();
            pwVar8 = pwVar13 + -2;
            iVar6 = *(int *)pwVar8;
            *(int *)pwVar8 = *(int *)pwVar8 + -1;
            UNLOCK();
            if (iVar6 + -1 < 1) {
              (**(code **)(**(int **)(pwVar13 + -8) + 4))();
            }
            iVar1 = *piVar18;
            LOCK();
            piVar18 = (int *)(iVar1 + -4);
            iVar6 = *piVar18;
            *piVar18 = *piVar18 + -1;
            UNLOCK();
            if (iVar6 == 1 || iVar6 + -1 < 0) {
              (**(code **)(**(int **)(iVar1 + -0x10) + 4))();
            }
            FUN_004644e6(plVar4);
            pvVar15 = (void *)local_24;
          }
          local_2c = local_2c + 1;
        } while (local_2c < uVar12);
      }
      local_24 = CONCAT44(pvVar15,(void *)local_24);
      MUI::MListBox::SetCurSel(*(MListBox **)((int)param_1 + 0x43c),0);
    }
    lVar11 = MUI::MListBox::GetItemData(*(MListBox **)((int)param_1 + 0x43c),0);
    FUN_004498a0(param_1,lVar11);
    if (pvVar15 != (void *)0x0) {
      FUN_00405190(pvVar15,local_1c - (int)pvVar15 >> 2);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


