#include "types.h"

struct Obj {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_0042BCC8(s32 arg0);

extern "C" void func_00266440(struct Obj *arg0) {
    struct Obj *s0 = arg0;
    s32 temp_v0 = s0->unk14;

    if (temp_v0 != 0) {
        func_0042BCC8(temp_v0);
        s0->unk14 = 0;
    }
}
