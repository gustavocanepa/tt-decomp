#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003404E0(s32);                             /* extern */
f32 func_004171B8(s32);                             /* extern */
s32 func_004172F0();                                /* extern */

f32 func_003406D0(s32 arg0, s32 arg1) {
    f32 temp_f20;
    s32 temp_v0;

    temp_v0 = func_004172F0();
    if (temp_v0 != 0) {
        temp_f20 = func_004171B8(temp_v0);
        return temp_f20 + M2C_FIELD((((arg1 ^ 1) * 0xC) + func_003404E0(arg0)), f32 *, 0xD0);
    }
    return M2C_FIELD((((arg1 ^ 1) * 0xC) + func_003404E0(arg0)), f32 *, 0xD0);
}
