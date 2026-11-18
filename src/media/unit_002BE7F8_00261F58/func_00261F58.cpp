#include "types.h"

struct S002BEB40 {
    char pad0[0x368];
    s32 unk308;
};

extern "C" void func_00261F58(struct S002BEB40 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk308;
    v = v & ~0x100;
    v = v | (temp << 8);
    arg0->unk308 = v;
}
