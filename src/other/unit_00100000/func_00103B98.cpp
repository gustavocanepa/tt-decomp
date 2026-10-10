struct Vec4 { float x, y, z, w; };
struct Obj { char pad[0x48]; float radius; };
extern "C" Vec4 func_00103798(Obj *o);

extern "C" Vec4 func_00103B98(Obj *o)
{
    Vec4 v = func_00103798(o);
    v.w = o->radius;
    return v;
}
