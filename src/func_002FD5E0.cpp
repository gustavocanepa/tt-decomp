/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tab { short n; float *y; float *x; };
extern "C" float func_002FD5E0(Tab *t, float v) {
    int n = t->n;
    float *x = t->x;
    if (v <= x[n-1]) return t->y[n-1];
    float *y = t->y;
    int i = n-1;
    float r = y[n-1];
    while (i > 0) {
        float yi = y[i];
        if (yi <= 0.0f) { r = 0.0f; break; }
        if (x[i-1] < v) {
            r = y[i-1];
        } else {
            float x0 = x[i];
            float t2 = (v-x0)/(x[i-1]-x0);
            r = y[i-1]*t2 + yi*(1.0f-t2);
            break;
        }
        i--;
    }
    return r;
}
