/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float fsqrt(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline void solve(float *o0, float *o1, float *o2, float p0, float p1, float p2, float p3) {
    float zero = 0.0f;
    float b = p1;
    *o0 = *o1 = *o2 = zero;
    if (b != zero && p3 != zero && p0 != zero && p2 != zero && !(p2 <= p0) && !(p3 <= b)) {
        p1 = b * p2 - p3 * p0;
        if (!(p1 <= zero)) {
            p0 = b * b * p2 - p3 * p3 * p0;
            if (!(p0 > zero)) {
                float product = b * p3;
                b = p3 - b;
                float q = p0 / (2.0f * p1);
                float u = (product * b) / p1;
                *o2 = fsqrt(u);
                float r = -(q * q) / u;
                *o0 = r;
                float w = fsqrt(-r);
                *o1 = -*o2 * w;
            }
        }
    }
}

extern "C" void func_003077C0(float *o0,float *o1,float *o2,float p0,float p1,float p2,float p3) { solve(o0,o1,o2,p0,p1,p2,p3); }
