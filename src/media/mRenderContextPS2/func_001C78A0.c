/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E49C8(s32);                             /* extern */
f32 func_001E4CA8();                                /* extern */
s32 func_00468090(s32, s32, s32, s32, s32, f32); /* extern */

void func_001C78A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 temp_f20;

    temp_f20 = func_001E4CA8();
    func_00468090(arg1, arg2, arg3, arg4, func_001E49C8(arg0), temp_f20);
}
