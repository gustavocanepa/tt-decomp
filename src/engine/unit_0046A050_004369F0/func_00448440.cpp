#include "types.h"

struct Cursor {
    u8 *ptr;
};

extern "C" s32 func_00448440(Cursor *arg0) {
    u8 *p = arg0->ptr;
    s32 b3 = p[3] << 24;
    s32 b2 = p[2] << 16;
    s32 b1 = p[1] << 8;
    s32 b0 = p[0];
    s32 lo = b0 + b3;
    s32 hi = b2 + b1;
    arg0->ptr = p + 4;
    return lo + hi;
}
