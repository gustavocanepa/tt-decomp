#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

void func_00481B68(s32 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_004A45D0(temp_v0);
        *arg0 = 0;
    }
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
