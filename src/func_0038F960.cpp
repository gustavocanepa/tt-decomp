/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;
static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern f32 D_005F78F4;

extern "C" void func_0038F960(char *out, f32 f) {
    if (f <= 0.0f || f == D_005F78F4) {
        out[0] = 0x7F;
        out[1] = 0x7F;
        out[2] = 0x7F;
        out[3] = 0x2E;
        out[4] = 0x7F;
        out[5] = 0;
        return;
    }
    f = minf(maxf(f, 0.0f), 999.9f);
    s32 v = (s32)(f * 10.0f + 0.5f);
    out[0] = v / 1000 + 0x30;
    v %= 1000;
    out[1] = v / 100 + 0x30;
    v %= 100;
    out[3] = 0x2E;
    out[2] = v / 10 + 0x30;
    out[4] = v % 10 + 0x30;
    out[5] = 0;
}
