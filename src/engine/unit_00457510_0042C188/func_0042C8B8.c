#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042C728(s32);                             /* extern */
void func_0042C848(s32, s32);                    /* extern */

s32 func_0042C8B8(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 != 0) {
        var_v0 = func_0042C728(arg1);
    }
    func_0042C848(arg0, var_v0);
    return arg0;
}
