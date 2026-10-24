#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" void func_001FC728(Obj *arg0);

extern "C" void func_001FC798(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unk8 = arg3;
    arg0->unkC = 0;
    return func_001FC728(arg0);
}
