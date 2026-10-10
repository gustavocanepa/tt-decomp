#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00464018();                                /* extern */

s32 func_004640A0(f32 fparg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(func_00464018() < (fparg0 + 1.0f))) {
        var_v0 = 0;
    }
    return var_v0;
}
