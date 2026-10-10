#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_002E5EA0(f32);                             /* extern */
f32 func_002E5FC0(void *, f32);                     /* extern */

struct func_002E60B0_arg0 {
    char pad0[0x574];
    f32 unk574;
};

f32 func_002E60B0(struct func_002E60B0_arg0 *arg0, f32 fparg0) {
    f32 temp_f20;
    f32 temp_f21;
    f32 var_f0;

    temp_f20 = fparg0 + arg0->unk574;
    temp_f21 = func_002E5EA0(temp_f20);
    var_f0 = temp_f21 - func_002E5FC0(arg0, temp_f20);
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    return var_f0;
}
