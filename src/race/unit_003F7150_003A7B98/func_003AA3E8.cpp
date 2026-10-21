/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P { float x, z; };
struct Seg {
    char pad0[6];
    unsigned short n;
    char pad8[8];
    P *pts;
    char pad14[4];
    float x, z;
    char pad20[0x20];
};
struct Tbl { char pad[0x1C]; Seg *segs; };
struct Mid { char pad[0xCC]; Tbl *tbl; };
struct Ctx { char pad[4]; Mid *mid; };
struct Out { float a, lo, hi; };
struct Pos { float x, y, z; };
extern "C" float func_00317438(float);
extern "C" float func_00317630(float, float);

static inline void update(Out *out, float v, float a) {
    float orig = v;
    if (a < v) v -= 360.0f;
    if (out->lo < v) out->lo = v;
    v = orig;
    if (v < a) v += 360.0f;
    if (v < out->hi) out->hi = v;
}

extern "C" void func_003AA3E8(Out *out, Ctx *ctx, Pos *pos, int idx) {
    int i = 0;
    Seg *s = &ctx->mid->tbl->segs[idx];
    float a = func_00317438(func_00317630(s->x - pos->x, s->z - pos->z) + 90.0f);
    out->lo = -360.0f;
    out->hi = 720.0f;
    out->a = a;
    if (s->n != 0) {
        do {
            P *p = &s->pts[i];
            i++;
            float v = func_00317438(func_00317630(p->x - pos->x, p->z - pos->z) + 90.0f);
            update(out, v, a);
        } while (i < s->n);
    }
}
