

void __fastcall FUN_00434230(int param_1)

{
  HANDLE hHandle;
  HWND__ *hWnd;
  int *piVar1;
  undefined *this;
  MDialog *this_00;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_4c;
  uint local_8;
  
  local_8 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  if (*(DWORD *)(param_1 + 0x52560) != 0) {
    hHandle = OpenProcess(0x1fffff,0,*(DWORD *)(param_1 + 0x52560));
    if (hHandle != (HANDLE)0x0) {
      WaitForSingleObject(hHandle,0xffffffff);
    }
    FUN_004358d0((void *)(param_1 + -0x2ac),1);
    iVar4 = 5;
    hWnd = MUI::MWindow::GetSafeHwnd((MWindow *)(param_1 + -0x2ac));
    ShowWindow(hWnd,iVar4);
    piVar1 = (int *)FUN_00413510();
    piVar1[9] = 0;
    FUN_0044e910(piVar1);
    FUN_0044f950(piVar1);
    *piVar1 = 1;
    piVar1[1] = 0;
    *(undefined4 *)(param_1 + 0x52560) = 0;
  }
  if (*(int *)(param_1 + 0x4bc) == 0) {
    if (*(char *)(param_1 + 0x4c8) == '\0') goto LAB_004343fd;
    iVar4 = *(int *)(param_1 + 0x540);
    if (iVar4 == 3) {
      timeBeginPeriod(1);
      FUN_0042adb0(param_1 + -0x2ac);
    }
    else if (iVar4 == 6) {
      timeBeginPeriod(1);
      FUN_00427f60(param_1 + -0x2ac);
    }
    else {
      if ((iVar4 != 7) || (*(char *)(param_1 + 0x4c9) == '\0')) goto LAB_004346cf;
      timeBeginPeriod(1);
      FUN_004332c0((void *)(param_1 + -0x2ac));
    }
    timeEndPeriod(1);
LAB_004346cf:
    FUN_004357d0((void *)(param_1 + -0x2ac),0);
    FUN_00435160((MWindow *)(param_1 + -0x2ac));
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar4 = *(int *)(**(int **)(param_1 + 0x4b8) + 8);
  piVar1 = (int *)**(undefined4 **)(param_1 + 0x4b8);
  *(int *)piVar1[1] = *piVar1;
  *(int *)(*piVar1 + 4) = piVar1[1];
  *(int *)(param_1 + 0x4bc) = *(int *)(param_1 + 0x4bc) + -1;
  free(piVar1);
  if (iVar4 == 1) {
    FUN_00434700((MWindow *)(param_1 + -0x2ac));
  }
  else if (iVar4 == 2) {
    FUN_0041f650(param_1 + -0x2ac);
    FUN_0041f8f0((MWindow *)(param_1 + -0x2ac));
    FUN_004357d0((void *)(param_1 + -0x2ac),1);
  }
  else if (iVar4 == 3) {
    FUN_0041f650(param_1 + -0x2ac);
    FUN_0041f8f0((MWindow *)(param_1 + -0x2ac));
  }
  else if (iVar4 == 4) {
    FUN_0041f650(param_1 + -0x2ac);
    FUN_0041f8f0((MWindow *)(param_1 + -0x2ac));
    FUN_004357d0((void *)(param_1 + -0x2ac),1);
    FUN_00434750((void *)(param_1 + -0x2ac));
  }
  if ((*(char *)(param_1 + 0x4c8) == '\0') || (*(char *)(param_1 + 0x4c9) == '\0'))
  goto LAB_004343fd;
  if (iVar4 == 5) {
    FUN_00434750((void *)(param_1 + -0x2ac));
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (iVar4 == 6) {
    FUN_00434840((void *)(param_1 + -0x2ac));
  }
  else {
    if (iVar4 == 7) {
      FUN_004348a0((void *)(param_1 + -0x2ac));
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (iVar4 == 8) {
      if (*(int *)(param_1 + 0x4d8) == 0) {
        FUN_0042d5d0(param_1 + -0x2ac);
      }
      else if (*(int *)(param_1 + 0x4d8) == 2) {
        FUN_0042db50(param_1 + -0x2ac);
      }
    }
    else {
      if (iVar4 == 9) {
        if (*(int *)(param_1 + 0x4d8) == 0) {
          FUN_0042afd0(param_1 + -0x2ac);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        if (*(int *)(param_1 + 0x4d8) == 2) {
          FUN_0042b170(param_1 + -0x2ac);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        goto LAB_004343fd;
      }
      if (iVar4 == 10) {
        FUN_00434900(param_1 + -0x2ac);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      if (iVar4 != 0xb) {
        if (iVar4 == 0xc) {
          if (*(int *)(param_1 + 0x4d8) == 0) {
            FUN_004141a0(param_1 + -0x2ac);
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          if (*(int *)(param_1 + 0x4d8) == 2) {
            FUN_00414410(param_1 + -0x2ac);
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          goto LAB_004343fd;
        }
        if (iVar4 == 0xf) {
          *(undefined1 *)(param_1 + 0x52964) = 1;
          FUN_00434e80(param_1 + -0x2ac);
        }
        else {
          if (iVar4 == 0x10) {
            *(undefined1 *)(param_1 + 0x52964) = 1;
            if (*(int *)(param_1 + 0x4d8) == 0) {
              FUN_00422ac0(param_1 + -0x2ac);
              this_00 = *(MDialog **)(param_1 + 0x52988);
            }
            else {
              if (*(int *)(param_1 + 0x4d8) == 2) {
                FUN_00423360(param_1 + -0x2ac);
              }
              this_00 = *(MDialog **)(param_1 + 0x52988);
            }
            goto LAB_00434591;
          }
          if (iVar4 != 0x11) {
            if (iVar4 == 0x13) {
              FUN_00434ec0(param_1 + -0x2ac);
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
            if (iVar4 == 0xd) {
              memset(&local_4c,0,0x41);
              local_4c._1_1_ = 0x1f;
              puVar2 = &local_4c;
              uVar3 = 0x41;
              this = FUN_00413510();
              FUN_0044f4d0(this,puVar2,uVar3);
            }
            else {
              if (iVar4 != 0xe) {
                if (iVar4 == 0x14) {
                  FUN_004352b0((MWindow *)(param_1 + -0x2ac));
                  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                  return;
                }
                if (iVar4 == 0x15) {
                  FUN_00435540((MWindow *)(param_1 + -0x2ac));
                  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                  return;
                }
                goto LAB_004343fd;
              }
              FUN_00434ee0((void *)(param_1 + -0x2ac));
            }
            goto LAB_004343e4;
          }
          *(undefined1 *)(param_1 + 0x52964) = 1;
          FUN_004349a0((void *)(param_1 + -0x2ac));
        }
        this_00 = *(MDialog **)(param_1 + 0x52984);
LAB_00434591:
        if (this_00 != (MDialog *)0x0) {
          MUI::MDialog::DoOK(this_00);
        }
        *(undefined1 *)(param_1 + 0x52964) = 0;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      FUN_00434980(param_1 + -0x2ac);
    }
  }
LAB_004343e4:
  if (*(MDialog **)(param_1 + 0x5295c) != (MDialog *)0x0) {
    MUI::MDialog::DoOK(*(MDialog **)(param_1 + 0x5295c));
  }
  Sleep(100);
LAB_004343fd:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


