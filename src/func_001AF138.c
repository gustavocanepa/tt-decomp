#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001AF2E0(s32, M2C_UNK);                    /* extern */

f32 func_001AF138(s32 arg0, s32 arg1) {
    return M2C_FIELD((func_001AF2E0(arg0, 1) + (arg1 << 6)), f32 *, 0x8C);
}
