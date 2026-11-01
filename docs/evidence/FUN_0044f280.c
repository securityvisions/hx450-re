

void __thiscall FUN_0044f280(void *this,undefined4 *param_1,DWORD param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EDX;
  int iVar3;
  uint local_9c;
  undefined1 local_90;
  undefined4 local_8f;
  undefined4 uStack_8b;
  undefined4 uStack_87;
  undefined4 uStack_83;
  undefined4 local_7f;
  undefined4 uStack_7b;
  undefined4 uStack_77;
  undefined4 uStack_73;
  undefined4 local_6f;
  undefined4 uStack_6b;
  undefined4 uStack_67;
  undefined4 uStack_63;
  undefined4 local_5f;
  undefined4 uStack_5b;
  undefined4 uStack_57;
  undefined4 uStack_53;
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
  if ((*(int *)this == 0) || (*(int *)((int)this + 4) != 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)((int)this + 4) = 1;
  puVar1 = (undefined4 *)FUN_0044fe10((int)this);
  if (puVar1 == (undefined4 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  timeBeginPeriod(1);
  Sleep(3);
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
  if (0 < iVar2) {
    Sleep(5);
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
    iVar2 = FUN_004513c0(puVar1,&local_4c,param_2);
    if (iVar2 < 0) {
      iVar3 = 0;
      do {
        if (-1 < iVar2) break;
        local_4b = *param_1;
        uStack_47 = param_1[1];
        uStack_43 = param_1[2];
        uStack_3f = param_1[3];
        iVar3 = iVar3 + 1;
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
        iVar2 = FUN_004513c0(puVar1,&local_4c,0x41);
        Sleep(5);
      } while (iVar3 < 10);
      if (local_4b._3_1_ == '\x01') {
        local_9c = 0;
        while (Sleep(3), 0 < iVar2) {
          memset(&local_90,0,0x41);
          GetTickCount64();
          iVar2 = FUN_004513c0(puVar1,&local_90,0x41);
          GetTickCount64();
          if ((extraout_EDX != extraout_EAX_00 < extraout_EAX) ||
             (0x168 < extraout_EAX_00 - extraout_EAX)) break;
          *param_1 = local_8f;
          param_1[1] = uStack_8b;
          param_1[2] = uStack_87;
          param_1[3] = uStack_83;
          param_1[4] = local_7f;
          param_1[5] = uStack_7b;
          param_1[6] = uStack_77;
          param_1[7] = uStack_73;
          param_1[8] = local_6f;
          param_1[9] = uStack_6b;
          param_1[10] = uStack_67;
          param_1[0xb] = uStack_63;
          param_1[0xc] = local_5f;
          param_1[0xd] = uStack_5b;
          param_1[0xe] = uStack_57;
          param_1[0xf] = uStack_53;
          if (iVar2 != 0x40) break;
          param_1 = param_1 + 0x10;
          local_9c = local_9c + 1;
          iVar2 = 0x40;
          if (8 < local_9c) break;
        }
      }
    }
  }
  *(undefined4 *)((int)this + 4) = 0;
  timeEndPeriod(1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


