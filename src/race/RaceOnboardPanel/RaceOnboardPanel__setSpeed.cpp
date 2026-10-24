#include "types.h"

struct Obj {
    u8 pad[0x88];
    f32 unk88;
    u8 pad2[0xA06 - 0x88 - 4];
    s16 unkA06;
};

extern "C" void RaceOnboardPanel__virtual_17(Obj *arg0, f32 fparg0) {
    arg0->unk88 = fparg0;
    arg0->unkA06 = (s16)(fparg0 + 0.5f);
}
