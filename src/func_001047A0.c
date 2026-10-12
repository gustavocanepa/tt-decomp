#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_005794DC[];
f32 func_001047A0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    f32 var_f0;
    s32 temp_v1;

    temp_v1 = *(s32 *)(s32)D_005794DC + 1;
    *(s32 *)(s32)D_005794DC = temp_v1;
    if (temp_v1 == 3) {
        *(s32 *)(s32)D_005794DC = 0;
    }
    var_f0 = 0x0.0p+0f;
    if (*(s32 *)(s32)D_005794DC == 0) {
        var_f0 = 0x1.4000000000000p+4f;
    }
    return var_f0;
}
