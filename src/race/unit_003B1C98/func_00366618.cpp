/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Cam {
    char pad0[0x58];
    float p58, p5C, p60, s64;
};

struct Self {
    char pad0[8];
    s32 f8;
    float fC;
    float f10;
    float m[16];
};

extern "C" Cam *func_00342620(s32);
extern "C" void func_004A6328(float *, float *, float);

extern "C" void func_00366618(Self *self, s32 idx, float *o1, float *o2, float *o3) {
    float s0, s4, s8, sC;
    Cam *c = func_00342620(idx);
    float ang = self->fC;
    func_004A6328(&s8, &sC, self->f10);
    float nx = c->p58;
    nx = -nx;
    float ny = c->p5C;
    float nz = -c->p60;
    float t1 = nx * sC - ny * s8;
    nx *= s8;
    nx += ny * sC;
    func_004A6328(&s0, &s4, ang);
    float *m = self->m;
    *o1 = (t1 + c->p58) * c->s64;
    float ns8 = -s8;
    float ns0 = -s0;
    float yc = nx * s4;
    nx *= s0;
    float zs = nz * s4;
    ny = yc - nz * s0;
    nz = nx + zs;
    *o2 = (ny - c->p5C) * c->s64;
    *o3 = (nz + c->p60) * c->s64;
    m[0] = sC;
    m[4] = s8;
    m[8] = 0;
    m[12] = 0;
    m[1] = s4 * ns8;
    m[5] = s4 * sC;
    m[9] = s0;
    m[13] = 0;
    m[2] = ns8 * ns8;
    m[6] = sC * ns0;
    m[10] = s4;
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    m[15] = 1.0f;
    self->f8 = 1;
}
