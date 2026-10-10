/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A330(s32, s32);                    /* extern */
s32 func_0045A3A8(s32, s32);                    /* extern */
s32 func_0045A560(s32, s32, s32);               /* extern */

void func_004574E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x85C;
    func_0045A3A8(temp_s1, 0xFFC4);
    func_0045A3A8(temp_s1, arg2 + 3);
    func_0045A330(temp_s1, (arg3 * 0x10) + arg4);
    func_0045A560(temp_s1, arg1, arg2);
}
