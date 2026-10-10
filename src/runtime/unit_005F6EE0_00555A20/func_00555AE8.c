#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00555AE8(s32 arg0, s32 arg1, s8 arg2) {
    M2C_FIELD((arg1 + arg0), s8 *, 0xC0) = arg2;
}
