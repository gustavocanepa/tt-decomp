/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec4 {
    union {
        u128 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec4() {}
    float &operator[](int i) { return (&f.x)[i]; }
    Vec4(const Vec4 &o) { q = o.q; }
    void sub3(const Vec4 &o)
    {
        (*this)[0] -= o.f.x;
        (*this)[1] -= o.f.y;
        (*this)[2] -= o.f.z;
    }
};

struct Circle {
    Vec4 pos;
    float radius;
};

static inline float sqrtf_(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline Vec4 sub3d(Vec4 a, const Vec4 &b)
{
    a.sub3(b);
    return a;
}

static inline float length3d(Vec4 v)
{
    return sqrtf_(v.f.x * v.f.x + v.f.y * v.f.y + v.f.z * v.f.z);
}

extern "C" float func_003EA778(Circle *c, Vec4 *p)
{
    return length3d(sub3d(*p, c->pos)) - c->radius;
}
