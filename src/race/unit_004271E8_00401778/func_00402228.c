#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400CF0(s32);                         /* extern */
s32 func_00401920();                                /* extern */
s32 func_00563E68(s32);                             /* extern */
s32 func_00564098(s32);                             /* extern */
s32 func_00564268(s32);                             /* extern */

void func_00402228(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;

    temp_s0 = func_00401920();
    temp_s0_2 = temp_s0 + func_00564268(arg0 + 0x233FC);
    temp_s0_3 = temp_s0_2 + func_00564098(arg0 + 0x23558);
    temp_s0_4 = temp_s0_3 + func_00564098(arg0 + 0x23A6C);
    func_00400CF0(temp_s0_4 + func_00563E68(arg0 + 0x23F80));
}
