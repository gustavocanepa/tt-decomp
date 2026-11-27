#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, s32);
};

struct Sub {
    char pad0[4];
    VEntry *vtbl;
};

struct Obj {
    Sub *unk0;
};

extern "C" void func_0029F6A0(struct Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Sub *a3 = arg0->unk0;
    VEntry *e = &a3->vtbl[54];

    e->fn((char *)a3 + e->delta, arg1, arg2);
}
