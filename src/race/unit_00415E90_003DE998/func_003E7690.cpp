/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Out { f32 f0; f32 f4; f32 f8; f32 fC; f32 f10; f32 f14; };
struct F { f32 v; f32 p1, p2, p3; };
extern "C" {
f32 func_004A5D18(f32) throw();
s32 func_003E7690(Out *o, f32 *a, f32 *b, f32 f) {
    F l0;
    F l10;
    s32 r = 0;
    if (!(f < 0.0f)) {
        if (*a < 0.0f || *a > 0x1.921fb4p+1f || *b < 0.0f || *b > 0x1.921fb4p+1f) return r;
        f32 v21, v0;
        s32 ok = 1;
        l0.v = (0x1.921fb4p+1f - *b) - *a;
        if (!(l0.v > 0.0f)) ok = 0;
        if (ok) {
            F *p = &l10;
            p->v = l0.v;
            f32 t = f / func_004A5D18(p->v);
            p->v = *a;
            v21 = func_004A5D18(p->v) * t;
            p->v = *b;
            v0 = func_004A5D18(p->v) * t;
        } else {
            v21 = (f * l0.v) / 0x1.921fb4p+1f;
            v0 = f - v21;
        }
        o->fC = f;
        o->f10 = v21;
        o->f14 = v0;
        f32 v1 = *b;
        o->f4 = l0.v;
        o->f0 = v1;
        o->f8 = *a;
        r = 1;
    }
    return r;
}
}
