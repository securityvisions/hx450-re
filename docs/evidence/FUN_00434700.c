

void __fastcall FUN_00434700(MWindow *param_1)

{
  if (param_1[0x76c] == (MWindow)0x0) {
    param_1[0x76c] = (MWindow)0x1;
    FUN_0041f650((int)param_1);
    FUN_0041f8f0(param_1);
    FUN_0045c230((undefined4 *)(param_1 + 0x87c));
    FUN_0045cb10((int)(param_1 + 0x87c));
    param_1[0x52142] = (MWindow)0x0;
    FUN_004357d0(param_1,1);
  }
  return;
}


