/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

extern "C" f32 func_00317630(f32, f32);

static inline f32 absf(f32 x) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" s32 func_0017DB58(f32 *arg0, f32 *arg1, f32 *arg2, f32 fp0, f32 fp1) {
    f32 h0 = fp0 * 0.5f;
    f32 h1 = fp1 * 0.5f;
    f32 y = *arg1 - h1;
    f32 x = *arg0 - h0;
    s32 r = 0;
    f32 t = func_00317630(x, y);
    *arg2 = t;
    t = absf(x / (h0 - 16.0f));
    if (t > 1.0f) {
        x /= t;
        r = 1;
        y /= t;
    }
    t = absf(y / (h1 - 16.0f));
    if (t > 1.0f) {
        x /= t;
        r = 1;
        y /= t;
    }
    *arg0 = x + h0;
    *arg1 = y + h1;
    return r;
}
