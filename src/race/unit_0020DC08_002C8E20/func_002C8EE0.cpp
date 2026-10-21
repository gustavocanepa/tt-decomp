#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0xD04];
    ObjInner *unk1C;
};

extern "C" void func_002C8EE0(Obj *arg0) {
    ObjInner *a1 = arg0->unk1C;
    VEntry *e = &a1->vtbl[12];

    e->fn((char *)a1 + e->delta);
}
