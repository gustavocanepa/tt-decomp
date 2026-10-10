typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

extern "C" void func_001FF578(u32 arg0, s32 arg1, u32 arg2, s8 arg3) {
    u32 t = arg2 + arg1 * 2;
    t = t + arg0;
    *(s8 *)(t + 0xC0) = arg3;
}
