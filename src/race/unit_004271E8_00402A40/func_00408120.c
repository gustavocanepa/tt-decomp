#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s64 func_00408170(s32);                             /* extern */

void func_00408120(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(((arg1 * 8) + arg0), s64 *, 0x4B8) = func_00408170(arg2);
}
