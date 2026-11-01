

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00435160(MWindow *param_1)

{
  DWORD DVar1;
  undefined *puVar2;
  undefined2 extraout_CX;
  char extraout_DL;
  undefined1 local_4c [2];
  byte bStack_4a;
  undefined4 uStack_48;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  if ((*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_005951b8) &&
     (FUN_004646a0(&DAT_005951b8), DAT_005951b8 == -1)) {
    _DAT_005951bc = GetTickCount();
    FUN_00464661(&DAT_005951b8);
  }
  DVar1 = GetTickCount();
  if (199 < DVar1 - _DAT_005951bc) {
    _DAT_005951bc = GetTickCount();
    memset(local_4c,0,0x41);
    puVar2 = FUN_00413510();
    if (*(undefined4 **)(puVar2 + 0x28) != (undefined4 *)0x0) {
      FUN_004511e0(*(undefined4 **)(puVar2 + 0x28),local_4c,0x41,10);
    }
    if ((char)_local_4c != '\0') {
      FUN_00452310();
      if ((char)extraout_CX == '\x05') {
        if ((char)((ushort)extraout_CX >> 8) == -0x5a) {
          if (bStack_4a == 0xff) {
            if (extraout_DL == '\x01') {
              param_1[0x775] = (MWindow)0x1;
              FUN_0041f8f0(param_1);
              uStack_48 = 0x43525d;
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
          }
          else if ((bStack_4a == 0xfe) && (extraout_DL == '\x02')) {
            param_1[0x775] = (MWindow)0x0;
            FUN_0041f8f0(param_1);
            uStack_48 = 0x435288;
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
        }
        FUN_00419270(param_1,(uint)bStack_4a);
      }
    }
  }
  uStack_48 = 0x4352a3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


