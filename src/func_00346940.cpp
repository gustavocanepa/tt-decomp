typedef int s32;

extern "C" s32 func_00346940(s32 arg0, s32 arg1) {
    char *dst = (char *)arg0;
    char *src = (char *)arg1;
    __builtin_memcpy(dst + 0x24, src + 0x24, 0x100);
    return arg0;
}
