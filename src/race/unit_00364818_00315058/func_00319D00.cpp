/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
typedef int s32; typedef float f32;

struct Link { char pad0[0x18]; void *p18; };
struct Obj {
    char pad0[4];
    Link *link;
    char pad8[0x60 - 8];
    f32 f60[3];
    f32 f6C, f70;
    char pad74[0xCC - 0x74];
    f32 fCC, fD0, fD4, fD8[3];
};

extern "C" f32 func_002E5EA0(void *, f32);
extern "C" f32 func_003173B0(void *);
extern "C" f32 func_003173F8(void *);
extern "C" f32 func_003174F8(f32, f32);
extern "C" f32 func_00552A38(f32 *);
extern "C" void func_00552A68(f32 *, f32 *);
extern "C" void func_00552C90(void *, void *);

static inline f32 fsqrt(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" s32 func_00319D00(Obj *self) {
    f32 v[3];
    f32 w[3];
    f32 *wx = w;
    f32 *pos = self->f60;
    s32 ok = 1;
    f32 one = 1.0f;
    f32 lim = self->fCC * 0.5f;
    void *l = self->link->p18;
    func_00552A68(self->fD8, v);
    f32 t0 = func_002E5EA0(l, 0.0f);
    f32 *vy = &v[1];
    *vy = t0 + 0.9f;
    func_00552C90(v, pos);
    f32 ang1 = func_003173B0(v);
    *vy = 0.0f;
    f32 len = -fsqrt(func_00552A38(v));
    f32 *wy = &w[1];
    f32 *wz = &w[2];
    *wx = one;
    *wy = 0.0f;
    *wz = len;
    f32 e1 = func_003173F8(w);
    len = -fsqrt(func_00552A38(v));
    *wx = 0.5f;
    *wy = 0.0f;
    *wz = len;
    f32 e2 = func_003173F8(w);
    f32 d1 = absf(func_003174F8(func_003173F8(v), self->f6C)) - e1;
    if (d1 < 0.0f) d1 = 0.0f;
    f32 d2 = __builtin_fabsf(func_003174F8(ang1, self->f70)) - e2;
    if (d2 < 0.0f) d2 = 0.0f;
    if (lim / self->fD0 < d1) ok = 0;
    if (lim / self->fD4 < d2) ok = 0;
    return ok;
}
