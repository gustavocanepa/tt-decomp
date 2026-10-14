/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { int f0; char p4[0x34 - 4]; void *f34; };
struct Self {
    char p0[8];
    float f8, fC, f10, f14, f18, f1C;
    char p20[0x48 - 0x20];
    float f48;
    Cam *f4C;
};
struct Glob { char p[0x18]; char *f18; };
extern Glob *D_0058493C;
extern char D_005F88C0[];
extern "C" void func_003CD750(float *, float, float, float) throw();
extern "C" int func_003CDE08(float *, int, float) throw();
extern "C" void func_0046AC48(void *);
extern "C" void func_0046D810(int, void *, void *, void *, int, int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" int *func_00473980(int);
extern "C" void func_004752F8(float *);
extern "C" void func_00475440(float *);

extern "C" void func_003CDF20(Self *self) {
    float m[16];
    float v[3];
    int s2 = 1;
    func_004752F8(m);
    v[0] = -m[12];
    v[1] = -m[13];
    v[2] = -m[14];
    func_00473050();
    func_003CD750(m, self->f8, self->fC, self->f10);
    m[12] = self->f14;
    m[13] = self->f18;
    m[14] = self->f1C;
    func_00475440(m);
    float d = (self->f14 - v[0]) * m[4] + (self->f18 - v[1]) * m[5] + (self->f1C - v[2]) * m[6];
    if (!(d < 0.0f)) s2 = 0;
    int *s1 = func_00473980(1);
    int c = func_003CDE08(&m[4], s2, self->f48);
    s1[0] = c;
    s1[1] = c;
    s1[2] = c;
    s1[3] = c;
    Glob *g = D_0058493C;
    if (g) func_0046AC48(g->f18 + self->f4C->f0 * 0x28);
    func_004702D8(0x64, 1.0f);
    func_0046D810(4, self->f4C->f34, D_005F88C0, s1, 0, 0);
    func_004730A8();
    if (g) func_0046AC48(g->f18);
    func_004702D8(0x68, 1.0f);
}
