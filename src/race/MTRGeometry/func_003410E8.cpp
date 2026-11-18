#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void func_003410E8(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[37];

    e->fn((char *)arg0 + e->delta);
}
