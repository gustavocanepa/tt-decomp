#include "types.h"

struct Obj {
    char pad[0x150];
    s32 unk9C;
};

extern "C" void func_0053C7C0(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x80;
    v = v | (temp << 7);
    arg0->unk9C = v;
}
