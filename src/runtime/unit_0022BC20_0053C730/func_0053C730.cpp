#include "types.h"

struct Obj00233D48 {
    char pad[0x150];
    s32 unkE8;
};

extern "C" void func_0053C730(struct Obj00233D48 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkE8;
    v = v & ~0x10;
    v = v | (temp << 4);
    arg0->unkE8 = v;
}
