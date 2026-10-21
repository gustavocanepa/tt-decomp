/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct H {
    char pad[0x18];
    void *m18;
};

struct Self {
    char pad0[1];
    u8 b1;
    u8 b2;
    char pad3;
    s16 x4;
    s16 x6;
    s16 w;
    s16 h;
    f32 fC;
    H *h10;
    char pad14[4];
    s32 h18;
    s32 h1C;
    f32 f20;
    f32 f24;
};

extern "C" void func_0035ACD0(Self *p);
extern "C" void func_0038E838(s32 h, u8 b1, u8 b2, f32 a, f32 b, f32 c, f32 d);
extern "C" void func_0038EE10(f32 x0, f32 y0, f32 x1, f32 y1, f32 u0, f32 v0, f32 u1, f32 v1);
extern "C" s32 func_0038F4A8(s32 x, s32 w, s32 fl);
extern "C" s32 func_0038F5F8(s32 c, f32 a);
extern "C" s32 func_00467728(void *p);
extern "C" void func_0046AC48(void *p);
extern "C" void func_00477DC0(s32 v);
extern "C" void func_00477E30(f32 a, f32 b, f32 c, f32 d);

extern "C" void RaceFuelMeter__render_main(Self *a) {
    f32 x0, y0, r, v;
    s32 k;

    if (a->h10 == 0) {
        func_0035ACD0(a);
    }
    func_00477E30(1.0f, 1.0f, 1.0f, a->fC);
    func_0038E838(a->h18, a->b1, a->b2, (f32)a->x4, (f32)a->x6, (f32)a->w, (f32)a->h);
    func_00477DC0(func_0038F5F8(a->h1C, a->fC));
    func_00467728(a->h10);
    func_0046AC48(a->h10->m18);
    x0 = (f32)func_0038F4A8(a->x4, a->w, a->b1);
    y0 = (f32)func_0038F4A8(a->x6, a->h, a->b2);
    r = minf(maxf(a->f20 / a->f24, 0.0f), 1.0f);
    k = (s32)(r * 10.0f + 0.5f);
    v = (f32)k * 5.2f + 15.0f;
    if (k >= 6) {
        v += 4.0f;
    }
    func_0038EE10(x0, y0, x0 + v, y0 + 11.0f, 0.0f, 0.0f, v * 0.0078125f, 0.6875f);
}
