/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005038D8();                                /* extern */
s32 func_00503928();                            /* extern */
s32 func_00504B00();                                /* extern */

s32 func_00504B70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s0 = func_005038D8();
    temp_s1 = func_00504B00();
    if (temp_s0 != 0) {
        func_00503928();
    }
    return temp_s1;
}
