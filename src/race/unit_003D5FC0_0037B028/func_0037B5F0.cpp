#include "types.h"

struct V3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Obj_003D7060 {
    char pad0[4];
    char *p4;
};

extern "C" V3 *func_0037B5F0(V3 *arg0, Obj_003D7060 *arg1) {
    V3 t;
    char *base = arg1->p4 + 0x668;

    t.x = *(f32 *)(base + 0x0);
    t.y = *(f32 *)(base + 0x8);
    t.z = -*(f32 *)(base + 0x4);
    *arg0 = t;
    return arg0;
}
