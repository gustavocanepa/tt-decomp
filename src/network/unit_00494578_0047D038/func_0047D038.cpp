#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0xA4];
    char *vtbl;
};

extern "C" void func_0047D038(Obj *self) {
    VEntry *e1 = (VEntry *)(self->vtbl + 0x30);
    e1->fn((char *)self + e1->delta);
    VEntry *e2 = (VEntry *)(self->vtbl + 0x18);
    e2->fn((char *)self + e2->delta);
}
