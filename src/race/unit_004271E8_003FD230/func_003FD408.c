#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00410D88(s32);                             /* extern */

extern char D_005FA0A0[];
s32 func_003FD408(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1164);
    if (temp_v0 == 0) {
        return (s32)D_005FA0A0;
    }
    return func_00410D88(temp_v0);
}
