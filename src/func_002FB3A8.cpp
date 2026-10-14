static inline float fsqrt(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_004A5B78(float, float);

extern "C" void func_002FB3A8(float *out, float x, float y) {
    float d = fsqrt(y * y + x * x);
    if (d >= 0x1.638e36p+1f) {
        d = 1.0f;
    } else if (d <= 0x1.1c71c6p-2f) {
        d = 0.0f;
    } else {
        d = (d - 0x1.1c71c6p-2f) * 0x1.99999ep-2f;
    }
    *out = d;
    if (d != 0.0f) {
        return func_004A5B78(-y, x);
    }
}
