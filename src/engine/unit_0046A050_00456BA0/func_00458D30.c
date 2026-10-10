#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00459950(s32, s32);                    /* extern */
s32 func_00459A38(s32);                             /* extern */

s32 func_00458D30(s32 arg0) {
    s32 temp_a1;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg0 + 0xA88;
    temp_a1 = func_00459A38(temp_s0) - 2;
    var_v0 = 1;
    if (temp_a1 >= 0) {
        func_00459950(temp_s0, temp_a1);
        var_v0 = -1;
    }
    return var_v0;
}
