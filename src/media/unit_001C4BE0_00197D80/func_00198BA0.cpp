#include "types.h"

typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0x30];
    ObjInner *unk30;
};

extern "C" void func_00198BA0(Obj *arg0) {
    ObjInner *a1 = arg0->unk30;
    VEntry *e = &a1->vtbl[4];

    e->fn((char *)a1 + e->delta);
}
