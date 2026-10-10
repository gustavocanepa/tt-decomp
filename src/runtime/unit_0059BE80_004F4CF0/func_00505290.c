/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005038D8();                                /* extern */
s32 func_00503928();                            /* extern */
s32 func_00505198(s32, s32, s32, s32);              /* extern */

s32 func_00505290(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;
    s32 temp_s4;

    temp_s4 = func_005038D8();
    temp_s0 = func_00505198(arg0, arg1, arg2, arg3);
    if (temp_s4 != 0) {
        func_00503928();
    }
    return temp_s0;
}
