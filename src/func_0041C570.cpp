/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Inner {
    char pad0[0x18];
    void *f18;
};

struct Self {
    Inner *inner;
};

extern "C" void *func_0041AB10(Self *) throw();
extern "C" void func_0041C308(float, float, Self *) throw();
extern "C" void func_0041C370(Self *) throw();
extern "C" void ModelSet2__begin(void *, void *);
extern "C" void ModelSet2__end(void *);
extern "C" void ModelSet2___render(void *, int, void *);
extern "C" void func_00473EF0(float, float, float, float);
extern "C" void func_00473F10(float, float, float, float);

extern float D_00769CF0[4];

extern "C" void func_0041C570(Self *self, s32 flag)
{
    void *s2 = 0;
    if (self->inner != 0) {
        s2 = self->inner->f18;
    }
    void *s0 = func_0041AB10(self);
    if (s2 != 0 && s0 != 0) {
        if (flag != 0) {
            func_0041C308(0x1.47ae14p-8f, 0x1.47ae14p-6f, self);
        }
        ModelSet2__begin(s2, s0);
        float *p = D_00769CF0;
        func_00473F10(p[0], p[1], p[2], 0.0f);
        func_00473EF0(1.0f, 1.0f, 1.0f, p[3]);
        ModelSet2___render(s2, 2, s0);
        ModelSet2__end(s2);
        if (flag != 0) {
            func_0041C370(self);
        }
    }
}
