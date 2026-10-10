struct Params {
    int v[8];
};

extern "C" void func_002E45F8(Params *);
extern "C" float func_002FD3D0(void *obj, float x);
extern "C" float func_002F5050(void *table, Params *p);
extern char D_00582E98[];

extern "C" float func_002F3030(void *obj, Params *p, float x)
{
    Params def;
    func_002E45F8(&def);
    if (p == 0)
        p = &def;
    float a = func_002FD3D0(obj, x);
    return a * func_002F5050(D_00582E98, p);
}
