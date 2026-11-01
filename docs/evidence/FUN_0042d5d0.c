

void __fastcall FUN_0042d5d0(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  void *pvVar11;
  void *pvVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  bool bVar15;
  uint uVar16;
  uint uVar17;
  char cVar18;
  int *piVar19;
  int *piVar20;
  uint local_e94;
  uint local_e88;
  uint local_e84;
  undefined1 *local_e80;
  void *local_e7c;
  uint local_e78;
  undefined1 *local_e74;
  undefined8 local_e70;
  int local_e68;
  undefined8 local_e64;
  undefined4 local_e5c;
  undefined4 local_e58;
  undefined1 auStack_e50 [3576];
  undefined2 local_58;
  undefined1 local_50;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00552376;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = FUN_0040f4c0();
  iVar3 = FUN_0040b320(puVar2);
  iVar4 = MUI::MListBox::GetItemCount(*(MListBox **)(param_1 + 0x55c));
  iVar3 = (iVar4 + iVar3) * 8;
  if (iVar3 == 0xa8c || iVar3 + -0xa8c < 0) {
    memset((void *)((int)&local_58 + 1),0,0x40);
    local_58 = 0x1904;
    puVar9 = (undefined4 *)&local_58;
    cVar18 = '\x01';
    uVar16 = 0x41;
    puVar2 = FUN_00413510();
    FUN_0044edb0(puVar2,puVar9,uVar16,cVar18);
    memset(&local_e58,0,0xe00);
    uVar16 = 400;
    local_e78 = 400;
    local_e70 = 0;
    local_e68 = 0;
    piVar19 = (int *)&local_e70;
    local_8 = 0;
    puVar2 = FUN_0040f4c0();
    iVar3 = FUN_0040a9a0(puVar2,piVar19);
    pvVar12 = (void *)local_e70;
    if (0 < iVar3) {
      local_e94 = 0;
      if (0 < iVar3) {
        iVar4 = local_e70._4_4_ - (int)(void *)local_e70;
        do {
          if ((uint)(iVar4 >> 2) <= local_e94) {
LAB_0042da64:
                    /* WARNING: Subroutine does not return */
            std::_Xout_of_range("invalid vector<T> subscript");
          }
          piVar19 = *(int **)((int)pvVar12 + local_e94 * 4);
          if (piVar19 != (int *)0x0) {
            local_e64 = 0;
            local_e5c = 0;
            piVar20 = (int *)&local_e64;
            local_8 = CONCAT31(local_8._1_3_,1);
            iVar5 = *piVar19;
            puVar2 = FUN_0040f4c0();
            iVar5 = FUN_0040aff0(puVar2,iVar5,piVar20);
            if (iVar5 < 1) {
              (&local_e58)[local_e94] = 0xffffffff;
              pvVar11 = (void *)local_e64;
            }
            else {
              iVar10 = 0;
              *(char *)(&local_e58 + local_e94) = (char)local_e78;
              *(char *)((int)&local_e58 + local_e94 * 4 + 1) = (char)(local_e78 >> 8);
              local_e88 = 0;
              if (0 < iVar5) {
                puVar13 = auStack_e50 + local_e78 + 3;
                iVar6 = local_e64._4_4_ - (int)(void *)local_e64;
                puVar8 = auStack_e50 + local_e78 + 1;
                local_e74 = auStack_e50 + local_e78;
                puVar14 = auStack_e50 + local_e78 + 2;
                local_e80 = puVar8;
                do {
                  if ((uint)(iVar6 >> 2) <= local_e88) goto LAB_0042da64;
                  local_e7c = *(void **)((int)(void *)local_e64 + local_e88 * 4);
                  if (local_e7c != (void *)0x0) {
                    if (*(int *)((int)local_e7c + 8) == 2) {
                      local_e84 = *(uint *)((int)local_e7c + 0x10);
                      uVar16 = FUN_00451450(&local_e84);
                      local_e74 = local_e74 + 4;
                      *puVar14 = (char)uVar16;
                      *puVar13 = 0xb0;
                      puVar8 = local_e80;
LAB_0042d8ff:
                      iVar10 = iVar10 + 1;
                      puVar14 = puVar14 + 4;
                      puVar8 = puVar8 + 4;
                      puVar13 = puVar13 + 4;
                    }
                    else {
                      if (*(int *)((int)local_e7c + 8) == 3) {
                        local_e84 = *(uint *)((int)local_e7c + 0x10);
                        uVar16 = FUN_00451450(&local_e84);
                        local_e74 = local_e74 + 4;
                        *puVar14 = (char)uVar16;
                        *puVar13 = 0x30;
                        puVar8 = local_e80;
                        goto LAB_0042d8ff;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 4) &&
                         (*(int *)((int)local_e7c + 0x10) == 1)) {
                        *puVar14 = 1;
                        *puVar13 = 0x90;
LAB_0042d8f6:
                        local_e74 = local_e74 + 4;
                        goto LAB_0042d8ff;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 5) &&
                         (*(int *)((int)local_e7c + 0x10) == 1)) {
                        *puVar14 = 1;
LAB_0042d8f3:
                        *puVar13 = 0x10;
                        goto LAB_0042d8f6;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 4) &&
                         (*(int *)((int)local_e7c + 0x10) == 2)) {
                        *puVar14 = 4;
                        *puVar13 = 0x90;
                        goto LAB_0042d8f6;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 5) &&
                         (*(int *)((int)local_e7c + 0x10) == 2)) {
                        *puVar14 = 4;
                        goto LAB_0042d8f3;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 4) &&
                         (*(int *)((int)local_e7c + 0x10) == 3)) {
                        *puVar14 = 2;
                        *puVar13 = 0x90;
                        goto LAB_0042d8f6;
                      }
                      if ((*(int *)((int)local_e7c + 8) == 5) &&
                         (*(int *)((int)local_e7c + 0x10) == 3)) {
                        *puVar14 = 2;
                        goto LAB_0042d8f3;
                      }
                    }
                    iVar1 = *(int *)((int)local_e7c + 0x14);
                    *puVar13 = 0x50;
                    iVar7 = 10;
                    if (10 < iVar1) {
                      iVar7 = iVar1;
                    }
                    iVar10 = iVar10 + 1;
                    puVar14 = puVar14 + 4;
                    puVar13 = puVar13 + 4;
                    *local_e74 = (char)iVar7;
                    local_e74 = local_e74 + 4;
                    *puVar8 = (char)((uint)iVar7 >> 8);
                    local_e80 = puVar8 + 4;
                    puVar9 = (undefined4 *)(*(int *)((int)local_e7c + 0x18) + -0x10);
                    LOCK();
                    piVar20 = (int *)(*(int *)((int)local_e7c + 0x18) + -4);
                    iVar1 = *piVar20;
                    *piVar20 = *piVar20 + -1;
                    UNLOCK();
                    if (iVar1 == 1 || iVar1 + -1 < 0) {
                      (**(code **)(*(int *)*puVar9 + 4))(puVar9);
                    }
                    FUN_004644e6(local_e7c);
                    puVar8 = local_e80;
                  }
                  local_e88 = local_e88 + 1;
                } while ((int)local_e88 < iVar5);
              }
              *(char *)((int)&local_e58 + local_e78) = (char)iVar10;
              *(char *)((int)&local_e58 + local_e78 + 1) = (char)((uint)iVar10 >> 8);
              uVar16 = local_e78 + iVar10 * 4 + 8;
              local_e64 = CONCAT44((void *)local_e64,(void *)local_e64);
              pvVar11 = (void *)local_e64;
              local_e78 = uVar16;
            }
            puVar9 = (undefined4 *)(piVar19[1] + -0x10);
            LOCK();
            piVar20 = (int *)(piVar19[1] + -4);
            iVar5 = *piVar20;
            *piVar20 = *piVar20 + -1;
            UNLOCK();
            if (iVar5 == 1 || iVar5 + -1 < 0) {
              (**(code **)(*(int *)*puVar9 + 4))(puVar9);
            }
            FUN_004644e6(piVar19);
            local_8 = local_8 & 0xffffff00;
            if (pvVar11 != (void *)0x0) {
              FUN_00405190(pvVar11,local_e5c - (int)pvVar11 >> 2);
              local_e64 = 0;
              local_e5c = 0;
            }
          }
          local_e94 = local_e94 + 1;
        } while ((int)local_e94 < iVar3);
      }
      local_e70 = CONCAT44((void *)local_e70,(void *)local_e70);
      pvVar12 = (void *)local_e70;
    }
    iVar3 = (int)(uVar16 + ((int)uVar16 >> 0x1f & 0x3fU)) >> 6;
    uVar16 = uVar16 & 0x8000003f;
    bVar15 = uVar16 == 0;
    if ((int)uVar16 < 0) {
      bVar15 = (uVar16 - 1 | 0xffffffc0) == 0xffffffff;
    }
    if (bVar15) {
      iVar3 = iVar3 + 1;
    }
    else {
      iVar3 = iVar3 + 2;
    }
    local_50 = (undefined1)iVar3;
    cVar18 = '\x01';
    uVar16 = iVar3 * 0x40;
    puVar9 = (undefined4 *)&local_58;
    uVar17 = 0x41;
    local_58 = 0x1504;
    *(undefined2 *)((int)&local_e5c + uVar16 + 2) = 0x55aa;
    puVar2 = FUN_00413510();
    FUN_0044edb0(puVar2,puVar9,uVar17,cVar18);
    Sleep(0x1e);
    cVar18 = '\x01';
    puVar9 = &local_e58;
    puVar2 = FUN_00413510();
    FUN_0044edb0(puVar2,puVar9,uVar16,cVar18);
    Sleep(0x1e);
    memset(&local_58,0,0x41);
    local_58 = 0x204;
    puVar9 = (undefined4 *)&local_58;
    cVar18 = '\x01';
    uVar16 = 0x41;
    puVar2 = FUN_00413510();
    FUN_0044edb0(puVar2,puVar9,uVar16,cVar18);
    if (pvVar12 != (void *)0x0) {
      FUN_00405190(pvVar12,local_e68 - (int)pvVar12 >> 2);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


