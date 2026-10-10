/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043D7C8(s32, f32);                    /* extern */
f32 func_0043E0B0();                             /* extern */

void func_0043EED0(s32 arg0, s32 arg1) {
    f32 temp_f20;

    temp_f20 = func_0043E0B0();
    func_0043D7C8(arg0, temp_f20 - func_0043E0B0(arg1));
}
