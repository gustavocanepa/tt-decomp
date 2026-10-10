#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s16 func_00552E40(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 0x1B4) + arg0), s16 *, 0x1C);
}
