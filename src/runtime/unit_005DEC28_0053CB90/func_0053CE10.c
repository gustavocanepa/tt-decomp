void func_0053CE10(float *p, float *end, float *src) {
    for (; p != end; p += 2) { float *q = src + 1; p[0] = *src; p[1] = *q; }
}
