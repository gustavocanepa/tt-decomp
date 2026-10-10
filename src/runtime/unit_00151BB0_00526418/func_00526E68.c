#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00526E68(s32 arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 1;
    if (M2C_FIELD(((arg1 * 0x64) + arg0), f32 *, 0x2C) == 0x0.0p+0f) {
        var_v1 = 0;
    }
    return var_v1;
}
