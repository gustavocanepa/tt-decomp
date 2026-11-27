/* expf: x = n*ln2 + r, exp(x) = 2^n * Taylor(r) to degree 8. */
extern float D_0060BEB8; /* +infinity returned on overflow */
static const float kLog2e = 1.4426950408889634;
static const float kLn2 = 0.6931471805599453;
static const float kInv2 = 0.5;
static const float kInv6 = 1.0 / 6.0;
static const float kInv24 = 1.0 / 24.0;
static const float kInv120 = 1.0 / 120.0;
static const float kInv720 = 1.0 / 720.0;
static const float kInv5040 = 1.0 / 5040.0;
static const float kInv40320 = 1.0 / 40320.0;
extern "C" float func_004A5EE8(float x) {
    int n = (int)(x * kLog2e);
    float r = x - (float)n * kLn2;
    float r2 = r * r;
    float r3 = r * r2;
    float r4 = r2 * r2;
    int e = n + 127;
    float s = r + 1.0f;
    s += r2 * kInv2;
    s += r3 * kInv6;
    s += r4 * kInv24;
    s += r2 * r3 * kInv120;
    s += r3 * r3 * kInv720;
    s += r3 * r4 * kInv5040;
    s += r4 * r4 * kInv40320;
    if (e >= 0) {
        if (e < 256) {
            float scale;
            __asm__("mtc1 %1, %0" : "=f"(scale) : "r"(e << 23));
            return s * scale;
        }
        return D_0060BEB8;
    }
    return 0.0f;
}
