typedef unsigned int u128 __attribute__((mode(TI)));
union Vec4 { struct { float x, y, z, w; } f; u128 q; };
struct Out { Vec4 a; Vec4 b; };
extern "C" const char *func_003D8FF0(const char *, float *);

extern "C" const char *func_003D9138(Out *o, const char *p)
{
    Vec4 a;
    p = func_003D8FF0(p, &a.f.x);
    p = func_003D8FF0(p, &a.f.y);
    p = func_003D8FF0(p, &a.f.z);
    o->a.q = a.q;
    Vec4 b;
    Vec4 *pb = &b;
    p = func_003D8FF0(p, &pb->f.x);
    p = func_003D8FF0(p, &pb->f.y);
    p = func_003D8FF0(p, &pb->f.z);
    p = func_003D8FF0(p, &pb->f.w);
    o->b.q = pb->q;
    return p;
}
