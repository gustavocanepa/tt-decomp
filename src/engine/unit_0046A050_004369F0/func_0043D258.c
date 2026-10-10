/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00443E70(s32, s8);                     /* extern */

void func_0043D258(s32 arg0, s8 arg1) {
    func_00443E70(arg0 + 0x40, arg1);
}
