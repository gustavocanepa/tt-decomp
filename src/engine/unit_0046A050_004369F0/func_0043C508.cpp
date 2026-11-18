/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float absval(float v) { return v < 0.0f ? -v : v; }
extern "C" int func_0043C508(float x, float y, float z, float w, float bx, float by) {
    x -= bx;
    float dx = z - bx;
retry:
    {
        float a = y - by;
        float b = w - by;
        int first = absval(x) <= a;
        int second = absval(dx) <= b;
        if (first) {
            if (second)
                return absval(x) + absval(a) < absval(dx) + absval(b);
            return 1;
        }
        if (second) return 0;
        if (by != -1000.0f) goto again;
        return a < b;
    }
again:
    by = -1000.0f;
    goto retry;
}
