#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0x1C];
    ObjInner *unk1C;
};

extern "C" void CarGeometry__GetStepPosition_Z(Obj *arg0, void *arg1) {
    ObjInner *a1 = arg0->unk1C;
    VEntry *e = &a1->vtbl[10];

    e->fn((char *)a1 + e->delta, arg1);
}
