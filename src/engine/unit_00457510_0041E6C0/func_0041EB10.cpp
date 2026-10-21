#include "types.h"

struct Vec3 {
    f32 x, y, z;
};

struct VEntry {
    short delta;
    short index;
    Vec3 (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void func_00475758(f32 a);
extern "C" void func_00475730(f32 a);
extern "C" void func_00475780(f32 a);

extern "C" void func_0041EB10(Obj *o) {
    VEntry *e = &o->vtbl[4];
    Vec3 r = e->fn((char *)o + e->delta);
    func_00475758(r.y);
    func_00475730(r.x);
    func_00475780(r.z);
}
