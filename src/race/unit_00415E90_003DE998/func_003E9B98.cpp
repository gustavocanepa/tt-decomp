struct Vec3 { float x, y, z; };
extern "C" void func_004A6328(float a, float *s, float *c);
static inline void sincos(const float &a, float *s, float *c) { func_004A6328(a, s, c); }

extern "C" void func_003E9B98(Vec3 *out, const float *angle, const Vec3 *in)
{
    float sc[4];
    float a = *angle;
    sincos(a, &sc[0], &sc[1]);
    float c = sc[1], s = sc[0];
    float z = in->z, y = in->y;
    out->x = in->x;
    out->y = y * c - z * s;
    out->z = y * s + z * c;

}
