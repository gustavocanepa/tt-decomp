#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct hInt__virtual_39_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void hInt__virtual_39(struct hInt__virtual_39_arg0 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_s0;
    s32 temp_v0;

    arg0->unk10 = (s32) (arg0->unk10 - 1);
    if (arg1 != arg2) {
        temp_s0 = *arg2;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = *arg1;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        *arg1 = temp_s0;
    }
}
