#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    VEntry *vtbl;
};

struct Obj {
    u8 pad0[0xD04];
    Sub *unk1C;
};

extern "C" void func_002C8DF0(Obj *arg0) {
    Sub *s = arg0->unk1C;
    VEntry *e = &s->vtbl[4];

    e->fn((char *)s + e->delta);
}
