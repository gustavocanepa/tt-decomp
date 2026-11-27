#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
};

extern "C" s32 func_0033B870(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[59];

    return e->fn((char *)arg0 + e->delta) + 0x1A24;
}
