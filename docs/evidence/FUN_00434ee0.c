

void __fastcall FUN_00434ee0(void *param_1)

{
  LPCWSTR pWVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  LPCWSTR pWVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_60;
  LPCWSTR local_5c;
  undefined4 local_58;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00552c20;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(byte *)((int)param_1 + 0x7a4) & 2) != 0) {
    FUN_0042c720(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 1) != 0) {
    FUN_004170d0(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 4) != 0) {
    FUN_0042a580((int)param_1);
  }
  if ((*(uint *)((int)param_1 + 0x7a4) & 0x100) != 0) {
    FUN_00433e20((int)param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 0x10) != 0) {
    FUN_00449370(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 8) != 0) {
    FUN_004277d0(param_1);
  }
  if ((*(byte *)((int)param_1 + 0x7a4) & 0x20) != 0) {
    FUN_00432cd0(param_1);
  }
  if (((*(byte *)((int)param_1 + 0x7a4) & 0x80) != 0) && (*(char *)((int)param_1 + 0x527c0) != '\0')
     ) {
    piVar2 = (int *)FUN_00405ab0();
    if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    local_5c = (LPCWSTR)(iVar3 + 0x10);
    local_8 = 0;
    FUN_0040b590(&local_60);
    local_8._0_1_ = 1;
    FUN_00405650(&local_5c,0x56e950);
    local_8 = (uint)local_8._1_3_ << 8;
    LOCK();
    piVar2 = (int *)(local_60 + -4);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      (**(code **)(**(int **)(local_60 + -0x10) + 4))((undefined4 *)(local_60 + -0x10));
    }
    pWVar1 = local_5c;
    FUN_0040b8d0(local_5c);
    puVar4 = FUN_0040f4c0();
    FUN_00407cf0(puVar4);
    FUN_00420c90(param_1);
    local_8 = 0xffffffff;
    pWVar5 = pWVar1 + -8;
    LOCK();
    pWVar1 = pWVar1 + -2;
    iVar3 = *(int *)pWVar1;
    *(int *)pWVar1 = *(int *)pWVar1 + -1;
    UNLOCK();
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      (**(code **)(**(int **)pWVar5 + 4))(pWVar5);
    }
  }
  FUN_00413880((int)param_1);
  if (*(int *)((int)param_1 + 0x784) == 0) {
    if ((*(byte *)((int)param_1 + 0x7a4) & 2) != 0) {
      FUN_0042d5d0((int)param_1);
    }
    if ((*(byte *)((int)param_1 + 0x7a4) & 1) != 0) {
      FUN_00418550(param_1,0);
      if (*(int *)((int)param_1 + 0x7b0) != 0) {
        FUN_00418550(param_1,1);
      }
    }
    if ((*(byte *)((int)param_1 + 0x7a4) & 0x10) != 0) {
      if (*(int *)((int)param_1 + 0x784) == 0) {
        FUN_0044b900((int)param_1);
      }
      else if (*(int *)((int)param_1 + 0x784) == 2) {
        FUN_0044bd70((int)param_1);
      }
    }
    if ((*(byte *)((int)param_1 + 0x7a4) & 4) != 0) {
      FUN_0042afd0((int)param_1);
    }
    if ((*(uint *)((int)param_1 + 0x7a4) & 0x100) != 0) {
      FUN_00433fd0((int)param_1);
    }
    FUN_004141a0((int)param_1);
  }
  else if (*(int *)((int)param_1 + 0x784) == 2) {
    memset(&local_58,0,0x41);
    local_58._1_1_ = 0xf;
    puVar6 = &local_58;
    uVar7 = 0x41;
    puVar4 = FUN_00413510();
    FUN_0044f4d0(puVar4,puVar6,uVar7);
    if ((*(byte *)((int)param_1 + 0x7a4) & 4) != 0) {
      Sleep(0x32);
      FUN_0042afd0((int)param_1);
    }
    if ((*(uint *)((int)param_1 + 0x7a4) & 0x100) != 0) {
      Sleep(0x32);
      FUN_00433fd0((int)param_1);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


