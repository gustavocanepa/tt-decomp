#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_00341950(s32, f32);                        /* extern */
void *func_00341AD8(s32);                           /* extern */
s32 func_004172F0();                                /* extern */
f32 func_00417230(s32);                             /* extern */

struct func_00341C50_temp_s0 {
    char pad0[0x3C];
    f32 unk3C;
};

f32 NormalCarGeometry__getSeatZ(s32 arg0, s32 arg1, f32 fparg0) {
    f32 var_f20;
    s32 temp_v0;
    struct func_00341C50_temp_s0 *temp_s0;

    temp_v0 = func_004172F0();
    if (temp_v0 != 0) {
        var_f20 = func_00417230(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    if (arg1 != 0) {
        return M2C_FIELD(func_00341AD8(arg0), f32 *, 0x3C) + var_f20;
    }
    temp_s0 = func_00341AD8(arg0);
    return temp_s0->unk3C + func_00341950(arg0, fparg0);
}
