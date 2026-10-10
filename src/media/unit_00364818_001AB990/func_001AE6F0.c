#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AF278(s32, s32);                    /* extern */
s32 func_001AFC20(s32, s32, s32);                   /* extern */

s32 func_001AE6F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;

    temp_s0 = func_001AFC20((arg1 * 0x2750) + arg0 + 0x540, arg2, arg3);
    func_001AF278(arg0, arg1);
    return temp_s0;
}
