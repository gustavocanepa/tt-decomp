typedef int s32;

extern "C" s32 func_003020F0(s32 arg0) {
    if (arg0 < 0x25) {
        if (arg0 >= 0xD) {
            return 0x18 - arg0;
        }
        return arg0;
    }
    return arg0 - 0x30;
}
