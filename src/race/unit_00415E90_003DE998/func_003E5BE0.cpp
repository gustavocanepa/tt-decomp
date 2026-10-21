/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float maxf(float a, float b) {
    float r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
static inline float minf(float a, float b) {
    float r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
static inline float clamp(const float &v, const float &lo, const float &hi) {
    return minf(maxf(v, lo), hi);
}
extern "C" float func_003E5BE0(const float *v, float lo, float hi) {
    return clamp(*v, lo, hi);
}
