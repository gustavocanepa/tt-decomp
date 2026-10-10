#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_002D66F8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s64 *, 0xD008) = (s64) ((M2C_FIELD(arg0, s64 *, 0xD008) & ~0xFF) | (arg1 & 0xFF));
    if (arg1 == 0) {
        M2C_FIELD(arg0, s8 *, 0xD009) = -1;
    }
}
