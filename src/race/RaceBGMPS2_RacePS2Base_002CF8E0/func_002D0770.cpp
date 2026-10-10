typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0xE3A4];
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    s32 dirty;
};

extern "C" void func_002D0770(Obj *self, f32 r, f32 g, f32 b, f32 a) {
    self->dirty = 1;
    self->g = g;
    self->b = b;
    self->a = a;
    self->r = r;
}
