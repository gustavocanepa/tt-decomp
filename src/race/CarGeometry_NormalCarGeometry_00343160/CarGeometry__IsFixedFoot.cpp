#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Inner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0x1C];
    Inner *unk1C;
};

static inline s32 vcall(struct Inner *o) {
    VEntry *e = &o->vtbl[47];
    return e->fn((char *)o + e->delta);
}

extern "C" void CarGeometry__IsFixedFoot(struct Obj *arg0) {
    vcall(arg0->unk1C);
}
