#include "types.h"

struct Obj {
    s16 unk0;
    char pad2[0x6];
    s32 unk8;
    s32 unkC;
};

extern "C" void func_0036C2E0(Obj *arg0) {
    s32 v = -1;
    arg0->unkC = 0;
    arg0->unk0 = (s16)v;
    arg0->unk8 = v;
}
