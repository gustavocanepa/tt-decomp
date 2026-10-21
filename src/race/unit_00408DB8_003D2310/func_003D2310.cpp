/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline void clamp(float *v) {
    float lo = -0x1.41b2f4p+1f, hi = 0x1.41b2f4p+1f;
    float r = *v;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(r), "f"(lo));
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(r), "f"(hi));
    *v = r;
}
extern "C" float func_003D2310(int k, float x) {
    float v;
    if (k == 0) v = x + -0x1.e28c6ep+0f;
    else v = x + 0x1.e28c6ep+0f;
    clamp(&v);
    if (k == 0 && v > -0x1.2d97c6p+0f) v = -0x1.2d97c6p+0f;
    else if (k == 1 && v < 0x1.2d97c6p+0f) v = 0x1.2d97c6p+0f;
    return v;
}
