#include "types.h"

struct Obj {
    char pad0[8];
    s64 unk8;
    char pad1[0x18 - 0x10];
    s64 unk18;
};

extern Obj D_00597CF8;

extern "C" Obj *func_0048D1D8(void) {
    D_00597CF8.unk8 = 1;
    D_00597CF8.unk18 = 1;
    return &D_00597CF8;
}
