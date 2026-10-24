/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned long u64;

struct V12 { char d[12]; };
struct Obj {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    char pad10[0xE8 - 0x10];
    s32 uE8;
    char padEC[0x148 - 0xEC];
    s32 u148;
    char pad14C[0x168 - 0x14C];
    u64 u168;
    char pad170[0x180 - 0x170];
    s32 u180;
    void *u184;
    V12 m188;
    V12 m194;
    V12 m1A0;
    V12 m1AC;
    s32 u1B8;
    f32 f1BC;
    char pad1C0[0x2EC - 0x1C0];
    union { s32 i; f32 f; } m2EC;
};
struct Arg { char pad[0x10]; s32 u10; };

extern "C" void func_00321898(Obj *) throw();
extern "C" void func_0032DE18(void *);
extern "C" void func_0032DF18(void *, f32, f32);
extern "C" void func_0032E2F8(void *, void *, f32, f32, f32);

extern "C" void func_0032C0E0(Obj *arg0, Arg *arg1) {
    f32 t;

    func_00321898(arg0);
    arg0->u148 = 0xD;
    arg0->u180 = arg1->u10;
    arg0->m2EC.i = 0;
    t = arg0->m2EC.f;
    arg0->f1BC = t;
    func_0032E2F8((char *)arg0 + 0x1C0, arg0->u184, t, t, 0.1f);
    arg0->u1B8 = -1;
    arg0->f8 = 100.0f;
    arg0->fC = 60.0f;
    arg0->u168 &= 0xFFFFFFFF00FFFFFFul;
    arg0->uE8 = 1;
    func_0032DE18(&arg0->m188);
    func_0032DE18(&arg0->m194);
    func_0032DF18(&arg0->m1A0, t, t);
    func_0032DF18(&arg0->m1AC, t, t);
}
