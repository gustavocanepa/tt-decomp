typedef int s32;

struct Pair_0048ECC8 {
    s32 a;
    s32 b;
};

struct Init_0048ECC8 {
    s32 index;
    Pair_0048ECC8 value;
};

extern "C" volatile s32 D_00586A60;
extern "C" Pair_0048ECC8 D_0076CE70[];
extern "C" Init_0048ECC8 D_006022B8[12];

extern "C" void func_00455858(void) {
    if (D_00586A60 == 0) {
        s32 i;
        for (i = 0; i < 12; i++) {
            D_0076CE70[D_006022B8[i].index] = D_006022B8[i].value;
        }
        D_00586A60 = 1;
    }
}
