#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B1428(s32, s32, s32);               /* extern */

void func_001AE940(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001B1428((arg1 * 0x2750) + arg0 + 0xF58, arg2, arg3);
}
