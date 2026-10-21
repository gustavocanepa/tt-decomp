#include "types.h"
extern f32 D_0060BEBC;
static inline s32 bits(f32 f) { s32 i; __asm__("mfc1 %0,%1" : "=r"(i) : "f"(f)); return i; }
static inline f32 frombits(s32 i) { f32 f; __asm__("mtc1 %1,%0" : "=f"(f) : "r"(i)); return f; }
extern "C" f32 func_004A6008(f32 x) {
    if (x > 0.0f) {
        f32 num = -137.0f;
        f32 den = 30.0f;
        s32 i = bits(x);
        f32 f = frombits((i & 0x7FFFFF) | 0x3F800000);
        f32 f2 = f * f;
        f32 f3 = f * f2;
        f32 f4 = f2 * f2;
        f32 f5 = f2 * f3;
        num -= f * 1625.0f;
        den = f * 750.0f + den;
        num -= f2 * 2000.0f;
        den += f2 * 3000.0f;
        num += f3 * 2000.0f;
        den += f3 * 3000.0f;
        num += f4 * 1625.0f;
        den += f4 * 750.0f;
        num += f5 * 137.0f;
        den += f5 * 30.0f;
        return (f32)((i >> 23) - 0x7F) * 0x1.62e42ep-1f + num / den;
    }
    return D_0060BEBC;
}
