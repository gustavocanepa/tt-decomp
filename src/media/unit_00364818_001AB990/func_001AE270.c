#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4690(s32);                             /* extern */
s32 func_004ADE90(void **, s32, s32);            /* extern */

s32 func_001AE270(void **arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s0;

    if (*arg0 != 0) {
        return 0;
    }
    var_s0 = func_004A4690(0x40);
    if (var_s0 != 0) {
        func_004ADE90(arg0, var_s0, arg1);
    }
    return var_s0 != 0;
}
