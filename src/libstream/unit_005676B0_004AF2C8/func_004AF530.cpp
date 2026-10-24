extern unsigned short D_0060C3E8[];
extern "C" int func_004AF530(int arg0, int arg1, int arg2) {
    int temp_a1 = arg1 - 1;
    int var_t4 = temp_a1 % 12;
    int var_a2 = arg0 + temp_a1 / 12;
    arg2 -= 1;
    if (var_t4 < 0) {
        var_a2 -= 1;
        var_t4 += 12;
    }
    int y = var_a2 - 1;
    int c = y / 100;
    int days = y * 365 + y / 4 - c + c / 4;
    int a = (y & 3) == 3;
    int b = (c & 3) == 3;
    int leap = ((y % 100) ^ 99) == 0 ? b : a;
    return days + (arg2 + D_0060C3E8[leap * 13 + var_t4]) + 0x1A4451;
}
