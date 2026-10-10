#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AFAC8(s32, s32, s32);               /* extern */
s32 func_001B0368(s32);                             /* extern */
s32 func_003EECA0(s32, s32, s32);           /* extern */
s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */

s32 func_001AEA20(s32 arg0, s32 arg1) {
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;

    temp_s3 = arg0 + 0x14244;
    temp_s1 = arg0 + 0x14218;
    func_004A4D68(temp_s3);
    temp_s2 = func_001AFAC8(temp_s1, arg1, 0);
    func_003EECA0(arg0 + 0x14278, 0, func_001B0368(temp_s1));
    func_004A4DD8(temp_s3);
    return temp_s2;
}
