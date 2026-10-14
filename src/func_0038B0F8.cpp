typedef int s32;
typedef float f32;

struct Rec {
    f32 x;
    f32 y;
    f32 z;
    char pad[0x34];
    f32 w[4];
};

struct Self {
    f32 m[7 * 20];
    char pad230[0x8];
    s32 flag;
    char *obj;
    f32 f240;
    f32 f244;
};

struct Out {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" void *func_0034E420(void *, void *);

extern "C" void *func_0038B0F8(Self *self, Out *out, s32 idx) {
    if (self->flag != 0) {
        f32 k = -*(f32 *)(self->obj + 0xA78);
        out->x = self->m[idx * 20] * k;
        out->y = self->m[idx * 20 + 1] * k;
        out->z = self->m[idx * 20 + 2] * k;
    } else {
        func_0034E420(self->obj, out);
    }
    return out;
}
