/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

struct Bar {
    char pad0;
    u8 b1;
    u8 b2;
    char pad3;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    f32 fC;
    char pad10[8];
    f32 f18;
    f32 f1C;
    char pad20[4];
    void *p24;
    void *p28;
    s32 i2C;
};

extern "C" void RaceSimpleBarMeter__render_bar(Bar *, s32, f32, f32, f32, f32, f32, f32);
extern "C" void func_0038F2A8(s32, s32, s32, s32);
extern "C" s32 func_0038F4A8(s32, s32, s32);
extern "C" s32 func_0038F5F8(void *, f32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_004702D8(s32, f32);
extern "C" void func_00477DC0(s32);

extern "C" void RaceSimpleBarMeter__render_main(Bar *self) {
    s32 x, y, w, h;
    func_0046F0F8(6);
    func_004702D8(0x44, 1.0f);
    x = func_0038F4A8(self->h4, self->h8, self->b1);
    y = func_0038F4A8(self->h6, self->hA, self->b2);
    func_00477DC0(func_0038F5F8(self->p24, self->fC));
    func_0038F2A8(x, y, self->h8, self->hA);
    s32 m = self->i2C;
    s32 d = m * 2;
    w = self->h8 - d;
    h = self->hA - d;
    y += m;
    x += m;
    RaceSimpleBarMeter__render_bar(self, func_0038F5F8(self->p28, self->fC), (f32)x, (f32)y, (f32)w, (f32)h, self->f18, self->f1C);
}
