#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Child {
    char pad0[0x64];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x84];
    Child *child;
};

extern "C" s32 func_00376B08(Obj *self) {
    Child *c = self->child;
    if (c) {
        VEntry *e = c->vtbl + 81;
        return e->fn((char *)c + e->delta);
    }
    return 0;
}
