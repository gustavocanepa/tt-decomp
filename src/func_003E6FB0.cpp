/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline bool negative(float x) { return x < 0.0f; }
static inline bool isZero(float x) { return x == 0.0f; }
extern "C" int func_003E6FB0(float x) {
    float t = (float)(int)x;
    float r = t;
    int v;
    if (negative(x) || isZero(x - t))
        v = (int)r;
    else
        v = (int)r + 1;
    return v;
}
