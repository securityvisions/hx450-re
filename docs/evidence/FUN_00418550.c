

void __thiscall FUN_00418550(void *this,int param_1)

{
  void *pvVar1;
  undefined1 uVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int extraout_EDX;
  undefined4 *puVar9;
  int iVar10;
  void *pvVar11;
  bool bVar12;
  bool bVar13;
  int iVar14;
  uint uVar15;
  char cVar16;
  int local_394;
  uint local_390;
  undefined4 local_38c;
  int local_388;
  void *local_384;
  uint local_380;
  undefined8 local_37c;
  int local_374;
  undefined8 local_370;
  int local_368;
  undefined4 local_364;
  undefined2 local_126;
  undefined4 local_58;
  undefined1 local_50;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055073a;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_384 = this;
  memset((void *)((int)&local_58 + 1),0,0x40);
  local_58._0_2_ = 0x1804;
  puVar9 = &local_58;
  cVar16 = '\x01';
  uVar15 = 0x41;
  puVar3 = FUN_00413510();
  FUN_0044edb0(puVar3,puVar9,uVar15,cVar16);
  uVar2 = 0x11;
  local_50 = 9;
  if (param_1 != 0) {
    uVar2 = 0x27;
  }
  cVar16 = '\x01';
  local_58._0_2_ = CONCAT11(uVar2,4);
  puVar9 = &local_58;
  uVar15 = 0x41;
  puVar3 = FUN_00413510();
  FUN_0044edb0(puVar3,puVar9,uVar15,cVar16);
  memset(&local_364,0,0x30c);
  local_370 = 0;
  local_368 = 0;
  piVar4 = (int *)&local_370;
  local_8 = 0;
  uVar15 = (uint)(param_1 != 0);
  iVar14 = *(int *)((int)this + 0x7f8);
  puVar3 = FUN_0040f4c0();
  FUN_004061b0(puVar3,iVar14,uVar15,piVar4);
  uVar15 = local_370._4_4_ - (int)(void *)local_370 >> 2;
  local_390 = 0;
  pvVar11 = (void *)local_370;
  local_380 = uVar15;
  if (0 < (int)uVar15) {
    bVar12 = false;
    bVar13 = uVar15 == 0;
    do {
      if (bVar12 || bVar13) goto LAB_00418dd8;
      iVar14 = *(int *)((int)pvVar11 + local_390 * 4);
      if ((iVar14 != 0) && (*(int *)(iVar14 + 0x18) != 0)) {
        iVar10 = 0;
        if (*(int *)((int)this + 0x820) != 0) {
          puVar9 = *(undefined4 **)((int)this + 0x81c);
          puVar8 = puVar9;
          if (*(char *)((int)puVar9[1] + 0xd) == '\0') {
            puVar6 = (undefined4 *)puVar9[1];
            do {
              if ((int)puVar6[4] < *(int *)(iVar14 + 0xc)) {
                puVar7 = (undefined4 *)puVar6[2];
              }
              else {
                puVar7 = (undefined4 *)*puVar6;
                puVar8 = puVar6;
              }
              puVar6 = puVar7;
              this = local_384;
            } while (*(char *)((int)puVar7 + 0xd) == '\0');
          }
          if ((puVar8 == puVar9) || (*(int *)(iVar14 + 0xc) < (int)puVar8[4])) {
            puVar8 = puVar9;
          }
          iVar10 = puVar8[5];
        }
        if (((param_1 == 0) || (*(int *)((int)this + 0x830) == 0)) ||
           (iVar5 = *(int *)((int)this + 0x82c),
           piVar4 = FUN_0040c770((int *)((int)this + 0x82c),&local_394,(int *)(iVar14 + 0xc)),
           *piVar4 == iVar5)) {
          iVar5 = *(int *)(iVar14 + 0x18);
          if (iVar5 == 1) {
            *(undefined2 *)(&local_364 + iVar10) = 0x305;
          }
          else if (iVar5 == 2) {
            iVar5 = *(int *)(iVar14 + 0x1c);
            *(undefined1 *)(&local_364 + iVar10) = 2;
            *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = *(undefined1 *)(iVar14 + 0x20);
            iVar5 = FUN_00451b80(iVar5);
            iVar14 = *(int *)(iVar14 + 0x20);
            *(char *)((int)&local_364 + iVar10 * 4 + 2) = (char)iVar5;
            if (((iVar14 == 0) && (0xdf < extraout_EDX)) && (extraout_EDX < 0xe8)) {
              *(char *)((int)&local_364 + iVar10 * 4 + 1) = (char)iVar5;
              if (0x30b < iVar10 * 4 + 2U) {
                    /* WARNING: Subroutine does not return */
                ___report_rangecheckfailure();
              }
              *(undefined1 *)((int)&local_364 + iVar10 * 4 + 2) = 0;
            }
          }
          else if (iVar5 == 0xd) {
            *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = *(undefined1 *)(iVar14 + 0x1c);
            *(undefined1 *)((int)&local_364 + iVar10 * 4 + 2) = *(undefined1 *)(iVar14 + 0x20);
            uVar2 = *(undefined1 *)(iVar14 + 0x24);
            *(undefined1 *)(&local_364 + iVar10) = 7;
            *(undefined1 *)((int)&local_364 + iVar10 * 4 + 3) = uVar2;
          }
          else if (iVar5 == 3) {
            local_37c = 0;
            local_374 = 0;
            piVar4 = (int *)&local_37c;
            local_8 = CONCAT31(local_8._1_3_,1);
            puVar3 = FUN_0040f4c0();
            local_388 = FUN_0040a9a0(puVar3,piVar4);
            uVar15 = 0;
            if (0 < local_388) {
              do {
                if ((uint)(local_37c._4_4_ - (int)(void *)local_37c >> 2) <= uVar15)
                goto LAB_00418dd8;
                piVar4 = *(int **)((int)(void *)local_37c + uVar15 * 4);
                if ((piVar4 != (int *)0x0) && (*piVar4 == *(int *)(iVar14 + 0x1c))) {
                  *(undefined1 *)((int)&local_364 + iVar10 * 4 + 2) = *(undefined1 *)(iVar14 + 0x20)
                  ;
                  uVar2 = *(undefined1 *)(iVar14 + 0x24);
                  *(undefined1 *)(&local_364 + iVar10) = 6;
                  *(char *)((int)&local_364 + iVar10 * 4 + 1) = (char)uVar15;
                  *(undefined1 *)((int)&local_364 + iVar10 * 4 + 3) = uVar2;
                  break;
                }
                uVar15 = uVar15 + 1;
              } while ((int)uVar15 < local_388);
            }
            local_8 = local_8 & 0xffffff00;
            if ((void *)local_37c != (void *)0x0) {
              FUN_00405190((void *)local_37c,local_374 - (int)(void *)local_37c >> 2);
              local_37c = 0;
              local_374 = 0;
            }
          }
          else if (iVar5 != 4) {
            if (iVar5 == 5) {
              iVar14 = *(int *)(iVar14 + 0x1c);
              *(undefined1 *)(&local_364 + iVar10) = 1;
              if (iVar14 == 1) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x101;
              }
              else if (iVar14 == 2) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x401;
              }
              else if (iVar14 == 3) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x201;
              }
              else if (iVar14 == 4) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x301;
              }
              else if (iVar14 == 5) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x103;
              }
              else if (iVar14 == 6) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0xff03;
              }
              else if (iVar14 == 7) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x801;
              }
              else if (iVar14 == 8) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x1001;
              }
            }
            else if (iVar5 == 6) {
              iVar14 = *(int *)(iVar14 + 0x1c);
              *(undefined1 *)(&local_364 + iVar10) = 3;
              if (iVar14 == 1) {
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = 0xcd;
              }
              else if (iVar14 == 2) {
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = 0xb7;
              }
              else if (iVar14 == 3) {
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = 0xb6;
              }
              else if (iVar14 == 4) {
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = 0xb5;
              }
              else if (iVar14 == 5) {
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = 0xe9;
              }
              else if (iVar14 == 6) {
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = 0xea;
              }
              else if (iVar14 == 7) {
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = 0xe2;
              }
            }
            else if (iVar5 == 7) {
              iVar14 = *(int *)(iVar14 + 0x1c);
              *(undefined1 *)(&local_364 + iVar10) = 2;
              if (iVar14 == 1) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x708;
              }
              else if (iVar14 == 2) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x808;
              }
              else if (iVar14 == 3) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0xf08;
              }
              else if (iVar14 == 4) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x1a01;
              }
              else if (iVar14 == 5) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x2b04;
              }
              else if (iVar14 == 6) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x601;
              }
              else if (iVar14 == 7) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x1901;
              }
              else if (iVar14 == 8) {
                *(undefined2 *)((int)&local_364 + iVar10 * 4 + 1) = 0x1b01;
              }
              else if (iVar14 == 0xb) {
                *(undefined2 *)(&local_364 + iVar10) = 0x102;
              }
              else if (iVar14 == 10) {
                *(undefined2 *)(&local_364 + iVar10) = 0x202;
              }
            }
            else {
              if ((((iVar5 == 8) || (iVar5 == 9)) || (iVar5 == 10)) || (iVar5 == 0xb)) {
                uVar2 = *(undefined1 *)(iVar14 + 0x1c);
                *(undefined2 *)(&local_364 + iVar10) = 0x205;
              }
              else {
                if (iVar5 != 0xc) goto LAB_00418ba6;
                local_38c = 0;
                local_388 = 0;
                FUN_00419450(*(undefined4 *)(iVar14 + 0x1c),&local_38c,&local_388);
                *(undefined1 *)((int)&local_364 + iVar10 * 4 + 1) = (undefined1)local_38c;
                *(undefined1 *)(&local_364 + iVar10) = 3;
                uVar2 = (undefined1)local_388;
              }
              *(undefined1 *)((int)&local_364 + iVar10 * 4 + 2) = uVar2;
            }
          }
        }
