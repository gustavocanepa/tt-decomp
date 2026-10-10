/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A53A0(s32);                         /* extern */
s32 func_004A58E0(s32, s32);                /* extern */

void func_0047D128(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_004A53A0(func_004A58E0(3, 0));
}
