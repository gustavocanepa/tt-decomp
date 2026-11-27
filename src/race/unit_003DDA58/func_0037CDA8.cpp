#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct ObjInner {
    char pad[0x64];
    VEntry *vtbl;
};

struct ObjA {
    char pad[0x84];
    ObjInner *unk84;
};

extern ObjA *D_005846B4;

static inline s32 vcall(ObjInner *o) {
    VEntry *e = &o->vtbl[60];
    return e->fn((char *)o + e->delta);
}

extern "C" void func_0037CDA8(void) {
    vcall(D_005846B4->unk84);
}
