/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float rsqrt_s(float a, float b) {
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
struct V4 { float x, y, z, w; };
static inline float get(const V4 *v, int i) { return ((const float *)v)[i]; }
struct M4 { V4 r0, r1, r2, r3; };
static inline void norm(V4 *v) {
    float k = rsqrt_s(1.0f, v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
    v->x *= k; v->y *= k; v->z *= k; v->w *= k;
}
static inline void cross(V4 *o, const V4 *a, const V4 *b) {
    o->x = get(a, 1) * get(b, 2) - get(a, 2) * get(b, 1);
    o->y = get(a, 2) * get(b, 0) - get(a, 0) * get(b, 2);
    o->z = get(a, 0) * get(b, 1) - get(a, 1) * get(b, 0);
}
extern "C" void func_001AAAD8(M4 *m, V4 *v) {
    m->r3.x = 0.0f;
    m->r3.w = 1.0f;
    m->r3.y = 0.0f;
    m->r3.z = 0.0f;
    V4 up;
    up.x = m->r3.x;
    up.y = 1.0f;
    up.z = m->r3.x;
    up.w = m->r3.x;
    m->r0.x = v->x;
    m->r0.y = v->y;
    m->r0.z = v->z;
    m->r0.w = v->w;
    norm(&m->r0);
    cross(&m->r2, &m->r0, &up);
    norm(&m->r2);
    cross(&m->r1, &m->r2, &m->r0);
    m->r1.w = up.x;
    m->r2.w = up.x;
}
