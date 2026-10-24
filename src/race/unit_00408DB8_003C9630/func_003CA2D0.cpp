/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Hit {
    f32 x, y, z;
    s32 id;
    f32 f10;
    char pad14[0x30 - 0x14];
    u8 flag;
};

struct Plane {
    f32 nx, ny, nz, d;
};

struct Out {
    f32 t;
    f32 u;
    Plane pl;
    s32 id;
};

extern "C" void func_0034B3E0(s32, Hit *);
extern "C" void func_0034B590(s32, f32 *, s32 *, Plane *);

extern "C" s32 func_003CA2D0(s32 a, Hit *h, Out *o, f32 x, f32 y, f32 z) {
    s32 sp0;
    f32 v[3];
    Plane *pl = (Plane *)((char *)o + 8);
    f32 t;
    v[0] = x;
    v[1] = y;
    v[2] = z;
    sp0 = 0;
    func_0034B590(a, v, &sp0, pl);
    h->id = sp0;
    h->x = v[0];
    h->y = v[1];
    t = 0.0f;
    h->z = v[2];
    func_0034B3E0(a, h);
    if (h->flag != 0) {
        return 0;
    }
    if (pl->ny != 0.0f) {
        t = -(pl->nx * v[0] + pl->nz * v[2] + pl->d) / pl->ny;
    }
    o->t = t;
    o->id = sp0;
    o->u = h->f10;
    return 1;
}
