

/* WARNING: Removing unreachable block (ram,0x0042821e) */
/* WARNING: Removing unreachable block (ram,0x00428079) */
/* WARNING: Removing unreachable block (ram,0x0042808a) */
/* WARNING: Removing unreachable block (ram,0x00428099) */
/* WARNING: Removing unreachable block (ram,0x004280ac) */
/* WARNING: Removing unreachable block (ram,0x004280b0) */
/* WARNING: Removing unreachable block (ram,0x004280ba) */
/* WARNING: Removing unreachable block (ram,0x004280b5) */
/* WARNING: Removing unreachable block (ram,0x004280be) */
/* WARNING: Removing unreachable block (ram,0x004280c4) */
/* WARNING: Removing unreachable block (ram,0x004280c8) */
/* WARNING: Removing unreachable block (ram,0x004280d0) */
/* WARNING: Removing unreachable block (ram,0x004280d2) */
/* WARNING: Removing unreachable block (ram,0x004280e9) */
/* WARNING: Removing unreachable block (ram,0x00428172) */
/* WARNING: Removing unreachable block (ram,0x00428178) */
/* WARNING: Removing unreachable block (ram,0x00428183) */
/* WARNING: Removing unreachable block (ram,0x004280fe) */
/* WARNING: Removing unreachable block (ram,0x00428104) */
/* WARNING: Removing unreachable block (ram,0x00428164) */
/* WARNING: Removing unreachable block (ram,0x00428187) */
/* WARNING: Removing unreachable block (ram,0x00428199) */
/* WARNING: Removing unreachable block (ram,0x00428047) */
/* WARNING: Removing unreachable block (ram,0x004281cb) */

void __fastcall FUN_00427f60(int param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 local_2b0 [150];
  undefined2 local_58;
  undefined1 local_50;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00551e6b;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  memset((void *)((int)&local_58 + 1),0,0x40);
  local_50 = 3;
  local_58 = 0x2004;
  if (*(int *)(param_1 + 0x7ac) != 0) {
    local_50 = 8;
  }
  puVar3 = (undefined4 *)&local_58;
  uVar4 = 0x41;
  puVar2 = FUN_00413510();
  cVar1 = FUN_0044efa0(puVar2,puVar3,uVar4);
  if (cVar1 != '\0') {
    memset(local_2b0,0,600);
    MUI::CustomLightMode::GetKeyItems(*(CustomLightMode **)(param_1 + 0x4e8));
    local_8 = 0;
    puVar3 = local_2b0;
    if (*(int *)(param_1 + 0x7ac) == 0) {
      uVar4 = 0xc0;
    }
    else {
      uVar4 = 0x200;
    }
    puVar2 = FUN_00413510();
    cVar1 = FUN_0044efa0(puVar2,puVar3,uVar4);
    if (cVar1 != '\0') {
      memset(&local_58,0,0x41);
      local_58 = 0x204;
      puVar3 = (undefined4 *)&local_58;
      uVar4 = 0x41;
      puVar2 = FUN_00413510();
      FUN_0044efa0(puVar2,puVar3,uVar4);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


