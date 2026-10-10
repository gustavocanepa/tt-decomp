typedef signed int s32;

extern "C" s32 func_0029F728();

extern "C" s32 func_0029F8C0(s32 arg0, s32 *arg1) {
    s32 *s0 = arg1;
    s32 s1 = arg0;
    *s0 = func_0029F728();
    return s1;
}
