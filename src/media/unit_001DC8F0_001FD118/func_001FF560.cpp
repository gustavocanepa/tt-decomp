typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

extern "C" s8 func_001FF560(u32 arg0, s32 arg1, u32 arg2) {
    u32 t = arg2 + arg1 * 2;
    t = t + arg0;
    return *(s8 *)(t + 0xC0);
}
