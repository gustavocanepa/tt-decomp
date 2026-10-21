/* compiler: ee-gcc2.96-no-strict-aliasing */
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
    Rec arr[7];
    char pad230[0x8];
    s32 flag;
    char *volatile obj;
    f32 f240;
    f32 f244;
};

struct Out {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern "C" f32 func_0034E1E8(void *, f32, f32);

extern "C" void *func_0038B180(Self *self, Out *out, s32 idx) {
    if (self->flag != 0) {
        out->x = self->arr[idx].w[0];
        out->y = self->arr[idx].w[1];
        out->z = self->arr[idx].w[2];
        out->w = self->arr[idx].w[3];
    } else {
        out->x = *(f32 *)(self->obj + 0xA60);
        out->y = *(f32 *)(self->obj + 0xA64);
        out->z = *(f32 *)(self->obj + 0xA68);
        out->w = *(f32 *)(self->obj + 0xA7C) * func_0034E1E8(self->obj, self->f240, self->f244);
    }
    return out;
}
