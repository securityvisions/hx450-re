

/* WARNING: Removing unreachable block (ram,0x00432ac6) */
/* WARNING: Removing unreachable block (ram,0x004329b7) */
/* WARNING: Removing unreachable block (ram,0x004329c2) */
/* WARNING: Removing unreachable block (ram,0x004329cc) */
/* WARNING: Removing unreachable block (ram,0x004329dd) */
/* WARNING: Removing unreachable block (ram,0x004329e0) */
/* WARNING: Removing unreachable block (ram,0x004329ea) */
/* WARNING: Removing unreachable block (ram,0x004329e5) */
/* WARNING: Removing unreachable block (ram,0x004329ee) */
/* WARNING: Removing unreachable block (ram,0x004329f4) */
/* WARNING: Removing unreachable block (ram,0x004329fa) */
/* WARNING: Removing unreachable block (ram,0x004329fe) */
/* WARNING: Removing unreachable block (ram,0x00432a06) */
/* WARNING: Removing unreachable block (ram,0x00432a08) */
/* WARNING: Removing unreachable block (ram,0x00432a17) */
/* WARNING: Removing unreachable block (ram,0x00432a3f) */
/* WARNING: Removing unreachable block (ram,0x00432a45) */
/* WARNING: Removing unreachable block (ram,0x00432a20) */
/* WARNING: Removing unreachable block (ram,0x00432a4d) */
/* WARNING: Removing unreachable block (ram,0x00432a53) */
/* WARNING: Removing unreachable block (ram,0x004329a3) */
/* WARNING: Removing unreachable block (ram,0x00432a73) */

void __fastcall FUN_004328c0(int param_1)

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
  puStack_c = &LAB_005528cb;
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
    MUI::KeyboardCtrl::GetKeyItems(*(KeyboardCtrl **)(param_1 + 0x60c));
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


