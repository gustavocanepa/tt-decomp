/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Env {
    char pad0[0x38];
    f32 scale;
    char pad3c[0xD0 - 0x3C];
    f32 nx, ny, nz;
    char padDC[4];
    f32 a[3];
    char padEC[4];
    f32 b[3];
};

extern Env *D_00584940;

extern "C" s32 func_003CDE08(f32 *vec, s32 flag, f32 t) {
    Env *e = D_00584940;
    u32 mask = 0x80000000;
    f32 inv = 1.0f / e->scale;
    f32 dot = e->nx * vec[0] + e->ny * vec[1] + e->nz * vec[2];
    f32 len2 = e->nx * e->nx + e->ny * e->ny + e->nz * e->nz;
    f32 r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(-1.0f), "f"(len2));
    f32 v = dot * r * (t * 0.7f + 0.3f);
    s32 i;
    if (flag == 0) {
        v = -v;
    }
    if (v < 0.0f) {
        v = 0.0f;
    }
    for (i = 0; i < 3; i++) {
        s32 q = (s32)(((e->b[i] * v + e->a[i] * t) * 128.0f) * inv);
        if (q >= 0x81) {
            q = 0x80;
        }
        mask |= q << (i * 8);
    }
    return mask;
}
