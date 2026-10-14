struct Stream {
    int f0, f4, f8, fC, f10, f14;
    char pad18[0x20];
    int f38, f3C, f40;
    char pad44[12];
};
struct Info { char pad[0x18]; unsigned short cnt; };
struct Obj { char pad[0x2C]; Info *tbl[1]; };
extern "C" int func_00420718(Info *, int);
extern "C" int func_00463200(Stream *, int, int);
extern "C" int func_00463248(Stream *);
extern "C" float *func_004637E0(Stream *);
static inline char *more(Stream *s) { return s->f40 == 0 ? &s->pad18[16] : 0; }
static inline float fsqrt(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}
extern "C" int func_00425588(Obj *o, int idx, float *out)
{
    Info *info = o->tbl[idx / 2];
    if (!info) return 0;
    float maxabs = 0.0f;
    int i = 0;
    int n = info->cnt;
    float maxsq = 0.0f;
    float minsq = 100.0f;
    for (; i < n; i++) {
        Stream it;
        func_00463200(&it, func_00420718(info, i), 1);
        while (more(&it)) {
            float *p = func_004637E0(&it);
            float sq = p[1] * p[1] + p[2] * p[2];
            if (maxsq < sq) maxsq = sq;
            float ax = p[0];
            if (ax < 0.0f) ax = -ax;
            if (maxabs < ax) maxabs = ax;
            if (sq < minsq) minsq = sq;
            func_00463248(&it);
        }
    }
    out[0] = fsqrt(minsq);
    out[1] = fsqrt(maxsq);
    out[2] = maxabs;
    return 1;
}
