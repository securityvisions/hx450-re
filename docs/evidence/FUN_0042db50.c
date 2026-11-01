

void __fastcall FUN_0042db50(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  void *pvVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  uint local_e98;
  uint local_e90;
  uint local_e84;
  undefined1 *local_e80;
  void *local_e7c;
  int local_e78;
  undefined1 *local_e74;
  undefined8 local_e70;
  int local_e68;
  undefined8 local_e64;
  undefined4 local_e5c;
  undefined4 local_e58;
  undefined1 auStack_e50 [3576];
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
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005523c2;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = FUN_0040f4c0();
  iVar3 = FUN_0040b320(puVar2);
  iVar4 = MUI::MListBox::GetItemCount(*(MListBox **)(param_1 + 0x55c));
  iVar3 = (iVar4 + iVar3) * 8;
  if (iVar3 == 0xe10 || iVar3 + -0xe10 < 0) {
    memset(&local_e58,0,0xe00);
    iVar3 = 400;
    local_e78 = 400;
    local_e70 = 0;
    local_e68 = 0;
    piVar16 = (int *)&local_e70;
    local_8 = 0;
    puVar2 = FUN_0040f4c0();
    iVar4 = FUN_0040a9a0(puVar2,piVar16);
    if (0 < iVar4) {
      local_e98 = 0;
      if (0 < iVar4) {
        iVar15 = (int)(void *)local_e70;
        iVar5 = local_e70._4_4_ - (int)(void *)local_e70;
        do {
          if ((uint)(iVar5 >> 2) <= local_e98) {
LAB_0042dfbd:
                    /* WARNING: Subroutine does not return */
            std::_Xout_of_range("invalid vector<T> subscript");
          }
          piVar16 = *(int **)(iVar15 + local_e98 * 4);
          if (piVar16 != (int *)0x0) {
            local_e64 = 0;
            local_e5c = 0;
            piVar17 = (int *)&local_e64;
            local_8 = CONCAT31(local_8._1_3_,1);
            iVar3 = *piVar16;
            puVar2 = FUN_0040f4c0();
            iVar3 = FUN_0040aff0(puVar2,iVar3,piVar17);
            if (iVar3 < 1) {
              (&local_e58)[local_e98] = 0xffffffff;
              pvVar12 = (void *)local_e64;
            }
            else {
              iVar11 = 0;
              *(char *)(&local_e58 + local_e98) = (char)local_e78;
              *(char *)((int)&local_e58 + local_e98 * 4 + 1) = (char)((uint)local_e78 >> 8);
              local_e90 = 0;
              if (0 < iVar3) {
                puVar13 = auStack_e50 + local_e78 + 3;
                iVar6 = local_e64._4_4_ - (int)(void *)local_e64;
                puVar9 = auStack_e50 + local_e78 + 1;
                local_e74 = auStack_e50 + local_e78;
                puVar14 = auStack_e50 + local_e78 + 2;
                local_e80 = puVar9;
                do {
                  if ((uint)(iVar6 >> 2) <= local_e90) goto LAB_0042dfbd;
                  local_e7c = *(void **)((int)(void *)local_e64 + local_e90 * 4);
                  if (local_e7c != (void *)0x0) {
                    if (*(int *)((int)local_e7c + 8) == 2) {
                      local_e84 = *(uint *)((int)local_e7c + 0x10);
                      uVar7 = FUN_00451450(&local_e84);
                      local_e74 = local_e74 + 4;
                      *puVar14 = (char)uVar7;
                      *puVar13 = 0xb0;
                      puVar9 = local_e80;
LAB_0042de5f:
                      iVar11 = iVar11 + 1;
                      puVar14 = puVar14 + 4;
                      puVar9 = puVar9 + 4;
                      puVar13 = puVar13 + 4;
                    }
                    else {
                      if (*(int *)((int)local_e7c + 8) == 3) {
                        local_e84 = *(uint *)((int)local_e7c + 0x10);
                        uVar7 = FUN_00451450(&local_e84);
                        local_e74 = local_e74 + 4;
                        *puVar14 = (char)uVar7;
                        *puVar13 = 0x30;
                        puVar9 = local_e80;
                        goto LAB_0042de5f;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 4) &&
                         (*(int *)((int)local_e7c + 0x10) == 1)) {
                        *puVar14 = 1;
                        *puVar13 = 0x90;
LAB_0042de56:
                        local_e74 = local_e74 + 4;
                        goto LAB_0042de5f;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 5) &&
                         (*(int *)((int)local_e7c + 0x10) == 1)) {
                        *puVar14 = 1;
LAB_0042de53:
                        *puVar13 = 0x10;
                        goto LAB_0042de56;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 4) &&
                         (*(int *)((int)local_e7c + 0x10) == 2)) {
                        *puVar14 = 4;
                        *puVar13 = 0x90;
                        goto LAB_0042de56;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 5) &&
                         (*(int *)((int)local_e7c + 0x10) == 2)) {
                        *puVar14 = 4;
                        goto LAB_0042de53;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 4) &&
                         (*(int *)((int)local_e7c + 0x10) == 3)) {
                        *puVar14 = 2;
                        *puVar13 = 0x90;
                        goto LAB_0042de56;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 5) &&
                         (*(int *)((int)local_e7c + 0x10) == 3)) {
                        *puVar14 = 2;
                        goto LAB_0042de53;
                      }
                    }
                    iVar1 = *(int *)((int)local_e7c + 0x14);
                    *puVar13 = 0x50;
                    iVar8 = 10;
                    if (10 < iVar1) {
                      iVar8 = iVar1;
                    }
                    iVar11 = iVar11 + 1;
                    puVar14 = puVar14 + 4;
                    puVar13 = puVar13 + 4;
                    *local_e74 = (char)iVar8;
                    local_e74 = local_e74 + 4;
                    *puVar9 = (char)((uint)iVar8 >> 8);
                    local_e80 = puVar9 + 4;
                    puVar10 = (undefined4 *)(*(int *)((int)local_e7c + 0x18) + -0x10);
                    LOCK();
                    piVar17 = (int *)(*(int *)((int)local_e7c + 0x18) + -4);
                    iVar1 = *piVar17;
                    *piVar17 = *piVar17 + -1;
                    UNLOCK();
                    if (iVar1 == 1 || iVar1 + -1 < 0) {
                      (**(code **)(*(int *)*puVar10 + 4))(puVar10);
                    }
                    FUN_004644e6(local_e7c);
                    puVar9 = local_e80;
                  }
                  local_e90 = local_e90 + 1;
                } while ((int)local_e90 < iVar3);
              }
              *(char *)((int)&local_e58 + local_e78) = (char)iVar11;
              *(char *)((int)&local_e58 + local_e78 + 1) = (char)((uint)iVar11 >> 8);
              local_e78 = local_e78 + iVar11 * 4 + 8;
              local_e64 = CONCAT44((void *)local_e64,(void *)local_e64);
              pvVar12 = (void *)local_e64;
            }
            puVar10 = (undefined4 *)(piVar16[1] + -0x10);
            LOCK();
            piVar17 = (int *)(piVar16[1] + -4);
            iVar3 = *piVar17;
            *piVar17 = *piVar17 + -1;
            UNLOCK();
            if (iVar3 == 1 || iVar3 + -1 < 0) {
              (**(code **)(*(int *)*puVar10 + 4))(puVar10);
            }
            FUN_004644e6(piVar16);
            local_8 = local_8 & 0xffffff00;
            if (pvVar12 != (void *)0x0) {
              FUN_00405190(pvVar12,local_e5c - (int)pvVar12 >> 2);
              local_e64 = 0;
              local_e5c = 0;
            }
          }
          local_e98 = local_e98 + 1;
          iVar3 = local_e78;
        } while ((int)local_e98 < iVar4);
      }
      local_e70 = CONCAT44((void *)local_e70,(void *)local_e70);
    }
    iVar3 = iVar3 / 0x1c;
    iVar15 = (local_e78 + iVar3 * -0x1c != 0) + 1 + iVar3;
    iVar4 = 0;
    *(undefined2 *)((int)&local_e5c + iVar15 * 0x1c + 2) = 0x55aa;
    if (0 < iVar15) {
      puVar10 = &local_e58;
      iVar5 = *(int *)ThreadLocalStoragePointer;
      do {
        memset(&local_58,0,0x41);
        local_58._1_2_ = 0x1c09;
        local_58._3_1_ = (char)iVar4;
        if (iVar4 == iVar15 + -1) {
          local_58._1_2_ = CONCAT11((char)local_e78 + (char)iVar3 * -0x1c,9);
        }
        local_54 = *puVar10;
        uStack_50 = puVar10[1];
        uStack_4c = puVar10[2];
        uStack_48 = puVar10[3];
        local_3c = puVar10[6];
        local_44 = *(undefined8 *)(puVar10 + 4);
        if ((*(int *)(iVar5 + 4) < DAT_00595178) &&
           (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
          local_8._0_1_ = 2;
          memset(&DAT_00595144,0,0x34);
          FUN_0044e680();
          _atexit(thunk_FUN_0044e780);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00464661(&DAT_00595178);
        }
        FUN_0044f4d0(&DAT_00595144,&local_58,0x41);
        puVar10 = puVar10 + 7;
        Sleep(2);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar15);
    }
    if ((void *)local_e70 != (void *)0x0) {
      FUN_00405190((void *)local_e70,local_e68 - (int)(void *)local_e70 >> 2);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


