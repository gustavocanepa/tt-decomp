#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_0039D110(s32 arg0, s32 arg1) {
    if (M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x96B4) != 0) {
        M2C_FIELD(((arg1 * 0x8D0) + arg0), s32 *, 0xCA8) = 1;
    }
}
