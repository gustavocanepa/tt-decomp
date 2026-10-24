#include "types.h"

extern "C" void FlareClass__updateFlare(char *arg0, f32 fparg0) {
    char *a0p = arg0 + 0x10;
    char *b3 = arg0 + 0xC;
    s32 a1 = 0x2250;
    s32 a2 = 7;
    do {
        f32 *t = (f32 *)(a0p + a1);
        f32 *s = (f32 *)(b3 + a1);
        f32 sv = *s;
        a1 += 0x3C;
        f32 tv = *t;
        f32 v = tv + sv * fparg0;
        *t = v;
        if (v > 1.0f) {
            *t = v - 1.0f;
        }
        a2--;
    } while (a2 >= 0);
}
