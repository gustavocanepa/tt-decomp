#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0040FB88();                                /* extern */
s32 func_0040FBB0(s32);                             /* extern */

s32 func_0040FB40(s32 arg0) {
    s32 var_v1;

    var_v1 = func_0040FB88();
    if (var_v1 == -1) {
        var_v1 = func_0040FBB0(arg0);
    }
    return var_v1;
}
