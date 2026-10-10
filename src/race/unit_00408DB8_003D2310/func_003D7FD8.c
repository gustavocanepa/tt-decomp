/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D7E50();                            /* extern */
s32 func_003D7F10(s32, s32);                    /* extern */

void func_003D7FD8(s32 arg0, s32 arg1) {
    func_003D7E50();
    func_003D7F10(arg0, arg1);
}
