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
    char pad[0x1C];
    ObjInner *unk1C;
};

extern "C" void CarGeometry__GetSideBrakePosition_X(Obj *arg0) {
    ObjInner *a1 = arg0->unk1C;
    VEntry *e = &a1->vtbl[21];

    e->fn((char *)a1 + e->delta);
}
