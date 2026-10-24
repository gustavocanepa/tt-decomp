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
    char pad0[0xD04];
    Sub *unkC44;
};

extern "C" void func_002C8E20(Obj *arg0) {
    Sub *s = arg0->unkC44;
    VEntry *e = &s->vtbl[5];

    e->fn((char *)s + e->delta);
}
