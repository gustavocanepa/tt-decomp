#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003265A8(s32, s32, s32);           /* extern */

struct func_0031AAF0_temp_a1 {
    char pad0[0x14C];
    s32 unk14C;
    char pad150[0x34];
    s32 unk184;
};

void func_0031AAF0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    struct func_0031AAF0_temp_a1 *temp_a1;

    temp_a1 = (arg1 * 0x1B4) + arg0 + 0x10;
    if (arg2 < 0) {
        temp_a1->unk14C = 1;
        return;
    }
    temp_v1 = temp_a1->unk184;
    temp_a1->unk14C = 2;
    if (temp_v1 != 0) {
        func_003265A8(temp_v1, arg2, 0);
    }
}
