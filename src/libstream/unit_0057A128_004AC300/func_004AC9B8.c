#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AC7F0();                                /* extern */
s32 func_004AC8B8(s32, s32);                    /* extern */

s32 func_004AC9B8(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = func_004AC7F0();
    if (var_v0 != 0) {
        func_004AC8B8(arg0, arg1);
        var_v0 = 1;
    }
    return var_v0;
}
