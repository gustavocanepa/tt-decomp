#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00406B50(s32 arg0, s32 arg1) {
    return ((s32) M2C_FIELD(((arg1 >> 3) + arg0), u8 *, 0x4DC) >> (arg1 & 7)) & 1;
}
