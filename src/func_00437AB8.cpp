extern "C" int func_004389E0(void *s, unsigned n);
extern "C" void func_00438148(void *s, int a, int b, float t, float *x, float *y, float *z, int c, int d);
extern int D_00586590[];

extern "C" int func_00437AB8(void *s, float px, float py, float t) {
    float best = 100.0f;
    int res = 6;
    int i;
    for (i = 0; i < 3; i++) {
        int v = D_00586590[i];
        int r = func_004389E0(s, v);
        if (r == v) {
            float a[3];
            float d, e, d2, sq;
            func_00438148(s, r, 0, t, &a[0], &a[1], &a[2], 0, 0);
            d = a[0] - px;
            e = a[1] - py;
            a[0] = d;
            a[1] = e;
            d2 = d * d + e * e;
            __asm__("sqrt.s %0, %1" : "=f"(sq) : "f"(d2));
            if (sq < best) {
                best = sq;
                res = r;
            }
        }
    }
    return res;
}
