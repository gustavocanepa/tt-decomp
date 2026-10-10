/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002DC820(s32, s32, s32, s32, s32, s32); /* extern */

void func_002C8C38(s32 arg0, s32 arg1) {
    func_002DC820(arg1, arg0, arg0 + 0x38BD4, arg0 + 0x38B40, arg0 + 0x39E20, arg0 + 0x3F2E0);
}
