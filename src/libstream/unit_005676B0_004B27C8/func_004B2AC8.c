#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s64 func_00504A80();                                /* extern */
s32 func_00535818(s32);                         /* extern */

extern char D_00773E60[];
s32 func_004B2AC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;

    temp_s0 = func_00535818((s32)D_00773E60);
    return temp_s0 + ((s64) (func_00504A80() << 0x20) >> 0x20);
}
