#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct VObj {
    char pad[0xD4];
    char *vtbl;
};

struct Obj {
    char pad[0x80];
    VObj *child;
};

extern "C" void func_003759E8(Obj *self) {
    VObj *o = self->child;
    if (o != 0) {
        VEntry *e = (VEntry *)(o->vtbl + 8);
        e->fn((char *)o + e->delta, 3);
    }
    self->child = 0;
}
