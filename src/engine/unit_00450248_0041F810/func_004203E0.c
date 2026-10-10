#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern f32 D_00585D30;
s32 func_004203E0(f32 fparg0) {
    f32 temp_f1;
    s32 var_v0;
    temp_f1 = D_00585D30;
    var_v0 = 0;
    if (!(temp_f1 < fparg0)) {
        var_v0 = 1;
        if (!((temp_f1 * 0.5f) < fparg0)) {
            var_v0 = 2;
            if (!((temp_f1 * 0.25f) < fparg0)) {
                var_v0 = 3;
            }
        }
    }
    return var_v0;
}
