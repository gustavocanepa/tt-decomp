/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x, y, z, w; };
struct A {
    float x, y, z;
    short n;
    short pad;
    V p[1];
};
struct V3 { float x, y, z; };
struct B {
    V3 a;
    V3 b;
    float pad;
    V3 c;
    float t;
};
extern "C" void func_00552A68(float *, float *);
extern "C" void func_00552C90(void *, void *);

extern "C" int func_003A9950(A *a, B *b) {
    V *e = a->p;
    float *s4 = &b->b.z;
    if (a->n < 0)
        e = e + a->n;
    float *s3 = &b->b.x;
    float ax = a->x;
    float az = a->z;
    float dx = e->x - ax;
    float dz = e->z - az;
    float u1 = dz * (*s3 - ax);
    float c1 = dx * (*s4 - az) - u1;
    if (c1 < 0.0f)
        return 0;
    float u2 = dz * (b->a.x - ax);
    float c2 = dx * (b->a.z - az) - u2;
    if (c2 > 0.0f)
        return 0;
    float n[3];
    func_00552A68(s3, n);
    func_00552C90(n, b);
    float bx = *s3;
    float bz = *s4;
    float *nz = &n[2];
    float n0 = n[0];
    float n2 = *nz;
    float u3 = n2 * (a->x - bx);
    if (n0 * (a->z - bz) - u3 < 0.0f)
        return 0;
    float u4 = n2 * (e->x - bx);
    if (n0 * (e->z - bz) - u4 > 0.0f)
        return 0;
    float t = c1 / (c1 - c2);
    n[0] = n0 * t;
    float *ny = &n[1];
    *ny *= t;
    *nz *= t;
    float *s0 = &b->c.x;
    func_00552A68(s3, s0);
    func_00552C90(s0, n);
    b->t = t;
    return 1;
}
