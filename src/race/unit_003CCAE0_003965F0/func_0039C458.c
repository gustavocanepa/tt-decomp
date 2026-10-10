/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00393A60(s32);                             /* extern */
s32 func_003CEC70(s32, s32);                    /* extern */

void func_0039C458(s32 arg0, s32 arg1) {
    func_003CEC70(arg0 + (func_00393A60(arg1) * 0x30) + 0x2C4, arg1);
}
