#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FC4E8(s32);                             /* extern */
s32 func_003FF678(s32);                             /* extern */
s32 func_003FF930(s32);                             /* extern */
s32 func_00400000(s32);                             /* extern */
s32 func_004001E0(s32);                             /* extern */
s32 func_00400CF0(s32);                             /* extern */
s32 func_004035F8(s32);                             /* extern */

void func_003FDC50(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;

    temp_s0 = func_00400CF0(0x1228);
    temp_s0_2 = temp_s0 + func_003FC4E8(arg0 + 0x1230);
    temp_s0_3 = temp_s0_2 + func_004035F8(arg0 + 0x1238);
    temp_s0_4 = temp_s0_3 + func_003FF678(arg0 + 0x13AC);
    temp_s0_5 = temp_s0_4 + func_00400000(arg0 + 0x145C);
    temp_s0_6 = temp_s0_5 + func_004001E0(arg0 + 0x16B8);
    func_00400CF0(temp_s0_6 + func_003FF930(arg0 + 0x170C));
}
