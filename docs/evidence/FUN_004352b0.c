

void __fastcall FUN_004352b0(MWindow *param_1)

{
  LPCWSTR pWVar1;
  MWindow *pMVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  HWND__ *pHVar6;
  BOOL BVar7;
  undefined4 *puVar8;
  LPCWSTR pWVar9;
  undefined4 uVar10;
  undefined1 *local_28;
  MWindow *local_24;
  int local_20;
  LPCWSTR local_1c;
  LPCWSTR local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00552c90;
  local_10 = ExceptionList;
  local_14 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 0;
  local_24 = param_1;
  FUN_0040c9e0(&local_20,(int *)(param_1 + 0x7d4),L"Keyboard-Software-Setup.zip");
  local_8 = 0;
  piVar4 = (int *)FUN_00405ab0();
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_00405810(0x80004005);
  }
  iVar5 = (**(code **)(*piVar4 + 0xc))();
  local_1c = (LPCWSTR)(iVar5 + 0x10);
  local_8._0_1_ = 1;
  FUN_0040b590((int *)&local_18);
  local_8._0_1_ = 2;
  FUN_00405650(&local_1c,0x56ea70);
  local_8._0_1_ = 1;
  LOCK();
  pWVar1 = local_18 + -2;
  iVar5 = *(int *)pWVar1;
  *(int *)pWVar1 = *(int *)pWVar1 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(local_18 + -8) + 4))();
  }
  FUN_0040b6c0((int *)local_1c);
  FUN_0040b590((int *)&local_18);
  local_8._0_1_ = 3;
  FUN_00405650(&local_1c,0x56e9a8);
  local_8._0_1_ = 1;
  LOCK();
  pWVar1 = local_18 + -2;
  iVar5 = *(int *)pWVar1;
  *(int *)pWVar1 = *(int *)pWVar1 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(local_18 + -8) + 4))();
  }
  pWVar1 = local_1c;
  uVar10 = 0x4353b7;
  DeleteFileW(local_1c);
  pHVar6 = MUI::MWindow::GetSafeHwnd(param_1);
  local_28 = &stack0xffffffbc;
  local_18 = (LPCWSTR)&stack0xffffffbc;
  piVar4 = FUN_00405020((int *)(pWVar1 + -8));
  pWVar9 = (LPCWSTR)(piVar4 + 4);
  local_18 = (LPCWSTR)&stack0xffffffb8;
  local_8._0_1_ = 4;
  piVar4 = FUN_00405020((int *)(local_20 + -0x10));
  local_8._0_1_ = 1;
  FUN_0045a3e0(local_24 + 0x52c00,(int)(piVar4 + 4),pWVar9,uVar10,pHVar6);
  BVar7 = PathFileExistsW(pWVar1);
  if (BVar7 != 0) {
    piVar4 = (int *)FUN_00405ab0();
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405810(0x80004005);
    }
    iVar5 = (**(code **)(*piVar4 + 0xc))();
    local_18 = (LPCWSTR)(iVar5 + 0x10);
    local_8._0_1_ = 5;
    FUN_0040b590((int *)&local_24);
    local_8._0_1_ = 6;
    FUN_00405650(&local_18,0x56ea70);
    local_8 = CONCAT31(local_8._1_3_,5);
    LOCK();
    pMVar2 = local_24 + -4;
    iVar5 = *(int *)pMVar2;
    *(int *)pMVar2 = *(int *)pMVar2 + -1;
    UNLOCK();
    if (iVar5 == 1 || iVar5 + -1 < 0) {
      (**(code **)(**(int **)(local_24 + -0x10) + 4))();
    }
    cVar3 = FUN_004637a0(pWVar1,local_18);
    if (cVar3 != '\0') {
      DeleteFileW(pWVar1);
    }
    FUN_0040b590((int *)&local_28);
    local_8._0_1_ = 7;
    FUN_00405650(&local_18,0x56e9f0);
    local_8 = CONCAT31(local_8._1_3_,5);
    puVar8 = (undefined4 *)(local_28 + -0x10);
    LOCK();
    piVar4 = (int *)(local_28 + -4);
    iVar5 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar5 == 1 || iVar5 + -1 < 0) {
      (**(code **)(*(int *)*puVar8 + 4))();
    }
    ShellExecuteW((HWND)0x0,L"open",local_18,(LPCWSTR)0x0,(LPCWSTR)0x0,5);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  LOCK();
  pWVar9 = pWVar1 + -2;
  iVar5 = *(int *)pWVar9;
  *(int *)pWVar9 = *(int *)pWVar9 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(pWVar1 + -8) + 4))();
  }
  local_8 = 0xffffffff;
  LOCK();
  piVar4 = (int *)(local_20 + -4);
  iVar5 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(local_20 + -0x10) + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


