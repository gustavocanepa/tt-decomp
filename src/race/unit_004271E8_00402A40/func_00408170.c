#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0040FC80(s32, s32);                    /* extern */

s32 func_00408170(s32 arg0) {
    s32 var_v1;

    var_v1 = -1;
    if (arg0 != 0) {
        var_v1 = func_0040FC80(0x1D, arg0);
    }
    return var_v1;
}
