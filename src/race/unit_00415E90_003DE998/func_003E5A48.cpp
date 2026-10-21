typedef int s32;
typedef unsigned int u32;

extern s32 D_005F8EC0[];

s32 func_003E5A48(u32 arg0) {
    if (arg0 < 0x14U) {
        return D_005F8EC0[arg0];
    }
    return -1;
}
