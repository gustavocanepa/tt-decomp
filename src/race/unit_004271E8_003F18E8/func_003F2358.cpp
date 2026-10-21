#include "types.h"

struct S_0042ACA8 {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char D_005D80B0[];

extern "C" void func_003F2358(S_0042ACA8 *arg0, s32 arg1) {
    arg0->unkC = arg1;
    arg0->unk8 = 0;
    arg0->unk4 = D_005D80B0;
    arg0->unk0 = 0;
}
