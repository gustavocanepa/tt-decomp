#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00294C10(void *, u32);                 /* extern */
u32 func_00294F40();                                /* extern */
s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct hArray__virtual_14_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void hArray__setElement(struct hArray__virtual_14_arg0 *arg0, u32 arg1, s32 *arg2) {
    s32 *temp_s1;
    s32 temp_s0;
    s32 temp_v0;

    if (arg1 >= func_00294F40()) {
        func_00294C10(arg0, arg1);
    }
    temp_s1 = arg0->unk14 + (arg1 * 4);
    if (temp_s1 != arg2) {
        temp_s0 = *arg2;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = *temp_s1;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        *temp_s1 = temp_s0;
    }
}
