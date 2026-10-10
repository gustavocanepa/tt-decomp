#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_004A45F8(s32);                         /* extern */

s32 func_0030BF98(s32 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0_2 = *arg0;
    if (temp_v0_2 != 0) {
        func_004A45D0(temp_v0_2);
        *arg0 = 0;
    }
    temp_v0 = func_004A45F8(0x1868);
    *arg0 = temp_v0;
    return temp_v0 != 0;
}
