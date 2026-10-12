#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_004A5DE0(void *, s32, s32, s32, s32, s32, s32, s32, f32); /* extern */

void func_00317EA0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 fparg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((M2C_FIELD(arg0, f32 *, 0x14) * 0x1.4000000000000p+3f) / (0x1.0000000000000p+1f * func_004A5DE0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, (fparg0 * 0x1.0000000000000p-1f * 0x1.921fb40000000p+1f) / 0x1.6800000000000p+7f)));
}
