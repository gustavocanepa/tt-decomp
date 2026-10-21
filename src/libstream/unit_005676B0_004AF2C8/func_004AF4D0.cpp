typedef int s32;

extern "C" s32 func_004AF4D0(s32 arg0) {
    s32 a = (arg0 & 3) == 0;
    s32 q = arg0 / 100;
    s32 r = arg0 % 100;
    s32 b = (q & 3) == 0;
    return r != 0 ? a : b;
}
