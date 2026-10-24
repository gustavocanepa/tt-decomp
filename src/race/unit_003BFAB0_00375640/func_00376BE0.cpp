#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, int, int);
};

struct Sub {
    char pad0[0x64];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x84];
    Sub *unk84;
};

extern "C" void func_00376BE0(struct Obj *arg0, int arg1, int arg2) {
    Sub *a3 = arg0->unk84;

    if (a3 != 0) {
        VEntry *e = &a3->vtbl[87];
        e->fn((char *)a3 + e->delta, arg1, arg2);
    }
}
