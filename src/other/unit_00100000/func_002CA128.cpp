typedef int s32;
typedef float f32;

struct Sub {
    char pad0[0x1044];
    f32 angle;
};

struct Obj {
    char pad0[0x32790];
    f32 level;
    char pad1E64C[0x6C];
    Sub sub;
};

extern "C" void func_002CA128(Obj *self, s32 on) {
    Sub *p = &self->sub;
    p->angle = (on && self->level < 1.0f) ? 90.0f : 0.0f;
}
