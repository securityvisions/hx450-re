

void __fastcall FUN_0042afd0(int param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  undefined *puVar4;
  undefined4 extraout_ECX;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_8c [2];
  int local_84;
  undefined1 local_7c;
  undefined1 local_78;
  undefined1 local_74;
  undefined1 local_70;
  undefined4 local_68;
  undefined2 local_58;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined2 local_4a;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055212b;
  local_10 = ExceptionList;
  uVar3 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  FUN_00407e80(local_8c);
  puVar6 = local_8c;
  local_8 = 0;
  iVar7 = *(int *)(param_1 + 0x804);
  uVar5 = extraout_ECX;
  puVar4 = FUN_0040f4c0();
  cVar2 = FUN_00408520(puVar4,uVar5,iVar7,puVar6);
  if (cVar2 != '\0') {
    memset((void *)((int)&local_58 + 1),0,0x40);
    local_58 = 0x1804;
    puVar6 = (undefined4 *)&local_58;
    cVar2 = '\x01';
    uVar8 = 0x41;
    puVar4 = FUN_00413510();
    FUN_0044edb0(puVar4,puVar6,uVar8,cVar2);
    cVar2 = '\x01';
    puVar6 = (undefined4 *)&local_58;
    local_58 = 0x1304;
    uVar8 = 0x41;
    local_50 = 1;
    puVar4 = FUN_00413510();
    FUN_0044edb0(puVar4,puVar6,uVar8,cVar2);
    memset(&local_58,0,0x41);
    if (*(int *)(param_1 + 0x804) != 0) {
      local_56 = (undefined1)((uint)local_68 >> 8);
      local_50 = local_70;
      local_4f = local_7c;
      local_58._1_1_ = (undefined1)local_68;
      local_4e = local_78;
      local_55 = (undefined1)((uint)local_68 >> 0x10);
      local_4d = local_74;
    }
    local_58 = CONCAT11(local_58._1_1_,*(undefined1 *)(param_1 + 0x804));
    cVar2 = '\0';
    puVar6 = (undefined4 *)&local_58;
    local_4a = 0x55aa;
    uVar8 = 0x41;
    puVar4 = FUN_00413510();
    FUN_0044edb0(puVar4,puVar6,uVar8,cVar2);
    memset(&local_58,0,0x41);
    local_58 = 0x204;
    puVar6 = (undefined4 *)&local_58;
    cVar2 = '\x01';
    uVar8 = 0x41;
    puVar4 = FUN_00413510();
    FUN_0044edb0(puVar4,puVar6,uVar8,cVar2);
    memset(&local_58,0,0x41);
    local_58 = 0xf004;
    puVar6 = (undefined4 *)&local_58;
    cVar2 = '\0';
    uVar8 = 0x41;
    puVar4 = FUN_00413510();
    FUN_0044edb0(puVar4,puVar6,uVar8,cVar2);
  }
  local_8 = 0xffffffff;
  LOCK();
  piVar1 = (int *)(local_84 + -4);
  iVar7 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar7 == 1 || iVar7 + -1 < 0) {
    (**(code **)(**(int **)(local_84 + -0x10) + 4))((undefined4 *)(local_84 + -0x10),uVar3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


