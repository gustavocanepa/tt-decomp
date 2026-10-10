/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_005CE0D8[];
extern char D_005CE5A0[];
extern char D_005CE408[];
extern char D_005CE270[];

struct SubA {
    void *vtbl;
    int m4;
    void init() { vtbl = D_005CE5A0; m4 = 0; }
};

struct SubB {
    void *vtbl;
    int m4;
    int m8;
    void init() { vtbl = D_005CE270; m8 = 0; }
};

struct Geo {
    void *vtbl;
    SubA a;
    void *vtblC;
    SubB b;
    int m1C;
};

extern "C" void func_00342650(Geo *self, int a, int b, int c);

extern "C" void CarGeometry__structor_0(Geo *self, int a, int c) {
    self->vtbl = D_005CE0D8;
    self->a.init();
    self->vtblC = D_005CE408;
    self->b.init();
    self->m1C = 0;
    return func_00342650(self, a, 0, c);
}
