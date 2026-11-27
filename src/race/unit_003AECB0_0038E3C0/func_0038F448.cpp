#include "types.h"

extern int D_00579518;

extern "C" f32 func_0038F448(int flags, f32 x, f32 width) {
    if ((flags & 4) && D_00579518) {
        f32 shift = 96.0f;
        if (flags & 8)
            x += shift;
        else
            x -= shift;
    }
    f32 half = width * 0.5f;
    flags &= 3;
    switch (flags) {
    case 0:
        return x;
    case 1:
        return x - width;
    default:
        return x - half;
    }
}
