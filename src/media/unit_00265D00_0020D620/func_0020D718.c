#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0020D640();                                /* extern */
s32 func_0020D770(s32);                             /* extern */
s32 func_0020D9C8(s32);                             /* extern */

s32 func_0020D718(s32 arg0) {
    s32 var_s1;

    var_s1 = 0;
    if ((func_0020D640() != 0) && (func_0020D770(arg0) != 0)) {
        var_s1 = func_0020D9C8(arg0) == 0;
    }
    return var_s1;
}
