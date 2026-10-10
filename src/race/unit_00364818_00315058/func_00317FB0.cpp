typedef int s32;
typedef float f32;

extern "C" f32 func_00317FB0(s32 arg0) {
    if (arg0 <= 0) {
        arg0 = 0;
    }
    if (arg0 >= 0x14) {
        arg0 = 0x14;
    }
    return *(f32 *)(0x583AE0 + (arg0 * 4));
}
