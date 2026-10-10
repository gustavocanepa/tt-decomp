#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00446170(s32, s32);                    /* extern */
s32 func_0056A498(s32);                             /* extern */

struct func_00446028_arg0 {
    s32 unk0;
    u32 unk4;
};

void func_00446028(struct func_00446028_arg0 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_s1;
    u32 var_s2;

    temp_a0 = arg0->unk0;
    if (temp_a0 != 0) {
        arg0->unk0 = func_0056A498(temp_a0);
    }
    var_s2 = 0;
    if (arg0->unk4 != 0) {
        var_s1 = 0;
        do {
            var_s2 += 1;
            temp_a0_2 = arg0->unk0 + var_s1;
            var_s1 += 0xC;
            func_00446170(temp_a0_2, arg1);
        } while (var_s2 < (u32) arg0->unk4);
    }
}
