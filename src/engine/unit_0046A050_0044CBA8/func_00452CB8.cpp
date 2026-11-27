/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 rsqrtf_(f32 a, f32 b) { f32 r; __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Vec { f32 x, y, z; };
extern "C" void func_004514F0(Vec *, const Vec *, f32) throw();
extern "C" void func_00452C18(Vec *, const Vec *, const Vec *) throw();
extern "C" f32 func_004EE530(f32);

static inline const float &elem(const Vec *p, const int &i) { return *(const float *)((const char *)p+i); }
static inline void cross(Vec *o, const Vec *a, const Vec *b) {
 float x=elem(a,4)*b->z-elem(a,8)*b->y;
 float y=elem(a,8)*b->x-a->x*b->z;
 float z=a->x*b->y-elem(a,4)*b->x;
 o->x=x; o->y=y; o->z=z;
}
static inline float dot(const Vec *a, const Vec *b) {
 const float &x=b->x, &y=b->y, &z=b->z;
 float bx=x, ax=a->x;
 float by=y, ay=a->y;
 float bz=z, az=a->z;
 return ax*bx+ay*by+az*bz;
}
extern "C" void func_00452CB8(Vec *out, const Vec *a, const Vec *b) {
    const Vec *bb = b;
    Vec axis;
    f32 ang;
    f32 d = dot(a,b);
    if (d + 1.0f > 0.0f) {
        cross(&axis,a,b);
        f32 inv = rsqrtf_(1.0f, axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
        axis.x = axis.x * inv;
        axis.y = axis.y * inv;
        axis.z = axis.z * inv;
        ang = 1.5707963f - func_004EE530(minf(maxf(d, -1.0f), 1.0f));
    } else {
        Vec fb;
        Vec *fp = &fb;
        fp->x = 1.0f;
        fb.y = 0.0f;
        fb.z = 0.0f;
        func_00452C18(&axis, bb, fp);
        ang = 0x1.921fb4p+1f;
    }
    func_004514F0(out, &axis, ang);
}
