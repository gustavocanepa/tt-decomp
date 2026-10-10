#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_001FFD00(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0xD0) = arg2;
    if (arg2 != 0) {
        M2C_FIELD(((arg1 * 2) + arg0), s16 *, 0xC4) = 1;
    }
}
