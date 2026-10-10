struct Target;
extern "C" void func_002661E8(Target *t, int a);
extern "C" void func_00266380(Target *t, int a, int b, int c, float f);

struct Ref {
    Target *p;
    Target *operator->() const { return p; }
    operator Target *() const { return p; }
};

struct Obj {
    char pad[0x14];
    Ref target;
};

extern "C" void func_001EED20(Obj *o, int a, int b, int c, int d, float f)
{
    func_002661E8(o->target, a);
    func_00266380(o->target, b, c, d, f);
}
