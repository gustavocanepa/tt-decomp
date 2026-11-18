#include "types.h"

struct Out0047AEB0 {
    s32 unk0;
    f32 unk4;
};

struct In0047AEB0 {
    char pad0[0x64];
    s32 unk64;
};

extern "C" struct Out0047AEB0 *func_00441BC8(struct Out0047AEB0 *arg0, struct In0047AEB0 *arg1) {
    f32 v = (f32)arg1->unk64;
    arg0->unk0 = 6;
    arg0->unk4 = v + 1.0f;
    return arg0;
}
