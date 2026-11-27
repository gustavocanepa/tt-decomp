#include "types.h"

struct Obj {
    char pad0[0x4];
    s32 unk4;
};

extern "C" s32 func_002E67D8(s32 arg0, f32 arg1);

extern "C" s32 func_0037BAF0(struct Obj *arg0) {
    return func_002E67D8(arg0->unk4, 0.0f);
}
