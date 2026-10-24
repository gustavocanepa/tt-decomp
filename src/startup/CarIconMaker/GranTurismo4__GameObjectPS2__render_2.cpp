#include "types.h"

struct VEntry_003EB340 {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Obj_003EB340 {
    char pad0[0x64];
    VEntry_003EB340 *vtbl;
};

extern "C" void GranTurismo4__GameObjectPS2__render_2(struct Obj_003EB340 *arg0, void *arg1) {
    VEntry_003EB340 *e = &arg0->vtbl[16];

    e->fn((char *)arg0 + e->delta, arg1);
}
