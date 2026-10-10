typedef float f32;

struct V4 { f32 x, y, z, w; };
struct M4 { f32 m[16]; };
extern "C" void func_00451270(V4 *, M4 *, f32, f32, f32);
extern "C" void func_00475440(M4 *);

extern "C" void func_003F3FC8(f32 x, f32 y, f32 z, f32 w) {
    M4 m;
    V4 v;
    V4 *p = &v;
    p->x = x;
    p->y = y;
    p->z = z;
    p->w = w;
    func_00451270(&v, &m, 0.0f, 0.0f, 0.0f);
    func_00475440(&m);
}
