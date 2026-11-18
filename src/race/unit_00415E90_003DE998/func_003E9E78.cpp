/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct V { f32 x, y, z; };
static inline f32 sqrtf_(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" {
f32 func_003E9D18(f32, f32, f32, f32, f32, f32) throw() __attribute__((const));
f32 func_003E9E78(V *a, V *b, V *c) {
    f32 ay = a->y, az = a->z;
    f32 by = b->y, bz = b->z;
    f32 cy = c->y, cz = c->z;
    f32 d0 = func_003E9D18(ay, az, by, bz, cy, cz);
    f32 ax = a->x, bx = b->x, cx = c->x;
    f32 d1 = func_003E9D18(az, ax, bz, bx, cz, cx);
    f32 d2 = func_003E9D18(ax, ay, bx, by, cx, cy);
    return sqrtf_(d0 * d0 + d1 * d1 + d2 * d2) * 0.5f;
}
}
