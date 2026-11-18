#include "types.h"

struct Obj {
    s32 unk0;
    char pad0[0x88 - 4];
    f32 unk70;
    f32 unk74;
};

extern "C" void func_003A7460(Obj *arg0) {
    if (arg0->unk0 == 0) {
        arg0->unk70 = 0.0f;
        return;
    }
    arg0->unk70 = 0.5f;
    arg0->unk74 = 0.008333333f;
}
