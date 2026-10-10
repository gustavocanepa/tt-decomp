typedef int s32;

extern "C" s32 func_00317F60(s32 arg0) {
    s32 idx = arg0;
    if (idx < 0) {
        idx = 0;
    }
    if (idx >= 0x10) {
        idx = 0xF;
    }
    return *(s32 *)(0x583A50 + idx * 4);
}
