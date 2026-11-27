#include "types.h"

struct Obj {
    s32 unk0;
    s16 unk4;
    char pad6[1];
    s8 unk7;
};

extern "C" void func_003FE9A8(Obj *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = 0;
    if (arg1 == 0) {
        arg0->unk7 = 1;
        return;
    }
    arg0->unk7 = 0;
}
