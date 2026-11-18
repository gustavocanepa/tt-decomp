#include "types.h"

struct VEntry_0038C6D0 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_0038C6D0 {
    VEntry_0038C6D0 *vtbl;
};

extern "C" void func_003410B8(Obj_0038C6D0 *arg0) {
    VEntry_0038C6D0 *e = &arg0->vtbl[36];

    e->fn((char *)arg0 + e->delta);
}
