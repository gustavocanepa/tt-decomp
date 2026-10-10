struct Vec2 { float x, y; };
extern "C" void func_004A6328(float a, float *s, float *c);
static inline void sincos(const float &a, float *s, float *c) { func_004A6328(a, s, c); }

extern "C" void func_003E9B20(Vec2 *out, const float *angle, const Vec2 *in)
{
    float sc[4];
    float a = *angle;
    sincos(a, &sc[0], &sc[1]);
    float c = sc[1], s = sc[0];
    float y = in->y, x = in->x;
    out->x = x * c - y * s;
    out->y = x * s + y * c;
}
