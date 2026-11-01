

void __fastcall FUN_00423bb0(int param_1)

{
  int iVar1;
  undefined *this;
  undefined4 *puVar2;
  uint uVar3;
  _SYSTEMTIME local_64;
  undefined1 local_54 [5];
  char local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_46;
  undefined2 local_42;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  memset(local_54,0,0x41);
  local_54._1_4_ = 0x100c;
  GetLocalTime(&local_64);
  iVar1 = MUI::LCDViewList::GetCurSel(*(LCDViewList **)(param_1 + 0x6b0));
  local_4f = (char)iVar1 + '\x01';
  local_4e = 0x5a;
  local_4c = (undefined1)local_64.wMonth;
  local_4b = (undefined1)local_64.wDay;
  local_4a = (undefined1)local_64.wHour;
  local_49 = (undefined1)local_64.wMinute;
  local_48 = (undefined1)local_64.wSecond;
  local_46 = (undefined1)local_64.wDayOfWeek;
  puVar2 = (undefined4 *)local_54;
  uVar3 = 0x41;
  local_4d = (undefined1)((ulonglong)local_64.wYear % 2000);
  local_42 = 0x55aa;
  this = FUN_00413510();
  FUN_0044f4d0(this,puVar2,uVar3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


