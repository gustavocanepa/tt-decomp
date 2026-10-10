#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041D200(s32, s32);                    /* extern */
s32 func_00466B28(s32);                         /* extern */
s32 func_004F6574(s32, s32, s32);           /* extern */

struct func_00343BF8_temp_s2 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_00343BF8(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s1;
    struct func_00343BF8_temp_s2 *temp_s2;

    temp_s2 = arg0 + 0x60C;
    if (arg1 != 0) {
        func_00466B28(arg1);
        func_0041D200(arg0 + 0x18, arg1);
        return;
    }
    temp_s1 = temp_s2->unk4;
    temp_s0 = temp_s2->unk8;
    func_004F6574(temp_s1, temp_s0, 0);
    temp_s2->unk8 = (s32) (temp_s2->unk8 - (temp_s0 - temp_s1));
}
