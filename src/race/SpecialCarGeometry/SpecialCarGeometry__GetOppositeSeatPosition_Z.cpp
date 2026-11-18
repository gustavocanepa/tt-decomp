#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void SpecialCarGeometry__GetOppositeSeatPosition_Z(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[4];

    e->fn((char *)arg0 + e->delta);
}
