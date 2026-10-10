/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004134A8();                                /* extern */
s32 func_00413AE0(s32 *, s32, s32);         /* extern */
s32 func_004F6678(s32, s32, s32);       /* extern */

void func_0010AF10(s32 *arg0, s32 arg1) {
    *arg0 = func_004134A8();
    func_004F6678(arg1, 0, 0x20);
    func_00413AE0(arg0, arg1, 0x20);
}
