typedef short s16;
typedef float f32;

struct Obj_0038E158 {
    char pad0[0x1C];
    char *inner;
};

struct VE0_0038E158 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self);
};

struct VE1_0038E158 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self, f32 x);
};

static inline f32 call0_0038E158(Obj_0038E158 *self, int off) {
    char *o = self->inner;
    VE0_0038E158 *e = (VE0_0038E158 *)(*(char **)o + off);
    return e->fn(o + e->delta);
}

static inline f32 call1_0038E158(Obj_0038E158 *self, int off, f32 f) {
    char *o = self->inner;
    VE1_0038E158 *e = (VE1_0038E158 *)(*(char **)o + off);
    return e->fn(o + e->delta, f);
}

extern "C" f32 func_00342B80(Obj_0038E158 *self, f32 fparg) {
    if (call0_0038E158(self, 0xD0) == 0.0f) {
        if (call1_0038E158(self, 0xD8, fparg) == 0.0f) {
            if (call1_0038E158(self, 0xE0, fparg) == 0.0f)
                return 0.0f;
        }
    }
    return call1_0038E158(self, 0xD0, fparg);
}
