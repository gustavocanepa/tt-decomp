/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8; typedef short s16; typedef int s32; typedef float f32;

struct Src { char pad0[1]; u8 b1, b2, b3; s16 h4; s16 h6; u8 b8, b9, bA, bB; };
struct Dst {
    char pad0[4];
    f32 f4, f8, fC, f10, f14, f18;
    s32 i1C;
    f32 f20;
    char pad24[0xC];
    s32 i30;
    f32 f34, f38, f3C;
    char pad40[0xC];
    f32 f4C, f50;
};

extern "C" s32 func_002FD8A0(void *, s32, void *, void *, s32, s32);

extern "C" s32 GtbABC_SetupGlobal(Dst *d, Src *s, s32 a, s32 b) {
    f32 fb = (f32)b;
    d->f4 = (f32)s->b1 * 0x1.47ae14p-7f * 0x1.1df468p-6f;
    d->f8 = (f32)s->b2 * 100.0f;
    d->fC = (f32)s->b3;
    d->f14 = (f32)s->h4 * 1000.0f;
    d->i1C = 0;
    d->f18 = (f32)s->h6 * 1000.0f;
    d->f20 = fb;
    func_002FD8A0((char *)d + 0x24, 2, &d->f14, &d->i1C, 0, 0);
    d->f34 = (f32)(a + b);
    d->f10 = 1.0f / fb;
    d->i30 = 0;
    d->f38 = (f32)s->b8 / 100.0f;
    d->f3C = (f32)s->b9 / 100.0f;
    func_002FD8A0((char *)d + 0x40, 2, &d->i30, &d->f38, 0, 0);
    d->f4C = (f32)s->bA * 0x1.1df468p-6f / 100.0f;
    d->f50 = (f32)s->bB * 0x1.1df468p-6f / 100.0f;
    return func_002FD8A0((char *)d + 0x54, 2, &d->i30, &d->f4C, 0, 0);
}
