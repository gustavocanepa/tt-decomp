#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00403DD0(s32);                             /* extern */
s32 func_00404160(s32);                             /* extern */
s32 func_00404550(s32);                             /* extern */
s32 func_004049B8(s32);                             /* extern */
s32 func_0050F4E8(s32, s32);                /* extern */

void func_00403378(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;

    temp_s0 = func_00403DD0(arg0 + 0x18);
    temp_s0_2 = temp_s0 + func_00404160(arg0 + 0x48);
    temp_s0_3 = temp_s0_2 + func_00404550(arg0 + 0x64);
    func_0050F4E8(temp_s0_3 + func_004049B8(arg0 + 0x8C), 4);
}
