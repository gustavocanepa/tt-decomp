#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_00586EF0[];
extern char D_00586EF4[];
f32 func_00415820(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    f32 var_f1;

    var_f1 = M2C_FIELD(*(void **)D_00586EF4, f32 *, 0x3C);
    if (*(s32 *)D_00586EF0 != 0) {
        var_f1 *= 0x1.9999980000000p-1f;
    }
    return var_f1;
}
