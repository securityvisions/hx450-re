

void __fastcall FUN_0044e910(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  uint local_8;
  
  pcVar6 = CancelIo_exref;
  if (*param_1 != 0) {
    *param_1 = 0;
    uVar4 = param_1[3] - param_1[2] >> 2;
    local_8 = 0;
    if (uVar4 != 0) {
      do {
        if ((uint)(param_1[3] - param_1[2] >> 2) <= local_8) {
                    /* WARNING: Subroutine does not return */
          std::_Xout_of_range("invalid vector<T> subscript");
        }
        pvVar3 = *(void **)(param_1[2] + local_8 * 4);
        if (pvVar3 != (void *)0x0) {
          puVar5 = *(undefined4 **)((int)pvVar3 + 0x414);
          if (puVar5 != (undefined4 *)0x0) {
            (*pcVar6)(*puVar5);
            CloseHandle((HANDLE)puVar5[0xd]);
            CloseHandle((HANDLE)*puVar5);
            LocalFree((HLOCAL)puVar5[5]);
            free((void *)puVar5[8]);
            free(puVar5);
          }
          puVar5 = (undefined4 *)(*(int *)((int)pvVar3 + 0x410) + -0x10);
          LOCK();
          piVar1 = (int *)(*(int *)((int)pvVar3 + 0x410) + -4);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 + -1 < 1) {
            (**(code **)(*(int *)*puVar5 + 4))(puVar5);
          }
          puVar5 = (undefined4 *)(*(int *)((int)pvVar3 + 0x40c) + -0x10);
          LOCK();
          piVar1 = (int *)(*(int *)((int)pvVar3 + 0x40c) + -4);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 + -1 < 1) {
            (**(code **)(*(int *)*puVar5 + 4))(puVar5);
          }
          puVar5 = (undefined4 *)(*(int *)((int)pvVar3 + 0x408) + -0x10);
          LOCK();
          piVar1 = (int *)(*(int *)((int)pvVar3 + 0x408) + -4);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1 || iVar2 + -1 < 0) {
            (**(code **)(*(int *)*puVar5 + 4))(puVar5);
          }
          FUN_004644e6(pvVar3);
          pcVar6 = CancelIo_exref;
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar4);
    }
    puVar5 = (undefined4 *)param_1[10];
    if (puVar5 != (undefined4 *)0x0) {
      (*pcVar6)(*puVar5);
      CloseHandle((HANDLE)puVar5[0xd]);
      CloseHandle((HANDLE)*puVar5);
      LocalFree((HLOCAL)puVar5[5]);
      free((void *)puVar5[8]);
      free(puVar5);
      param_1[10] = 0;
    }
    puVar5 = (undefined4 *)param_1[0xb];
    if (puVar5 != (undefined4 *)0x0) {
      CancelIo((HANDLE)*puVar5);
      CloseHandle((HANDLE)puVar5[0xd]);
      CloseHandle((HANDLE)*puVar5);
      LocalFree((HLOCAL)puVar5[5]);
      free((void *)puVar5[8]);
      free(puVar5);
      param_1[0xb] = 0;
    }
    param_1[3] = param_1[2];
  }
  return;
}


