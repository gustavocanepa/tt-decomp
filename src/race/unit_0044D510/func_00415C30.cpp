#include "types.h"

struct Obj {
    char pad0[0x44];
    s32 unk2C;
    char pad30[0x88 - 0x48];
    f32 unk70;
};

extern Obj *D_00586EF4;

extern "C" void func_00415C30(f32 fparg0) {
    if (fparg0 > 0.0f) {
        D_00586EF4->unk2C = 1;
    }
    D_00586EF4->unk70 = fparg0;
}
