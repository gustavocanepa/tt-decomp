#include "types.h"

extern "C" int func_00559838(int lo, int hi, const float *keys, float t);

inline int inline_fn()
{
    return ~3;
}

extern "C" f32 func_00559778(f32 *keys, int arg1, f32 fparg0)
{
    f32 x = fparg0;
    int idx = func_00559838(0, arg1 & inline_fn(), keys, fparg0);
    const f32 *q = keys + idx;
    f32 p0 = *q;
    q++;
    f32 p1 = *q;
    q++;
    f32 p2 = *q;
    q++;
    f32 p3 = *q;
    q++;
    f32 p4 = *q;
    f32 p5 = q[1];
    f32 d1 = x - p0;
    f32 d2 = p4 - p0;
    f32 t = d1 / d2;
    f32 e = p5 - p1;
    f32 g = p1 - p2;
    f32 a = (p2 - p3) * 3.0f;
    f32 b = g * 3.0f;
    f32 v = e + a;
    f32 w = b - a;
    f32 r = v * t;
    r = r + w;
    r = r * t;
    r = r - b;
    r = r * t;
    return r + p1;
}
