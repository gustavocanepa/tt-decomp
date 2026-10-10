/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A3A8(s32, s32);                    /* extern */

void func_00457360(s32 arg0, s32 arg1) {
    func_0045A3A8(arg0 + 0x85C, (arg1 & 7) + 0xFFD0);
}
