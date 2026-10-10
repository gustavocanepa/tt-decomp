struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj;

extern "C" unsigned char *func_003D8FF0(unsigned char *p, void *out);
extern "C" unsigned char *func_003D9138(Obj *self, unsigned char *p);
extern "C" void func_003D9618(Obj *self, Vec4 *v);

extern "C" unsigned char *func_003D9710(Obj *self, unsigned char *p)
{
    Vec4 v;
    p = func_003D9138(self, p);
    p = func_003D8FF0(p, &v.x);
    p = func_003D8FF0(p, &v.y);
    p = func_003D8FF0(p, &v.z);
    func_003D9618(self, &v);
    return p;
}
