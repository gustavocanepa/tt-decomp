/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00567CB0(s32, s32);                    /* extern */

void func_0042D800(s32 arg0) {
    func_00567CB0(arg0 + 0x14, arg0);
}
