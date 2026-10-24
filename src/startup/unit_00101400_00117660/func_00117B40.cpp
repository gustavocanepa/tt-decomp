#include "types.h"

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

#define ORDER(a, b) do { if ((b) < (a)) { f32 t_ = (a); (a) = (b); (b) = t_; } } while (0)

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

extern "C" f32 func_00117B40(const Curve *c, int track, f32 lo, f32 hi) {
    ORDER(lo, hi);
    f32 m = func_001176B0(c, track);
    f32 z = 0.0f;
    if (m < lo || hi < z) return z;
    int i0 = (int)(maxf(lo, z) / c->step);
    int i1 = (int)(minf(hi, m) / c->step);
    unsigned int total = 0;
    const Sample *row = c->samples[track];
    for (int i = i0; i <= i1; i++) total += row[i].time;
    return (f32)total / ((f32)(i1 - i0 + 1) * 40.0f);
}
