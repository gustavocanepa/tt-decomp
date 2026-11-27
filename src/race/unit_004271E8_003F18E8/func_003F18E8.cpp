#include "types.h"
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
struct O { char p[4]; f32 lo; char p2[4]; f32 span; int p3; unsigned char clamp; };
extern "C" int func_003E6F48(f32);
extern "C" f32 func_003F18E8(O *o, f32 x) {
    volatile f32 spill[4];
    spill[0] = x;
    if (*(volatile unsigned char *)&o->clamp) {
        return minf(x, o->lo + o->span);
    }
    f32 s = o->span;
    f32 lo = o->lo;
    f32 d = x - lo;
    if (s != 0.0f) {
        d -= s * (f32)func_003E6F48(d / s);
    }
    return d + lo;
}
