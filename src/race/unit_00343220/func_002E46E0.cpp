struct Limits;

extern Limits D_00582E98;

extern "C" float func_002F4F90(Limits *l);

struct Obj {
    char pad0[4];
    float value;
    char pad[12];
    unsigned char locked;
};

extern "C" void func_002E46E0(Obj *o, float v) {
    if (o->locked)
        return;
    Limits *l = &D_00582E98;
    if (func_002F4F90(l) < v)
        o->value = func_002F4F90(l);
    else
        o->value = v;
}
