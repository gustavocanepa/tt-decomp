#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void **);
};

struct Elem {
    char pad[4];
    char *vtbl;
};

struct Owner {
    char pad[0x8];
    Elem **arr;
    char pad2[8];
    s32 count;
};

struct Outer {
    char pad[0x2C];
    Owner *owner;
};

extern "C" void func_002B4188(void *unused, Outer *a1) {
    Owner *o = a1->owner;
    s32 idx = o->count - 1;
    Elem **slot = o->arr + idx;
    Elem *e = *slot;
    if (e != 0) {
        VEntry *v = (VEntry *)(e->vtbl + 0xA0);
        v->fn((char *)e + v->delta, (void **)slot);
    }
}
