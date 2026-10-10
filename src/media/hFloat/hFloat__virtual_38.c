#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct hFloat__virtual_38_arg0 {
    char pad0[0x10];
    f32 unk10;
};

void hFloat__virtual_38(struct hFloat__virtual_38_arg0 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_s0;
    s32 temp_v0;

    arg0->unk10 = (f32) (arg0->unk10 + 1.0f);
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
