typedef short s16;
typedef float f32;

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *self, f32 *out, f32 zero);
};

struct VEntryF {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self);
};

struct Obj {
    char *vtbl;
};

extern "C" f32 func_004170D8(Obj *self) {
    f32 v[16];
    VEntryV *e1 = (VEntryV *)(self->vtbl + 0x38);
    e1->fn((char *)self + e1->delta, v, 0.0f);
    VEntryF *e2 = (VEntryF *)(self->vtbl + 0x70);
    return e2->fn((char *)self + e2->delta) * v[0] * 0.5f;
}
