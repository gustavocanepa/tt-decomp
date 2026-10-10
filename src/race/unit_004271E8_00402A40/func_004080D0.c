#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

u64 func_00408170(s32);
s32 func_004080D0(s32 arg0, s32 arg1, s32 arg2) {
    return M2C_FIELD(((arg1 * 8) + arg0), u64 *, 0x4B8) == func_00408170(arg2);
}
