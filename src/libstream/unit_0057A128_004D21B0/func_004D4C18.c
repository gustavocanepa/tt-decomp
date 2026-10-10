/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004D9EE0(s32, s32);                    /* extern */
s32 func_005038D8();                                /* extern */
s32 func_00503928();                            /* extern */

s32 func_004D4C18(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = func_005038D8();
    temp_s0 = func_004D9EE0(arg0, 0);
    if (temp_s1 != 0) {
        func_00503928();
    }
    return temp_s0;
}
