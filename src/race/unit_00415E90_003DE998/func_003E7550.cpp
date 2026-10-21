/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Out { f32 x0, x4, x8, xC, x10, x14; };
struct F { f32 v; f32 p1, p2, p3; };
extern "C" {
f32 *func_003E73A0(f32 *, f32, f32, f32, f32, f32) throw();
void func_004A6328(f32, f32 *, f32 *);
static inline f32 sqrtf_(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
s32 func_003E7550(Out *o, f32 *a1, f32 f22, f32 f21) {
    F l0;
    F l10;
    f32 sc[4];
    F l30;
    if (f22 < 0.0f || f21 < 0.0f || *a1 < 0.0f || *a1 > 0x1.921fb4p+1f) return 0;
    f32 x = *a1;
    {
        {
            {
                {
            F *p30 = &l30;
            F *p10 = &l10;
            p30->v = x;
            func_004A6328(x, &sc[0], &sc[1]);
            f32 t0 = f21 * sc[0];
            f32 f20 = (f21 * sc[1]) - f22;
            f20 = sqrtf_(f20 * f20 + t0 * t0);
            func_003E73A0(&p30->v, f21, f20, f21 * f21, f20 * f20, f22 * f22);
            f32 f2 = p30->v;
            f32 g = 0x1.921fb4p+1f - *a1;
            o->xC = f22;
            o->x10 = f21;
            o->x14 = f20;
            l0.v = f2;
            f32 f1 = g - f2;
            o->x0 = *a1;
            p10->v = f1;
            o->x8 = f1;
            o->x4 = l0.v;
                    return 1;
                }
            }
        }
    }
    return 0;
}
}
