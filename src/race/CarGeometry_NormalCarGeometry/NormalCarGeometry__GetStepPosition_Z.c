#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_00341950(void *, f32);                     /* extern */
s32 func_00341AD8(void *);                          /* extern */
s32 func_004172F0();                                /* extern */
f32 func_004171D0(s32);                             /* extern */

struct NormalCarGeometry__virtual_09_arg0 {
    char pad0[0x4];
    s32 unk4;
};

f32 NormalCarGeometry__GetStepPosition_Z(struct NormalCarGeometry__virtual_09_arg0 *arg0, s32 arg1, f32 fparg0) {
    f32 var_f20;
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = func_004172F0();
    if (temp_v0 != 0) {
        var_f20 = func_004171D0(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    if (arg0->unk4 == 0) {
        return M2C_FIELD(((arg1 * 0xC) + func_00341AD8(arg0)), f32 *, 0x24) + var_f20;
    }
    temp_s0 = func_00341AD8(arg0);
    return M2C_FIELD(((arg1 * 0xC) + temp_s0), f32 *, 0x24) + func_00341950(arg0, fparg0);
}
