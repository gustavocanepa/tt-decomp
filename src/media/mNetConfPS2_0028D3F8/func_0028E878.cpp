#include "types.h"

extern "C" void func_002067E8(s32 arg0, s32 arg1, s32 arg2);

struct D_Obj {
    char pad[0xDC];
    s32 unkC4;
};

extern "C" void func_0028E878(D_Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0->unkC4 != 0) {
        func_002067E8(arg1, arg2, arg3);
    } else {
        func_002067E8(arg1, arg3, arg2);
    }
}
