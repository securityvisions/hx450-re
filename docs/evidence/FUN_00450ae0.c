

void FUN_00450ae0(void)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  HDEVINFO DeviceInfoSet;
  undefined4 *puVar5;
  BOOL BVar6;
  char *pcVar7;
  uint uVar8;
  HANDLE hObject;
  int *piVar9;
  wchar_t *pwVar10;
  long lVar11;
  byte *pbVar12;
  int unaff_ESI;
  DWORD MemberIndex;
  code *pcVar13;
  bool bVar14;
  HANDLE apvStack_5e8 [2];
  HDEVINFO local_5e0;
  int *local_5dc;
  HANDLE local_5d8;
  int *local_5d4;
  DWORD local_5d0;
  undefined4 local_5cc;
  undefined4 local_5c8 [2];
  char *pcStack_5c0;
  GUID local_5bc;
  undefined4 local_5ac;
  undefined2 uStack_5a8;
  undefined2 uStack_5a6;
  undefined2 uStack_5a4;
  _SP_DEVINFO_DATA local_5a0;
  _SP_DEVICE_INTERFACE_DATA local_57c [3];
  byte local_520 [240];
  undefined1 auStack_430 [8];
  undefined1 auStack_428 [8];
  wchar_t awStack_420 [511];
  undefined2 uStack_22;
  uint local_14;
  
  local_14 = DAT_0058400c ^ (uint)apvStack_5e8;
  local_5bc.Data1 = 0x4d1e55b2;
  local_5cc = 0;
  local_5d4 = (int *)0x0;
  local_5bc.Data2 = 0xf16f;
  local_5bc.Data3 = 0x11cf;
  local_5bc.Data4[0] = 0x88;
  local_5bc.Data4[1] = 0xcb;
  local_5bc.Data4[2] = '\0';
  local_5bc.Data4[3] = '\x11';
  local_5bc.Data4[4] = '\x11';
  local_5bc.Data4[5] = '\0';
  local_5bc.Data4[6] = '\0';
  local_5bc.Data4[7] = '0';
  local_5d0 = 0;
  if (DAT_0059470c == '\0') {
    iVar4 = FUN_004509d0();
    if (iVar4 < 0) {
      if (DAT_00594710 != (HMODULE)0x0) {
        FreeLibrary(DAT_00594710);
      }
      DAT_00594710 = (HMODULE)0x0;
      DAT_0059470c = '\0';
      __security_check_cookie(local_14 ^ (uint)apvStack_5e8);
      return;
    }
    DAT_0059470c = '\x01';
  }
  local_5a0.Reserved = 0;
  local_5a0.ClassGuid.Data1 = 0;
  local_5a0.ClassGuid.Data2 = 0;
  local_5a0.ClassGuid.Data3 = 0;
  local_5a0.ClassGuid.Data4[0] = '\0';
  local_5a0.ClassGuid.Data4[1] = '\0';
  local_5a0.ClassGuid.Data4[2] = '\0';
  local_5a0.ClassGuid.Data4[3] = '\0';
  local_5a0.ClassGuid.Data4[4] = '\0';
  local_5a0.ClassGuid.Data4[5] = '\0';
  local_5a0.ClassGuid.Data4[6] = '\0';
  local_5a0.ClassGuid.Data4[7] = '\0';
  local_5a0.DevInst = 0;
  local_5a0.cbSize = 0x1c;
  local_57c[0].cbSize = 0x1c;
  DeviceInfoSet = SetupDiGetClassDevsA(&local_5bc,(PCSTR)0x0,(HWND)0x0,0x12);
  local_5c8[0] = 0;
  local_5e0 = DeviceInfoSet;
  iVar4 = SetupDiEnumDeviceInterfaces(DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,&local_5bc,0,local_57c);
  pcVar13 = SetupDiGetDeviceInterfaceDetailA_exref;
  do {
    if (iVar4 == 0) {
      SetupDiDestroyDeviceInfoList(DeviceInfoSet);
      __security_check_cookie(local_14 ^ (uint)apvStack_5e8);
      return;
    }
    (*pcVar13)(DeviceInfoSet,local_57c,0,0,local_5c8,0);
    puVar5 = malloc((size_t)local_5e0);
    *puVar5 = 5;
    iVar4 = (*pcVar13)(DeviceInfoSet,local_5a0.ClassGuid.Data4,puVar5,local_5e0,0,0);
    if (iVar4 != 0) {
      MemberIndex = 0;
      BVar6 = SetupDiEnumDeviceInfo(DeviceInfoSet,0,&local_5a0);
      pcVar13 = SetupDiGetDeviceInterfaceDetailA_exref;
      if (BVar6 != 0) {
LAB_00450c40:
        BVar6 = SetupDiGetDeviceRegistryPropertyA
                          (DeviceInfoSet,&local_5a0,7,(PDWORD)0x0,local_520,0x100,(PDWORD)0x0);
        pcVar13 = SetupDiGetDeviceInterfaceDetailA_exref;
        if (BVar6 != 0) {
          pcVar7 = "HIDClass";
          pbVar12 = local_520;
          do {
            bVar1 = *pbVar12;
            bVar14 = bVar1 < (byte)*pcVar7;
            if (bVar1 != *pcVar7) {
LAB_00450c93:
              uVar8 = -(uint)bVar14 | 1;
              goto LAB_00450c98;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar12[1];
            bVar14 = bVar1 < (byte)pcVar7[1];
            if (bVar1 != pcVar7[1]) goto LAB_00450c93;
            pbVar12 = pbVar12 + 2;
            pcVar7 = pcVar7 + 2;
          } while (bVar1 != 0);
          uVar8 = 0;
LAB_00450c98:
          if ((uVar8 != 0) ||
             (BVar6 = SetupDiGetDeviceRegistryPropertyA
                                (DeviceInfoSet,&local_5a0,9,(PDWORD)0x0,local_520,0x100,(PDWORD)0x0)
             , BVar6 == 0)) break;
          hObject = CreateFileA((LPCSTR)(local_5dc + 1),0,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000000,
                                (HANDLE)0x0);
          local_5d8 = hObject;
          if (hObject != (HANDLE)0xffffffff) {
            local_5ac = 0xc;
            (*DAT_005950b4)(hObject,&local_5ac);
            local_5cc = 0;
            memset(auStack_428,0,0x400);
            piVar9 = calloc(1,0x24);
            piVar2 = piVar9;
            if (local_5dc != (int *)0x0) {
              local_5dc[8] = (int)piVar9;
              piVar2 = local_5d4;
            }
            local_5d4 = piVar2;
            local_5dc = piVar9;
            cVar3 = (*DAT_005950a8)(hObject,&local_5cc);
            if (cVar3 != '\0') {
              iVar4 = (*DAT_005950ac)(local_5d4,local_57c[0].InterfaceClassGuid.Data4);
              if (iVar4 == 0x110000) {
                *(undefined2 *)(piVar9 + 6) = local_57c[0].InterfaceClassGuid.Data1._2_2_;
                *(undefined2 *)((int)piVar9 + 0x1a) =
                     (undefined2)local_57c[0].InterfaceClassGuid.Data1;
              }
              (*DAT_005950a4)(local_5dc);
            }
            piVar9[8] = 0;
            pcVar7 = (char *)(unaff_ESI + 4);
            if (pcVar7 == (char *)0x0) {
              *piVar9 = 0;
            }
            else {
              do {
                cVar3 = *pcVar7;
                pcVar7 = pcVar7 + 1;
              } while (cVar3 != '\0');
              uVar8 = (int)pcVar7 - (unaff_ESI + 5);
              pcVar7 = calloc(-(uint)(0xfffffffe < uVar8) | uVar8 + 1,1);
              *piVar9 = (int)pcVar7;
              strncpy(pcVar7,(char *)(unaff_ESI + 4),uVar8 + 1);
              *(undefined1 *)(uVar8 + *piVar9) = 0;
              hObject = apvStack_5e8[0];
            }
            cVar3 = (*DAT_005950b8)(hObject,auStack_430,0x400);
            uStack_22 = 0;
            if (cVar3 != '\0') {
              pwVar10 = _wcsdup(awStack_420);
              piVar9[5] = (int)pwVar10;
            }
            *(undefined2 *)(piVar9 + 1) = uStack_5a8;
            *(undefined2 *)((int)piVar9 + 6) = uStack_5a6;
            *(undefined2 *)(piVar9 + 3) = uStack_5a4;
            piVar9[7] = -1;
            DeviceInfoSet = local_5e0;
            if (((char *)*piVar9 != (char *)0x0) &&
               (pcVar7 = strstr((char *)*piVar9,"&mi_"), DeviceInfoSet = local_5e0,
               pcVar7 != (char *)0x0)) {
              pcStack_5c0 = (char *)0x0;
              lVar11 = strtol(pcVar7 + 4,&pcStack_5c0,0x10);
              piVar9[7] = lVar11;
              hObject = local_5d8;
              DeviceInfoSet = local_5e0;
              if (pcStack_5c0 == pcVar7 + 4) {
                piVar9[7] = -1;
              }
            }
          }
          CloseHandle(hObject);
          pcVar13 = SetupDiGetDeviceInterfaceDetailA_exref;
        }
      }
    }
LAB_00450ebe:
    free(local_5dc);
    local_5c8[0] = 0;
    local_5d0 = local_5d0 + 1;
    iVar4 = SetupDiEnumDeviceInterfaces
                      (DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,&local_5bc,local_5d0,local_57c);
  } while( true );
  MemberIndex = MemberIndex + 1;
  BVar6 = SetupDiEnumDeviceInfo(DeviceInfoSet,MemberIndex,&local_5a0);
  pcVar13 = SetupDiGetDeviceInterfaceDetailA_exref;
  if (BVar6 == 0) goto LAB_00450ebe;
  goto LAB_00450c40;
}


