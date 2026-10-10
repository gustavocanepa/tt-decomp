/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A430();                    /* extern */
s32 func_0045A4B8(s32, s32);                    /* extern */

void func_00457820(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x85C;
    func_0045A430(temp_s0);
    func_0045A430(temp_s0, arg2);
    func_0045A4B8(temp_s0, arg3);
    func_0045A4B8(temp_s0, arg4);
}
