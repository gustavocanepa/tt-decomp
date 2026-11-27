#include "types.h"

struct Obj {
    char pad[0x10];
    u64 flags;
};

extern "C" s32 func_004E4870(Obj **h, s32 on) {
    Obj *o = *h;
    u64 old = o->flags;
    s32 r = old & 1;
    if (on)
        o->flags = old | 1;
    else
        o->flags = old & ~1ULL;
    return r;
}
