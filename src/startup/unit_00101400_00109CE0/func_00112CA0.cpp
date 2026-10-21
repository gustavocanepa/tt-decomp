typedef int s32;
typedef float f32;

extern "C" void func_00112CA0(char *arg0, s32 arg1) {
    s32 v0;
    s32 v1;

    *(f32 *)(arg0 + 0xCFF4) = 0.5f;
    if (arg1 != 0) {
        v1 = 0x23;
        v0 = 0x24;
    } else {
        v1 = 0x1B;
        v0 = 0x1C;
    }
    *(s32 *)(arg0 + 0xE24) = v1;
    *(s32 *)(arg0 + 0xE28) = v0;
}
