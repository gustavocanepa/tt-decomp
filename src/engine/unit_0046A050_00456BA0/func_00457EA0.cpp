inline void *operator new(unsigned int, void *p) { return p; }
struct func_0045D2B0 {
    func_0045D2B0();
    char d[0x24];
};
struct Group {
    func_0045D2B0 e[3];
};
struct Obj {
    int m0;
    int m4;
    char pad[0x10F8 - 8];
    Group g[2];
};
extern "C" void func_00457EA0(Obj *o)
{
    o->m0 = 0;
    o->m4 = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            new (&o->g[i].e[j]) func_0045D2B0;
}
