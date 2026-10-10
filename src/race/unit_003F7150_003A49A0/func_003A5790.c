#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_003A5790(s8 *p, s32 i) {
    s8 *e = p + i * 0xF4;
    f32 r = *(f32 *)(e + 0x1AC) / *(f32 *)(*(s8 **)(p + 0x10) + (i >> 1) * 4 + 0x108C);
    if (1.0f < r) r = 1.0f;
    return r;

}
