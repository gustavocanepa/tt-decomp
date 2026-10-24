#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003CBC30(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    s8 *dst;

    dst = (s8 *)(arg0 + 12);
    var_a2 = 0;
    do {
        temp_v0 = var_a2 * 4;
        var_a2 += 1;
        *(f32 *)(dst + temp_v0) = *(f32 *)(temp_v0 + arg1);
    } while (var_a2 < 0x10);
}
