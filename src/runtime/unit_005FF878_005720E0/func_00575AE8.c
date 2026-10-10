#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004E5458(s32, s8);                         /* extern */

struct func_00575AE8_temp_a0 {
    s32 unk0;
    char pad4[0x16];
    u8 unk1A;
};

void **func_00575AE8(void **arg0, s8 arg1) {
    struct func_00575AE8_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    if (temp_a0->unk1A == 0) {
        if (func_004E5458(temp_a0->unk0, arg1) == -1) {
            M2C_FIELD(*arg0, u8 *, 0x1A) = 4U;
        }
    }
    return arg0;
}
