#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_003418B0(s32, f32);                        /* extern */
void *func_00341AD8();                              /* extern */

struct func_00341BE8_temp_s0 {
    char pad0[0x38];
    f32 unk38;
};

f32 NormalCarGeometry__getSeatY(s32 arg0, s32 arg1, f32 fparg0) {
    struct func_00341BE8_temp_s0 *temp_s0;

    if (arg1 != 0) {
        return M2C_FIELD(func_00341AD8(), f32 *, 0x38);
    }
    temp_s0 = func_00341AD8();
    return temp_s0->unk38 + func_003418B0(arg0, fparg0);
}
