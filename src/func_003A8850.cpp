/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float frsq(float a, float b) {
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
struct Q { char p[0x14]; float f14; };
extern "C" float func_003A86D0(void *, void *) throw();
extern "C" float func_003A8850(void *a0, Q *q, void *a2, float p0, float p1, float p2, float p3)
{
    float r = frsq(p1 * 0x1.0624dcp-10f, p2 * p2 + 1.0f);
    float t21 = p3 * (r + r);
    float t20 = r * 0.5f * q->f14;
    float c = func_003A86D0(a0, a2);
    float sq = t20 * t20;
    float res = (c * ((t21 * p0 * t20) - sq)) / ((c * t21 * p0) - sq);
    return res < c ? c : res;
}
