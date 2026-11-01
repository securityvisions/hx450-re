

int FUN_00451b80(int param_1)

{
  if (param_1 != 0) {
    switch(param_1) {
    case 0xe0:
      return 1;
    case 0xe1:
      return 2;
    case 0xe2:
      return 4;
    case 0xe3:
      return 8;
    case 0xe4:
      return 0x10;
    case 0xe5:
      return 0x20;
    case 0xe6:
      return 0x40;
    case 0xe7:
      param_1 = 0x80;
    }
    return param_1;
  }
  return 0;
}


