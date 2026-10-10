typedef int s32;

extern s32 D_00582A74;

extern "C" s32 func_00551420(s32 arg0) {
    s32 mask = 1 << arg0;
    s32 v = D_00582A74;
    return (v & mask) != 0;
}
