/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tab { short n; short pad; float *v; float *k; };
struct Self { char p[0x6C]; Tab t; char q[0x1D9 - 0x6C - 12]; unsigned char m1D9; };
extern "C" float func_002F6D00(float *, float) throw();
extern "C" float func_002FD698(Tab *, float);

extern "C" float func_002F8538(Self *self) {
    if (self->m1D9) {
        Tab *t = &self->t;
        float r = 0.0f;
        float best = 0.0f;
        for (int i = 0; i < t->n; i++) {
            float k = t->k[i];
            if (best < k) {
                best = k;
                r = t->v[i];
            }
        }
        return r;
    }
    float best = 0.0f;
    int bi = 90;
    float base = 0.0f;
    for (int i = 0; i < 46; i++) {
        float out;
        float a = func_002F6D00(&out, (float)i * 0x1.1df468p-6f - base);
        float c = func_002FD698(&self->t, a) * out;
        if (best < c) {
            best = c;
            bi = i;
        }
    }
    return (float)bi * 0x1.1df468p-6f;
}
