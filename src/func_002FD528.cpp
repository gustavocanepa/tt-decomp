/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tab {
    short n;
    float *y;
    float *x;
};

extern "C" float func_002FD528(Tab *t, float v) {
    float *x = t->x;
    int n = t->n;
    if (v <= x[0]) {
        return t->y[0];
    }
    float *y = t->y;
    int n1 = n - 1;
    int i = 0;
    float r = y[0];
    while (i < n1) {
        float yi = y[i];
        if (0.0f <= yi) {
            r = 0.0f;
            break;
        }
        if (x[i + 1] < v) {
            r = y[i + 1];
        } else {
            float x0 = x[i];
            float t2 = (v - x0) / (x[i + 1] - x0);
            r = y[i + 1] * t2 + yi * (1.0f - t2);
            break;
        }
        i++;
    }
    return r;
}
