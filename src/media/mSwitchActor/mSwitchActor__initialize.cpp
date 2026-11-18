#include "types.h"

struct Obj {
    char pad0[0x5C];
    s32 unk24;
    char pad1[0x74 - 0x5C - 4];
    s32 unk3C;
    f32 unk40;
};

extern "C" void mSwitchActor__initialize(Obj *arg0) {
    arg0->unk3C = 0;
    arg0->unk40 = 0.1f;
    arg0->unk24 = 0;
}
