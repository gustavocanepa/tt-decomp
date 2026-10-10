#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B0908(s32, s32, s32, s32);          /* extern */

void func_001AE7E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001B0908((arg1 * 0x2750) + arg0 + 0x5A0, arg2, arg3, arg4);
}
