#include "types.h"

struct Obj {
    char pad0[0x94];
    s32 unk94;
    s32 unk98;
};

extern "C" void func_002D9078(struct Obj *arg0) {
    s32 three = 3;
    s32 one = 1;
    s32 t = arg0->unk94 + 1;
    s32 r;

    arg0->unk94 = t;
    r = t % three;
    arg0->unk98 = one;
    arg0->unk94 = r;
}
