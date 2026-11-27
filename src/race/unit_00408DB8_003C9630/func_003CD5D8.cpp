/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj {
    s32 a;
    f32 m;
    f32 w;
    f32 h;
    f32 inv;
    f32 diag;
    f32 k18;
    f32 k1c;
    f32 k20;
    f32 k24;
    f32 k28;
    f32 k2c;
    f32 k30;
    f32 *v;
};

extern "C" void func_003CD5D8(Obj *o, s32 a, f32 m, f32 w, f32 h) {
    f32 hw, hh, t, k, q, sq, u;
    o->m = m;
    hw = w * 0.5f;
    o->v = (f32 *)(((s32)o + 0x47) & ~0xF);
    hh = h * 0.5f;
    o->a = a;
    o->w = w;
    o->h = h;
    o->v[0] = -hw;
    t = w * -2.0f;
    u = (w + h) * -2.0f * 0.005f;
    k = m * 0x1.555554p-4f;
    o->v[1] = 0.0f;
    o->v[2] = -hh;
    o->v[3] = hw;
    o->v[4] = 0.0f;
    o->v[5] = -hh;
    o->v[6] = -hw;
    o->v[7] = 0.0f;
    o->v[8] = hh;
    o->v[9] = hw;
    o->v[10] = 0.0f;
    o->v[11] = hh;
    q = t * h;
    sq = w * w + h * h;
    {
        f32 s;
        __asm__("sqrt.s %0, %1" : "=f"(s) : "f"(sq));
        o->diag = s;
    }
    o->k18 = k * h * h;
    o->k1c = k * sq;
    o->inv = 1.0f / o->m;
    o->k20 = k * w * w;
    o->k2c = q * h * h / 12.0f * 0.015f;
    o->k30 = t * w * w * h / 12.0f * 0.015f;
    o->k24 = q;
    o->k28 = u;
}
