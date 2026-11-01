

void __fastcall FUN_00451320(undefined4 *param_1,undefined4 param_2)

{
  short sVar1;
  char cVar2;
  DWORD dwMessageId;
  short *psVar3;
  DWORD dwLanguageId;
  short **lpBuffer;
  DWORD nSize;
  va_list *Arguments;
  short *local_c;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  cVar2 = (*DAT_005950a0)(*param_1,param_2,0x41);
  if (cVar2 != '\0') {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  Arguments = (va_list *)0x0;
  nSize = 0;
  lpBuffer = &local_c;
  dwLanguageId = 0x400;
  dwMessageId = GetLastError();
  FormatMessageW(0x1300,(LPCVOID)0x0,dwMessageId,dwLanguageId,(LPWSTR)lpBuffer,nSize,Arguments);
  sVar1 = *local_c;
  psVar3 = local_c;
  do {
    if (sVar1 == 0) {
LAB_00451386:
      LocalFree((HLOCAL)param_1[5]);
      param_1[5] = local_c;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (*psVar3 == 0xd) {
      *psVar3 = 0;
      goto LAB_00451386;
    }
    psVar3 = psVar3 + 1;
    sVar1 = *psVar3;
  } while( true );
}


