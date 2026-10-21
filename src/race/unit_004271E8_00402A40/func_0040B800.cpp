typedef int s32;

extern s32 D_00585A08[];

extern "C" s32 func_0040B800(s32 unused, s32 arg1) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_00585A08[i] == arg1) return 1;
    }
    return 0;
}
