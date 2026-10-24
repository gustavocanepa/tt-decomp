/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct A { f32 x, y, z, w, r; };
struct B { f32 x, y, z, w, dx, dy, dz; };
static inline f32 sqrtf_(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" {
s32 func_003EA900(A *a, B *b, f32 *o1, f32 *o2) {
    f32 dx = b->dx, dz = b->dz, dy = b->dy;
    f32 d2 = dx * dx + dy * dy + dz * dz;
    if (d2 == 0.0f) return -1;
    f32 ax = a->x, ay = a->y, az = a->z;
    f32 bx = b->x, by = b->y, bz = b->z;
    f32 r = a->r;
    f32 rr = r * r;
    f32 h = (((ax * dx + ay * dy + az * dz) - dx * bx) - dy * by) - dz * bz;
    f32 c = (ax * ax + ay * ay + az * az + bx * bx + by * by + bz * bz) - rr - 2.0f * (ax * bx + ay * by + az * bz);
    f32 disc = h * h;
    disc -= d2 * c;
    if (disc < 0.0f) return 0;
    f32 inv = 1.0f / d2;
    if (disc == 0.0f) {
        *o1 = h * inv;
        return 1;
    }
    disc = sqrtf_(disc);
    *o1 = (h - disc) * inv;
    *o2 = (h + disc) * inv;
    return 2;
}
}
