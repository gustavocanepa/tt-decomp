#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_00526E48(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 0x64) + arg0), f32 *, 0x28);
}
