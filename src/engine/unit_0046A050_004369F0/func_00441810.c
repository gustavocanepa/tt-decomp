/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0043E0B0(s32);                             /* extern */
s32 func_004447A8(s32, f32);                    /* extern */

void func_00441810(s32 arg0, s32 arg1) {
    func_004447A8(arg0, func_0043E0B0(arg1));
}
