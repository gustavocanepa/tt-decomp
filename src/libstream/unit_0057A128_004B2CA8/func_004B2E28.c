#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B2E28(s32 arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v0;

    temp_a0 = arg0 & 0xFF;
    temp_v0 = (arg0 & 0x3F00) * 2;
    var_v0 = temp_v0 + 0x1F82;
    if (temp_a0 < 0x9F) {
        var_v0 = temp_v0 + 0x1EE0 + (temp_a0 < 0x7F);
    }
    return var_v0 + temp_a0;
}
