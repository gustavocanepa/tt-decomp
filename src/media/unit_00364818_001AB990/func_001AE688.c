#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AF278(s32, s32);                    /* extern */
s32 func_001AFAC8(s32, s32, s32);               /* extern */

s32 func_001AE688(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;

    temp_s0 = func_001AFAC8((arg1 * 0x2750) + arg0 + 0x540, arg2, 0);
    func_001AF278(arg0, arg1);
    return temp_s0;
}
