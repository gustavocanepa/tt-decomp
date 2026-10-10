struct Limits;

extern Limits D_00583690;

extern "C" float func_0030E650(Limits *l);

struct Obj {
    char pad0[16];
    float value;
    unsigned char locked;
};

extern "C" void func_002E4AE0(Obj *o, float v) {
    if (o->locked)
        return;
    Limits *l = &D_00583690;
    if (func_0030E650(l) < v)
        o->value = func_0030E650(l);
    else
        o->value = v;
}
