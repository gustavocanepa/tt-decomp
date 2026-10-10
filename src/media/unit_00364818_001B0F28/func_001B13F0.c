#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041ECD0(s32);                         /* extern */

s32 func_001B13F0(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 != 0) {
        func_0041ECD0(arg1);
        var_v0 = 1;
    }
    return var_v0;
}
