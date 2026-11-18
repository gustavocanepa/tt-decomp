#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_00228E28(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[82];

    e->fn((char *)arg0 + e->delta, 0);
}
