#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00200068(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0xF8) = arg2;
}
