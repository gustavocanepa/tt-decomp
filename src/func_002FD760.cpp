/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tab {
    short n;
    float *x;
    float *y;
};

extern "C" int func_002FD760(Tab *a, Tab *b, float *o1, float *o2, float v) {
    float *x = a->x;
    unsigned n1 = a->n - 1;
    float *y1 = a->y;
    float *y2 = b->y;
    if (v <= x[0]) {
        *o1 = y1[0];
        *o2 = y2[0];
        return 1;
    }
    if (x[n1] <= v) {
        *o1 = y1[n1];
        *o2 = y2[n1];
        return 1;
    }
    unsigned i;
    for (i = 1; i < n1; i++) {
        if (v < x[i]) break;
    }
    float *py = y1 + i;
    float *px = x + i;
    float *pz = y2 + i;
    float ya = py[-1];
    float xa = px[-1];
    float py0 = py[0];
    float d = v - xa;
    float t1 = py0 - ya;
    float dx = px[0] - xa;
    *o1 = ya + d * t1 / dx;
    ya = pz[-1];
    float t2 = pz[0] - ya;
    *o2 = ya + d * t2 / dx;
    return 1;
}
