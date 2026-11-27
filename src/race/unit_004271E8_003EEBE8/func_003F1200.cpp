struct Seg { char p[8]; float len; };
struct Ent { int p0; char *t4; char *t8; int p3; };
struct Rec { char p[4]; short a; short b; short c; int p2; };
struct A { char p[0x10]; Ent *tab; char q[8]; Rec *recs; };
struct St { float t; float dt; int idx; int pad; int loop; int arg; };
extern "C" float func_003F4AB8(char *l, float t);
extern "C" float func_003F0FA0(float t, float dt, Seg *s, int a) throw();

static inline Ent *entry(Ent *p, int i) { p += i; return p; }
static inline float wrap(float t, Seg *g) { float f = g->len; while (f <= t) t -= f; return t; }
static inline float wrap2(float t, float m) { while (m <= t) t -= m; return t; }
extern "C" int func_003F1200(A *self, St *s) {
    float t = s->t;
    float dt = s->dt;
    if (s->idx < 0) {
        t = 0.0f;
    } else {
        Rec *r = (Rec *)(s->idx * 16 + (int)self->recs);
        if (r->b >= 0) {
            t = t + dt;
            char *l = entry(self->tab, r->a)->t4 + (r->b << 5);
            if (s->loop != 0) {
                t = func_003F4AB8(l, t);
            } else {
                float f = *(float *)l;
                if (f < t) t = f;
            }
        } else {
            if (r->c >= 0) {
            Seg *g = (Seg *)(entry(self->tab, r->a)->t8 + (r->c << 5));
            t = func_003F0FA0(t, dt, g, s->arg);
            float f = g->len;
            if (f <= t) {
                if (s->loop != 0) {
                    while (g->len <= t) t -= g->len;
                    float z = 0.0f;
                    t = func_003F0FA0(t, z, g, s->arg);
                } else {
                    t = f;
                }
            }
            } else { return 0; }
        }
    }
    s->t = t;
    return 1;
}
