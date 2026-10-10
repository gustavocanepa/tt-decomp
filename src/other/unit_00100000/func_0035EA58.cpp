typedef int s32;
typedef float f32;

struct Self { char pad[0x10]; f32 rate; char pad2[4]; s32 mode; };
extern f32 D_005F57D8;

extern "C" void func_0035EA58(Self *self, f32 t) {
    if (t <= 0.0f) self->rate = D_005F57D8;
    else self->rate = 0x1.000000p+0f / t;
    self->mode = 2;
}
