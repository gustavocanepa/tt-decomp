#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00317438();                                /* extern */

f32 func_003174B8(void) {
    f32 var_f1;

    var_f1 = func_00317438();
    if (var_f1 > 180.0f) {
        var_f1 -= 360.0f;
    }
    return var_f1;
}
