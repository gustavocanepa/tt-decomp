typedef int s32;
typedef float f32;
struct Ptr { char p[0xE8]; s32 fE8; };
struct Self { char p0[0x1C]; f32 f1C; short s20; char p22[0x30 - 0x22]; void *f30; };
struct L {
    char a[0x5008];
    char b[0x6E0C - 0x5008];
    Ptr *c;
    char pad[0x6E90 - 0x6E10];
    s32 d0[4];
    s32 d1[4];
    s32 d2[4];
};
extern "C" void func_0043AF18(void *, s32);
extern "C" void func_0043B138(void *, void *, f32);
extern "C" void func_0043FE80(void *, s32, f32, void *, s32, s32);
extern "C" void *func_00568098(void *, void *, void *, void *);
extern "C" void func_00568140(void *, void *);
extern "C" void func_0043AE50(Self *self, s32 a1, s32 a2, f32 f) {
    L sp;
    f32 t = f * self->f1C;
    if (!((f32)self->s20 <= t)) {
        func_0043AF18(self, a1);
        func_0043FE80(&sp, a1, 0.0f, self, a2, 0);
        func_0043B138(self->f30, &sp, t);
        sp.d1[1] = sp.c->fE8;
        sp.d2[1] = (s32)sp.c;
        func_00568098(sp.d0, sp.b, sp.d1, sp.d2);
        func_00568140(sp.b, sp.c);
    }
}
