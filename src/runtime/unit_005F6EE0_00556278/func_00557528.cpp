#include "types.h"

struct Obj {
    char pad[0x24];
    s32 unk24;
};

extern "C" void func_00557528(struct Obj *arg0, u8 arg1) {
    arg0->unk24 = (arg0->unk24 & ~0xFF) | arg1;
}
