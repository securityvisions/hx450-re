

undefined4 __thiscall FUN_004501d0(void *this,int param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  bool bVar11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00554648;
  local_10 = ExceptionList;
  uVar4 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uVar9 = 0;
  uVar3 = (*(int *)((int)this + 0x18) - *(int *)((int)this + 0x14)) / 0x14;
  if (uVar3 != 0) {
    iVar2 = *(int *)((int)this + 0x14);
    iVar8 = 0;
    do {
      if ((uint)((*(int *)((int)this + 0x18) - iVar2) / 0x14) <= uVar9) {
                    /* WARNING: Subroutine does not return */
        std::_Xout_of_range("invalid vector<T> subscript");
      }
      puVar5 = *(ushort **)(iVar8 + 8 + iVar2);
      if (*(int *)(puVar5 + -6) == 0) {
        if ((*(int *)(iVar8 + iVar2) == param_1) && (*(int *)(iVar8 + 4 + iVar2) == param_2)) {
LAB_00450273:
          uVar10 = *(undefined4 *)(iVar8 + 0xc + iVar2);
          goto LAB_004502ef;
        }
      }
      else if ((*(int *)(iVar8 + iVar2) == param_1) && (*(int *)(iVar8 + 4 + iVar2) == param_2)) {
        puVar7 = param_3;
        if (param_3 == (ushort *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_00405810(0x80004005);
        }
        do {
          uVar1 = *puVar5;
          bVar11 = uVar1 < *puVar7;
          if (uVar1 != *puVar7) {
LAB_004502b6:
            uVar6 = -(uint)bVar11 | 1;
            goto LAB_004502bb;
          }
          if (uVar1 == 0) break;
          uVar1 = puVar5[1];
          bVar11 = uVar1 < puVar7[1];
          if (uVar1 != puVar7[1]) goto LAB_004502b6;
          puVar5 = puVar5 + 2;
          puVar7 = puVar7 + 2;
        } while (uVar1 != 0);
        uVar6 = 0;
LAB_004502bb:
        if (uVar6 == 0) goto LAB_00450273;
      }
      uVar9 = uVar9 + 1;
      iVar8 = iVar8 + 0x14;
    } while (uVar9 < uVar3);
  }
  uVar10 = 0;
LAB_004502ef:
  local_8 = 0xffffffff;
  LOCK();
  puVar5 = param_3 + -2;
  iVar2 = *(int *)puVar5;
  *(int *)puVar5 = *(int *)puVar5 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(**(int **)(param_3 + -8) + 4))(param_3 + -8,uVar4);
  }
  ExceptionList = local_10;
  return uVar10;
}


