

void __fastcall FUN_00451100(undefined4 *param_1,void *param_2,DWORD param_3)

{
  void *_Dst;
  BOOL BVar1;
  DWORD DVar2;
  _OVERLAPPED local_20;
  DWORD local_c;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  local_20.hEvent = (HANDLE)0x0;
  local_20.Internal = 0;
  local_20.InternalHigh = 0;
  local_20.u.s.Offset = 0;
  local_20.u.s.OffsetHigh = 0;
  _Dst = param_2;
  if (param_3 < *(ushort *)(param_1 + 2)) {
    _Dst = malloc((uint)*(ushort *)(param_1 + 2));
    memcpy(_Dst,param_2,param_3);
    memset((void *)(param_3 + (int)_Dst),0,*(ushort *)(param_1 + 2) - param_3);
    param_3 = (DWORD)*(ushort *)(param_1 + 2);
  }
  BVar1 = WriteFile((HANDLE)*param_1,_Dst,param_3,(LPDWORD)0x0,&local_20);
  if ((BVar1 == 0) && (DVar2 = GetLastError(), DVar2 != 0x3e5)) {
    FUN_00450950((int)param_1);
    local_c = 0xffffffff;
  }
  else {
    BVar1 = GetOverlappedResult((HANDLE)*param_1,&local_20,&local_c,1);
    if (BVar1 == 0) {
      FUN_00450950((int)param_1);
      local_c = 0xffffffff;
    }
  }
  if (_Dst != param_2) {
    free(_Dst);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


