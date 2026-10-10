#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00341AD8(s32);                           /* extern */
s32 func_004172F0();                                /* extern */
f32 func_00417188(s32);                             /* extern */

f32 NormalCarGeometry__GetChairAngle(s32 arg0) {
    f32 var_f20;
    s32 temp_v0;

    temp_v0 = func_004172F0();
    if (temp_v0 != 0) {
        var_f20 = func_00417188(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    return M2C_FIELD(func_00341AD8(arg0), f32 *, 0x40) + var_f20;
}
