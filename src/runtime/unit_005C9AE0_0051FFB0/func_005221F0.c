#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001AF2E0(s32, s32);                        /* extern */

s32 func_005221F0(s32 arg0, s32 arg1, s32 arg2) {
    return func_001AF2E0(arg0, arg2) + (arg1 << 6) + 0x50;
}
