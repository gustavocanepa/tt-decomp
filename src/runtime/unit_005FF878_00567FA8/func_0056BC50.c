#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0043D3B8(s32, s32);                    /* extern */

s32 func_0056BC50(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = arg0;
    var_s0 = arg2;
    if (var_s1 != arg1) {
        do {
            if (var_s0 != 0) {
                func_0043D3B8(var_s0, var_s1);
            }
            var_s1 += 8;
            var_s0 += 8;
        } while (var_s1 != arg1);
    }
    return var_s0;
}
