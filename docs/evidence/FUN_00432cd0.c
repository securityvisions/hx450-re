

void __fastcall FUN_00432cd0(void *param_1)

{
  int iVar1;
  wchar_t wVar2;
  ushort uVar3;
  long *plVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  wchar_t *pwVar8;
  ushort *puVar9;
  long lVar10;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint uVar11;
  wchar_t *pwVar12;
  int extraout_ECX_03;
  ushort *puVar13;
  int extraout_ECX_04;
  int extraout_ECX_05;
  int extraout_ECX_06;
  void *pvVar14;
  bool bVar15;
  undefined4 uVar16;
  wchar_t **ppwVar17;
  int *piVar18;
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
  int local_38;
  uint local_34;
  void *local_30;
  uint local_2c;
  undefined8 local_24;
  int local_1c;
  wchar_t *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005529a4;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = param_1;
  FUN_00432770((int)param_1);
  puVar5 = FUN_0040f4c0();
  iVar6 = FUN_00402eb0(puVar5);
  if (iVar6 < 1) {
    local_18 = (wchar_t *)0x0;
    iVar6 = extraout_ECX;
    FUN_0040cbd0(&stack0xffffff80,L"KB.DIALOG");
    FUN_0043f8b0(&local_18,0x65,iVar6);
    local_8 = 0;
    FUN_00415880(&local_18,L" 1",2);
    iVar6 = (uint)(*(int *)((int)param_1 + 0x7ac) == 0) * 2 + 4;
    ppwVar17 = &local_18;
    uVar16 = extraout_ECX_00;
    puVar5 = FUN_0040f4c0();
    FUN_00402f80(puVar5,uVar16,ppwVar17,iVar6);
    iVar6 = 1;
    uVar16 = extraout_ECX_01;
    puVar5 = FUN_0040f4c0();
    FUN_004037f0(puVar5,uVar16,iVar6);
    local_8 = 0xffffffff;
    LOCK();
    pwVar8 = local_18 + -2;
    iVar6 = *(int *)pwVar8;
    *(int *)pwVar8 = *(int *)pwVar8 + -1;
    UNLOCK();
    if (iVar6 == 1 || iVar6 + -1 < 0) {
      (**(code **)(**(int **)(local_18 + -8) + 4))();
    }
  }
  MUI::MListBox::DeleteAllItems(*(MListBox **)((int)param_1 + 0x604));
  local_24 = 0;
  local_1c = 0;
  piVar18 = (int *)&local_24;
  local_8 = 1;
  uVar16 = extraout_ECX_02;
  puVar5 = FUN_0040f4c0();
  iVar6 = FUN_004032e0(puVar5,uVar16,piVar18);
  pvVar14 = (void *)local_24;
  if (0 < iVar6) {
    local_2c = 0;
    uVar11 = local_24._4_4_ - (int)(void *)local_24 >> 2;
    local_34 = uVar11;
    if (uVar11 != 0) {
      if (uVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      do {
        plVar4 = *(long **)((int)pvVar14 + local_2c * 4);
        if (plVar4 != (long *)0x0) {
          piVar18 = plVar4 + 2;
          piVar7 = FUN_00405020((int *)(plVar4[2] + -0x10));
          local_18 = (wchar_t *)(piVar7 + 4);
          local_8 = CONCAT31(local_8._1_3_,2);
          piVar7 = FUN_0040cac0(piVar18,&local_38,0x10);
          pwVar12 = L"New Music Effect";
          pwVar8 = (wchar_t *)*piVar7;
          do {
            wVar2 = *pwVar8;
            bVar15 = (ushort)wVar2 < (ushort)*pwVar12;
            if (wVar2 != *pwVar12) {
LAB_00432e77:
              uVar11 = -(uint)bVar15 | 1;
              goto LAB_00432e7c;
            }
            if (wVar2 == L'\0') break;
            wVar2 = pwVar8[1];
            bVar15 = (ushort)wVar2 < (ushort)pwVar12[1];
            if (wVar2 != pwVar12[1]) goto LAB_00432e77;
            pwVar8 = pwVar8 + 2;
            pwVar12 = pwVar12 + 2;
          } while (wVar2 != L'\0');
          uVar11 = 0;
LAB_00432e7c:
          LOCK();
          piVar7 = (int *)(local_38 + -4);
          iVar6 = *piVar7;
          *piVar7 = *piVar7 + -1;
          UNLOCK();
          if (iVar6 == 1 || iVar6 + -1 < 0) {
            (**(code **)(**(int **)(local_38 + -0x10) + 4))();
          }
          if (uVar11 == 0) {
            FUN_00413290(piVar18,&local_40,*(int *)(*piVar18 + -0xc) + -0x10);
            local_8._0_1_ = 3;
            iVar6 = extraout_ECX_03;
            FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
            FUN_0043f8b0(&local_3c,0x65,iVar6);
            local_8._0_1_ = 4;
            FUN_00405650(&local_18,0x56d138);
            local_8._0_1_ = 3;
            LOCK();
            piVar7 = (int *)(local_3c + -4);
            iVar6 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar6 + -1 < 1) {
              (**(code **)(**(int **)(local_3c + -0x10) + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,2);
            iVar6 = local_40;
LAB_0043316e:
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
            piVar7 = FUN_0040cac0(piVar18,&local_44,5);
            puVar13 = &DAT_0056e934;
            puVar9 = (ushort *)*piVar7;
            do {
              uVar3 = *puVar9;
              bVar15 = uVar3 < *puVar13;
              if (uVar3 != *puVar13) {
LAB_00432f4c:
                uVar11 = -(uint)bVar15 | 1;
                goto LAB_00432f51;
              }
              if (uVar3 == 0) break;
              uVar3 = puVar9[1];
              bVar15 = uVar3 < puVar13[1];
              if (uVar3 != puVar13[1]) goto LAB_00432f4c;
              puVar9 = puVar9 + 2;
              puVar13 = puVar13 + 2;
            } while (uVar3 != 0);
            uVar11 = 0;
LAB_00432f51:
            LOCK();
            piVar7 = (int *)(local_44 + -4);
            iVar6 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar6 == 1 || iVar6 + -1 < 0) {
              (**(code **)(**(int **)(local_44 + -0x10) + 4))();
            }
            if (uVar11 == 0) {
              FUN_00413290(piVar18,&local_4c,*(int *)(*piVar18 + -0xc) + -5);
              local_8._0_1_ = 5;
              iVar6 = extraout_ECX_04;
              FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
              FUN_0043f8b0(&local_48,0x65,iVar6);
              local_8._0_1_ = 6;
              FUN_00405650(&local_18,0x56d138);
              local_8._0_1_ = 5;
              LOCK();
              piVar7 = (int *)(local_48 + -4);
              iVar6 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar6 + -1 < 1) {
                (**(code **)(**(int **)(local_48 + -0x10) + 4))();
              }
              local_8 = CONCAT31(local_8._1_3_,2);
              iVar6 = local_4c;
              goto LAB_0043316e;
            }
            piVar7 = FUN_0040cac0(piVar18,&local_50,5);
            puVar13 = &DAT_0056e928;
            puVar9 = (ushort *)*piVar7;
            do {
              uVar3 = *puVar9;
              bVar15 = uVar3 < *puVar13;
              if (uVar3 != *puVar13) {
LAB_00433026:
                uVar11 = -(uint)bVar15 | 1;
                goto LAB_0043302b;
              }
              if (uVar3 == 0) break;
              uVar3 = puVar9[1];
              bVar15 = uVar3 < puVar13[1];
              if (uVar3 != puVar13[1]) goto LAB_00433026;
              puVar9 = puVar9 + 2;
              puVar13 = puVar13 + 2;
            } while (uVar3 != 0);
            uVar11 = 0;
LAB_0043302b:
            LOCK();
            piVar7 = (int *)(local_50 + -4);
            iVar6 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar6 == 1 || iVar6 + -1 < 0) {
              (**(code **)(**(int **)(local_50 + -0x10) + 4))();
            }
            if (uVar11 == 0) {
              FUN_00413290(piVar18,&local_58,*(int *)(*piVar18 + -0xc) + -5);
              local_8._0_1_ = 7;
              iVar6 = extraout_ECX_05;
              FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
              FUN_0043f8b0(&local_54,0x65,iVar6);
              local_8._0_1_ = 8;
              FUN_00405650(&local_18,0x56d138);
              local_8._0_1_ = 7;
              LOCK();
              piVar7 = (int *)(local_54 + -4);
              iVar6 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar6 + -1 < 1) {
                (**(code **)(**(int **)(local_54 + -0x10) + 4))();
              }
              local_8 = CONCAT31(local_8._1_3_,2);
              iVar6 = local_58;
              goto LAB_0043316e;
            }
            piVar7 = FUN_0040cac0(piVar18,&local_5c,7);
            bVar15 = FUN_00413240(piVar7,&DAT_0056e940);
            LOCK();
            piVar7 = (int *)(local_5c + -4);
            iVar6 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar6 == 1 || iVar6 + -1 < 0) {
              (**(code **)(**(int **)(local_5c + -0x10) + 4))();
            }
            if (bVar15) {
              FUN_00413290(piVar18,&local_64,*(int *)(*piVar18 + -0xc) + -7);
              local_8._0_1_ = 9;
              iVar6 = extraout_ECX_06;
              FUN_0040cbd0(&stack0xffffff7c,L"KB.DIALOG");
              FUN_0043f8b0(&local_60,0x65,iVar6);
              local_8._0_1_ = 10;
              FUN_00405650(&local_18,0x56d138);
              local_8._0_1_ = 9;
              LOCK();
              piVar7 = (int *)(local_60 + -4);
              iVar6 = *piVar7;
              *piVar7 = *piVar7 + -1;
              UNLOCK();
              if (iVar6 + -1 < 1) {
                (**(code **)(**(int **)(local_60 + -0x10) + 4))();
              }
              local_8 = CONCAT31(local_8._1_3_,2);
              iVar6 = local_64;
              goto LAB_0043316e;
            }
          }
          pwVar12 = local_18;
          MUI::MListBox::AddString(*(MListBox **)((int)local_30 + 0x604),local_18,*plVar4,-1);
          local_8 = CONCAT31(local_8._1_3_,1);
          LOCK();
          pwVar8 = pwVar12 + -2;
          iVar6 = *(int *)pwVar8;
          *(int *)pwVar8 = *(int *)pwVar8 + -1;
          UNLOCK();
          if (iVar6 + -1 < 1) {
            (**(code **)(**(int **)(pwVar12 + -8) + 4))();
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
          uVar11 = local_34;
          pvVar14 = (void *)local_24;
        }
        local_2c = local_2c + 1;
        param_1 = local_30;
      } while (local_2c < uVar11);
    }
    local_24 = CONCAT44(pvVar14,(void *)local_24);
  }
  if ((*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595140) &&
     (FUN_004646a0(&DAT_00595140), DAT_00595140 == -1)) {
    local_8._0_1_ = 0xb;
    memset(&DAT_005950d0,0,0x70);
    FUN_00401250();
    _atexit(thunk_FUN_00401370);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00464661(&DAT_00595140);
  }
  lVar10 = FUN_00403910(&DAT_005950d0);
  MUI::MListBox::SetCurData(*(MListBox **)((int)param_1 + 0x604),lVar10);
  FUN_004334a0(param_1,lVar10);
  if (pvVar14 != (void *)0x0) {
    FUN_00405190(pvVar14,local_1c - (int)pvVar14 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


