#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F40F8(s32 arg0) {
    s32 temp_v1;
    s32 var_a0;

    var_a0 = arg0 & 0xFF;
    temp_v1 = (arg0 >> 8) & 0x7FFFFF;
    if ((temp_v1 == 0) || (temp_v1 != *(s32 *)(0x78B120 + (var_a0 * 4)))) {
        var_a0 = -1;
    }
    return var_a0;
}
