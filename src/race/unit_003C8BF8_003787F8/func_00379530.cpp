/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Point { float x, y; };
struct Skip { char pad[0x10]; int polygon, edge; };
extern "C" int func_00379530(int *arg0, int arg1, Point *arg2, Skip *arg3) {
    int n = arg0[0];
    Point *p, *q, *hi;
    int i;
    int inside;
    float *new_var;
    q = (Point *)((char *)arg0 + 4);
    i = 0;
    inside = 0;
    p = (Point *)((char *)arg0 + n * 8 - 4);
    if (n > 0) {
        do {
            if (arg1 != arg3->polygon || i != arg3->edge) {
                if ((*(new_var = &p->y)) != q->y) {
                    hi = q;
                    if (!(p->y < q->y)) { hi = p; p = q; }
                    if (p->y <= arg2->y) {
                        if (arg2->y < hi->y) {
                            float cr = ((arg2->x - p->x) * (hi->y - p->y)) - ((arg2->y - p->y) * (hi->x - p->x));
                            if (0.0f < cr) inside ^= 1;
                        }
                    }
                }
            }
            i++;
            p = q;
            q++;
        } while (i < arg0[0]);
    }
    return inside;
}
