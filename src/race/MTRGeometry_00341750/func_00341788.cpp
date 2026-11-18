#include "types.h"

struct VEntry_0038C7F8 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_0038C7F8 {
    VEntry_0038C7F8 *vtbl;
};

extern "C" void func_00341788(Obj_0038C7F8 *arg0) {
    VEntry_0038C7F8 *e = &arg0->vtbl[42];

    e->fn((char *)arg0 + e->delta);
}
