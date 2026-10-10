#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003404E0();                                /* extern */

f32 func_00340690(s32 arg0, s32 arg1) {
    return M2C_FIELD((((arg1 ^ 1) * 0xC) + func_003404E0()), f32 *, 0xCC);
}
