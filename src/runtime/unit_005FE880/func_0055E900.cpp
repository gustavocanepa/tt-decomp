#include "types.h"

struct VEntry_005FE8D0 {
    s16 delta;
    s16 index;
    void (*fn)(void *, float, float);
};

struct Obj_005FE8D0 {
    char pad[0x14];
    VEntry_005FE8D0 *vtbl;
};

extern "C" void func_0055E900(Obj_005FE8D0 *arg0, float f) {
    VEntry_005FE8D0 *e = &arg0->vtbl[10];

    e->fn((char *)arg0 + e->delta, 0.0f, f);
}
