#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_001AF170(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(((arg1 * 0x2750) + arg0 + (arg2 << 7)), s32 *, 0x140) = arg3;
}
