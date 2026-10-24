#include "types.h"

struct Vec3 {
    f32 x, y, z;
};

extern "C" f32 func_00479D60(f32 y, f32 x);

extern "C" f32 func_003173B0(Vec3 *v) {
    f32 h = v->x * v->x + v->z * v->z;
    __asm__("sqrt.s %0, %1" : "=f"(h) : "f"(h));
    return -func_00479D60(v->y, h) * 57.29578f;
}
