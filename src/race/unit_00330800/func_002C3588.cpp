struct Obj { int m0[4]; int m10, m14, m18, m1C; };
extern "C" void func_002C3618(Obj *);
extern "C" void func_002C3660(Obj *);

extern "C" void func_002C3588(Obj *o)
{
    if (o->m18 == 1 && o->m1C == 1) return;
    func_002C3618(o);
    if (o->m18 >= 2) func_002C3660(o);
    o->m10 *= o->m18;
    o->m14 *= o->m1C;
    o->m18 = 1;
    o->m1C = 1;
}
