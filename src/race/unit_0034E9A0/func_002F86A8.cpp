#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct VObj {
    char pad[0xD0];
    char *vtbl;
};

struct Obj {
    char pad[0xC];
    VObj *owner;
};

extern "C" s32 func_002F8688(Obj *);

extern "C" void func_002F86A8(Obj *self) {
    s32 v = func_002F8688(self);
    VObj *o = self->owner;
    VEntry *e = (VEntry *)(o->vtbl + 0x30);
    e->fn((char *)o + e->delta, v);
}
