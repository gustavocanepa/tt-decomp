/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Point { float x, y; };
struct Tab { int n; Point points[1]; };
extern "C" float func_003181E0(Tab *t, float x) {
    if (x <= 0.0f) x = 0.0f;
    if (x >= 1.0f) x = 1.0f;
    int lo = 0;
    int hi = t->n;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (x < t->points[mid].x) hi = mid;
        else lo = mid + 1;
    }
    hi = t->n - 1;
    int i = lo - 1;
    if (i >= hi) i = hi - 1;
    Point *a = &t->points[i];
    Point *b = &t->points[i + 1];
    return (b->y - a->y) * (x - a->x) / (b->x - a->x) + a->y;
}
