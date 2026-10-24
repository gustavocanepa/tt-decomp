#include "types.h"

struct VEntry_00109910 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_00109910 {
    char pad[0xA4];
    VEntry_00109910 *vtbl;
};

extern "C" void func_0047C8A8(Obj_00109910 *arg0) {
    VEntry_00109910 *e = &arg0->vtbl[10];

    e->fn((char *)arg0 + e->delta);
}
