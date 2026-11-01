

void __fastcall FUN_00434900(int param_1)

{
  undefined *this;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 local_4c;
  undefined1 local_48;
  undefined2 local_3a;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_1 + 0x784) == 0) {
    FUN_00433fd0(param_1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(int *)(param_1 + 0x784) == 2) {
    memset(&local_4c,0,0x41);
    local_48 = *(undefined1 *)(param_1 + 0x808);
    puVar1 = &local_4c;
    local_4c._1_2_ = 0x105;
    local_4c._3_1_ = 0;
    uVar2 = 0x41;
    local_3a = 0x55aa;
    this = FUN_00413510();
    FUN_0044f4d0(this,puVar1,uVar2);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


