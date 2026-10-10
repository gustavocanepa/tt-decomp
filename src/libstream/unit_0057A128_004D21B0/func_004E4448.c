#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004E42B0(s32);                         /* extern */
s32 func_004E81D0(s32, s32);                /* extern */

struct func_004E4448_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x12];
    u8 unk1A;
};

void **func_004E4448(void **arg0) {
    s32 temp_v0;
    s32 var_a0;
    struct func_004E4448_temp_v1 *temp_v1;

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
        func_004E81D0(0, M2C_FIELD(*arg0, s32 *, 0));
    }
    return arg0;
}
