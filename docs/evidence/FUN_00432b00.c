

void __thiscall FUN_00432b00(void *this,undefined1 (*param_1) [16])

{
  undefined1 auVar1 [16];
  uint uVar2;
  long lVar3;
  undefined4 local_58;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 auStack_50 [15];
  undefined4 local_41;
  undefined1 local_3d;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055290c;
  local_10 = ExceptionList;
  uVar2 = DAT_0058400c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  memset(&local_58,0,0x41);
  local_58._1_2_ = 0x1c0b;
  local_58._3_1_ = 0;
  lVar3 = MUI::MComboBox::GetCurData(*(MComboBox **)((int)this + 0x618));
  local_54 = (undefined1)lVar3;
  lVar3 = MUI::MComboBox::GetCurData(*(MComboBox **)((int)this + 0x630));
  local_53 = (undefined1)lVar3;
  auVar1 = *param_1;
  local_52 = (undefined1)*(undefined4 *)(*(int *)((int)this + 0x638) + 0x144);
  local_41 = *(undefined4 *)param_1[1];
  local_3d = param_1[1][4];
  local_51 = auVar1[0];
  auStack_50 = auVar1._1_15_;
  MUI::M_Trace(L"mxn: %02d %02d %02d %02d %02d %02d %02d %02d %02d %02d \n",auVar1._0_4_ & 0xff,
               auVar1._1_4_ & 0xff,auVar1._2_4_ & 0xff,auVar1._3_4_ & 0xff,auVar1._4_4_ & 0xff,
               auVar1._5_4_ & 0xff,auVar1._6_4_ & 0xff,auVar1._7_4_ & 0xff,auVar1._8_4_ & 0xff,
               auVar1._9_4_ & 0xff,uVar2);
  if (*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_00595178) {
    FUN_004646a0(&DAT_00595178);
    if (DAT_00595178 == -1) {
      local_8 = 0;
      memset(&DAT_00595144,0,0x34);
      FUN_0044e680();
      _atexit(thunk_FUN_0044e780);
      local_8 = 0xffffffff;
      FUN_00464661(&DAT_00595178);
    }
  }
  FUN_0044f4d0(&DAT_00595144,&local_58,0x21);
  ExceptionList = local_10;
  local_54 = 0xbb;
  local_53 = 0x2c;
  local_52 = 0x43;
  local_51 = 0;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


