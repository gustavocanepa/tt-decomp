/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F94B0(s32, s32, s32);           /* extern */

void func_003F94F0(s32 arg0, s32 arg1, s32 arg2) {
    func_003F94B0(arg1, arg0 + (arg2 * 0x2C) + 9, 8);
}
