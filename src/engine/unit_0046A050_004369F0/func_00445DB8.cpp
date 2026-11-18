/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Seg { float k; float cx, cy; float ex, ey; };
struct Pt { float x, y; };
struct Vec { Seg *b; int n; };
struct Path { float pad; float x, y; Vec v; };

extern "C" int func_00445DB8(float scale, Path *p, Pt *o, int max) {
    if (max < 2) return 0;
    float px = p->x, py = p->y;
    o->x = px;
    o->y = py;
    Pt *end = o + max;
    Pt *base = o;
    Vec *v = &p->v;
    Seg *se = v->b + v->n;
    Seg *s = v->b;
    o++;
    for (; s != se; s++) {
        float k = s->k;
        float cx = s->cx, cy = s->cy;
        float ex = s->ex, ey = s->ey;
        int n = (int)(scale * k);
        if (n < 2) {
            o->x = ex;
            o->y = ey;
            o++;
            if (o == end) return max;
        } else {
            for (int i = 0; i < n; i++) {
                float t = (float)(i + 1) / (float)n;
                float t2 = t * t;
                t = 1.0f - t;
                t = t * t;
                float u2 = t;
                float c = 1.0f - t2 - u2;
                o->x = px * u2 + cx * c + ex * t2;
                o->y = py * u2 + cy * c + ey * t2;
                o++;
                if (o == end) return max;
            }
        }
        px = ex;
        py = ey;
    }
    return o - base;
}
