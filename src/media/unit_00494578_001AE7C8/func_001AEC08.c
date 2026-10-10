#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AFC20(s32, s32, s32);                   /* extern */
s32 func_001B0368(s32);                             /* extern */
s32 func_003EECA0(s32, s32, s32);           /* extern */
s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */

s32 func_001AEC08(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s4;

    temp_s4 = arg0 + 0x142BC;
    temp_s1 = arg0 + 0x14290;
    func_004A4D68(temp_s4);
    temp_s2 = func_001AFC20(temp_s1, arg1, arg2);
    func_003EECA0(arg0 + 0x142F0, 0, func_001B0368(temp_s1));
    func_004A4DD8(temp_s4);
    return temp_s2;
}
