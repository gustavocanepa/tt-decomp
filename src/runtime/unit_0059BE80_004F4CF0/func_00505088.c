/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005038D8();                                /* extern */
s32 func_00503928();                            /* extern */
s32 func_00505040(s32);                             /* extern */

s32 func_00505088(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = func_005038D8();
    temp_s0 = func_00505040(arg0);
    if (temp_s1 != 0) {
        func_00503928();
    }
    return temp_s0;
}
