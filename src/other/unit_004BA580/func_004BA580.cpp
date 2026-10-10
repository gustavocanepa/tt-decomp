typedef int s32;

struct S0086DD84 {
    s32 unk0;
    char pad4[8];
};

extern "C" struct S0086DD84 D_00775304[];

extern "C" s32 func_004BA580(s32 arg0) {
    return D_00775304[arg0].unk0;
}
