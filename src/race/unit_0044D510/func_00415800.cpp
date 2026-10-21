#include "types.h"

struct Obj {
    char pad[0x3C];
    f32 unk24;
    f32 unk28;
};

extern struct Obj *D_00586EF4;

extern "C" void func_00415800(f32 fparg0, f32 fparg1) {
    struct Obj *temp_v1 = D_00586EF4;
    temp_v1->unk24 = fparg0;
    temp_v1->unk28 = fparg1;
}

extern "C" void func_0044DC28(void) {
}
