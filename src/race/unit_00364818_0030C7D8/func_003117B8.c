#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004A5C50(f32);                             /* extern */
f32 func_004A5D18(f32);                             /* extern */

f32 func_003117B8(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f21;
    f32 var_f0;
    f32 var_f1;
    f32 var_f21;

    temp_f21 = func_004A5D18(fparg2 * fparg0);
    var_f21 = temp_f21 + func_004A5C50(fparg2 * fparg1);
    if (arg0 != 0) {
        var_f0 = var_f21;
        if (arg0 == 1) {
            var_f1 = var_f21 * var_f21;
            if (var_f21 < 0.0f) {
                var_f1 = -var_f1;
            }
            var_f21 = var_f1;
            goto block_5;
        }
    } else {
block_5:
        var_f0 = var_f21;
    }
    return var_f0;
}
