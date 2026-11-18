/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct RaceBattleTachometer {
    char pad0[1];
    u8 alignX;
    u8 alignY;
    char pad3[1];
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    float alpha;
    s32 initialized;
};

extern "C" void func_0038F210(float x0, float y0, float x1, float y1);
extern "C" s32 func_0038F4A8(s32 pos, s32 size, s32 align);
extern "C" s32 func_0038F5F8(s32 color, float alpha);
extern "C" void RaceBarMeter__render_main(RaceBattleTachometer *self, void *arg1);
extern "C" void func_0039E9A8(RaceBattleTachometer *self);
extern "C" void func_00477DC0(s32 color);

extern "C" void RaceBattleTachometer__render_main(RaceBattleTachometer *self, void *arg1) {
    if (self->initialized == 0) {
        func_0039E9A8(self);
    }
    RaceBarMeter__render_main(self, arg1);
    float x = (float)func_0038F4A8(self->x, self->w, self->alignX);
    float y = (float)func_0038F4A8(self->y, self->h, self->alignY) - 3.0f;
    float x2 = x + (float)self->w;
    float y2 = y + 2.0f;
    func_00477DC0(func_0038F5F8(0x70000099, self->alpha));
    func_0038F210(x + (float)self->w * 0x1.699998p-1f, y, x2 - 1.0f, y2);
}
