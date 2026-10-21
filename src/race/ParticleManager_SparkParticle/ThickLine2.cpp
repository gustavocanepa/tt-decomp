/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Vec3 { float x, y, z; };
extern char D_005F7A20[];
extern "C" s32 *func_00473980(s32);
extern "C" float *func_00473980_f(s32) __asm__("func_00473980");
extern "C" void func_0046D810(s32, float *, char *, s32 *, s32, s32);

static inline float rsqrt_s(float a, float b) {
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" void ThickLine2(Vec3 *a, Vec3 *b, s32 color, float w) {
    s32 *c = func_00473980(1);
    float *v = func_00473980_f(3);
    c[0] = color;
    c[1] = color;
    c[2] = color;
    c[3] = color;
    float ax = a->x, ay = a->y, az = a->z;
    float bx = b->x, by = b->y, bz = b->z;
    float dx = bx - ax;
    float dy = by - ay;
    float d2 = dx * dx + dy * dy;
    if (d2 == 0.0f) {
        v[0] = ax + w;
        v[1] = ay + w;
        v[2] = az;
        v[3] = ax - w;
        v[4] = ay + w;
        v[5] = az;
        v[6] = ax + w;
        v[7] = ay - w;
        v[8] = az;
        v[9] = ax - w;
        v[10] = ay - w;
        v[11] = az;
    } else {
        d2 = rsqrt_s(w, d2);
        dx *= d2;
        dy *= d2;
        float f0 = ax - dx;
        float f1 = ay - dy;
        float f2 = bx + dx;
        float f3 = by + dy;
        v[0] = f0 - dy;
        v[1] = f1 + dx;
        v[2] = az;
        v[3] = f0 + dy;
        v[4] = f1 - dx;
        v[5] = az;
        v[6] = f2 - dy;
        v[7] = f3 + dx;
        v[8] = bz;
        v[9] = f2 + dy;
        v[10] = f3 - dx;
        v[11] = bz;
    }
    func_0046D810(4, v, D_005F7A20, c, 0, 0);
}
