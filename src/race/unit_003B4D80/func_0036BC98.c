/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00370A58(s32, s32);                /* extern */
s32 func_00370AA8(s32, s32);                    /* extern */

void func_0036BC98(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x20;
    func_00370A58(temp_s0, 0);
    func_00370AA8(temp_s0, arg1);
}
