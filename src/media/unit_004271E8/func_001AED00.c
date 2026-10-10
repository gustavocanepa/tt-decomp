#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AFF00(s32);                             /* extern */
s32 func_001B13E8(s32);                             /* extern */
s32 func_0041CF28(s32, s32, s32);               /* extern */

s32 func_001AED00(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s1;
    s32 var_v0;

    temp_s0 = (arg1 * 0x2750) + arg0;
    temp_s1 = func_001B13E8(temp_s0 + 0xF58);
    var_v0 = func_001AFF00(temp_s0 + 0x5A0);
    if (var_v0 != 0) {
        func_0041CF28(temp_s0 + 0x600, arg2, temp_s1);
        var_v0 = 1;
    }
    return var_v0;
}
