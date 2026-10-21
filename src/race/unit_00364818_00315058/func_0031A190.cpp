typedef int s32; typedef float f32;

struct Input { char pad0[0x30]; f32 x, y; };
struct Obj {
    char pad0[0x34];
    f32 f34;
    char pad38[4];
    f32 f3C;
    char pad40[0x20];
    f32 vec60[3];
    f32 pos[2];
    f32 f74;
    s32 i78;
    char pad7C[4];
    s32 i80;
    char pad84[0xCC - 0x84];
    f32 fCC;
};

extern "C" f32 func_00317438(f32);
extern "C" void func_00318E60(Obj *, f32, f32);
extern "C" void func_00319A68(Obj *, f32 *, f32 *, f32 *, s32);
extern "C" f32 func_004A5C50(f32);
extern "C" f32 func_004A5D18(f32);
extern "C" void func_00552A68(f32 *, f32 *);

extern "C" void func_0031A190(Obj *self, Input *in) {
    f32 sp[8];
    f32 *p = self->pos;
    f32 *v = self->vec60;
    f32 k = self->fCC;
    f32 sc = k / 45.0f;
    f32 b = (in->y + in->y) * sc;
    f32 a = (in->x + in->x) * sc;
    sp[0] = k;
    func_00552A68(p, &sp[4]);
    f32 ang = -self->f74 * 0x1.921fb4p+1f / 180.0f;
    f32 s = func_004A5D18(ang);
    f32 c = func_004A5C50(ang);
    f32 t = a * c + b * s;
    b = a * -s + b * c;
    a = t;
    if (b != 0.0f || a != 0.0f) {
        if (self->i78 < 22) self->i78++;
        f32 r = (f32)self->i78 / 22.0f;
        b *= r;
        a *= r;
    } else {
        self->i78 = 0;
    }
    p[0] = p[0] + a;
    p[0] = func_00317438(p[0]);
    f32 *pp = p + 1;
    *pp = *pp + b;
    if (*pp < -30.0f) *pp = -30.0f;
    if (*pp > 45.0f) *pp = 45.0f;
    func_00319A68(self, sp, p, v, self->i80);
    f32 *q = &self->f34;
    func_00552A68(v, q);
    func_00318E60(self, *q, self->f3C);
}
