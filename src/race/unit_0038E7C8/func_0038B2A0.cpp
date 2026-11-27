/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct V4 {
    float x, y, z, w;
};

static inline float frsq(float a, float b) {
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" void func_0046A0D8(s32 a, float *buf1, s32 b, s32 *buf2, s32 c, s32 d);
extern "C" float *func_00473980(s32 n);
extern "C" s32 func_00477D28(float a, float b, float c, float d, float e);

extern "C" void func_0038B2A0(V4 *dir, V4 *col, float alpha) {
    float one = 1.0f;
    float x = dir->x;
    float y = dir->y;
    float z = dir->z + one;
    float inv = frsq(one, x * x + y * y + z * z);
    float ny = y * inv;
    float nx = x * inv;
    float u = 0.0f;
    float v;
    float nv;
    float nu;
    s32 c1;
    s32 c0;
    float *b1;
    s32 *b2;
    float *p;
    s32 *q;
    s32 n;
    c1 = func_00477D28(col->x, col->y, col->z, col->w * alpha, 255.0f);
    c0 = func_00477D28(col->x, col->y, col->z, u, 255.0f);
    b1 = func_00473980(0x10);
    b2 = (s32 *)func_00473980(6);
    p = b1;
    q = b2;
    v = dir->w;
    n = 9;
    float s = -0x1.2cf230p-1f;
    float c = 0x1.9e3778p-1f;
    do {
        n--;
        *p++ = nx + u;
        *p++ = ny + v;
        *p++ = 0.0f;
        *p++ = nx;
        *p++ = ny;
        *p++ = 0.0f;
        *q++ = c0;
        *q++ = c1;
        nu = c * u - s * v;
        nv = s * u + c * v;
        u = nu;
        v = nv;
    } while (n >= 0);
    *p++ = nx + nu;
    *p++ = ny + nv;
    *p++ = 0.0f;
    *q = c0;
    func_0046A0D8(0x15, b1, 0, b2, 0, 0);
}
