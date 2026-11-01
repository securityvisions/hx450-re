

void __fastcall FUN_00433fd0(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  undefined2 local_4c;
  undefined1 local_44;
  undefined2 local_3e;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  memset((void *)((int)&local_4c + 1),0,0x40);
  local_4c = 0x1804;
  puVar2 = (undefined4 *)&local_4c;
  cVar4 = '\x01';
  uVar3 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  cVar4 = '\x01';
  puVar2 = (undefined4 *)&local_4c;
  local_4c = 0x1304;
  uVar3 = 0x41;
  local_44 = 1;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  memset(&local_4c,0,0x41);
  local_4c = CONCAT11(local_4c._1_1_,*(undefined1 *)(param_1 + 0x808));
  puVar2 = (undefined4 *)&local_4c;
  local_3e = 0x55aa;
  cVar4 = '\0';
  uVar3 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  memset(&local_4c,0,0x41);
  local_4c = 0x204;
  puVar2 = (undefined4 *)&local_4c;
  cVar4 = '\x01';
  uVar3 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  memset(&local_4c,0,0x41);
  local_4c = 0xf004;
  puVar2 = (undefined4 *)&local_4c;
  cVar4 = '\0';
  uVar3 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar2,uVar3,cVar4);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


