#include "types.h"

struct Vec3 {
    float x, y, z;
};

struct VEntry {
    s16 delta;
    s16 index;
    Vec3 (*fn)(void *);
};

struct Obj {
    char *vtbl;
};

extern "C" void func_004755EC(float, float, float);

extern "C" void func_0041EB60(Obj *self) {
    VEntry *e = (VEntry *)(self->vtbl + 0x40);
    Vec3 v = e->fn((char *)self + e->delta);
    func_004755EC(v.x, v.y, v.z);
}
