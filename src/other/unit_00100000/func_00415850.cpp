typedef float f32;

struct S_00624980 {
    char pad[0x40];
    f32 unk24;
};

extern S_00624980 *D_00586EF4;

extern "C" f32 func_00415850(void) {
    return D_00586EF4->unk24;
}
