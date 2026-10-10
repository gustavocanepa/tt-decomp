/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0043E0B0(s32);                             /* extern */
s32 func_004447C8(s32, f32);                    /* extern */

void func_004418F0(s32 arg0, s32 arg1) {
    func_004447C8(arg0, func_0043E0B0(arg1) * 0x1.47ae140000000p-7f);
}
