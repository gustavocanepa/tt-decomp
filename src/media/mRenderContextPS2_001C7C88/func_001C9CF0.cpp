#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x4];
    char *vtbl;
};

extern "C" void func_00104D10(s32 *arg0);

extern "C" void func_001C9CF0(Obj *self) {
    VEntry *e = (VEntry *)(self->vtbl + 0x1F0);
    e->fn((char *)self + e->delta);
    func_00104D10((s32 *)((char *)self + 0x1D58));
}
