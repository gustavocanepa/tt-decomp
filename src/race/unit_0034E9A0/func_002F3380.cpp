typedef short s16;
typedef float f32;

struct Obj {
    char pad0[0xFC];
    f32 unkFC;
};

extern "C" f32 func_002F32C0(Obj *self, s16 a, s16 b);

extern "C" f32 func_002F3380(Obj *self, s16 a, s16 b) {
    f32 v = func_002F32C0(self, a, b);
    f32 limit = self->unkFC + 1.0f;
    if (limit < v)
        v = limit;
    return v;
}
