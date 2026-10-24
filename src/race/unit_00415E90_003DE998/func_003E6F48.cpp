/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline bool positive(float x) { return 0.0f < x; }
static inline bool isZero(float x) { return x == 0.0f; }
extern "C" int func_003E6F48(float x) {
    float t = (float)(int)x;
    float r = t;
    int v;
    if (positive(x) || isZero(x - t))
        v = (int)r;
    else
        v = (int)r - 1;
    return v;
}
