/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Obj {
    f32 m0;
    f32 m4;
    f32 m8;
    f32 mC;
    f32 m10;
    f32 m14;
    f32 m18;
    f32 m1C;
    f32 m20;
};

extern "C" void func_0032E578(Obj *o, f32 target) {
    f32 d;
    f32 lim = o->mC;
    f32 old = o->m4;
    o->m4 = target;
    if (lim > 0.0f) {
        d = target - old;
        if (lim < __builtin_fabsf(d)) {
            if (d > 0.0f)
                target = old + lim;
            else
                target = old - lim;
            o->m4 = target;
        }
    }
    f32 v = o->m8;
    f32 cap = o->m20;
    f32 force = o->m10;
    d = o->m4 - o->m0;
    force *= d;
    f32 nv2 = v + (((force + (o->m14 * v)) / 60.0f) * o->m18);
    o->m8 = nv2;
    if (cap > 0.0f && cap < nv2)
        o->m8 = cap;
    f32 m = o->m1C;
    f32 w;
    if (m > 0.0f) {
        f32 n = -m;
        w = o->m8;
        if (w < n) {
            o->m8 = n;
            w = n;
        }
    } else {
        w = o->m8;
    }
    o->m0 = o->m0 + w / 60.0f;
}
