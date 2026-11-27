#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    char pad0[4];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x308];
    Sub *unk2A4;
};

extern "C" void func_00126768(Obj *arg0) {
    Sub *a1 = arg0->unk2A4;
    if (a1 != 0) {
        VEntry *e = &a1->vtbl[60];
        e->fn((char *)a1 + e->delta);
    }
}
