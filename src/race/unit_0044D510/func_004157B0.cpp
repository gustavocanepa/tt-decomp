#include "types.h"

struct Obj {
    char pad0[0x18];
    f32 sx;
    f32 sy;
    f32 kx;
    f32 ky;
    f32 x;
    f32 y;
};

extern "C" void func_00415800(Obj *o, f32 x, f32 y);

extern "C" void func_004157B0(Obj *o, f32 x, f32 y) {
    o->x = x;
    o->y = y;
    func_00415800(o, x * o->sx * o->kx, y * o->sy * o->ky);
}
