/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Quat {
    f32 x, y, z, w;
};

struct Vec3 {
    f32 x, y, z;
};

extern "C" void func_0044DA00(const Quat *q, Vec3 *out) {
    f32 x = q->x;
    f32 y = q->y;
    f32 z = q->z;
    f32 w = q->w;
    f32 xx = x * x;
    f32 zz = z * z;
    f32 yw = y * w;
    f32 zw = z * w;
    f32 xy = x * y;
    f32 xz = x * z;
    out->x = 2.0f * (0.5f - (y * y) - zz);
    out->y = 2.0f * (xy + zw);
    out->z = 2.0f * (xz - yw);
}
