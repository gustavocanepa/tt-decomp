#include "types.h"

#define ORDER(a, b) do { if ((b) < (a)) { f32 t_ = (a); (a) = (b); (b) = t_; } } while (0)

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Sample {
    unsigned short sub : 3;
    unsigned short time : 13;
    unsigned short pad;
    short value;
    short value2;
};

struct Curve {
    Sample samples[2][0x4000];
    int counts[2];
    f32 step;
};

extern "C" f32 func_001176B0(const Curve *c, int track);

extern "C" f32 func_001178A0(const Curve *c, int track, f32 lo, f32 hi) {
    ORDER(lo, hi);
    f32 res = 0.0f;
    f32 m = func_001176B0(c, track);
    if (!(m < lo) && !(hi < 0.0f)) {
        const Sample *row = c->samples[track];
        int i0 = (int)(maxf(lo, 0.0f) / c->step);
        int i1 = (int)(minf(hi, m) / c->step);
        u32 v = row[i0].time;
        for (int i = i0 + 1; i <= i1; i++) {
            u32 t = row[i].time;
            if (t < v) v = t;
        }
        res = (f32)v / 40.0f;
    }
    return res;
}
