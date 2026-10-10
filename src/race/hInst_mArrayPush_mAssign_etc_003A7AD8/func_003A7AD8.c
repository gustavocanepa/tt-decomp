/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00552A68(s32);                         /* extern */
s32 func_00552C90(s32, s32);                    /* extern */

void func_003A7AD8(s32 arg0, s32 arg1) {
    func_00552A68(arg0 + 0x14);
    func_00552C90(arg1, arg0 + 0x4C);
}
