#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_003404E0(s32);                           /* extern */
f32 func_00417200(s32);                             /* extern */
s32 func_004172F0();                                /* extern */

f32 func_003404F8(s32 arg0) {
    f32 temp_f20;
    s32 temp_v0;

    temp_v0 = func_004172F0();
    if (temp_v0 != 0) {
        temp_f20 = func_00417200(temp_v0);
        return temp_f20 + M2C_FIELD(func_003404E0(arg0), f32 *, 0x84);
    }
    return M2C_FIELD(func_003404E0(arg0), f32 *, 0x84);
}
