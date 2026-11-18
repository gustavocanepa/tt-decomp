#include "types.h"

struct VEntry_00109910 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_00109910 {
    char pad[0x64];
    VEntry_00109910 *vtbl;
};

extern "C" void func_00108B40(Obj_00109910 *arg0) {
    VEntry_00109910 *e = &arg0->vtbl[8];

    e->fn((char *)arg0 + e->delta);
}
