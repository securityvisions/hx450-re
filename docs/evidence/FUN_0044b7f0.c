

void __fastcall FUN_0044b7f0(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  undefined4 local_4c;
  undefined1 local_44;
  undefined1 local_43;
  undefined2 local_42;
  undefined2 local_3e;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  memset((void *)((int)&local_4c + 1),0,0x40);
  local_4c._0_2_ = 0x1804;
  puVar2 = &local_4c;
  cVar4 = '\x01';
  uVar3 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  cVar4 = '\x01';
  puVar2 = &local_4c;
  local_4c = CONCAT22(local_4c._2_2_,0x1304);
  uVar3 = 0x41;
  local_44 = 1;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  memset(&local_4c,0,0x41);
  local_43 = *(undefined1 *)(param_1 + 0x814);
  puVar2 = &local_4c;
  local_4c = 0x80;
  local_44 = 0;
  cVar4 = '\0';
  uVar3 = 0x41;
  local_42 = 0;
  local_3e = 0x55aa;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  memset(&local_4c,0,0x41);
  local_4c._0_2_ = 0x204;
  puVar2 = &local_4c;
  cVar4 = '\x01';
  uVar3 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  memset(&local_4c,0,0x41);
  local_4c = CONCAT22(local_4c._2_2_,0xf004);
  puVar2 = &local_4c;
  cVar4 = '\0';
  uVar3 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


