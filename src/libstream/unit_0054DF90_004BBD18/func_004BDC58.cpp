#include "types.h"

struct Obj2 {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
};

struct Obj1 {
    char pad0[0x8];
    Obj2 *unk8;
};

extern "C" s32 D_00776D4C;

extern "C" s32 func_004BDC58(Obj1 *arg0) {
    Obj2 *a1 = arg0->unk8;
    s32 shift = D_00776D4C;
    return a1->unk34 + (a1->unk30 << shift);
}
