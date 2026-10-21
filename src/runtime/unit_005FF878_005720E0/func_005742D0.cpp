#include "types.h"

struct Obj {
    char pad[0x44];
    f32 unk44;
    f32 unk48;
};

extern "C" void func_005742D0(struct Obj *arg0) {
    arg0->unk44 = arg0->unk44 + arg0->unk48;
}
