typedef int s32;
typedef float f32;

extern "C" f32 func_0037C3E8(char *self) {
    f32 s = *(f32 *)(self + 0x14);
    char *sub = *(char **)(self + 0x24);
    f32 pa = *(f32 *)(self + 0x18);
    f32 pb = *(f32 *)(sub + 0x4);
    s32 a = (s32)(pa / s);
    s32 b = (s32)(pb / s);
    return s * (f32)(a - b - 1);
}
