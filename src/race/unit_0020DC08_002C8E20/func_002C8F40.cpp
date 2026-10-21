#include "types.h"

struct VEntry_0038E008 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner_0038E008 {
    VEntry_0038E008 *vtbl;
};

struct Obj_0038E008 {
    char pad[0xD04];
    Inner_0038E008 *unk1C;
};

extern "C" void func_002C8F40(struct Obj_0038E008 *arg0) {
    Inner_0038E008 *a1 = arg0->unk1C;
    VEntry_0038E008 *e = &a1->vtbl[18];

    e->fn((char *)a1 + e->delta);
}
