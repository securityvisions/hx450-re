

void __fastcall FUN_00423a80(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  char cVar5;
  _SYSTEMTIME local_64;
  undefined2 local_54;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4a;
  undefined2 local_16;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  memset((void *)((int)&local_54 + 1),0,0x40);
  local_54 = 0x1804;
  puVar3 = (undefined4 *)&local_54;
  cVar5 = '\x01';
  uVar4 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar3,uVar4,cVar5);
  memset(&local_54,0,0x41);
  local_54 = 0x2804;
  puVar3 = (undefined4 *)&local_54;
  local_4c = 1;
  cVar5 = '\x01';
  uVar4 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar3,uVar4,cVar5);
  GetLocalTime(&local_64);
  memset(&local_54,0,0x41);
  local_54 = local_54 & 0xff00;
  iVar2 = MUI::LCDViewList::GetCurSel(*(LCDViewList **)(param_1 + 0x6b0));
  local_52 = 0x5a;
  local_54 = CONCAT11((char)iVar2 + '\x01',(undefined1)local_54);
  local_50 = (undefined1)local_64.wMonth;
  local_4f = (undefined1)local_64.wDay;
  local_4e = (undefined1)local_64.wHour;
  local_4d = (undefined1)local_64.wMinute;
  local_4c = (undefined1)local_64.wSecond;
  cVar5 = '\x01';
  local_4a = (undefined1)local_64.wDayOfWeek;
  puVar3 = (undefined4 *)&local_54;
  uVar4 = 0x41;
  local_51 = (undefined1)((ulonglong)local_64.wYear % 2000);
  local_16 = 0x55aa;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar3,uVar4,cVar5);
  memset(&local_54,0,0x41);
  local_54 = 0x204;
  puVar3 = (undefined4 *)&local_54;
  cVar5 = '\x01';
  uVar4 = 0x41;
  puVar1 = FUN_00413510();
  FUN_0044edb0(puVar1,puVar3,uVar4,cVar5);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


