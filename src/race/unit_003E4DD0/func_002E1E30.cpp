/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

struct V3 { f32 x, y, z; };
struct V2 { f32 u, v; };
struct Plane { f32 a, b, c, d; };
struct Self {
    char pad[0x1C];
    V2 *uv;
    V3 *vert;
    Plane *plane;
};
struct Out { f32 x, y, z, u, v; };

extern "C" f32 func_002E1E30(Self *self, Out *out, s32 i) {
    V3 *p0 = &self->vert[i];
    Plane *pl = self->plane;
    s32 j = (i + 1) & 3;
    V3 *p1 = &self->vert[j];
    V2 *t0 = &self->uv[i];
    V2 *t1 = &self->uv[j];
    f32 x = p0->x, y = p0->y;
    f32 dx = p1->x - x;
    f32 dy = p1->y - y;
    f32 du = t1->u - t0->u;
    f32 dv = t1->v - t0->v;
    f32 t = -(x * pl->a + y * pl->b + p0->z * pl->c + pl->d) / (dx * pl->a + dy * pl->b);
    out->x = x + t * dx;
    out->y = p0->y + t * dy;
    out->z = p0->z;
    out->u = t0->u + t * du;
    out->v = t0->v + t * dv;
    return t;
}
