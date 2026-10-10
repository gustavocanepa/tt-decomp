#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00205C50(s32);                             /* extern */
f32 func_00205CB0(s32);                             /* extern */

struct func_00276148_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x28];
    s32 unk30;
    f32 unk34;
};

s32 func_00276148(struct func_00276148_arg0 *arg0) {
    f32 var_f0;
    s32 temp_a0;

    temp_a0 = arg0->unk30;
    if (temp_a0 != 0) {
        if (arg0->unk4 != 0) {
            var_f0 = func_00205C50(temp_a0);
        } else {
            var_f0 = func_00205CB0(temp_a0);
        }
        arg0->unk34 = var_f0;
    }
    return 1;
}
