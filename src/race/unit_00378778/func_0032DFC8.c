#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_005357F8(s32);                             /* extern */

void func_0032DFC8(f32 *arg0, s32 arg1, f32 fparg0) {
    f32 var_f20;

    var_f20 = -*arg0;
    if (func_005357F8(arg1) < 0x1.9999980000000p-3f) {
        var_f20 += fparg0 * ((0x1.0000000000000p+1f * func_005357F8(arg1)) - 0x1.0000000000000p+0f);
    }
    *arg0 = var_f20 * 0x1.1111100000000p-3f;
}
