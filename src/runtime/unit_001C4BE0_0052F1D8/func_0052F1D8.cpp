#include "types.h"

struct Obj {
    char pad[0xE0];
    s32 unk8F0;
    s32 unk8F4;
};

extern "C" void func_0052F1D8(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk8F0 = arg1;
    arg0->unk8F4 = arg2;
}
