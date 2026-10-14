/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Obj {
    char pad0[4];
    s32 unk4;
};

struct Self {
    char pad0[1];
    u8 unk1;
    char pad2[2];
    s16 unk4;
    s16 unk6;
    char pad8[4];
    f32 unkC;
    char pad10[8];
    s32 unk18;
    char pad1C[0x68 - 0x1C];
    f32 unk68;
};

extern Obj D_00585CC8;
extern char D_005F57E0[];
extern "C" f32 RaceDisplayUtil__wideOffset(s32 flags);
extern "C" s32 func_0038F5F8(s32 a, f32 f);
extern "C" void func_00415510(void *o, const char *s);
extern "C" void func_00415578(void *o);
extern "C" void func_00415A10(void *o, f32 x, f32 y, f32 z);
extern "C" void func_00415B10(void *o, s32 v);
extern "C" void func_00415D18(void *o, const char *fmt, ...);

extern "C" void RaceGasMileageDisplay__render_main(Self *self) {
    char buf[8];
    s32 v;
    f32 x;
    func_00415510(&D_00585CC8, D_005F57E0);
    func_00415B10(&D_00585CC8, func_0038F5F8(self->unk18, self->unkC));
    D_00585CC8.unk4 = 2;
    v = (s32)(minf(maxf(self->unk68, 0.0f), 99.9f) * 10.0f + 0.5f);
    s32 q = v / 100;
    if (q > 0) {
        buf[0] = q + 0x30;
    } else {
        buf[0] = 0x20;
    }
    v %= 100;
    buf[1] = v / 10 + 0x30;
    buf[2] = 0x2E;
    buf[3] = v % 10 + 0x30;
    buf[4] = 0;
    x = (f32)self->unk4;
    func_00415A10(&D_00585CC8, x + RaceDisplayUtil__wideOffset(self->unk1), (f32)self->unk6, 0.0f);
    func_00415D18(&D_00585CC8, buf);
    D_00585CC8.unk4 = 0;
    func_00415578(&D_00585CC8);
}
