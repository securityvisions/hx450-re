

void __fastcall FUN_0044f950(void *param_1)

{
  char cVar1;
  short sVar2;
  LPCSTR pCVar3;
  undefined4 *puVar4;
  short *psVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  HMODULE pHVar9;
  undefined4 *_Memory;
  void *pvVar10;
  ushort *puVar11;
  ushort *extraout_ECX;
  ushort *extraout_ECX_00;
  ushort *extraout_ECX_01;
  ushort *extraout_ECX_02;
  int iVar12;
  ushort *extraout_ECX_03;
  ushort *extraout_ECX_04;
  ushort *extraout_ECX_05;
  short *psVar13;
  ushort *extraout_ECX_06;
  ushort *extraout_ECX_07;
  ushort *extraout_ECX_08;
  char *pcVar14;
  ushort *puVar15;
  ushort *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00554610;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar6 = (undefined4 *)FUN_00450ae0();
  puVar4 = puVar6;
  puVar11 = extraout_ECX;
joined_r0x0044f98c:
  do {
    if (puVar4 == (undefined4 *)0x0) {
      FUN_00450f20(puVar6);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    FUN_0040cbd0(&stack0xffffffc0,(short *)puVar4[5]);
    iVar7 = FUN_0044ff10(param_1,(uint)*(ushort *)(puVar4 + 1),(uint)*(ushort *)((int)puVar4 + 6),
                         puVar11);
    puVar11 = extraout_ECX_00;
    if (iVar7 != 0) {
      pCVar3 = (LPCSTR)*puVar4;
      piVar8 = (int *)FUN_00405ab0();
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405810(0x80004005);
      }
      iVar7 = (**(code **)(*piVar8 + 0xc))();
      iVar7 = iVar7 + 0x10;
      local_8 = 0;
      local_18 = iVar7;
      if ((pCVar3 == (LPCSTR)0x0) || (((uint)pCVar3 & 0xffff0000) != 0)) {
        FUN_0040cfc0(&local_18,pCVar3);
        iVar7 = local_18;
      }
      else {
        pHVar9 = FUN_0040e560((uint)pCVar3 & 0xffff);
        if (pHVar9 != (HMODULE)0x0) {
          FUN_0040d870(&local_18,pHVar9,(uint)pCVar3 & 0xffff);
          iVar7 = local_18;
        }
      }
      local_8 = 1;
      _Memory = (undefined4 *)FUN_00450f60((LPCSTR)*puVar4);
      if (_Memory == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)puVar4[8];
        local_8 = 0xffffffff;
        LOCK();
        piVar8 = (int *)(iVar7 + -4);
        iVar12 = *piVar8;
        *piVar8 = *piVar8 + -1;
        UNLOCK();
        puVar11 = extraout_ECX_01;
        if (iVar12 == 1 || iVar12 + -1 < 0) {
          (**(code **)(**(int **)(iVar7 + -0x10) + 4))();
          puVar11 = extraout_ECX_02;
        }
        goto joined_r0x0044f98c;
      }
      if (*(short *)(_Memory + 4) == 0x41) {
        pvVar10 = operator_new(0x428);
        puVar11 = (ushort *)FUN_0044fd70((int)pvVar10);
        *(int *)puVar11 = *(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 8) >> 2;
        puVar11[2] = *(ushort *)(puVar4 + 1);
        puVar11[3] = *(ushort *)((int)puVar4 + 6);
        *(undefined4 **)(puVar11 + 0x20a) = _Memory;
        local_1c = puVar11;
        FUN_004050e0(puVar11 + 0x204,&PTR_005699cc,0);
        psVar5 = (short *)puVar4[5];
        if (psVar5 == (short *)0x0) {
          iVar12 = 0;
        }
        else {
          psVar13 = psVar5;
          do {
            sVar2 = *psVar13;
            psVar13 = psVar13 + 1;
          } while (sVar2 != 0);
          iVar12 = (int)psVar13 - (int)(psVar5 + 1) >> 1;
        }
        FUN_004050e0(puVar11 + 0x206,psVar5,iVar12);
        FUN_004050e0(puVar11 + 0x208,&PTR_005699cc,0);
        *(uint *)(puVar11 + 0x20c) = (uint)*(ushort *)(puVar4 + 3);
        puVar15 = extraout_ECX_03;
        FUN_0040cbd0(&stack0xffffffc0,(short *)puVar4[5]);
        iVar12 = FUN_004501d0(param_1,(uint)*(ushort *)(puVar4 + 1),
                              (uint)*(ushort *)((int)puVar4 + 6),puVar15);
        *(int *)(puVar11 + 0x20e) = iVar12;
        puVar15 = extraout_ECX_04;
        FUN_0040cbd0(&stack0xffffffc0,(short *)puVar4[5]);
        iVar12 = FUN_00450070(param_1,(uint)puVar11[2],(uint)puVar11[3],puVar15);
        *(int *)(puVar11 + 0x210) = iVar12;
        puVar11[0x212] = 1;
        puVar11[0x213] = 0;
        if (iVar12 != 0) {
          puVar11[0x212] = 0;
          puVar11[0x213] = 0;
        }
        pcVar14 = (char *)*puVar4;
        puVar11 = puVar11 + 4;
        do {
          cVar1 = *pcVar14;
          pcVar14 = pcVar14 + 1;
          *(char *)puVar11 = cVar1;
          puVar11 = (ushort *)((int)puVar11 + 1);
        } while (cVar1 != '\0');
        FUN_00404510((int *)((int)param_1 + 8),&local_1c);
        puVar11 = extraout_ECX_05;
      }
      else if ((*(short *)(_Memory + 2) == 0x21) && (_Memory[3] == 0x21)) {
        pvVar10 = operator_new(0x428);
        local_1c = (ushort *)FUN_0044fd70((int)pvVar10);
        *(int *)local_1c = *(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 8) >> 2;
        local_1c[2] = *(ushort *)(puVar4 + 1);
        local_1c[3] = *(ushort *)((int)puVar4 + 6);
        *(undefined4 **)(local_1c + 0x20a) = _Memory;
        FUN_004050e0(local_1c + 0x204,&PTR_005699cc,0);
        psVar5 = (short *)puVar4[5];
        if (psVar5 == (short *)0x0) {
          iVar12 = 0;
        }
        else {
          psVar13 = psVar5;
          do {
            sVar2 = *psVar13;
            psVar13 = psVar13 + 1;
          } while (sVar2 != 0);
          iVar12 = (int)psVar13 - (int)(psVar5 + 1) >> 1;
        }
        FUN_004050e0(local_1c + 0x206,psVar5,iVar12);
        FUN_004050e0(local_1c + 0x208,&PTR_005699cc,0);
        *(uint *)(local_1c + 0x20c) = (uint)*(ushort *)(puVar4 + 3);
        puVar11 = local_1c;
        FUN_0040cbd0(&stack0xffffffc0,(short *)puVar4[5]);
        iVar12 = FUN_004501d0(param_1,(uint)*(ushort *)(puVar4 + 1),
                              (uint)*(ushort *)((int)puVar4 + 6),puVar11);
        *(int *)(local_1c + 0x20e) = iVar12;
        local_1c[0x210] = 2;
        local_1c[0x211] = 0;
        iVar12 = FUN_0044f670(_Memory);
        *(int *)(local_1c + 0x212) = iVar12;
        puVar11 = local_1c + 4;
        pcVar14 = (char *)*puVar4;
        do {
          cVar1 = *pcVar14;
          pcVar14 = pcVar14 + 1;
          *(char *)puVar11 = cVar1;
          puVar11 = (ushort *)((int)puVar11 + 1);
        } while (cVar1 != '\0');
        FUN_00404510((void *)((int)param_1 + 8),&local_1c);
        puVar11 = extraout_ECX_06;
      }
      else {
        puVar11 = (ushort *)0xffff;
        if ((*(short *)(puVar4 + 6) == -1) && (*(short *)((int)puVar4 + 0x1a) == 1)) {
          *(undefined4 **)((int)param_1 + 0x28) = _Memory;
        }
        else {
          puVar11 = (ushort *)0x1001;
          if (*(short *)(_Memory + 2) == 0x1001) {
            *(undefined4 **)((int)param_1 + 0x2c) = _Memory;
          }
          else {
            CancelIo((HANDLE)*_Memory);
            CloseHandle((HANDLE)_Memory[0xd]);
            CloseHandle((HANDLE)*_Memory);
            LocalFree((HLOCAL)_Memory[5]);
            free((void *)_Memory[8]);
            free(_Memory);
            puVar11 = extraout_ECX_07;
          }
        }
      }
      local_8 = 0xffffffff;
      LOCK();
      piVar8 = (int *)(iVar7 + -4);
      iVar12 = *piVar8;
      *piVar8 = *piVar8 + -1;
      UNLOCK();
      if (iVar12 == 1 || iVar12 + -1 < 0) {
        (**(code **)(**(int **)(iVar7 + -0x10) + 4))();
        puVar11 = extraout_ECX_08;
      }
    }
    puVar4 = (undefined4 *)puVar4[8];
  } while( true );
}


