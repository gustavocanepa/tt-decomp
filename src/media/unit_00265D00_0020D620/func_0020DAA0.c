#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020D640(s32);                             /* extern */
s32 func_0020DBC8();                                /* extern */

s32 func_0020DAA0(s32 arg0) {
    s32 var_s1;

    var_s1 = 0;
    if (func_0020DBC8() != 0) {
        var_s1 = func_0020D640(arg0) != 0;
    }
    return var_s1;
}
