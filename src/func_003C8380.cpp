/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};

struct Obj {
    char pad0[0x10];
    float f10;
    char pad1[0x16C - 0x14];
    float v[3];
};

extern "C" void func_004519B0(Vec4 *v, float angle);
extern "C" void func_00450CB8(Vec4 *q, float *out, float *in);

extern "C" void func_003C8380(Obj *self, float *dir, float *off, float a, float b) {
    Vec4 q;
    float v[4];
    float r[4];
    float t[4];
    func_004519B0(&q, b);
    float *vp = v;
    func_00450CB8(&q, vp, dir);
    float *dst = self->v;
    float *t0 = &t[0];
    float *t1 = &t[1];
    float *t2 = &t[2];
    *t0 = *vp;
    t[1] = v[1];
    t[2] = v[2];
    *t0 += off[0];
    *t1 += off[1];
    *t2 += off[2];
    float *r0 = &r[0];
    *r0 = *t0;
    r[1] = *t1;
    float *r2 = &r[2];
    *r2 = *t2;
    dst[0] = *r0;
    dst[1] = r[1];
    dst[2] = r[2];
    self->f10 = a + b;
}
