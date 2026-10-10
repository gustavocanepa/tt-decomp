#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */
s32 func_004AC9B8(s32, s32);                        /* extern */

s32 func_004ACDE8(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = arg0 + 0xC;
    func_004A4D68(temp_s1);
    temp_s0 = func_004AC9B8(arg0, arg1);
    func_004A4DD8(temp_s1);
    return temp_s0;
}
