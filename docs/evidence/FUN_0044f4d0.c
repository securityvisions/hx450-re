

void __thiscall FUN_0044f4d0(void *this,undefined4 *param_1,uint param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  if (*(int *)this == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)((int)this + 4) = 1;
  puVar2 = (undefined4 *)FUN_0044fe10((int)this);
  if (puVar2 == (undefined4 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  cVar5 = '\0';
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      pcVar1 = (char *)((int)param_1 + uVar4);
      uVar4 = uVar4 + 1;
      cVar5 = cVar5 + *pcVar1;
    } while (uVar4 < param_2);
  }
  *(char *)(param_1 + 8) = cVar5;
  local_4c = *param_1;
  uStack_48 = param_1[1];
  uStack_44 = param_1[2];
  uStack_40 = param_1[3];
  local_c = *(undefined1 *)(param_1 + 0x10);
  local_3c = param_1[4];
  uStack_38 = param_1[5];
  uStack_34 = param_1[6];
  uStack_30 = param_1[7];
  local_2c = param_1[8];
  uStack_28 = param_1[9];
  uStack_24 = param_1[10];
  uStack_20 = param_1[0xb];
  local_1c = param_1[0xc];
  uStack_18 = param_1[0xd];
  uStack_14 = param_1[0xe];
  uStack_10 = param_1[0xf];
  iVar3 = FUN_00451100(puVar2,&local_4c,0x21);
  if (iVar3 < 1) {
    Sleep(10);
    local_4c = *param_1;
    uStack_48 = param_1[1];
    uStack_44 = param_1[2];
    uStack_40 = param_1[3];
    local_c = *(undefined1 *)(param_1 + 0x10);
    local_3c = param_1[4];
    uStack_38 = param_1[5];
    uStack_34 = param_1[6];
    uStack_30 = param_1[7];
    local_2c = param_1[8];
    uStack_28 = param_1[9];
    uStack_24 = param_1[10];
    uStack_20 = param_1[0xb];
    local_1c = param_1[0xc];
    uStack_18 = param_1[0xd];
    uStack_14 = param_1[0xe];
    uStack_10 = param_1[0xf];
    iVar3 = FUN_00451100(puVar2,&local_4c,0x21);
    if (iVar3 < 1) goto LAB_0044f62e;
  }
  Sleep(5);
  iVar3 = 0;
  do {
    local_4c = *param_1;
    uStack_48 = param_1[1];
    uStack_44 = param_1[2];
    uStack_40 = param_1[3];
    local_c = *(undefined1 *)(param_1 + 0x10);
    local_3c = param_1[4];
    uStack_38 = param_1[5];
    uStack_34 = param_1[6];
    uStack_30 = param_1[7];
    local_2c = param_1[8];
    uStack_28 = param_1[9];
    uStack_24 = param_1[10];
    uStack_20 = param_1[0xb];
    local_1c = param_1[0xc];
    uStack_18 = param_1[0xd];
    uStack_14 = param_1[0xe];
    uStack_10 = param_1[0xf];
    FUN_004511e0(puVar2,&local_4c,0x21,5);
    if (((*(char *)((int)param_1 + 1) == (char)local_4c) &&
        (*(char *)((int)param_1 + 2) == local_4c._1_1_)) &&
       (*(char *)((int)param_1 + 3) == local_4c._2_1_)) {
      *param_1 = local_4c;
      param_1[1] = uStack_48;
      param_1[2] = uStack_44;
      param_1[3] = uStack_40;
      param_1[4] = local_3c;
      param_1[5] = uStack_38;
      param_1[6] = uStack_34;
      param_1[7] = uStack_30;
      *(undefined1 *)(param_1 + 8) = (undefined1)local_2c;
      break;
    }
    iVar3 = iVar3 + 1;
    Sleep(10);
  } while (iVar3 < 0x14);
LAB_0044f62e:
  *(undefined4 *)((int)this + 4) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


