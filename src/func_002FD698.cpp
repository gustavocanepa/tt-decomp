struct Tab { short n; float *xs; float *ys; };
extern "C" float func_002FD698(Tab *t, float x)
{
    float *xs = t->xs;
    unsigned last = t->n - 1;
    float a = xs[0];
    float b = xs[last];
    if (x <= a) return t->ys[0];
    if (b <= x) return t->ys[last];
    unsigned i = 1;
    while (i < last) {
        if (x < xs[i]) break;
        i++;
    }
    a = xs[i - 1];
    b = xs[i];
    float y0 = t->ys[i - 1];
    return y0 + ((x - a) * (t->ys[i] - y0)) / (b - a);
}
