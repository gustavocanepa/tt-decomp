#include "types.h"

struct VEntry_002638E8 {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Obj_002638E8 {
    char pad[0];
    VEntry_002638E8 *vtbl;
};

extern "C" void func_00556390(Obj_002638E8 *arg0, void *arg1) {
    VEntry_002638E8 *e = &arg0->vtbl[51];

    e->fn((char *)arg0 + e->delta, arg1);
}
