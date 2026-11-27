/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Out { f32 x0, x4, x8, xC, x10, x14; };
extern "C" {
f32 *func_003E73A0(f32 *, f32, f32, f32, f32, f32) throw();
s32 func_003E7410(Out *o, f32 a, f32 b, f32 c) {
    f32 sp0[4];
    if (a < 0.0f || b < 0.0f || c < 0.0f || a + b < c || b + c < a || c + a < b) return 0;
    f32 a2 = a * a;
    f32 b2 = b * b;
    f32 c2 = c * c;
    f32 *p4 = &o->x4;
    func_003E73A0(sp0, a, b, a2, b2, c2);
    o->x0 = sp0[0];
    func_003E73A0(sp0, b, c, b2, c2, a2);
    *p4 = sp0[0];
    o->x14 = c;
    o->xC = a;
    o->x10 = b;
    f32 t = (0x1.921fb4p+1f - o->x0) - sp0[0];
    o->x8 = t;
    sp0[0] = t;
    return 1;
}
}
