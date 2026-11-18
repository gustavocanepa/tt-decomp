#include "types.h"

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" void func_002E14B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_0034B928(struct Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0 = arg0->unk8;
    if (temp_v0 != 0) {
        func_002E14B0(temp_v0, arg1, arg2, 1, arg3);
    }
}
