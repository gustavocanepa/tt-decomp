#include "types.h"

struct Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void func_005591E8(struct Obj *arg0, u8 arg1) {
    arg0->unk18 = (arg0->unk18 & ~0xFF) | arg1;
}
