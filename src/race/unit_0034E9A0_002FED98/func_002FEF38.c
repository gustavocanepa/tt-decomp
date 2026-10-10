#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_002FEF38(s32 arg0, s32 arg1, s8 arg2) {
    if (arg1 < 4) {
        M2C_FIELD((arg1 + arg0), s8 *, 0x7D0) = arg2;
    }
}
