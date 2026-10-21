#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
    char pad1[0x704 - 4 - 4];
    f32 unk6E8;
};

extern "C" s32 func_002F0D48(s32 arg0);

extern "C" f32 func_002E6118(struct Obj *arg0) {
    s32 r = func_002F0D48(arg0->unk4);
    f32 v0 = 0.0f;

    if (r == 0) {
        v0 = arg0->unk6E8;
    }
    return v0;
}
