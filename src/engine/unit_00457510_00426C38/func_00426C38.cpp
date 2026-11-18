/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_00426C38(float x) {
    float q = (absf(x) + 0x1.921fb4p+1f) / 0x1.921fb4p+2f;
    int n = (int)q;
    if (n < 8) return x;
    q = (float)n;
    if (x < 0.0f) return x + q * 0x1.921fb4p+2f;
    return x + q * -0x1.921fb4p+2f;
}
