/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00475440(s32, s32);                    /* extern */

void func_0041B7D8(s32 arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 << 6;
    func_00475440(arg0 + temp_a1 + 0x1A0, temp_a1);
}
