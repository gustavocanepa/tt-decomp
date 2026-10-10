typedef int s32;

extern "C" s32 func_0019B7E0(s32 *arg0);

extern "C" s32 func_0019B7A8(s32 *arg0) {
    s32 *s0 = arg0;
    s32 v1 = func_0019B7E0(arg0);
    if (v1 < 0) {
        return 0;
    }
    *s0 = v1;
    return 1;
}
