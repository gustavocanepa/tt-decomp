/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043D7C8(s32, f32);                    /* extern */
f32 func_0043E0B0();                                /* extern */

void func_0043F3D0(s32 arg0) {
    func_0043D7C8(arg0, func_0043E0B0() - 0x1.0000000000000p+0f);
}
