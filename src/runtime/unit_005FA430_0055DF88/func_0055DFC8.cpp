#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    u8 active;
    char pad[0x13];
    char *vtbl;
};

extern "C" void func_0055DFC8(Obj *self, s32 arg1) {
    if (self->active) {
        VEntry *e = (VEntry *)(self->vtbl + 0x30);
        e->fn((char *)self + e->delta, arg1);
    }
}
