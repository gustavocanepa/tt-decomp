/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A58E0(s32, s32);                /* extern */
s32 func_004FA6B0(s32, s32);                    /* extern */
s32 func_004FA710();                                /* extern */

void func_004A5688(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;

    temp_s0 = func_004FA710();
    func_004FA6B0(temp_s0, func_004A58E0(1, 0));
}
