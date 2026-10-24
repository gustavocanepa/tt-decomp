/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pt { float x, y; };
struct Node { float len; Pt a,b,c,d; };
struct Vec { Node *begin; int count; };
struct Obj { float len; Pt a,b; Vec v; };
extern "C" Pt *func_00444C80(Pt *, const Pt *, const Pt *, float) throw();
static inline Node *beg(Vec *v) { return v->begin; }
static inline Node *end(Vec *v) { return v->begin + v->count; }
extern "C" int func_00446560(Obj *o, Pt *out, int max, float scale, float t) {
    Pt p, q, r;
    if (max < 2) return 0;
    Pt *limit = out + max;
    func_00444C80(&p, &o->a, &o->b, t);
    *out = p;
    Pt *start = out;
    Vec *v = &o->v;
    Node *last = end(v);
    Node *it = beg(v);
    out++;
    for (; it != last; it++) {
        func_00444C80(&q, &it->a, &it->b, t);
        func_00444C80(&r, &it->c, &it->d, t);
        int n = (int)(scale * it->len);
        if (n < 2) {
            *out = r;
            out++;
            if (out == limit) return max;
        } else {
            for (int i = 0; i < n; i++) {
                float u = (float)(i + 1) / (float)n;
                float c = u * u;
                u = 1.0f - u;
                float a = u * u;
                float b = (1.0f - c) - a;
                out->x = p.x * a + q.x * b + r.x * c;
                out->y = p.y * a + q.y * b + r.y * c;
                out++;
                if (out == limit) return max;
            }
        }
        p = r;
    }
    return out - start;
}
