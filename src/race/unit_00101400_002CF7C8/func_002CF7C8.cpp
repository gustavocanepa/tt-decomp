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

extern "C" void func_002CF7C8(Obj_00109910 *arg0) {
    VEntry_00109910 *e = &arg0->vtbl[125];

    e->fn((char *)arg0 + e->delta);
}
