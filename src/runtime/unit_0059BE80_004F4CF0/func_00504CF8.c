/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005038D8();                                /* extern */
s32 func_00503928();                            /* extern */
s32 func_00504CA8(s32, s32);                        /* extern */

s32 func_00504CF8(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s2;

    temp_s2 = func_005038D8();
    temp_s0 = func_00504CA8(arg0, arg1);
    if (temp_s2 != 0) {
        func_00503928();
    }
    return temp_s0;
}
