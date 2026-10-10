/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A4980(s32, s32);                    /* extern */
s32 func_003A4990(s32, s32);                    /* extern */
s32 func_00404980(s32, s32);                    /* extern */

void func_00402CA0(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x8C;
    func_003A4980(arg1, func_00404980(temp_s0, 1));
    func_003A4990(arg1, func_00404980(temp_s0, 2));
}
