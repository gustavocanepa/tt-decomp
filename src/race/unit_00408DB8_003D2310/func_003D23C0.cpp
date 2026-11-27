/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline f32 absf(f32 a) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(a)); return r; }

extern "C" void *func_004172F0();
extern "C" f32 func_00417D88(void *);
extern "C" f32 func_00417D98(void *);
extern "C" f32 func_00417DA8(void *);

extern "C" f32 func_003D23C0(f32 x) {
    f32 lim[2];
    lim[0] = 0x1.5fdbbcp+3f;
    lim[1] = 0x1.2d97c6p+5f;
    f32 s = 1.5f;
    if (func_004172F0() != 0) {
        s = func_00417D88(func_004172F0());
        lim[0] = func_00417D98(func_004172F0());
        lim[1] = func_00417DA8(func_004172F0());
    }
    return minf(maxf(absf(x) * s, lim[0]), lim[1]);
}
