#include "types.h"

struct VEntry_0038E738 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Inner_0038E738 {
    VEntry_0038E738 *vtbl;
};

struct Obj_0038E738 {
    char pad[0x1C];
    Inner_0038E738 *unk1C;
};

static inline s32 vcall_0038E738(struct Inner_0038E738 *o) {
    VEntry_0038E738 *e = &o->vtbl[49];
    return e->fn((char *)o + e->delta);
}

extern "C" void func_003431C0(struct Obj_0038E738 *arg0) {
    vcall_0038E738(arg0->unk1C);
}
