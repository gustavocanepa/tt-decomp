#include "types.h"

struct S_00600240 {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char D_005D76E0[];

extern "C" void func_00560A98(struct S_00600240 *arg0, s32 arg1, s32 arg2) {
    arg0->unkC = arg2;
    arg0->unk8 = arg1;
    arg0->unk4 = D_005D76E0;
    arg0->unk0 = 0;
}
