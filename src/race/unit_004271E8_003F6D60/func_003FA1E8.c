/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FA1A8(s32, s32, s32);           /* extern */

void func_003FA1E8(s32 arg0, s32 arg1, s32 arg2) {
    func_003FA1A8(arg1, arg0 + (arg2 * 0x30) + 0x18, 8);
}
