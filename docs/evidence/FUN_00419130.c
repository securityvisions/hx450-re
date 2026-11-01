

void __thiscall FUN_00419130(void *this,int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_88 [6];
  int local_70;
  int local_5c;
  undefined4 local_58;
  undefined2 uStack_54;
  undefined1 local_52;
  undefined1 local_51;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005507bb;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)((int)this + 0x800);
  if (0 < *(int *)((int)this + 0x800)) {
    memset(&local_58,0,0x41);
    uVar2 = *(undefined1 *)piVar1;
    local_58._1_1_ = 3;
    local_58._2_1_ = 4;
    local_58._3_1_ = '\0';
    uStack_54 = 2;
    if (param_1 != 0) {
      local_58._1_1_ = 0xd;
    }
    local_51 = 0;
    local_52 = uVar2;
    if (*(int *)((int)this + 0x820) != 0) {
      piVar3 = FUN_0040c770((void *)((int)this + 0x81c),&local_5c,piVar1);
      local_58._3_1_ = *(char *)(*piVar3 + 0x14);
      local_52 = uVar2;
      if (local_58._3_1_ == '$') {
        local_52 = 0xaf;
      }
    }
    FUN_00405c40(local_88);
    local_8 = 0;
    puVar7 = local_88;
    iVar8 = *piVar1;
    local_70 = 0;
    iVar6 = *(int *)((int)this + 0x7fc);
    iVar5 = *(int *)((int)this + 0x7f8);
    puVar4 = FUN_0040f4c0();
    FUN_00405fd0(puVar4,iVar5,iVar6,iVar8,puVar7);
    if (local_70 != 0) {
      uStack_54 = 0;
      local_52 = 0;
      local_51 = 0;
      FUN_004181a0(this,(int)local_88,&uStack_54);
    }
    puVar7 = &local_58;
    uVar9 = 0x41;
    puVar4 = FUN_00413510();
    FUN_0044f4d0(puVar4,puVar7,uVar9);
    FUN_00405f60((int)local_88);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


