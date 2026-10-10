#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00292270(s32);                         /* extern */
s32 func_00292768(s32);                         /* extern */
s32 func_002BDA28(s32, s32);                /* extern */
s32 func_002C0FE8(s32);                         /* extern */

s32 func_002BF120(s32 *arg0) {
    s32 temp_v0;

    if (*arg0 == 0) {
        temp_v0 = func_002BDA28(0x7C, 4);
        func_00292768(temp_v0);
        *arg0 = temp_v0;
        func_002C0FE8(temp_v0);
        func_00292270(*arg0);
    }
    return *arg0;
}
