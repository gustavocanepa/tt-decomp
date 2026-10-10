static inline int isNegative(float x) { return x < 0.0f; }
static inline int isZero(float x) { return x == 0.0f; }

extern "C" int func_003E7018(float x)
{
    float t = (float)(int)x;
    float r = t;
    if (isNegative(x) || isZero(x - t))
        return (int)r - 1;
    return (int)r;
}
