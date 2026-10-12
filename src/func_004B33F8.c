#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_006191A0[];
u32 func_004B33F8(u32 arg0) {
    s32 temp_v0;
    u32 var_a1;
    u32 var_a2;
    u32 var_a3;

    var_a2 = arg0;
    var_a1 = 0;
    var_a3 = 0;
    do {
        temp_v0 = var_a1 ^ var_a2;
        var_a2 = var_a2 >> 8;
        var_a3 += 1;
        var_a1 = (var_a1 >> 8) ^ *(s32 *)(D_006191A0 + ((temp_v0 & 0xFF) * 4));
    } while (var_a3 < 4U);
    return var_a1;
}
