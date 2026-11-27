#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;
};

extern "C" char D_005D8DC8[];

extern "C" void func_003FEC30(struct Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk0 = arg1;
    arg0->unkC = D_005D8DC8;
    arg0->unk4 = arg2;
    arg0->unk8 = arg3;
}