LAB_00418ba6:
        uVar15 = local_380;
        pvVar11 = (void *)local_370;
        this = local_384;
      }
      local_390 = local_390 + 1;
      bVar12 = uVar15 < local_390;
      bVar13 = uVar15 == local_390;
    } while (!bVar13 && (int)local_390 <= (int)uVar15);
  }
  uVar15 = 0;
  if (local_380 != 0) {
    if (local_380 == 0) {
LAB_00418dd8:
                    /* WARNING: Subroutine does not return */
      std::_Xout_of_range("invalid vector<T> subscript");
    }
    do {
      pvVar1 = *(void **)((int)pvVar11 + uVar15 * 4);
      if (pvVar1 != (void *)0x0) {
        puVar9 = (undefined4 *)(*(int *)((int)pvVar1 + 0x28) + -0x10);
        LOCK();
        piVar4 = (int *)(*(int *)((int)pvVar1 + 0x28) + -4);
        iVar14 = *piVar4;
        *piVar4 = *piVar4 + -1;
        UNLOCK();
        if (iVar14 + -1 < 1) {
          (**(code **)(*(int *)*puVar9 + 4))(puVar9);
        }
        puVar9 = (undefined4 *)(*(int *)((int)pvVar1 + 0x14) + -0x10);
        LOCK();
        piVar4 = (int *)(*(int *)((int)pvVar1 + 0x14) + -4);
        iVar14 = *piVar4;
        *piVar4 = *piVar4 + -1;
        UNLOCK();
        if (iVar14 == 1 || iVar14 + -1 < 0) {
          (**(code **)(*(int *)*puVar9 + 4))(puVar9);
        }
        FUN_004644e6(pvVar1);
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < local_380);
  }
  local_370 = CONCAT44(pvVar11,(void *)local_370);
  local_126 = 0x55aa;
  iVar14 = *(int *)ThreadLocalStoragePointer;
  if ((*(int *)(iVar14 + 4) < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
    local_8._0_1_ = 2;
    memset(&DAT_00595144,0,0x34);
    FUN_0044e680();
    _atexit(thunk_FUN_0044e780);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595178);
  }
  FUN_0044edb0(&DAT_00595144,&local_364,0x240,'\x01');
  memset(&local_58,0,0x41);
  local_58._0_2_ = 0x204;
  if ((*(int *)(iVar14 + 4) < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
    local_8._0_1_ = 3;
    memset(&DAT_00595144,0,0x34);
    FUN_0044e680();
    _atexit(thunk_FUN_0044e780);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595178);
  }
  FUN_0044edb0(&DAT_00595144,&local_58,0x41,'\x01');
  local_58._0_2_ = 0xf004;
  if ((*(int *)(iVar14 + 4) < DAT_00595178) && (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
    local_8._0_1_ = 4;
    memset(&DAT_00595144,0,0x34);
    FUN_0044e680();
    _atexit(thunk_FUN_0044e780);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00464661(&DAT_00595178);
  }
  FUN_0044edb0(&DAT_00595144,&local_58,0x41,'\x01');
  if (pvVar11 != (void *)0x0) {
    FUN_00405190(pvVar11,local_368 - (int)pvVar11 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


