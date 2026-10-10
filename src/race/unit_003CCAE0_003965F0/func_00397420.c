#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00397420(s32 arg0, s32 arg1, s32 arg2) {
    return M2C_FIELD(((((arg1 * 4) + arg2) * 4) + arg0), s32 *, 0x9870);
}
