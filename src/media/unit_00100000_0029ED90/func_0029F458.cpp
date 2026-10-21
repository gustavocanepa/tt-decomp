#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32);
};

struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_0029F458(struct Obj *arg0, s8 arg1) {
    s8 tmp = arg1;
    VEntry *e = &arg0->vtbl[55];

    e->fn((char *)arg0 + e->delta, &tmp, 1);
}
