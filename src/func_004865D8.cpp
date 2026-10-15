typedef unsigned int u32;
typedef int s32;

extern "C" s32 D_005978A8[];

extern "C" s32 func_004865D8(u32 arg0, u32 arg1) {
    if (!(arg1 < 5U)) {
        return 0;
    }
    if (!(arg0 < 0x28U)) {
        return 0;
    }
    {
        u32 k = arg0 * 5 + arg1;
        return D_005978A8[k];
    }
}
