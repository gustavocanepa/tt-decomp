#include "types.h"

struct S00480F78 {
    char pad0[8];
    s32 unk8;
};

extern "C" void func_0043D510(s32 arg0);

extern "C" void func_00447CD8(struct S00480F78 *arg0) {
    s32 temp_a0;

    temp_a0 = arg0->unk8 - 8;
    arg0->unk8 = temp_a0;
    func_0043D510(temp_a0);
}
