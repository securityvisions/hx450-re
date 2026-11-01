

void __fastcall FUN_0041f8f0(MWindow *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  if (param_1[0x774] == (MWindow)0x0) {
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x30c),0);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2dc),0);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e0),0);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e8),0);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2f0),0);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x30c),0);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x304),0);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x338),1);
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x308),0);
    MUI::MTabCtrl::SetSelectItem(*(MTabCtrl **)(param_1 + 0x30c),0);
    (**(code **)(**(int **)(param_1 + 0x2c4) + 0xa0))(L"home_bkg.png");
    MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2c8),1);
    (**(code **)(**(int **)(param_1 + 0x33c) + 0xa0))(*(undefined4 *)(param_1 + 0x7c4),1);
    MUI::CDeviceCtrl::SetDeviceStatus(*(CDeviceCtrl **)(param_1 + 0x33c),0);
  }
  else {
    if (*(int *)(param_1 + 0x7c0) == 0) {
      puVar3 = FUN_00413510();
      iVar2 = 0x65;
      *(undefined4 *)(puVar3 + 0x20) = 0x65;
      *(undefined4 *)(puVar3 + 0x24) = 0;
    }
    else {
      iVar2 = MUI::CDeviceList::GetSelectDevice(*(CDeviceList **)(param_1 + 0x340));
      puVar3 = FUN_00413510();
      *(int *)(puVar3 + 0x20) = iVar2;
      *(undefined4 *)(puVar3 + 0x24) = 0;
      FUN_004202b0();
    }
    FUN_0041ccf0(param_1,iVar2);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(*(int *)(param_1 + 0x340) + 0x1a0);
    puVar3 = FUN_00413510();
    uVar4 = FUN_0044eb90((int)puVar3);
    *(undefined4 *)(param_1 + 0x784) = uVar4;
    FUN_0041eef0((int)param_1);
    if ((*(int *)(param_1 + 0x784) != 1) && (*(int *)(param_1 + 0x784) != 2)) {
      param_1[0x775] = (MWindow)0x1;
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2c8),0);
      (**(code **)(**(int **)(param_1 + 0x2c4) + 0xa0))(L"main_bkg.png");
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x30c),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2dc),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e0),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e8),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2f0),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x338),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x308),1);
      MUI::MTabCtrl::SetSelectItem(*(MTabCtrl **)(param_1 + 0x30c),*(int *)(param_1 + 0x7f0));
      (**(code **)(**(int **)(param_1 + 0x33c) + 0xa0))(*(undefined4 *)(param_1 + 0x7c8),1);
      MUI::CDeviceCtrl::SetDeviceStatus(*(CDeviceCtrl **)(param_1 + 0x33c),1);
      MUI::MWindow::KillTimer(param_1,300);
      MUI::MWindow::SetTimer(param_1,300,3000,(_func_void_HWND___ptr_uint_uint_ulong *)0x0);
      FUN_00415830(param_1 + 0x764,(undefined4 *)&stack0xffffffe4);
      *(undefined4 *)(param_1 + 0x778) = 0;
      return;
    }
    if (param_1[0x775] == (MWindow)0x0) {
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x30c),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2dc),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e0),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e8),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2f0),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x30c),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x304),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x338),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x308),0);
      MUI::MTabCtrl::SetSelectItem(*(MTabCtrl **)(param_1 + 0x30c),0);
      (**(code **)(**(int **)(param_1 + 0x2c4) + 0xa0))(L"home_bkg.png");
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2c8),1);
      (**(code **)(**(int **)(param_1 + 0x33c) + 0xa0))(*(undefined4 *)(param_1 + 0x7c4),1);
      MUI::CDeviceCtrl::SetDeviceStatus(*(CDeviceCtrl **)(param_1 + 0x33c),0);
    }
    else {
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2c8),0);
      (**(code **)(**(int **)(param_1 + 0x2c4) + 0xa0))(L"main_bkg.png");
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x30c),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2dc),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e0),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2e8),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x2f0),1);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x338),0);
      MUI::MControl::SetVisible(*(MControl **)(param_1 + 0x308),1);
      *(undefined4 *)(param_1 + 0x7f0) = 1;
      MUI::MTabCtrl::SetSelectItem(*(MTabCtrl **)(param_1 + 0x30c),1);
      (**(code **)(**(int **)(param_1 + 0x33c) + 0xa0))(*(undefined4 *)(param_1 + 0x7c8),1);
      MUI::CDeviceCtrl::SetDeviceStatus(*(CDeviceCtrl **)(param_1 + 0x33c),1);
      MUI::MWindow::KillTimer(param_1,300);
      MUI::MWindow::SetTimer(param_1,300,3000,(_func_void_HWND___ptr_uint_uint_ulong *)0x0);
      puVar1 = *(undefined4 **)(param_1 + 0x764);
      iVar2 = FUN_00415950(puVar1,(undefined4 *)puVar1[1],(undefined4 *)&stack0xffffffe4);
      if (*(int *)(param_1 + 0x768) == 0x15555554) {
                    /* WARNING: Subroutine does not return */
        std::_Xlength_error("list<T> too long");
      }
      *(int *)(param_1 + 0x768) = *(int *)(param_1 + 0x768) + 1;
      puVar1[1] = iVar2;
      **(int **)(iVar2 + 4) = iVar2;
    }
    if (*(int *)(param_1 + 0x784) == 1) {
      FUN_004135b0((int)param_1);
      *(undefined4 *)(param_1 + 0x778) = 0;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x778) = 0;
  return;
}


