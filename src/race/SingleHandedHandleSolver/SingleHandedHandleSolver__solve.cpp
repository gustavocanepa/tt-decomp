/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ctx {
    char pad[0x120];
    int mode;
};

struct Self {
    int flag;
    char pad4[0x3C];
    float f40;
    char pad44[0x1C];
    float f60;
};

extern "C" void func_003DEDA0(Self *, float *, float *, Ctx *, float);
extern "C" void func_003DEE98(Self *, float *, float *, Ctx *, float);

static inline float fmaxs(float a, float b) {
    float r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
static inline float fmins(float a, float b) {
    float r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

static inline void clamp01(float *p) {
    *p = fmins(fmaxs(*p, 0.0f), 1.0f);
}

static inline int pick(Ctx *c, Self *s) {
    int m = c->mode;
    if ((m == 1 && !s->flag) || (m == 2 && s->flag)) return 1;
    return 0;
}

extern "C" void SingleHandedHandleSolver__solve(Self *self, float *a, float *b, Ctx *ctx, float x, float y) {
    float v = y;
    float t;
    if (v < 0.0f) v = -v;
    if (v > 0.5f) t = 2.0f * (1.0f - v);
    else t = 2.0f * v;
    clamp01(&t);
    float w = self->f60 * t;
    float p[4];
    float q[4];
    float r[4];
    if (v > 0.0f && v <= 1.0f) {
        if (pick(ctx, self)) {
            float *pp = p;
            float *qp = q;
            *pp = *a;
            *qp = *b;
            func_003DEE98(self, pp, qp, ctx, x);
            self->f40 = 0.5f - w / 3.1415927f;
            return;
        }
    }
    float *pp = p;
    float *rp = r;
    *pp = *a;
    *rp = *b;
    func_003DEDA0(self, pp, rp, ctx, x);
}
