/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Src { s32 m0; char pad[0x1C - 4]; f32 m1C; };
struct Obj {
    char pad0[0xDC];
    f32 mDC;
    f32 mE0;
    f32 mE4;
    s32 mE8;
    char pad1[0x148 - 0xEC];
    s32 m148;
    char pad2[0x150 - 0x14C];
    s32 m150;
    char pad3[0x180 - 0x154];
    s32 m180;
    s32 m184;
    s32 m188;
    char pad4[0x190 - 0x18C];
    s32 m190;
    s32 m194;
    s32 m198;
    s32 m19C;
    s32 m1A0;
    f32 m1A4;
};

extern "C" void func_00321898(void *) throw();

extern "C" void func_00325180(Obj *self, s32 unused, s32 a2, s32 a3, Src *t0, s32 t1, f32 f) {
    func_00321898(self);
    self->m148 = 2;
    self->m194 = a3;
    self->m190 = a2;
    self->m198 = (s32)t0;
    if (f <= 0.0f)
        f = 0.0f;
    if (f >= 1.0f)
        f = 1.0f;
    self->m1A4 = f;
    if (a2 != 0) {
        if (t0 != 0) {
            s32 v = t0->m0;
            self->m19C = v & 3;
            self->m1A0 = v & 0xC;
            if (v & 0x400)
                self->m1A4 = 1.0f;
            f32 g = t0->m1C;
            if (g < 1.0f)
                g = 8.0f;
            self->mE8 = 1;
            self->m184 = 1;
            self->m188 = t1;
            self->m180 = 0;
            self->m150 = (s32)(g * 100.0f);
            f32 *px = &self->mDC;
            f32 *py = &self->mE0;
            f32 *pz = &self->mE4;
            *px = *px + 0.0f;
            *py = *py + 0x1.999998p-2f;
            *pz = *pz + 0.0f;
        }
    }
}
