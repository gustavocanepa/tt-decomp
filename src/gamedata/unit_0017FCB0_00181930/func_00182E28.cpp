typedef int s32;

extern "C" s32 func_001802B0(s32 arg0);
extern char D_0003277C[];

extern "C" s32 func_00182E28(s32 arg0, s32 arg1) {
    s32 v0 = func_001802B0(arg1);
    s32 v1 = 0;
    if (v0 != 0) {
        v1 = *(s32 *)(D_0003277C + v0);
    }
    return v1;
}
