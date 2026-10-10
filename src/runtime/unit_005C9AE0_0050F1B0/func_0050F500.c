/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0037B0D0(s32, s32);                    /* extern */

void func_0050F500(s32 arg0, s32 arg1, s32 arg2) {
    func_0037B0D0(arg0 + (arg1 * 0x198) + 0x138, arg2);
}
