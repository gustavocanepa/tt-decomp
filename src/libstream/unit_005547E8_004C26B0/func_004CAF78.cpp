#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    char *vtbl;
};

struct Obj {
    void *m0;
    VObj *child;
};

extern "C" void func_004CA080(Obj *);

static inline s32 vcall(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x20);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_004CAF78(Obj *self) {
    VObj *o = self->child;
    if (o != 0) {
        vcall(o);
        return;
    }
    return func_004CA080(self);
}
