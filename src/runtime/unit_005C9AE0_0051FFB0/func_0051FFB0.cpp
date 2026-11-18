#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    char pad0[0x0];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x4];
    Sub *unk58;
};

extern "C" void func_0051FFB0(struct Obj *arg0) {
    Sub *a1 = arg0->unk58;

    if (a1 != 0) {
        VEntry *e = &a1->vtbl[2];
        e->fn((char *)a1 + e->delta);
    }
}
