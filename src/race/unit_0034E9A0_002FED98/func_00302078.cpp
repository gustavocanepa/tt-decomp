typedef int s32;
typedef signed char s8;

extern s8 D_005834A8[];

extern "C" s32 func_00301F68(s32 x);

extern "C" s32 func_00302078(s32 x) {
    s32 i = func_00301F68(x);
    s8 c = D_005834A8[i];
    if (c == 1 || c == -1) {
        return c;
    }
    return 0;
}
