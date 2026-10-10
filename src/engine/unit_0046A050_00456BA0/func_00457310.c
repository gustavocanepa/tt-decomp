/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A3A8(s32, s32);                    /* extern */

void func_00457310(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x85C;
    func_0045A3A8(temp_s0, 0xFFDD);
    func_0045A3A8(temp_s0, 4);
    func_0045A3A8(temp_s0, arg1);
}
