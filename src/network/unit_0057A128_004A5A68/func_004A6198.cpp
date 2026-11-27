static inline float absolute(float x) {
    float a;
    __asm__("abs.s %0,%1" : "=f"(a) : "f"(x));
    return a;
}
static inline float round_word(float x) {
    float bits;
    __asm__("cvt.w.s %0,%1" : "=f"(bits) : "f"(x));
    return bits;
}
static inline float word_float(float bits) {
    float x;
    __asm__("cvt.s.w %0,%1" : "=f"(x) : "f"(bits));
    return x;
}
extern "C" float func_004A6198(float x) {
    float a=absolute(x);
    float result=x;
    if (a<8388608.0f) {
        float t=word_float(round_word(a));
        float negative=-1.0f-t;
        if (t!=a) {
            result=t;
            if (x<0.0f) result=negative;
        }
    }
    return result;
}
