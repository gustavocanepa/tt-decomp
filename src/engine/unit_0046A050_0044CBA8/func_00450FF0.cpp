typedef float f32;

struct Quat {
    f32 x, y, z, w;
};

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" void func_00450FF0(const Quat *q, Vec4 *out, f32 w4) {
    f32 x = q->x;
    f32 y = q->y;
    f32 z = q->z;
    f32 w = q->w;
    out->w = w4;
    f32 ox = 2.0f * (x * y - z * w);
    f32 oz = 2.0f * (y * z + x * w);
    f32 oy = 2.0f * (0.5f - z * z - x * x);
    out->x = ox;
    out->y = oy;
    out->z = oz;
}
