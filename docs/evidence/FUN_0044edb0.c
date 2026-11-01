

void __thiscall FUN_0044edb0(void *this,undefined4 *param_1,uint param_2,char param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_58;
  undefined1 local_4c;
  undefined4 local_4b;
  undefined4 uStack_47;
  undefined4 uStack_43;
  undefined4 uStack_3f;
  undefined4 local_3b;
  undefined4 uStack_37;
  undefined4 uStack_33;
  undefined4 uStack_2f;
  undefined4 local_2b;
  undefined4 uStack_27;
  undefined4 uStack_23;
  undefined4 uStack_1f;
  undefined4 local_1b;
  undefined4 uStack_17;
  undefined4 uStack_13;
  undefined4 uStack_f;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  if (*(int *)this == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)((int)this + 4) = 1;
  puVar1 = (undefined4 *)FUN_0044fe10((int)this);
  if (puVar1 == (undefined4 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (param_2 < 0x42) {
    Sleep(*(DWORD *)((int)this + 0x30));
    memset(&local_4c,0,0x41);
    local_4b = *param_1;
    uStack_47 = param_1[1];
    uStack_43 = param_1[2];
    uStack_3f = param_1[3];
    local_3b = param_1[4];
    uStack_37 = param_1[5];
    uStack_33 = param_1[6];
    uStack_2f = param_1[7];
    local_2b = param_1[8];
    uStack_27 = param_1[9];
    uStack_23 = param_1[10];
    uStack_1f = param_1[0xb];
    local_1b = param_1[0xc];
    uStack_17 = param_1[0xd];
    uStack_13 = param_1[0xe];
    uStack_f = param_1[0xf];
    iVar2 = FUN_00451320(puVar1,&local_4c);
    if ((0 < iVar2) && (param_3 != '\0')) {
      Sleep(*(DWORD *)((int)this + 0x30));
      local_4b = *param_1;
      uStack_47 = param_1[1];
      uStack_43 = param_1[2];
      uStack_3f = param_1[3];
      local_3b = param_1[4];
      uStack_37 = param_1[5];
      uStack_33 = param_1[6];
      uStack_2f = param_1[7];
      local_2b = param_1[8];
      uStack_27 = param_1[9];
      uStack_23 = param_1[10];
      uStack_1f = param_1[0xb];
      local_1b = param_1[0xc];
      uStack_17 = param_1[0xd];
      uStack_13 = param_1[0xe];
      uStack_f = param_1[0xf];
      FUN_004513c0(puVar1,&local_4c,param_2);
    }
  }
  else {
    Sleep(*(DWORD *)((int)this + 0x30));
    local_58 = 0;
    if (param_2 >> 6 != 0) {
      do {
        memset(&local_4c,0,0x41);
        local_4b = *param_1;
        uStack_47 = param_1[1];
        uStack_43 = param_1[2];
        uStack_3f = param_1[3];
        local_3b = param_1[4];
        uStack_37 = param_1[5];
        uStack_33 = param_1[6];
        uStack_2f = param_1[7];
        local_2b = param_1[8];
        uStack_27 = param_1[9];
        uStack_23 = param_1[10];
        uStack_1f = param_1[0xb];
        local_1b = param_1[0xc];
        uStack_17 = param_1[0xd];
        uStack_13 = param_1[0xe];
        uStack_f = param_1[0xf];
        iVar2 = FUN_00451320(puVar1,&local_4c);
        Sleep(*(DWORD *)((int)this + 0x30));
        if (iVar2 < 0) {
          iVar3 = 0;
          do {
            if (-1 < iVar2) goto LAB_0044ef5b;
            iVar3 = iVar3 + 1;
            Sleep(*(DWORD *)((int)this + 0x30));
            iVar2 = FUN_00451320(puVar1,&local_4c);
          } while (iVar3 < 10);
          if (iVar2 < 0) break;
        }
LAB_0044ef5b:
        local_58 = local_58 + 1;
        param_1 = param_1 + 0x10;
      } while (local_58 < (int)(param_2 >> 6));
    }
  }
  *(undefined4 *)((int)this + 4) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


