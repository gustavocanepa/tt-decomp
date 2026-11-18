/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x, y, z; };
struct V4 { float x, y, z, w; };
struct Mat { V4 r0, r1, r2, r3; };

extern "C" void func_0041B098(Vec3 *, Vec3 *, Vec3 *) throw();

static inline float rsqrt_s(float one, float s) {
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(one), "f"(s));
    return r;
}

static inline void norm(V4 *out, V4 *in)
{
    float x = in->x, y = in->y, z = in->z;
    float i = rsqrt_s(1.0f, x * x + y * y + z * z);
    out->x = x * i;
    out->y = y * i;
    out->z = z * i;
}

extern "C" void func_0041B100(Mat *m, V4 *p, V4 *q, V4 *r)
{
    V4 u, d;
    V4 *r2 = &m->r2;
    V4 *r3 = &m->r3;
    V4 *r1 = &m->r1;
    float one = 1.0f;
    d.x = q->x - p->x;
    d.y = q->y - p->y;
    d.z = q->z - p->z;
    u.x = r->x - p->x;
    u.y = r->y - p->y;
    u.z = r->z - p->z;
    norm(&m->r0, &d);
    func_0041B098((Vec3 *)r2, (Vec3 *)&m->r0, (Vec3 *)&u);
    norm(r2, r2);
    func_0041B098((Vec3 *)r1, (Vec3 *)r2, (Vec3 *)&m->r0);
    m->r0.w = 0;
    r1->w = 0;
    r2->w = 0;
    r3->x = p->x;
    r3->y = p->y;
    r3->z = p->z;
    r3->w = one;
}
