#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00344500();                              /* extern */

s32 func_00343A78(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return M2C_FIELD(func_00344500(), s32 *, 0x3B00);
}
