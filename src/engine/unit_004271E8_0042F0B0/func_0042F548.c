#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A8368(s32);                         /* extern */
s32 func_0050F4E8(s32, s32);                /* extern */

extern char D_00586204[];
s32 func_0042F548(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_0050F4E8(func_004A8368(*(s32 *)(s32)D_00586204) + 0x11, 0x40);
}
