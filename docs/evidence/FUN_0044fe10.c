

int __fastcall FUN_0044fe10(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    uVar2 = 0;
    uVar5 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2;
    if (uVar5 != 0) {
      iVar1 = *(int *)(param_1 + 8);
      iVar4 = *(int *)(param_1 + 0xc) - iVar1;
      do {
        if ((uint)(iVar4 >> 2) <= uVar2) goto LAB_0044fee5;
        iVar3 = *(int *)(iVar1 + uVar2 * 4);
        if (iVar3 != 0) {
          if ((*(int *)(param_1 + 0x20) == *(int *)(iVar3 + 0x41c)) &&
             (*(int *)(iVar3 + 0x420) == 0)) goto LAB_0044fef0;
          iVar1 = *(int *)(param_1 + 8);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar5);
    }
    uVar2 = 0;
    if (uVar5 != 0) {
      iVar1 = *(int *)(param_1 + 8);
      iVar4 = *(int *)(param_1 + 0xc) - iVar1;
      do {
        if ((uint)(iVar4 >> 2) <= uVar2) goto LAB_0044fee5;
        iVar3 = *(int *)(iVar1 + uVar2 * 4);
        if (iVar3 != 0) {
          if ((*(int *)(param_1 + 0x20) == *(int *)(iVar3 + 0x41c)) &&
             (*(int *)(iVar3 + 0x420) == 1)) goto LAB_0044fef0;
          iVar1 = *(int *)(param_1 + 8);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar5);
    }
    uVar2 = 0;
    if (uVar5 != 0) {
      iVar1 = *(int *)(param_1 + 8);
      iVar4 = *(int *)(param_1 + 0xc) - iVar1;
      do {
        if ((uint)(iVar4 >> 2) <= uVar2) {
LAB_0044fee5:
                    /* WARNING: Subroutine does not return */
          std::_Xout_of_range("invalid vector<T> subscript");
        }
        iVar3 = *(int *)(iVar1 + uVar2 * 4);
        if (iVar3 != 0) {
          if ((*(int *)(param_1 + 0x20) == *(int *)(iVar3 + 0x41c)) &&
             (*(int *)(iVar3 + 0x420) == 2)) {
LAB_0044fef0:
            *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar3 + 0x414);
            return *(int *)(iVar3 + 0x414);
          }
          iVar1 = *(int *)(param_1 + 8);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar5);
    }
    iVar1 = 0;
  }
  return iVar1;
}


