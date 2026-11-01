

void __fastcall FUN_00450f60(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *_Memory;
  HANDLE pvVar3;
  void *pvVar4;
  undefined4 unaff_ESI;
  undefined1 auStack_58 [4];
  undefined4 local_54;
  undefined2 uStack_50;
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_0058400c ^ (uint)auStack_58;
  local_54 = 0;
  if (DAT_0059470c == '\0') {
    iVar2 = FUN_004509d0();
    if (iVar2 < 0) {
      if (DAT_00594710 != (HMODULE)0x0) {
        FreeLibrary(DAT_00594710);
      }
      DAT_00594710 = (HMODULE)0x0;
      DAT_0059470c = '\0';
      __security_check_cookie(local_c ^ (uint)auStack_58);
      return;
    }
    DAT_0059470c = '\x01';
  }
  _Memory = calloc(1,0x38);
  *_Memory = 0xffffffff;
  _Memory[1] = 1;
  *(undefined2 *)(_Memory + 2) = 0;
  _Memory[3] = 0;
  _Memory[5] = 0;
  _Memory[6] = 0;
  _Memory[7] = 0;
  _Memory[8] = 0;
  _Memory[9] = 0;
  _Memory[10] = 0;
  _Memory[0xb] = 0;
  _Memory[0xc] = 0;
  _Memory[0xd] = 0;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  _Memory[0xd] = pvVar3;
  pvVar3 = CreateFileA(param_1,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000000,(HANDLE)0x0);
  *_Memory = pvVar3;
  if (pvVar3 != (HANDLE)0xffffffff) {
    cVar1 = (*DAT_005950a8)(pvVar3);
    if (cVar1 != '\0') {
      iVar2 = (*DAT_005950ac)(local_54);
      if (iVar2 == 0x110000) {
        *(undefined2 *)(_Memory + 2) = local_54._2_2_;
        _Memory[3] = local_54 & 0xffff;
        *(undefined2 *)(_Memory + 4) = uStack_50;
        (*DAT_005950a4)(unaff_ESI);
        pvVar4 = malloc(_Memory[3]);
        _Memory[8] = pvVar4;
        __security_check_cookie(uStack_18 ^ (uint)&stack0xffffff9c);
        return;
      }
      FUN_00450950((int)_Memory);
      (*DAT_005950a4)(unaff_ESI);
      goto LAB_00451075;
    }
  }
  FUN_00450950((int)_Memory);
LAB_00451075:
  CloseHandle((HANDLE)_Memory[0xd]);
  CloseHandle((HANDLE)*_Memory);
  LocalFree((HLOCAL)_Memory[5]);
  free((void *)_Memory[8]);
  free(_Memory);
  __security_check_cookie(local_c ^ (uint)auStack_58);
  return;
}


