

void __fastcall FUN_004511e0(undefined4 *param_1,void *param_2,uint param_3,DWORD param_4)

{
  HANDLE hEvent;
  char *_Src;
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_c;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  local_c = 0;
  hEvent = (HANDLE)param_1[0xd];
  if (param_1[7] == 0) {
    param_1[7] = 1;
    memset((void *)param_1[8],0,param_1[3]);
    ResetEvent(hEvent);
    BVar1 = ReadFile((HANDLE)*param_1,(LPVOID)param_1[8],param_1[3],&local_c,
                     (LPOVERLAPPED)(param_1 + 9));
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if (DVar2 != 0x3e5) {
        CancelIo((HANDLE)*param_1);
        param_1[7] = 0;
        goto LAB_0045125b;
      }
    }
  }
  if (-1 < (int)param_4) {
    DVar2 = WaitForSingleObject(hEvent,param_4);
    if (DVar2 != 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  BVar1 = GetOverlappedResult((HANDLE)*param_1,(LPOVERLAPPED)(param_1 + 9),&local_c,1);
  param_1[7] = 0;
  if (BVar1 != 0) {
    if (local_c != 0) {
      _Src = (char *)param_1[8];
      if (*_Src == '\0') {
        local_c = local_c - 1;
        if (local_c < param_3) {
          param_3 = local_c;
        }
        memcpy(param_2,_Src + 1,param_3);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      if (local_c < param_3) {
        param_3 = local_c;
      }
      memcpy(param_2,_Src,param_3);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0045125b:
  FUN_00450950((int)param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


