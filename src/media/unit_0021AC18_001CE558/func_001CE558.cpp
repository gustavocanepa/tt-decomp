#include "types.h"

struct Obj0021B4D8 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" void func_001CE558(struct Obj0021B4D8 *arg0, s32 arg1, s32 arg2) {
    arg0->unk8 = arg1;
    arg0->unkC = arg2;
}
