

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_0044f1b0(void *this,void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_100c;
  undefined1 local_100b [4099];
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  if (*(int *)this == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  puVar1 = *(undefined4 **)((int)this + 0x2c);
  *(undefined4 *)((int)this + 4) = 1;
  if (puVar1 == (undefined4 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  memset(&local_100c,0,0x1001);
  memcpy(local_100b,param_1,0x1000);
  iVar2 = FUN_00451100(puVar1,&local_100c,0x1001);
  if (0 < iVar2) {
    FUN_004511e0(puVar1,&local_100c,0x1001,300);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


