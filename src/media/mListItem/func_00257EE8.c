#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00257198(s32, s32);                      /* extern */
s32 func_002571D8();                                /* extern */

s16 func_00257EE8(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < func_002571D8())) {
        return M2C_FIELD(func_00257198(arg0, arg1), s16 *, 0x1C);
    }
    return 0;
}
