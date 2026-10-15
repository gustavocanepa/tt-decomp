typedef int s32;

extern "C" char D_007A64F0[];
extern "C" s32 func_004FA710(void);
extern "C" s32 func_005091C0(void);
extern "C" void func_004A45D0(s32);

extern "C" s32 func_00509580(void) {
    char *base = D_007A64F0;
    s32 s0 = *(s32 *)(base + func_004FA710() * 4);
    if (s0 == 0) {
        s0 = func_005091C0();
        s32 v1 = *(s32 *)(base + func_004FA710() * 4);
        if (v1 != 0) {
            func_004A45D0(v1);
        }
        s32 *slot = (s32 *)(base + func_004FA710() * 4);
        *slot = s0;
    }
    return s0;
}
