

void __fastcall FUN_004513c0(undefined4 *param_1,LPVOID param_2,DWORD param_3)

{
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
  BVar1 = DeviceIoControl((HANDLE)*param_1,0xb0192,param_2,param_3,param_2,param_3,&local_c,
                          &local_20);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 != 0x3e5) goto LAB_0045140e;
  }
  BVar1 = GetOverlappedResult((HANDLE)*param_1,&local_20,&local_c,1);
  if (BVar1 != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0045140e:
  FUN_00450950((int)param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


