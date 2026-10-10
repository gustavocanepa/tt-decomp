#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004E36A8(void **, s32, s32);       /* extern */
s32 func_004E42B0(s32);                         /* extern */

struct func_004E3CF0_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x12];
    u8 unk1A;
};

void **func_004E3CF0(void **arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a0;
    struct func_004E3CF0_temp_v1 *temp_v1;

    temp_v1 = *arg0;
    var_a0 = 0;
    if (temp_v1->unk1A == 0) {
        temp_v0 = temp_v1->unk4;
        if (temp_v0 != 0) {
            func_004E42B0(temp_v0);
        }
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        func_004E36A8(arg0, arg1, 0);
    }
    return arg0;
}
