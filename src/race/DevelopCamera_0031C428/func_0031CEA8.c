#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0031CEA8(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 0x1B4) + arg0), s32 *, 0x1AC);
}
