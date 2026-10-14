extern "C" {
    extern char D_005CE0D8[];
    extern char D_005CE5A0[];
    extern char D_005CE408[];
    extern char D_005CE270[];
}

struct SpecialGeometry {
    void *vtbl;
    void *state;
};
struct NormalGeometry {
    void *vtbl;
    void *context;
    void *geometry;
};
struct CarGeometry {
    void *vtbl;
    SpecialGeometry special;
    void *baseVtbl;
    NormalGeometry normal;
    void *implementation;
};

extern "C" int func_00342650(CarGeometry *, void *, void *, void *);

extern "C" int CarGeometry__structor_1(CarGeometry *arg0, void *arg1, void *arg2) {
    arg0->vtbl = D_005CE0D8;
    SpecialGeometry *special = &arg0->special;
    special->vtbl = D_005CE5A0;
    special->state = 0;
    arg0->baseVtbl = D_005CE408;
    NormalGeometry *normal = &arg0->normal;
    normal->vtbl = D_005CE270;
    normal->geometry = 0;
    arg0->implementation = 0;
    return func_00342650(arg0, 0, arg1, arg2);
}
