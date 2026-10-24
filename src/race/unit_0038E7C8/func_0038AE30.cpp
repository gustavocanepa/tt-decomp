/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Sub {
    char pad0[0x38];
    float f38;
    char pad3C[0xEF0 - 0x3C];
    float fEF0[4];
};

struct Self {
    char pad0[0x230];
    s32 f230;
    char pad234[4];
    s32 f238;
    Sub *f23C;
    float f240;
    float f244;
};

extern "C" void func_0038A4C8(float *out, float *in, float scale) throw();
extern "C" void func_0034DCA0(Sub *o);
extern "C" void func_0034E018(Sub *o, float a, float b);
extern "C" void func_0046F0F8(s32 a);
extern "C" void func_00473A08(s32 a, s32 b, void *c);
extern "C" void func_00473AD0(s32 a, void *b);
extern "C" void func_00478C98(s32 a);

extern "C" void func_0038AE30(Self *self) {
    float tmp[4];
    float inv = 1.0f / self->f23C->f38;
    func_0038A4C8(tmp, self->f23C->fEF0, inv);
    func_00473AD0(0, tmp);
    if (self->f238 != 0) {
        s32 id = 0x65;
        s32 i = 0;
        if (self->f230 > 0) {
            char *p = (char *)self;
            do {
                i++;
                func_0046F0F8(id);
                func_00473A08(id, 0xD, p);
                func_0038A4C8(tmp, (float *)(p + 0x10), inv);
                func_00473A08(id, 0, tmp);
                func_0038A4C8(tmp, (float *)(p + 0x20), inv);
                func_00473A08(id, 1, tmp);
                func_0038A4C8(tmp, (float *)(p + 0x30), inv);
                func_00473A08(id, 4, tmp);
                p += 0x50;
                id++;
            } while (i < self->f230);
        }
        if (i < 8) {
            do {
                s32 t = id;
                id++;
                i++;
                func_00478C98(t);
            } while (i < 8);
        }
    } else {
        func_0034E018(self->f23C, self->f240, self->f244);
    }
    func_0034DCA0(self->f23C);
}
