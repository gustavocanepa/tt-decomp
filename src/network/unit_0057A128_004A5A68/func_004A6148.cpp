/* compiler: ee-gcc2.96-no-strict-aliasing */
inline float absolute(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
inline float toint(float x) { float r; __asm__("cvt.w.s %0, %1" : "=f"(r) : "f"(x)); return r; }
inline float fromint(float x) { float r; __asm__("cvt.s.w %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_004A6148(float x) {
    float guard = 8388608.0f;
    float a = absolute(x);
    float r = x;
    if (a < guard) {
        float t = fromint(toint(a));
        float u = t + 1.0f;
        if (t != a) {
            r = -t;
            if (x >= 0.0f) r = u;
        }
    }
    return r;
}
