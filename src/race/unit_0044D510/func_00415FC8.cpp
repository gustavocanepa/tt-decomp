/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

extern "C" {
    extern char *D_00586EF4;
}

extern "C" void func_00415FC8(char *arg0) {
    char **g = (char **)&D_00586EF4;

    *(f32 *)(arg0 + 0x8) = (f32)(*(f32 *)(*g + 0x6C) + *(f32 *)(*g + 0x48));
    *(f32 *)(arg0 + 0xC) = (f32)(*(f32 *)(*g + 0x70) + *(f32 *)(*g + 0x4C));
}
