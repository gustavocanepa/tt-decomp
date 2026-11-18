#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32);
};

struct Child {
    VEntry *vtbl;
};

struct Obj {
    char pad0[0xE4E0];
    Child *child;
};

extern "C" void func_0033E438(Obj *self, s32 a, s32 b) {
    Child *c = self->child;
    if (c) {
        VEntry *e = c->vtbl + 19;
        e->fn((char *)c + e->delta, a, b);
    }
}
