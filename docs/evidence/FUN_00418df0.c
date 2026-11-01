

void __thiscall FUN_00418df0(void *this,int param_1)

{
  void *pvVar1;
  undefined *this_00;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  void *local_2ac;
  int local_2a8;
  undefined8 local_2a4;
  int local_29c;
  undefined4 local_298 [143];
  undefined2 local_5a;
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
  puStack_c = &LAB_00550787;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2ac = this;
  memset(local_298,0,0x240);
  local_2a4 = 0;
  local_29c = 0;
  piVar2 = (int *)&local_2a4;
  local_8 = 0;
  uVar5 = (uint)(param_1 != 0);
  iVar3 = *(int *)((int)this + 0x7f8);
  this_00 = FUN_0040f4c0();
  FUN_004061b0(this_00,iVar3,uVar5,piVar2);
  uVar5 = local_2a4._4_4_ - (int)(void *)local_2a4 >> 2;
  iVar3 = (int)(void *)local_2a4;
  if (0 < (int)uVar5) {
    uVar7 = 0;
    if (0 < (int)uVar5) {
      do {
        if (uVar5 <= uVar7) goto LAB_00419116;
        local_2a8 = *(int *)((int)(void *)local_2a4 + uVar7 * 4);
        if ((local_2a8 != 0) && (*(int *)(local_2a8 + 0x18) != 0)) {
          local_2b0 = 0;
          if (*(int *)((int)this + 0x820) != 0) {
            piVar2 = FUN_0040c770((void *)((int)this + 0x81c),&local_2b4,(int *)(local_2a8 + 0xc));
            local_2b0 = *(int *)(*piVar2 + 0x14);
          }
          if (((param_1 == 0) || (*(int *)((int)this + 0x830) == 0)) ||
             (iVar3 = *(int *)((int)this + 0x82c),
             piVar2 = FUN_0040c770((int *)((int)this + 0x82c),&local_2b8,(int *)(local_2a8 + 0xc)),
             this = local_2ac, *piVar2 == iVar3)) {
            FUN_004181a0(this,local_2a8,(undefined2 *)(local_298 + local_2b0));
          }
        }
        uVar7 = uVar7 + 1;
        iVar3 = (int)(void *)local_2a4;
      } while ((int)uVar7 < (int)uVar5);
    }
    uVar7 = 0;
    if (uVar5 != 0) {
      if (uVar5 == 0) {
LAB_00419116:
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      do {
        pvVar1 = *(void **)(iVar3 + uVar7 * 4);
        if (pvVar1 != (void *)0x0) {
          puVar4 = (undefined4 *)(*(int *)((int)pvVar1 + 0x28) + -0x10);
          LOCK();
          piVar2 = (int *)(*(int *)((int)pvVar1 + 0x28) + -4);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 + -1 < 1) {
            (**(code **)(*(int *)*puVar4 + 4))(puVar4);
          }
          puVar4 = (undefined4 *)(*(int *)((int)pvVar1 + 0x14) + -0x10);
          LOCK();
          piVar2 = (int *)(*(int *)((int)pvVar1 + 0x14) + -4);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1 || iVar3 + -1 < 0) {
            (**(code **)(*(int *)*puVar4 + 4))(puVar4);
          }
          FUN_004644e6(pvVar1);
          iVar3 = (int)(void *)local_2a4;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar5);
    }
    local_2a4 = CONCAT44(iVar3,(void *)local_2a4);
  }
  puVar4 = local_298;
  iVar6 = 0;
  local_5a = 0x55aa;
  local_2ac = (void *)(CONCAT31((int3)((uint)iVar3 >> 8),param_1 != 0) * 2 + 0x10);
  local_2a8 = *(int *)ThreadLocalStoragePointer;
  do {
    memset(&local_58,0,0x41);
    local_58._1_1_ = (char)local_2ac;
    local_58._3_1_ = (char)iVar6;
    local_58._2_1_ = 0x1c;
    if (iVar6 == 0x14) {
      local_58._2_1_ = 0x10;
    }
    local_54 = *puVar4;
    uStack_50 = puVar4[1];
    uStack_4c = puVar4[2];
    uStack_48 = puVar4[3];
    local_3c = puVar4[6];
    local_44 = *(undefined8 *)(puVar4 + 4);
    if ((*(int *)(local_2a8 + 4) < DAT_00595178) &&
       (FUN_004646a0(&DAT_00595178), DAT_00595178 == -1)) {
      local_8._0_1_ = 1;
      memset(&DAT_00595144,0,0x34);
      FUN_0044e680();
      _atexit(thunk_FUN_0044e780);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00464661(&DAT_00595178);
    }
    FUN_0044f4d0(&DAT_00595144,&local_58,0x41);
    puVar4 = puVar4 + 7;
    Sleep(2);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x15);
  if ((void *)local_2a4 != (void *)0x0) {
    FUN_00405190((void *)local_2a4,local_29c - (int)(void *)local_2a4 >> 2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


