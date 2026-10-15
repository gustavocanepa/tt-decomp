/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V4 { int a, b, c, d; };
struct V5 { int a, b, c, d, e; };
struct O {
    char pad[0x30]; int f30, f34, f38; char pad3C[0xC]; int f48, f4C, f50; char pad54[0xC];
    int f60; V4 f64; int f74, f78, f7C, f80; V5 f84; int f98, f9C, fA0, fA4;
};
extern "C" void func_0047EFD8(void *);
extern "C" void func_0047EA28(O *o) {
    V4 z;
    V5 t;
    z.a = 0; z.b = 0; z.c = 0; z.d = 0;
    o->f30 = 0;
    o->f34 = 0;
    o->f38 = 0;
    o->f48 = 0;
    o->f4C = 0;
    o->f50 = 0;
    o->f60 = 0;
    o->f64 = z;
    o->f74 = 2;
    o->f7C = 5;
    o->f78 = 0;
    o->f80 = 0;
    func_0047EFD8(&t);
    o->f84 = t;
    o->f98 = 0;
    o->f9C = 0;
    o->fA0 = 0;
    o->fA4 = 0;
}
