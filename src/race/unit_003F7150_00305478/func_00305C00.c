#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s16 func_00305C00(s32 arg0, s32 arg1) {
    if (arg1 >= 6) {
        arg1 = 0;
    }
    return M2C_FIELD(((arg1 * 2) + arg0), s16 *, 0x54);
}
