

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004357d0(void *this,int param_1)

{
  char cVar1;
  DWORD DVar2;
  undefined *this_00;
  char *pcVar3;
  uint uVar4;
  char local_4c [4];
  undefined4 uStack_48;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0x784) == 2) {
    if ((*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_005951c0) &&
       (FUN_004646a0(&DAT_005951c0), DAT_005951c0 == -1)) {
      _DAT_005951c4 = GetTickCount();
      FUN_00464661(&DAT_005951c0);
    }
    if ((param_1 != 0) || (DVar2 = GetTickCount(), 14999 < DVar2 - _DAT_005951c4)) {
      _DAT_005951c4 = GetTickCount();
      memset(local_4c,0,0x41);
      local_4c[1] = ' ';
      local_4c[2] = '\x01';
      pcVar3 = local_4c;
      uVar4 = 0x41;
      this_00 = FUN_00413510();
      cVar1 = FUN_0044f4d0(this_00,(undefined4 *)pcVar3,uVar4);
      if ((cVar1 != '\0') && ((local_4c[0] == ' ' && (local_4c[3] != 0)))) {
        uVar4 = (uint)(byte)local_4c[3];
        if (100 < uVar4) {
          uVar4 = 100;
        }
        MUI::BatteryCtrl::SetBatteryInfo(*(BatteryCtrl **)((int)this + 0x304),uVar4,0);
        if (*(char *)((int)this + 0x775) == '\0') {
          *(undefined1 *)((int)this + 0x775) = 1;
          FUN_0041f8f0(this);
        }
      }
    }
  }
  uStack_48 = 0x4358ca;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


