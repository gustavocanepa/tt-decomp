/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Limits {
    char pad0[0x38 + 0];
    f32 f38, f3C, f40, f44, f48, f4C, f50, f54, f58;
};
struct Info { char pad0[0xCC]; Limits *limits; };
struct Owner { char pad0[4]; Info *info; };

struct Cam {
    Owner *owner;
    int i4;
    f32 f8, fC, f10, f14, f18, f1C;
    int i20, i24;
    char u28[0xC];
    char u34[0xC];
    int i40;
    char pad44[4];
    char u48[0x18];
    char u60[0xC];
    char u6C[0xC];
    int i78[2];
    int i80, i84;
    char pad88[0x24];
    f32 fAC, fB0, fB4, fB8;
    int iBC;
    f32 fC0, fC4, fC8, fCC, fD0, fD4;
    f32 fD8, fDC, fE0;
    f32 fE4;
    int iE8;
    char padEC[0xC];
    f32 fF8;
    int iFC;
};

extern "C" void func_00317DE0(void *) throw();
extern "C" void func_00318ED8(void *, void *, int);
extern "C" void func_00319BB0(void *, int, void *, int);
extern "C" int func_003AA138(void *, Owner *, f32);
extern "C" int func_003AA540(f32 *, Owner *, int, f32);
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_00552A68(f32 *, f32 *);

extern "C" void func_00318478(Cam *c, Owner *owner, int a2) {
    f32 *p8 = &c->fD8;
    f32 *pC = &c->fDC;
    f32 *p0 = &c->fE0;
    c->f8 = 128.0f;
    c->fC = 128.0f;
    c->i4 = a2;
    c->owner = owner;
    c->f10 = 1.0f;
    c->f14 = 500.0f;
    c->f18 = 500.0f;
    c->f1C = 100.0f;
    c->i20 = 0;
    c->i24 = 0;
    func_004F6678(c->u28, 0, 0xC);
    func_004F6678(c->u34, 0, 0xC);
    c->i40 = -1;
    func_00317DE0(c->u48);
    func_004F6678(c->u60, 0, 0xC);
    func_004F6678(c->u6C, 0, 0xC);
    c->i80 = -1;
    c->fB0 = 0.0f;
    f32 z = c->fB0;
    c->fAC = 1.3f;
    c->fCC = 60.0f;
    c->fC4 = -360.0f;
    c->fC8 = 720.0f;
    c->i84 = -1;
    c->fB4 = 100.0f;
    c->fB8 = z;
    c->iBC = 0;
    c->fC0 = z;
    c->fD0 = 1.0f;
    c->fD4 = 1.0f;
    *p8 = 50.0f;
    *pC = z;
    *p0 = 100.0f;
    c->iE8 = -1;
    c->fE4 = z;
    func_00552A68(p8, (f32 *)((char *)c + 0xEC));
    c->fF8 = c->fE4;
    c->iFC = c->iE8;
    if (owner) {
        Limits *lim = c->owner->info->limits;
        f32 v[3];
        f32 vx = lim->f38;
        f32 vz = lim->f3C;
        v[0] = vx;
        v[1] = 100.0f;
        v[2] = vz;
        int r = func_003AA138(v, c->owner, z);
        if (r >= 0)
            func_00319BB0(c, r, v, 1);
        func_00318ED8(c, c->u60, r);
        f32 a = lim->f54 - lim->f4C;
        f32 b = lim->f58 - lim->f50;
        if (a <= 1.0f) a = 500.0f;
        if (b <= 1.0f) b = 500.0f;
        c->f14 = a;
        c->f18 = b;
        if (b < a) a = b;
        c->f1C = a;
        f32 wx = lim->f40;
        f32 wz = lim->f44;
        *p8 = wx;
        *pC = z;
        *p0 = wz;
        c->fE4 = lim->f48;
        int r2 = func_003AA540(p8, c->owner, c->i80, z);
        c->iE8 = r2;
        c->iFC = r2;
    }
}
